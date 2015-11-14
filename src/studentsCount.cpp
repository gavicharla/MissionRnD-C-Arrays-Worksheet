
/*
OVERVIEW:  Write a function that takes ascending sorted student's score array and tells how many number of students got more marks and how many students got less marks than the given student.
E.g.: Input array: [10, 20, 30, 40, 50], score: 30, lessCount value is 2 (10, 20 are less than 30), moreCount value is 2 (40, 50 are greater than 30).

INPUTS: Ascending sorted student marks array, length of the array, one student score, lessCount and moreCount are to be
used to store final results.

OUTPUT: Update lessCount and moreCount with number of students less than and more than given score.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>

void * studentsCount(int *Arr, int len, int score, int *lessCount, int *moreCount) {
	if (len<1||Arr==NULL)
	return NULL;
	else
	{
		int i = 0, a = 0, b = 0;
		/*while (i < len)
		{
		if (Arr[i]>score)
		a++;
		if (Arr[i] < score)
		b++;
		i++;
		}*/
		//this uses better binary search algo than linear search
		if (len == 1)
		{
			if (Arr[0] > score)
			b = 1;
			else if (Arr[0] < score)
				a = 1;
			*lessCount = a;
			*moreCount = b;
			
		}
		else
		{
			int min = 0, max = len - 1, mid = (min + max) / 2;
			while (1)
			{
				if (Arr[mid] == score || (Arr[mid]<score&&Arr[mid + 1]>score))
					break;
				else if (Arr[mid] < score)
					min = mid;
				else if (Arr[mid] > score)
					max = mid;
				mid = (min + max) / 2;
			}
			b = len - 1 - mid;
			a = mid, i = 1;
			int flag1 = 1, flag2 = 1;
			while (flag1 == 1 || flag2 == 1)
			{
				if (mid - i >= 0 && flag1 == 1)
				{
					if (Arr[mid - i] == score)
						a--;
					else
						flag1--;
				}
				else
					flag1--;
				if (mid + i < len&&flag2 == 1)
				{
					if (Arr[mid + i] == score)
						b--;
					else
						flag2--;
				}
				else
					flag2--;

				i++;
			}
			*lessCount = a;
			*moreCount = b;
			if (Arr[mid] != score)
			{
				*lessCount=a+1;
			}

		}
	}
}
