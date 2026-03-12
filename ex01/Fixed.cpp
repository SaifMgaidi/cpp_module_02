#include "Fixed.hpp"


const int	Fixed::nFractionalBits_ = 8;

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
	if (this != &other)
		fixedPoint_ = other.fixedPoint_;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}


Fixed::Fixed(const int integer)
{
	fixedPoint_ = integer << nFractionalBits_;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float float_number)
{
	fixedPoint_ = roundf(float_number * (1 << nFractionalBits_));
	std::cout << "Float constructor called" << std::endl;
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

