#ifndef UNTITLED_COURSE_H
#define UNTITLED_COURSE_H
#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;

class Course {
private:
    string name;
    string lecturer;
    int classroom;
public:
    Course(string nameIN, string lecturerIN, int classroomIN){
        if (to_string(classroomIN).length() > 3 || to_string(classroomIN).length() < 3){
            cerr << "Classroom should be the length of 3!"<<endl;
            return;
        }
        else {
            name = nameIN;
            lecturer = lecturerIN;
            classroom= classroomIN;
        }
    }

    const string &getName() const {
        return name;
    }

    const string &getLecturer() const {
        return lecturer;
    }

    int getClassroom() const {
        return classroom;
    };
    Course(){};
};




#endif //UNTITLED_COURSE_H
