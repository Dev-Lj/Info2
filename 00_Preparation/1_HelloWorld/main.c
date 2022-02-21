#include <stdio.h>
#include <stdlib.h>
#include "horse.h"

int main () {
    const char* msg = startRunning();
    printf(msg);
    return 0;
}