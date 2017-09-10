#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 6

void printData(int [SIZE][SIZE]);
void spiralOrganizer(int [SIZE][SIZE]);
void checkData(int [SIZE][SIZE]);

int main() {
int data[SIZE][SIZE];
int i,j;
srand(time(NULL));
for(i=0;i<SIZE;i++) {
	for(j=0;j<SIZE;j++) {
		data[i][j] = rand()%2;
	}	
}

//input data will be 0/1. Top half of the matrix is class 1, and bottom part is class 0

printData(data);
printf("\n\n\nSpiral Output:\n\n");
spiralOrganizer(data);
printf("\n");
checkData(data);
return 0;
}

void printData(int m[SIZE][SIZE]) {
int i,j;
printf("\nClass 1\n");
for(i=0;i<SIZE;i++) {
	printf("\n");
	if(i==SIZE/2)
		printf("-------------------------\n Class 0\n");  // A line for reference
	for(j=0;j<SIZE;j++) {
		printf("%d\t", m[i][j]);
			}
}
}



void spiralOrganizer(int m[SIZE][SIZE]) {

int row,col;

row=SIZE/2-1; 		// Start From mid row

//we need all cols to be traversed
for(col=0;col<SIZE;col++) {
	if(m[row][col] != m[SIZE-row-1][col]) { 

/* if row = 4/2-1 = 1, 
 * then we need to compare with 
 * 4-1-1 = 2 row.
 * if row = 0, 4-0-1 = 3 
 */
		if(m[row][col] == 0) {
			int t = m[row][col];
			m[row][col]=m[SIZE-row-1][col];
			m[SIZE-row-1][col]=t;
		}
	}
	//go 1 row backwards.
	
	if(row>0 && col == SIZE-1) {
		row--;
		col=-1;
	}
}

printData(m);
}

//check for outliers after stage1
void checkData(int m[SIZE][SIZE]){
printf("\nSwapping Outliers after first pass: \n");
int row,col,col2,t;
row = SIZE/2 - 1;

while(row >= 0){
col = 0;
jump:if(m[row][col] == 0){
	t = 0;col2 = 0;
	there: if(m[SIZE-row-1][col2] == 1){		
			t = m[row][col];
			m[row][col]=m[SIZE-row-1][col2];
			m[SIZE-row-1][col2]=t;		
			}
			else
			{col2++;
			if(!(col2 == SIZE - 1))goto there;}
}	
	col++;
	if(!(col == SIZE))
		goto jump;
row--;
}
printData(m);
}
