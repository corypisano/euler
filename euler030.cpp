/*projecteuler.net problem 30

Surprisingly there are only three numbers that can be written as the sum of 
fourth powers of their digits:

1634 = 14 + 64 + 34 + 44
8208 = 84 + 24 + 04 + 84
9474 = 94 + 44 + 74 + 44
As 1 = 14 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth 
powers of their digits.
*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void GetDigits(long double digitarray[], long long number)
{
	//clear the digit array
	for (int a=0;a<6;a++)
	{digitarray[a]=0;}

	int index=0;
	//extract each digit, place into digit array
	while (number>0)
	{
		digitarray[index++]=number%10;
		number/=10;
	}
}

int euler030()
{
	long double DigitSum;
	long double result=0;
	for (long long number=2; number < 1000000; number++)
	{
		long double digitarray[6];
		GetDigits(digitarray,number);

		DigitSum=pow(digitarray[0],5) +
			pow(digitarray[1],5) +
			pow(digitarray[2],5) +
			pow(digitarray[3],5) +
			pow(digitarray[4],5) +
			pow(digitarray[5],5);

		if (DigitSum==number)
		{
			cout << number << " sum of fifth power of digits: " << DigitSum << endl;
			result+=number;
		}
	}

	cout << "\n\nThe total sum is: " << result << endl;

	return 0;
}