#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>


#define SPEC_D 0
#define SPEC_LD 1
#define SPEC_U 2
#define SPEC_LU 3
#define SPEC_F 4
#define SPEC_LF 5
#define SPEC_C 6
#define SPEC_S 7

typedef struct {
    int whole_precision;
    int point_precision;
} Precision;

// Parsing format string
char* strformat(char* format, ...);
int count_arguments(char* format);
Precision find_specifier(char* format, int index, char*);
char* left_pad(char* str, int width);
int get_specifier_from_beginning(char* format, char* out);

// Converting data types
char* int_to_str(int number, int presicion);
char* float_to_str(float number, int whole_precision, int point_precision, bool exponential);

bool is_digit(char character);