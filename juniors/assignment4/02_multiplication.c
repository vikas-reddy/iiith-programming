/*
 * Program to multiply two large numbers
 *
 */

#include<stdio.h>

int main(){
	char a[26], b[26], temp[50], ans[50];
	int i=0, j=0, tmp_var=0, len_a=0, len_b=0, k=0, l=0, carry=0;

	while(scanf("%s %s", a, b) != EOF){
		// Initializing ans[] array to zeroes
		for(i=0; i<50; ans[i]='0', i++);

		// Finding the lengths of the strings...
		for(len_a=0; a[len_a]!='\0' && len_a < 25; len_a++);
		for(len_b=0; b[len_b]!='\0' && len_b < 25; len_b++);

		// Actual multiplication
		for(j=len_b - 1, l=49; j>=0; j--, l--){
			// Initializing temp[] array to zeroes
			for(i=0; i<50; temp[i]='0', i++);

			for(i=len_a-1, carry=0, k=l; i>=0; i--, k--){
				temp[k] = ((a[i] - '0') * (b[j] - '0') + carry) % 10 + '0';
				carry   = ((a[i] - '0') * (b[j] - '0') + carry) / 10;
			}
			temp[k] = carry + '0';

			// Adding temp[] and ans[] arrays
			for(carry=0, i=49; i>=0; i--){
				tmp_var = ans[i];
				ans[i] = ((ans[i]  - '0') + (temp[i] - '0') + carry) % 10 + '0';
				carry  = ((tmp_var - '0') + (temp[i] - '0') + carry) / 10;
			}
		}

		// Printing
		for(i=0; i<50 && ans[i]=='0'; i++);
		if(i == 50 && ans[49] == '0'){
			printf("0\n");
			continue;
		}
		for(  ; i<50; printf("%c",ans[i]), i++);
		printf("\n");
	}
	return 0;
}
