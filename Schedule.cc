#include "Schedule.h"
#include "Course.h"
#include <iostream>
#include <iomanip>

Schedule::Schedule(const std::string& term) : term(term) {
    for (int i = 0; i < NUM_DAYS; ++i) {
        for (int j = 0; j < NUM_SLOTS; ++j) {
            grid[i][j] = nullptr; 
        }
    }
}

Schedule::~Schedule() {
    
}

bool Schedule::addCourse(Course* course) {
    if (!course || course->getTerm() != this->term) {
        std::cerr << "Error: Course is null or does not match schedule's term." << std::endl;
        return false;
    }
    
    WeekDayType day1, day2;
    course->computeDays(day1, day2); 

    TimeSlotType slot;
    if (!course->computeSlot(slot)) { 
        std::cerr << "Error: Unable to compute the time slot for the course." << std::endl;
        return false;
    }

    int slotIndex = static_cast<int>(slot);
    if (grid[static_cast<int>(day1)][slotIndex] == nullptr && grid[static_cast<int>(day2)][slotIndex] == nullptr) {
        grid[static_cast<int>(day1)][slotIndex] = course;
        grid[static_cast<int>(day2)][slotIndex] = course;
    } else {
        std::cerr << "Error: Course slot is already occupied." << std::endl;
        return false;
    }

    return true;
}



void Schedule::print() const {
    
    std::cout << "SCHEDULE FOR CURRENT TERM: " << term << std::endl;
    std::cout << std::left << std::setw(10) << " "
              << std::setw(10) << "MON"
              << std::setw(10) << "TUE"
              << std::setw(10) << "WED"
              << std::setw(10) << "THU"
              << std::setw(10) << "FRI" << std::endl;

    for (int slot = 0; slot < NUM_SLOTS; ++slot) {
        
        Time slotTime;
        slotTime.setFromSlot(static_cast<TimeSlotType>(slot));
        slotTime.print(); 
        std::cout << " | ";

        for (int day = 0; day < NUM_DAYS; ++day) {
            
            if (grid[day][slot]) {
                grid[day][slot]->print(); 
            } else {
                std::cout << std::setw(10) << " "; 
            }
        }
        std::cout << std::endl;
        std::cout << "-------------------------------------------------------------------------------" << std::endl;
    }
}


void Schedule::clear() {
    for (int i = 0; i < NUM_DAYS; ++i) {
        for (int j = 0; j < NUM_SLOTS; ++j) {
            grid[i][j] = nullptr;
        }
    }
}

std::string Schedule::getTerm() const {
    return term;
}
