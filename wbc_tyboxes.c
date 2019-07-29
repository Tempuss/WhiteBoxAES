#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tboxes.h"

#define DW(t) (*(unsigned int*)(t))

void shiftRows(unsigned char out[16]) {
    
    // +----+----+----+----+
    // | 00 | 04 | 08 | 12 |
    // +----+----+----+----+
    // | 01 | 05 | 09 | 13 |
    // +----+----+----+----+
    // | 02 | 06 | 10 | 14 |
    // +----+----+----+----+
    // | 03 | 07 | 11 | 15 |
    // +----+----+----+----+
    
    int tmp;
    unsigned int i,k,s;
    
    for(i=1; i<4; i++){
        s=0;
        while(s<i){
            tmp=out[i];
            for(k=0; k<3; k++){
                out[k*4+i]=out[k*4+i+4];
            }
            
            out[i+12]=tmp;
            s++;
        }
    }
}

void wbaes_tyboxes(unsigned char in[16], unsigned char out[16])
{
    memcpy(out, in, 16);

    for (size_t i = 0; i < 9; ++i) {
        shiftRows(out);

        for (size_t j = 0; j < 4; ++j) {
            unsigned int x = Tyboxes[i][j * 4 + 0][out[j * 4 + 0]];
            unsigned int y = Tyboxes[i][j * 4 + 1][out[j * 4 + 1]];
            unsigned int z = Tyboxes[i][j * 4 + 2][out[j * 4 + 2]];
            unsigned int k = Tyboxes[i][j * 4 + 3][out[j * 4 + 3]];

            DW(&out[j * 4]) = x ^ y ^ z ^ k;
        }
    }

    shiftRows(out);

    for (size_t j = 0; j < 16; ++j) {
        unsigned char x = Tboxes[9][j][out[j]];
        out[j] = x;
    }
}

int main() {
    unsigned char plain[] = "bestbestbestbest";
    unsigned char out[16] = { 0 };

    wbaes_tyboxes(plain, out);
    
    for(size_t i =0 ; i<16; i++ ) {
        printf("%x",out[i]);
    }
    printf("\n");

    return 0;
}
