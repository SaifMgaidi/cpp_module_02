#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
	// Constructors
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	Fixed(const int integer);
	Fixed(const float float_number);

	// Destructor
	~Fixed();

	// Member Functions
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat( void ) const;
	int		toInt( void ) const;
private:
	int					fixedPoint_;
	static const int	nFractionalBits_ = 8;
};


std::ostream&	operator<<(std::ostream& out, const Fixed& obj);

#endif