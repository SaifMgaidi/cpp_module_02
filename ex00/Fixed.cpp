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
