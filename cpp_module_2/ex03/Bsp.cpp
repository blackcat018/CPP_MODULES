#include "Fixed.hpp"
#include "Point.hpp"

static Fixed calc_area(Point a, Point b, Point c)
{
    Fixed ret = a.get_x() * (b.get_y() - c.get_y()) + 
                b.get_x() * (c.get_y() - a.get_y()) +
                c.get_x() * (a.get_y() - b.get_y()) ;
                return(ret);
} 


bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed tr_1 = calc_area(point,b,c);
    Fixed tr_2 = calc_area(a,point,c);
    Fixed tr_3 = calc_area(a,b,point);
    if(tr_1 * tr_2 > 0 && tr_2 * tr_3 >0  && (tr_1 != 0 && tr_2 !=0 && tr_3 != 0))
        return true;
    else
        return false;

}
