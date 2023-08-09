#include <stdio.h>
#include <unistd.h>
#include "ConsoleColor.h"

void loading() {
    printf("Loading...\n");
    for (int i = 0; i < 100; i++) {
        usleep(100000); 
        for(int i = 0; i < 1000; i++) {
            c_setAttribute(R_LEFT);
        }
        printf("%d%%", i + 1);
        fflush(stdout);
    }
    printf("\nLoaded Successfully!\n");
}

int main() {
    loading();
    return 0;
}
