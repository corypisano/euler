// Not finished!

/*projecteuler.net problem 23
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/

#include <iostream>

using namespace std;


//returns 1 if input is 'abundant'
//returns 0 if 'deficient'
bool isAbundant(long input)
{
	//get sum of divisors
	long sum = 0;

	//check all possible divisors up to the input.
	//do not need to keep track, only the running total sum.
	for (long a=1; a <= input/2; a++)
	{
		if (input % a == 0)
		{sum += a;}
	}

	//result==1 if sum of the inputs is strictly greater than the input
	return sum>input;
}

int main()
{
	long total = 0;

	long max = 28123; //taken from problem

	//get abundant numbers into abundants[]
	long abundants[7000];
	int index=0;

	for(long a=12; a<max; a++)
	{
		if (isAbundant(a))
		{
			abundants[index++]=a;
			if (a%2 != 0)
			{cout << a << endl;}
		}
	}


	return 0;
}