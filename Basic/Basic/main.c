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

/*19�� ��ó����
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
*/
/*20�� �ڷᱸ�� 
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

//���Ḯ��Ʈ
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
//���Ḯ��Ʈ ����

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
*/
/*22�� ����� ���� ����Ʈ
typedef struct {
	int data;
	struct Node *prev;
	struct Node *next;
} Node;

Node *head, *tail;

void insert(int data) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	Node *cur;
	cur = head->next;
	while (cur->data < data && cur != tail)
	{
		cur = cur->next;
	}
	Node *prev = cur->prev;
	prev->next = node;
	node->prev = prev;
	cur->prev = node;
	node->next = cur;
}
void removeFront() {
	Node *node = head->next; 
	head->next = node->next;
	Node *next = node->next;
	next->prev = head;
	free(node);
} 

void show() {
	Node *cur = head->next;
	while (cur != tail) {
		printf("%d", cur->data);
		cur = cur->next;
	}
}

int main(void) {
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	head->next = tail;
	head->prev = head;
	tail->next = tail;
	tail->prev = head;
	insert(1);
	insert(2);
	printf("OK");
	system("puase");
	return 0;
}
*/

/*23�� ����

#define SIZE 10000
#define INF 99999999

int stack[SIZE];
int top = -1;


void push(int data) {
	if (top == SIZE - 1)
	{
		printf("�����÷ο� �߻�");
		return;
	}
	stack[++top] = data;
}

void pop() {
	if (top == -1)
	{
		printf("����÷ο� �߻�");
		return -INF;
	}
	return stack[top--];
}

void show() {
	printf("������ �ֻ��\n");
	for (int i = top; i >= 0; i--)
	{
		printf("%d\n", stack[i]);
	}
	printf("������ �ϴ�\n");
}

 
int main(void) {
	push(7);
	push(5);
	push(4);
	pop();
	show();
	system("pause");
	return 0;
}
*/ 
#define INF 9999999

typedef struct {
	int data;
	struct Node *next;
}Node;

typedef struct {
	Node *top;
} Stack;

void push(Stack *stack, int data) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = stack->top;
	stack->top = node;
}

int main(void) {


	system("pause");
	return 0;
}