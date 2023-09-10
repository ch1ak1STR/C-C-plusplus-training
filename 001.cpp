#include <stdio.h>
#include <iostream>

static const char* line = "------------------";

void startPrint(const char* c) {
    printf("%s %s start %s\n", line, c, line);
}

void endPrint(const char* c) {
    printf("%s %s end   %s\n", line, c, line);
}

void showAddress() {
    start_print(__func__);
    int     num = -10;
    char      a = 'a';
    int *intptr = &num;
    printf("printf(%%d\\n, num)         = %d\n",         num);
    // 型整合のため(void*)にキャスト
    printf("printf(%%p\\n, (void*)&num) = %p\n", (void*)&num);
    end_print(__func__);
}

void jointReference() {
    start_print(__func__);
    int x = 25; // int型の変数
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
    end_print(__func__);
}

void inputNum(int &num) {
  std::cout << "好きな数字を入力 : ";
  std::cin  >> num;
  std::cout << "入力した数字 = " << num << std::endl;
}

void callByReference() {
    start_print(__func__);
    int num;
    in_num(num);
    end_print(__func__);
}

void showSetValue(int *num) {
    printf("printf(%%p\\n, (void*)value) = %p\n", (void*)num);
    *value = 10;
}

void passingByReference() {
    start_print(__func__);
    int num = 5;
    printf("printf(%%d\\n, num) = %d\n", num);
    showValue(&num);
    printf("呼び出し先の関数でvalueを弄ったのが反映される (num : 5 -> 10)\n");
    printf("printf(%%d\\n, num) = %d\n", num);
    end_print(__func__);
}

int main() {
    showAddress();
    jointReference();
    callByReference();
    passingByReference();
    return 0;
}
