//
//  records.hpp
//  Code_in_MAC
//
//  Created by Marinos Nisiotis on 26/9/22.
//

#ifndef records_hpp
#define records_hpp
#include <stdio.h>
#include <string>

class Student{
private:
    int id;
    std::string name;

public:
    Student(int _id, std::string _name);
    int getId();
    std::string getName();
};

class Course{
private:
    int id;
    std::string name;
    int credits;

public:
    Course(int _id, std::string _name, char _credits);
    int getCourseId();
    std::string getName();
    unsigned char getCredits();


};

class Grade{
private:
    int student_id;
    int course_id;
    char grade;

public:
    Grade(int _student_id, int _course_id, char _grade);
    int getStudentId();
    int getCourseId();
    char getGrade();
    

};


#endif /* records_hpp */
