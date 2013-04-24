/*projecteuler.net problem 4
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91  99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <iostream>
using namespace std;

bool isNumericPalindrome(int number)
{
	int index=0;
	//digit cannot be greater than 9, so initialize to 10 to handle <6 digit numbers
	int digits[6]={10,10,10,10,10,10};

	do{
		digits[index++]=number%10;
		number/=10;
	} while(number>0);


	if(digits[5]==digits[0] && digits[4]==digits[1] && digits[3]==digits[2] )
	{
		return 1;
	}

	return 0;
}

int main(){

	int largestPalindrome = 0;

	for(int a=999; a>99; a--)
	{
		for (int b=a; b>99; b--)
		{
			if ((a*b > largestPalindrome) && isNumericPalindrome(a*b))
			{
				largestPalindrome=a*b;
			}
			
		}
	}

	cout << "Largest palindrome made from the product of two 3-digit numbers is: " << largestPalindrome <<endl;

	return 0;
}