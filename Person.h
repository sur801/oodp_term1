/*
 *  This file is header of sms.cpp
 *
 *  @author Jeonghoon Lee
 *  @since  2017-03-26
 */

#ifndef __PERSON_H__
#define __PERSON_H__

#include <iostream>
#include <vector>

typedef enum Group {
    FAMILY,
    FRIEND,
    COWORKER,
    ETC
};

class Person{
    public:
        static vector<Person> addr;
        Person(string name, int number, Group group) : name_(name), number_(number), group_(group) {
            addr.push_back(this);
        }
    
        void displayData();
        void loadData();
        void saveData();
        void delData(string name);
        void delData(string number);
        void sortData();
        void search();
    
        friend ostream& operator<<(ostream&, const Person&);
    
    
    private:
        string name_;
        int number_;
        Group group;
    

};


#endif
