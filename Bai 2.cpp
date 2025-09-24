#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev, * next;
} Node;

// T?o node m?i
Node* createNode(int x) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->prev = p->next = NULL;
    return p;
}

// Thêm cu?i danh sách
void insertTail(Node** head, int x) {
    Node* p = createNode(x);
    if (*head == NULL) {
        *head = p;
        return;
    }
    Node* q = *head;
    while (q->next != NULL) q = q->next;
    q->next = p;
    p->prev = q;
}

// Xu?t danh sách xuôi
void printForward(Node* head) {
    Node* p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// Xu?t danh sách ng??c
void printBackward(Node* head) {
    if (head == NULL) return;
    Node* p = head;
    while (p->next != NULL) p = p->next; // t?i cu?i
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->prev;
    }
    printf("\n");
}

// Tìm giá tr? x
Node* search(Node* head, int x) {
    Node* p = head;
    while (p != NULL) {
        if (p->data == x) return p;
        p = p->next;
    }
    return NULL;
}

// Xóa ??u
void deleteHead(Node** head) {
    if (*head == NULL) return;
    Node* p = *head;
    *head = (*head)->next;
    if (*head != NULL) (*head)->prev = NULL;
    free(p);
}

// Xóa cu?i
void deleteTail(Node** head) {
    if (*head == NULL) return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    Node* p = *head;
    while (p->next != NULL) p = p->next;
    p->prev->next = NULL;
    free(p);
}

// Xóa theo giá tr?
void deleteValue(Node** head, int x) {
    Node* p = search(*head, x);
    if (p == NULL) return;
    if (p->prev != NULL) p->prev->next = p->next;
    else *head = p->next; // xóa ??u
    if (p->next != NULL) p->next->prev = p->prev;
    free(p);
}

// S?p x?p t?ng d?n
void sortList(Node** head) {
    for (Node* i = *head; i != NULL; i = i->next) {
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                int tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
}

int main() {
	printf("Nguyen Vo Hoang Phi\n");
    Node* head = NULL;
    int chon, x, n;

    do {
        printf("\n--- MENU DSLK KEP ---\n");
        printf("1. Nhap danh sach\n");
        printf("2. Xuat xuoi\n");
        printf("3. Xuat nguoc\n");
        printf("4. Tim phan tu\n");
        printf("5. Xoa dau\n");
        printf("6. Xoa cuoi\n");
        printf("7. Xoa theo gia tri\n");
        printf("8. Sap xep tang dan\n");
        printf("0. Thoat\n");
        printf("Chon: ");
        scanf("%d", &chon);

        switch (chon) {
        case 1:
            printf("Nhap so phan tu: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++) {
                printf("Nhap phan tu %d: ", i + 1);
                scanf("%d", &x);
                insertTail(&head, x);
            }
            break;
        case 2: printForward(head); break;
        case 3: printBackward(head); break;
        case 4:
            printf("Nhap gia tri can tim: ");
            scanf("%d", &x);
            if (search(head, x)) printf("Tim thay!\n");
            else printf("Khong tim thay!\n");
            break;
        case 5: deleteHead(&head); break;
        case 6: deleteTail(&head); break;
        case 7:
            printf("Nhap gia tri can xoa: ");
            scanf("%d", &x);
            deleteValue(&head, x);
            break;
        case 8: sortList(&head); break;
        }
    } while (chon != 0);

    return 0;
}
