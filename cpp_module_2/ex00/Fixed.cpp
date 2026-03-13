#include"Fixed.hpp"

Fixed::Fixed(): value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& cpy)
{
    std::cout << "Copy constructor called " <<std::endl;
    this->value = cpy.value;
}
Fixed& Fixed::operator=(const Fixed& op)
{
    std::cout << "Copy assignment operator called" <<std::endl;
    if(this != &op)
        this->value = op.getRawBits();
    return(*this);
}
Fixed::~Fixed()
{
    std::cout << "Destructor called" <<std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" <<std::endl;
    return value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" <<std::endl;
    value = raw;
}