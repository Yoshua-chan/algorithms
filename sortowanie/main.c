#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "header.h"


byte parse(char* str) {
    byte FLAGS = 0;
    char c;
    for(int i = 1; (c = str[i]) != '\0'; i++) {
        switch(c) {
            case 'b':
                FLAGS |= BUBBLE;
            break;
            case 'q':
                FLAGS |= QUICK;
            break;
            case 'm':
                FLAGS |= MERGE;
            break;
            case 's':
                FLAGS |= SELECT;
            break;
            case 'i':
                FLAGS |= INSERT;
            break;
            case 'k':
                FLAGS |= QUICK_K;
            break;
            case 'a':
                FLAGS |= ALL;
            break;
        }
    }
    return FLAGS;
}

int main(int argc, char* argv[]) {

    byte FLAGS = 0U;
    int size_index;

    if(isdigit(argv[1][0])) {
        size_index = 1;
        FLAGS |= ALL;
    } else
        size_index = 2;

    if(size_index == 2 && argv[1][0] == '-')
        FLAGS = parse(argv[1]);


    int size = atoi(argv[size_index]);
    test(size, FLAGS);
    return 0;
}
