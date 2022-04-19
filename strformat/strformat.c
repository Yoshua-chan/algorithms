#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "strformat.h"
#include <math.h>


/*
A little string formatting library with printf-inspired format specifiers
Written without any functions from string.h
*/


//TODO: Support '%%' escape sequence

char* strformat(char* format, ...) {
    va_list args;
    va_start(args, count_arguments(format));


    va_end(args);
}

int count_arguments(char* format) {
    int arg_count = 0;
    for(int i = 0; format[i] != '\0'; i++) {
        if(format[i] == '%')
            arg_count++;
    }
    return arg_count;
}

char* left_pad(char* str, int width) {
    int str_len = 0;
    char* new_str;

    for(int i = 0; str[i] != '\0'; i++, str_len++)
        ;  

    if(width > str_len) {
        new_str = malloc(width * sizeof(char));
        int i;

        for(i = 0; i < width - str_len; i++) 
            new_str[i] = ' ';
       
        for(int j = 0; j < str_len; j++, i++)
            new_str[i] = str[j]; 

    }
    return new_str;
}

char* int_to_str(int number, int presicion) {
    int negative = 0;
    if(number < 0) {
        negative = 1;
        number *= (-1);
    }

    int numbersize = log10(number) + 1 + negative;
    char* str = malloc(numbersize * sizeof(char));


    for(int i = 0; i < numbersize; i++) {
        
        str[numbersize - (i + 1)] = (number % 10) + 48;
        number /= 10;
    }

    if(negative)
        str[0] = '-';

    return str;
}

Precision find_specifier(char* format, int index, char* out) { 
    Precision precision;
    float point_number = 0;
    int number = 0;
    int point = 0;
    int cur_index = 0;
    for(int i = 0; format[i] != '\0'; i++) {
        //check if percent ✅
            //if double percent, skip and continue ✅
            //else skip one percent ✅
                //if digit, save to int 
                //if l, check for next character and save
                //if unexpected character, throw error or assume int
                //return digit if met,
                    //else return 0
                   
        bool point_occured = false;
        if(format[i] == '%') {
            i++; //moves to next character
            if(format[i] == '%') {// moves to next char, skips if double percent encountered
                i++;
                printf("skips cause %%%%\n");
                continue;
            }
            if(cur_index == index) {
                for(; format[i] != '\0'; i++) {
                    if(is_digit(format[i]) && !point_occured) { // converts string part to int
                        number *= 10;
                        number += format[i] - 48;
                    } else {
                        precision.whole_precision = number;
                        precision.point_precision = point_number;
                        get_specifier_from_beginning(format + i, out);
                        return precision;
                    }
                }
                /*
                if(format[i] == '.')
                    i++;

                for(; format[i] != '\0'; i++) {
                    if(is_digit(format[i])) { // converts string part to int
                        number *= 10;
                        number += format[i] - 48;
                    } 
                    else
                        precision.point_precision = number;
                    
                } */
            }
            cur_index++;
            i--;
        }   
    }
    return precision;
}

//Helper function, exists only to be called by find_specifier.
int get_specifier_from_beginning(char* format, char* out) {
    int s_len = 0;
    char c;
    for(int i = 0; (c = format[i]) != '\0'; i++) {
        if(c == 'l') { // long (int by default)
            if(c == 'd') { // int

            } else if(c == 'u') { // uint

            } else if(c == 'c') { // char

            } else if(c == 'f') { // float

            }
        } else if(c == 'd') { // int

        } else if(c == 'u') { // uint

        } else if(c == 'c') { // char

        } else if(c == 'f') { // float

        } else if(c == 'e' || c == 'E') { // exponential float

        } else if(c == 's') { // string

        } else if(c == 'x') { // hex

        } else if(c == 'o') { // octal

        } else if(c == 'p') { // pointer

        }     
    }
}

bool is_digit(char character) {
    if(character >= '0' && character <= '9')
        return true;
    else
        return false;
}