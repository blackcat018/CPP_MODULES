#include"Fixed.hpp"

Fixed::Fixed(): value(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int param)
{
    // std::cout << "Int constructor called" << std::endl;
    value = param * (1 << bits);
}

Fixed::Fixed(const float param)
{
    // std::cout << "Float constructor called" << std::endl;
    value = roundf(param * (float)(1 << bits));
}

Fixed& Fixed::operator=(const Fixed& new_val)
{
    // std::cout <<"Copy assignment operator called" <<std::endl;
    if(this != &new_val)
    {
        this->value =new_val.value;
    }
    return(*this);
}

Fixed::Fixed(const Fixed& cpy)
{
    // std::cout << "Copy constructor called " <<std::endl;
    this->value = cpy.value;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" <<std::endl;
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


//arithmetics
Fixed Fixed::operator+(const Fixed& add) const
{
    return Fixed(this->toFloat() + add.toFloat());
}

Fixed Fixed::operator*(const Fixed& mult) const
{
    return Fixed(this->toFloat() * mult.toFloat());
}

Fixed Fixed::operator-(const Fixed& sub) const
{
    return Fixed(this->toFloat() - sub.toFloat());
}

Fixed Fixed::operator/(const Fixed& div) const
{
    if(div.toFloat() == 0)
    {
        std::cerr<< "Bro! you cannot devide by zero!" <<std::endl;
        return(Fixed());
    }
    return Fixed(this->toFloat()/ div.toFloat());
}

//comparisons

bool Fixed::operator<(const Fixed& comp)const 
{
    return(value < comp.value);
}
bool Fixed::operator<=(const Fixed& comp)const 
{
    return(value <= comp.value);
}
bool Fixed::operator>(const Fixed& comp)const
{
    return(value > comp.value);
}
bool Fixed::operator>=(const Fixed& comp)const
{
    return(value >= comp.value);
}
bool Fixed::operator==(const Fixed& comp)const
{
    return(value == comp.value);
}

bool Fixed::operator!=(const Fixed& comp)const
{
    return(value != comp.value);
}

Fixed& Fixed::operator++()
{
    this->value++;
    return(*this);
}

Fixed& Fixed::operator--()
{
    this->value--;
    return(*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp;
    tmp.value = this->value++;
    return(tmp);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp;
    tmp.value = this->value--;
    return(tmp);
}

Fixed& Fixed::min(Fixed& a,Fixed& b)
{
    if(a.value <= b.value)
        return(a);
    return(b);
}

const Fixed& Fixed::min(const Fixed& a,const Fixed& b)
{
    if(a.value <= b.value)
        return(a);
    return(b);
}

Fixed& Fixed::max(Fixed& a,Fixed& b)
{
    if(a.value >= b.value)
        return(a);
    return(b);
}

const Fixed& Fixed::max(const Fixed& a,const Fixed& b)
{
    if(a.value >= b.value)
        return(a);
    return(b);
}