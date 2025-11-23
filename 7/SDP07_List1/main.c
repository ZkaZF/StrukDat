/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait, representasi fisik pointer */
/* NIM & Nama : 24060124140161_Azka Wayasy Al Hafizh*/
/* Tanggal : 5 November 2025 */
#include <stdio.h>
#include <stdlib.h>
#include "list1.h"
int main()
{ // kamus
  address A;
  address B;
  address P;
  List1 Senarai;
  infotype deleted;
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

  // aplikasi tipe List1
  Senarai.First = B; // First(Senarai) = B;
  printf("Isi Senarai :");
  P = First(Senarai);
  while (P != NIL)
  {
    printf("\t%c", info(P));
    P = next(P);
  }
  // PrintList(Senarai);
  CreateList(&Senarai);
  InsertVFirst(&Senarai, 'X');
  InsertVFirst(&Senarai, 'Y');
  InsertVFirst(&Senarai, 'Z');
  PrintList(Senarai);
  printf("\nNbElm(Senarai) = %d\n", NbElm(Senarai));
  DeleteVFirst(&Senarai, &deleted);
  printf("\nDeleted: %c\n", deleted);
  PrintList(Senarai);

  InsertVLast(&Senarai, 'A');
  InsertVLast(&Senarai, 'B');
  InsertVLast(&Senarai, 'A');
  PrintList(Senarai);
  printf("\nCountVocal(Senarai) = %d\n", CountVocal(Senarai));
  printf("CountX(Senarai, 'A') = %d\n", CountX(Senarai, 'A'));
  printf("FrekuensiX(Senarai, 'A') = %.2f\n", FrekuensiX(Senarai, 'A'));
  SearchAllX(Senarai, 'A');
  printf("Modus(Senarai) = %c\n", Modus(Senarai));
  printf("NbModus(Senarai) = %d\n", NbModus(Senarai));

  // Test SearchX
  SearchX(Senarai, 'C', &A);
  if (A != NIL)
  {
    printf("'C' ketemu %c\n");
  }
  else
  {
    printf("'C' tidak ketemu\n");
  }

  // Test UpdateX
  UpdateX(&Senarai, 'A', 'C');
  PrintList(Senarai);

  // Test Invers
  Invers(&Senarai);
  PrintList(Senarai);

  return 0;
}
