/*
projecteuler.net Problem 1:
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/
#include <iostream>

using namespace std;

void main(){

	int N=1000; 
	int result=0;

	for (int number=0; number<N; number++)
	{
		if (number%3==0 || number%5==0)
		{
			result+=number;
		}		
	}

	cout << "The sum of the multiples is: " << result << endl;
}
