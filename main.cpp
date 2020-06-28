#include <iostream>
#include <Windows.h>
#include <tchar.h>

int main() {
    DWORD dwError = 0;
    std::cout << "amd64 using dll!" << std::endl;
    LPSTR lpStr = _T("C:\\Users\\xh\\Desktop\\work5\\node_call_dll\\food.dll");
    //char dName = "C:\\Users\\xh\\Desktop\\work5\\node_call_dll\\food.dll";

    HINSTANCE hDll = LoadLibrary(lpStr);
    dwError = GetLastError();
    std::cout << "dwError = " << dwError << std::endl;
    if(hDll != NULL) {
        std::cout << "load ok!" << std::endl;
        typedef int(*GetSum)(int,int);
        GetSum getSum = (GetSum)GetProcAddress(hDll,"main");
        if (getSum==NULL) {
            FreeLibrary(hDll); // 释放内存
        }
        std::cout << "get two nums sum (5,6)" << std::endl;
        int finalResult = getSum(5,6);
        std::cout << "sum = ";
        std::cout << finalResult << std::endl;
        FreeLibrary(hDll); // 释放内存
    }else {
        std::cout << "load failure!" << std::endl;
    }

    return 0;
}
