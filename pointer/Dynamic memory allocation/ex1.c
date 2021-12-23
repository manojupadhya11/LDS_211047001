#include<stdio.h>
#include<stdlib.h>

int main(int argc,char* argv[]){
	int n; //size of the array
	int size_int;
	printf("Enter the size of the array\n");
	scanf("%d",&n);
        //printf("%d\n", sizeof(int));
	int *A =(int*) malloc(n*sizeof(n));
	printf("The address of  A[0] is: %d\n",&A[0]);
	//store the value to array
	for(int i=0;i<n;i++){
		A[i] = i+1;
	}
	//display the array
	for(int i=0;i<n;i++){
		printf("%d\n", A[i]);
	}
	return 0;
}
