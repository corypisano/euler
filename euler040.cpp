/*projecteuler.net problem 40
An irrational decimal fraction is created by concatenating the positive integers:

0.123456789101112131415161718192021...

It can be seen that the 12th digit of the fractional part is 1.

If dn represents the nth digit of the fractional part, find the value of the following expression.

d1  d10  d100  d1000  d10000  d100000  d1000000
*/

/*
to have 1,000,000 digits in the decimal, we need to concatenate positive numbers up to:
(approximately) 1*10 + 2*90 + 3*900 + 4*9000 + 5*90000 + 6*900000 = 5,888,890
(closer approximation) 1*10 + 2*90 + 3*900 + 4*9000 + 5*90000 + 6*100000 = 1,088,890
so numbers 1 to 200,000 will be needed.

simple solution:
write out numbers 1 to 200,000 to a text file, get each power of 10 digit
*/

#include <iostream>
#include <fstream>
using namespace std;

#define N1 100
#define N2 100

int euler040()
{
	fstream dataFile;
	dataFile.open("euler40data.txt", fstream::out | fstream::trunc);
	for (long n=1; n<N1; n++)
	{
		dataFile << n;
	}
	dataFile.close();

	dataFile.open("euler40data.txt", fstream::in);
	char ch;
	for(long index=1; index<N2; index++)
	{
		ch=dataFile.get();
		cout << ch << " ";

		if (index%10==0)
			cout << "\n.\n";
	}
	dataFile.close();

	cout << "done\n";
	return 0;
}