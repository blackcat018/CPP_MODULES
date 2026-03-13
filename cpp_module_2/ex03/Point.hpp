#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        Fixed const x;
        Fixed const y;
    public:
        Point();
        Point(float x_axis, float y_axis);
        Point(const Point& cpy);
        Point &operator=(const Point& op);
        ~Point();
        Fixed get_x() const;
        Fixed get_y() const ;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif