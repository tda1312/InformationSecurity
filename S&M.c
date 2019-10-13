#include <stdio.h>
#include <math.h>

int square_and_multiply(int x, int y, int z){
	int r = x;
	int i = 0;
	int bin[32];
	int h;
	
	while(y > 0){
		if(y & 1){
			bin[i] = 1;
		} else{
			bin[i] = 0;
		}
		
		y = y >> 1;
		i++;
	}
	
	i--;
	
	while(i > 0){
		r = (r * r) % z;
		
		if(bin[--i] == 1){
			r = (r * x) % z;
		}
	}
	
	return r;
}

void print_menu(){
	printf("\n--------------------------MENU--------------------------\n");
	printf("0. Exit the program\n");
	printf("1. Calculate a^b mod c\n");
}

int main(){
	int a, b, c, choice;
	
	do{
		print_menu();
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 0:
				continue;
			case 1:
				printf("Enter value for a: ");
				scanf("%d", &a);
				printf("Enter value for b: ");
				scanf("%d", &b);
				printf("Enter value for c: ");
				scanf("%d", &c);
				
				printf("Result: %u", square_and_multiply(a, b, c));
				break;
		}
	} while(choice != 0);
	
	return 0;
}
