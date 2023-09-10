#include <stdio.h>
static const char* line = "------------------";

void startPrint(const char* c) {
    printf("%s %s start %s\n", line, c, line);
}

void endPrint(const char* c) {
    printf("%s %s end   %s\n", line, c, line);
}
