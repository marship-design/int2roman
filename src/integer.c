#include <stdio.h>
#include <stdlib.h>

#define BUF		64

char* integer_to_roman(int number){

	char* res = malloc(BUF);
	int idx = 0;

	int thou = number / 1000;
	if(thou > 3) return NULL;

	int hundr = number % 1000;
	int tens = number % 100;
	int ones = number % 10;

	for(int i = 0; i < thou; i++){
		res[idx++] = 'M';	
	}
	
	int h = hundr / 100;
	printf("h=%d\n", h);
	if(h == 5){
		res[idx++] = 'D';
	}else if(h == 9){
		res[idx++] = 'C';
		res[idx++] = 'M';
	}else if(h == 4){
		res[idx++] = 'C';
		res[idx++] = 'D';
	}else if(h > 0 && h < 4){
		for(int i = 0; i < h; i++){
			res[idx++] = 'C';
		}
	}else if(h > 5 && h < 9){
		res[idx++] = 'D';
		for(int i = 0; i < h-5; i++){
			res[idx++] = 'C';
		}
	}

	int t = tens / 10;
	printf("t=%d\n", t);
	if(t == 5){
		res[idx++] = 'L';
	}else if(t == 9){
		res[idx++] = 'X';
		res[idx++] = 'C';
	}else if(t == 4){
		res[idx++] = 'X';
		res[idx++] = 'L';
	}else if(t > 0 && t < 4){
		for(int i = 0; i < t; i++){
			res[idx++] = 'X';
		}
	}else if(t > 5 && t < 9){
		res[idx++] = 'L';
		for(int i = 0; i < t - 5; i++){
			res[idx++] = 'X';
		}
	}

	printf("ones=%d\n", ones);
	if(ones == 5){
		res[idx++] = 'V';
	}else if(ones == 9){
		res[idx++] = 'I';
		res[idx++] = 'X';
	}else if(ones == 4){
		res[idx++] = 'I';
		res[idx++] = 'V';
	}else if(ones > 0 && ones < 4){
		for(int i = 0; i < ones; i++){
			res[idx++] = 'I';
		}
	}else if(ones > 5 && ones < 9){
		res[idx++] = 'V';
		for(int i = 0; i < ones - 5; i++){
			res[idx++] = 'I';
		}
	}


	res[idx] = '\0';
	return res;
}


int main(){

	int num = 2814;
	char* txt = integer_to_roman(num);

	if(txt){
		printf("Liczba %d w rzymskim zapisie to %s\n", num, txt);
	}
	
	int thou = num % 10000;
	int hundr = num % 1000;
	int tens = num % 100;
	int ones = num % 10;

	printf("thou %d, hundr %d, tens %d, ones %d\n", thou, hundr, tens, ones);

	return 0;
}
