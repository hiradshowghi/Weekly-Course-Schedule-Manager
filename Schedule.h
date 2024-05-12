#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "Course.h"
#include "defs.h"




class Schedule {
public:
    Schedule(const std::string& term);
    ~Schedule();

    bool addCourse(Course* course);
    void print() const;
    void clear();
    std::string getTerm() const;

private:
    std::string term;
    Course* grid[NUM_DAYS][NUM_SLOTS]; 
};

#endif 
