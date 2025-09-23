#include <stdio.h>
#include <string.h>

typedef struct {
    int ma;
    char ten[40];
    float dtb;
    int nam;
} SinhVien;

void nhap(SinhVien* sv, int n) {
    for (int i = 0;i < n;i++) {
        printf("\nNhap sinh vien thu %d:\n", i + 1);
        printf("Ma so: "); scanf("%d", &sv[i].ma);
        getchar();
        printf("Ten: "); fgets(sv[i].ten, 40, stdin); sv[i].ten[strcspn(sv[i].ten, "\n")] = 0;
        printf("Diem TB: "); scanf("%f", &sv[i].dtb);
        printf("Nam TN: "); scanf("%d", &sv[i].nam);
    }
}

void xuat(SinhVien* sv, int n) {
    printf("\n%-5s %-15s %-10s %-10s\n", "Ma", "Ten", "Diem TB", "Nam TN");
    for (int i = 0;i < n;i++) {
        printf("%-5d %-15s %-10.2f %-10d\n", sv[i].ma, sv[i].ten, sv[i].dtb, sv[i].nam);
    }
}

void sapxep_ma(SinhVien* sv, int n) {
    for (int i = 0;i < n - 1;i++)
        for (int j = i + 1;j < n;j++)
            if (sv[i].ma > sv[j].ma) {
                SinhVien tmp = sv[i]; sv[i] = sv[j]; sv[j] = tmp;
            }
}

void sapxep_dtb(SinhVien* sv, int n) {
    for (int i = 0;i < n - 1;i++)
        for (int j = i + 1;j < n;j++)
            if (sv[i].dtb < sv[j].dtb) {
                SinhVien tmp = sv[i]; sv[i] = sv[j]; sv[j] = tmp;
            }
}

void sapxep_nam(SinhVien* sv, int n) {
    for (int i = 0;i < n - 1;i++)
        for (int j = i + 1;j < n;j++)
            if (sv[i].nam > sv[j].nam) {
                SinhVien tmp = sv[i]; sv[i] = sv[j]; sv[j] = tmp;
            }
}

int main() {
    #include <stdio.h>
#include <string.h>

typedef struct {
    int ma;
    char ten[40];
    float dtb;
    int nam;
} SinhVien;

void nhap(SinhVien *sv, int n) {
    for (int i=0;i<n;i++) {
        printf("\nNhap sinh vien thu %d:\n", i+1);
        printf("Ma so: "); scanf("%d", &sv[i].ma);
        getchar();
        printf("Ten: "); fgets(sv[i].ten, 40, stdin); sv[i].ten[strcspn(sv[i].ten, "\n")] = 0;
        printf("Diem TB: "); scanf("%f", &sv[i].dtb);
        printf("Nam TN: "); scanf("%d", &sv[i].nam);
    }
}

void xuat(SinhVien *sv, int n) {
    printf("\n%-5s %-15s %-10s %-10s\n", "Ma", "Ten", "Diem TB", "Nam TN");
    for (int i=0;i<n;i++) {
        printf("%-5d %-15s %-10.2f %-10d\n", sv[i].ma, sv[i].ten, sv[i].dtb, sv[i].nam);
    }
}

void sapxep_ma(SinhVien *sv, int n) {
    for (int i=0;i<n-1;i++)
        for (int j=i+1;j<n;j++)
            if (sv[i].ma > sv[j].ma) {
                SinhVien tmp = sv[i]; sv[i] = sv[j]; sv[j] = tmp;
            }
}

void sapxep_dtb(SinhVien *sv, int n) {
    for (int i=0;i<n-1;i++)
        for (int j=i+1;j<n;j++)
            if (sv[i].dtb < sv[j].dtb) {
                SinhVien tmp = sv[i]; sv[i] = sv[j]; sv[j] = tmp;
            }
}

void sapxep_nam(SinhVien *sv, int n) {
    for (int i=0;i<n-1;i++)
        for (int j=i+1;j<n;j++)
            if (sv[i].nam > sv[j].nam) {
                SinhVien tmp = sv[i]; sv[i] = sv[j]; sv[j] = tmp;
            }
}

int main() {
    printf("Nguyen Vo Hoang Phi\n");
    int n;
    printf("Nhap so sinh vien: "); scanf("%d", &n);
    SinhVien ds[n];
    nhap(ds, n);

    printf("\nTang dan theo ma:\n");
    sapxep_ma(ds, n); xuat(ds, n);

    printf("\nGiam dan theo diem TB:\n");
    sapxep_dtb(ds, n); xuat(ds, n);

    printf("\nTang dan theo nam TN:\n");
    sapxep_nam(ds, n); xuat(ds, n);

    return 0;
}

    int n;
    printf("Nhap so sinh vien: "); scanf("%d", &n);
    SinhVien ds[n];
    nhap(ds, n);

    printf("\nTang dan theo ma:\n");
    sapxep_ma(ds, n); xuat(ds, n);

    printf("\nGiam dan theo diem TB:\n");
    sapxep_dtb(ds, n); xuat(ds, n);

    printf("\nTang dan theo nam TN:\n");
    sapxep_nam(ds, n); xuat(ds, n);

    return 0;
}
