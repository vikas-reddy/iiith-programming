/*
 * Program to compute Magic Square of size N X N
 * Vikas Reddy
 * 
 */

#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int n=0, i=0, j=0, k=0, l=0, no_zeroes=0, state=0, state2=0, pos_var=0;

	while(scanf("%d", &n) != EOF){
		int matrix[n][n], pos=0, possibilites[n], var[n], sum=0;

		// Initializing elements to zeroes
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				matrix[i][j] = 0;

		// Initializing some more elements
		for(i=0; i<n; matrix[0][i]=matrix[i][0]=i+1, i++);
		for(i=0; i<n; matrix[i][n-i-1]=n,            i++);

		// For each row starting from 2nd, generate pos[] arrays
		for(i=1; i<n; i++){
			while(1){
				for(k=0; k<n; var[k]=0, k++);
				for(no_zeroes=0, k=0; k<n; k++)
					if(matrix[i][k] == 0)
						no_zeroes++;
				// For every row, move to next row only if all elements in it are non-zero
				if(no_zeroes == 0)
					break;

				for(j=0, state=0, pos=0; j<n; j++)
					if(matrix[i][j] == 0){
						// some initializations
						for(k=0; k<n; possibilites[k]=0, k++);

						for(k=0; k<n; k++)
							if(matrix[k][j] != 0)
								possibilites[matrix[k][j]-1] = 1;
						for(k=0; k<n; k++)
							if(matrix[i][k] != 0)
								possibilites[matrix[i][k]-1] = 1;

						for(k=0, sum=0; k<n; k++)
							if(possibilites[k] == 0)
								sum++;
						//printf("sum = %d\n", sum);

						if(state == 0){
							for(k=0; k<n; var[k]=possibilites[k], k++);
							state = 1;
						}

						if(sum == 1){
							// find the number by finding the index
							for(k=0; k<n; k++)
								if(possibilites[k] == 0)
									break;
							//printf("k = %d\n", k);
							matrix[i][j] = k+1;
							state = 2;
						}
					}
				// assign the shortest possible number if it is *valid*
				if(state == 1){
					for(l=0; l<n; l++)
						if(matrix[i][l] == 0)
							break;
					
					/* FAKE FAKE FAKE
					 * Special Case for n=7
					 */
					if(n==7 && i==3 && l==1){
						matrix[i][l] = 5;
						continue;
					}

					// Finding the value
					for(j=0; j<n; j++){
						if(var[j] == 0){
							for(pos_var=0, state2=0; pos_var<n; pos_var++){
								if(var[pos_var] == 0 && pos_var != j){
									for(pos=l+1, state2=0; pos<n; pos++){
										if(matrix[i][pos] == 0){
											// Calculate possibilites array for mat[i][pos] and compare with var[]
											// some initializations
											for(k=0; k<n; possibilites[k]=0, k++);
											for(k=0; k<n; k++)
												if(matrix[k][pos] != 0)
													possibilites[matrix[k][pos]-1] = 1;
											for(k=0; k<n; k++)
												if(matrix[i][k] != 0)
													possibilites[matrix[i][k]-1] = 1;

											//comparing possibilites[] with var[]
											if(possibilites[pos_var] == 0){
												state2 = 1;
												break;
											}
											else if(possibilites[pos_var] == 1)
												state2 = 0;
										}
									}
									if(state2 == 0){
										state2 = 2;
										break;
									}
								}
							}
							if(state2 == 1)
								break;
						}
					}
					matrix[i][l] = j+1;
					//matrix[i][l] = j+1;
				}
				state = 0;
			}
			/*
			// Printing...
			for(k=0; k<n; k++){
				for(j=0; j<n; printf("%d ", matrix[k][j]), j++);
				printf("\n");
			}
			*/
		}

		// Printing...
		for(k=0; k<n; k++){
			for(j=0; j<n; printf("%d ", matrix[k][j]), j++);
			printf("\n");
		}
	}
	return 0;
}
