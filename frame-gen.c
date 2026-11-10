#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tinycthread.h"
#include <string.h>

const char *GREEN_TILE = "\033[92m\xE2\x96\x88\xE2\x96\x88\033[0m";
const char *RED_TILE = "\033[91m\xE2\x96\x88\xE2\x96\x88\033[0m";
const char *YELLOW_TILE = "\033[93m\xE2\x96\x88\xE2\x96\x88\033[0m";
const char *BLUE_TILE = "\033[94m\xE2\x96\x88\xE2\x96\x88\033[0m";
const char *PINK_TILE = "\033[95m\xE2\x96\x88\xE2\x96\x88\033[0m";
const char *BLACK_TILE = "\033[90m\xE2\x96\x88\xE2\x96\x88\033[0m";
const char *WHITE_TILE = "\033[97m\xE2\x96\x88\xE2\x96\x88\033[0m";
const char *CYAN_TILE = "\033[96m\xE2\x96\x88\xE2\x96\x88\033[0m";
const char *EMPTY_TILE = "  ";
const char *frame[50][50];

void timeout(void){
    struct timespec timeout;
    timeout.tv_sec = 0;
    timeout.tv_nsec = 1000/60 * 1000000L;

    thrd_sleep(&timeout, NULL); 
}

void build_frame(int x ,int y){
    for(int i = 0; i<50; i++){
        for(int j =0; j<50;j++){
            if(i == x && y == j){ 
                printf(RED_TILE);
            }else{
                printf(EMPTY_TILE);
            }
        }
        printf("\n");
    }
}

int main(void){
        timeout();
        build_frame(24,24);
        //display_frame();
        //system("cls");
    return 0;
}

