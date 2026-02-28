#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	const Fixed	ab[2] = {b.getX() - a.getX(), b.getY() - a.getY()};
	const Fixed	bc[2] = {c.getX() - b.getX(), c.getY() - b.getY()};
	const Fixed	ca[2] = {a.getX() - c.getX(), a.getY() - c.getY()};
	Fixed		p[2] = {point.getX() - a.getX(), point.getY() - a.getY()};
	Fixed		edge_ab = 0;
	Fixed		edge_bc = 0;
	Fixed		edge_ca = 0;

	edge_ab = (ab[0] * p[1]) - (ab[1] * p[0]);
	p[0] = point.getX() - b.getX();
	p[1] = point.getY() - b.getY();
	edge_bc = (bc[0] * p[1]) - (bc[1] * p[0]);
	p[0] = point.getX() - c.getX();
	p[1] = point.getY() - c.getY();
	edge_ca = (ca[0] * p[1]) - (ca[1] * p[0]);

	if (edge_ab > 0 && edge_bc > 0 && edge_ca > 0)
		return (true);
	else if (edge_ab < 0 && edge_bc < 0 && edge_ca < 0)
		return (true);
	return (false);
}