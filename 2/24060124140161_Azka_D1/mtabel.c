#include <stdio.h>
#include "tabel.h"
#include "tabel.c"
/*Deskripsi : driver ADT tabel integer */
/* NIM/Nama : 24060124140161/Azka Wayasy Al Hafizh*/
/* Tanggal : 10 September 2025*/

int main()
{
	/*kamus*/
	Tabel T1;
	Tabel T2;

	/*algoritma*/
	createTable(&T1);
	createTable(&T2);
	printf("apakah tabel kosong? %s\n", isEmptyTable(T1) ? "true" : "false");
	addXTable(&T1, 'A');
	addXTable(&T1, 'B');
	addXTable(&T1, 'B');
	addXTable(&T1, 'C');
	addXTable(&T1, 'D');
	addXTable(&T1, 'E');
	addXTable(&T1, 'F');
	addXTable(&T1, 'G');
	printTable(T1);
	printf("apakah tabel kosong? %s\n", isEmptyTable(T1) ? "true" : "false");
	printf("ukuran tabel ini adalah :  %d\n", getSize(T1));
	printf("%s\n", isEmptyTable(T1) ? "true" : "false");
	printf("%s\n", isFullTable(T1) ? "true" : "false");
	int pos, count;
	searchX(T1, 'E', &pos);
	printf("apakah ada huruf E di tabel? %d\n", pos);
	searchX(T1, 'K', &pos);
	printf("apakah ada huruf K di tabel? %d\n", pos);
	printf("Jumlah huruf A di tabel: %d\n", countX(T1, 'A'));
	printf("Jumlah huruf vokal di tabel: %d\n", countVocal(T1));
	addUniqueXTable(&T1, 'A');
	printTable(T1);
	addUniqueXTable(&T1, 'H');
	printTable(T1);
	delXTable(&T1, 'A');
	addXTable(&T1, 'H');
	printTable(T1);
	delAllXTable(&T1, 'H');
	printTable(T1);
	delTable(&T1, 3);
	printTable(T1);
	viewTable(T1);
	// populateTable(&T1, 3);
	// printTable(T1);
	// viewTable(T1);
	printf("Modus dari tabel adalah: %c\n", Modus(T1));
	printf("apakah tabel sama? %s\n", isEqualTable(T1, T2) ? "true" : "false");
	inverseTable(&T1);
	printTable(T1);
	Tabel T3 = getInverseTable(T1);
	printTable(T3);
	sortAsc(&T1);
	printTable(T1);
	sortDesc(&T1);
	printTable(T1);


	return 0;
}
