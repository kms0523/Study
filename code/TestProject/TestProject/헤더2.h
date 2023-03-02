#include <algorithm>
#include <cmath>
#include <set>
#include <vector>

class myCompare {
public:
	bool operator()(const std::vector<int>& a, const std::vector<int>& b)
	{
		if (a[1] < b[1]) {
			return true;
		}
		else if (a[1] == b[1]) {
			return a[0] < b[0];
		}
		else {
			return false;
		}
	}
};

double cal_distance(const std::vector<int>& hold1, const std::vector<int>& hold2)
{
	const auto delx = hold1[0] - hold2[0];
	const auto dely = hold1[1] - hold2[1];
	return std::sqrt(delx * delx + dely * dely);
}

class Map {
private:
	Map(void) = delete;

public:
	static void initialize(std::vector<std::vector<int>>& H, const double arm_length)
	{
		std::sort(H.begin(), H.end(), myCompare());

		const auto num_holds = H.size();
		Map::hold_id_to_reachable_hold_id_set_.clear();
		Map::hold_id_to_reachable_hold_id_set_.resize(num_holds);

		for (int i = 0; i < num_holds; ++i) {
			const auto& current_hold = H[i];

			auto& reachable_hold_id_set = Map::hold_id_to_reachable_hold_id_set_[i];
			for (int j = i + 1; j < num_holds; ++j) {
				const auto& other_hold = H[j];

				const auto other_x = other_hold[0];
				const auto other_y = other_hold[1];
				const auto current_x = current_hold[0];
				const auto current_y = current_hold[1];

				if (current_x + 2 * arm_length < other_x && current_y + 2 * arm_length < other_y) {
					break;
				}

				const auto distance = cal_distance(current_hold, other_hold);

				if (distance <= 2 * arm_length && current_y < other_y) {
					reachable_hold_id_set.insert(j);
				}
			}
		}
	}

	static const std::set<int>& get_reachable_hold_id_set(const int hold_id)
	{
		return Map::hold_id_to_reachable_hold_id_set_[hold_id];
	}

private:
	inline static std::vector<std::set<int>> hold_id_to_reachable_hold_id_set_;
};

class HJ {
public:
	static void initialize(const int arm_length)
	{
		HJ::arm_length_ = arm_length;
		HJ::last_hold_id_ = -1;
	}

public:
	static int get_last_hold_id(void)
	{
		return HJ::last_hold_id_;
	}

public:
	void go(const int hold_id)
	{
		this->current_hold_id_ = hold_id;
	}

	void search(void)
	{
		const auto& candidate_hold_id_set = Map::get_reachable_hold_id_set(this->current_hold_id_);

		if (candidate_hold_id_set.empty()) {
			if (HJ::last_hold_id_ < this->current_hold_id_) {
				HJ::last_hold_id_ = this->current_hold_id_;
			}
			return;
		}

		for (const auto hold_id : candidate_hold_id_set) {
			auto copy_hj = *this;
			copy_hj.go(hold_id);
			copy_hj.search();
		}
	}

public:
	bool can_start(const std::vector<int>& hold) const
	{
		return hold[1] <= this->arm_length_;
	}



private:
	inline static int last_hold_id_ = -1;
	inline static int arm_length_ = 0;
	int current_hold_id_ = -1;
};

int solution(int N, std::vector<std::vector<int>> H, int D)
{
	Map::initialize(H, D);
	HJ::initialize(D);

	HJ hj;

	for (int i = 0; i < N; ++i) {
		const auto& hold = H[i];

		if (hj.can_start(hold)) {
			auto copy_hj = hj;
			copy_hj.go(i);
			copy_hj.search();
		}
		else {
			break;
		}
	}

	const auto last_hold_id = HJ::get_last_hold_id();

	if (last_hold_id == -1) {
		return 0;
	}
	else {
		return H[last_hold_id][1];
	}
}
