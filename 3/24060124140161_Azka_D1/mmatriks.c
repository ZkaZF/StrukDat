/* Program   : mmatriks.c */
/* Deskripsi : driver ADT matriks integer */
/* NIM/Nama  : 24060124140161/Azka Wayasy Al Hafizh*/
/* Tanggal   : 17 September 2025*/
/***********************************/

#include <stdio.h>
#include "matriks.h"
#include "boolean.h"
#include "matriks.c"

int main()
{
	/*kamus*/
	Matriks M1, M2, M3, M4, M5;

	/*algoritma*/
	initMatriks(&M1);
	initMatriks(&M2);
	initMatriks(&M3);
	initMatriks(&M4);
	initMatriks(&M5);
	addX(&M1, 1, 1, 5);
	addX(&M1, 2, 2, 5);
	viewMatriks(M1);
	delX(&M1, 1);
	viewMatriks(M1);
	printf("apakah matriks kosong? %s\n", isEmptyMatriks(M1) ? "true" : "false");

	isiMatriksRandom(&M3, 10, 10);
	viewMatriks(M3);
	printf("apakah matriks penuh? %s\n", isFullMatriks(M3) ? "true" : "false");

	isiMatriksIdentitas(&M2, 5);
	viewMatriks(M2);

	// populateMatriks(&M1, 2, 3);
	viewMatriks(M1);

	printMatriks(M1);

	// tambah matriks
	printf("Matriks 1 :\n");
	isiMatriksRandom(&M3, 2, 2);
	viewMatriks(M3);
	printf("Ditambah\n");
	isiMatriksRandom(&M4, 2, 2);
	printf("Matriks 2 : \n");
	viewMatriks(M4);
	M5 = addMatriks(M3, M4);
	printf("Hasil : \n");
	viewMatriks(M5);

	// kurang matriks
	printf("Matriks 1 :\n");
	isiMatriksRandom(&M3, 2, 2);
	viewMatriks(M3);
	printf("Dikurang\n");
	isiMatriksRandom(&M4, 2, 2);
	printf("Matriks 2 : \n");
	viewMatriks(M4);
	M5 = subMatriks(M3, M4);
	printf("Hasil : \n");
	viewMatriks(M5);

	// kali matriks
	printf("Matriks 1 :\n");
	isiMatriksRandom(&M3, 2, 3);
	viewMatriks(M3);
	printf("Dikali\n");
	isiMatriksRandom(&M4, 3, 2);
	printf("Matriks 2 : \n");
	viewMatriks(M4);
	M5 = kaliMatriks(M3, M4);
	printf("Hasil : \n");
	viewMatriks(M5);

	// kali skalar matriks
	printf("Matriks 1 :\n");
	isiMatriksRandom(&M3, 2, 2);
	viewMatriks(M3);
	printf("Dikali skalar 5\n");
	M5 = kaliSkalarMatriks(M3, 5);
	printf("Hasil : \n");
	viewMatriks(M5);

	// transpose matriks
	printf("Matriks 1 :\n");
	isiMatriksRandom(&M3, 2, 3);
	viewMatriks(M3);
	printf("Transpose : \n");
	transposeMatriks(&M3);
	viewMatriks(M3);

	// get transpose matriks
	printf("Matriks 1 :\n");
	isiMatriksRandom(&M3, 2, 3);
	viewMatriks(M3);
	printf("Get Transpose : \n");
	M5 = getTransposeMatriks(M3);
	viewMatriks(M5);

	// add padding matriks
	printf("Matriks 1 :\n");
	isiMatriksRandom(&M3, 2, 3);
	viewMatriks(M3);
	printf("Add Padding 2 : \n");
	M5 = addPadding(M3, 2);
	viewMatriks(M5);

	// max pooling
	printf("Matriks 1 :\n");
	isiMatriksRandom(&M3, 4, 4);
	viewMatriks(M3);
	printf("Max Pooling size 2 : \n");
	M5 = maxPooling(M3, 2);
	viewMatriks(M5);

	// avg pooling
	printf("Matriks 1 :\n");
	isiMatriksRandom(&M3, 4, 4);
	viewMatriks(M3);
	printf("Avg Pooling size 2 : \n");
	M5 = avgPooling(M3, 2);
	viewMatriks(M5);

	// conv
	printf("Matriks 1 :\n");
	isiMatriksRandom(&M3, 4, 4);
	viewMatriks(M3);
	printf("Kernel : \n");
	isiMatriksRandom(&M4, 2, 2);
	viewMatriks(M4);
	printf("Convolution : \n");
	M5 = conv(M3, M4);
	viewMatriks(M5);

	// searchX
	printf("Matriks 1 :\n");
	isiMatriksRandom(&M3, 4, 4);
	viewMatriks(M3);
	int x = M3.cell[2][3];
	int row, col;
	searchX(M3, 3, &row, &col);
	printf("Nilai 3 ditemukan di baris: %d, kolom: %d\n", row, col);

	// countX
	printf("Matriks 1 :\n");
	isiMatriksRandom(&M3, 4, 4);
	viewMatriks(M3);
	int count = countX(M3, 5);
	printf("Jumlah 5 di matriks: %d\n", count);
}
