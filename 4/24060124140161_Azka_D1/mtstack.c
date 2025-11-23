/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : 24060124140161/Azka Wayasy Al Hafizh*/
/* Tanggal   : 24 September 2025*/
/***********************************/

#include <stdio.h>
#include "tstack.c"
#include "boolean.h"

int main()
{ /* kamus main */
	Tstack A;
	Tstack B;
	char kata[30];
	boolean Palindrom;
	int N;

	/* algoritma */
	createStack(&A);
	printf("apakah stack kosong? %s\n", isEmptyStack(A) ? "true" : "false");
	printf("apakah stack penuh? %s\n", isFullStack(A) ? "true" : "false");
	push(&A, 'A');
	push(&A, 'B');
	push(&A, 'C');
	push(&A, 'D');
	push(&A, 'E');
	printf("apakah stack kosong? %s\n", isEmptyStack(A) ? "true" : "false");
	printf("info top %c\n", infotop(A));
	printStack(A);
	char a;
	pop(&A, &a);
	printf("\nPop Char %c\n", a);
	printStack(A);
	printf("\n");
	viewStack(A);

	printf("Masukkan sebuah kata (maks. 30 karakter): ");
	scanf("%s", kata);

	Palindrom = isPalindrom(kata);

	if (Palindrom)
	{
		printf("Kata %s adalah palindrom\n", kata);
	}
	else
	{
		printf("Kata %s bukan palindrom\n", kata);
	}

	printf("Isi stack A dengan N karakter :\n");
	printf("Masukkan N (1..10) = ");
	scanf("%d", &N);
	createStack(&B);
	pushN(&B, N);
	printStack(B);
	printf("Apakah stack A kosong? %s\n", isEmptyStack(B) ? "true" : "false");
	printf("Apakah stack A penuh? %s\n", isFullStack(B) ? "true" : "false");
	printf("\n");
	return 0;
}
