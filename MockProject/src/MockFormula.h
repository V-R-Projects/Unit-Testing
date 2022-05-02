#ifndef MOCKFORMULA_H
#define MOCKFORMULA_H

#include "Formula.h"
#include "gmock/gmock.h"

class MockFormula : public Formula {
public:
    MOCK_METHOD(int, bla, (int), (override));
};

#endif //MOCKFORMULA_H
