#include <stdio.h>
#include <stdlib.h>

#define SIZE_X 19
#define SIZE_Y 22
#define SIZE_Z 23

#define CLOCK_X 8
#define CLOCK_Y 10
#define CLOCK_Z 10

#define BITS 10 // number of key stream bits

struct Registers{
    int x[SIZE_X];
    int y[SIZE_Y];
    int z[SIZE_Z];
    int output[BITS];
} regs;

int maj(int x, int y, int z){
    int num_of_zeros, num_of_ones;

    if(x == 0){
        num_of_zeros++;
    } else num_of_ones++;
    if(y == 0){
        num_of_zeros++;
    } else num_of_ones++;
    if(z == 0){
        num_of_zeros++;
    } else num_of_ones++;

    if(num_of_ones > num_of_zeros){
        return 1;
    } else return 0;
}

void shift(struct Registers *regsPointer, int size){
    int input;

    if(size == SIZE_X){
        input = regsPointer->x[SIZE_X - 1] ^ regsPointer->x[SIZE_X - 2] ^ regsPointer->x[SIZE_X - 3] ^ regsPointer->x[SIZE_X - 6];
    } else if(size == SIZE_Y){
        input = regsPointer->x[SIZE_Y - 1] ^ regsPointer->y[SIZE_Y - 2];
    } else if(size == SIZE_Z){
        input = regsPointer->z[SIZE_Z - 1] ^ regsPointer->z[SIZE_Z - 2] ^ regsPointer->z[SIZE_Z - 3] ^ regsPointer->z[SIZE_Z - 15];
    }

}

void generate(){

}

void display(struct Registers *registers, int size){

}

int main(){
    //assigning values
    regs.x = {1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
    regs.y = {1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1};
    regs.z = {1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0};
    struct Registers *regsPointer = &regs;

    for(int i = 0; i < BITS; i++){
        // compare
        int m = maj(regs.x[CLOCK_X], regs.y[CLOCK_Y], reg.z[CLOCK_Z]);

        //shifting
        if(regs.x[CLOCK_X] == m){
            shift(regs, SIZE_X);
        }
        if(regs.y[CLOCK_Y] == m){
            shift(regs, SIZE_Y);
        }
        if(regs.z[CLOCK_Z] == m){
            shift(regs, SIZE_Z);
        }

        regsPointer->output[bits - i] = regs.x[SIZE_X - i] ^ regs.y[SIZE_Y - i] ^ regs.z[SIZE_X - i];
        generate(regsPointer);
    }

    display(regsPointer, BITS);

    return 0;
}