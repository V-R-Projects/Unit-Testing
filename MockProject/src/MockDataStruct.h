#ifndef MOCKDATASTRUCT_H
#define MOCKDATASTRUCT_H

#include "dataStruct.hpp"
#include "gmock/gmock.h"

class MockDataStruct : public dataStruct {
public:
    MOCK_METHOD(void, createFile, (), (override));
    MOCK_METHOD(card, getFCard, (int i, int j), (override));
    MOCK_METHOD(void, setFCard, (int i, int j, int ID, int status), (override));
    MOCK_METHOD(void, createPagedMemory, (int size), (override));
    MOCK_METHOD(int, isCardinMemory, (int i, int j), (override));
    MOCK_METHOD(char, getCardfromMemory, (int i, int j), (override));
    MOCK_METHOD(void, replaceCard, (int i, int j), (override));
    MOCK_METHOD(void, shuffle, (), (override));
    MOCK_METHOD(char, verify, (int i1, int j1, int i2, int j2), (override));
    MOCK_METHOD(int, getMemorySize, (), (override));
    MOCK_METHOD(int, getPageFaults, (), (override));
    MOCK_METHOD(int, getPageHits, (), (override));
};

#endif // MOCKDATASTRUCT_H
