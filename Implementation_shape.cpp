//
// Created by ssaito on 1/15/16.
//

#include "shape.h"
#include <memory>
#include <iostream>

using namespace std;

int shape::m_total = 0;

struct square::Impl{
    Impl(double side, double side1, double side2, double side3):m_side(side), m_side1(side1), m_side2(side2), m_side3(side3){};
    Impl* clone() const{return new Impl(*this);};
    //Impl(Impl& other){return new Impl(other.m_side,other.m_side1,other.m_side2,other.m_side3)};
    void move(Impl* other){
        m_side = other->m_side;
        m_side1 = other->m_side1;
        m_side2 = other->m_side2;
        m_side3 = other->m_side3;
        other->m_side = 0;
        other->m_side1  = 0;
        other->m_side2 = 0;
        other->m_side3 = 0;
    };
    double m_side;
    double m_side1;
    double m_side2;
    double m_side3;
};
double square::getSide(){return pimpl->m_side;} //Getter m_side
double square::getSide1(){return pimpl->m_side1;} //Getter m_side1
double square::getSide2(){return pimpl->m_side2;} //Getter m_side2
double square::getSide3(){return pimpl->m_side3;} //Getter m_side3
void square::setSide(double side){pimpl->m_side = side;} //Setter m_side
void square::setSide1(double side){pimpl->m_side1 = side;} //Setter m_side1
void square::setSide2(double side){pimpl->m_side2 = side;} //Setter m_side2
void square::setSide3(double side){pimpl->m_side3 = side;} //Setter m_side3
square::square(double side):pimpl(new Impl(side,0,0,0)){} //Constructor - Changed so second input defaults to 0 and third input defaults to 0
square::square(double side, double side1):pimpl(new Impl(side,side1,0,0)){} //Constructor Overload 1
square::square(double side, double side1, double side2):pimpl(new Impl(side,side1,side2,0)){} //Constructor Overload 2
square::square(double side, double side1, double side2, double side3):pimpl(new Impl(side,side1,side2,side3)){} //Constructor Overload 2
square::square(const square& other):pimpl(other.pimpl->clone()){} //Copy Constructor
square& square::operator=(square& rhs) {
    square temp = square(rhs);
    swap(pimpl,temp.pimpl);
    return *this;
} //Copy Assignment Operator
square::~square(){std::cout << "DESTRUCT SQUARE" << std::endl; delete pimpl;} //Destructor
square::square(square&& other): pimpl(new Impl(0,0,0,0)){swap(pimpl,other.pimpl);} //Move Constructor
square& square::operator=(square&& rhs) {
    if (this!=&rhs){
        pimpl->move(rhs.pimpl);
    }
    return *this;
} //Move Assignment Operator
void square::draw(){ std::cout << "Square = " << m_id << " " << pimpl->m_side << std::endl;}

struct circle::Impl{
    Impl(double radius, double side):m_radius(radius), m_side(side){};
    //Impl(Impl& other){return new Impl(other.m_radius,other.m_side)};
    Impl* clone() const{return new Impl(*this);};
    void move(Impl* other){
        m_radius = other->m_radius;
        m_side = other->m_side;
        other->m_radius = 0;
        other->m_side = 0;
    };
    double m_radius;
    double m_side;
};
double circle::getRadius(){return pimpl->m_radius;} //Getter m_side
double circle::getSide(){return pimpl->m_side;}
void circle::setSide(double side) {pimpl->m_side = side;}
void circle::setRadius(double radius){pimpl->m_radius = radius;} //Setter m_side
circle::circle(double radius, double side):pimpl(new Impl(radius,side)){} //Constructor - Changed so second input defaults to 0 and third input defaults to 0
circle::circle(const circle& other):pimpl(other.pimpl->clone()){} //Copy Constructor
circle& circle::operator=(circle& rhs) {
    circle temp = circle(rhs);
    swap(pimpl,temp.pimpl);
    return *this;
} //Copy Assignment Operator
circle::~circle(){
    std::cout << "DESTRUCT CIRCLE" << std::endl;
    delete pimpl;
} //Destructor
circle::circle(circle&& other): pimpl(new Impl(0,0)){
    swap(pimpl,other.pimpl);
} //Move Constructor
circle& circle::operator=(circle&& rhs) {
    if (this!=&rhs){
         pimpl->move(rhs.pimpl);
    }
    return *this;
} //Move Assignment Operator
void circle::draw(){ std::cout << "Circle = " << m_id << " " << pimpl->m_radius << std::endl;}

