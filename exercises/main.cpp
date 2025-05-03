#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <numeric>
#include <algorithm>
#include <list>
#include <unordered_map>
#include "records.hpp"
#include <random>
#include <array>
#include <ranges>
#include <map>
#include <fstream>
#include <set>
#include <thread>
#include <map>
#include <chrono>
#include <limits>
#include <typeinfo>
#include <typeindex>
#include <filesystem>
#include <new>
#include <cstdlib>


class Tnode {
public:
    std::string word;
    int count;
    Tnode* left;
    Tnode* right;
    
};



void enterWord(Tnode*& node, std::string str ){

    if(node == nullptr) {
        node = new Tnode();
        node->word = str;
        node->count++;
        node->left = nullptr;
        node->right = nullptr;
        return;
    }
    
    if( str < node->word) {
        enterWord(node->left, str);
    }
    
    if(str > node->word){
        enterWord(node->right, str);
    }
    
}

void printNode(Tnode* node){
    
    if(node == nullptr)
        return;
    
    printNode(node->left);
    
    std::cout<<node->word << " ";
    
    printNode(node->right);
    
}

struct Date{
  
    int day;
    int month;
    int year;
    
    Date(int _day = 1, int _month = 1, int _year = 2000) {
        
        if (_year < 2000)
            std::cout<<"Please input year, greater than 2000\n";
            
        else if ((_day<1 || _day>31) || (_month<1 || _month>12))
            std::cout<<"Please input valid Date for the day and the month\n";
            
        else{
            if (_month == 2 || _month == 4 || _month == 6 || _month == 7 || _month == 9 || _month == 11) {
                if (_day>30)
                    std::cout<<"This month cannot take 31 days in the calendar. Input again the date with the correct number of days\n";
                
                else {
                    day = _day;
                    month = _month;
                    year = _year;
                }
            }
            else {
                day = _day;
                month = _month;
                year = _year;
            }
        }
    }
    
    
    void printDate(){
        std::cout<< day << "/" << month << "/" << year << "\n";
    }
};


void addOneDay(Date& date){
    if(date.month == 1 || date.month == 3 || date.month == 5 || date.month == 8 || date.month == 10 || date.month == 12){
        if(date.day == 31){
            if(date.month == 12){
                date.day = 1;
                date.month = 1;
                date.year++;
            }
            else {
                date.day = 1;
                date.month ++;
            }
        }
        else
            date.day++;
    }
    else{
        if(date.day == 30){
            date.month++;
            date.day = 1;
        }
        else
            date.day++;
    }
}


void addOneMonth(Date& date){
    if(date.month == 12) {
        date.month = 1;
        date.year++;
    }
    else{
        if(date.month == 1 || date.month == 3 || date.month == 5 || date.month == 8 || date.month == 10) {
            if(date.day == 31){
                date.month++;
                date.day = 30;
                //February needs more logic, to check if the year is disekto or not, in order to add 28 or 29 days
            }
            else
                date.month++;
        }
        else
            date.month++;
    }
}

void dayOfTheWeek(Date& date){
    
    std::map<int, int> daysOfMonth = {
        {1,31}, {2,28},
        {3,31}, {4,30},
        {5,31}, {6,30},
        {7,30}, {8,31},
        {9,30}, {10,31},
        {11,30}, {12,31}
        
    };
    
    
    int currentFirstDayOfTheMonth = 1;    //Wednesday of March in 2000 ==> 1/3/2000
    int currentMonth = 3;
    int currentYear = 2000;
    
    const char* arr[] = {"wednesday", "thursday", "friday", "saturday", "sunday", "monday", "tuesday"};
    
    std::cout<<"The initial date is: " << arr[currentFirstDayOfTheMonth-1] << "/" << currentMonth << "/" << currentYear << "\n\n";
    while(currentMonth != date.month) {
        if (daysOfMonth[currentMonth+1] == 30 ){
            if(currentFirstDayOfTheMonth>5)
                currentFirstDayOfTheMonth = 1;
            std::cout<<"The first day of the month " << currentMonth << " is "<<  arr[currentFirstDayOfTheMonth-1] << "\n";
            currentFirstDayOfTheMonth += 2;
            currentMonth +=1;
        }
        else if (daysOfMonth[currentMonth+1] == 31) {
            if(currentFirstDayOfTheMonth>4)
                currentFirstDayOfTheMonth = 1;
            std::cout<<"The first day of the month " << currentMonth << " is "<<  arr[currentFirstDayOfTheMonth-1] << "\n";
            currentFirstDayOfTheMonth += 3;
            
            currentMonth +=1;
        }
    }
    
    int diffDay = {29 - date.day};  //29 magic number
    int days_to_go_back {0};
    int days_to_go_front {0};
    
    if(diffDay > 0){
        days_to_go_back = diffDay % 7;
        currentFirstDayOfTheMonth -= days_to_go_back; //it needs logic in order to track the days inside the range of [Mon-Fri]
    }
    else if(diffDay<0){
        days_to_go_front = diffDay;
        currentFirstDayOfTheMonth += days_to_go_front;
    }
    
    
}



int main(int argc, char* argv[]) {
    
    Date date(15, 6, 2000);
    date.printDate();
    std::cout<<"\n";

    dayOfTheWeek(date);

   
    std::cout <<  '\n';
  
    return 0;
}


//    //AT THE MAIN PART OF THE PROGRAM
//    //find the .yaml files in the path that will be given... surely we need a try catch block
//    std::string txt {};
//    std::cout<<"Please give the path of the project to check for the github workflows\n";
//    getline(std::cin, txt);
//    std::vector<std::string> workflowFiles {};
//    workflowFiles = file_name_list(txt.append("/.github/workflows"));
//    for(const auto& i: workflowFiles)
//        std::cout<< i <<'\n';

////THE FUNCTION
//namespace fs = std::filesystem; //i have to #inlude <filesystem>
//std::vector<std::string> file_name_list(std::string& path_to_dir, const std::string& extension = ".yaml"){
//    if(fs::is_directory(path_to_dir)){
//        std::vector<std::string> file_names;
//        for(const auto& entry: fs::recursive_directory_iterator(path_to_dir)){
//            if(entry.is_regular_file() and entry.path().extension() == extension)
//                file_names.push_back(entry.path().string());
//        }
//        return file_names;
//    }
//    else return {};
//}
