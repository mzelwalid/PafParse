//
//  PafParser.hpp
//  PafParse
//
//  Created by Mohamed Z El-Walid on 1/16/20.
//  Copyright © 2020 Mohamed Z El-Walid. All rights reserved.
//
#ifndef PafParser_hpp
#define PafParser_hpp
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using std::cout;
using std::string;


class PafParser
{
public:
    struct Alignment{
        string queryName;
        int queryLength, queryStart, queryStop;
        char strand;

        string targetName;
        int targetLength, targetStart, targetEnd;
        
        int numOfMatch, numOfBases, mapQual;

        string remainder;

        //construct Alignment requiring first 12 paf outputs
        //constructor for alignment init
        Alignment(string queryName, int queryLength, int queryStart, int queryStop, 
                char strand, string targetName, int targetLength, int targetStart, int targetEnd, 
                int numOfMatch, int numOfBases, int mapQual, string remainder):
                queryName(queryName), queryLength(queryLength), queryStart(queryStart), 
                queryStop(queryStop), strand(strand), targetName(targetName), 
                targetLength(targetLength), targetStart(targetStart), targetEnd(targetEnd), 
                numOfMatch(numOfMatch), numOfBases(numOfBases), mapQual(mapQual), remainder(remainder)
        {
        }
    } typedef Alignment;
    PafParser(string);
    ~PafParser();
    string getFileName();
    int getNumOfAlignments();
    bool sortByTarget(const Alignment, const Alignment);
    std::vector<PafParser::Alignment> alignmentList;
private:
    string fileName;
    int numOfAlignments;
    int lineCount(string);
    void populateAlignList();
};
#endif /* PafParser_hpp */