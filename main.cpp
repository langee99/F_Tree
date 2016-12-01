// Eric Lange
// COMP 4472

#include <iostream>
#include "Person.hpp"
#include <map>

int main(int argc, const char * argv[]) {

    string in;
    string name, pName;
    map<string, Person> people;
    map<string, Person>::iterator it, pIt;
    
    while(cin >> in) {
        
        cin >> name;
        if (in == "PERSON") {
            
            pName = name; // Keep track of what person is currently being evaluated
            
            people.insert(pair<string, Person>(name, *new Person(name, "")));
            
        } else if (in == "FATHER_OF") {
            
            // If child exists make pName their father
            // Else create child and set their father to pName
            if((it = people.find(name)) != people.end()) {
                
                pIt = people.find(pName);
                
                if (pIt->second.getSex() == "M" || pIt->second.getSex() == "") {
                    
                    // Check to make sure you aren't assigning a person to be its own father
                    if(pIt->second.getName() != it->second.getName()){
                        
                        it->second.setFather(&pIt->second); // Set the childs father
                        pIt->second.addChild(&it->second);  // Add child into fathers children list
                        
                        // Assign the father's sex if it's currently unassigned
                        if(pIt->second.getSex() == "")
                            pIt->second.setSex("M");
                        
                    } else {
                        printf(FYEL("Warning[\"%s\"]: \"%s\" cannot be their own father\n"), in.c_str(), pName.c_str());
                    }
                    
                } else {
                    printf(FYEL("Warning[\"%s\"]: \"%s\" is a female\n"), in.c_str(), name.c_str());
                }
            }
            else {
                
                // Create a new person
                people.insert(pair<string, Person>(name, *new Person(name, "")));
                it = people.find(name);
                pIt = people.find(pName);
                
                it->second.setFather(&pIt->second); // Assign pName as their father
                pIt->second.addChild(&it->second);  // Add child into fathers children set
                
                // Assign the fathers sex if it's currently unassigned
                if(pIt->second.getSex() == "")
                    pIt->second.setSex("M");
                
            }

        } else if (in == "FATHER") {
            
            // If name exists, set name as pName's father
            // Else create person(name) and set pName's father as person(name)
            if((it = people.find(name)) != people.end()) {
                pIt = people.find(pName);
                
                // Make sure pName doesn't already have a father
                if (pIt->second.getFather() == nullptr){
                    
                    // Make sure the fathers sex isn't female
                    if (it->second.getSex() == "M" || it->second.getSex() == "") {
                        pIt->second.setFather(&it->second);
                        it->second.addChild(&pIt->second);
                        it->second.setSex("M");
                    } else {
                        printf(FYEL("Warning[\"%s\"]: \"%s\" is a female\n"), in.c_str(), name.c_str());
                    }
                    
                } else {
                    printf(FYEL("Warning[\"%s\"]: \"%s\" already has a father\n"), in.c_str(), pName.c_str());
                }
            } else {
                pIt = people.find(pName);
                
                // Make sure the pName doesn't already have a father
                if(pIt->second.getFather() == nullptr){
                    people.insert(pair<string, Person>(name, *new Person(name, "M")));
                    it = people.find(name);
                    pIt->second.setFather(&it->second);
                    it->second.addChild(&pIt->second);
                } else {
                    printf(FYEL("Warning[\"%s\"]: \"%s\" already has a father\n"), in.c_str(), pName.c_str());
                }
                
            }
            
        } else if (in == "MOTHER_OF") {
            
            // If child exists make pName the mother
            // Else create child and set father to pName
            if((it = people.find(name)) != people.end()) {
                
                pIt = people.find(pName);
                if (pIt->second.getSex() == "F" || pIt->second.getSex() == "") {
                    
                    // Check to make sure you aren't assigning a person to be its own mother
                    if (pIt->second.getName() != it->second.getName()) {
                    
                        it->second.setMother(&pIt->second);
                        pIt->second.addChild(&it->second);  // Add child into mothers children set
                    
                        // Assign the mothers sex if it's currently unassigned
                        if(pIt->second.getSex() == "")
                            pIt->second.setSex("F");
                    
                    } else {
                        printf(FYEL("Warning[\"%s\"]: \"%s\" cannot be their own mother\n"), in.c_str(), pName.c_str());
                    }
                } else {
                    printf(FYEL("Warning[\"%s\"]: \"%s\" is a male\n"), in.c_str(), pName.c_str());
                }
            } else {
                
                // Create a new person
                people.insert(pair<string, Person>(name, *new Person(name, "")));
                
                it = people.find(name);
                pIt = people.find(pName);
                
                it->second.setMother(&pIt->second); // Assign pName as their mother
                pIt->second.addChild(&it->second);  // Add child into mothers children set
                
                // Assign the mothers sex if it's currently unassigned
                if(pIt->second.getSex() == "")
                    pIt->second.setSex("F");
            
            }
            
        } else if (in =="MOTHER") {
            
            // If name exists, set name as pName's mother
            // Else create person(name) and set pName's mother as person(name)
            if((it = people.find(name)) != people.end()) {
                
                pIt = people.find(pName);
                
                // Make sure pName doesn't already have a mother
                if (pIt->second.getMother() == nullptr){
                    
                    // Make sure the mothers sex isn't male
                    if (it->second.getSex() == "F" || it->second.getSex() == "") {
                        pIt->second.setMother(&it->second);
                        it->second.addChild(&pIt->second);
                        it->second.setSex("F");
                    } else {
                        printf(FYEL("Warning[\"%s\"]: \"%s\" is a male\n"), in.c_str(), name.c_str());
                    }
                    
                } else {
                    printf(FYEL("Warning[\"%s\"]: \"%s\" already has a mother\n"), in.c_str(), pName.c_str());
                }
            
            } else {
                pIt = people.find(pName);
                
                // Make sure the pName doesn't already have a mother
                if(pIt->second.getMother() == nullptr) {
                    
                    // Create a new person
                    people.insert(pair<string, Person>(name, *new Person(name, "F")));
                    it = people.find(name);
                    
                    pIt->second.setMother(&it->second); // Assign the newly created person as pNames mother
                    it->second.addChild(&pIt->second);  // Add pName to the newly created persons children set
                } else {
                    printf(FYEL("Warning[\"%s\"]: \"%s\" already has a mother\n"), in.c_str(), pName.c_str());
                }
            }
            
        } else if (in == "SEX") {
            
            if((it = people.find(pName)) != people.end()) {
                it->second.setSex(name);
            }
            
        } else {
            printf(FRED("Error:    input: \"%s\" name: \"%s\" pName: \"%s\"\n"), in.c_str(), name.c_str(), pName.c_str());
        }
    }
    
    for (it = people.begin(); it != people.end(); it++) {
        it->second.Print();
    }

    return 0;
}










