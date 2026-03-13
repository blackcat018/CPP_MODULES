#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int value;
        static const int bits = 8;
    public:
        Fixed();
        Fixed(const int param);
        Fixed(const float param);
        Fixed(const Fixed& cpy);
        Fixed& operator=(const Fixed& newVal);
        ~Fixed();
        float toFloat( void ) const;
        int toInt( void ) const;
        int getRawBits( void ) const;
        void setRawBits( int const raw );

        //comparison
        bool operator<(const Fixed& comp)const;
        bool operator>(const Fixed& comp)const;
        bool operator<=(const Fixed& comp)const;
        bool operator>=(const Fixed& comp)const;
        bool operator==(const Fixed& comp)const;
        bool operator!=(const Fixed& comp)const;

        //arithmetic

        Fixed operator+(const Fixed& add) const;
        Fixed operator*(const Fixed& mult) const;
        Fixed operator-(const Fixed& sub)const;
        Fixed operator/(const Fixed& div)const;

        //pre inrement or decrement
        Fixed& operator++();
        Fixed& operator--();
        //post increment or decrement
        Fixed operator++(int);
        Fixed operator--(int);


        //min & max normal
        static Fixed& min(Fixed &a, Fixed &b);
        static Fixed& max(Fixed &a, Fixed &b);

        //min & max consts
        static const Fixed& min(const Fixed &a,const Fixed &b);
        static const Fixed& max(const Fixed &a,const Fixed &b);
};

std::ostream& operator<<(std::ostream& output,const Fixed&op);

#endif