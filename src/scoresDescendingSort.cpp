/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

struct student {
	char name[10];
	int score;
};
int partition(struct student *x, int p, int r)
{
	int z = x[r - 1].score;
	int i = p - 1;
	int j = 0;
	struct student temp;
	int k;
	for (j = i + 1; j < r - 1; j++)
	{
		if (x[j].score >= z)
		{
			i++;
			for (k = 0; x[i].name[k] != '\0'; k++)
			{
				temp.name[k] = x[i].name[k];
			}
			temp.name[k] = '\0';
			temp.score = x[i].score;
			for (k = 0; x[j].name[k] != '\0'; k++)
			{
				x[i].name[k] = x[j].name[k];
			}
			x[i].name[k] = '\0';
			x[i].score = x[j].score;
			for (k = 0; temp.name[k] != '\0'; k++)
			{
				x[j].name[k] = temp.name[k];
			}
			x[j].name[k] = '\0';
			x[j].score = temp.score;

		}
	}
	for (k = 0; x[i + 1].name[k] != '\0'; k++)
	{
		temp.name[k] = x[i + 1].name[k];
	}
	temp.name[k] = '\0';
	temp.score = x[i + 1].score;

	for (k = 0; x[r - 1].name[k] != '\0'; k++)
	{
		x[i + 1].name[k] = x[r - 1].name[k];
	}
	x[i + 1].name[k] = '\0';
	x[i + 1].score = x[r - 1].score;
	for (k = 0; temp.name[k] != '\0'; k++)
	{
		x[r - 1].name[k] = temp.name[k];
	}
	x[r - 1].name[k] = '\0';
	x[r - 1].score = temp.score;
	return i + 1;
}
void quicksort(struct student *x, int p, int r)
{
	int q;
	if (p < r)
	{
		q = partition(x, p, r);
		quicksort(x, 0, q - 1);
		quicksort(x, q + 1, r);
	}
}
void * scoresDescendingSort(struct student *students, int len) {
	if (students == NULL || len<1)
		return NULL;
	else
	{
		quicksort(students, 0, len);
	}
}