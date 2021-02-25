#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

19강 전처리기
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

20강 자료구조
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

연결리스트
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
연결리스트 삽입

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


22강 양방향 연결 리스트
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


23강 스택

#define SIZE 10000
#define INF 99999999

int stack[SIZE];
int top = -1;


void push(int data) {
	if (top == SIZE - 1)
	{
		printf("오버플로우 발생");
		return;
	}
	stack[++top] = data;
}

void pop() {
	if (top == -1)
	{
		printf("언더플로우 발생");
		return -INF;
	}
	return stack[top--];
}

void show() {
	printf("스택의 최상단\n");
	for (int i = top; i >= 0; i--)
	{
		printf("%d\n", stack[i]);
	}
	printf("스택의 하단\n");
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

void pop(Stack *stack) {
	if (stack->top == NULL)
	{
		printf("스택 언더플로우\n");
		return -INF;
	}
	Node *node = stack->top;
	int data = node->data;
	stack->top = node->next;
	free(node);
	return data;
}

void show(Stack *stack) {
	Node *cur = stack->top;
	printf("스택의 최상단\n");
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("스택의 최하단\n");
}


int main(void) {
	Stack stack;
	stack.top = NULL;
	push(&stack,7);
	push(&stack, 5);
	push(&stack, 4);
	pop(&stack);
	show(&stack);

	system("pause");
	return 0;
}


24강 스택을 활용한 계산기 만들기

typedef struct {
	char data[100];
	struct Node *next;
}Node;

typedef struct {
	Node *top;
}Stack;

void push(Stack *stack, char *data) {
	Node *node = (Node*)malloc(sizeof(Node));
	strcpy(node->data, data);
	node->next = stack->top;
	stack->top = node;
}
int getTop(Stack *stack) {
	Node *top = stack->top;
	return top->data;
}

int pop(Stack *stack) {
	if (stack->top == NULL){
		printf("스택 언더 플로우");
		return NULL;
	}
	Node *node = stack->top;
	char *data = (char*)malloc(sizeof(char) * 100);
	strcpy(data, node->data);
	stack->top = node->next;
	free(node);
	return data;
}

int getPriority(char *i) {
	if (!strcmp(i, "(")) {
		return 0;
	}
	if (!strcmp(i, "+") || !strcmp(i, "-")) {
		return 1;
	}
	if (!strcmp(i, "*") || !strcmp(i, "/")) {
		return 2;
	}
	return 3;
}

char *transition(Stack *stack, char **s, int size) {
	char res[1000] = "";
	for (int i = 0; i < size; i++) {
		if (!strcmp(s[i], "+") || !strcmp(s[i], "-")
			|| !strcmp(s[i], "*") || !strcmp(s[i], "/")) {
			while (stack->top != NULL && getPriority(getTop(stack))
				>= getPriority(s[i]))
			{
				strcat(res, pop(stack));
				strcat(res, " ");
			}
			push(stack, s[i]);
		}
		else if (!strcmp(s[i], "(")) push(stack, s[i]);
		else if (!strcmp(s[i], ")")) {
			while (strcmp(getTop(stack), "(")) {
				strcat(res, pop(stack));
				strcat(res, " ");
			}
			pop(stack);
		}
		else {
			strcat(res, s[i]);
			strcat(res, " ");
		}
	}
	while (stack->top != NULL) {
		strcat(res, pop(stack));
		strcat(res, " ");
	}
	return res;
}

void calculate(Stack *stack, char **s, int size) {
	int x, y, z;
	for (int i = 0; i < size; i++) {
		if (!strcmp(s[i], "+") || !strcmp(s[i], "-") ||
			!strcmp(s[i], "*") || !strcmp(s[i], "/")) {
			x = atoi(pop(stack));
			y = atoi(pop(stack));
			if (!strcmp(s[i], "+")) z = y + x;
			if (!strcmp(s[i], "-")) z = y - x;
			if (!strcmp(s[i], "*")) z = y * x;
			if (!strcmp(s[i], "/")) z = y / x;
			char buffer[100];
			sprintf(buffer, "%d", z);
			push(stack, buffer);
			
		}
		else {
			push(stack, s[i]);
		}
	}
	printf("%s\n", pop(stack));
}

int main(void) {
	Stack stack;
	stack.top = NULL;
	char a[100] = "( ( 3 + 4 ) * 5 ) - 35";
	int size = 1;
	for (int i = 0; i < strlen(a); i++){
		if (a[i] == ' ') size++;
	}
	char *ptr = strtok(a, " ");
	char **input = (char**)malloc(sizeof(char*) * size);
	for (int i = 0; i < size; i++) {
		input[i] = (char*)malloc(sizeof(char) * 100);
	}
	for (int i = 0; i < size; i++) {
		strcpy(input[i], ptr);
		ptr = strtok(NULL, " ");
	}
	char b[1000] = "";
	strcpy(b, transition(&stack, input, size));
	printf("후위 표기법 : %s\n", b);
	size = 1;

	for (int i = 0; i < strlen(b) - 1; i++) {
		if (b[i] == ' ') size++;
	}

	char *ptr2 = strtok(b, " ");
	for (int i = 0; i < size; i++) {
		strcpy(input[i], ptr2);
		ptr2 = strtok(NULL, " ");
	}

	calculate(&stack, input, size);
	system("pause");
	return 0;
}


25강 큐
배열을 이용
#define SIZE 10000
#define INF 99999999

int queue[SIZE];
int front = 0;
int rear = 0;

int push(int data) {
	if (rear >= SIZE) {
		printf("큐 오버플로우\n");
		return;
	}
	queue[rear++] = data;
}

int pop() {
	if (front == rear) {
		printf("큐 언더플로우\n");
		return -INF;
	}
	return queue[front++]; 
}

void show() {
	printf("큐의 앞\n");
	for (int i = front; i < rear; i++) {
		printf("%d\n", queue[i]);
	}
	printf("큐의 뒤\n");
}

int main(void) {
	push(1);
	push(2);
	push(3);
	push(4);
	pop();
	show();
	system("pause");
	return 0;
}

연결리스트를 이용한 큐

#define INF 99999999

typedef struct {
	int data;
	struct Node *next;
} Node;

typedef struct {
	Node *front;
	Node *rear;
	int count;
} Queue;

void push(Queue *queue, int data) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	if (queue->count == 0) {
		queue->front = node;
	}
	else
	{
		queue->rear->next = node;
	}
	queue->rear = node;
	queue->count++;
}

void pop(Queue *queue) {
	if (queue->count == 0) {
		printf("큐 언더플로우");
		return -INF;
	}
	Node *node = queue->front;
	int data = node->data;
	queue->front = node->next;
	free(node);
	queue->count--;
	return data;
}

void show(Queue *queue) {
	Node *cur = queue->front;
	printf("큐의 앞\n");
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("큐의 뒤\n");
}

int main(void) {
	Queue queue;
	queue.front = queue.rear = NULL;
	queue.count = 0;

	push(&queue, 1);
	push(&queue, 2);
	push(&queue, 3);
	pop(&queue);
	show(&queue);

	system("pause");
	return 0;
}

#include<limits.h>
#define SIZE 1000

int a[SIZE];

int swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(void) {
	int n, min, index;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		min = INT_MAX;
		for (int j = i; j < n; j++) {
			if (min > a[j]) {
				min = a[j];
				index = j;
			}
		}
		swap(&a[i], &a[index]);
	}
	for (int i = 0; i < n; i++) {
		printf("%d", a[i]);
	}

		system("pause");
		return 0;

}

#include<limits.h>
#define SIZE 1000

int a[SIZE];

int swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(void) {
	int n, min, index;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n - 1; i++) {
		int j = i;
		while (j >=0 && a[j] > a[j + 1])
		{
			swap(&a[i], &a[j + 1]);
			j--;
		}
	}
	
	for (int i = 0; i < n; i++) {
		printf("%d", a[i]);
	}
	system("pause");
	return 0;

}

#include<limits.h>
#define SIZE 1000

int a[SIZE];

int swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void quickSort(int start, int end) {
	if (start >= end) return;
	int key = start, i = start + 1, j = end;
	while (i <= j) {
		while (i <= end && a[i] <= a[key]) i++;
		while (j > start && a[j] >= a[key]) j--;
		if (i > j) swap(&a[key], &a[j]); // 피벗 결과가 서로 엇갈릴 때
		else swap(&a[i], &a[j]);
	}
	quickSort(start, j - 1);
	quickSort(j + 1, end);
}

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	quickSort(0, n - 1);
	for (int i = 0; i < n; i++) printf("%d", a[i]);
	system("pause");
	return 0;
}


*/