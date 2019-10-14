#include <stdio.h>
#include <stdlib.h>

#define SIZE_X 19
#define SIZE_Y 22
#define SIZE_Z 23

#define CLOCK_X 8
#define CLOCK_Y 10
#define CLOCK_Z 10

#define BITS 10 // number of key stream bits

typedef struct Registers{
    int x[SIZE_X];
    int y[SIZE_Y];
    int z[SIZE_Z];
    int output[BITS];
} Regs;

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
    int input, j;

    if(size == SIZE_X){
        input = regsPointer->x[SIZE_X - 1] ^ regsPointer->x[SIZE_X - 2] ^ regsPointer->x[SIZE_X - 3] ^ regsPointer->x[SIZE_X - 6];
    } else if(size == SIZE_Y){
        input = regsPointer->x[SIZE_Y - 1] ^ regsPointer->y[SIZE_Y - 2];
    } else if(size == SIZE_Z){
        input = regsPointer->z[SIZE_Z - 1] ^ regsPointer->z[SIZE_Z - 2] ^ regsPointer->z[SIZE_Z - 3] ^ regsPointer->z[SIZE_Z - 15];
    }

	for(j = (size - 1); j >= 0; j--) {
		if(size == SIZE_X) {
			if(j == 0) {
				regsPointer->x[j] = input;
			}
			else{
				regsPointer->x[j] = regsPointer->x[j - 1];
			}
		}
		else if(size == SIZE_Y) {
			if (j == 0) {
				regsPointer->y[j] = input;
			}
			else {
				regsPointer->y[j] = regsPointer->y[j - 1];
			}
		}
	}
}

void generate(struct Registers *registers, int outvalue){
	int i;
	
	printf("\nKey stream: ");
	for (i = outvalue; i <= BITS; i++) {
		printf("%d, ", registers->output[i]);
	}
}

void print_menu(){
	printf("\n--------------------------MENU--------------------------\n");
	printf("0. Exit the program\n");
	printf("1. A5/1 Key generation algorithm\n");
}

int main(){
    //assigning values
    Regs regs = {   {1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
					{1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1},
					{1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0}   };
	int i, choice;
	Regs *regsPointer = &regs;
	
	print_menu();
	printf("Enter your choice: ");
	scanf("%d", &choice);
	switch(choice){
		case 0:
			break;
		case 1:
				
			for(i = 0; i < BITS; i++){
				// compare
				int m = maj(regs.x[CLOCK_X], regs.y[CLOCK_Y], regs.z[CLOCK_Z]);

       			//shifting
       			if(regs.x[CLOCK_X] == m){
           			shift(regsPointer, SIZE_X);
       			}
       			if(regs.y[CLOCK_Y] == m){
           			shift(regsPointer, SIZE_Y);
       			}
       			if(regs.z[CLOCK_Z] == m){
           			shift(regsPointer, SIZE_Z);
       			}

       			regsPointer->output[BITS - i] = regs.x[SIZE_X - i] ^ regs.y[SIZE_Y - i] ^ regs.z[SIZE_X - i];
       			generate(regsPointer, BITS-i);
       		}
        		
       		break;
    }
	
	
    return 0;
}
