#include <iostream>
#include <cstring>

using namespace std;

class Point
{
    public:
        Point();
        Point(int x, int y);
        Point(const Point& p);


        Point& operator = (const Point&);
        Point  operator + (const Point&) const;    // Add two points together
        Point  operator * (const int scale)const; // Multiplty x and y by the scale
        Point& operator += (const Point&);
        Point& operator *= (const int scale);

        bool operator == (const Point&)const;
        bool operator != (const Point&)const;
        
        friend ostream& operator << (ostream&, const Point&);
        friend istream& operator >> (istream&, Point&);

        // Used to test your implementation --Do not use--
        bool isEqual(const Point&)const;
    private:
        int x;
        int y;
};
