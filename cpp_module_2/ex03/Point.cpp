#include "Point.hpp"

Point::Point():x(0),y(0){};

Point::Point(float x_axis, float y_axis):x(x_axis),y(y_axis){}

Point::Point(const Point& cpy):x(cpy.x),y(cpy.y){}

Point& Point::operator=(const Point& op)
{
    (void)op;//cuz x and y are tatic and cannot reassigne them grrrrrr
    return(*this);
}
Point::~Point(){}

Fixed Point::get_x() const
{
    return(x);
}
Fixed Point::get_y() const
{
    return(y);
}

