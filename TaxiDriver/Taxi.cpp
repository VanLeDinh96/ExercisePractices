#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Taxi {
    int maSo;
    char tenTaiXe[50];
    char diaChi[100];
    int soKmDaChay;
    int soChoNgoi;
};


void xuatThongTinTaxi(struct Taxi taxi) {
    printf("Ma so: %d\n", taxi.maSo);
    printf("Ten tai xe: %s\n", taxi.tenTaiXe);
    printf("Dia chi don khach: %s\n", taxi.diaChi);
    printf("So km da chay: %d\n", taxi.soKmDaChay);
    printf("So cho ngoi cua xe taxi: %d\n", taxi.soChoNgoi);
}


int kiemTraTaiXe(struct Taxi taxi, char ten[]) {
    char driverName[50]{};
    char inputName[50]{};

    for (int i = 0; taxi.tenTaiXe[i]; i++) {
        driverName[i] = tolower(taxi.tenTaiXe[i]);
    }
    for (int i = 0; ten[i]; i++) {
        inputName[i] = tolower(ten[i]);
    }

    if (strstr(driverName, inputName) != NULL) {
        return 1;
    }
    else {
        return 0;
    }
}


int kiemTraQuan(struct Taxi taxi, char quan[]) {
    if (strstr(taxi.diaChi, quan) != NULL) {
        return 1;
    }
    else {
        return 0;
    }
}


void hienThiSoChoNgoi(struct Taxi taxi) {
    printf("So cho ngoi cua xe taxi: %d\n", taxi.soChoNgoi);
}

float tinhTien(int soKm) {
    float gia;
    if (soKm <= 5) {
        gia = soKm * 15;
    }
    else if (soKm <= 10) {
        gia = 5 * 15 + (soKm - 5) * 14;
    }
    else {
        gia = 5 * 15 + 5 * 14 + (soKm - 10) * 10;
        return gia;
    }
}

int main() {
    FILE* file;
    struct Taxi taxi {};


    if (fopen_s(&file, "thongtin.txt", "r") != 0) {
        printf("Khong the mo file.\n");
        return 1;
    }

    fscanf_s(file, "Ma so: %d\n", &taxi.maSo);
    fscanf_s(file, "Ten tai xe: %[^\n]\n", taxi.tenTaiXe, (unsigned int)sizeof(taxi.tenTaiXe));
    fscanf_s(file, "Dia chi don khach: %[^\n]\n", taxi.diaChi, (unsigned int)sizeof(taxi.diaChi));
    fscanf_s(file, "So km da chay: %d\n", &taxi.soKmDaChay);
    fscanf_s(file, "So cho ngoi cua xe taxi: %d\n", &taxi.soChoNgoi);


    fclose(file);


    printf("Thong tin cua Taxi:\n");
    xuatThongTinTaxi(taxi);


    char tenTaiXe[50];
    printf("\nNhap ten tai xe can kiem tra: ");
    scanf_s(" %[^\n]", tenTaiXe, (unsigned int)sizeof(tenTaiXe));
    if (kiemTraTaiXe(taxi, tenTaiXe)) {
        printf("%s dang chay taxi.\n", taxi.tenTaiXe);
    }
    else {
        printf("%s khong chay taxi.\n", tenTaiXe);
    }


    char quan[50];
    printf("\nNhap quan/huyen can kiem tra: ");
    scanf_s(" %[^\n]", quan, (unsigned int)sizeof(quan));
    if (kiemTraQuan(taxi, quan)) {
        printf("Taxi chay tren quan/huyen %s.\n", quan);
    }
    else {
        printf("Taxi khong chay tren quan/huyen %s.\n", quan);
    }


    printf("\n");
    hienThiSoChoNgoi(taxi);

    int soKm;
    printf("\nnhap so km da di: ");
    scanf_s("%d", &soKm);

    float tien = tinhTien(soKm);
    printf("so tien phai tra la: %.2f Do \n", tien);

    return 0;
}