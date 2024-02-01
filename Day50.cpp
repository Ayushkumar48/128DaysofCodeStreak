#include <iostream>
#include <math.h>
using namespace std;

class Rectangle{
    float length;
    float height;
    public:
    Rectangle(float length, float height){
        this->length=length;
        this->height=height;
    }
    float perimeter(float length, float height){
        return 2.0*(length+height);
    }
    float area(float length, float height){
        return length*height;
    }
};

class Student{
    string name;
    float mark1;
    float mark2;
    public:
    Student(){
        this->name="";
        this->mark1=0;
        this->mark2=0;
    }
    Student(string name, float mark1, float mark2){
        this->name=name;
        this->mark1=mark1;
        this->mark2=mark2;
    }
    float getMarks(int marknumber){
        if(marknumber==1){
            return mark1;
        }
        return mark2;
    }
    float calc_total(){
        return this->mark1+this->mark2;
    }
};

class Calculator{
    float num1;
    float num2;
    public:
    Calculator(){
        this->num1=0;
        this->num2=0;
    }
    float add(float n1, float n2){
        return n1+n2;
    }
    float subtract(float n1, float n2){
        return n2-n1;
    }
    float multiply(float n1, float n2){
        return n1*n2;
    }
    float divide(float n1, float n2){
        return n2/n1;
    }
};

class Point{
    int x,y;
    public:
    Point(){
        this->x=0;
        this->y=0;
    }
    Point(int x, int y){
        this->x=x;
        this->y=y;
    }
    double distance(){
        return sqrt(pow((this->x),2)+pow((this->y),2));
    }
    double distance(int x1, int y1){
        return sqrt(pow(x-x1,2)+pow(y-y1,2));
    }
};

int main()
{
    
    return 0;
}
