#include <iostream>
#include "server.hpp"
#include "dataStruct.hpp"
#include "card.hpp"

int main() {
    dataStruct *pagedMemory = new dataStruct();
    Server server = Server(pagedMemory);
    return 0;
}