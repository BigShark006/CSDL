// a. Xóa 1 SV sau SV có mã X
void xoaSauMaX(char ma[]) {
    Node* p = timSV(ma);
    if(p == NULL || p->next == NULL) {
        printf("Khong xoa duoc!\n");
        return;
    }
    Node* q = p->next;
    p->next = q->next;
    free(q);
}

// b. Xóa tất cả SV có tên là X
void xoaTatCaTheoTen(char ten[]) {
    while(head != NULL && strcmp(head->data.tenSV, ten)==0) {
        Node* tmp = head;
        head = head->next;
        free(tmp);
    }
    Node* p = head;
    while(p != NULL && p->next != NULL) {
        if(strcmp(p->next->data.tenSV, ten)==0) {
            Node* tmp = p->next;
            p->next = tmp->next;
            free(tmp);
        } else p = p->next;
    }
}

// c. Sắp xếp DSSV tăng dần theo mã SV
void sapXepTheoMaSV() {
    for(Node* i=head;i!=NULL;i=i->next){
        for(Node* j=i->next;j!=NULL;j=j->next){
            if(strcmp(i->data.maSV, j->data.maSV) > 0){
                SinhVien tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
    printf("Da sap xep theo ma SV!\n");
}

// d. In danh sách SV xếp loại khá (6.5 <= DTB < 8)
void inSVKha() {
    Node* p = head;
    printf("\n===== DANH SACH SV LOAI KHA =====\n");
    while(p != NULL) {
        if(p->data.diemTB >= 6.5 && p->data.diemTB < 8)
            printf("%-10s | %-30s | %.2f\n",
                   p->data.maSV, p->data.tenSV, p->data.diemTB);
        p = p->next;
    }
}

// e. Cho biết SV có điểm TB cao nhất, thấp nhất
void svMaxMin() {
    if(head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    Node* p = head;
    Node* svMax = head;
    Node* svMin = head;
    while(p != NULL) {
        if(p->data.diemTB > svMax->data.diemTB) svMax = p;
        if(p->data.diemTB < svMin->data.diemTB) svMin = p;
        p = p->next;
    }
    printf("\nSV diem cao nhat: %s - %s - %.2f\n",
           svMax->data.maSV, svMax->data.tenSV, svMax->data.diemTB);
    printf("SV diem thap nhat: %s - %s - %.2f\n",
           svMin->data.maSV, svMin->data.tenSV, svMin->data.diemTB);
}


\\\_________________________///


printf("11. Xoa 1 SV sau SV co ma X\n");
printf("12. Xoa tat ca SV co ten la X\n");
printf("13. Sap xep DSSV tang dan theo ma SV\n");
printf("14. In danh sach SV xep loai kha\n");
printf("15. Tim SV co diem TB cao nhat, thap nhat\n");


\\\__________________________///


case 11:
    printf("Nhap ma SV X: ");
    fflush(stdin); gets(ma);
    xoaSauMaX(ma);
    break;
case 12: {
    char ten[40];
    printf("Nhap ten SV X: ");
    fflush(stdin); gets(ten);
    xoaTatCaTheoTen(ten);
    break;
}
case 13: sapXepTheoMaSV(); break;
case 14: inSVKha(); break;
case 15: svMaxMin(); break;
