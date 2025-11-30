#include<stdio.h>
#include<stdlib.h>
int main(){
int m,n,p;//m rows of first n coloum of first row of second and p coloum of second 
printf("enter the number of rows and coloums of 1 matrix\n ");
scanf("%d %d",&m,&n);
printf("enter the number of coloums of 2 matrix \n");
scanf("%d",&p);
int **mat_A=(int **) malloc(m*sizeof(int*));
for(int i = 0 ;i<m;i++){
  mat_A[i]=(int*) malloc(n*sizeof(int));   
}

int **mat_B=(int **) malloc(n*sizeof(int*));
for(int i=0;i<n;i++){
  mat_B[i]=(int*) malloc(p*sizeof(int*));
}
int **mat_c=(int**)malloc(m*sizeof(int*));
for(int i=0;i<m;i++){
  mat_c[i]=(int*) malloc(p*sizeof(int));   
}

for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
    	printf("enter element for the 1 matrix\n");
        scanf("%d",&mat_A[i][j]);
    }
}
for(int i=0;i<n;i++){
    for(int j=0;j<p;j++){
    		printf("enter element for the 2 matrix\n");
        scanf("%d",&mat_B[i][j]);
    }
}
for(int i=0;i<m;i++){
    for(int j=0;j<p;j++){
    	mat_c[i][j]=0;
    	for(int k=0;k<n;k++){
       mat_c[i][j]+=mat_A[i][k]*mat_B[k][j];
   }
    }
}
for(int i=0;i<m;i++){
    for(int j=0;j<p;j++){
        printf("%d",mat_c[i][j]);
    }
    printf("\n");
}
for(int i=0;i<m;i++){
	free(mat_A[i]);
}
for(int i=0;i<n;i++){
	free(mat_B[i]);
}
for(int i=0;i<m;i++){
	free(mat_c[i]);
}

return 0;
}

