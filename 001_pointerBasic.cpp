#include <stdio.h>
#include <iostream>
#include "trainingLib.h"

void showAddress() {
    startPrint(__func__);
    int     num = -10;
    char      a = 'a';
    int *intptr = &num;
    printf("printf(%%d\\n, num)         = %d\n",         num);
    // 型整合のため(void*)にキャスト
    printf("printf(%%p\\n, (void*)&num) = %p\n", (void*)&num);
    endPrint(__func__);
}

void jointReference() {
    startPrint(__func__);
    int x = 25; 
    int *ptr;   // int型へのポインタ
    ptr = &x;   // ｘのアドレスをポインタに代入

    printf("printf(%%d\\n,         x) = %d\n",         x);
    printf("printf(%%d\\n,      *ptr) = %d\n",      *ptr);
    printf("printf(%%p\\n, (void*)&x) = %p\n", (void*)&x);
    printf("printf(%%p\\n,       ptr) = %p\n",       ptr);
    *ptr = 100; // これは実際にxに100を割り当てる。(デリファレンス)
    printf("値を変更した結果\n");
    printf("printf(%%d\\n,         x) = %d\n",         x);
    printf("printf(%%d\\n,      *ptr) = %d\n",      *ptr);
    printf("printf(%%p\\n, (void*)&x) = %p\n", (void*)&x);
    printf("printf(%%p\\n,       ptr) = %p\n",       ptr);
    endPrint(__func__);
}

void inputNum(int &num) {
    std::cout << "好きな数字を入力 : ";
    std::cin  >> num;
    std::cout << "入力した数字 = " << num << std::endl;
}

void callByReference() {
    startPrint(__func__);
    int num;
    inputNum(num);
    endPrint(__func__);
}

void showSetValue(int *num) {
    printf("printf(%%p\\n, (void*)value) = %p\n", (void*)num);
    *num = 10;
}

void passingByReference() {
    startPrint(__func__);
    int num = 5;
    printf("printf(%%d\\n, num) = %d\n", num);
    showSetValue(&num);
    printf("呼び出し先の関数でvalueを弄ったのが反映される (num : 5 -> 10)\n");
    printf("printf(%%d\\n, num) = %d\n", num);
    endPrint(__func__);
}

void pointerArithmetic() {
    startPrint(__func__);
    int vals[] = { 1, 2, 3 };
    int *valptr;
    valptr = vals;  
    // vals[i] は *(valptr + i) と同じ
    printf("printf(%%d\\n, vals[1])     = %d\n",           vals[1]);
    printf("printf(%%d\\n, *(valptr+1)) = %d\n",       *(valptr+1));
    printf("printf(%%d\\n, vals[2])     = %d\n",           vals[2]);
    printf("printf(%%d\\n, *(valptr+2)) = %d\n",       *(valptr+2));

    printf("printf(%%p\\n, vals[1])     = %p\n",   (void*)&vals[1]);
    printf("printf(%%p\\n, *(valptr+1)) = %p\n", (void*)(valptr+1));
    printf("printf(%%p\\n, vals[2])     = %p\n",   (void*)&vals[2]);
    printf("printf(%%p\\n, *(valptr+2)) = %p\n", (void*)(valptr+2));
    endPrint(__func__);
}

int main() {
    showAddress();
    jointReference();
    callByReference();
    passingByReference();
    pointerArithmetic();
    return 0;
}
