#ifndef SCHOOL_H
#define SCHOOL_H

#include "CourseArray.h"
#include <string>

class School {
public:
    School(const std::string& name);
    ~School(); 

    void addCourse(Course* course);
    bool findCourse(int id, Course*& course) const;
    void printCourses(const std::string& term) const;

private:
    std::string name;
    CourseArray courses; 
};

#endif 
