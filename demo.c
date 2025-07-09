#include <stdio.h>
#include <stdlib.h>

// Cấu trúc dữ liệu stack
typedef struct Stack {
    int *arr;   // Mảng đại diện cho ngăn xếp
    int top;    // Chỉ số phần tử trên cùng
    int cap;    // Kích thước ngăn xếp
} Stack;

// Hàm khởi tạo ngăn xếp
Stack *createStack(int cap) {
    Stack *newStack = (Stack *)malloc(sizeof(Stack));
    if (newStack == NULL) {
        printf("Khong the cap phat bo nho cho Stack\n");
        return NULL;
    }

    newStack->top = -1;
    newStack->cap = cap;
    newStack->arr = (int *)malloc(sizeof(int) * cap);
    if (newStack->arr == NULL) {
        printf("Khong the cap phat bo nho cho mang\n");
        free(newStack);
        return NULL;
    }

    return newStack;
}

// Hàm kiểm tra stack đầy
int isFull(Stack *stack) {
    return stack->top == stack->cap - 1;
}

// Hàm kiểm tra stack rỗng
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Hàm thêm phần tử vào stack
int push(Stack *stack, int val) {
    if (isFull(stack)) {
        printf("Stack day. Khong the push %d\n", val);
        return 0;
    }
    stack->arr[++stack->top] = val;
    return 1;
}

// Hàm lấy phần tử ra khỏi stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack rong. Khong the pop\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Hàm xem phần tử trên cùng mà không lấy ra
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack rong. Khong co phan tu tren cung\n");
        return -1;
    }
    return stack->arr[stack->top];
}

int main(void) {
    Stack *stack = createStack(5);

    if (stack == NULL) return 1;

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("Phan tu tren cung: %d\n", peek(stack));  // 30

    printf("Pop: %d\n", pop(stack));  // 30
    printf("Pop: %d\n", pop(stack));  // 20

    push(stack, 40);
    printf("Phan tu tren cung moi: %d\n", peek(stack));  // 40

    // Gỡ hết phần tử
    pop(stack); // 40
    pop(stack); // 10
    pop(stack); // stack rỗng

    // Giải phóng bộ nhớ
    free(stack->arr);
    free(stack);

    return 0;
}
