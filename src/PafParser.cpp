//
//  PafParser.cpp
//  PafParse
//
//  Created by Mohamed Z El-Walid on 1/16/20.
//  Copyright © 2020 Mohamed Z El-Walid. All rights reserved.
//
//std::find(vec.begin(), vec.end(), item) != vec.end()
#include "PafParser.hpp"
#include <iostream>
#include <iomanip>
using std::cout;
using std::string;
PafParser::PafParser(string name){
    fileName = name;
    numOfAlignments = PafParser::lineCount(fileName);
    if(numOfAlignments == -1)
        exit(EXIT_FAILURE);
    alignmentList.reserve(sizeof(Alignment) * numOfAlignments);
    populateAlignList();
}
PafParser::~PafParser(){    
}
string PafParser::getFileName(){
    return fileName;
}
//counts the number of new line chars in a file and return the value.
//for a *.paf file this should be the number of alignments in the file.
int PafParser::lineCount(string name)
{
    std::ifstream input(name);
    int i = 0;
    if(!input.is_open())
        return -1;
    i = (int) std::count(std::istreambuf_iterator<char>(input),
                         std::istreambuf_iterator<char>(), '\n');
    input.close();
    return i;
}
int PafParser::getNumOfAlignments(){
    return numOfAlignments;
}
void PafParser::populateAlignList(){
    std::ifstream input(fileName);
    string queryName, targetName;
    char strand;
    int queryLength, queryStart, queryStop, targetLength, targetStart,
        targetEnd, numOfMatch, numOfBases, mapQual;
    while(input)
    {
        string line;
        getline(input, line);
        std::stringstream ss(line);
        if(ss >> queryName >> queryLength >> queryStart >> queryStop >>
           strand >> targetName >> targetLength >> targetStart >> targetEnd
           >> numOfMatch >> numOfBases >> mapQual)
        {
            alignmentList.emplace_back(queryName, queryLength, queryStart,
                                       queryStop, strand, targetName,
                                       targetLength, targetStart, targetEnd,
                                       numOfMatch, numOfBases, mapQual);
        };
    }
    return;
}
bool PafParser::sortByTarget(const Alignment a, const Alignment b){
    return a.queryStart < b.queryStart;
};