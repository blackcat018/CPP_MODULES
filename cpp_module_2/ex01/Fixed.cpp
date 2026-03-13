#include"Fixed.hpp"

Fixed::Fixed(): value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int param)
{
    std::cout << "Int constructor called" << std::endl;
    value = param * (1 << bits);
}

Fixed::Fixed(const float param)
{
    std::cout << "Float constructor called" << std::endl;
    value = roundf(param * (float)(1 << bits));
}

Fixed& Fixed::operator=(const Fixed& new_val)
{
    std::cout <<"Copy assignment operator called" <<std::endl;
    if(this != &new_val)
    {
        this->value =new_val.value;
    }
    return(*this);
}

Fixed::Fixed(const Fixed& cpy)
{
    std::cout << "Copy constructor called " <<std::endl;
    this->value = cpy.value;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" <<std::endl;
}

float Fixed::toFloat() const
{
    float real_value;
    real_value = value / (float)(1 << bits);
    return real_value;
}
int Fixed::toInt( void ) const
{
    int real_value;
    real_value = value / (1 << bits);
    return real_value;
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

std::ostream& operator<<(std::ostream& output,const Fixed& op )
{
    output << op.toFloat();
    return output;
}