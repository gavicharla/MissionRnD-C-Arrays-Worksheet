/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/#include<stdio.h>
#include<stdlib.h>
struct student {
	char *name;
	int score;
};
struct student ** topKStudents(struct student *students, int len, int K) 
{
	
	if (students == NULL || len<1  || K <= 0)
	{
		return NULL;
	}
	else
	{
		int  j = 0;
		if (K > len)
			K = len;
		struct student ** s = (struct student**)malloc(sizeof(struct student *)*K);
		int i;
		for (i = 0; i < K; i++)
			s[i] = (struct student *)malloc(sizeof(struct student));
		for (i = 0; i < K; i++)
		{
			for (j = i + 1; j < len; j++)
			{
				if (students[j].score>students[i].score)
				{
					int temp = students[j].score;
					students[j].score = students[i].score;
					students[i].score = temp;
				}
			}
			(*s[i]).name = students[i].name;
			(*s[i]).score = students[i].score;
		}
		
		return s;
	}
	
}
