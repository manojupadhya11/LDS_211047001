#include<stdio.h>
#include<stdlib.h>

int main(int argc,char* argv[]){
	int n; //size of the array
	int size_int;
	printf("Enter the size of the array\n");
	scanf("%d",&n);
        //printf("%d\n", sizeof(int));
	int *A =(int*) calloc(n,sizeof(n));
	//display the array
	for(int i=0;i<n;i++){
		printf("%d\n", A[i]);
	}
	int *B =(int*) realloc(A,(n*3)*sizeof(n));
	//starting address
	printf("The address of  A[0] is: %d\n",&A[0]);
	//store the value to array
	/*for(int i=0;i<n;i++){
		A[i] = i+1;
	}*/

	//display the array
	for(int i=0;i<n*3;i++){
		printf("%d\n", B[i]);
	}
	return 0;
}
