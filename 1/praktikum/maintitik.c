/************************************/
/* Program   : maintitik.c */
/* Deskripsi : aplikasi driver modul Titik */
/* NIM/Nama  : 24060124140161/Azka Wayasy Al Hafizh */
/* Tanggal   : 3 September 2025*/
/***********************************/
#include <stdio.h>
#include "titik.h"
#include "titik.c"

int main()
{
	// kamus main
	Titik T1;
	Titik T2;
	Titik T3;
	Titik T4;
	Titik T5;
	int A;

	// algoritma
	makeTitik(&T1, 4, 5);
	makeTitik(&T2, 4, 5);
	makeTitik(&T3, 0, 0);
	makeTitik(&T4, 5, 0);
	makeTitik(&T5, 0, 5);

	printf("Halo, ini driver modul Titik \n");

	printf("\nNilai absis = %d", getAbsis(T1));
	printf("\nNilai ordinat = %d", getOrdinat(T1));

	/*********PREDIKAT**********/
	// is equal
	printf("\nApakah T1 dan T2 sama? %s", isEqual(T1, T3) ? "true" : "false");

	// is origin
	printf("\nApakah T1 di origin? %s", isOrigin(T3) ? "true" : "false");

	// is on sumbu x
	printf("\nApakah T1 di sumbu X? %s", isOnSumbuX(T4) ? "true" : "false");

	// is on sumbu y
	printf("\nApakah T1 di sumbu Y? %s", isOnSumbuY(T5) ? "true" : "false");

	/*********SUBRUTIN LAIN*********/
	// geser
	printf("\nT1 sebelum digeser: (%d,%d)", getAbsis(T1), getOrdinat(T1));
	printf("\nMasukkan nilai x dan y untuk menggeser T1: ");
	scanf("%d %d", &A, &A);
	geser(&T1, A, A);
	printf("T1 setelah digeser: (%d,%d)", getAbsis(T1), getOrdinat(T1));

	// refleksi x
	printf("\nT1 sebelum direfleksi terhadap sumbu X: (%d,%d)", getAbsis(T1), getOrdinat(T1));
	refleksiX(&T1);
	printf("\nT1 setelah direfleksi terhadap sumbu X: (%d,%d)", getAbsis(T1), getOrdinat(T1));

	// refleksi y
	printf("\nT1 sebelum direfleksi terhadap sumbu Y: (%d,%d)", getAbsis(T1), getOrdinat(T1));
	refleksiY(&T1);
	printf("\nT1 setelah direfleksi terhadap sumbu Y: (%d,%d)", getAbsis(T1), getOrdinat(T1));
	return 0;
}
