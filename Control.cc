#include <iostream>
using namespace std;
#include <string>

#include "Control.h"
#include "defs.h"

Control::Control(const std::string& schoolName)
: school(new School(schoolName)), numSchedules(0) {
    for (int i = 0; i < MAX_SCHEDULES; i++) {
        schedules[i] = nullptr;
    }
}

Control::~Control() {
    delete school;
    for (int i = 0; i < numSchedules; i++) {
        delete schedules[i];
    }
}

void Control::addSched(Schedule* sched) {
    if (numSchedules < MAX_SCHEDULES) {
        schedules[numSchedules++] = sched;
    }
}

bool Control::findSched(const std::string& term, Schedule*& sched) const {
    for (int i = 0; i < numSchedules; i++) {
        if (schedules[i] && schedules[i]->getTerm() == term) {
            sched = schedules[i];
            return true;
        }
    }
    sched = nullptr;
    return false;
}

void Control::launch() {
    
    
    initCourses(school);

    int choice;
    int menuOption;
    std::string selectedTerm;

    while (true) {
        view.showMenu(menuOption);
        choice = view.readMenuSelection();

        if (choice == 0) break; 

        switch (choice) {
            case 1: { 
                selectedTerm = view.promptForTerm();
                Schedule* sched;
                if (!findSched(selectedTerm, sched)) {
                    sched = new Schedule(selectedTerm);
                    addSched(sched);
                }
                break;
            }
            case 2: { 
                school->printCourses(selectedTerm);
                break;
            }
            case 3: { 
                Schedule* sched;
                if (findSched(selectedTerm, sched)) {
                    sched->print();
                } else {
                    view.printError("Schedule does not exist for the term.");
                }
                break;
            }
            case 4: { 
                Schedule* sched;
                if (!findSched(selectedTerm, sched)) {
                    view.printError("Schedule does not exist for the term.");
                    break;
                }
                int courseId = view.promptForCourseId();
                Course* course;
                if (school->findCourse(courseId, course) && course->getTerm() == selectedTerm) {
                    sched->addCourse(course);
                } else {
                    view.printError("Course not found or not offered in the selected term.");
                }
                break;
            }
            case 5: { 
                Schedule* sched;
                if (findSched(selectedTerm, sched)) {
                    sched->clear();
                } else {
                    view.printError("Schedule does not exist for the term.");
                }
                break;
            }
            default:
                view.printError("Invalid option selected.");
        }
    }
}

void Control::initCourses(School* sch)
{
  sch->addCourse(new Course("F23", "COMP", 2401, 'A', "Laurendeau", TUE_THU, 10, 0));
  sch->addCourse(new Course("F23", "COMP", 2401, 'B', "Hillen", WED_FRI, 16, 0));
  sch->addCourse(new Course("F23", "COMP", 2401, 'C', "Laurendeau", MON_WED, 13, 0));
  sch->addCourse(new Course("F23", "COMP", 2401, 'D', "Hillen", TUE_THU, 8, 30));
  sch->addCourse(new Course("F23", "COMP", 2402, 'A', "Shaikhet", TUE_THU, 11, 30));
  sch->addCourse(new Course("F23", "COMP", 2402, 'B', "Shaikhet", MON_WED, 10, 0));
  sch->addCourse(new Course("F23", "COMP", 2404, 'A', "Hill", MON_WED, 14, 30));
  sch->addCourse(new Course("F23", "COMP", 2404, 'B', "Hill", MON_WED, 18, 0));
  sch->addCourse(new Course("F23", "COMP", 2406, 'A', "Nel", TUE_THU, 16, 0));
  sch->addCourse(new Course("F23", "COMP", 2406, 'B', "Shaikhet", TUE_THU, 18, 0));
  sch->addCourse(new Course("F23", "COMP", 2804, 'A', "Morin", TUE_THU, 14, 30));
  sch->addCourse(new Course("F23", "COMP", 2804, 'B', "Hill", MON_WED, 8, 30));

  sch->addCourse(new Course("W24", "COMP", 2401, 'A', "CI", MON_WED, 14, 30));
  sch->addCourse(new Course("W24", "COMP", 2401, 'B', "Lanthier", TUE_THU, 16, 0));
  sch->addCourse(new Course("W24", "COMP", 2402, 'A', "Sharp", WED_FRI, 13, 0));
  sch->addCourse(new Course("W24", "COMP", 2402, 'B', "Sharp", TUE_THU, 14, 30));
  sch->addCourse(new Course("W24", "COMP", 2404, 'A', "Hill", TUE_THU, 16, 0));
  sch->addCourse(new Course("W24", "COMP", 2404, 'B', "Laurendeau", TUE_THU, 13, 0));
  sch->addCourse(new Course("W24", "COMP", 2404, 'C', "Laurendeau", MON_WED, 10, 0));
  sch->addCourse(new Course("W24", "COMP", 2406, 'A', "Nel", TUE_THU, 10, 0));
  sch->addCourse(new Course("W24", "COMP", 2406, 'B', "Nel", MON_WED, 18, 0));
  sch->addCourse(new Course("W24", "COMP", 2804, 'A', "Hill", TUE_THU, 8, 30));
  sch->addCourse(new Course("W24", "COMP", 2804, 'B', "Hill", WED_FRI, 16, 0));
}

