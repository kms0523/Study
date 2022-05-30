//#include <iostream>
//
//#include "Exception.h"
//
//using uint = unsigned int;
//
//class Coordinate
//{
//public:
//	Coordinate(void) = delete;
//	Coordinate(const int x_coordinate, const int y_coordinate)
//		: x_(x_coordinate), y_(y_coordinate) {};
//
//public://Query
//	uint quadrant(void) const
//	{
//		ms::require(!this->is_on_axis(), "좌표축 위에 있는 좌표는 사분면을 정의할 수 없습니다.");
//
//		if (this->x_ > 0)
//		{
//			if (this->y_ > 0)
//			{
//				return 1;
//			}
//			else
//			{
//				return 2;
//			}
//		}
//		else
//		{
//			if (this->y_ > 0)
//			{
//				return 3;
//			}
//			else
//			{
//				return 4;
//			}
//		}
//	}
//
//private:
//	bool is_on_axis(void) const
//	{
//		return x_ == 0 || y_ == 0;
//	}
//
//private:
//	int x_ = 0;
//	int y_ = 0;
//};
//
//int main(void)
//{
//	int x_coordinate, y_coordinate;
//	std::cin >> x_coordinate >> y_coordinate;
//
//	Coordinate coordinate = { x_coordinate, y_coordinate };
//
//	try 
//	{
//		std::cout << coordinate.quadrant();
//	}
//	catch (const std::exception& except)
//	{
//		std::cout << except.what();
//		std::cout << "좌표를 다시 입력하세요! \n\n";
//
//		main();
//	}	
//
//	return 0;
//}