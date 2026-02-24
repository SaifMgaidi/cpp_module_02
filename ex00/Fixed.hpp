#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	// Constructors
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);

	// Destructor
	~Fixed();

	// Member Functions
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
private:
	int					fixedPoint_;
	static const int	nFractionalBits = 8;
};

#endif