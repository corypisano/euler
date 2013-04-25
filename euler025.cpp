/*projecteuler.net problem 25

The Fibonacci sequence is defined by the recurrence relation:

Fn = F(n-1) + F(n-2), where F1 = 1 and F2 = 1...
F11 = 89
F12 = 144
The 12th term, F12, is the first term to contain three digits.

What is the first term in the Fibonacci sequence to contain 1000 digits?
*/

/*
got me an answer, but took about 2 minutes for the code to run. 
meh.
*/

#include <iostream>
#include <string>

//BIG number library- windows port of GMP, using mpirxx for standard interface
#include <mpirxx.h>

using namespace std;

//get number of digits of GMP number
int digits(mpz_class num)
{
	int digits=0;
	while(num>0)
	{
		num/=10;
		digits++;
	}
	return digits;
}

int euler025()
{

	mpz_class fn; //f(n)
	mpz_class fn1;//f(n-1)
	mpz_class fn2;//f(n-2)

	//initalize
	fn2=1;
	fn1=1;
	fn=fn1+fn2;

	int NumDigits=0;
	int a=4;
	while (NumDigits < 1000)
	{
		fn2=fn1;
		fn1=fn;
		fn=fn1+fn2;
		NumDigits=digits(fn);
		cout << "F(" << a++ << ") = " << fn << endl;
		cout << "digits = " << NumDigits << endl << endl;
	}

	
	return 0;
}