#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H
#include <string>
#include "Course.h"
#include <list>

using namespace std;


class Student {
private:
    string name;
    string surname;
    int id;
    list<Course> courses;
public:
    void addCourse(const Course &course) {
        Student::courses.push_back(course);
    }

public:
    Student(string nameIN, string surnameIN, int idIN, Course courseIN){
        if (to_string(idIN).length() > 8 || to_string(idIN).length() < 8){
            cerr<<"ID is not correct!"<<endl;
            return;
        }
        else
        {
            name=nameIN;
            surname=surnameIN;
            id=idIN;
            courses.push_back(courseIN);
        }
    }

    const string &getName() const {
        return name;
    }

    const string &getSurname() const {
        return surname;
    }

    int getId() const {
        return id;
    }

    const list<Course> &getCourses() const {
        return courses;
    }
};


#endif //UNTITLED_STUDENT_H
