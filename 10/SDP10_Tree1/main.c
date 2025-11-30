/* File : pohon1.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060124140161 - Azka Wayasy Al Hafizh*/
/* Tanggal : 26 November 2025 */

#include "pohon1.h"

int main()
{ // kamus
     bintree B, A;
     // algirtma
     B = Tree('T',
              Tree('I',
                   Tree('N', NIL, NIL),
                   Tree('F',
                        Tree('O', NIL, NIL),
                        NIL)),
              Tree('R',
                   Tree('M',
                        Tree('A', NIL, NIL),
                        Tree('T', NIL, NIL)),
                   Tree('I',
                        NIL,
                        Tree('K',
                             NIL,
                             Tree('A', NIL, NIL)))));
     PrintPrefix(B);
     printf("\n");
     printf("apakah tree kosong? %s\n", IsEmptyTree(B) ? "true" : "false");
     printf("apakah daun? %s\n", IsDaun(B) ? "true" : "false");
     printf("apakah pohon biner? %s\n", IsBiner(B) ? "true" : "false");
     printf("apakah uner left? %s\n", IsUnerLeft(B) ? "true" : "false");
     printf("apakah uner right? %s\n", IsUnerRight(B) ? "true" : "false");
     printf("jumlah elemen: %d\n", NbElm(B));
     printf("jumlah daun: %d\n", NbDaun(B));

     printf("nilai maksimal antara 10 dan 20 adalah %d\n", max2(10, 20));
     printf("tinggi pohon: %d\n", Tinggi(B));
     printf("apakah ada elemen 'K': %s\n", SearchX(B, 'K') ? "true" : "false");
     printf("apakah ada elemen 'Z': %s\n", SearchX(B, 'Z') ? "true" : "false");
     UpdateX(&B, 'K', 'Z');
     printf("setelah update K menjadi Z\n");
     PrintPrefix(B);
     printf("\n");
     printf("apakah ada elemen 'Z': %s\n", SearchX(B, 'Z') ? "true" : "false");
     printf("jumlah elemen 'T': %d\n", CountX(B, 'T'));
     printf("skew left? %s\n", IsSkewLeft(B) ? "true" : "false");
     printf("skew right? %s\n", IsSkewRight(B) ? "true" : "false");
     printf("prefix ringkas: ");
     PrintPrefixRingkas(B);
     printf("\n");
     printf("level dari elemen 'A': %d\n", LevelX(B, 'A'));
     printf("jumlah elemen pada level 3: %d\n", CountLevel(B, 3));
     printf("elemen pada level 3: ");
     PrintLevel(B, 3);
     printf("\n");
     printf("daun terkiri: %c\n", GetDaunTerkiri(B));
     printf("frekuensi elemen 'T': %.2f\n", FrekuensiX(B, 'T'));
     printf("jumlah elemen vokal: %d\n", CountVocal(B));
     PrintVocal(B);
     printf("\n");
     printf("jumlah elemen konsonan: %d\n", CountConsonant(B));
     PrintConsonant(B);
     printf("\n");
     printf("modus : %c\n", Modus(B));

     return 0;
}
