// ConsoleApplication1.cpp : File writer using Threads with Mutex.
// Copyright (c) Omar Ramirez 10/09/2022
// About: The code makes two threads using WINAPI. After it uses Mutex to lock the order of threads and each thread write onto a text file synch.txt.
//          The first thread writes the alphabet in order 20 times and then the second thread writes the numbers 1-26 in order 20 times

#include <iostream>
#include <fstream>
#include <windows.h>
#include <mutex>

using namespace std;

char twentySixLetters[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
mutex mutexHandler;

DWORD WINAPI ThreadPrint(LPVOID printOrderBool) {
    mutexHandler.lock();
    bool* pointer = static_cast<bool*>(printOrderBool);
    ofstream OutFile("synch.txt", ios::app);
    
    for (int i = 0; i < 20; i++) {
        if (*pointer) {
            for (int i = 0; i < 26; i++) {
                OutFile << twentySixLetters[i] << " ";
            }
            OutFile << endl;
        }
        else {
            for (int i = 1; i < 27; i++) {
                OutFile << i << " ";
            }
            OutFile << endl;
        }
    }
    OutFile << endl;
    OutFile.close();
    *pointer = !(*pointer);
    mutexHandler.unlock();
    return 0;
}

int main()
{
    cout << "Write to synch.txt Started" << endl;
    ofstream OutFile("synch.txt", ios::app);
    OutFile.close();

    bool printOrderBool = false;

    DWORD ThreadIDA;
    DWORD ThreadIDB;
    HANDLE ThreadHandlerA;
    HANDLE ThreadHandlerB;

    ThreadHandlerA = CreateThread(NULL, 0, ThreadPrint, &printOrderBool, 0, &ThreadIDA);
    ThreadHandlerB = CreateThread(NULL, 0, ThreadPrint, &printOrderBool, 0, &ThreadIDA);

    if (ThreadHandlerA != NULL) {
        WaitForSingleObject(ThreadHandlerA, INFINITE);
        CloseHandle(ThreadHandlerA);
    }
    if (ThreadHandlerB != NULL) {
        WaitForSingleObject(ThreadHandlerB, INFINITE);
        CloseHandle(ThreadHandlerB);
    }
    cout << "Write to synch.txt Ended" << endl;
}

