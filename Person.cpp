// Eric Lange
// COMP 4472

#include "Person.hpp"
#include <iostream>

// Constructor
Person::Person(string name, string sex):
    name(name),
    sex(sex)
{}


// Getters
string Person::getName() {
    return name;
}

string Person::getSex() {
    return sex;
}

Person* Person::getFather() {
    return father;
}

Person* Person::getMother() {
    return mother;
}


// Setters
void Person::setName(string name) {
    this->name = name;
}

void Person::setSex(string sex) {
    this->sex = sex;
}

void Person::setFather(Person* father) {
    this->father = father;
}

void Person::setMother(Person* mother){
    this->mother = mother;
}

void Person::addChild(Person* child) {
    children.push_back(*child);
}


void Person::Print() {
    printf(FWHT("\n%s\n"), name.c_str());
    
    printf(FYEL("\tSex: "));
    if(sex == "M") {
        printf(FBLU("Male\n"));
    } else if (sex == "F") {
        printf(FMAG("Female\n"));
    } else {
        printf(FRED("unknown\n"));
    }

    printf(FYEL("\tFather: "));
    if(father == nullptr) {
        printf(FRED("unknown\n"));
    } else {
        printf(FWHT("%s\n"), father->name.c_str());
    }
   
    printf(FYEL("\tMother: "));
    if(mother == nullptr) {
        printf(FRED("unknown\n"));
    } else {
        printf(FWHT("%s\n"), mother->name.c_str());
    }
    
    printf(FYEL("\tChildren: "));
    if(children.empty()) {
         printf(FRED("none\n"));
    } else {
    
        list<Person>::iterator it;
        
        for(it = children.begin(); it != children.end(); it++) {
          printf(FWHT("%s "), it->getName().c_str());
        }
        
        printf("\n");
    }
}






