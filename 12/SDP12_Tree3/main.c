/* File : main.c */
/* Deskripsi : Driver untuk testing ADT bintree3 */
/* NIM & Nama : 24060124140161 - Azka Wayasy Al Hafizh*/
/* Tanggal : 10 Desember 2025*/
#include <stdio.h>
#include <stdlib.h>
#include "pohon3.h"

int main()
{
      // kamus
      bintree3 P, Q;
      int tinggi, level, count;

      // algoritma
      printf("===== TESTING BINTREE3 =====\n\n");

      // Membuat pohon dengan parent pointer
      // Struktur:     T
      //              / \
    //             I   R
      //            / \   \
    //           N   F   A
      //              /
      //             O

      P = Tree3(NIL, 'T', FALSE,
                Tree3(NIL, 'I', FALSE,
                      Tree3(NIL, 'N', FALSE, NIL, NIL),
                      Tree3(NIL, 'F', FALSE,
                            Tree3(NIL, 'O', FALSE, NIL, NIL),
                            NIL)),
                Tree3(NIL, 'R', FALSE,
                      NIL,
                      Tree3(NIL, 'A', FALSE, NIL, NIL)));

      // Test printDFS
      printf("1. Print DFS (Depth First Search):\n");
      printDFS(P);
      printf("\n\n");

      // Test PrintBFS
      printf("2. Print BFS (Breadth First Search):\n");
      PrintBFS(P);
      printf("\n\n");

      // Test Tinggi
      tinggi = Tinggi(P);
      printf("3. Tinggi pohon: %d\n\n", tinggi);

      // Test PrintLevel
      printf("4. Print per level:\n");
      printf("   Level 1: ");
      PrintLevel(P, 1);
      printf("\n   Level 2: ");
      PrintLevel(P, 2);
      printf("\n   Level 3: ");
      PrintLevel(P, 3);
      printf("\n   Level 4: ");
      PrintLevel(P, 4);
      printf("\n\n");

      // Test Predikat
      printf("5. Testing Predikat:\n");
      printf("   IsEmptyTree(P): %s\n", IsEmptyTree(P) ? "TRUE" : "FALSE");
      printf("   IsDaun(P): %s\n", IsDaun(P) ? "TRUE" : "FALSE");
      printf("   IsDaun(left(left(P))): %s (node N)\n", IsDaun(left(left(P))) ? "TRUE" : "FALSE");
      printf("   IsBiner(P): %s\n", IsBiner(P) ? "TRUE" : "FALSE");
      printf("   IsUnerLeft(P): %s\n", IsUnerLeft(P) ? "TRUE" : "FALSE");
      printf("   IsUnerRight(right(P)): %s (node R)\n\n", IsUnerRight(right(P)) ? "TRUE" : "FALSE");

      // Test NbElmTree
      printf("6. Jumlah elemen pohon: %d\n\n", NbElmTree(P));

      // Test NbDaun
      printf("7. Jumlah daun pohon: %d\n\n", NbDaun(P));

      // Test printPathX
      printf("8. Print path dari root ke node 'O':\n   ");
      printPathX(P, 'O');
      printf("\n");

      // Test printPathDaunX
      printf("9. Print path dari root ke daun 'N':\n   ");
      printPathDaunX(P, 'N');
      printf("\n");

      // Test printAllPaths
      printf("10. Print semua path dari root ke semua daun:\n");
      printAllPaths(P);
      printf("\n");

      // Test Level
      printf("11. Level dari setiap node:\n");
      printf("    Level node T (root): %d\n", Level(P));
      printf("    Level node I: %d\n", Level(left(P)));
      printf("    Level node F: %d\n", Level(right(left(P))));
      printf("    Level node O: %d\n", Level(left(right(left(P)))));
      printf("\n");

      // Test CountLevelT
      printf("12. Jumlah node per level:\n");
      printf("    Level 1: %d node\n", CountLevelT(P, 1));
      printf("    Level 2: %d node\n", CountLevelT(P, 2));
      printf("    Level 3: %d node\n", CountLevelT(P, 3));
      printf("    Level 4: %d node\n", CountLevelT(P, 4));
      printf("\n");

      // Test Max2
      printf("13. Max2(5, 8) = %d\n\n", Max2(5, 8));

      // Test resetVisited
      printf("14. Reset visited flag semua node...\n");
      visited(P) = TRUE;
      visited(left(P)) = TRUE;
      printf("    Sebelum reset - visited(P): %s\n", visited(P) ? "TRUE" : "FALSE");
      resetVisited(P);
      printf("    Setelah reset - visited(P): %s\n\n", visited(P) ? "TRUE" : "FALSE");

      // Test dengan pohon kosong
      printf("15. Testing dengan pohon kosong:\n");
      Q = NIL;
      printf("    IsEmptyTree(Q): %s\n", IsEmptyTree(Q) ? "TRUE" : "FALSE");
      printf("    Tinggi(Q): %d\n", Tinggi(Q));
      printf("    NbElmTree(Q): %d\n\n", NbElmTree(Q));

      // Test Linearisasi Pohon
      printf("16. Testing Linearisasi Pohon:\n");
      List1 LPrefix, LPosfix, LInfix, LBFS;

      printf("    a. Linear Prefix (Akar-Kiri-Kanan): ");
      LPrefix = LinearPrefix(P);
      PrintList(LPrefix);

      printf("    b. Linear Posfix (Kiri-Kanan-Akar): ");
      LPosfix = LinearPosfix(P);
      PrintList(LPosfix);

      printf("    c. Linear Infix (Kiri-Akar-Kanan): ");
      LInfix = LinearInfix(P);
      PrintList(LInfix);

      printf("    d. Linear Breadth First Search: ");
      LBFS = LinearBreadthFS(P);
      PrintList(LBFS);
      printf("\n");

      // Test Pconcat
      printf("17. Testing Pconcat (menyambung 2 list):\n");
      List1 L1, L2;
      CreateList(&L1);
      CreateList(&L2);
      InsertVLast(&L1, 'A');
      InsertVLast(&L1, 'B');
      InsertVLast(&L2, 'C');
      InsertVLast(&L2, 'D');
      printf("    List1 awal: ");
      PrintList(L1);
      printf("    List2: ");
      PrintList(L2);
      Pconcat(&L1, L2);
      printf("    List1 setelah Pconcat: ");
      PrintList(L1);
      printf("\n");

      // Test Fconcat
      printf("18. Testing Fconcat (concat tanpa ubah list asli):\n");
      List1 L3, L4, L5;
      CreateList(&L3);
      CreateList(&L4);
      InsertVLast(&L3, 'X');
      InsertVLast(&L3, 'Y');
      InsertVLast(&L4, 'Z');
      printf("    List3: ");
      PrintList(L3);
      printf("    List4: ");
      PrintList(L4);
      L5 = Fconcat(L3, L4);
      printf("    Hasil Fconcat: ");
      PrintList(L5);
      printf("    List3 masih: ");
      PrintList(L3);
      printf("\n");

      printf("===== TESTING SELESAI =====\n");

      return 0;
}