#ifndef dataStruct_h
#define dataStruct_h

#define MATRIX_SIZE 30
#define ROWS 5
#define COLUMNS 6
#include "card.hpp"
#include <string>
#include <iostream>
#include <unistd.h>
#include <cstdio>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>

using namespace std;

class dataStruct
{

public:
    virtual void createFile();
    virtual card getFCard(int i, int j);
    virtual void setFCard(int i, int j, int ID, int status);
    virtual void createPagedMemory(int size);
    virtual int isCardinMemory(int i, int j);
    virtual char getCardfromMemory(int i, int j);
    virtual void replaceCard(int i, int j);
    virtual void shuffle();
    virtual char verify(int i1, int j1, int i2, int j2);
    virtual int getMemorySize();
    virtual int getPageFaults();
    virtual int getPageHits();

private:
    vector<card> memory;
    int memory_size;
    int matrix_size = 30;
    int flag;
    int page_faults = 0;
    int page_hits = 0;
};

#endif