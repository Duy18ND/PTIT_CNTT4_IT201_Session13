#include <stdio.h>
#define MAX 5

int Stack[MAX];
int top = -1;
//Kiem tra xem ngan xep co rong hay khong
int isEmpty() {
    if (    top == -1) return 1;
    return 0;
}
//Ham kiem tra xem ngan xep da day hay chua?
int isFull() {
    if (top == MAX - 1) return 1;
    return 0;
}
//Ham kiem tra ptu vao trong ngan xep da day hay chua
void push(int x) {
    if (isFull()) {
        printf("Stack day\n");
        return;
    }
    top++;
    Stack[top] = x;
}
//Ham lay phan tu tren dinh ra
int pop() {
    if (isEmpty()) {
        return -1;
    }
    int temp = Stack[top];
    top--;
    return temp;
}
int main() {
    int n = 5;//Them 5 phan tu trong ngan xep
    int i = 0;
    while (n--) {
        int t;
        printf("moi ban nhap gia tri thu %d la: ", i);
        scanf("%d", &t);
        i++;
        push(t);
    }
    //In ra
    while (!isEmpty()) {
        printf("%d\n", pop());
    }
    return 0;
}