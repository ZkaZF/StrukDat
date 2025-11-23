/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait, representasi fisik pointer */
/* NIM & Nama : 24060124140161_Azka Wayasy Al Hafizh*/
/* Tanggal : 12 November 2025 */
#include "list2.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // kamus
    List2 Senarai;
    address A;
    address B;
    address C;
    address P;
    infotype D;
    infotype X, Y, V;
    List2 L, L1, L2, L3;

    // algoritma

    // aplikasi tipe address
    A = (address)malloc(sizeof(Elm)); // Alokasi('G')
    A->info = 'G';
    A->next = NIL;
    printf("info(A)=%c\t", A->info);
    B = (address)malloc(sizeof(Elm)); // Alokasi('N')
    B->info = 'N';
    B->next = A;
    printf("info(B)=%c\n", B->info);

    CreateList(&L);

    printf("Insert 'A'\n");
    InsertVFirst(&L, 'A');
    printf("Insert 'B'\n");
    InsertVFirst(&L, 'B');
    printf("Insert 'C'\n");
    InsertVFirst(&L, 'C');

    printf("List setelah insert: ");
    PrintList(L);
    printf("\n");

    InsertVLast(&L, 'D');
    printf("List setelah insert last 'D': ");
    PrintList(L);
    printf("\n");

    DeleteVFirst(&L, &V);
    printf("Elemen yang dihapus %c\n", V);
    printf("List: ");
    PrintList(L);
    printf("\n");

    if (IsEmptyList(L))
    {
        printf("List kosong \n");
    }
    else
    {
        printf("bukan list kosong\n");
    }

    if (IsOneElm(L))
    {
        printf("Satu element\n");
    }
    else
    {
        printf("bukan satu element\n");
    }

    printf("jumlah element: %d\n", NbElm(L));

    printf("CountX('A'): %d\n", CountX(L, 'A'));
    printf("FrekuensiX('A'): %.2f\n", FrekuensiX(L, 'A'));
    printf("CountVocal: %d\n", CountVocal(L));
    printf("CountNG: %d\n", CountNG(L));

    printf("InsertVAfterX 'A' with 'E'\n");
    InsertVAfterX(&L, 'A', 'E');
    printf("List after InsertVAfterX: ");
    PrintList(L);
    printf("\n");

    printf("UpdateX 'A' to 'Z'\n");
    UpdateX(&L, 'A', 'Z');
    printf("List after UpdateX: ");
    PrintList(L);
    printf("\n");

    printf("Invers list\n");
    Invers(&L);
    printf("List after Invers: ");
    PrintList(L);
    printf("\n");

    address found;
    SearchX(L, 'Z', &found);
    if (found != NIL)
    {
        printf("SearchX 'Z' found\n");
    }
    else
    {
        printf("SearchX 'Z' not found\n");
    }
}
