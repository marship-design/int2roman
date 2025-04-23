#include <stdio.h>
#include <stdlib.h>

#define BUF		64

char* integer_to_roman(int number){

	char* res = malloc(BUF);
	int idx = 0;

	int t = number / 1000;
	if(t > 3) return NULL;
	for(int i = 0; i < t; i++){
		res[idx++] = 'M';	
	}
}


int main(){

	int num = 2714;
	char* txt = integer_to_roman(num);

	if(txt){
		printf("Liczba %d w rzymskim zapisie to %s\n", num, txt);
	}

	

	return 0;
}
