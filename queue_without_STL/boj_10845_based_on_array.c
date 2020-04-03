//10845 Queue
#include <stdio.h>
#include <string.h>

#define MAX_Q 10001
#define FULL MAX_Q
#define EMPTY 0

int Q[MAX_Q];
int st = EMPTY, en = EMPTY; //front and back
char ord[15];

//push
void q_push(int data) {
	Q[en++] = data;
}

//pop
int q_pop() {
	if (st == en) return -1;
	int val = Q[st++];
	return val;
}

//size
int q_size() {
	return en-st;
}

//empty
int q_empty() {
	if (st == en) return 1;
	else return 0;
}

//front
int q_front() {
	if (q_empty()) return -1;
	else return Q[st];
}

//back
int q_back() {
	if (q_empty()) return -1;
	else return Q[en - 1];
}

int main() {
	int N, value; scanf("%d", &N);

	while (N--) {
		scanf("%s", ord);

		if (strcmp(ord, "push") == 0) {
			scanf("%d", &value);
			q_push(value);
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