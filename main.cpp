#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

class Shape
{
public:
    virtual ~Shape() {}
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double radius) : radius(radius) {}
    double getArea() const override { return M_PI * radius * radius; }
    double getPerimeter() const override { return 2 * M_PI * radius; }
};
class Rectangle : public Shape
{
private:
    double length;
    double width;

public:
    Rectangle(double length, double width) : length(length), width(width) {}
    double getArea() const override { return length * width; }
    double getPerimeter() const override { return (2 * length) + (2 * width); }
};
class RightTriangle : public Shape
{
private:
    double base;
    double height;

public:
    RightTriangle(double base, double height) : base(base), height(height) {}
    double getArea() const override { return 0.5 * base * height; }
    double getPerimeter() const override
    {
        double thirdSide = sqrt(base * base + height * height);
        return base + height + thirdSide;
    }
};

class Square : public Rectangle
{
private:
    double length;

public:
    Square(double length) : Rectangle(length, length) {}
};

class IsoTriangle : public RightTriangle
{
private:
    double length;

public:
    IsoTriangle(double length) : RightTriangle(length, length) {}
};

void printToScreen(Shape *s)
{
    cout << "This shape is " << "[name]" << endl;
    cout << "With an area of " << s->getArea();
}

int main()
{
    Shape *rect = new Rectangle(6, 7);
    Shape *circ = new Circle(4);
    Shape *tri = new RightTriangle(3, 5);
    Shape *sqr = new Square(6);
    Shape *iso = new IsoTriangle(4);

    assert(rect->getArea());
    assert(rect->getPerimeter());
    assert(circ->getArea());
    assert(circ->getPerimeter());
    assert(tri->getArea());
    assert(tri->getPerimeter());
    assert(sqr->getArea());
    assert(sqr->getPerimeter());
    assert(iso->getArea());
    assert(iso->getPerimeter());
    cout << "all good" << endl;

    printToScreen(sqr);
    return 0;
}
