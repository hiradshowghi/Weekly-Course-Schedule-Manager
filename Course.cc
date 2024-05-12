
#include "Course.h"
#include "defs.h"
#include "Time.h"
#include <iostream>
#include <iomanip>

Course::Course(const string& term, const string& subject, int code, char section, 
               const string& instructor, LectDaysType lectureDays, int startHour, int startMin)
: id(COURSE_ID), term(term), subject(subject), code(code), section(section),
  instructor(instructor), lectureDays(lectureDays), startTime(new Time(startHour, startMin)) {}




Course::~Course() {
    delete startTime;
}

void Course::computeDays(WeekDayType& day1, WeekDayType& day2) {
    switch (lectureDays) {
        case MON_WED:
            day1 = MON;
            day2 = WED;
            break;
        case TUE_THU:
            day1 = TUE;
            day2 = THU;
            break;
        case WED_FRI:
            day1 = WED;
            day2 = FRI;
            break;
        default:
            day1 = day2 = BAD_WEEK_DAY;
    }
}

bool Course::computeSlot(TimeSlotType& slot) const {
    
    if (startTime->getHour() == 8 && startTime->getMinute() == 30) slot = SLOT_0830;
    else if (startTime->getHour() == 10 && startTime->getMinute() == 0) slot = SLOT_1000;
    else if (startTime->getHour() == 11 && startTime->getMinute() == 30) slot = SLOT_1130;
    else if (startTime->getHour() == 13 && startTime->getMinute() == 0) slot = SLOT_1300;
    else if (startTime->getHour() == 14 && startTime->getMinute() == 30) slot = SLOT_1430;
    else if (startTime->getHour() == 16 && startTime->getMinute() == 0) slot = SLOT_1600;
    else if (startTime->getHour() == 18 && startTime->getMinute() == 0) slot = SLOT_1800;
    else return false; 

    return true;
}

bool Course::lessThan(const Course& rhs) const {
    if (subject < rhs.subject) return true;
    else if (subject == rhs.subject && code < rhs.code) return true;
    else if (subject == rhs.subject && code == rhs.code && term < rhs.term) return true;
    else if (subject == rhs.subject && code == rhs.code && term == rhs.term && section < rhs.section) return true;
    return false;
}

void Course::print() const {
    std::cout << "Term: " << term << " "
              << subject << " " << std::setw(4) << std::setfill('0') << code << " "
              << section << " "
              << lectureDays << " "
              << std::setw(5) << std::setfill(' ') << ""; 

    
    startTime->print();

    std::cout << " Instr: " << instructor << std::endl;
}


int Course::getId() const { return id; }
std::string Course::getTerm() const { return term; }
std::string Course::getInstructor() const { return instructor; }
std::string Course::getCourseCode() const {
    return subject + " " + std::to_string(code) + "-" + section;
}


void Course::setId(int newId) { id = newId; }
