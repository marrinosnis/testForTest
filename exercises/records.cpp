//
//  records.cpp
//  Code_in_MAC
//
//  Created by Marinos Nisiotis on 26/9/22.
//

#include "records.hpp"
Student::Student(int _id, std::string _name){
    id = _id;
    name = _name;
}
int Student::getId(){
    return id;
    
}
std::string Student::getName() {
    return name;
    
}

Course::Course(int _id, std::string _name, char _credits){
    id = _id;
    name = _name;
    credits = _credits;
}

int Course::getCourseId(){
    return id;
}
std::string Course::getName(){
    return name;
}
unsigned char Course::getCredits(){
    return credits;
}

Grade::Grade(int _student_id, int _course_id, char _grade){
    student_id = _student_id;
    course_id = _course_id;
    grade = _grade;
}

int Grade::getStudentId(){
    return student_id;
}

int Grade::getCourseId(){
    return course_id;
}

char Grade::getGrade(){
    return grade;
}
