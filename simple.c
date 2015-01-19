#include <stdio.h>

int abc() {
	printf("hello abc!\n");
	return 123;
}

int main() {
	printf("Some simple file...! num=%d!\n", 5);
	abc();
	abc();
	return 100;
}
