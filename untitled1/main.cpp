#include <iostream>
#include "Course.h"
#include "Student.h"
#include "Text_Preprocessor.h"
#include <iomanip>
#include <list>

void student_info(const Student& student);
void timetable(const std::list<Student>& student_list);

int main() {
    list <Course> courses;
    list <Student> students;
    courses.push_back(Course("C++", "Mr. Yerassyl", 355)); //just the process of inserting data
    students.push_back(Student("Yerzhan", "Appazov", 20113400, courses.front()));
    courses.push_back(Course("Java", "Mr. Olzhas", 255));
    students.push_back(Student("John", "Doe", 25640100, courses.front()));
    courses.push_back(Course("Python", "Mr. Didar", 155));
    students.push_back(Student("Cassie", "Cage", 10246400, courses.front()));
    auto students_iterator = students.begin();                                          //just the process of inserting data
    auto courses_iterator = courses.begin();
    courses_iterator++;
    students_iterator->addCourse(*courses_iterator);
    courses_iterator++;
    students_iterator->addCourse(*courses_iterator);

    student_info(students.front());                   //student_info function
//    timetable(students);                                //timetable function
                                            //Task 2
    Text_Preprocessor textPreprocessor("..//Task_1.txt");
    if (textPreprocessor.getInFile().is_open()){
    cout<<"File is opened!"<<endl;
    }
    else
        cerr<<"File can not be opened!";
    return 0;
}
void timetable(const std::list<Student>& students){
    int rowNum=1;
    for (auto it = students.begin(); it != students.end(); it++){
        cout<<rowNum<<") "<<it->getName()<<" "<<it->getSurname()<<endl;
        rowNum++;
    }
    while (true){
        string in;
        cin>>in;
        if (in=="Q" || in=="q"){
            break;
        }
        else{
            for (auto it = students.begin(); it!=students.end(); it++){
                if (it->getName()==in){
                    student_info(*it);
                    break;
                }
                else
                    continue;
            }

        }
    }

}
void student_info(const Student& student){
    cout<<"_________________________________________________________________________________________";
    cout<<"\n"<<"Name: "<<student.getName()<<setw(20)<<"| Surname: "<<student.getSurname()<<setw(59);
    cout<<"\n"<<"Course name: "<<student.getCourses().front().getName()<<setw(25)<<"| Course lecturer: "<<student.getCourses().front().getLecturer()<<setw(19)<<"| Course class: "<<student.getCourses().front().getClassroom()<<setw(20)<<endl;
    string in;
    auto it = student.getCourses().begin();
    while (true) {
        cin >> in;
        if (in == "N" || in == "n") {
            it++;
            if (it == student.getCourses().end()) {         //if we reach the end of courses
                it = student.getCourses().begin();
                cout << "Course name: " << it->getName() << setw(24) << "| Course lecturer: "
                     << it->getLecturer() << setw(25) << "| Course class: "
                     << it->getClassroom()<<endl;
            } else {
                cout << "Course name: " << it->getName() << setw(24) << "| Course lecturer: "
                     << it->getLecturer() << setw(25) << "| Course class: "
                     << it->getClassroom()<<endl;
            }
        }
        else if (in == "A" || in == "a") {
            it--;
            if (student.getCourses().empty()) {         //if we reach the area before begin of courses
                it = student.getCourses().end();
                it--;
                cout << "Course name: " << it->getName() << setw(24) << "| Course lecturer: "
                     << it->getLecturer() << setw(25) << "| Course class: "
                     << it->getClassroom()<<endl;
            }
            else {
                cout << "Course name: " << it->getName() << setw(24) << "| Course lecturer: "
                     << it->getLecturer() << setw(25) << "| Course class: "
                     << it->getClassroom() << endl;
            }
        }
        else
            break;
    }

}
