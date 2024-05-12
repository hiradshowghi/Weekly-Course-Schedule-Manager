#ifndef COURSE_ARRAY_H
#define COURSE_ARRAY_H

#include "Course.h"

const int MAX_COURSES = 100; 

class CourseArray {
public:
    CourseArray(); 
    ~CourseArray(); 

    void add(Course* course); 
    bool find(int id, Course** c) const; 
    void print(const std::string& term) const; 

private:
    Course* elements[MAX_COURSES]; 
    int numElements; 
    int nextId; 
};

#endif 
