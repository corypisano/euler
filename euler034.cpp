#include <iostream>

using namespace std;

//gets the sum of the factorial of each digit
long Sum_Factorial_Digits(int facts[],long n)
{
	int digit = 0;
	long sum = 0;
	//get each digit
	while(n>0)
	{
		digit=n%10;
		n/=10;
		//add factoral of digit to the sum
		sum+=facts[digit];
	}
	return sum;
}

int euler034()
{
	//preallocate factorial array. only going to be using 0! through 9!
	int factorials[10];
	factorials[0]=1;
	for (int index=1;index<10;index++)
	{
		factorials[index]=index;
		int i=index;
		while(i>2)
		{
			factorials[index]*=--i;
		}
	}

	//get result
	int result = 0;
	for (long a=3; a<1000000; a++)
	{
		if (Sum_Factorial_Digits(factorials,a)==a)
		{
			cout << a << endl;
			result+=a;
		}
	}

	cout << "\n\ndone! Final sum is: " << result;

	return 0;
}