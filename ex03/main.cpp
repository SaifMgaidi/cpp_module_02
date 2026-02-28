#include "Point.hpp"

int	main(void)
{
	Point	a(0, 0);
	Point	b(10, 0);
	Point	c(5, 10);
	Point	points[4] = {Point(2, 2), Point(15, 15), Point(10, 0), Point(5, 0)};

	for (int i = 0; i < 4; i++)
	{
		if (bsp(a, b, c, points[i]))
			std::cout << "Le point " << i + 1 << " se trouve a l'interieur du triangle" << std::endl;
		else
			std::cout << "Le point " << i + 1 << " ne se trouve pas a l'interieur du triangle" << std::endl;
	}
	return 0;
}

