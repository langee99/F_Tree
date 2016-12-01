// Eric Lange
// COMP 4472

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
#include <string>
#include <set>
#include <list>
#include "colors.h"

#endif /* Person_hpp */

using namespace std;

class Person {
    
public:
    Person(string name, string sex);
    void Print();
    
    // Setters
    void setName(string name);
    void setSex(string sex);
    void setFather(Person* father);
    void setMother(Person* mother);
    void addChild(Person* child);
    
    // Getters
    string getName();
    string getSex();
    Person* getFather();
    Person* getMother();

private:
    string name;
    string sex;
    Person* father;
    Person* mother;
    list<Person> children;
};
