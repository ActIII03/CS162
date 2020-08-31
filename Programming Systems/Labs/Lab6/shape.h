#include "point.h"
#include <stdio.h>
#include <stdlib.h>

enum Color { red, orange, yellow, green, blue, violet };

class Shape
{
    public:
        Shape(int x, int y, const Color & c);
        Shape(const Shape&); // Copy constructor

        // These are already implemented
        bool operator == (const Shape&) const;
        bool operator != (const Shape&) const;

        virtual char* display() const; // generic display for the subclasses

        Shape& operator =  (const Shape&);
        Shape operator +  (const Shape&) const; 
        Shape& operator += (const Point&);

        friend ostream& operator << (ostream&, const Shape&); // Insertion operator *hint: how might we use this without needing to overload this operator for our children?*
        friend Point operator + (const Point &, const Shape &);
        friend Point operator + (const Shape &, const Point &);

    private:
        Point center;
        Color color;
};

class Circle : public Shape 
{
    public:
        //Constructor that creates a circle with radius r, centered at point(x,y)
        Circle(int x, int y, int r, const Color  &c);
        Circle(const Circle &); // Copy constructor

        // Already implemented
        bool operator == (const Circle&)const;
        bool operator != (const Circle&)const;
        char* display()const;

        Circle& operator =  (const Circle&); // Overloaded Assignment Operator
        Circle operator *  (const int scale)const; // Overloaded * operator to modify size of circle by a scalar
        Circle& operator *= (const int scale);

    private:
        int radius;
};

class Square : public Shape
{
    public:
        Square(int x, int y, int r, const Color &c);
        Square(const Square&); // Copy constructor

        // Already implemented
        bool operator == (const Square&)const;
        bool operator != (const Square&)const;
        char* display()const;

        using Shape::operator+;
        using Shape::operator+=;
        
        Square& operator = (const Square&); // Overloaded Assignment Operator
        Square operator +  (const int i)const; // Returns a new square with side length increase by i
        Square& operator += (const int); // Alters the current square by increase the side length

    public:
        int side;
};

ostream& operator << (ostream& out, const Color & c);
void tests();
