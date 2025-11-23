/* File : main.c */
/* Deskripsi : aplikasi untuk menguji ADT list3 */
/* NIM & Nama : 24060124140161/Azka Wayasy Al Hafizh */
/* Tanggal : 20 November 2024 */
#include "list3.h"
#include <stdio.h>

int main()
{
    List3 L, L1, L2, L3;
    infotype val, searchVal;
    address addr;

    CreateList(&L);
    printf("List kosong: ");
    PrintList(L);

    InsertVFirst(&L, 'A');
    InsertVLast(&L, 'B');
    InsertVFirst(&L, 'C');
    printf("Setelah insert: ");
    PrintList(L);

    printf("Jumlah elemen: %d\n", NbElm(L));

    DeleteVFirst(&L, &val);
    printf("Hapus first (%c): ", val);
    PrintList(L);

    UpdateX(&L, 'B', 'D');
    printf("Update B ke D: ");
    PrintList(L);

    Invers(&L);
    printf("Invers: ");
    PrintList(L);

    InsertVLast(&L, 'E');
    InsertVLast(&L, 'F');
    printf("Setelah tambah E dan F: ");
    PrintList(L);

    DeleteVLast(&L, &val);
    printf("Hapus last (%c): ", val);
    PrintList(L);

    InsertVFirst(&L, 'G');
    InsertVLast(&L, 'H');
    printf("Setelah tambah G di depan dan H di belakang: ");
    PrintList(L);

    DeleteX(&L, 'G');
    printf("Hapus elemen 'G': ");
    PrintList(L);

    searchVal = 'D';
    SearchX(L, searchVal, &addr);
    if (addr != NIL)
        printf("Search '%c': ditemukan\n", searchVal);
    else
        printf("Search '%c': tidak ditemukan\n", searchVal);

    InsertVAfterX(&L, 'D', 'I');
    printf("Insert I setelah D: ");
    PrintList(L);

    InsertVBeforeX(&L, 'I', 'J');
    printf("Insert J sebelum I: ");
    PrintList(L);

    DeleteVAfterX(&L, 'D', &val);
    printf("Hapus elemen setelah D (%c): ", val);
    PrintList(L);

    DeleteVBeforeX(&L, 'I', &val);
    printf("Hapus elemen sebelum I (%c): ", val);
    PrintList(L);

    int count = CountX(L, 'D');
    printf("Jumlah elemen 'D': %d\n", count);

    float freq = FrekuensiX(L, 'D');
    printf("Frekuensi elemen 'D': %.2f\n", freq);

    int max = MaxMember(L);
    printf("Max member count: %d\n", max);

    char modus = Modus(L);
    printf("Modus daftar: %c\n", modus);

    int countVocal = CountVocal(L);
    printf("Jumlah vokal: %d\n", countVocal);

    int countNG = CountNG(L);
    printf("Jumlah pasangan 'NG': %d\n", countNG);

    printf("Posisi elemen 'D': ");
    SearchAllX(L, 'D');

    DeleteAllX(&L, 'D');
    printf("Hapus semua elemen 'D': ");
    PrintList(L);

    CreateList(&L1);
    InsertVLast(&L1, 'X');
    InsertVLast(&L1, 'Y');
    CreateList(&L2);
    InsertVLast(&L2, 'Z');
    InsertVLast(&L2, 'W');
    ConcatList(L1, L2, &L3);
    printf("Concat L1 dan L2 menjadi L3: ");
    PrintList(L3);

    List3 L4, L5;
    SplitList(L3, &L4, &L5);
    printf("Split L3 menjadi L4 dan L5:\nL4: ");
    PrintList(L4);
    printf("L5: ");
    PrintList(L5);

    List3 L6;
    CopyList(L4, &L6);
    printf("Copy L4 menjadi L6: ");
    PrintList(L6);

    return 0;
}
