#include <stdio.h>
#include <string.h>

struct NhaSach {
    int maSach;
    char tenSach[50];
    int soLuong;
    float giaBan;
};

struct NhaSach ds[50];  
int n = 0;              

int timTheoMa(int ma) {
    for (int i = 0; i < n; i++) {
        if (ds[i].maSach == ma) {
            return i;
        }
    }
    return -1;
}


void nhapTenSach(char ten[]) {
    printf("Nhap ten sach: ");
    fgets(ten, 50, stdin);
    int len = strlen(ten);
    if (len > 0 && ten[len - 1] == '\n') {
        ten[len - 1] = '\0'; 
    }
}


int nhapSoLuong() {
    int sl;
    printf("Nhap so luong: ");
    scanf("%d", &sl);
    while (sl < 0) {
        printf("So luong khong hop le , nhap lai: ");
        scanf("%d", &sl);
    }
    return sl;
}



float nhapGiaBan() {
    float gb;
    printf("Nhap gia ban: ");
    scanf("%f", &gb);
    while (gb < 0) {
        printf("Gia ban, nhap lai: ");
        scanf("%f", &gb);
    }
    return gb;
}



void themSach() {
    int ma;

    if (n == 50) {
        printf("Danh sach da day\n");
        return;
    }

    printf("Nhap ma sach: ");
    scanf("%d", &ma);

    if (ma <= 0) {
        printf("Ma sach khong hop le\n");
        return;
    }
    if (timTheoMa(ma) != -1) {
        printf("Ma sach da ton tai\n");
        return;
    }

    getchar(); 

    ds[n].maSach = ma;
    nhapTenSach(ds[n].tenSach);
    ds[n].soLuong = nhapSoLuong();
    ds[n].giaBan = nhapGiaBan();
    n++;      

    printf("Them sach thanh cong\n");
}


void hienThiDanhSach() {

    if (n == 0) {
        printf("Danh sach rong\n");
        return;
    }

    printf("%-6s %-25s %-10s %-8s %-10s\n", "Ma", "Ten Sach", "So Luong", "Gia Ban");
    for (int i = 0; i < n; i++) {
        printf("%-6d %-25s %-10d %-8.2f %-10s\n",
               ds[i].maSach, ds[i].tenSach, ds[i].soLuong, ds[i].giaBan);
    }
}



void capNhatSach() {
    int ma;

    if (n == 0) {
        printf("Danh sach rong\n");
        return;
    }

    printf("Nhap ma sach can sua: ");
    scanf("%d", &ma);

    int vt = timTheoMa(ma);
    if (vt == -1) {
        printf("Khong tim thay sach\n");
        return;
    }

    getchar();

    nhapTenSach(ds[vt].tenSach);         
    ds[vt].soLuong = nhapSoLuong();
    ds[vt].giaBan = nhapGiaBan();

    printf("Cap nhat thanh cong\n");
}


void xoaSach() {
    int ma;

    if (n == 0) {
        printf("Danh sach rong\n");
        return;
    }

    printf("Nhap ma sach can xoa: ");
    scanf("%d", &ma);

    int vt = timTheoMa(ma);
    if (vt == -1) {
        printf("Khong tim thay sach\n");
        return;
    }

    for (int i = vt; i < n - 1; i++) {
        ds[i] = ds[i + 1];
    }
    n--;

    printf("Xoa thanh cong\n");
}

int main() {
    int choice;
    do {
        printf("\n===== QUAN LY SACH =====\n");
        printf("1. Them sach\n");
        printf("2. Hien thi danh sach\n");
        printf("3. Cap nhat sach theo ma\n");
        printf("4. Xoa sach theo ma\n");
        printf("5. Tim dau sach theo ten\n");
        printf("6. Thong ke kho hang\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

		switch (choice){
			case 1: {
				themSach();
				break;
			}
			case 2: {
				hienThiDanhSach();
				break;
			}
			case 3: {
				capNhatSach();
				break;
			}
			case 4: {
				xoaSach();
				break;
			}
			case 0:{
				printf("Thoat chuong trinh");
				break;
			}
			default:{
				printf("Lua chon khong hop le!\n");
				break;
			}
		}


    } while (choice != 0);

    return 0;
}