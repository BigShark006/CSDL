#include <stdio.h>
#include <string.h>

typedef struct {
    int ma;
    char nguoi_gui[40];
    char nguoi_nhan[40];
    float trong_luong;
    int don_gia;
} BuuKien;

void nhap(BuuKien* bk, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nNhap buu kien thu %d:\n", i + 1);
        printf("Ma: "); scanf("%d", &bk[i].ma);
        getchar();
        printf("Nguoi gui: "); fgets(bk[i].nguoi_gui, 40, stdin); bk[i].nguoi_gui[strcspn(bk[i].nguoi_gui, "\n")] = 0;
        printf("Nguoi nhan: "); fgets(bk[i].nguoi_nhan, 40, stdin); bk[i].nguoi_nhan[strcspn(bk[i].nguoi_nhan, "\n")] = 0;
        printf("Trong luong: "); scanf("%f", &bk[i].trong_luong);
        printf("Don gia: "); scanf("%d", &bk[i].don_gia);
    }
}

void xuat(BuuKien* bk, int n) {
    printf("\n%-5s %-15s %-15s %-10s %-10s\n", "Ma", "Nguoi gui", "Nguoi nhan", "Trong luong", "Don gia");
    for (int i = 0; i < n; i++) {
        printf("%-5d %-15s %-15s %-10.2f %-10d\n", bk[i].ma, bk[i].nguoi_gui, bk[i].nguoi_nhan, bk[i].trong_luong, bk[i].don_gia);
    }
}

void sapxep_ma(BuuKien* bk, int n) {
    for (int i = 0;i < n - 1;i++)
        for (int j = i + 1;j < n;j++)
            if (bk[i].ma > bk[j].ma) {
                BuuKien tmp = bk[i]; bk[i] = bk[j]; bk[j] = tmp;
            }
}

void sapxep_trongluong(BuuKien* bk, int n) {
    for (int i = 0;i < n - 1;i++)
        for (int j = i + 1;j < n;j++)
            if (bk[i].trong_luong < bk[j].trong_luong) {
                BuuKien tmp = bk[i]; bk[i] = bk[j]; bk[j] = tmp;
            }
}

void sapxep_dongia(BuuKien* bk, int n) {
    for (int i = 0;i < n - 1;i++)
        for (int j = i + 1;j < n;j++)
            if (bk[i].don_gia > bk[j].don_gia) {
                BuuKien tmp = bk[i]; bk[i] = bk[j]; bk[j] = tmp;
            }
}

int main() {
    printf("Nguyen Vo Hoang Phi\n");
    int n;
    printf("Nhap so buu kien: "); scanf("%d", &n);
    BuuKien ds[n];

    nhap(ds, n);

    printf("\nDanh sach tang dan theo ma:\n");
    sapxep_ma(ds, n); xuat(ds, n);

    printf("\nDanh sach giam dan theo trong luong:\n");
    sapxep_trongluong(ds, n); xuat(ds, n);

    printf("\nDanh sach tang dan theo don gia:\n");
    sapxep_dongia(ds, n); xuat(ds, n);

    return 0;
}
