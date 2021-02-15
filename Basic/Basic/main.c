#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/* 18강 파일처리
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
	printf("점수 평균 : %.2f\n", (double)sum / n);
	system("pause");
	return 0;
}
*/

/*19강 전처리기
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

	printf("원의 둘레 : %.2f\n", 2 * r * PI);
	printf("x의 제곱 : %d ", POW(x));
	system("pause");
	return 0;
}
*/
/*20강 자료구조 
#define INF 10000

int arr[INF];
int count = 0;

void addBack(int data) {
	arr[count] = data;
	count++;
}
void addFirst(int data) {
	for (int i = count; i >= 1; i--){
		arr[i] = arr[i - 1];
	}
	arr[0] = data;
	count++;
}

void removeAt(int index) {
	for (int i = index; i < count - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	count--;
}

void show() {
	for (int i = 0; i < count; i++)
	{
		printf("%d", arr[i]);
	}
}

int main(void) {
	addBack(6);
	addBack(7);
	addBack(8);
	addFirst(1);
	addFirst(2);
	addFirst(3);
	removeAt(0);
	show();
	printf("\n");
	system("pause");
	return 0;
}

//연결리스트
typedef struct {
	int data;
	struct Node *next;
}Node;

Node *head;
int main(void) {
	head = (Node*)malloc(sizeof(Node));
	Node *node1 = (Node*)malloc(sizeof(Node));
	node1->data = 1;
	Node *node2 = (Node*)malloc(sizeof(Node));
	node2->data = 2;
	head->next = node1;
	node1->next = node2;
	node2->next = NULL;
	Node *cur = head->next;
	while (cur !=NULL)
	{
		printf("%d", cur->data);
		cur = cur->next;
	}
	system("pause");
	return 0;
}
*/
//연결리스트 삽입

typedef struct {
	int data;
	struct Node *next;
}Node;

Node *head;

void addFront(Node *root, int data) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = root->next;
	root->next = node;
}

void removeFront(Node *root) {
	Node *front = root->next;
	root->next = front->next;
	free(front);
}

void freeAll(Node *root) {
	Node *cur = head->next;
	while (cur != NULL) {
		Node *next = cur->next;
		free(cur);
		cur = next;
	}
}

void showAll(Node *root) {
	Node *cur = head->next;
	while (cur != NULL)
	{
		printf("%d", cur->data);
		cur = cur->next;
	}
}


int main(void) {
	head = (Node*)malloc(sizeof(Node));
	head->next = NULL;

	addFront(head, 1);
	addFront(head, 2);
	addFront(head, 3);
	removeFront(head);
	showAll(head);
	printf("OK");
	
	
	system("pause");
	return 0;
}