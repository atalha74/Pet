#ifndef Evcil_H
#define Evcil_H

typedef struct
{
    char type[50];
    char name[50];
    int energy;
    int mutluluk;
} EvcilHayvan;


EvcilHayvan* olusturEvcilHayvan();
EvcilHayvan* GuncelleEvcilhayvan();
void silEvcilHayvan(EvcilHayvan* hayvan);
void kaydetEvcilHayvan(EvcilHayvan* hayvan);
void duyguGoster(EvcilHayvan* hayvan);
void kaydetDuyguEvcilHayvan(EvcilHayvan* hayvan);
void besleEvcilHayvan(EvcilHayvan* hayvan);
void suVerEvcilHayvan(EvcilHayvan* hayvan);
void oynaEvcilHayvan(EvcilHayvan* hayvan);
void temizleEvcilHayvan(EvcilHayvan* hayvan);
void sevEvcilHayvan(EvcilHayvan* hayvan);
void uyutEvcilHayvan(EvcilHayvan* hayvan);
void odulEvcilHayvan(EvcilHayvan* hayvan);

EvcilHayvan* olusturEvcilHayvan()
{
    EvcilHayvan* hayvan = (EvcilHayvan*)malloc(sizeof(EvcilHayvan)); // EvcilHayvan örneði için bellek ayýrýr
    if (hayvan == NULL)
    {
        printf("Bellek hatasi! Evcil Hayvan olusturulamadi.\n");
        return NULL;
    }

    printf("Evcil Hayvanin turunu girin: ");
    scanf("%s", hayvan->type);
    printf("Evcil Hayvanin adini girin: ");
    scanf("%s", hayvan->name);


    hayvan->energy = 60;
    hayvan->mutluluk = 60;

    return hayvan;
}

void silEvcilHayvan(EvcilHayvan* hayvan)
{
    //FILE* file = fopen("evcil_veri.txt", "wb+");
    printf("silmek istediginiz hayvanin ismini giriniz: ");
}

void kaydetEvcilHayvan(EvcilHayvan* hayvan)
{
    FILE* file = fopen("evcil_veri.txt", "wb+");
    if (file == NULL)
    {
        printf("Dosya hatasi! Evcil Hayvan kaydedilemedi.\n");
        return;
    }

    fprintf(file, "%s,%s,%d,%d\n", hayvan->type, hayvan->name, hayvan->energy, hayvan->mutluluk);

    fclose(file);
}

void duyguGoster(EvcilHayvan* hayvan) // ekranda her seferinde printlencek olan fonksiyon
{
        if (hayvan->energy > 25 && hayvan->mutluluk > 50)
    {
        printf("1,Mutlu,:),es>25,ms>50\n");
    }
    if (hayvan->energy < 20 && hayvan->mutluluk < 20)
    {
        printf("2,Uzgun,:(,es<20,ms<20\n");
    }
    if (hayvan->energy < 10 && hayvan->mutluluk < 10)
    {
        printf("3,Agliyor,:'( es<10,ms<10\n");
    }
    if (hayvan->energy < 5)
    {
        printf("4,Uyuyor,:zz,es<5");
    }
    if (hayvan->energy < 20)
    {
        printf("5,Ac,:-o,es<20");
    }
    if (hayvan->energy > 40 || hayvan->mutluluk < 30)
    {
        printf("6,Oyun Istiyor,<:o,es>40 or ms<30");
    }
}

void kaydetDuyguEvcilHayvan(EvcilHayvan* hayvan)  // evcil_cikti.txt olarak kaydetmemizi saglayacak
{
    FILE* file = fopen("evcil_cikti.txt", "wb+");
    if (file == NULL)
    {
        printf("Dosya hatasi! Evcil Hayvan kaydedilemedi.\n");
        return;
    }

    if (hayvan->energy > 25 && hayvan->mutluluk > 50)
    {
        fprintf(file, "1,Mutlu,:),es>25,ms>50\n");
    }
    if (hayvan->energy < 20 && hayvan->mutluluk < 20)
    {
        fprintf(file, "2,Uzgun,:(,es<20,ms<20\n");
    }
    if (hayvan->energy < 10 && hayvan->mutluluk < 10)
    {
        fprintf(file, "3,Agliyor,:'( es<10,ms<10\n");
    }
    if (hayvan->energy < 5)
    {
        fprintf(file, "4,Uyuyor,:zz,es<5");
    }
    if (hayvan->energy < 20)
    {
        fprintf(file, "5,Ac,:-o,es<20");
    }

    if (hayvan->energy > 40 | hayvan->mutluluk < 30)
    {
        fprintf(file, "6,Oyun Istiyor,<:o,es>40 or ms<30");
    }

    fclose(file);
    FILE* ifile = fopen("evcil_veri.txt", "a");
    if (ifile == NULL)
    {
        printf("Dosya hatasi! Evcil Hayvan kaydedilemedi.\n");
        return;
    }

    if (hayvan->energy > 25 && hayvan->mutluluk > 50)
    {
        fprintf(ifile, "1,Mutlu,:),es>25,ms>50\n");
    }
    if (hayvan->energy < 20 && hayvan->mutluluk < 20)
    {
        fprintf(ifile, "2,Uzgun,:(,es<20,ms<20\n");
    }
    if (hayvan->energy < 10 && hayvan->mutluluk < 10)
    {
        fprintf(ifile, "3,Agliyor,:'( es<10,ms<10\n");
    }
    if (hayvan->energy < 5)
    {
        fprintf(ifile, "4,Uyuyor,:zz,es<5");
    }
    if (hayvan->energy < 20)
    {
        fprintf(ifile, "5,Ac,:-o,es<20");
    }
    if (hayvan->energy > 40 || hayvan->mutluluk < 30)
    {
        fprintf(ifile, "6,Oyun Istiyor,<:o,es>40 or ms<30");
    }

    fclose(ifile);
}





void besleEvcilHayvan(EvcilHayvan* hayvan)
{
    if (hayvan == NULL)
    {
        printf("Evcil Hayvan bulunamadi!\n");
        return;
    }

    hayvan->energy += 15;
    hayvan->mutluluk += 10;

    printf("Evcil Hayvana yemek verildi. Enerji: %d, Mutluluk: %d\n", hayvan->energy, hayvan->mutluluk);
}

void suVerEvcilHayvan(EvcilHayvan* hayvan)
{
    if (hayvan == NULL)
    {
        printf("Evcil Hayvan bulunamadi!\n");
        return;
    }

    hayvan->energy += 5;
    hayvan->mutluluk += 5;

    printf("Evcil Hayvana su verildi. Enerji: %d, Mutluluk: %d\n", hayvan->energy, hayvan->mutluluk);
}

void oynaEvcilHayvan(EvcilHayvan* hayvan)
{
    if (hayvan == NULL)
    {
        printf("Evcil Hayvan bulunamadi!\n");
        return;
    }

    hayvan->energy -= 15;
    hayvan->mutluluk += 15;

    printf("Evcil Hayvanla oyun oynandi. Enerji: %d, Mutluluk: %d\n", hayvan->energy, hayvan->mutluluk);
}

void temizleEvcilHayvan(EvcilHayvan* hayvan)
{
    if (hayvan == NULL)
    {
        printf("Evcil Hayvan bulunamadi!\n");
        return;
    }

    hayvan->energy -= 10;
    hayvan->mutluluk -= 5;

    printf("Evcil Hayvan temizlendi. Enerji: %d, Mutluluk: %d\n", hayvan->energy, hayvan->mutluluk);
}

void sevEvcilHayvan(EvcilHayvan* hayvan)
{
    if (hayvan == NULL)
    {
        printf("Evcil Hayvan bulunamadi!\n");
        return;
    }

    hayvan->mutluluk += 5;

    printf("Evcil Hayvana sevgi gosterildi. Enerji: %d, Mutluluk: %d\n", hayvan->energy, hayvan->mutluluk);
}

void uyutEvcilHayvan(EvcilHayvan* hayvan)
{
    if (hayvan == NULL)
    {
        printf("Evcil Hayvan bulunamadi!\n");
        return;
    }

    printf("Evcil Hayvan uyuyor...\n");
    hayvan->energy += 5;

    printf("Evcil Hayvan uyandý. Enerji: %d, Mutluluk: %d\n", hayvan->energy, hayvan->mutluluk);
}

void odulEvcilHayvan(EvcilHayvan* hayvan)
{
    if (hayvan == NULL)
    {
        printf("Evcil Hayvan bulunamadi!\n");
        return;
    }

    hayvan->mutluluk += 10;

    printf("Evcil Hayvana odul verildi. Enerji: %d, Mutluluk: %d\n", hayvan->energy, hayvan->mutluluk);
}

void updateEvcilHayvan(EvcilHayvan* hayvan)
{
    if (hayvan == NULL)
    {
        printf("Evcil Hayvan bulunamadi!\n");
        return;
    }

    if (hayvan->energy < 5 || hayvan->mutluluk < 5)
    {
        printf("Evcil Hayvanin enerji seviyesi cok dusuk! Uyumasý gerekiyor.\n");
        uyutEvcilHayvan(hayvan);
    }
    else if (hayvan->mutluluk < 5)
    {
        printf("Evcil Hayvanin mutsuz durumda! Sadece sevgi islemlerini gerceklestirebilirsiniz.\n");
    }
    else
    {
        printf("Evcil Hayvanin durumu:\n");
        printf("Tur: %s\n", hayvan->type);
        printf("Ad: %s\n", hayvan->name);
        printf("Enerji: %d\n", hayvan->energy);
        printf("Mutluluk: %d\n", hayvan->mutluluk);
    }
}
EvcilHayvan* GuncelleEvcilhayvan()
{
    //FILE* file = fopen("evcil_veri.txt", "wb+");
    char ename;
    EvcilHayvan* hayvan;
    printf("Evcil Hayvanin adini girin: ");
    scanf("%d", ename);
    if (hayvan->name != ename)
    {
        printf("Evcil Hayvan Guncellenemedi\n");
        return hayvan;
    }
    else (hayvan->name == ename);
    {
        printf("Vermek istediginiz yeni ismi giriniz :");
        //fprintf("evcil_veri.txt"* hayvan->name "wb+");
    }

}




#endif  // Evcil_H
