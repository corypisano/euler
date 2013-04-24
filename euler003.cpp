/*  projecteuler.net problem 3
 *The prime factors of 13195 are 5, 7, 13 and 29.
 *What is the largest prime factor of the number 600851475143 ? 
 */

/*
code is not perfect. does not properly handle when the number is prime, and 
recursive calls carry out unnecessarily. Gets a solution though :P
*/

#include <iostream>
#include <cmath>

using namespace std; 

long long findPrimeFactor(long long Number)
{
	//minimum prime factor is 2, maxFactor is sqrt(n), and 2 is the only even prime, so +=2
	long double maxFactor = ceil(sqrt(Number));

	for (long long factor = 2; factor < maxFactor; factor+=1)
	{
		if (Number % factor == 0)
		{
			cout << factor << ". . .\n";
			Number=findPrimeFactor(Number/factor);
		}
	}
	return Number;
}

int main()
{
	long long Number;

	cout << "Enter a number:\n";
	cin >> Number;

	cout << "\n\nPrime factors are:\n";
	Number = findPrimeFactor(Number);


	return 0;
}