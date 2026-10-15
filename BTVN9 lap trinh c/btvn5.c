#include <stdio.h>
#include <string.h>

struct VeMayBay {
    char maDatCho[10];
    char tenHanhKhach[50];
    int hangVe;
    float khoiLuongHanhLy;
    double tongTienVe;
};

int main() {
    struct VeMayBay danhSachVe[100];
    int soLuong = 0;
    int luaChon, i, j, viTri;
    int hangVeMoi;
    int trungPNR;
    int viTriMax;
    float khoiLuongMoi;
    double giaVe, phuPhi, tongDoanhThu;
    char maPNR[10];
    char hangVeText[12];

    do {
        printf("\n================ HE THONG QUAN LY VE MAY BAY ================\n");
        printf("1. Them moi ve may bay (Create)\n");
        printf("2. Hien thi danh sach ve may bay (Read)\n");
        printf("3. Cap nhat hang ve va hanh ly theo ma PNR (Update)\n");
        printf("4. Huy / Xoa ve may bay theo ma PNR (Delete)\n");
        printf("5. Thong ke tong doanh thu va ve co tien cao nhat\n");
        printf("6. Thoat chuong trinh\n");
        printf("=============================================================\n");
        printf("Lua chon cua ban (1-6): ");

        if (scanf("%d", &luaChon) != 1) {
            while (getchar() != '\n' && !feof(stdin));
            luaChon = 0;
        } else {
            while (getchar() != '\n' && !feof(stdin));
        }

        switch (luaChon) {
            case 1:
                printf("\n--- THEM MOI VE MAY BAY ---\n");

                if (soLuong >= 100) {
                    printf("LOI: Danh sach ve da den gioi han toi da (100)!\n");
                    break;
                }

                printf("Nhap ma PNR dat cho: ");
                scanf("%9s", maPNR);
                while (getchar() != '\n' && !feof(stdin));

                trungPNR = 0;

                for (i = 0; i < soLuong; i++) {
                    if (strcmp(danhSachVe[i].maDatCho, maPNR) == 0) {
                        trungPNR = 1;
                        break;
                    }
                }

                if (trungPNR == 1) {
                    printf("LOI: Ma PNR %s da ton tai trong he thong!\n", maPNR);
                    break;
                }

                strcpy(danhSachVe[soLuong].maDatCho, maPNR);

                printf("Nhap ho ten hanh khach: ");
                fgets(danhSachVe[soLuong].tenHanhKhach,
                      sizeof(danhSachVe[soLuong].tenHanhKhach), stdin);
                danhSachVe[soLuong].tenHanhKhach[
                    strcspn(danhSachVe[soLuong].tenHanhKhach, "\n")] = '\0';

                do {
                    printf("Nhap hang ve (1-Eco, 2-Deluxe, 3-Business): ");

                    if (scanf("%d", &danhSachVe[soLuong].hangVe) != 1) {
                        while (getchar() != '\n' && !feof(stdin));
                        danhSachVe[soLuong].hangVe = 0;
                    } else {
                        while (getchar() != '\n' && !feof(stdin));
                    }

                    if (danhSachVe[soLuong].hangVe < 1 ||
                        danhSachVe[soLuong].hangVe > 3) {
                        printf("LOI: Hang ve khong hop le! Vui long nhap tu 1 den 3.\n");
                    }
                } while (danhSachVe[soLuong].hangVe < 1 ||
                         danhSachVe[soLuong].hangVe > 3);

                do {
                    printf("Nhap khoi luong hanh ly ky gui (kg): ");

                    if (scanf("%f", &danhSachVe[soLuong].khoiLuongHanhLy) != 1) {
                        while (getchar() != '\n' && !feof(stdin));
                        danhSachVe[soLuong].khoiLuongHanhLy = -1;
                    } else {
                        while (getchar() != '\n' && !feof(stdin));
                    }

                    if (danhSachVe[soLuong].khoiLuongHanhLy < 0) {
                        printf("LOI: Khoi luong hanh ly phai lon hon hoac bang 0!\n");
                    }
                } while (danhSachVe[soLuong].khoiLuongHanhLy < 0);

                if (danhSachVe[soLuong].hangVe == 1) {
                    giaVe = 1200000;
                    if (danhSachVe[soLuong].khoiLuongHanhLy > 7.0) {
                        phuPhi = (danhSachVe[soLuong].khoiLuongHanhLy - 7.0) * 50000;
                    } else {
                        phuPhi = 0;
                    }
                } else if (danhSachVe[soLuong].hangVe == 2) {
                    giaVe = 2500000;
                    if (danhSachVe[soLuong].khoiLuongHanhLy > 7.0) {
                        phuPhi = (danhSachVe[soLuong].khoiLuongHanhLy - 7.0) * 50000;
                    } else {
                        phuPhi = 0;
                    }
                } else {
                    giaVe = 5000000;
                    phuPhi = 0;
                }

                danhSachVe[soLuong].tongTienVe = giaVe + phuPhi;

                printf("--> Them moi ve may bay thanh cong! Tong tien ve: %.0lf VND.\n",
                       danhSachVe[soLuong].tongTienVe);

                soLuong++;
                break;

            case 2:
                printf("\n--- DANH SACH VE MAY BAY ---\n");

                if (soLuong == 0) {
                    printf("Hien tai chua co ve may bay nao trong he thong.\n");
                    break;
                }

                printf("------------------------------------------------------------------------------------------------\n");
                printf("%-10s %-22s %-12s %12s %18s\n",
                       "Ma PNR", "Ho Ten Hanh Khach", "Hang Ve",
                       "Hanh Ly (kg)", "Tong Tien (VND)");
                printf("------------------------------------------------------------------------------------------------\n");

                for (i = 0; i < soLuong; i++) {
                    if (danhSachVe[i].hangVe == 1) {
                        strcpy(hangVeText, "Eco");
                    } else if (danhSachVe[i].hangVe == 2) {
                        strcpy(hangVeText, "Deluxe");
                    } else {
                        strcpy(hangVeText, "Business");
                    }

                    printf("%-10s %-22s %-12s %12.1f %18.0lf\n",
                           danhSachVe[i].maDatCho,
                           danhSachVe[i].tenHanhKhach,
                           hangVeText,
                           danhSachVe[i].khoiLuongHanhLy,
                           danhSachVe[i].tongTienVe);
                }

                printf("------------------------------------------------------------------------------------------------\n");
                break;

            case 3:
                printf("\n--- CAP NHAT VE MAY BAY ---\n");

                if (soLuong == 0) {
                    printf("Hien tai chua co ve may bay nao trong he thong.\n");
                    break;
                }

                printf("Nhap ma PNR can cap nhat: ");
                scanf("%9s", maPNR);
                while (getchar() != '\n' && !feof(stdin));

                viTri = -1;

                for (i = 0; i < soLuong; i++) {
                    if (strcmp(danhSachVe[i].maDatCho, maPNR) == 0) {
                        viTri = i;
                        break;
                    }
                }

                if (viTri == -1) {
                    printf("LOI: Khong tim thay ve may bay co ma PNR %s!\n", maPNR);
                    break;
                }

                do {
                    printf("Nhap hang ve moi (1-Eco, 2-Deluxe, 3-Business): ");

                    if (scanf("%d", &hangVeMoi) != 1) {
                        while (getchar() != '\n' && !feof(stdin));
                        hangVeMoi = 0;
                    } else {
                        while (getchar() != '\n' && !feof(stdin));
                    }

                    if (hangVeMoi < 1 || hangVeMoi > 3) {
                        printf("LOI: Hang ve khong hop le! Vui long nhap tu 1 den 3.\n");
                    }
                } while (hangVeMoi < 1 || hangVeMoi > 3);

                do {
                    printf("Nhap khoi luong hanh ly moi (kg): ");

                    if (scanf("%f", &khoiLuongMoi) != 1) {
                        while (getchar() != '\n' && !feof(stdin));
                        khoiLuongMoi = -1;
                    } else {
                        while (getchar() != '\n' && !feof(stdin));
                    }

                    if (khoiLuongMoi < 0) {
                        printf("LOI: Khoi luong hanh ly phai lon hon hoac bang 0!\n");
                    }
                } while (khoiLuongMoi < 0);

                danhSachVe[viTri].hangVe = hangVeMoi;
                danhSachVe[viTri].khoiLuongHanhLy = khoiLuongMoi;

                if (hangVeMoi == 1) {
                    giaVe = 1200000;
                    if (khoiLuongMoi > 7.0) {
                        phuPhi = (khoiLuongMoi - 7.0) * 50000;
                    } else {
                        phuPhi = 0;
                    }
                } else if (hangVeMoi == 2) {
                    giaVe = 2500000;
                    if (khoiLuongMoi > 7.0) {
                        phuPhi = (khoiLuongMoi - 7.0) * 50000;
                    } else {
                        phuPhi = 0;
                    }
                } else {
                    giaVe = 5000000;
                    phuPhi = 0;
                }

                danhSachVe[viTri].tongTienVe = giaVe + phuPhi;

                printf("--> Cap nhat ve %s thanh cong! Tong tien ve moi: %.0lf VND.\n",
                       maPNR, danhSachVe[viTri].tongTienVe);
                break;

            case 4:
                printf("\n--- HUY / XOA VE MAY BAY ---\n");

                if (soLuong == 0) {
                    printf("Hien tai chua co ve may bay nao trong he thong.\n");
                    break;
                }

                printf("Nhap ma PNR can huy xoa: ");
                scanf("%9s", maPNR);
                while (getchar() != '\n' && !feof(stdin));

                viTri = -1;

                for (i = 0; i < soLuong; i++) {
                    if (strcmp(danhSachVe[i].maDatCho, maPNR) == 0) {
                        viTri = i;
                        break;
                    }
                }

                if (viTri == -1) {
                    printf("LOI: Khong tim thay ve may bay co ma PNR %s!\n", maPNR);
                } else {
                    for (j = viTri; j < soLuong - 1; j++) {
                        danhSachVe[j] = danhSachVe[j + 1];
                    }

                    soLuong--;

                    printf("Da huy va xoa ve %s thanh cong!\n", maPNR);
                }
                break;

            case 5:
                printf("\n--- THONG KE FINTECH & DOANH THU ---\n");

                if (soLuong == 0) {
                    printf("Hien tai chua co ve may bay nao trong he thong.\n");
                    break;
                }

                tongDoanhThu = 0;
                viTriMax = 0;

                for (i = 0; i < soLuong; i++) {
                    tongDoanhThu += danhSachVe[i].tongTienVe;

                    if (danhSachVe[i].tongTienVe >
                        danhSachVe[viTriMax].tongTienVe) {
                        viTriMax = i;
                    }
                }

                printf("Tong doanh thu cac ve hien tai: %.0lf VND\n",
                       tongDoanhThu);
                printf("Thong tin ve co tong tien cao nhat:\n");
                printf("- Ma PNR: %s\n", danhSachVe[viTriMax].maDatCho);
                printf("- Hanh khach: %s\n", danhSachVe[viTriMax].tenHanhKhach);
                printf("- Tong tien: %.0lf VND\n",
                       danhSachVe[viTriMax].tongTienVe);
                break;

            case 6:
                printf("Cam on ban da su dung chuong trinh!\n");
                break;

            default:
                printf("Lua chon khong hop le! Vui long chon tu 1 den 6.\n");
        }

    } while (luaChon != 6);

    return 0;
}

