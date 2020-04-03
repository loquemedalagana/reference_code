#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct node {
	int val;
	struct node *prev;
	struct node *next;
} Node;

Node Head, Tail; //start and end
Node data;

char ord[15];

int q_empty() {
	return Head.next == &Tail || Tail.prev == &Head;
}

void q_push(Node *data) {
	Node *p = calloc(1, sizeof(Node));
	if (p == NULL) return;
	*p = *data;

	p->next = &Tail; 
	p->prev = Tail.prev;
	p->next->prev = p;
	p->prev->next = p;

}

int q_pop() {
	if (q_empty()) return -1;
	int val = Head.next->val;
	Node *del = Head.next;

	del->prev->next = del->next;
	del->next->prev = del->prev;

	free(del);
	return val;
}

int q_size() {
	int idx = 0;
	Node *ptr = Head.next;

	while (ptr->next) {
		idx++;
		ptr = ptr->next;
	}

	return idx;
}

int q_front() {
	if (q_empty()) return -1;
	else return Head.next->val;
}

int q_back() {
	if (q_empty()) return -1;
	else return Tail.prev->val;
}

int main() {
	int N, value; scanf("%d", &N);

	Head.prev = NULL, Head.next = &Tail;
	Tail.next = NULL, Tail.prev = &Head;

	while (N--) {
		scanf("%s", ord);

		if (strcmp(ord, "push") == 0) {
			scanf("%d", &data.val);
			data.prev = NULL, data.next = NULL;
			q_push(&data);
		}
		else if (strcmp(ord, "pop") == 0) {
			printf("%d\n", q_pop());
		}
		else if (strcmp(ord, "size") == 0) {
			printf("%d\n", q_size());
		}
		else if (strcmp(ord, "empty") == 0) {
			printf("%d\n", q_empty());
		}
		else if (strcmp(ord, "front") == 0) {
			printf("%d\n", q_front());
		}
		else if (strcmp(ord, "back") == 0) {
			printf("%d\n", q_back());
		}

	}

	return 0;
}