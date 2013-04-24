/*
#include <iostream>
#include <cmath>
using namespace std;

/*

solved in about 30 min, after getting the mathematical matrix hint

had to use long long int [][]  to handle the values

executes quickly but probably a better container then multidim array available

*/ 


//   4/29/2012 , was not sure how to begin aside from brute force by hand expanding matrices to see pattern
/* mxn to find concepts involved 

 __
|__|      1x1          2 



 __ __ 
|__|__|         2x1          3

 __ __ 
|__|__|       2x2      6
|__|__|

 __ __ __
|__|__|__|     3x1   4

 __ __ 
|__|__|			3x2  
|__|__|
|__|__|

looked up hint.. matrix, add top and left to get mxn
2 3   4  5  6
3 6   10 15 21
4 10  20 
5
6

will try to create 20x20 matrix with program
*/ 
/*
int main(){
	long long int matrix[20][20];
	//intitialize to 0
	for (int w=0;w<20;w++)
	{
		for (int x=0;x<20;x++){
			matrix[w][x]=0;
		}
	}

	//initialize first row, first column
	for (int a=0;a<20;a++)
	{
		matrix[0][a]=a+2;
		matrix[a][0]=a+2;
	}

	// set values to (top+left) 

	for (int row=1;row<20;row++)
	{
		for (int column=1;column<20;column++)
		{
			matrix[row][column]=matrix[row-1][column]+matrix[row][column-1];
		}
	}

	//print out matrix   
	// * printing out full matrix is unreadable, printing diagonals instead
	// * numbers became too large

	for (int z=0;z<20;z++)
	{
		cout << z << " " << matrix[z][z] << endl;
	}
	

	getchar();
	
	return 0;
}

*/