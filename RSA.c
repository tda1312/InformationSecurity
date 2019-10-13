#include <stdio.h>
#include <math.h>

int check_coprime(int x, int y){
	int temp;
	
	while(1){
		temp = x % y;
		if(temp == 0){
			return y;
		}
		x = y;
		y = temp;
	}
}

void print_menu(){
	printf("\n--------------------------MENU--------------------------\n");
	printf("0. Exit the program\n");
	printf("1. RSA\n");
}

int main(){
	double p, q, N, e, d, phi, k, M, encrypt, decrypt;
	int choice;
	
	do{
		print_menu();
		printf("Enter your choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 0:
				continue;
			case 1:
				printf("Enter value for p: ");
				scanf("%lf", &p);
				printf("Enter value for q: ");
				scanf("%lf", &q);
				printf("Enter value for plaintext M: ");
				scanf("%lf", &M);
				
				e = 2;
				k = 2;
				N = p * q;
				phi = (p - 1) * (q - 1);
				
				while(e < phi){
					if(check_coprime(e, phi) == 1){
						break;
					} else{
						e++;
					}
				}
				
				d = ((k * phi) + 1) / e;
				
				encrypt = pow(M, e);
				encrypt = fmod(encrypt, N);
				printf("Encrypted: %lf", encrypt);
				printf("\nd: %lf\ne: %lf\nN: %lf\nphi: %lf\nM: %lf", d, e, N, phi, M);
				decrypt = pow(encrypt, d);
				decrypt = fmod(decrypt, N);
				printf("\nDecryption complete. Origional message: %lf", decrypt);
				
				break;
		}
	} while(choice != 0);
	
	return 0;
}
