#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockDataStruct.h"
#include "server.hpp"

using ::testing::Return;

TEST(ServerTest, requestHandler) {
    //arrange
    //act
    //assert
    MockDataStruct data;
    card card1(1, 1, 1, 1);
    card1.img = "estoesunaprueba";
    EXPECT_CALL(data, getFCard(1,1)).WillOnce(Return(card1));
    EXPECT_CALL(data, getCardfromMemory(1,1)).WillOnce(Return('1'));
    EXPECT_CALL(data, verify(1,1,1,1)).WillOnce(Return(1));

    Server server = Server(&data);
    char prueba1[1024] = "01111";
    char prueba2[1024] = "11111";


    server.requestHandler(prueba1);
    server.requestHandler(prueba2);


}

TEST(ServerTest, getMemorySize){
    //arrange
    //act
    //assert
    MockDataStruct data;
    EXPECT_CALL(data, getMemorySize()).WillOnce(Return(1));
    Server server = Server(&data);
    EXPECT_EQ(server.getMemorySize(), 1);
}

TEST(ServerTest, getPageFaults){
    //arrange
    //act
    //assert
    MockDataStruct data;
    EXPECT_CALL(data, getPageFaults()).WillOnce(Return(1));
    Server server = Server(&data);
    EXPECT_EQ(server.getPageFaults(), 1);
}

TEST(ServerTest, getPageHits){
    //arrange
    //act
    //assert
    MockDataStruct data;
    EXPECT_CALL(data, getPageHits()).WillOnce(Return(1));
    Server server = Server(&data);
    EXPECT_EQ(server.getPageHits(), 1);
}