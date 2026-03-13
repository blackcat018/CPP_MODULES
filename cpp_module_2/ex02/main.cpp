#include"Fixed.hpp"

int main()
{
    std::cout << "===== CONSTRUCTORS =====" << std::endl;
    Fixed a;
    Fixed b(10);
    Fixed c(42.42f);
    Fixed d(b);
    a = Fixed(5.05f);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;

    std::cout << "\n===== CONVERSIONS =====" << std::endl;
    std::cout << "a as int = " << a.toInt() << std::endl;
    std::cout << "c as float = " << c.toFloat() << std::endl;

    std::cout << "\n===== ARITHMETIC =====" << std::endl;
    Fixed x(5.5f);
    Fixed y(2);

    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;

    std::cout << "x + y = " << x + y << std::endl;
    std::cout << "x - y = " << x - y << std::endl;
    std::cout << "x * y = " << x * y << std::endl;
    std::cout << "x / y = " << x / y << std::endl;

    std::cout << "\n===== COMPARISONS =====" << std::endl;
    std::cout << "x > y : " << (x > y) << std::endl;
    std::cout << "x < y : " << (x < y) << std::endl;
    std::cout << "x >= y : " << (x >= y) << std::endl;
    std::cout << "x <= y : " << (x <= y) << std::endl;
    std::cout << "x == y : " << (x == y) << std::endl;
    std::cout << "x != y : " << (x != y) << std::endl;

    std::cout << "\n===== INCREMENT / DECREMENT =====" << std::endl;
    Fixed i;

    std::cout << "i = " << i << std::endl;
    std::cout << "++i = " << ++i << std::endl;
    std::cout << "i = " << i << std::endl;

    std::cout << "i++ = " << i++ << std::endl;
    std::cout << "i = " << i << std::endl;

    std::cout << "--i = " << --i << std::endl;
    std::cout << "i-- = " << i-- << std::endl;
    std::cout << "i = " << i << std::endl;

    std::cout << "\n===== MIN / MAX =====" << std::endl;
    Fixed p(3.3f);
    Fixed q(7.7f);

    std::cout << "p = " << p << std::endl;
    std::cout << "q = " << q << std::endl;

    std::cout << "min(p, q) = " << Fixed::min(p, q) << std::endl;
    std::cout << "max(p, q) = " << Fixed::max(p, q) << std::endl;

    const Fixed r(8.8f);
    const Fixed s(1.1f);

    std::cout << "const min(r, s) = " << Fixed::min(r, s) << std::endl;
    std::cout << "const max(r, s) = " << Fixed::max(r, s) << std::endl;

    std::cout << "\n===== DIVIDE BY ZERO TEST =====" << std::endl;
    Fixed zero;
    std::cout << "x / zero = " << x / zero << std::endl;

    return 0;
}

//sibject main

// int main( void ) {
// Fixed a;
// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// std::cout << a << std::endl;
// std::cout << ++a << std::endl;
// std::cout << a << std::endl;
// std::cout << a++ << std::endl;
// std::cout << a << std::endl;
// std::cout << b << std::endl;
// std::cout << Fixed::max( a, b ) << std::endl;
// return 0;
// }


//result
// 0
// 0.00390625
// 0.00390625
// 0.00390625
// 0.0078125
// 10.1016
// 10.1016