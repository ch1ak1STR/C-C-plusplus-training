#include <stdio.h>
#include <iostream>
#include <cstring>
#include "trainingLib.h"

void dynamicArray() {
    startPrint(__func__);
    char *arrayPtr;
    const char* gomiData = "-";
    const int       size = 5;
    size_t     arraySize = strlen(gomiData) * (size / strlen(gomiData)) + 1;
    arrayPtr             = new char[arraySize]; // 終端文字で + 1
    int           offset = 0;
    int written;
    for (int i = 0; i < arraySize - 1; ++i) {
        written = snprintf(arrayPtr + offset, sizeof(gomiData), "%s", gomiData);
        if (written < 0 || written >= sizeof(gomiData)) {
            break;                              // 配列の範囲外に書き込むのを防ぐ
        }
        offset += written;
    }
    printf("arrayPtr size : %zu\n"          , arraySize);
    printf("write    byte : %d\n"           ,    offset);
    arrayPtr[offset] = '\0';
    printf("printf(%%s\\n, arrayPtr) = %s\n",  arrayPtr);
    delete[] arrayPtr;                          // 配列をdeleteするときは[]をつける
    arrayPtr = nullptr;                         // delete後nullptrを入れて事故を防ぐ
    endPrint(__func__);
}

int main() {
    dynamicArray();
    return 0;
}
