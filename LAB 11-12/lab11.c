#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int number;
    char name[50];
    char department[50];
};

void createFile() {
    FILE *file = fopen("student.dat", "w");
    if (file == NULL) {
        printf("Dosya oluþturulamadý.\n");
        return;
    }
    fclose(file);
    printf("Dosya olusturuldu: student.dat\n");
}

void addRecord() {
    struct Student student;
    FILE *file = fopen("student.dat", "a");
    if (file == NULL) {
        printf("Dosya acilamadi.\n");
        return;
    }
    printf("Ogrenci numarasi: ");
    scanf("%d", &student.number);
    printf("Ogrenci ismi: ");
    scanf("%s", student.name);
    printf("Bolum: ");
    scanf("%s", student.department);

    fwrite(&student, sizeof(struct Student), 1, file);
    fclose(file);
    printf("Kayit eklendi.\n");
}

void searchByName() {
    char searchName[50];
    struct Student student;
    FILE *file = fopen("student.dat", "r");
    if (file == NULL) {
        printf("Dosya acilamadi.\n");
        return;
    }

    printf("Aranacak ogrenci ismi: ");
    scanf("%s", searchName);

    while (fread(&student, sizeof(struct Student), 1, file) == 1) {
        if (strcmp(student.name, searchName) == 0) {
            printf("Ogrenci No: %d\n", student.number);
            printf("Ogrenci ismi: %s\n", student.name);
            printf("Bolum: %s\n", student.department);
            fclose(file);
            return;
        }
    }

    printf("Ogrenci bulunamadý.\n");
    fclose(file);
}

void listStudents() {
    struct Student student;
    FILE *file = fopen("student.dat", "r");
    if (file == NULL) {
        printf("Dosya acilamadi.\n");
        return;
    }

    while (fread(&student, sizeof(struct Student), 1, file) == 1) {
        printf("Ogrenci No: %d\n", student.number);
        printf("Ogrenci ismi: %s\n", student.name);
        printf("Bolum: %s\n", student.department);
        printf("--------------------\n");
    }

    fclose(file);
}

int main() {
    int choice;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1- Dosya olustur\n");
        printf("2- Kayit ekle\n");
        printf("3- Isme gore ogrenci ara ve bilgilerini ekrana yazdir\n");
        printf("4- Ogrencileri listele\n");
        printf("5- Cikis\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                addRecord();
                break;
            case 3:
                searchByName();
                break;
            case 4:
                listStudents();
                break;
            case 5:
                printf("Programdan cikiliyor...\n");
                exit(0); 
            default:
                printf("Gecersiz secim. Tekrar deneyin.\n");
        }
    }

    return 0;
}

