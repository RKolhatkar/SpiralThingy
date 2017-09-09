#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 4


void printm(int [SIZE][SIZE]);
void spiral(int [SIZE][SIZE]);


int main() {
int data[SIZE][SIZE];
int i,j;
srand(time(NULL));
for(i=0;i<SIZE;i++) {
	for(j=0;j<SIZE;j++) {
		data[i][j] = rand()%2;
	}	
}

//input data will be 0/1. Top half of the matrix is class 0, and bottom part is class 1

printm(data);
printf("\n\n\nSpiral Output:\n\n");
spiral(data);
return 0;
}

void printm(int m[SIZE][SIZE]) {
int i,j;
printf("Class 0\n");
for(i=0;i<SIZE;i++) {
	printf("\n");
	if(i==SIZE/2)
		printf("-------------------------\n Class 1\n");  // A line for reference
	for(j=0;j<SIZE;j++) {
		printf("%d\t", m[i][j]);
			}
}
}

void spiral(int m[SIZE][SIZE]) {

int row,col,t;

row=SIZE/2 - 1; 		// Start From mid row

//we need all cols to be traversed
while(row >= 0){
col = 0;
	here: if(m[row][col] != m[SIZE-row-1][col]) { 

/* if row = 4/2-1 = 1, 
 * then we need to compare with 
 * 4-1-1 = 2 row.
 * if row = 0, 4-0-1 = 3 
 */
		if(m[row][col] == 0) {
			t = m[row][col];
			m[row][col]=m[SIZE-row-1][col];
			m[SIZE-row-1][col]=t;
		}
	}
	col++;
	if(!(col == SIZE - 1))
		goto here;
row--; //go 1 row backwards.
}

printm(m);
}


