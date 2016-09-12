#include <stdio.h>
#include <stdlib.h>
void penney();
void print_binary(int number);

int main() {
	int n = getchar() - '0';
	//printf("n = %d\n",n);
	getchar();
	for (int i = 1;i <= n;i++) {
		penney();	
	}
	printf("\n");
  	return 0;
}

void penney() {
	int n = getchar() - '0';
	getchar();
	printf("\n%d ",n);
	int c = 0;
	//print_binary(c);
	//printf(": 1st\n");
	c |= (getchar() == 'H');
	//print_binary(c);
	//printf(": 2nd\n");
	c |= (getchar() == 'H') << 1;
	//print_binary(c);
	//printf(": 3rd\n");
	c |= (getchar() == 'H') << 2;	
	//print_binary(c);
	//printf(": 4th\n");
	int cases[8] = {0,0,0,0,0,0,0,0};
	for (int i = 2;i <40;i++) {
		//print_binary(c);
		//printf("\n");
		cases[c]++;
		c = c >> 1;
		c |= (getchar() == 'H') << 2;	
	}
	for (int i = 0;i < 8;i++) {
		printf("%d ",cases[i]);
	}
}

void print_binary(int number) {
    if (number) {
        print_binary(number >> 1);
        putc((number & 1) ? 'H' : 'T', stdout);
    }
}
