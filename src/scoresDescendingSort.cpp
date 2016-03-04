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
void swap1(int *num1, int *num2);
void swap2(char *str1, char *str2);

void * scoresDescendingSort(struct student *students, int len) {
	int i,j;
	if (students == NULL || len <= 0)
		return NULL;
	for (i = 0; i < len; i++){
		for (j = 0; j < len - i - 1; j++){
			if (((students + j)->score) < ((students + j + 1)->score)){
				swap1(&((students + j)->score), &((students + j + 1)->score));
				swap2((students + i)->name, (students + i + 1)->name);


			}
		}
	}


	//return NULL;
}
void swap1(int *num1,int *num2){
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;

}
void swap2(char *s1, char *s2){
	char *temp = s1;
	s1 = s2;
	s2 = temp;
}