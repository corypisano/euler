/*
-- eulerproject.net problem 42
-- Cory Pisano
-- December 3, 2013

Coded triangle numbers

The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. 
For example, the word value for 
		SKY is 19 + 11 + 25 = 55 = t10. 
		
If the word value is a triangle number then we shall call the word a triangle word.

Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?
*/

#include <iostream>
using namespace std;


// convert from ascii to alphabetical position
// (A->1, a->1, B->2, ...)
int ascii2num(char abc)
{
	int num;
	if (abc >= 'A' && abc <= 'Z'){
		num = abc - 'A' + 1; // UPPERCASE
	}
	else if (abc >= 'a' && abc <= 'z'){
		num = abc - 'a' + 1; // lowercase
	}
	else{
		num = 0; // errorcase
	}
	return num;
}


int euler042()
{	
	// generate lookup table of triangular numbers
	const int tN = 50;
	int triangleNums[tN];
	for (int i = 1; i < tN; i++){
		triangleNums[i] = i/2*(i+1);
	}

	
	
	return 0;
}