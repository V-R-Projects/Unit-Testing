#include "server.hpp"

using namespace std;

/**
 * @brief Construct a new Server object
 * Creates the server interface
 * Creates a socket
 */
Server::Server(dataStruct *pMemory)
{
    // creating the paged memory

    server = socket(AF_INET, SOCK_STREAM, 0);

    if (server < 0)
    {
        cout << "\n Server Error \n"
             << endl;
    }
    else
    {
        cout << "\n Server Initialized \n"
             << endl;
    }

    // Cleaning struct
    memset(&server_address, 0, sizeof(server_len));

    // Initialize struct
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(IP);
    server_address.sin_port = htons(PORT);

    // Store paged memory
    this->pagedMemory = pMemory;

    // thread run_server(&Server::run, this);
    // run_server.detach();

    // this->run();
}

void Server::run()
{
    // Bind the socket to the local port
    if (bind(server, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        cout << "\n Bind error" << endl;
    }
    else
    {
        cout << "Bind succesfull" << endl;

        // Listen request from client
        if (listen(server, 3) < 0)
        {
            cout << "\n Error listening \n"
                 << endl;
        }
        else
        {

            cout << "\n Started to listen \n"
                 << endl;

            // Accept connections
            while (true)
            {
                client = accept(server, (struct sockaddr *)&client_address, &client_len);

                if (client < 0)
                {
                    cout << "\n Error to accept client \n"
                         << endl;
                }
                else
                {
                    cout << "\n Client accepted \n"
                         << endl;
                    while (true)
                    {
                        read(client, this->buffer, 1024);
                        requestHandler(this->buffer);
                    }
                }

                close(client);
            }
        }
    }
}

/**
 * @brief Manages the requests from the client
 */
void Server::requestHandler(char buffer[1024])
{
    char operation = buffer[0];

    if (operation == '0')
    {
        // return 0 or 1 (if it is in memory) and encoded img
        int i = buffer[1] - '0';
        int j = buffer[2] - '0';

        card Card = pagedMemory->getFCard(i, j);

        // Card.encodeImg();

        memset(buffer, 0, 1024);

        // char verify
        buffer[0] = pagedMemory->getCardfromMemory(i, j);

        // image size
        int img_size = Card.img.size();
        buffer[1] = img_size / 100;
        buffer[2] = (img_size / 10) % 10;
        buffer[3] = img_size % 10;

        // Writing buffer

        for (int i = 0; i < img_size; ++i)
        {
            buffer[i + 4] = Card.img[i];
        }

        write(client, buffer, img_size + 4);
    }
    else if (operation == '1')
    {
        int i1 = buffer[1] - '0';
        int j1 = buffer[2] - '0';
        int i2 = buffer[3] - '0';
        int j2 = buffer[4] - '0';

        // return 0 or 1
        char equals = pagedMemory->verify(i1, j1, i2, j2);
        memset(buffer, 0, 1024);
        strcpy(buffer, &equals);
        write(client, buffer, 1);
    }

}

/**
 * @brief Gets the memory size from the paged memory
 * @return int
 */
int Server::getMemorySize()
{
    return this->pagedMemory->getMemorySize();
}

/**
 * @brief Gets the page faults from paged memory
 * @return int
 */
int Server::getPageFaults()
{
    return this->pagedMemory->getPageFaults();
}

/**
 * @brief Gets the page hits from paged memory
 * @return int
 */
int Server::getPageHits()
{
    return this->pagedMemory->getPageHits();
}