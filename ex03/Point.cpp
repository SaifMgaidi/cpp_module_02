#include "Point.hpp"

// --------------------Constructors---------------------------------

// default constructor
Point::Point(): x(0), y(0)
{
}

// variables constructor
Point::Point(const float f_x, const float f_y)
:	x(f_x), y(f_y)
{
}

// copy constructor
Point::Point(const Point& other)
:	x(other.x), y(other.y)
{
}

// copy assignment operator overload
Point&	Point::operator=(const Point& other)
{
	if (this == &other)
		return (*this);
	return (*this);
}


bool    Point::operator==(const Point& other) const
{
	if (x == other.x && y == other.y)
		return (true);
	return (false);
}

// --------------------Destructor---------------------------------

Point::~Point()
{
}


// --------------------member functions---------------------------------

Fixed   Point::getX() const
{
	return (x);
}

Fixed   Point::getY() const
{
	return (y);
}
