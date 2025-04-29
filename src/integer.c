#include <stdio.h>
#include <stdlib.h>

#define BUF		64

char* integer_to_roman(int number){

	char* res = malloc(BUF);
	int idx = 0;

	int thou = number / 1000;
	if(thou > 3) return NULL;

	int hundr = (number % 1000) / 100;
	int tens = (number % 100) / 10;
	int ones = number % 10;

	for(int i = 0; i < thou; i++){
		res[idx++] = 'M';	
	}
	
	if(hundr == 5){
		res[idx++] = 'D';
	}else if(hundr == 9){
		res[idx++] = 'C';
		res[idx++] = 'M';
	}else if(hundr == 4){
		res[idx++] = 'C';
		res[idx++] = 'D';
	}else if(hundr > 0 && hundr < 4){
		for(int i = 0; i < hundr; i++){
			res[idx++] = 'C';
		}
	}else if(hundr > 5 && hundr < 9){
		res[idx++] = 'D';
		for(int i = 0; i < hundr-5; i++){
			res[idx++] = 'C';
		}
	}

	if(tens == 5){
		res[idx++] = 'L';
	}else if(tens == 9){
		res[idx++] = 'X';
		res[idx++] = 'C';
	}else if(tens == 4){
		res[idx++] = 'X';
		res[idx++] = 'L';
	}else if(tens > 0 && tens < 4){
		for(int i = 0; i < tens; i++){
			res[idx++] = 'X';
		}
	}else if(tens > 5 && tens < 9){
		res[idx++] = 'L';
		for(int i = 0; i < tens - 5; i++){
			res[idx++] = 'X';
		}
	}

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

	int num = 2001;
	char* txt = integer_to_roman(num);

	if(txt){
		printf("Liczba %d w rzymskim zapisie to %s\n", num, txt);
	}
	

	return 0;
}
