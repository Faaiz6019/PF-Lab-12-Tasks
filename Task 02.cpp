#include<stdio.h>
#include<stdlib.h>
int main(){
	int n=0;
	printf("enter the number of element you want\n ");
	scanf("%d",&n);
	int* arr=(int*) malloc(n*sizeof(int));
	for(int i = 0;i<n;i++){
		printf("enter the number you want to enter ");
		scanf("%d",&arr[i]);
		
	}
	for(int i = 0;i<n;i++){
		printf("%d,",arr[i]);
	}
	
	
	arr= (int*) realloc(arr,(n*2)*sizeof(int));
	for(int i =0;i<(n*2);i++){
		printf("\nenter the number you want to enter ");
		scanf("%d",&arr[i]);	
	}
		for(int i = 0;i<(n*2);i++){
		printf("%d,",arr[i]);
	}
	return 0;
}
