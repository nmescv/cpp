#ifndef _TRASH_H_
#define _TRASH_H_
//============================================================
//
// Description:
// <purpose of this file>
//============================================================
#include "gen.h"

struct Person
{
    int age;
    int height;
    int weight;

    string name;
    string job;
};

bool isAdult(Person &p);
void checkDasha();

class _my_template_class
{
public:    
    _my_template_class();
    ~_my_template_class();
    
    void run();
private:    
    vector <string> main_array;    
};


#endif
