#include "Fixed.hpp"
#include "Point.hpp"

void testPoint(const Point& a, const Point& b, const Point& c, const Point& p)
{
    std::cout << "Testing point (" 
              << p.get_x().toFloat() << ", " 
              << p.get_y().toFloat() << ") : ";

    if (bsp(a, b, c, p))
        std::cout << "INSIDE";
    else
        std::cout << "OUTSIDE";

    std::cout << std::endl;
}

int main()
{
    Point A(0, 0);
    Point B(10, 0);
    Point C(5, 10);

    std::cout << "Triangle vertices:" << std::endl;
    std::cout << "A(0,0)  B(10,0)  C(5,10)\n" << std::endl;

    // clearly inside
    testPoint(A, B, C, Point(5, 5));

    // outside
    testPoint(A, B, C, Point(10, 10));

    // near edge
    testPoint(A, B, C, Point(5, 0));

    // vertex
    testPoint(A, B, C, Point(0, 0));

    // random tests
    testPoint(A, B, C, Point(4, 3));
    testPoint(A, B, C, Point(7, 2));
    testPoint(A, B, C, Point(2, 8));
    testPoint(A, B, C, Point(-1, 3));

    return 0;
}

// Triangle vertices:
// A(0,0)  B(10,0)  C(5,10)

// Testing point (5, 5) : INSIDE
// Testing point (10, 10) : OUTSIDE
// Testing point (5, 0) : OUTSIDE
// Testing point (0, 0) : OUTSIDE
// Testing point (4, 3) : INSIDE
// Testing point (7, 2) : INSIDE
// Testing point (2, 8) : OUTSIDE
// Testing point (-1, 3) : OUTSIDE