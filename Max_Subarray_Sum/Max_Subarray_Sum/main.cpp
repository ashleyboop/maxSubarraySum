#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 5;

void randomFunc(int[]);
void display(int[]);
void max_sub(int[], int n);

void max_sub(int array[], int n)
{
	cout<<"\n";
	int newsum=array[0];
    int maxVal=array[0];

	int begin=0;
	int end=0;
	for(int i=1;i<SIZE;i++)
	{
		//newsum starts of as the value in index 0, we add the value in index 1 to newsum
		//we compare their sum with the sum of the subarray: index1+index2
		//the highest value gets placed in newsum
		newsum=max(newsum+array[i],array[i]+array[i++]);
		
		//newsum=max(array[i],newsum+array[i]);
		//maxVal = max(newsum+array[i++],array[i]+array[i++]);
		
		//now we compare maxval with newsum and place the highest value into maxVal and repeat
		maxVal= max(newsum,maxVal);
		
		//track the beginning and ending of the max subarray sum
		//NOT WORKING
		if(newsum>0 && newsum>maxVal)
		{
			end=i;
		}
		else
		{
			begin=0;
			end=i;
		}
    }
	cout<<maxVal<<"\n";
	cout<<"Starting index is: "<<begin<<"\n";
	cout<<"Ending index is: " <<end<<"\n";
}



void randomFunc(int array[])
{
	for (int i = 0; i <SIZE; i++)
	{
		array[i] = 1+rand() % 10;
	}
}

void display(int array[])
{
	for (int i = 0; i < SIZE; i++)
	{
			  cout << array[i] << " ";
	}
	cout <<"\n";
}

int main()
{
	int A[SIZE];
	srand(time(NULL));
	randomFunc(A);
	display(A);
	max_sub(A, SIZE);
	return 0;
}