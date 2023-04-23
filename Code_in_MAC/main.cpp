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

int main(int argc, char* argv[]) {
    
    int x = 1;
    
    if(true){
        
    }
   
    std::cout<< x << '\n';
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
