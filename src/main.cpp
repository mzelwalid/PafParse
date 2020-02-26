//
//  main.cpp
//  PafParse
//
//  Created by Mohamed Z El-Walid on 1/16/20.
//  Copyright © 2020 Mohamed Z El-Walid. All rights reserved.
//
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include "PafParser.hpp"



int main(int argc, const char * argv[]) {
    cout << "Hello, World!\n";
    string applicationName = argv[0];
    if(argc != 2){
        cout << "ERROR: Incorrect number of arguments.\n";
        cout << "Usage: " << applicationName << " <path-to-file>\n";
        return 1;
    }

    string fileName = argv[1];
    cout << fileName << std::endl;

    PafParser test(fileName);
    cout << test.getFileName() << '\n';
    cout << test.getNumOfAlignments() << '\n';
    cout << (int) (sizeof(PafParser::Alignment) * test.getNumOfAlignments()) << '\n';
    
    
    std::unordered_set<string> uset;
    std::vector<string> uniqueKeys;

    for(int i = 0; i < test.getNumOfAlignments(); i++)
    {
        cout << test.alignmentList[i].remainder << " " << test.alignmentList[i].targetLength << std::endl;
        uset.insert(test.alignmentList[i].targetName);
    }

    std::unordered_set<string>::iterator itr; 
    for (itr = uset.begin(); itr != uset.end(); itr++){ 
        uniqueKeys.emplace_back((string)(*itr));
    }

    for(string i : uniqueKeys)
        cout << i << '\n';

    return 0;
}