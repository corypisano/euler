/*
4/29/2012 5:24 (only working on it til i leave for dinner)

amicable pairs
first thoughts- use a  function to find divisors and sum them, store original number and sum in container next to each other, be able to look up at the end
*/

#include <iostream>
using namespace std;

int divisorSum(int original){

	//find divisors
	int sum=1;
	for (int a=2;a<original;a++)
	{
		if  (original%a==0)
		{
			sum+=a;
		}
	}
	return sum;
}

int main(){
	const int size=10000;
	int matrix[size][2];
	for (int n=0;n<size;n++)
	{
		matrix[n][0]=n;
		matrix[n][1]=divisorSum(n);
	}
	
	cout << matrix[220][1] << " " << matrix[220][0] << endl;
	cout << matrix[284][1] << " " << matrix[284][0] << endl;

	int amicable[50]={0};
	
	int count =0;
	for (int shit=0;shit<10000;shit++)
	{
		if (matrix[shit][1]<10000){
		if (matrix[shit][0]==matrix[ (matrix[shit][1]) ][1] )
		{
			if (matrix[shit][0] != matrix[shit][1])
			{
			amicable[count]=matrix[shit][0];
			count++;
			amicable[count]=matrix[shit][1];
			count++;
			}
		}
		if (count>49)
			break;
		}
	}

	for (int tits=0;tits<50;tits++)
	{
		for (int balls=tits+1;balls<50;balls++)
		{
			if (amicable[tits]==amicable[balls])
			{
				amicable[balls]=0;
			}
		}
	}

	int sum=0;
	for (int fuck1=0;fuck1<50;fuck1++)
	{
		sum+=amicable[fuck1];
	}

	for (int fuck=0;fuck<50;fuck++)
	{
		cout << amicable[fuck] <<" ";
	}
	cout << "\n\n\nanswer:"<<sum;
	getchar();
	return 0;
}