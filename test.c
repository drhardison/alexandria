#include "alex.h"

int main(){
	String hello = newString("123456789");
	printSLine(hello);
	printf("Length: %d\n", hello.length);
	printf("Size: %d\n", hello.size);
	return 0;

}
