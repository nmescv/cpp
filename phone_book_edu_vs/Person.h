#ifndef _PERSON_H_
#define _PERSON_H_
//============================================================
// 2011 
//============================================================
// File:           Person.h
// Author:         YS
//============================================================
// Description:
//============================================================
#include "gen.h" 

class Person
{
public:
    Person();
    virtual ~Person();
    
private:
    std::string name;
    std::string address;

};


class Student: public Person
//class Student
{
public:
    Student();
    ~Student();

    bool amIStudent();
    
private:
    std::string schoolName;
    std::string schoolAddress;
    bool isStudent;
};
bool validateStudent(Student s);

#endif
