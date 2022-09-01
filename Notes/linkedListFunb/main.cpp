#include <iostream>
#include <string.h>

#include "list.h"

using namespace std;

string printPrompt();

int main()
{
  Gradebook* gradebook = new Gradebook();

  cout << "Welcome to my Gradebook Linked List Practice" << endl;
  string input = printPrompt();
  while(input!="quit")
  {
    //Help Output
    if(input == "help")
    {
      cout << "Possible commands: \n\t- print\n\t- printStudent\n\t- getCount\n\t- addStudent\n\t- quit" << endl;
    }
    if(input=="getCount")
    {
      //int count = gradebook->getCount();
      cout <<"The student count is: " << gradebook->getCount() << endl;
    }
    if(input=="addStudent")
    {
      string first,last,gradeLevel;

      cout << "Adding Student \n\tFirst Name: ";
      cin >> first;
      cout << "\tLast Name: ";
      cin >> last;
      cout << "\tGrade Level: ";
      cin >> gradeLevel;

      bool addStudent = gradebook->addStudent(first,last,gradeLevel);
      if(addStudent)
      {
        cout << "Student Added Successfully" << endl;
      } else {
        cout << "Error Occurred, Try Again" << endl;
      }
    }
    if(input=="print")
    {
      gradebook->printGradebook(cout);
    }
    cout << endl;
    input = printPrompt();
  }

  return 0;
}

string printPrompt()
{
  string input;
  cout << "Please enter a command, or enter help for more options: ";
  cin >> input;

  return input;
}