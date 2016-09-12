#include <stdio.h>
#include <stdlib.h>
void penney();

int main() {
	int n = fgetc(stdin) - '0';
	for (int i = 1;i <= n;i++) {
		penney();	
	}
  	return 0;
}

void penney() {
	int n = fgetc(stdin) - '0';
	printf("Num: %d",n);
	char *c;
	c[0] = fgetc(stdin);
	c[1] = fgetc(stdin);
	c[2] = fgetc(stdin);	
	for (int i = 3;i <40;i++) {
		printf("Test %s\n",c);
		c[0] = c[1];
		c[1] = c[2];
		c[3] = fgetc(stdin);	
	}
}
