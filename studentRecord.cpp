
#include "stdafx.h"
#include <string.h>
#include <iostream>
using namespace std;

struct student
{
	char name[50];
	int id;
	int *course;
};

void course_saving(struct student list[10], int NumStudent)
{
	int ID;
	int k = 0;
	char str1[100] = { 'C:\\' };
	char str2[50];
	char str3[10] = { '.txt' };
	cout << "Enter an ID";
	cin >> ID;
	for (k = 0;k < NumStudent;k++)
	{
		if (list[k].id == ID)
		{
			FILE *fptr2;
			for (int i = 0;list[k].name[i] != '\0';i++)
			{
				str2[i] = list[k].name[i];
			}
			strcat_s(str1, str2);
			cout << "First concat:\n" << str1;
			strcat_s(str1, str3);
			cout << "Second concat:\n" << str1;
			fopen_s(&fptr2, "*str3", "w");
			fprintf(fptr2, "%d", list[k].course);
		}
	}
}

void saving(struct student list[], int NumStudent, int n)
{
	list[n];
	int NumCourse;
	int i;//student id
	int j;//course id
	FILE *fptr;
	fopen_s(&fptr, "D:\\StudentInfo.bin", "wb");
	for (i = 0;i < NumStudent;i++)
	{
		cout << "Enter the student's name.\n";
		cin >> list[i].name;
		fprintf(fptr, "%d", list[i].name);
		cout << "Enter studen's ID.\n";
		cin >> list[i].id;
		fprintf(fptr, "%d", list[i].id);
		cout << "How many courses are you entering?\n";
		cin >> NumCourse;
		list[i].course = (int*)malloc(NumCourse * sizeof(int));
		for (j = 0;j < NumCourse;j++)
		{
			cout << "Enter a course code.\n";
			scanf_s("%d", &list[i].course + j);
			fprintf(fptr, "%d", list[i].course + j);
		}
	}
	fclose(fptr);
}

int main()
{
	struct student list[10];
	int NumStudent;
	cout << "How many students are you entering?\n";
	cin >> NumStudent;
	saving(&list[10], NumStudent, 10);
	course_saving(&list[10], NumStudent);
	return 0;
}
