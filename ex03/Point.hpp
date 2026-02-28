#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
public:
	// constructors
	Point();
	Point(const float f_x, const float f_y);
	Point(const Point& other);
	Point&	operator=(const Point& other);
	bool	operator==(const Point& other) const;

	// destructor
	~Point();

	// member functions
	Fixed	getX() const;
	Fixed	getY() const;

private:
	const Fixed	x;
	const Fixed	y;
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif