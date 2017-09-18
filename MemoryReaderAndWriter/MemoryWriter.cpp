#include <iostream>
#include <windows.h>
#include "pch.h"
//FindWindow();
//GetWindowProcessThreadId();
//OpenProcess();

//WriteProcessMemory();
//CloseHandle();

using namespace std;

int main()
{
    int newValue = 500;

    HWND hwnd = FindWindow(0, "Calculator");

    if (hwnd == 0){
        cerr << "Can't Find Window."<< endl;
    }else{

        DWORD pId;
        GetWindowProcessThreadId(hwnd, &pId);
        HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);

        if(!hProc){
            cerr << "Cannot open process"<< endl;

        }else{
            int isSuccessful = WriteProcessMemory(hProc,(LPVOID)0x21F4ED6D51C, &newValue, (DWORD)sizeof(newValue), NULL);

            if (isSuccessful > 0){

                clog << "Process Memory Written"<< endl;
            }else{

                cerr <<  "cant write process memory"<< endl;
            }
            CloseHandle(hProc);




        }
    }


    return 0;



}
