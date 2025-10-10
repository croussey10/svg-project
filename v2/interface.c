#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"

int ask_for_int(char* message) {
    printf("%s : ", message);
    int value = 0;
    scanf("%d", &value);
    return value;
}
