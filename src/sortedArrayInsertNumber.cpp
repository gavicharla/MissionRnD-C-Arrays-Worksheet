/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)

{
	if (Arr == NULL || len < 1)
		return NULL;
	else
	{
		int ind = 0;
		if (Arr[0]>num)
		{
			ind = 0;
		}
		else if (Arr[len - 1] < num)
			ind = len;
		else
		{
			int min = 0, max = len - 1, mid = (min + max) / 2;
			while (1)
			{
				if (Arr[mid] == num || (Arr[mid]<num&&Arr[mid + 1]>num))
					break;
				else if (Arr[mid] < num)
					min = mid;
				else if (Arr[mid] > num)
					max = mid;
				mid = (min + max) / 2;
			}
			ind = mid+1;
		}
		int max = ind + 1, i = len;
		realloc(Arr, len + 1);
		while (i>=ind+1)
		{
			Arr[i] = Arr[i - 1];
			i--;
		}
		Arr[ind] = num;

	}
	return Arr;
}