#include <string> 
#include <iostream>

#include "list.h"

using namespace std;

Grades::Grades()
{
    this->className = "No name set";
    this->letterGrade = "N/A";
    this->percent = 0.0;
    this->next = nullptr;
}

Grades::Grades(string className,string letterGrade,double percent, Grades* next = nullptr)
{
    this->className =className;
    this->letterGrade = letterGrade;
    this->percent = percent;
    this->next = next;
}

Student::Student()
{
    this->first = "No Name Set";
    this->last = "No Name Set";
    this->gradeLevel = "No Level Set";
    this->classCount = 0;
    this->headGrades = nullptr;
    this->next = nullptr;
}

Student::Student(string first,string last, string gradeLevel, int classCount,Student* next=nullptr)
{
    this->first = first;
    this->last = last;
    this->gradeLevel = gradeLevel;
    this->classCount = classCount;
    this->headGrades = nullptr;
    this->next = next;
}

Gradebook::Gradebook()
{
    this->headStudentList = nullptr;
    this->count = 0;
}

int Gradebook::getCount()
{
    return this->count;
}

void Gradebook::printGradebook(ostream &os)
{
    Student* tempNode = headStudentList;
    if (tempNode==nullptr)
    {
        cout << "Gradebook is Empty" << endl;
        return;
    }else {
        while(tempNode!=nullptr)
        {
            cout<<"\tFirst Name: " << tempNode->first << endl;
            cout<<"\tLast Name: " << tempNode->last << endl;
            cout<<"\tGrade Level: " << tempNode->gradeLevel << endl;
            cout<<"\tClass Count : "<< tempNode->classCount << endl;
            cout<<endl;
            tempNode = tempNode->next;
        }
    }
}

void Gradebook::printStudent(ostream &os, string first, string last)
{

}

bool Gradebook::addStudent(string first, string last, string gradeLevel)
{
    if(headStudentList==nullptr)
    {
        Student* newNode = new Student();
        newNode->first = first;
        newNode->last = last;
        newNode->gradeLevel = gradeLevel;
        headStudentList = newNode;
        count++;
        return true;
    } else {
            Student* tempNode = headStudentList;
                Student* newNode = new Student();
                newNode->first = first;
                newNode->last = last;
                newNode->gradeLevel = gradeLevel;
                newNode->next = nullptr;
        if(tempNode->next==nullptr)
        {
            if(last<=tempNode->last)
            {
                if(last==tempNode->last)
                {
                    if(first<tempNode->first)
                    {
                        headStudentList = newNode;
                        headStudentList->next = tempNode;
                        count++;
                        return true;
                    } else if(first>tempNode->first)
                    {
                        tempNode->next = newNode;
                        count++;
                        return true;
                    } else {
                        return false;
                    }
                } else {
                        headStudentList = newNode;
                        headStudentList->next = tempNode;
                        count++;
                        return true;
                }
            } else {
                tempNode->next= newNode;
                count++;
                return true;
            }
        }
        Student* curNode = tempNode->next;
        if(last<=tempNode->last)
            {
                if(last==tempNode->last)
                {
                    if(first<tempNode->first)
                    {
                        headStudentList = newNode;
                        headStudentList->next = tempNode;
                        count++;
                        return true;
                    } else if(first>tempNode->first)
                    {
                        tempNode->next = newNode;
                        count++;
                        return true;
                    } else{
                        return false;
                    }
                }
                headStudentList = newNode;
                headStudentList->next = tempNode;
                count++;
                return true;
            }
        while(curNode!=nullptr)
        {
            if(last<=curNode->last)
            {
                if(last==curNode->last)
                {
                    if(first<curNode->first)
                    {
                        tempNode->next = newNode;
                        newNode->next = curNode;
                        return true;
                    }
                    if(first==curNode->first)
                    {
                        return false;
                    }
                } else {
                    tempNode->next = newNode;
                    newNode->next = curNode;
                    count++;
                    return true;
                }
            }
            tempNode = tempNode->next;
            curNode = curNode->next;
        }
        tempNode->next = newNode;
        return true;
    }
    return false;
}



