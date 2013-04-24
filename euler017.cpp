/*projecteuler.net problem 17

If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. 
The use of "and" when writing out numbers is in compliance with British usage.
*/

#include <iostream>
#include <string>
using namespace std;

int euler17()
{
	//strings for number to letter conversions
	string ones[] = {"one","two","three","four","five","six","seven", "eight", "nine" };
	string TEENS[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	string tens[] = { "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
	string and = "and"; 
	string hundred = "hundred";
	string thousand = "thousand";

	//running total of letters {ones,TEENS,tens}
	long LetterSums[] = {0,0,0};

	/* sum of 1 through 9 is the sum of ones[] 	*/
	for (int a=0; a<9; a++)
	{
		LetterSums[0] += ones[a].length();
	}

	/* sum of teens is the sum of TEENS[] */
	for (int b=0; b<10; b++)
	{
		LetterSums[1] += TEENS[b].length();
	}

	/* 20 - 99, Every item in tens[] is counted ten times each.
	For each item in tens[], every item in ones[] is counted. The sum of "ones" is already in LetterSums[0]
	*/
	for (int c=0; c<8; c++)
	{
		LetterSums[2] += tens[c].length()*10 + LetterSums[0]; 
	}

	//so far the FinalSum is 1-99:
	int FinalSum = LetterSums[0]+LetterSums[1]+LetterSums[2];

	/* 	100 - 999,	there are 9 groups of "hundreds" [100,200,...,900]. */	
	for (int group=0; group<9; group++)
	{
		//initial "ones" get counted 100 times [100,101,...,199]
		FinalSum += ones[group].length()*100;

		// each "hundred" gets counted 100 times for each of the 9 groups
		FinalSum += hundred.length()*100;

		// "and" is used for [101-199, 201-299, etc]. All hundreds except for mulitples of 100, so 99 times per group.
		FinalSum += and.length()*99;

		// each group has the numbers 1-99 added on. These sums are already stored in letterSums[]
		FinalSum += LetterSums[0] + LetterSums[1] + LetterSums[2];
	}

	/* 	1000, add the final "one thousand" and thats it!	*/
	FinalSum += ones[0].length() + thousand.length();

	cout << "Letter total of numbers from 1 to 999 is: " << FinalSum <<endl;
	//answer: 21124
	return 0;

}
