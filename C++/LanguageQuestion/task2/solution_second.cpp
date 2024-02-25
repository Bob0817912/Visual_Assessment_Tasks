#include <iostream>
using namespace std;

class Shape {
public:
    Shape(char id_){
        id = id_;
    }
    virtual void calculateArea(){}
    void displayArea(){
        cout << "Area of " << id << " is " << area << endl;
    }
protected:
    char id;
    double area;
};

class Circle : public Shape {
public:
    Circle(char id_) : Shape(id_){};
    void calculateArea(){
        area = 3.14*radius*radius;
    }
    void set(double radius_){
        radius = radius_;
    }
private:
    double radius;
};


class Rectangle : public Shape {
public:
    Rectangle(char id_) : Shape(id_){};
    void calculateArea(){
        area = width * height;
    }
    void set(double width_,double height_){
        width = width_;
        height = height_;
    }
private:
    double width,height;
};
int main(){
    Circle circle('A');
    circle.set(2);
    Rectangle rectangle('B');
    rectangle.set(3,4);
    circle.calculateArea();
    rectangle.calculateArea();
    circle.displayArea();
    rectangle.displayArea();
    return 0;
}