#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "evil.h"


int main()
{
    EvcilHayvan *hayvan = NULL;  // Evcil Hayvan yapýsýný temsil eden struct tanýmý

    int choice;

    printf("Evcil Hayvan Simulasyonuna Hos Geldiniz!\n");  //baslangýc gorseli
    while (1)
    {
        printf("\nYapmak istediginiz islemi secin:\n");
        printf("1. Evcil Hayvan Ekle\n");
        printf("2. Evcil Hayvan Sil    (Calisma asamasinda)\n");
        printf("3. Evcil Hayvana Besle\n");
        printf("4. Evcil Hayvana Su Ver\n");
        printf("5. Evcil Hayvana Oyun Oynat\n");
        printf("6. Evcil Hayvani Temizle\n");
        printf("7. Evcil Hayvani Sev\n");
        printf("8. Evcil Hayvani Uyut\n");
        printf("9. Evcil Hayvana Odul Ver\n");
        printf("10.Evcil Hayvan Guncelle   (Calisma asamasinda)\n");
        printf("0. Cikis\n");

        printf("Seciminizi yapin: ");
        scanf("%d", &choice);

        switch (choice)  // menu baslangýcý
        {
        case 1:
            hayvan = olusturEvcilHayvan();
            if (hayvan != NULL)
            {
                printf("Evcil Hayvan olusturuldu.\n");
            }
            break;
        case 2:
            silEvcilHayvan(hayvan);
            hayvan = NULL;
            break;
        case 3:
            if(hayvan->energy<5)   //Enerjinin 5'den düsük olma durumu her bir eylemde test ediliyor.
            {
                printf("Lutfen evcil hayvaninizi uyutun!\n");
            }
            else
                besleEvcilHayvan(hayvan);
            break;
        case 4:
            if(hayvan->energy<5)
            {
                printf("Lutfen evcil hayvaninizi uyutun!\n");
            }
            else
                suVerEvcilHayvan(hayvan);
            break;
        case 5:
            if(hayvan->energy<5)
            {
                printf("Lutfen evcil hayvaninizi uyutun !\n");
            }
            else
                oynaEvcilHayvan(hayvan);
            break;
        case 6:
            if(hayvan->energy<5)
            {
                printf("Lutfen evcil hayvaninizi uyutun !\n");
            }
            else if(hayvan->mutluluk<5)
                {
                    printf("Lütfen evcil hayvaninizi mutlu edin!\n");
                }
            else
                temizleEvcilHayvan(hayvan);
            break;
        case 7:
            if(hayvan->energy<5)
            {
                printf("Lutfen evcil hayvaninizi uyutun!\n");
            }
            else
                sevEvcilHayvan(hayvan);
            break;
        case 8:
            if(hayvan->mutluluk<5)
                {
                    printf("Lutfen evcil hayvaninizi mutlu edin!\n");
                }
            else
                uyutEvcilHayvan(hayvan);
            break;
        case 9:
            if(hayvan->energy<5)
            {
                printf("Lutfen evcil hayvaninizi uyutun!\n");
            }
            else
            odulEvcilHayvan(hayvan);
            break;
        case 10:
            hayvan = GuncelleEvcilhayvan();
                    if (hayvan != NULL)
                {
                    printf("Lutfen evcil hayvaninizin ismini girin!\n");
                }
                else
                break;
        case 0:
            kaydetEvcilHayvan(hayvan);
            kaydetDuyguEvcilHayvan(hayvan);
            printf("Cikis yapiliyor...\n");
            exit(0);
        default:
            printf("Gecersiz bir secim yaptiniz.\n");
            break;
        }
        duyguGoster(hayvan);
    }

    return 0;
}
