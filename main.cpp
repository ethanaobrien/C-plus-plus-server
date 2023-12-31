#include <iostream>

#ifdef _WIN32
#include "windows.cpp"
#else
#include "linux.cpp"
#endif

int main() {
    Socket socket;
    socket.Start();
    
}
