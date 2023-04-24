#include <vector>

using f32 = float;

enum class Type
{
	square,
	rectangle,
	triangle
};

class shape_base
{
public:
	shape_base() {}
	virtual f32 Area() = 0;
};

class square : public shape_base
{
public:
	square(f32 SideInit) : Side(SideInit) {}
	virtual f32 Area() { return Side * Side; }

private:
	f32 Side;
};

class rectangle : public shape_base
{
public:
	rectangle(f32 WidthInit, f32 HeightInit) : Width(WidthInit), Height(HeightInit) {}
	virtual f32 Area() { return Width * Height; }

private:
	f32 Width, Height;
};

class triangle : public shape_base
{
public:
	triangle(f32 BaseInit, f32 HeightInit) : Base(BaseInit), Height(HeightInit) {}
	virtual f32 Area() { return 0.5f*Base*Height; }

private:
	f32 Base, Height;
};

class shapes
{
public:
	void cal_areas(double* areas) const;

private:
	std::vector<double> widths;
	std::vector<double> heigths;
	std::vector<Type> types;
};

int main(void)
{

}