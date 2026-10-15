
#include <stdio.h>
#include <string.h>

struct VeMayBay {
    char maPNR[10];
    char tenHanhKhach[50];
    char hangVe[15];
    float trongLuongHanhLy;
    long phiPhuThu;
};

int main() {
    struct VeMayBay ds[50];
    int n, i, timThay = 0;
    char maCanTim[10];
    float trongLuongMoi;

    printf("=== HE THONG CHECK-IN VE MAY BAY ===\n");

    do {
        printf("Nhap so luong ve (1 - 50): ");
        if (scanf("%d", &n) != 1) {
            while (getchar() != '\n');
            n = 0;
        } else {
            while (getchar() != '\n');
        }
    } while (n < 1 || n > 50);

    for (i = 0; i < n; i++) {
        printf("\n--- Nhap thong tin ve thu %d ---\n", i + 1);

        printf("Nhap ma PNR: ");
        fgets(ds[i].maPNR, sizeof(ds[i].maPNR), stdin);
        ds[i].maPNR[strcspn(ds[i].maPNR, "\n")] = '\0';

        printf("Nhap ho ten hanh khach: ");
        fgets(ds[i].tenHanhKhach, sizeof(ds[i].tenHanhKhach), stdin);
        ds[i].tenHanhKhach[strcspn(ds[i].tenHanhKhach, "\n")] = '\0';

        printf("Nhap hang ve (Eco/Deluxe/Business): ");
        fgets(ds[i].hangVe, sizeof(ds[i].hangVe), stdin);
        ds[i].hangVe[strcspn(ds[i].hangVe, "\n")] = '\0';

        printf("Nhap trong luong hanh ly (kg): ");
        scanf("%f", &ds[i].trongLuongHanhLy);
        while (getchar() != '\n');

        if (ds[i].trongLuongHanhLy > 7.0) {
            ds[i].phiPhuThu =
                (long)((ds[i].trongLuongHanhLy - 7.0) * 50000);
        } else {
            ds[i].phiPhuThu = 0;
        }
    }

    printf("\n=== DANH SACH VE MAY BAY CHUYEN BAY ===\n");
    printf("------------------------------------------------------------------------------------------------\n");
    printf("%-5s %-10s %-25s %-12s %-12s %-15s\n",
           "STT", "MA PNR", "HO TEN HANH KHACH", "HANG VE",
           "HANH LY(KG)", "PHI PHU THU");
    printf("------------------------------------------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%-5d %-10s %-25s %-12s %-12.1f %-15ld\n",
               i + 1,
               ds[i].maPNR,
               ds[i].tenHanhKhach,
               ds[i].hangVe,
               ds[i].trongLuongHanhLy,
               ds[i].phiPhuThu);
    }

    printf("------------------------------------------------------------------------------------------------\n");

    printf("\n=== CAP NHAT THONG TIN HANH LY ===\n");
    printf("Nhap ma PNR can cap nhat: ");
    fgets(maCanTim, sizeof(maCanTim), stdin);
    maCanTim[strcspn(maCanTim, "\n")] = '\0';

    for (i = 0; i < n; i++) {
        if (strcmp(ds[i].maPNR, maCanTim) == 0) {
            timThay = 1;

            printf("Tim thay ve cua hanh khach: %s\n",
                   ds[i].tenHanhKhach);

            printf("Nhap trong luong hanh ly moi (kg): ");
            scanf("%f", &trongLuongMoi);
            while (getchar() != '\n');

            ds[i].trongLuongHanhLy = trongLuongMoi;

            if (ds[i].trongLuongHanhLy > 7.0) {
                ds[i].phiPhuThu =
                    (long)((ds[i].trongLuongHanhLy - 7.0) * 50000);
            } else {
                ds[i].phiPhuThu = 0;
            }

            printf("Cap nhat thanh cong! Phi phu thu moi: %ld VND\n",
                   ds[i].phiPhuThu);

            break;
        }
    }

    if (timThay == 0) {
        printf("Khong tim thay ma PNR hop le!\n");
    } else {
        printf("\n=== DANH SACH VE MAY BAY SAU CAP NHAT ===\n");
        printf("------------------------------------------------------------------------------------------------\n");
        printf("%-5s %-10s %-25s %-12s %-12s %-15s\n",
               "STT", "MA PNR", "HO TEN HANH KHACH", "HANG VE",
               "HANH LY(KG)", "PHI PHU THU");
        printf("------------------------------------------------------------------------------------------------\n");

        for (i = 0; i < n; i++) {
            printf("%-5d %-10s %-25s %-12s %-12.1f %-15ld\n",
                   i + 1,
                   ds[i].maPNR,
                   ds[i].tenHanhKhach,
                   ds[i].hangVe,
                   ds[i].trongLuongHanhLy,
                   ds[i].phiPhuThu);
        }

        printf("------------------------------------------------------------------------------------------------\n");
    }

    return 0;
}

