#ifndef CONTROL_H
#define CONTROL_H

#include "School.h"
#include "Schedule.h"
#include "View.h" 

const int MAX_SCHEDULES = 10; 

class Control {
public:
    Control(const std::string& schoolName);
    ~Control();

    void addSched(Schedule* sched);
    bool findSched(const std::string& term, Schedule*& sched) const;
    void launch();
    void initCourses(School* sch);
    

private:
    School* school;
    Schedule* schedules[MAX_SCHEDULES];
    int numSchedules;
    View view; 
};

#endif 
