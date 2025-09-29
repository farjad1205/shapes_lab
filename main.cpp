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
    virtual string getName() const = 0;
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double radius) : radius(radius) {}
    double getArea() const override { return M_PI * radius * radius; }
    double getPerimeter() const override { return 2 * M_PI * radius; }
    string getName() const override { return "Circle"; }
};

class Rectangle : public Shape
{
private:
    double length;
    double width;

public:
    Rectangle(double length, double width) : length(length), width(width) {}
    double getArea() const override { return length * width; }
    double getPerimeter() const override { return 2 * (length + width); }
    string getName() const override { return "Rectangle"; }
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
    string getName() const override { return "Right Triangle"; }
};

class Square : public Rectangle
{
private:
    double length;

public:
    Square(double length) : Rectangle(length, length), length(length) {}
    string getName() const override { return "Square"; }
};

class IsoTriangle : public RightTriangle
{
private:
    double length;

public:
    IsoTriangle(double length) : RightTriangle(length, length), length(length) {}
    string getName() const override { return "IsoTriangle"; }
};

void printAreaToScreen(Shape *s)
{
    cout << "This shape is a " << s->getName()
         << " with an area of " << s->getArea() << endl;
}

int main()
{
    Shape *rect = new Rectangle(6, 7);
    Shape *circ = new Circle(4);
    Shape *tri = new RightTriangle(3, 5);
    Shape *sqr = new Square(6);
    Shape *iso = new IsoTriangle(4);

    assert(rect->getArea() == 42);
    assert(rect->getPerimeter() == 26);

    assert(circ->getArea() == M_PI * 16);
    assert(circ->getPerimeter() == 2 * M_PI * 4);

    assert(tri->getArea() == 7.5);
    assert(tri->getPerimeter() == 3 + 5 + sqrt(34));

    assert(sqr->getArea() == 36);
    assert(sqr->getPerimeter() == 24);

    assert(iso->getArea() == 8);
    assert(iso->getPerimeter() == 4 + 4 + sqrt(32));

    cout << "All tests passed!" << endl;

    printAreaToScreen(rect);
    printAreaToScreen(circ);
    printAreaToScreen(tri);
    printAreaToScreen(sqr);
    printAreaToScreen(iso);

    delete rect;
    delete circ;
    delete tri;
    delete sqr;
    delete iso;

    return 0;
}
