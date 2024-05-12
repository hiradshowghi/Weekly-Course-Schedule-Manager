#include "School.h"

School::School(const std::string& name) : name(name) {}

School::~School() {
    
}

void School::addCourse(Course* course) {
    courses.add(course);
}

bool School::findCourse(int id, Course*& course) const {
    return courses.find(id, &course);
}

void School::printCourses(const std::string& term) const {
    courses.print(term);
}
