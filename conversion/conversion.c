#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

void init_stack(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];
}

int main(void) {
	StackType s;
	init_stack(&s);
	int n, t;

	printf("���� �迭�� ũ��: \n");
	scanf_s("%d", &n);
	printf("������ �Է��Ͻÿ�: ");

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &t);
		push(&s, t);
	}

	printf("������ ���� �迭:\n");
	for (int i = 0; i < n; i++)
		printf("%d ", pop(&s));
	return 0;

}