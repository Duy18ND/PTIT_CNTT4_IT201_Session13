#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    int *arr;
    int top;
    int maxSize;
} Stack;

Stack createStack(int size) {
    Stack s;
    s.arr = (int *)malloc(size * sizeof(int));
    s.top = -1;
    s.maxSize = size;
    return s;
}

void push(Stack *s, int val) {
    if (s->top < s->maxSize - 1)
        s->arr[++(s->top)] = val;
}

int pop(Stack *s) {
    if (s->top == -1) return 0;
    return s->arr[(s->top)--];
}

int evaluatePostfix(char *expr) {
    int len = strlen(expr);
    Stack s = createStack(len);
    for (int i = 0; i < len; i++) {
        char c = expr[i];
        if (isdigit(c)) {
            push(&s, c - '0');
        } else {
            int b = pop(&s);
            int a = pop(&s);
            int res = 0;
            if (c == '+') res = a + b;
            else if (c == '-') res = a - b;
            else if (c == '*') res = a * b;
            else if (c == '/') res = a / b;
            push(&s, res);
        }
    }
    return pop(&s);
}

int main() {
    char expr[100];
    printf("Nhap bieu thuc hau to: ");
    scanf("%s", expr);
    int result = evaluatePostfix(expr);
    printf("Ket qua: %d\n", result);
    return 0;
}