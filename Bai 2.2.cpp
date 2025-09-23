#include <stdio.h>
#include <string.h>

typedef struct {
    int ma;
    char ten_chu[40];
    float so_dt;
    int thoigian;
} ThueBao;

void nhap(ThueBao* tb, int n) {
    for (int i = 0;i < n;i++) {
        printf("\nNhap thue bao thu %d:\n", i + 1);
        printf("Ma: "); scanf("%d", &tb[i].ma);
        getchar();
        printf("Ten chu: "); fgets(tb[i].ten_chu, 40, stdin); tb[i].ten_chu[strcspn(tb[i].ten_chu, "\n")] = 0;
        printf("So dien thoai: "); scanf("%f", &tb[i].so_dt);
        printf("Thoi gian goi: "); scanf("%d", &tb[i].thoigian);
    }
}

void xuat(ThueBao* tb, int n) {
    printf("\n%-5s %-15s %-10s %-10s\n", "Ma", "Ten chu", "So DT", "Thoi gian");
    for (int i = 0;i < n;i++) {
        printf("%-5d %-15s %-10.0f %-10d\n", tb[i].ma, tb[i].ten_chu, tb[i].so_dt, tb[i].thoigian);
    }
}

void sapxep_ma(ThueBao* tb, int n) {
    for (int i = 0;i < n - 1;i++)
        for (int j = i + 1;j < n;j++)
            if (tb[i].ma > tb[j].ma) {
                ThueBao tmp = tb[i]; tb[i] = tb[j]; tb[j] = tmp;
            }
}

void sapxep_sodt(ThueBao* tb, int n) {
    for (int i = 0;i < n - 1;i++)
        for (int j = i + 1;j < n;j++)
            if (tb[i].so_dt < tb[j].so_dt) {
                ThueBao tmp = tb[i]; tb[i] = tb[j]; tb[j] = tmp;
            }
}

void sapxep_thoigian(ThueBao* tb, int n) {
    for (int i = 0;i < n - 1;i++)
        for (int j = i + 1;j < n;j++)
            if (tb[i].thoigian > tb[j].thoigian) {
                ThueBao tmp = tb[i]; tb[i] = tb[j]; tb[j] = tmp;
            }
}

int main() {
    printf("Nguyen Vo Hoang Phi\n");
    int n;
    printf("Nhap so thue bao: "); scanf("%d", &n);
    ThueBao ds[n];
    nhap(ds, n);

    printf("\nTang dan theo ma:\n");
    sapxep_ma(ds, n); xuat(ds, n);

    printf("\nGiam dan theo so dien thoai:\n");
    sapxep_sodt(ds, n); xuat(ds, n);

    printf("\nTang dan theo thoi gian:\n");
    sapxep_thoigian(ds, n); xuat(ds, n);

    return 0;
}
