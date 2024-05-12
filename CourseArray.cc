#include "CourseArray.h"

CourseArray::CourseArray()
: numElements(0), nextId(COURSE_ID) { 
    for (int i = 0; i < MAX_COURSES; ++i) {
        elements[i] = nullptr; 
    }
}

CourseArray::~CourseArray() {
    for (int i = 0; i < numElements; ++i) {
        delete elements[i]; 
    }
}

void CourseArray::add(Course* course) {
    if (numElements >= MAX_COURSES) {
        return; 
    }

    
    course->setId(nextId++);

    
    int i;
    for (i = numElements - 1; (i >= 0) && (elements[i]->lessThan(*course)); --i) {
        elements[i + 1] = elements[i]; 
    }

    elements[i + 1] = course; 
    ++numElements; 
}

bool CourseArray::find(int id, Course** c) const {
    for (int i = 0; i < numElements; ++i) {
        if (elements[i]->getId() == id) {
            *c = elements[i]; 
            return true;
        }
    }
    *c = nullptr; 
    return false;
}

void CourseArray::print(const std::string& term) const {
    for (int i = 0; i < numElements; ++i) {
        if (elements[i]->getTerm() == term) {
            elements[i]->print(); 
        }
    }
}
