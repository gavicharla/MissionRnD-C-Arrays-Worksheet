/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	if (Arr == NULL || len < 1)
		return NULL;
	int count = 0,i=0,a=0,b=0;
	while (i < len-1)
	{
		if (Arr[i] > Arr[i + 1])
		{
			if (count == 0)
			{
				a = i;//the first misplaced element
				count++;
			}
			else
				b = i + 1;//second misplaced element
		}
		i++;
	}
	int temp = *(Arr+a);
	*(Arr+a) = *(Arr+b);//exchanging both
	*(Arr+b) = temp;
}