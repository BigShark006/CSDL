#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char maSV[10];
    char tenSV[40];
    float diemTB;
} SinhVien;

typedef struct Node {
    SinhVien data;
    struct Node* next;
} Node;

Node* createNode(SinhVien sv) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = sv;
    p->next = NULL;
    return p;
}

void nhapSV(SinhVien* sv) {
    printf("Nhap ma SV: ");
    scanf("%s", sv->maSV);
    getchar();
    printf("Nhap ten SV: ");
    fgets(sv->tenSV, sizeof(sv->tenSV), stdin);
    sv->tenSV[strcspn(sv->tenSV, "\n")] = '\0';
    printf("Nhap diem TB: ");
    scanf("%f", &sv->diemTB);
}

void themCuoi(Node** head, SinhVien sv) {
    Node* p = createNode(sv);
    if (*head == NULL) *head = p;
    else {
        Node* q = *head;
        while (q->next != NULL) q = q->next;
        q->next = p;
    }
}

void xuatDS(Node* head) {
    Node* p = head;
    while (p != NULL) {
        printf("%-10s %-20s %.2f\n", p->data.maSV, p->data.tenSV, p->data.diemTB);
        p = p->next;
    }
}

void xuatDSTB5(Node* head) {
    Node* p = head;
    while (p != NULL) {
        if (p->data.diemTB > 5)
            printf("%-10s %-20s %.2f\n", p->data.maSV, p->data.tenSV, p->data.diemTB);
        p = p->next;
    }
}

Node* timSV(Node* head, char* ma) {
    Node* p = head;
    while (p != NULL) {
        if (strcmp(p->data.maSV, ma) == 0) return p;
        p = p->next;
    }
    return NULL;
}

void sapXep(Node** head) {
    for (Node* i = *head; i != NULL; i = i->next) {
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (i->data.diemTB > j->data.diemTB) {
                SinhVien temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void themSauMa(Node** head, const char* maX, SinhVien sv) {
    if (*head == NULL) {
        printf("Danh sach rong. Khong tim thay ma %s.\n", maX);
        return;
    }
    Node* p = *head;
    while (p != NULL && strcmp(p->data.maSV, maX) != 0) {
        p = p->next;
    }
    if (p == NULL) {
        printf("Khong tim thay sinh vien co ma %s. Khong the them.\n", maX);
        return;
    }
    Node* q = createNode(sv);
    q->next = p->next;
    p->next = q;
    printf("Da them SV %s sau ma %s.\n", sv.maSV, maX);
}

void xoaDau(Node** head) {
    if (*head == NULL) return;
    Node* p = *head;
    *head = (*head)->next;
    free(p);
}

void xoaCuoi(Node** head) {
    if (*head == NULL) return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    Node* p = *head;
    while (p->next->next != NULL) p = p->next;
    free(p->next);
    p->next = NULL;
}

void xoaAll(Node** head) {
    Node* p;
    while (*head != NULL) {
        p = *head;
        *head = (*head)->next;
        free(p);
    }
}

void xoaTheoMa(Node** head, char* ma) {
    Node* p = *head, * prev = NULL;
    while (p != NULL) {
        if (strcmp(p->data.maSV, ma) == 0) {
            if (prev == NULL) *head = p->next;
            else prev->next = p->next;
            free(p);
            return;
        }
        prev = p;
        p = p->next;
    }
}

int main() {
    printf("Nguyen Vo Hoang Phi\n");
    Node* head = NULL;
    int n, chon;
    char ma[10];
    SinhVien sv;

    do {
        printf("\n----- MENU -----\n");
        printf("1. Nhap danh sach SV\n");
        printf("2. Xuat danh sach SV\n");
        printf("3. Xuat SV co DTB > 5\n");
        printf("4. Tim SV theo ma\n");
        printf("5. Sap xep tang theo DTB\n");
        printf("6. Them SV vao sau SV\n");
        printf("7. Xoa dau\n");
        printf("8. Xoa cuoi\n");
        printf("9. Xoa tat ca\n");
        printf("10. Xoa SV theo ma\n");
        printf("0. Thoat\n");
        printf("Chon: ");
        scanf("%d", &chon);
        getchar();

        switch (chon) {
        case 1:
            printf("Nhap so SV: ");
            scanf("%d", &n);
            getchar();
            for (int i = 0; i < n; i++) {
                printf("\nNhap SV thu %d:\n", i + 1);
                nhapSV(&sv);
                themCuoi(&head, sv);
            }
            break;
        case 2: xuatDS(head); break;
        case 3: xuatDSTB5(head); break;
        case 4:
            printf("Nhap ma SV: ");
            scanf("%s", ma);
            if (timSV(head, ma)) printf("Tim thay!\n");
            else printf("Khong thay!\n");
            break;
        case 5: sapXep(&head); break;
        case 6:
            printf("Nhap ma SV X: "); scanf("%s", ma);
            getchar();              
            printf("Nhap thong tin SV can them:\n"); nhapSV(&sv);           
            themSauMa(&head, ma, sv);
            break;
        case 7: xoaDau(&head); break;
        case 8: xoaCuoi(&head); break;
        case 9: xoaAll(&head); break;
        case 10:
            printf("Nhap ma SV: ");
            scanf("%s", ma);
            xoaTheoMa(&head, ma);
            break;
        }
    } while (chon != 0);

    xoaAll(&head);
    return 0;
}

