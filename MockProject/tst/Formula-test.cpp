#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockFormula.h"

using ::testing::Return;

TEST(blaTest, test1) {
    //arrange
    //act
    //assert
    MockFormula formula;
    EXPECT_CALL(formula, bla(1)).WillOnce(Return(1));

    EXPECT_EQ(1, formula.bla(1));

}