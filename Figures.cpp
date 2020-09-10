#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cmath>
#include <iomanip>

using namespace std;

struct Figure {
    virtual string Name() = 0;
    virtual double Perimeter() = 0;
    virtual double Area() = 0;
};

class Rect : public Figure {
public:
    explicit Rect( const double& width, const double& height) : width_(width), height_(height){}
    string Name() override { return name; }
    double Perimeter() override { return 2.0 * (width_ + height_); }
    double Area() override { return width_ * height_; }
private:
    const string name = "RECT";
    const double width_;
    const double height_;
};

class Triangle : public Figure {
public:
    explicit Triangle( const double& a, const double& b, const double& c ) :
            a_(a), b_(b), c_(c) {}
    string Name() override { return name; }
    double Perimeter() override { return a_ + b_ + c_; }
    double Area() override {
        double p = (a_ + b_ + c_) / 2;
        return sqrt(p * (p - a_) * (p - b_) * (p - c_));
    }
private:
    const string name = "TRIANGLE";
    const double a_;
    const double b_;
    const double c_;
};

class Circle : public Figure {
public:
    explicit Circle(const double r) : radius(r){}
    string Name() override { return name; }
    double Perimeter() override { return 2.0 * 3.14 * radius; }
    double Area() override { return 3.14 * pow(radius, 2); }
private:
    const string name = "CIRCLE";
    const double radius;
};

shared_ptr<Figure> CreateFigure(istringstream& is)
{
    string figure;
    is >> figure;

    if (figure == "RECT")
    {
        int width, height;
        is >> width >> height;
        return make_shared<Rect>(width, height);
    }

    if (figure == "TRIANGLE")
    {
        int a, b, c;
        is >> a >> b >> c;
        return make_shared<Triangle>(a, b, c);
    }

    if (figure == "CIRCLE")
    {
        int r;
        is >> r;
        return make_shared<Circle>(r);
    }

}
