//
// Created by ssaito on 1/15/16.
//

#ifndef LESSONBIG5_SHAPE_H
#define LESSONBIG5_SHAPE_H


#include <memory>

class shape{
public:
    int m_type;
    shape(){
        m_id = m_total++;
    }
    virtual void draw() =0;
    virtual ~shape(){};

protected:
    int m_id;
    static int m_total;
};

class square: public shape{
public:
    square(double side); //Constructor
    square(double side, double side1); //Constructor Overload1
    square(double side, double side1, double side2); //Constructor Overload2
    square(double side, double side1, double side2, double side3);
    square(const square& other); //Copy Constructor
    double getSide(); //getter
    void setSide(double side); //setter
    double getSide1();
    void setSide1(double side);
    double getSide2();
    void setSide2(double side);
    double getSide3();
    void setSide3(double side);
    square(square&& other); //Move Constructor
    square& operator=(square& rhs); //Copy Assignment Operator
    square& operator=(square&& rhs); //Move Assignment Operator
    virtual ~square(); //Destructor
    void draw();
  //  static shape* Create() {return new square(0,0,0,0)};
private:
    struct Impl;
    Impl* pimpl;
};

class circle: public shape{
public:
    circle(double radius, double side); //Constructor
    circle(const circle& other); //Copy Constructor
    double getRadius(); //getter
    void setRadius(double radius); //setter
    double getSide();
    void setSide(double side);
    circle(circle&& other); //Move Constructor
    circle& operator=(circle& rhs); //Copy Assignment Operator
    circle& operator=(circle&& rhs); //Move Assignment Operator
    virtual ~circle(); //Destructor
    void draw();
    //static shape* Create() {return new circle(0,0)};
private:
    struct Impl;
    Impl* pimpl;
};

class shapeFactory{
public:

    shape* createCircleInstance(double v1, double v2){
        shape* temp = new circle(v1,v2);
        temp->m_type = 0;
        return temp;
    }
    shape* createSquareInstance(double v1, double v2, double v3){
        shape* temp = new square(v1,v2,v3);
        temp->m_type = 1;
        return temp;
    }

};




#endif //LESSONBIG5_SHAPE_H
