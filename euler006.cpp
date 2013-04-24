/*projecteuler.net problem 6
The sum of the squares of the first ten natural numbers is,

1^2 + 2^2 + ... + 10^2 = 385
The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)^2 = 55^2 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025  385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

#include <iostream>
#include <cmath>	//for pow()

using namespace std;

int sumOfSquares(int max)
{
	int result = 1;

	for(int a=2; a<=max; a++)
	{
		result += pow(a,2);
	}

	return result;
}

int squareOfSums(int max)
{
	int result = 1;

	for(int a=2; a<=max; a++)
	{
		result += a;
	}
	
	return pow(result,2);
}

int main(){

	//BRUTE FORCE!!!!
	//probably a better way to do this, but for N=100, result is still computed without a noticable delay
	
	cout << squareOfSums(100) - sumOfSquares(100)  << endl;


	return 0;
}