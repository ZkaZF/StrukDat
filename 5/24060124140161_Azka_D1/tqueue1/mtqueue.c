/* Program   : mtqueue.c */
/* Deskripsi : aplikasi driver modul Queue */
/* NIM/Nama  : 24060124140161/Azka Wayasy Al Hafizh */
/* Tanggal   : 5 Oktober 2025*/
/***********************************/
#include <stdio.h>
#include "tqueue.c"
#include "boolean.h"

int main()
{
    // kamus main
    tqueue Q1;
    tqueue Q2;
    char e;

    // algoritma
    createQueue(&Q1);

    printf("Apakah Queue Q1 kosong? %s\n", isEmptyQueue(Q1) ? "true" : "false");
    printf("Apakah Queue Q1 penuh? %s\n", isFullQueue(Q1) ? "true" : "false");

    printf("Enqueue 'A', 'B', 'C' ke Q1\n");
    enqueue(&Q1, 'A');
    enqueue(&Q1, 'B');
    enqueue(&Q1, 'C');

    printf("Apakah Queue Q1 kosong? %s\n", isEmptyQueue(Q1) ? "true" : "false");
    printf("Apakah Queue Q1 penuh? %s\n", isFullQueue(Q1) ? "true" : "false");
    printf("Size Q1: %d\n", sizeQueue(Q1));
    printf("Info Head Q1: %c\n", infoHead(Q1));
    printf("Info Tail Q1: %c\n", infoTail(Q1));
    printf("Apakah hanya satu Element Q1: %s\n", isOneElement(Q1) ? "true" : "false");

    printf("Print Queue Q1: ");
    printQueue(Q1);
    printf("View Queue Q1: ");
    viewQueue(Q1);

    printf("Dequeue dari Q1: ");
    dequeue(&Q1, &e);
    printf("%c\n", e);
    printf("View Queue Q1: ");
    viewQueue(Q1);

    printf("Enqueue 'D', 'E' ke Q1\n");
    enqueue(&Q1, 'D');
    enqueue(&Q1, 'E');
    printf("View Queue Q1: ");
    viewQueue(Q1);

    printf("Dequeue dari Q1: ");
    dequeue(&Q1, &e);
    printf("%c\n", e);
    printf("View Queue Q1: ");
    viewQueue(Q1);

    createQueue(&Q2);
    printf("\nTest enqueue2 dan dequeue2\n");
    enqueue2(&Q1, &Q2, 'F');
    enqueue2(&Q1, &Q2, 'G');
    enqueue2(&Q1, &Q2, 'H');
    enqueue2(&Q1, &Q2, 'I');
    printf("Q1: ");
    viewQueue(Q1);
    printf("Q2: ");
    viewQueue(Q2);

    printf("Dequeue2: ");
    dequeue2(&Q1, &Q2, &e);
    printf("%c\n", e);
    printf("Q1: ");
    viewQueue(Q1);
    printf("Q2: ");
    viewQueue(Q2);

    return 0;
}
