#include "vector.h"
#include <cmath>
namespace VECTOR
{

const double Rad_to_deg = 45.0 / atan(1.0);

void VECTOR::Vector::set_x()
{
    x = mag * cos(ang);
}

void VECTOR::Vector::set_y()
{
    y = mag * sin(ang);
}

void VECTOR::Vector::set_mag()
{
    mag = sqrt(x*x+y*y);
}

void VECTOR::Vector::set_ang()
{
    if(x==0&&y==0)
        ang = 0;
    else
        ang = atan2(y,x);
}

VECTOR::Vector::Vector()
{
    x=y=mag=ang=0.0;
    mode=RECT;
    std::cout << "Create function!" << std::endl;
}

VECTOR::Vector::Vector(double n1, double n2, VECTOR::Vector::Mode form)
{
    if(form==RECT)
    {
        x=n1;
        y=n2;
        set_mag();
        set_ang();
    }
    else if(form==POL)
    {
        mag=n1;
        ang=n2/Rad_to_deg;
        set_x();
        set_y();
    }
    else
    {
        std::cout << "Error! All is reset..." << std::endl;
        x=y=mag=ang=0.0;
        mode=RECT;
    }
}

void VECTOR::Vector::reset(double n1, double n2, VECTOR::Vector::Mode form)
{
    if(form==RECT)
    {
        x=n1;
        y=n2;
        set_mag();
        set_ang();
    }
    else if(form==POL)
    {
        mag=n1;
        ang=n2/Rad_to_deg;
        set_x();
        set_y();
    }
    else
    {
        std::cout << "Error! All is reset..." << std::endl;
        x=y=mag=ang=0.0;
        mode=RECT;
    }
}

VECTOR::Vector::~Vector()
{
    std::cout << "×ßÑ½×ß¡£¡£¡£!" << std::endl;
}

void VECTOR::Vector::polar_set()
{
    mode=POL;
}

void VECTOR::Vector::rect_set()
{
    mode=RECT;
}

VECTOR::Vector VECTOR::Vector::operator+(const VECTOR::Vector &b) const
{
    return Vector(x+b.x,y+b.y);
}

VECTOR::Vector VECTOR::Vector::operator-(const VECTOR::Vector &b) const
{
    return Vector(x-b.x,y-b.y);
}

VECTOR::Vector VECTOR::Vector::operator-() const
{
    return Vector(-x,-y);
}

VECTOR::Vector VECTOR::Vector::operator*(double n) const
{
    return Vector(x*n,y*n);
}

std::ostream & operator<<(std::ostream &os, const Vector &b)
{
    if (b.mode==Vector::RECT)
        os << "(x,y) = " << "(" << b.x << "," << b.y << ")" << std::endl;
    else if (b.mode==Vector::POL)
        os << "(mag,ang) = " << "(" << b.mag << "," << b.ang * Rad_to_deg<< ")" << std::endl;
    else
        os << "Error input!" << std::endl;
    return os;
}

VECTOR::Vector operator*(double n, const Vector &b)
{
    return b*n;
}
}
