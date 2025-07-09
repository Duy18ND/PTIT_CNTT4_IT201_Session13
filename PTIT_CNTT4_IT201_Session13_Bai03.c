#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int top;
    int capacity;
} Stack;

Stack taoStack(int kichThuocToiDa) {
    Stack s;
    s.data = (int*)malloc(sizeof(int) * kichThuocToiDa);
    if (s.data == NULL) {
        printf("Loi cap phat bo nho!\n");
        exit(1);
    }
    s.top = -1;
    s.capacity = kichThuocToiDa;
    return s;
}

int day(Stack* s) {
    return s->top == s->capacity - 1;
}

void them(Stack* s, int giaTri) {
    if (day(s)) {
        printf("Stack day, khong the them %d\n", giaTri);
        return;
    }
    s->top++;
    s->data[s->top] = giaTri;
}

void inThongTinStack(Stack* s) {
    printf("stack={\n");
    printf("    elements: [");
    for (int i = 0; i <= s->top; i++) {
        printf("%d", s->data[i]);
        if (i < s->top) printf(", ");
    }
    printf("],\n");
    printf("    top: %d,\n", s->top);
    printf("    cap: %d\n", s->capacity);
    printf("}\n");
}

int main() {
    Stack s = taoStack(5);
    int giaTri;

    for (int i = 0; i < 5; i++) {
        printf("Nhap phan tu thu %d la: ", i);
        scanf("%d", &giaTri);
        them(&s, giaTri);
    }

    inThongTinStack(&s);

    // Nhap index muon lay phan tu
    int indexNhap;
    printf("Nhap index phan tu muon lay: ");
    scanf("%d", &indexNhap);

    if (indexNhap >= 0 && indexNhap <= s.top) {
        printf("Phan tu tai index %d la: %d\n", indexNhap, s.data[indexNhap]);
    } else {
        printf("Index %d khong hop le hoac phan tu trong\n", indexNhap);
    }

    free(s.data);
    return 0;
}
