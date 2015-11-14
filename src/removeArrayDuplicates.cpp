/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

INPUTS: Integer array and length of the array.

OUTPUT: Update input array by removing duplicate values.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>
#include<malloc.h>
int partition(int *x, int p, int r)
{
	int z = x[r - 1];
	int i = p - 1;
	int j = 0;
	int temp;
	for (j = i + 1; j < r - 1; j++)
	{
		if (x[j] <= z)
		{
			i++;
			
			temp = x[i];
			
			x[i]= x[j];
			
			x[j]= temp;

		}
	}
	
	temp= x[i + 1];
	x[i + 1] = x[r - 1];
	x[r - 1] = temp;
	return i + 1;
}
void quicksort(int *x, int p, int r)
{
	int q;
	if (p < r)
	{
		q = partition(x, p, r);
		quicksort(x, 0, q - 1);
		quicksort(x, q + 1, r);
	}
}
void * removeArrayDuplicates(int *Arr, int len)
{
	if (Arr == NULL || len < 1)
		return NULL;
	int i = 0, min = 0, max = len - 1, mid = (min + max) / 2;
	quicksort(Arr, 0, len);
	for (i = 0; i < len; i++)
	{
		if (Arr[i] != Arr[i + 1])
			i++;
		else
		{
			min = i;
			max = len - 1;
			while (1)
			{
				if ((Arr[mid] == Arr[i] && Arr[mid + 1] != Arr[i])||i==len-1)
					break;
				if ((Arr[mid] == Arr[len - 1]))
				{
					len = mid + 1;
					Arr = (int*)realloc(Arr, sizeof(int)*len);
					break;
				}
				if (Arr[mid] < Arr[i])
					min = mid;
				else if (Arr[mid] > Arr[i])
					max = mid;
				else
					min = mid;
				mid = (min + max) / 2;
			}
			int j = 0, k = mid + 1;
			for (j = i + 1; k < len; k++, j++)
			{
				Arr[j] = Arr[k];
			}
			len = len - mid + i;
			//Arr = (int*)realloc(Arr, sizeof(int)*len);
		}

	}


	return NULL;
}