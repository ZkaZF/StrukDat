/* Program   : main.c */
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

    printf("Apakah Queue Q1 kosong? %s\n", isEmptyQueue3(Q1) ? "true" : "false");
    printf("Apakah Queue Q1 penuh? %s\n", isFullQueue3(Q1) ? "true" : "false");

    printf("Enqueue 'A', 'B', 'C' ke Q1\n");
    enqueue3(&Q1, 'A');
    enqueue3(&Q1, 'B');
    enqueue3(&Q1, 'C');

    printf("Apakah Queue Q1 kosong? %s\n", isEmptyQueue3(Q1) ? "true" : "false");
    printf("Apakah Queue Q1 penuh? %s\n", isFullQueue3(Q1) ? "true" : "false");
    printf("Size Q1: %d\n", sizeQueue3(Q1));
    printf("Info Head Q1: %c\n", infoHead3(Q1));
    printf("Info Tail Q1: %c\n", infoTail3(Q1));
    printf("Apakah hanya satu Element Q1: %s\n", isOneElement3(Q1) ? "true" : "false");

    printf("Print Queue Q1: ");
    printQueue3(Q1);
    printf("View Queue Q1: ");
    viewQueue3(Q1);

    printf("Dequeue dari Q1: ");
    dequeue3(&Q1, &e);
    printf("%c\n", e);
    printf("View Queue Q1: ");
    viewQueue3(Q1);

    printf("Enqueue 'D', 'E' ke Q1\n");
    enqueue3(&Q1, 'D');
    enqueue3(&Q1, 'E');
    printf("View Queue Q1: ");
    viewQueue3(Q1);

    printf("Dequeue dari Q1: ");
    dequeue3(&Q1, &e);
    printf("%c\n", e);
    printf("View Queue Q1: ");
    viewQueue3(Q1);

    printf("Enqueue 'F' ke Q1 (mungkin penuh)\n");
    enqueue3(&Q1, 'F');
    printf("View Queue Q1: ");
    viewQueue3(Q1);
    printf("Apakah tail over head? %s\n", isTailOverHead(Q1) ? "true" : "false");

    printf("Dequeue beberapa kali untuk test wrap\n");
    dequeue3(&Q1, &e);
    printf("Dequeued: %c\n", e);
    dequeue3(&Q1, &e);
    printf("Dequeued: %c\n", e);
    dequeue3(&Q1, &e);
    printf("Dequeued: %c\n", e);
    printf("View Queue Q1: ");
    viewQueue3(Q1);

    printf("Enqueue 'G', 'H', 'I', 'J' ke Q1\n");
    enqueue3(&Q1, 'G');
    enqueue3(&Q1, 'H');
    enqueue3(&Q1, 'I');
    enqueue3(&Q1, 'J');
    printf("View Queue Q1: ");
    viewQueue3(Q1);
    printf("Apakah tail over head? %s\n", isTailOverHead(Q1) ? "true" : "false");

    return 0;
}
