#ifndef _LIST_H_
#define _LIST_H_

#include <string>
#include <iostream>
#include <math.h>

using namespace std;
class Grades{
    public: 
        string letterGrade;
        double percent;
        string className;
        Grades* next;

        Grades();
        Grades(string className,string letterGrade,double percent,Grades* next);
};

class Student{
    public:
        string first;
        string last;
        int classCount;
        string gradeLevel; 
        Student* next;
        Grades* headGrades;

        Student();
        Student(string first, string last, string gradeLevel, int classCount,Student*);
};

class Gradebook{
    private:
        Student* headStudentList;
        int count;
    public:
        Gradebook();
        
        int getCount();

        void printGradebook(ostream &os);
        void printStudent(ostream &os, string first, string last);

        bool addStudent(string first, string last, string gradeLevel);
};

#endif