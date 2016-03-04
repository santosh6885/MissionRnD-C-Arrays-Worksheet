/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};
void swapa(int *num1, int *num2);
void swapb(char *s1, char *s2);
struct student ** topKStudents(struct student *students, int len, int K) {
	int m,i,j;
	if (students == NULL || len <= 0 || K <= 0)
		return NULL;
	if (K > len)
		K = len;
		
	struct student **temp = (struct student **)malloc(sizeof(struct student)*K);
	for (m = 0; m < K; m++){
		 temp[m] = (struct student *)malloc(sizeof(struct student));
	}
	if (students == NULL || len <= 0)
		return NULL;
	for (i = 0; i < len; i++){
		for (j = 0; j < len - i - 1; j++){
			if (((students + j)->score) < ((students + j + 1)->score)){
				swapa(&((students + j)->score), &((students + j + 1)->score));
				swapb((students + i)->name, (students + i + 1)->name);


			}
		}
		
	}
	for (i = 0; i < K; i++){
		temp[i]->score =  (students+i)->score;
		temp[i]->name = (students + i)->name;
	}
	
	return temp;

	//return NULL;
}
void swapa(int *num1, int *num2){
		int temp = *num1;
		*num1 = *num2;
		*num2 = temp;
}
void swapb(char *s1, char *s2){
		char *temp = s1;
		s1 = s2;
		s2 = temp;
}