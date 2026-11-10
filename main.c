#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "keyboard.h"
#include "tinycthread.h"

#define FRAME_WIDTH 50
#define FRAME_HEIGHT 50
#define REFRESH_RATE 60

const char *BLACK_TILE = "\033[90m\xE2\x96\x88\xE2\x96\x88\033[0m";
const char *RED_TILE = "\033[91m\xE2\x96\x88\xE2\x96\x88\033[0m";
const char *GREEN_TILE = "\033[92m\xE2\x96\x88\xE2\x96\x88\033[0m";
const char *YELLOW_TILE = "\033[93m\xE2\x96\x88\xE2\x96\x88\033[0m";
const char *BLUE_TILE = "\033[94m\xE2\x96\x88\xE2\x96\x88\033[0m";
const char *PINK_TILE = "\033[95m\xE2\x96\x88\xE2\x96\x88\033[0m";
const char *CYAN_TILE = "\033[96m\xE2\x96\x88\xE2\x96\x88\033[0m";
const char *WHITE_TILE = "\033[97m\xE2\x96\x88\xE2\x96\x88\033[0m";
const char *EMPTY_TILE = "  ";

const char *BLACK_TILE_V2 = "\033[100m  \033[0m";
const char *RED_TILE_V2 = "\033[101m  \033[0m";
const char *GREEN_TILE_V2 = "\033[102m  \033[0m";
const char *YELLOW_TILE_V2 = "\033[103m  \033[0m";
const char *BLUE_TILE_V2 = "\033[104m  \033[0m";
const char *PINK_TILE_V2 = "\033[105m  \033[0m";
const char *CYAN_TILE_V2 = "\033[106m  \033[0m";
const char *WHITE_TILE_V2 = "\033[107m  \033[0m";
const char *frame[FRAME_HEIGHT][FRAME_WIDTH];

void timeout(void){
    struct timespec timeout;
    timeout.tv_sec = 0;
    timeout.tv_nsec = 1000/REFRESH_RATE * 1000000L;
    thrd_sleep(&timeout, NULL); 
}

void build_frame(int x ,int y){
    for(int i = 0; i<FRAME_WIDTH; i++){
        for(int j =0; j<FRAME_HEIGHT;j++){
            if(i ==  y && x == j){ 
                printf(RED_TILE_V2);
            }else{
                printf(EMPTY_TILE);
            }
        }
        printf("\n");
    }
}

void player_input(int *px ,int *py){
    keyboard_init();    

    int max_pos_x = FRAME_WIDTH-1;
    int max_pos_y = FRAME_HEIGHT-1;
    int min_pos_x = 0;
    int min_pos_y = 0;
    
    int key = read_key();
    switch (key){
        case KEY_UP:
            if(*py<max_pos_y){
                *py-=1;
            }
        break;
        case KEY_DOWN:
            if(*py>min_pos_y){
                *py+=1;
            }
        break;
        case KEY_LEFT:
            if(*px>min_pos_x){
                *px-=1;
            }
        break;
        case KEY_RIGHT:
            if(*px<max_pos_x){
                *px+=1;
            }
        break;
        default:
            if (key >= 32 && key <= 126){
                printf("Commom character: '%c'\n", key);
            }
            break;
        }
        keyboard_restore();
    }


int main(void){
    int x = 0;
    int y = 0;
    while(1){
        printf("\n\n\n\n\n\n\n\n\n\n\n\n");
        player_input(&x,&y);
        timeout();
        build_frame(x,y);
    }
    return 0;
}

