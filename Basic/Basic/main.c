#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/* 18�� ����ó��
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	char name[2];
	int score;
}Student;

int main(void) {
	int n = 0;
	int sum = 0;
	FILE *fp;
	fp = fopen("input.txt", "r");
	fscanf(fp, "%d", &n);
	printf("%d\n", n);
	Student *students = (Student*)malloc(sizeof(Student) * n);
	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%s %d", &((students + i)->name), &((students + i)->score));
	}
	for (int i = 0; i < n; i++)
	{
		sum += (students + i)->score;
	}
	free(students);
	fclose(fp);
	printf("���� ��� : %.2f\n", (double)sum / n);
	system("pause");
	return 0;
}
*/

/*19�� ��ó����*/
#include "temp.h"
#include "temp.h"
#define PI 3.14159263535
#define POW(x) (x * x)
#define ll long long
#define ld long double

int main(void) {
	int r = 10;
	int x = 10;
	ll a = 987654321000;
	ld b = 100.5054;
	printf("%.1f\n", a * b);

	printf("���� �ѷ� : %.2f\n", 2 * r * PI);
	printf("x�� ���� : %d ", POW(x));
	system("pause");
	return 0;
}

