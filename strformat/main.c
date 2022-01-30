#include <stdio.h>
#include "strformat.h"


int main() {
    Precision pr = find_specifier("dupa cipa %2137d %% fiut %17.77f", 1, NULL);
    printf("whole: %d\npoint: %d\n", pr.whole_precision, pr.point_precision);
}