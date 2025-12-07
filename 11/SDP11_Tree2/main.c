/* File : main.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060124140161 - Azka Wayasy Al Hafizh*/
/* Tanggal : 3 Desember 2025 */

#include "pohon2.h"

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

     PrintTreeInden(B, 1);
     printf("\n");
     printf("Update All T to X:\n");
     UpdateAllX(&B, 'T', 'X');
     PrintTreeInden(B, 1);
     printf("\n");
     printf("Add Daun Terkiri with Z:\n");
     AddDaunTerkiri(B, 'Z');
     printf("\n");
     PrintTreeInden(B, 1);
     printf("\n");
     printf("Add Daun Y to Daun F di kanan:\n");
     AddDaun(B, 'F', 'Y', FALSE);
     printf("\n");
     PrintTreeInden(B, 1);
     printf("\n");
     printf("Insert X:\n");
     InsertX(&B, 'X');
     PrintTreeInden(B, 1);
     printf("\n");
     printf("Delete Daun Terkiri:\n");
     DelDaunTerkiri(&B, 'X');
     PrintTreeInden(B, 1);
     printf("\n");
     printf("Delete Daun A:\n");
     DelDaun(&B, 'A');
     PrintTreeInden(B, 1);
     printf("\n");
     printf("Delete node R:\n");
     DeleteX(&B, 'R');
     PrintTreeInden(B, 1);
     printf("\n");

     printf("Build Balance Tree dengan 7 node:\n");
     A = BuildBalanceTree(7);
     PrintTreeInden(A, 1);
     printf("\n");
     printf("Apakah A balance tree? %s\n", IsBalanceTree(A) ? "True" : "False");
     printf("Karakter maksimal di tree A: %c\n", maxTree(A));
     printf("Karakter minimal di tree A: %c\n\n", minTree(A));

     bintree BST = NIL;
     BST = InsSearch(BST, 'M');
     BST = InsSearch(BST, 'D');
     BST = InsSearch(BST, 'S');
     BST = InsSearch(BST, 'B');
     BST = InsSearch(BST, 'G');
     BST = InsSearch(BST, 'P');
     BST = InsSearch(BST, 'Z');
     printf("BST setelah insert M,D,S,B,G,P,Z:\n");
     PrintTreeInden(BST, 1);
     printf("\n");
     printf("Cari 'G' di BST: %s\n", BSearch(BST, 'G') ? "Ditemukan" : "Tidak ditemukan");
     printf("Cari 'X' di BST: %s\n", BSearch(BST, 'X') ? "Ditemukan" : "Tidak ditemukan");
     printf("\n");
     printf("Delete 'D' dari BST:\n");
     DelBtree(&BST, 'D');
     PrintTreeInden(BST, 1);
     printf("\n");

     return 0;
}
