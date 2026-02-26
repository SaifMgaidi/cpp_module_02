#include "Fixed.hpp"


// ---------------------------Constructor-------------------------------------------

// default constructor
Fixed::Fixed(): fixedPoint_(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// copy constructor
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// copy assignment operator overload
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		fixedPoint_ = other.fixedPoint_;
	return (*this);
}


Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called" << std::endl;
	fixedPoint_ = integer << nFractionalBits_;
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	fixedPoint_ = roundf(number * (1 << nFractionalBits_));
}

// --------------------------------Destructor----------------------------------------
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


// ------------------------------Member Functions----------------------------------------

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixedPoint_);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	fixedPoint_ = raw;
}

float	Fixed::toFloat( void ) const
{
	return ((float)fixedPoint_ / (1 << nFractionalBits_));
}

int	Fixed::toInt( void ) const
{
	return (fixedPoint_ >> nFractionalBits_);
}


// ---------------------Non-Member Functions----------------------------

std::ostream&	operator<<(std::ostream& out, const Fixed& obj)
{
	out << obj.toFloat();
	return (out);
}

