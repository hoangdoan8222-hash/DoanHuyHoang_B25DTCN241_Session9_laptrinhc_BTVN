
#include <stdio.h>
#include <string.h>

#define MAX_VE 100

struct VeMayBay {
    char maVe[16];
    char tenHanhKhach[51];
    char hangVe[20];
    float canNangHanhLy;
    double cuocHanhLy;
};

int main() {
    struct VeMayBay danhSachVe[MAX_VE];
    int soLuong, i, viTri, viTriNangNhat;
    char maCanTim[16];
    double tongCuoc = 0;
    float canNangMoi;

    printf("Nhap so luong ve may bay: ");
    if (scanf("%d", &soLuong) != 1) {
        while (getchar() != '\n');
        printf("So luong ve khong hop le!\n");
        return 0;
    }
    while (getchar() != '\n');

    if (soLuong < 1 || soLuong > MAX_VE) {
        printf("So luong ve phai tu 1 den 100!\n");
        return 0;
    }

    for (i = 0; i < soLuong; i++) {
        printf("\n--- Nhap thong tin ve thu %d ---\n", i + 1);

        printf("Ma ve PNR: ");
        fgets(danhSachVe[i].maVe, sizeof(danhSachVe[i].maVe), stdin);
        danhSachVe[i].maVe[strcspn(danhSachVe[i].maVe, "\n")] = '\0';

        printf("Ho ten hanh khach: ");
        fgets(danhSachVe[i].tenHanhKhach,
              sizeof(danhSachVe[i].tenHanhKhach), stdin);
        danhSachVe[i].tenHanhKhach[
            strcspn(danhSachVe[i].tenHanhKhach, "\n")] = '\0';

        do {
            printf("Hang ve (Business/Deluxe/Eco): ");
            fgets(danhSachVe[i].hangVe,
                  sizeof(danhSachVe[i].hangVe), stdin);
            danhSachVe[i].hangVe[
                strcspn(danhSachVe[i].hangVe, "\n")] = '\0';

            if (strcmp(danhSachVe[i].hangVe, "Business") != 0 &&
                strcmp(danhSachVe[i].hangVe, "Deluxe") != 0 &&
                strcmp(danhSachVe[i].hangVe, "Eco") != 0) {
                printf("Hang ve khong hop le! Vui long nhap lai.\n");
            }
        } while (strcmp(danhSachVe[i].hangVe, "Business") != 0 &&
                 strcmp(danhSachVe[i].hangVe, "Deluxe") != 0 &&
                 strcmp(danhSachVe[i].hangVe, "Eco") != 0);

        do {
            printf("Khoi luong hanh ly ky gui (kg): ");

            if (scanf("%f", &danhSachVe[i].canNangHanhLy) != 1) {
                while (getchar() != '\n');
                danhSachVe[i].canNangHanhLy = -1;
            } else {
                while (getchar() != '\n');
            }

            if (danhSachVe[i].canNangHanhLy < 0) {
                printf("Can nang khong hop le! Vui long nhap lai.\n");
            }
        } while (danhSachVe[i].canNangHanhLy < 0);

        if (strcmp(danhSachVe[i].hangVe, "Business") == 0) {
            if (danhSachVe[i].canNangHanhLy <= 20) {
                danhSachVe[i].cuocHanhLy = 0;
            } else {
                danhSachVe[i].cuocHanhLy =
                    (danhSachVe[i].canNangHanhLy - 20) * 50000;
            }
        } else {
            danhSachVe[i].cuocHanhLy =
                danhSachVe[i].canNangHanhLy * 50000;
        }

        tongCuoc += danhSachVe[i].cuocHanhLy;
    }

    viTriNangNhat = 0;

    for (i = 1; i < soLuong; i++) {
        if (danhSachVe[i].canNangHanhLy >
            danhSachVe[viTriNangNhat].canNangHanhLy) {
            viTriNangNhat = i;
        }
    }

    printf("\n================ DANH SACH VE MAY BAY CHUYEN BAY ================\n");
    printf("%-5s %-12s %-25s %-12s %12s %15s\n",
           "STT", "MA VE", "HO TEN HANH KHACH", "HANG VE",
           "HANH LY (KG)", "CUOC PHI (VND)");
    printf("-------------------------------------------------------------------------------\n");

    for (i = 0; i < soLuong; i++) {
        printf("%-5d %-12s %-25s %-12s %12.1f %15.0f\n",
               i + 1,
               danhSachVe[i].maVe,
               danhSachVe[i].tenHanhKhach,
               danhSachVe[i].hangVe,
               danhSachVe[i].canNangHanhLy,
               danhSachVe[i].cuocHanhLy);
    }

    printf("-------------------------------------------------------------------------------\n");
    printf("Tong tien cuoc hanh ly toan chuyen: %.0f VND\n", tongCuoc);

    printf("Ve co hanh ly ky gui nang nhat: %s - %s (%.1f kg)\n",
           danhSachVe[viTriNangNhat].maVe,
           danhSachVe[viTriNangNhat].tenHanhKhach,
           danhSachVe[viTriNangNhat].canNangHanhLy);

    printf("\n--- CAP NHAT THONG TIN HANH LY ---\n");
    printf("Nhap ma ve PNR can cap nhat hanh ly: ");
    fgets(maCanTim, sizeof(maCanTim), stdin);
    maCanTim[strcspn(maCanTim, "\n")] = '\0';

    viTri = -1;

    for (i = 0; i < soLuong; i++) {
        if (strcmp(danhSachVe[i].maVe, maCanTim) == 0) {
            viTri = i;
            break;
        }
    }

    if (viTri == -1) {
        printf("Khong tim thay ma ve PNR nay trong he thong!\n");
    } else {
        do {
            printf("Nhap can nang hanh ly ky gui moi (kg): ");

            if (scanf("%f", &canNangMoi) != 1) {
                while (getchar() != '\n');
                canNangMoi = -1;
            } else {
                while (getchar() != '\n');
            }

            if (canNangMoi < 0) {
                printf("Can nang khong hop le! Vui long nhap lai.\n");
            }
        } while (canNangMoi < 0);

        danhSachVe[viTri].canNangHanhLy = canNangMoi;

        if (strcmp(danhSachVe[viTri].hangVe, "Business") == 0) {
            if (canNangMoi <= 20) {
                danhSachVe[viTri].cuocHanhLy = 0;
            } else {
                danhSachVe[viTri].cuocHanhLy =
                    (canNangMoi - 20) * 50000;
            }
        } else {
            danhSachVe[viTri].cuocHanhLy = canNangMoi * 50000;
        }

        printf("Tim thay ma ve %s. Da cap nhat cuoc hanh ly moi: %.0f VND\n",
               danhSachVe[viTri].maVe,
               danhSachVe[viTri].cuocHanhLy);

        tongCuoc = 0;

        for (i = 0; i < soLuong; i++) {
            tongCuoc += danhSachVe[i].cuocHanhLy;
        }

        viTriNangNhat = 0;

        for (i = 1; i < soLuong; i++) {
            if (danhSachVe[i].canNangHanhLy >
                danhSachVe[viTriNangNhat].canNangHanhLy) {
                viTriNangNhat = i;
            }
        }

        printf("\n================ DANH SACH VE MAY BAY SAU CAP NHAT ================\n");
        printf("%-5s %-12s %-25s %-12s %12s %15s\n",
               "STT", "MA VE", "HO TEN HANH KHACH", "HANG VE",
               "HANH LY (KG)", "CUOC PHI (VND)");
        printf("-------------------------------------------------------------------------------\n");

        for (i = 0; i < soLuong; i++) {
            printf("%-5d %-12s %-25s %-12s %12.1f %15.0f\n",
                   i + 1,
                   danhSachVe[i].maVe,
                   danhSachVe[i].tenHanhKhach,
                   danhSachVe[i].hangVe,
                   danhSachVe[i].canNangHanhLy,
                   danhSachVe[i].cuocHanhLy);
        }

        printf("-------------------------------------------------------------------------------\n");
        printf("Tong tien cuoc hanh ly toan chuyen: %.0f VND\n", tongCuoc);

        printf("Ve co hanh ly ky gui nang nhat: %s - %s (%.1f kg)\n",
               danhSachVe[viTriNangNhat].maVe,
               danhSachVe[viTriNangNhat].tenHanhKhach,
               danhSachVe[viTriNangNhat].canNangHanhLy);
    }

    return 0;
}

