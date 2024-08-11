#include <stdio.h>

#define EXTRACT_BIT(n, i) ((n & (1 << i)) ? 1 : 0)

int check_circuit(int id, int z) {
    int v[16];  // Array to hold the bits of the input number
    int i;

    // Extract each bit from the input number z and store it in the array v
    for (i = 0; i < 16; i++) {
        v[i] = EXTRACT_BIT(z, i);
    }

    // Check the circuit conditions
    if ((v[0] || v[1]) &&
        (!v[1] || !v[3]) &&
        (v[2] || v[3]) &&
        (!v[3] || !v[4]) &&
        (v[4] || !v[5]) &&
        (v[5] || !v[6]) &&
        (v[5] || v[6]) &&
        (v[6] || !v[15]) &&
        (v[7] || !v[8]) &&
        (!v[7] || !v[13]) &&
        (v[8] || v[9]) &&
        (v[8] || !v[9]) &&
        (!v[9] || !v[10]) &&
        (v[9] || v[11]) &&
        (v[10] || v[11]) &&
        (v[12] || v[13]) &&
        (v[13] || !v[14]) &&
        (v[14] || v[15]) 
       ) {
        
        printf("%d) %d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d\n", id,
               v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7],
               v[8], v[9], v[10], v[11], v[12], v[13], v[14], v[15]);

        fflush(stdout);
        return 1;
    } else {
        return 0;
    }
}
