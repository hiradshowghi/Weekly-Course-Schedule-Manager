#include <iostream>
using namespace std;
#include <string>

#include "View.h"

void View::showMenu(int& choice)
{
  int numOptions = 5;

  cout << endl;
  cout << "What would you like to do:"<< endl;
  cout << "  (1) Change current term" << endl;
  cout << "  (2) View courses" << endl;
  cout << "  (3) View schedule" << endl;
  cout << "  (4) Add course to schedule" << endl;
  cout << "  (5) Clear schedule" << endl;
  cout << "  (0) Exit" << endl<<endl;

  cout << "Enter your selection: ";
  cin >> choice;
  if (choice == 0)
    return;

  while (choice < 1 || choice > numOptions) {
    cout << "Enter your selection: ";
    cin >> choice;
  }

}

void View::printStr(string str)
{
  cout << str;
}

void View::readInt(int& n)
{
  cin >> n;
}

void View::readStr(string& str)
{
  cin >> str;
}

void View::printError(const std::string& message) {
    std::cerr << message << std::endl;
}

std::string View::promptForTerm() {
    std::string term;
    std::cout << "Enter term: ";
    std::cin >> term;
    return term;
}

int View::promptForCourseId() {
    int id;
    std::cout << "Enter course ID: ";
    std::cin >> id;
    return id;
}

int View::readMenuSelection() {
    int selection;
    std::cout << "Enter menu selection: ";
    std::cin >> selection;
    return selection;
}


