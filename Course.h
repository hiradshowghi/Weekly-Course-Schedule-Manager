#ifndef COURSE_H
#define COURSE_H

#include "Time.h" 
#include "defs.h" 
#include <string>
using namespace std;

class Course {
public:
    Course(const string& term, const string& subject, int code, char section, 
           const string& instructor, LectDaysType lectureDays, int startHour, int startMin);
    ~Course();
    void computeDays(WeekDayType& day1, WeekDayType& day2);
    bool computeSlot(TimeSlotType& slot) const;
    bool lessThan(const Course& rhs) const;
    void print() const;
    int getId() const;
    string getTerm() const;
    string getInstructor() const;
    string getCourseCode() const;
    void setId(int newId);

private:
    int id;
    string term;
    string subject;
    int code;
    char section;
    string instructor;
    LectDaysType lectureDays;
    Time* startTime;

};

#endif