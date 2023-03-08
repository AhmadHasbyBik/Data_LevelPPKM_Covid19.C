#include <stdio.h>
#include <string.h>

typedef struct daerah {
    char kota[50];
    char provinsi[20];
} daerah;

struct dataPPKM {
    daerah daerah;
    double TotalPenduduk;
    double TotalLansia;
    double TotalPendudukTervaksinasi;
    double TotalLansiaTervaksinasi;
    char levelPPKM[1];
} dataPPKM[10], swap;

void penentuanLevel();
void urutAscen();
void urutDescen();
void cariLevel();
void cariProvinsi();
void cariKabupatenKota();

const int jumlahData = 10;

int main() {
    int menu;
    char kembali;

    strcpy(dataPPKM[0].daerah.kota,"Gresik");
	strcpy(dataPPKM[0].daerah.provinsi,"Jawa Timur");
	dataPPKM[0].TotalPenduduk = 1311215;
	dataPPKM[0].TotalLansia = 323849;
	dataPPKM[0].TotalPendudukTervaksinasi = 893823;
	dataPPKM[0].TotalLansiaTervaksinasi = 123834;

	strcpy(dataPPKM[1].daerah.kota,"Brebes");
	strcpy(dataPPKM[1].daerah.provinsi,"Jawa Tengah");
	dataPPKM[1].TotalPenduduk = 823742;
	dataPPKM[1].TotalLansia = 139432;
	dataPPKM[1].TotalPendudukTervaksinasi = 423943;
	dataPPKM[1].TotalLansiaTervaksinasi = 20334;

	strcpy(dataPPKM[2].daerah.kota,"Surabaya");
	strcpy(dataPPKM[2].daerah.provinsi,"Jawa Timur");
	dataPPKM[2].TotalPenduduk = 3234289;
	dataPPKM[2].TotalLansia = 732479;
	dataPPKM[2].TotalPendudukTervaksinasi = 2763378;
	dataPPKM[2].TotalLansiaTervaksinasi = 502534;

	strcpy(dataPPKM[3].daerah.kota,"Tuban");
	strcpy(dataPPKM[3].daerah.provinsi,"Jawa Timur");
	dataPPKM[3].TotalPenduduk = 623892;
	dataPPKM[3].TotalLansia = 100234;
	dataPPKM[3].TotalPendudukTervaksinasi = 102342;
	dataPPKM[3].TotalLansiaTervaksinasi = 12314;

	strcpy(dataPPKM[4].daerah.kota,"Malang");
	strcpy(dataPPKM[4].daerah.provinsi,"Jawa Timur");
	dataPPKM[4].TotalPenduduk = 2319813;
	dataPPKM[4].TotalLansia = 530131;
	dataPPKM[4].TotalPendudukTervaksinasi = 2139820;
	dataPPKM[4].TotalLansiaTervaksinasi = 201231;

	strcpy(dataPPKM[5].daerah.kota,"Trenggalek");
	strcpy(dataPPKM[5].daerah.provinsi,"Jawa Timur");
	dataPPKM[5].TotalPenduduk = 423892;
	dataPPKM[5].TotalLansia = 50234;
	dataPPKM[5].TotalPendudukTervaksinasi = 203213;
	dataPPKM[5].TotalLansiaTervaksinasi = 20321;

	strcpy(dataPPKM[6].daerah.kota,"Bogor");
	strcpy(dataPPKM[6].daerah.provinsi,"Jawa Barat");
	dataPPKM[6].TotalPenduduk = 1031223;
	dataPPKM[6].TotalLansia = 201334;
	dataPPKM[6].TotalPendudukTervaksinasi = 302234;
	dataPPKM[6].TotalLansiaTervaksinasi = 50123;

	strcpy(dataPPKM[7].daerah.kota,"Pacitan");
	strcpy(dataPPKM[7].daerah.provinsi,"Jawa Timur");
	dataPPKM[7].TotalPenduduk = 302439;
	dataPPKM[7].TotalLansia = 40243;
	dataPPKM[7].TotalPendudukTervaksinasi = 102348;
	dataPPKM[7].TotalLansiaTervaksinasi = 10234;

	strcpy(dataPPKM[8].daerah.kota,"Banjar");
	strcpy(dataPPKM[8].daerah.provinsi,"Jawa Tengah");
	dataPPKM[8].TotalPenduduk = 923459;
	dataPPKM[8].TotalLansia = 301258;
	dataPPKM[8].TotalPendudukTervaksinasi = 724085;
	dataPPKM[8].TotalLansiaTervaksinasi = 20345;

	strcpy(dataPPKM[9].daerah.kota,"Jember");
	strcpy(dataPPKM[9].daerah.provinsi,"Jawa Timur");
	dataPPKM[9].TotalPenduduk = 702139;
	dataPPKM[9].TotalLansia = 202384;
	dataPPKM[9].TotalPendudukTervaksinasi = 302733;
	dataPPKM[9].TotalLansiaTervaksinasi = 80233;

    do {
		printf("===================================================\n");
		printf("========= PROGRAM DATA LEVEL PPKM COVID-19 =========\n");
		printf("=========== Ahmad Hasby Bik || 20081010032 ==========\n");
		printf("===================================================\n");
		printf("\n=== SILAHKAN PILIH MENU YANG DI BAWAH INI ===\n");
		printf("1. PENENTUAN LEVEL PPKM\n");
		printf("2. PENGURUTAN MENURUT LEVEL PPKM\n");
		printf("3. PENCARIAN MENURUT LEVEL PPKM, PROVINSI, KABUPATEN/KOTA\n");

		printf("Masukkan pilihan anda: ");
		scanf("%d", &menu);

		printf("\n");

		switch(menu) {
			case 1 :
				penentuanLevel();
				printf("\n");
				break;
			case 2 :
				urutLevel();
				printf("\n");
				break;
			case 3 :
				pencarianData();
				printf("\n");
				break;
			default :
				printf("Maaf, input yang anda masukkan salah/invalid");
				printf("\n");
				break;
		}
		printf("\n");

		printf("Ingin kembali ke menu pilihan? (Y/T): ");
		scanf("%c", &kembali); scanf("%c", &kembali);
    }
    while(kembali == 'y' || kembali == 'Y');
}

void penentuanLevel() {
    int i;
    double persentaseVaksin, persentaseLansia;

    for(i = 0; i < jumlahData; i++) {

        persentaseVaksin = (dataPPKM[i].TotalPendudukTervaksinasi / dataPPKM[i].TotalPenduduk) * 100;
        persentaseLansia = (dataPPKM[i].TotalLansiaTervaksinasi / dataPPKM[i].TotalLansia) * 100;

        if(persentaseVaksin >= 70 && persentaseLansia >= 60) {
            strcpy(dataPPKM[i].levelPPKM, "1");
        }
        else if(persentaseVaksin >= 50 && persentaseLansia >= 40) {
            strcpy(dataPPKM[i].levelPPKM, "2");
        }
        else {
            strcpy(dataPPKM[i].levelPPKM, "3");
        }
    }

    //tampilkan hasil level
    for(i = 0; i < jumlahData; i++) {
        printf("Provinsi:\t%s\n", dataPPKM[i].daerah.provinsi);
        printf("Kabupaten/Kota:\t%s\n", dataPPKM[i].daerah.kota);
        printf("Level PPKM:\t%s\n", dataPPKM[i].levelPPKM);
        printf("Jumlah Penduduk Total:\t%lf\n", dataPPKM[i].TotalPenduduk);
        printf("Jumlah Lansia:\t%lf\n", dataPPKM[i].TotalLansia);
        printf("Jumlah Penduduk Tervaksinasi:\t%lf\n", dataPPKM[i].TotalPendudukTervaksinasi);
        printf("Jumlah Lansia Tervaksinasi:\t%lf\n", dataPPKM[i].TotalLansiaTervaksinasi);
        printf("\n");
    }
}

void tampilDataUrut() {
    int i;

    printf("LEVEL PPKM\tNAMA KABUPATEN/KOTA\tNAMA PROVINSI\n\n");

    for(i = 0; i < jumlahData; i++) {
        printf("%s\t\t%s\t\t%s\n", dataPPKM[i].levelPPKM, dataPPKM[i].daerah.kota, dataPPKM[i].daerah.provinsi);
    }
}

void urutAscen() {
    int i, j, minimum;

	for (i = 0; i < (jumlahData-1); i++) {
		minimum = i;

		for (j = i+1; j < jumlahData; j++) {
			if (strcmp(dataPPKM[j].levelPPKM, dataPPKM[minimum].levelPPKM) < 0)
				minimum = j;
		}
		if (minimum != i) {
            swap = dataPPKM[minimum];
            dataPPKM[minimum] = dataPPKM[i];
            dataPPKM[i] = swap;
		}
	}
}

void urutDescen() {
    int i, j, minimum;

	for (i = 0; i < (jumlahData-1); i++) {
		minimum = i;

		for (j = i+1; j < jumlahData; j++) {
			if (strcmp(dataPPKM[j].levelPPKM, dataPPKM[minimum].levelPPKM) > 0)
				minimum = j;
		}
		if (minimum != i) {
            swap = dataPPKM[minimum];
            dataPPKM[minimum] = dataPPKM[i];
            dataPPKM[i] = swap;
		}
	}
}

void urutLevel() {
    int menu;

    printf("============== Pengurutan LEVEL PPKM ==============\n\n");

	printf("1. URUT LEVEL PPKM ASCENDING\n");
	printf("2. URUT LEVEL PPKM DESCENDING\n");

	printf("Masukkan pilihan anda: ");
	scanf("%d", &menu);

	printf("\n");

	switch(menu) {
		case 1 :
			urutAscen();
			tampilDataUrut();
			printf("\n");
			break;
		case 2 :
			urutDescen();
			tampilDataUrut();
			printf("\n");
			break;
		default :
			printf("Maaf, input yang anda masukkan salah/invalid");
			printf("\n");
			break;
	}
}

void tampilHasilPencarian(int i) {
    printf("Provinsi:\t%s\n", dataPPKM[i].daerah.provinsi);
    printf("Kabupaten/Kota:\t%s\n", dataPPKM[i].daerah.kota);
    printf("Level PPKM:\t%s\n", dataPPKM[i].levelPPKM);
    printf("Jumlah Penduduk Total:\t%lf\n", dataPPKM[i].TotalPenduduk);
    printf("Jumlah Lansia:\t%lf\n", dataPPKM[i].TotalLansia);
    printf("Jumlah Penduduk Tervaksinasi:\t%lf\n", dataPPKM[i].TotalPendudukTervaksinasi);
    printf("Jumlah Lansia Tervaksinasi:\t%lf\n", dataPPKM[i].TotalLansiaTervaksinasi);
    printf("\n");
}

void cariLevel() {
    int i, flag = 0;
    char cari[1];

    printf("==================== Pencarian Data Menurut LEVEL ====================\n\n");

	printf("Masukkan LEVEL PPKM yang datanya ingin dicari: ");
	gets(cari);
	scanf("%s", &cari);

	for(i = 0; i < jumlahData; i++) {
		if (strcmp(dataPPKM[i].levelPPKM, cari) == 0) {
            flag = 1;
            tampilHasilPencarian(i);
		}
	}

	if (flag == 0) {
        printf("Data yang tidak ditemukan \n");
    }
}

void cariProvinsi() {
    int i, flag = 0;
    char cari[20];

    printf("==================== Pencarian Data Menurut Provinsi ====================\n\n");

	printf("Masukkan Provinsi yang datanya ingin dicari: ");
	gets(cari);
	scanf("%[^\n]", &cari);

	for(i = 0; i < jumlahData; i++) {
		if (strcmp(dataPPKM[i].daerah.provinsi, cari) == 0) {
            flag = 1;
            tampilHasilPencarian(i);
		}
	}

	if (flag == 0) {
        printf("Data yang tidak ditemukan \n");
    }
}

void cariKabupatenKota() {
    int i, flag = 0;
    char cari[50];

    printf("==================== Pencarian Data Menurut Kabupaten/Kota ====================\n\n");

	printf("Masukkan Kabupaten/Kota yang datanya ingin dicari: ");
	gets(cari);
	scanf("%s", &cari);

	for(i = 0; i < jumlahData; i++) {
		if (strcmp(dataPPKM[i].daerah.kota, cari) == 0) {
            flag = 1;
            tampilHasilPencarian(i);
		}
	}

	if (flag == 0) {
        printf("Data yang tidak ditemukan \n");
    }
}

void pencarianData() {
    int menu;

    printf("========================= Pencarian Data LEVEL PPKM =============================\n\n");
	printf("\n================== SILAHKAN PILIH OPSI PENCARIAN DI BAWAH INI =================\n");

	printf("1. CARI MENURUT LEVEL PPKM\n");
	printf("2. CARI MENURUT PROVINSI\n");
	printf("3. CARI MENURUT KABUPATEN/KOTA\n");

    printf("Masukkan pilihan anda: ");
	scanf("%d", &menu);

	printf("\n");

	switch(menu) {
		case 1 :
			cariLevel();
			printf("\n");
			break;
		case 2 :
			cariProvinsi();
			printf("\n");
			break;
		case 3 :
			cariKabupatenKota();
			printf("\n");
			break;
		default :
			printf("Maaf, input yang anda masukkan salah/invalid");
			printf("\n");
			break;
	}
}
