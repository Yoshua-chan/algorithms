#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdlib.h>
#include <math.h>

int parse(int argc, char** argv) {
    if(argc < 2)
        return 0;

    if(argc == 2)
        return atoi(argv[1]);
    else if(!strcmp(argv[1], "-r") || !strcmp(argv[1], "--range"));
        return atoi(argv[2]);
}

uint8_t* prime_sieve(uint64_t range) {
    uint64_t root = ceil(sqrt(range));
    uint8_t* sieve = malloc(range * sizeof(uint8_t));
    memset(sieve, 1, range);
    sieve[0] = 0;

    for(uint64_t start = 2; start <= root; start++) {
        #ifdef LOG
        printf("sieving multiples of %lu\n", start);
        #endif
        
        if(sieve[start] == 0) {
            #ifdef LOG
            printf("%lu alreade sieved, skipping\n", start);
            #endif
            continue;
        }

        for(uint64_t cur = 2 * start; cur < range; cur += start) {
            sieve[cur] = 0;
        }   
    }
    #ifdef LOG
    printf("done ;)\n");
    #endif
    return sieve;
}

int main(int argc, char** argv) {
    int range = parse(argc, argv);

    if(range == 0)
        return 1;

    uint8_t* sieve = prime_sieve(range);

    #ifdef PRINT
    for(uint64_t i = 1; i <= range; i++) {
        if(sieve[i] == 1)
            printf("%lu\n", i);
    }
    #endif

}