/* Program   : mtqueue3.c */
/* Deskripsi : aplikasi driver modul Queue model III */
/* NIM/Nama  : 24060124140161/Azka Wayasy Al Hafizh */
/* Tanggal   : 8 Oktober 2025 */
/***********************************/
#include <stdio.h>
#include "tqueue3.c"
#include "boolean.h"

int main()
{
    // kamus main
    tqueue3 Q1;
    tqueue3 Q2;
    char e;

    // algoritma
    createQueue3(&Q1);

    printf("halloooo\n");
    printf("Apakah Queue Q1 kosong? %s\n", isEmptyQueue3(Q1) ? "true" : "false");
    printf("Apakah Queue Q1 penuh? %s\n", isFullQueue3(Q1) ? "true" : "false");

    printf("enqeueue A\n");
    enqueue3(&Q1, 'A');
    printf("enqeueue B\n");
    enqueue3(&Q1, 'B');
    printf("enqeueue C\n");
    enqueue3(&Q1, 'C');
    printf("enqeue D \n");
    enqueue3(&Q1, 'D');

    printf("head Q1: %d\n", head3(Q1));
    printf("tail Q1: %d\n", tail3(Q1));
    printf("info head Q1: %c\n", infoHead3(Q1));
    printf("info tail Q1: %c\n", infoTail3(Q1));

    return 0;
}
