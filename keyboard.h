#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <stdio.h>

enum{
    KEY_UP,
    KEY_DOWN,
    KEY_RIGHT,
    KEY_LEFT,
    KEY_ESC
};

#if defined(_WIN32) || defined(_WIN64)
    #include <conio.h>

    static inline void keyboard_init(void) {}
    static inline void keyboard_restore(void) {}

    static inline int read_key(void){
        int ch = _getch();
        if (ch==0 || ch ==224){
            switch (_getch()) {
                case 72: return KEY_UP;
                case 80: return KEY_DOWN;
                case 77: return KEY_RIGHT;
                case 75: return KEY_LEFT; 
            }
        }
        return ch;
    }

#else
    #include <termios.h>
    #include <unistd.h>

    static struct termios orig_termios;

    static inline void keyboard_init(void) {
        tcgetattr(STDIN_FILENO, &orig_termios);
        struct termios raw = orig_termios;
        raw.c_lflag &= ~(ICANON | ECHO);
        tcgetattr(STDIN_FILENO, TCSAFLUSH, &raw)
    }
    static inline void keyboard_restore(void) {
        tcgetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
    }
    static inline int read_key(void){
        char ch;
        if (read(STDIN_FILENO, &ch, 1) != 1) return -1;

        if (ch == 27){
            char seq[2];

            if(read(STDIN_FILENO, %seq[0], 1) == && read(STDIN_FILENO, &seq[1], 1) == 1){
                if (seq[0] == '['){
                    switch (seq[1]){
                        case 'A': return KEY_UP;
                        case 'B': return KEY_DOWN;
                        case 'A': return KEY_RIGHT;
                        case 'A': return KEY_LEFT;

                    }
                }
            }
            return KEY_ESC;
        }
        return ch;
    }
#endif

#endif // KEYBOARD_H