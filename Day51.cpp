// _main.cpp file
#include <iostream>
#include "Day30.cpp"
#include <assert.h>
using namespace std;

class Vehicle{
  string speed;
  string model;
  public:
  string getModel(){
    return model;
  }
  string getSpeed(){
    return speed;
  }
};

// Derived Class
class Car : public Vehicle {
  
  string name; //  Name of a Car
  
  public:
  Car() { // Default Constructor
    name = "";
  }
  
  // This function sets the name of the car
  void setDetails(string name) { // Setter Function
    this->name = name;
  }

  // This function calls the Base class functions and appends the result with the input 
  string getDetails(string carName) {

    string details = carName + ", " + getModel() + ", " + getSpeed(); // calling Base Class Function
    return details;
  } 
};

#include <iostream>
using namespace std;

class Animal {
  string Name;
  string Sound;
  
  public:
  Animal() {
    Name = "";
    Sound = "";
  }
  
  Animal(string nam, string soun) {
    Name = nam;
    Sound = soun;
  }
  
  void Animal_detail() {
    cout << "Animal Name : " << Name << endl;
    cout << "Animal Sound : " << Sound << endl;
  }
};

class Dog : public Animal {
  
  string family;
  
  public:
  Dog(string N, string S): Animal(N, S) {
    family = "Carnivores";
  }
  void Dog_detail() {
    Animal_detail();
    cout << "Dog's Family : " << family  << endl; 
  }
};

class Sheep : public Animal {
  
  string color;
  
  public:
  Sheep(string N, string S): Animal(N, S) {
    color = "White";
  }
  void Sheep_detail() {
    Animal_detail();
    cout << "Sheep Color: " << color << endl; 
  }
};

class Father{
  string eye_color;
  string hair_color;
  public:
    Father(string eye, string hair){
      eye_color=eye;
      hair_color=hair;
    }
    void Father_traits(){
      cout<<"Eye color : "<<eye_color<<endl;
      cout<<"Hair color : "<<hair_color<<endl;
    }
};

class Son:public Father{
  string name;
  public:
    Son(string name, string eye, string hair):Father(eye,hair){
      this->name=name;
    }
    void Son_traits(){
     Father_traits();
     cout<<name+" has beard!"<<endl;
    }
};

class Daughter : Father{
  string name;
  public:
    Daughter(string name, string eye, string hair):Father(eye,hair){
      this->name=name;
    }
    void Daughter_traits(){
      Father_traits();
      cout<<name+" has long hair!"<<endl;
    }
};

class DynamicArray {

    int *array;
    int capacity = 2;
    int size;

public:
    DynamicArray() {
        array = new int[capacity];
        size = 0;
    }

    void append(int element) {
        insertAt(element, size);
    }

    int length() {
        return size;
    }

    int get(int pos) {
        return array[pos];
    }

    ~DynamicArray() {
        delete[] array;
    }

private:
    void insertAt(int element, int pos) {
        assert(0 <= pos && pos <= size);
        if(size == capacity) {
            resize();
        }
        for(int i = size; i > pos; i--) {
            array[i] = array[i-1];
        }
        size++;
        array[pos] = element;
    }

    void resize() {
        capacity *= 2;
        int *temp = new int[capacity];
        copy(array, array + size, temp);
        delete [] array;
        array = temp;
    }

};

class DynamicArrayWithStats : public DynamicArray {
public:
    int max(){
        int max = get(0);
        for (int i = 1; i < length(); i++){
            if (get(i) > max)
                max = get(i);
        }
        return max;
    }
    int min(){
        int min = get(0);
        for (int i = 1; i < length(); i++){
            if (get(i) < min)
                min = get(i);
        }
        return min;
    }
    int mean(){
        int sum = 0;
        for (int i = 0; i < length(); i++){
            sum += get(i);
        }
        int mean = sum/length();
        return mean;
    }
};


class Shape {
  public:
  virtual float getArea() = 0;
};
// A Rectangle is a Shape with a specific width and height
class Rectangle : public Shape {   // derived form Shape class
  private:
  float width;
  float height;

  public:
  Rectangle(float wid, float heigh) {
    width = wid;
    height = heigh;
  }
  float getArea(){
    return width * height; 
  }
};

// A Circle is a Shape with a specific radius
class Circle : public Shape {
  private:
  float radius;

  public:
  Circle(float rad){
    radius = rad; 
  }
  float getArea(){
    return 3.14159f * radius * radius; 
  }
};

// A Square is a Shape with a specific length
class Square : public Shape {
  private:
  float length;

  public:
  Square(float len){
    length = len;
  }
  float getArea(){
    return length * length; 
  }
};


int main() {
  // Dog d("Pongo", "Woof Woof");
  // d.Dog_detail();
  
  // cout << endl;
  
  // Sheep s("Billy", "Baaa Baaa");
  // s.Sheep_detail();

  // Planet earth(6.38e6, 5.98e24);
  // double m = earth.getMass();
  // cout << "Mass: " << m << endl;
  // double gravStrength = earth.calculateGravity();
  // cout << "Gravitational strength: "<< gravStrength << endl;
  // Daughter obj("Rapunzel","Green","Golden");
  // obj.Daughter_traits();

  // Son Obj("Ralph","Brown","Black");
  // Obj.Son_traits();


  // DynamicArrayWithStats arr = DynamicArrayWithStats();
  // arr.append(2);
  // arr.append(6);
  // arr.append(4);
  // arr.append(1);
  // arr.append(3);
  // arr.append(8);
  // cout << "Array: ";
  // for(int i = 0; i < arr.length(); i++){
  //     cout << arr.get(i) << " ";
  // }
  // cout << endl; 
  // cout << "Max: " << arr.max() << endl;
  // cout << "Min: " << arr.min() << endl;
  // cout << "Mean: " << arr.mean() << endl;
  Shape * shape[3];   // Referencing Shape class to Rectangle object
  //Shape * shape1 = new Shape(); //Instantiating the shape object

  Rectangle r(2, 6);    // Creating Rectangle object
  shape[0] = &r;   // Referencing Shape class to Rectangle object
  
  Circle c(5);    // Creating Circle object
  shape[1] = &c;   // Referencing Shape class to Circle object

  Square s(10);   // Creating Square object
  shape[2] = &s;     // Referencing Shape class to Circle object

  for(int i=0; i<3; i++){
    cout << shape[i]->getArea() << endl;
  }  
  return 0;
}


// .cpp file
#include "Day30.h"

Planet::Planet(double r, double m){
  radius = r;
  mass = m;
}

double Planet::getMass(){
  return mass;
}

void Planet::setMass(double m){
  mass = m;
}

double Planet::getRadius(){
  return radius;
}

void Planet::setRadius(double r){
  radius = r;
}

double Planet::calculateGravity(){
  double gravity = (G * mass)/(radius * radius);
  return gravity;
}

// .h file
#ifndef DAY30_H
#define DAY30_H

class Planet {
  double radius;
  double mass;
  const double G = 6.673e-11;
  
  public:
  Planet(double r, double m);
  double getMass();
  void setMass(double m);
  double getRadius();
  void setRadius(double r);
  double calculateGravity();
};

#endif