#include <iostream>

#ifdef _WIN32
#include "windows.cpp"
#else
#include "linux.cpp"
#endif

int main() {
    Server server;
    if (!server.Start()) {
        std::cout << "Error starting server" << std::endl;
        return 0;
    }
    return 1;
}
