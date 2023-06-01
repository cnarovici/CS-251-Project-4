#pragma once

using namespace std;

class Shape
{
    protected:
        int x;
        int y;

    public: 
        //Default constructor for the Shape object.
        Shape() {
            x = 0;
            y = 0;
        }
        //Parameterized constructor that takes 2 ints.
        Shape(int x, int y) {
            this->x = x;
            this->y = y;
        }
        //Empty destructor.
        virtual ~Shape() {}
        //Copy Constructor.
        virtual Shape* copy() {
            Shape* temp = new Shape(x, y);
            return temp;
        }
        //Function to return the value stored in x.
        int getX() const {
            return x;
        }
        //Function to return the value stored in y.
        int getY() const {
            return y;
        }
        //Function to set the value of x.
        void setX(int x) {
            this->x = x;
        }
        //Function to set the value of y.
        void setY(int y) {
            this->y = y;
        }
        //Function to print the details of the shape.
        virtual void printShape() const {
            cout << "It's a Shape at x: " << x << ", y: " << y << endl;
        }
};


class Circle : public Shape 
{
    private:
        int radius;

    public: 
        //Default constructor for the Circle object.
        Circle() {
            radius = 0;
            x = 0;
            y = 0;
        }
        //Parameterized constructor for Circle object to change radius.
        Circle(int r) {
            radius = r;
            x = 0;
            y = 0;
        }
        //Parameterized constructor for Circle object to change radius, x, and y.
        Circle(int x, int y, int r) {
            this->x = x;
            this->y = y;
            radius = r;
        }
        //Destructor
        virtual ~Circle() {}
        //Copy constructor.
        virtual Circle* copy() {
            Circle* temp = new Circle(x, y, radius);
            return temp;
        }
        //Function that returns the radius of the Circle object.
        int getRadius() const {
            return radius;
        }
        //Function that sets the radius of the Circle object.
        void setRadius(int r) {
            radius = r;
        }
        //Function to print the details of the Circle.
        virtual void printShape() const {
            cout << "It's a Circle at x: " << x << ", y: " << y << ", radius: " << radius << endl;
        }
};


class Rectangle : public Shape 
{
    private:
        int width;
        int height;

    public: 
        //Default constructor for rectangle.
        Rectangle() {
            x = 0;
            y = 0;
            width = 0;
            height = 0;
        }
        //Parameterized Constructor
        Rectangle(int w, int h) {
            x = 0;
            y = 0;
            width = w;
            height = h;
        }
        //Parameterized Constructor
        Rectangle(int x, int y, int w, int h) {
            this->x = x;
            this->y = y;
            width = w;
            height = h;
        }
        //Destructor
        virtual ~Rectangle() {}
        //Copy constructor.
        virtual Rectangle* copy() {
            Rectangle* temp = new Rectangle(x, y, width, height);
            return temp;
        }
        //Function that returns the width of Rectangle.
        int getWidth() const {
            return width;
        }
        //Function that returns the height of Rectangle.
        int getHeight() const {
            return height;
        }
        //Function that sets the width of Rectangle.
        void setWidth(int w) {
            width = w;
        }
        //Function that sets the height of Rectangle.
        void setHeight(int h) {
            height = h;
        }
        //Function to print the details of the Rectangle.
        virtual void printShape() const {
            cout << "It's a Rectangle at x: " << x << ", y: " << y << " with width: " << width << " and height: " << height << endl;
        }
};

class RightTriangle : public Shape 
{
    private:
        int base;
        int height;

    public: 
        //Default constructor.
        RightTriangle() {
            x = 0;
            y = 0;
            base = 0;
            height = 0;
        }
        //Parametarized Constructor.
        RightTriangle(int b, int h) {
            x = 0;
            y = 0;
            base = b;
            height = h;
        }
        //Parametarized Constructor.
        RightTriangle(int x, int y, int b, int h) {
            this->x = x;
            this->y = y;
            base = b;
            height = h;
        }
        //Destructor.
        virtual ~RightTriangle() {}
        //Copy constructor.
        virtual RightTriangle* copy() {
            RightTriangle* temp = new RightTriangle(x, y, base, height);
            return temp;
        }
        //Function that returns the value of base.
        int getBase() const {
            return base;
        }
        //Function that returns the value of height.
        int getHeight() const {
            return height;
        }
        //Function that sets the value of base.
        void setBase(int b) {
            base = b;
        }
        //Function that sets the value of base.
        void setHeight(int h) {
            height = h;
        }
        //Function to print the details of the Right Triangle.
        virtual void printShape() const {
            cout << "It's a Right Triangle at x: " << x << ", y: " << y << " with base: " << base << " and height: " << height << endl;
        }
};
