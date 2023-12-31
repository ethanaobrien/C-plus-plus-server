#include <iostream>
#define WIN32_LEAN_AND_MEAN
#include <stdbool.h>
#include <windows.h>

#include <commdlg.h>

#include <winsock2.h>
//? #pragma comment(lib, "ws2_32.lib")


class Socket {
    int port = 8080;
    SOCKET sock;
public: 
    bool Start() {
        WSADATA wsaData;

        if (WSAStartup(0x202, &wsaData) == SOCKET_ERROR) {
            std::cout << "WSAStartup failed with error " << WSAGetLastError() << std::endl;
            WSACleanup();
            return false;
        }
        
        struct sockaddr_in local;
        
        local.sin_family = AF_INET;
        local.sin_addr.s_addr = INADDR_ANY;
        local.sin_port = htons(port);

        sock = socket(AF_INET, SOCK_STREAM, 0); // tcp socket

        if (sock == INVALID_SOCKET) {
            std::cout << "socket() failed with error " << WSAGetLastError() << std::endl;
            WSACleanup();
            return false;
        }

        if (bind(sock, (struct sockaddr * ) & local, sizeof(local)) == SOCKET_ERROR) {
            std::cout << "bind() failed with error " << WSAGetLastError() << std::endl;
            WSACleanup();
            return false;
        }

        if (listen(sock, 5) == SOCKET_ERROR) {
            std::cout << "listen() failed with error " << WSAGetLastError() << std::endl;
            WSACleanup();
            return false;
        }
        std::cout << "Listening on port " << port << std::endl;
        return true;
        std::cout << "Window" << std::endl;
    }
};
