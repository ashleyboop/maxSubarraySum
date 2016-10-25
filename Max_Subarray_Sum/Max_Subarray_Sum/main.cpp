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
	int index1=0;
	int index2=0;
	cout<<"\n";
	int newsum=array[0];
    int subsum1=array[0];
	int subsum2=array[0];
    int maxVal=array[0];
    for(int i=1;i<SIZE;i++)
	{
		//newsum starts of as the value in index 0
		//we add the value in index 1 to newsum
		//we compare their sum with the sum of the subarray: index1+index2
		//the highest value gets placed in newsum
		newsum=max(newsum+array[i],array[i]+array[i++]);
		if(newsum+array[i] > array[i]+array[i++])
		{
			//index0 + index1 - MAX
			newsum=(newsum+array[i]);
			//index1+index2 - not max
			subsum2=(array[i]+array[i++]);
		}
		else
		{
			//index1 + index2 - MAX
			newsum=(array[i]+array[i++]);
			//index0 + index1 - not max
			subsum2=(newsum+array[i]);
		}

		//newsum is the current max of the sum of the subarrays
		//add the value of the next index into newsum
		//compare it with the other subarray plus the next index since maybe it will become the largest sum subarray after that
		maxVal = max(newsum+array[i++],subsum2+array[i++]);
		//now we compare maxval with newsum and place the max of the 2 into maxVal and repeat
		maxVal= max(maxVal, newsum);
    }
	 cout<<"\n";
     cout<< maxVal;
	 cout<<"\n";


	//for(int i=1;i<SIZE;i++)
	//{
	//	newsum starts of as the value in index 0
	//	we add the value in index 1 to newsum
	//	we compare their sum with the sum of the subarray: index1+index2
	//	the highest value gets placed in newsum
	//	newsum=max(newsum+array[i],array[i]+array[i++]);

	//	newsum is 
	//	maxVal = max(newsum+array[i++],array[i]+array[i++]);
	//	now we compare maxval with newsum and place the highest value into maxVal and repeat
	//	maxVal= max(maxVal, newsum);

 //   }

	//for(int i=0; i<SIZE;i++)
	//{
	//	index1 = array[i];
	//	cout<<" "<<index1;
	//}
	//cout<<"\n";
	//for(int j=1; j<SIZE;j++)
	//{
	//	index2 = array[j];
	//	cout<<" " <<index2;
	//}
	//int sum=0;
	//int sum2=0;
	//int k=0;
	//while(k<=SIZE)
	//{
	//	for(int i=0; i<2;i++)
	//	{
	//		sum += array[i];
	//		cout<<" "<<sum;
	//	}
	//	for(int i=1; i<3;i++)
	//	{
	//		sum2 += array[i];
	//		cout<<" "<<sum2;
	//	}
	//	if(sum>sum2)
	//	{

	//	}
	//	//sum2>sum
	//	else
	//	{
	//		//sum2
	//	}
	//}
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