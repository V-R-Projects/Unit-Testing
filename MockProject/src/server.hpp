#ifndef server_h
#define server_h

#define PORT 11500
#define IP "127.0.0.1"
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <cstdlib>
#include <string.h>
#include <thread>
#include <iostream>
#include <netdb.h>
#include <arpa/inet.h>
#include <string>
#include "dataStruct.hpp"
#include "card.hpp"

class Server
{
private:
    int server, client;
    struct sockaddr_in server_address, client_address;
    int message_len;
    unsigned int client_len;
    int server_len;
    char buffer[1024];
    dataStruct *pagedMemory;
    

public:
    Server(dataStruct *pMemory);
    void requestHandler(char buffer[1024]);
    int getMemorySize();
    int getPageFaults();
    int getPageHits();
    void run();
};
#endif