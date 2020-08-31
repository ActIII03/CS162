#include "shape.h"

//These are the operators you will be overloading
Point Point::operator + (const Point& p) const
{
}

Point& Point::operator += (const Point& p)
{
}

bool Point::operator == (const Point& p) const
{
    return false;    
}

ostream& operator << (ostream& out, const Point& p)
{
}

Shape& Shape::operator = (const Shape& s)
{
}

Shape& Shape::operator += (const Point& p)
{
    return *this;    
}

ostream& operator << (ostream& out, const Shape& s)
{
}

Shape Shape::operator + (const Shape & s) const
{

}

Point operator + (const Point& p, const Shape& s)
{
}

Point operator + (const Shape& s, const Point& p)
{
}

Circle operator + (const Point& p, const Circle& c)
{
}

Circle operator + (const Circle& c, const Point& p)
{
}

Circle& Circle::operator = (const Circle& c)
{
}


