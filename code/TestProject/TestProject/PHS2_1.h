#pragma once
#include <algorithm>
#include <assert.h>
#include <set>
#include <vector>

class Student
{
public:
  Student(const int lan_cable_length)
      : _cable_length(lan_cable_length){};

public:
  void lend(Student& other)
  {
    other._remaining_cable_lengths = std::move(this->_remaining_cable_lengths);
  }

  void lend(Student& other, const int remain_length)
  {
    other._remaining_cable_lengths = std::move(this->_remaining_cable_lengths);
    other._remaining_cable_lengths.insert(remain_length);
  }

  void lend_max(Student& other, const int remain_length)
  {
    if (this->_remaining_cable_lengths.empty())
    {
      other._remaining_cable_lengths.insert(remain_length);
    }
    else
    {
      const auto length1    = *this->_remaining_cable_lengths.begin();
      const auto max_length = std::max(length1, remain_length);
      other._remaining_cable_lengths.insert(max_length);
    }
  }

  void select_borrowed_cable(const int table_height)
  {
    const auto iter = this->find_best_length(table_height);
    if (iter != this->_remaining_cable_lengths.end())
    {
      this->_borrowed_cable_length = *iter;
      this->_remaining_cable_lengths.erase(iter);
    }
  }

public:
  bool can_connect(const int table_height) const
  {
    const auto total_length = this->_cable_length + this->_borrowed_cable_length;
    return table_height <= total_length;
  };

  bool can_self_connect(const int table_height) const
  {
    return table_height <= this->_cable_length;
  }

  int cal_remain_length(const int table_height) const
  {
    return this->_cable_length - table_height;
  }

  int cal_max_length_to_lend(const int table_height) const
  {
    const auto remain_length = this->cal_remain_length(table_height);

    return std::max(remain_length, this->_borrowed_cable_length);
  }

private:
  std::multiset<int>::const_iterator find_best_length(const int table_height) const
  {
    if (this->_remaining_cable_lengths.empty()) return this->_remaining_cable_lengths.end();

    auto ref_value = table_height - this->_cable_length;

    //find least value exceeding the reference value
    return this->_remaining_cable_lengths.upper_bound(ref_value - 1);
  }

private:
  int _cable_length          = 0;
  int _borrowed_cable_length = 0;
  std::multiset<int> _remaining_cable_lengths;
};

int solution1(int H, int W, std::vector<int> D)
{
  const auto count = std::count_if(D.begin(), D.end(), [&](int i) { return H <= i; });
  return count;
}

int solution2(int H, int W, std::vector<int> D)
{
  const auto num_students = D.size();

  std::vector<Student> students;
  students.reserve(num_students);

  for (const auto d : D)
  {
    students.push_back(d);
  }

  auto count = 0;
  for (int i = 0; i < num_students; ++i)
  {
    auto& student = students[i];
    if (student.can_connect(H))
    {
      count++;

      if (!student.can_self_connect(H)) continue;

      if (i != num_students - 1)
      {
        auto& next_student = students[i + 1];

        const auto remain_length = student.cal_remain_length(H);
        student.lend(next_student, remain_length);
      }
    }
  }

  return count;
}

int solution3(int H, int W, std::vector<int> D)
{
  const auto num_students = D.size();

  std::vector<Student> students;
  students.reserve(num_students);

  for (const auto d : D)
  {
    students.push_back(d);
  }

  auto count = 0;
  for (int i = 0; i < num_students; ++i)
  {
    auto& student = students[i];
    if (student.can_connect(H))
    {
      count++;

      if (i != num_students - 1)
      {
        const auto remain_length = student.cal_remain_length(H);
        auto&      next_student  = students[i + 1];
        student.lend_max(next_student, remain_length);
      }
    }
    else
    {
      student.select_borrowed_cable(H);

      if (student.can_connect(H))
      {
        count++;
      }

      if (i != num_students - 1)
      {
        auto& next_student = students[i + 1];
        student.lend(next_student);
      }
    }
  }

  return count;
}

int solution4(int H, int W, std::vector<int> D)
{
  const auto num_students = D.size();

  std::vector<Student> students;
  students.reserve(num_students);

  for (const auto d : D)
  {
    students.push_back(d);
  }

  auto count = 0;
  for (int i = 0; i < num_students; ++i)
  {
    auto& student = students[i];

    if (student.can_connect(H))
    {
      count++;

      if (i != num_students - 1)
      {
        auto& next_student = students[i + 1];

        const auto remain_length = student.cal_remain_length(H);

        student.lend(next_student, remain_length);
      }
    }
    else
    {
      student.select_borrowed_cable(H);

      if (student.can_connect(H))
      {
        count++;
      }

      if (i != num_students - 1)
      {
        auto& next_student = students[i + 1];
        student.lend(next_student);
      }
    }
  }

  return count;
}