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
		fixedPoint_ = other.getRawBits();
	return (*this);
}


Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(integer << nFractionalBits_);
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
	return (fixedPoint_);
}

void	Fixed::setRawBits(int const raw)
{
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



bool	Fixed::operator<(const Fixed& other) const
{
	return (fixedPoint_ < other.fixedPoint_);
}

bool	Fixed::operator>(const Fixed& other) const
{
	return (fixedPoint_ > other.fixedPoint_);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (fixedPoint_ <= other.fixedPoint_);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (fixedPoint_ >= other.fixedPoint_);
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (fixedPoint_ == other.fixedPoint_);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (fixedPoint_ != other.fixedPoint_);
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits(fixedPoint_ + other.fixedPoint_);
	return (result);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits(fixedPoint_ - other.fixedPoint_);
	return (result);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits(static_cast<long> (fixedPoint_) * static_cast<long>(other.fixedPoint_) >> nFractionalBits_);
	return (result);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits((static_cast<long>(fixedPoint_) << nFractionalBits_) / other.fixedPoint_);
	return (result);
}

// ---------------------Non-Member Functions----------------------------

std::ostream&	operator<<(std::ostream& out, const Fixed& obj)
{
	out << obj.toFloat();
	return (out);
}

