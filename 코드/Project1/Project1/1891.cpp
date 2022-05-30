#include <algorithm>
#include <iostream>
#include <string_view>
#include <vector>

#include "Exception.h"

namespace ms
{
    int char_to_number(const char c)
    {
        ms::require(std::isdigit(c), "examine character should be digit");

        return c - '0';
    }
}

class Hierarchical_Quadrant
{
public:
    Hierarchical_Quadrant(const std::string_view& quadrants)
    {
        ms::require(this->is_valid(quadrants), "initial quadrants should be valid");

        this->quadrants_.resize(quadrants.size());
        std::copy(quadrants.begin(), quadrants.end(), this->quadrants_.begin());
    }

public: //Command
    void move(const int horizontal_movement, const int vertical_movement)
    {
        const auto index_pos = static_cast<int>(this->quadrants_.size() - 1);

        if (horizontal_movement > 0)
        {
            for (int i = 0; i < horizontal_movement; ++i)
            {
                this->move_right(index_pos);
            }
        }
        else
        {
            const auto num_movement = std::abs(horizontal_movement);

            for (int i = 0; i < num_movement; ++i)
            {
                this->move_left(index_pos);
            }
        }

        if (vertical_movement > 0)
        {
            for (int i = 0; i < vertical_movement; ++i)
            {
                this->move_up(index_pos);
            }
        }
        else
        {
            const auto num_movement = std::abs(vertical_movement);

            for (int i = 0; i < num_movement; ++i)
            {
                this->move_down(index_pos);
            }
        }
    }

public: //Query
    void print(void) const
    {
        for (const auto c : this->quadrants_)
        {
            std::cout << c;
        }
        std::cout << "\n";
    }

private:
    void move_right(const int pos)
    {
        ms::require(pos >= 0, "position should be positive");

        const auto quadrant_index = this->quadrants_[pos];
        switch (quadrant_index)
        {
        case '1':
            this->quadrants_[pos] = '2';
            this->move_right(pos - 1);
            break;
        case '2':
            this->quadrants_[pos] = '1';
            break;
        case '3':
            this->quadrants_[pos] = '4';
            break;
        case '4':
            this->quadrants_[pos] = '3';
            this->move_right(pos - 1);
            break;
        default:
            ms::exception("Error");
        }
    }

    void move_left(const int pos)
    {
        ms::require(pos >= 0, "position should be positive");

        const auto quadrant_index = this->quadrants_[pos];
        switch (quadrant_index)
        {
        case '1':
            this->quadrants_[pos] = '2';            
            break;
        case '2':
            this->quadrants_[pos] = '1';
            this->move_left(pos - 1);
            break;
        case '3':
            this->quadrants_[pos] = '4';
            this->move_left(pos - 1);
            break;
        case '4':
            this->quadrants_[pos] = '3';
            break;
        default:
            ms::exception("Error");
        }
    }

    void move_up(const int pos)
    {
        ms::require(pos >= 0, "position should be positive");

        const auto quadrant_index = this->quadrants_[pos];
        switch (quadrant_index)
        {
        case '1':
            this->quadrants_[pos] = '4';
            this->move_up(pos - 1);
            break;
        case '2':
            this->quadrants_[pos] = '3';
            this->move_up(pos - 1);
            break;
        case '3':
            this->quadrants_[pos] = '2';
            break;
        case '4':
            this->quadrants_[pos] = '1';
            break;
        default:
            ms::exception("Error");
        }
    }

    void move_down(const int pos)
    {
        ms::require(pos >= 0, "position should be positive");

        const auto quadrant_index = this->quadrants_[pos];
        switch (quadrant_index)
        {
        case '1':
            this->quadrants_[pos] = '4';
            break;
        case '2':
            this->quadrants_[pos] = '3';            
            break;
        case '3':
            this->quadrants_[pos] = '2';
            this->move_down(pos - 1);
            break;
        case '4':
            this->quadrants_[pos] = '1';
            this->move_down(pos - 1);
            break;
        default:
            ms::exception("Error");
        }
    }


    bool is_valid(const std::string_view quadrants) const
    {
        for (const auto c : quadrants)
        {
            const auto number = ms::char_to_number(c);

            if (0 == number || 4 < number)
            {
                return false;
            }
        }

        return true;
    }

private:
    std::vector<char> quadrants_;
};

int main(void)
{
    int n;
    std::string start_quadrants;
    std::cin >> n >> start_quadrants;

    int horizontal_movement, vertical_movement;
    std::cin >> horizontal_movement >> vertical_movement;
    
    try
    {
        Hierarchical_Quadrant hierarchical_quadrant(start_quadrants);
        try
        {
            hierarchical_quadrant.move(horizontal_movement, vertical_movement);
            hierarchical_quadrant.print();
        }
        catch (...)
        {
            std::cout << "-1";
        }
    }
    catch (const std::exception& except)
    {
        std::cout << except.what();
        std::exit(523);
    }

    return 0;
}
