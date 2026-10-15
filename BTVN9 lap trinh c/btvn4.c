
#include <stdio.h>
#include <string.h>

struct HanhKhach {
    char maPNR[15];
    char hoTen[50];
    char hangVe[15];
    float canNangHanhLy;
    float phiHanhLy;
};

int main() {
    struct HanhKhach danhSach[100];
    int soLuong = 0;
    int luaChon, i, viTri;
    int soBusiness;
    float kgMienPhi, kgVuot, tongPhi;
    char pnrCanTim[15];

    do {
        printf("\n=== HE THONG CHECK-IN HANG KHONG ===\n");
        printf("1. Them hanh khach check-in\n");
        printf("2. Hien thi danh sach hanh khach\n");
        printf("3. Cap nhat hanh ly theo ma PNR\n");
        printf("4. Thong ke doanh thu qua cuoc\n");
        printf("5. Thoat\n");
        printf("Lua chon cua ban: ");

        if (scanf("%d", &luaChon) != 1) {
            while (getchar() != '\n');
            luaChon = 0;
        } else {
            while (getchar() != '\n');
        }

        switch (luaChon) {
            case 1:
                if (soLuong >= 100) {
                    printf("Bo nho day, khong the them hanh khach!\n");
                    break;
                }

                printf("Nhap ma PNR: ");
                fgets(danhSach[soLuong].maPNR,
                      sizeof(danhSach[soLuong].maPNR), stdin);
                danhSach[soLuong].maPNR[
                    strcspn(danhSach[soLuong].maPNR, "\n")] = '\0';

                printf("Nhap ho ten: ");
                fgets(danhSach[soLuong].hoTen,
                      sizeof(danhSach[soLuong].hoTen), stdin);
                danhSach[soLuong].hoTen[
                    strcspn(danhSach[soLuong].hoTen, "\n")] = '\0';

                do {
                    printf("Nhap hang ve (Business/Deluxe/Eco): ");
                    fgets(danhSach[soLuong].hangVe,
                          sizeof(danhSach[soLuong].hangVe), stdin);
                    danhSach[soLuong].hangVe[
                        strcspn(danhSach[soLuong].hangVe, "\n")] = '\0';

                    if (strcmp(danhSach[soLuong].hangVe, "Business") != 0 &&
                        strcmp(danhSach[soLuong].hangVe, "Deluxe") != 0 &&
                        strcmp(danhSach[soLuong].hangVe, "Eco") != 0) {
                        printf("Hang ve khong hop le! Vui long nhap lai.\n");
                    }
                } while (strcmp(danhSach[soLuong].hangVe, "Business") != 0 &&
                         strcmp(danhSach[soLuong].hangVe, "Deluxe") != 0 &&
                         strcmp(danhSach[soLuong].hangVe, "Eco") != 0);

                do {
                    printf("Nhap so kg hanh ly ky gui: ");

                    if (scanf("%f", &danhSach[soLuong].canNangHanhLy) != 1) {
                        while (getchar() != '\n');
                        danhSach[soLuong].canNangHanhLy = -1;
                    } else {
                        while (getchar() != '\n');
                    }

                    if (danhSach[soLuong].canNangHanhLy < 0) {
                        printf("Can nang khong hop le! Vui long nhap lai.\n");
                    }
                } while (danhSach[soLuong].canNangHanhLy < 0);

                if (strcmp(danhSach[soLuong].hangVe, "Business") == 0) {
                    kgMienPhi = 30.0;
                } else if (strcmp(danhSach[soLuong].hangVe, "Deluxe") == 0) {
                    kgMienPhi = 20.0;
                } else {
                    kgMienPhi = 0.0;
                }

                if (danhSach[soLuong].canNangHanhLy > kgMienPhi) {
                    kgVuot = danhSach[soLuong].canNangHanhLy - kgMienPhi;
                } else {
                    kgVuot = 0.0;
                }

                danhSach[soLuong].phiHanhLy = kgVuot * 50000.0;

                printf("Them hanh khach thanh cong! Phi hanh ly qua cuoc: %.0f VND\n",
                       danhSach[soLuong].phiHanhLy);

                soLuong++;
                break;

            case 2:
                if (soLuong == 0) {
                    printf("Danh sach hanh khach hien dang rong!\n");
                    break;
                }

                tongPhi = 0;

                printf("\n====================================================================================================\n");
                printf("%-5s %-10s %-25s %-12s %-14s %-18s\n",
                       "STT", "Ma PNR", "Ho va Ten", "Hang ve",
                       "Can nang (kg)", "Phi hanh ly (VND)");
                printf("====================================================================================================\n");

                for (i = 0; i < soLuong; i++) {
                    printf("%-5d %-10s %-25s %-12s %-14.1f %-18.0f\n",
                           i + 1,
                           danhSach[i].maPNR,
                           danhSach[i].hoTen,
                           danhSach[i].hangVe,
                           danhSach[i].canNangHanhLy,
                           danhSach[i].phiHanhLy);

                    tongPhi += danhSach[i].phiHanhLy;
                }

                printf("====================================================================================================\n");
                printf("Tong tien phi hanh ly: %.0f VND\n", tongPhi);
                break;

            case 3:
                if (soLuong == 0) {
                    printf("Danh sach hanh khach hien dang rong!\n");
                    break;
                }

                printf("Nhap ma PNR can cap nhat: ");
                fgets(pnrCanTim, sizeof(pnrCanTim), stdin);
                pnrCanTim[strcspn(pnrCanTim, "\n")] = '\0';

                viTri = -1;

                for (i = 0; i < soLuong; i++) {
                    if (strcmp(danhSach[i].maPNR, pnrCanTim) == 0) {
                        viTri = i;
                        break;
                    }
                }

                if (viTri == -1) {
                    printf("Ma PNR khong ton tai trong he thong!\n");
                } else {
                    printf("Tim thay hanh khach: %s\n",
                           danhSach[viTri].hoTen);

                    do {
                        printf("Nhap so kg hanh ly ky gui moi: ");

                        if (scanf("%f", &danhSach[viTri].canNangHanhLy) != 1) {
                            while (getchar() != '\n');
                            danhSach[viTri].canNangHanhLy = -1;
                        } else {
                            while (getchar() != '\n');
                        }

                        if (danhSach[viTri].canNangHanhLy < 0) {
                            printf("Can nang khong hop le! Vui long nhap lai.\n");
                        }
                    } while (danhSach[viTri].canNangHanhLy < 0);

                    if (strcmp(danhSach[viTri].hangVe, "Business") == 0) {
                        kgMienPhi = 30.0;
                    } else if (strcmp(danhSach[viTri].hangVe, "Deluxe") == 0) {
                        kgMienPhi = 20.0;
                    } else {
                        kgMienPhi = 0.0;
                    }

                    if (danhSach[viTri].canNangHanhLy > kgMienPhi) {
                        kgVuot = danhSach[viTri].canNangHanhLy - kgMienPhi;
                    } else {
                        kgVuot = 0.0;
                    }

                    danhSach[viTri].phiHanhLy = kgVuot * 50000.0;

                    printf("Cap nhat thanh cong! Phi hanh ly moi: %.0f VND\n",
                           danhSach[viTri].phiHanhLy);
                }
                break;

            case 4:
                if (soLuong == 0) {
                    printf("Danh sach hanh khach hien dang rong!\n");
                    break;
                }

                soBusiness = 0;
                tongPhi = 0;

                for (i = 0; i < soLuong; i++) {
                    if (strcmp(danhSach[i].hangVe, "Business") == 0) {
                        soBusiness++;
                    }

                    tongPhi += danhSach[i].phiHanhLy;
                }

                printf("\n=== THONG KE DOANH THU QUA CUOC ===\n");
                printf("So hanh khach hang Business: %d\n", soBusiness);
                printf("Tong doanh thu phi hanh ly qua cuoc: %.0f VND\n",
                       tongPhi);
                break;

            case 5:
                printf("Cam on ban da su dung chuong trinh!\n");
                break;

            default:
                printf("Lua chon khong hop le! Vui long chon tu 1 den 5.\n");
        }

    } while (luaChon != 5);

    return 0;
}

