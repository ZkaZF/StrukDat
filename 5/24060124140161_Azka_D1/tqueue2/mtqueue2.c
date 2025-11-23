/* Program   : mtqueue2.c */
/* Deskripsi : aplikasi driver modul Queue model II */
/* NIM/Nama  : 24060124140161/Azka Wayasy Al Hafizh */
/* Tanggal   : 5 Oktober 2025*/
/***********************************/
#include <stdio.h>
#include "tqueue2.c"
#include "boolean.h"

int main()
{
    // kamus main
    tqueue2 Q1;
    tqueue2 Q2;
    tqueue2 Q3;
    char e;

    // algoritma
    createQueue2(&Q1);

    printf("Apakah Queue Q1 kosong? %s\n", isEmptyQueue2(Q1) ? "true" : "false");
    printf("Apakah Queue Q1 penuh? %s\n", isFullQueue2(Q1) ? "true" : "false");

    printf("Enqueue 'A', 'B', 'C' ke Q1\n");
    enqueue2(&Q1, 'A');
    enqueue2(&Q1, 'B');
    enqueue2(&Q1, 'C');

    printf("Apakah Queue Q1 kosong? %s\n", isEmptyQueue2(Q1) ? "true" : "false");
    printf("Apakah Queue Q1 penuh? %s\n", isFullQueue2(Q1) ? "true" : "false");
    printf("Size Q1: %d\n", sizeQueue2(Q1));
    printf("Info Head Q1: %c\n", infoHead2(Q1));
    printf("Info Tail Q1: %c\n", infoTail2(Q1));
    printf("Apakah hanya satu Element Q1: %s\n", isOneElement2(Q1) ? "true" : "false");

    printf("Print Queue Q1: ");
    printQueue2(Q1);
    printf("View Queue Q1: ");
    viewQueue2(Q1);

    printf("Dequeue dari Q1: ");
    dequeue2(&Q1, &e);
    printf("%c\n", e);
    printf("View Queue Q1: ");
    viewQueue2(Q1);

    printf("Enqueue 'D', 'E' ke Q1\n");
    enqueue2(&Q1, 'D');
    enqueue2(&Q1, 'E');
    printf("View Queue Q1: ");
    viewQueue2(Q1);

    printf("Dequeue dari Q1: ");
    dequeue2(&Q1, &e);
    printf("%c\n", e);
    printf("View Queue Q1: ");
    viewQueue2(Q1);

    createQueue2(&Q2);
    printf("\nTest enqueue2N untuk Q2\n");
    enqueue2N(&Q2, 3);
    printf("View Queue Q2: ");
    viewQueue2(Q2);

    printf("Dequeue dari Q2: ");
    dequeue2(&Q2, &e);
    printf("%c\n", e);
    printf("View Queue Q2: ");
    viewQueue2(Q2);

    printf("Apakah tail tidak dapat digeser? : %s\n", isTailStop(Q1) ? "true" : "false");

    printf("Test resetHead pada Q1\n");
    resetHead(&Q1);
    printf("View Queue Q1 setelah resetHead: ");
    viewQueue2(Q1);

    createQueue2(&Q3);
    enqueue2(&Q3, 'B');
    enqueue2(&Q3, 'C');
    enqueue2(&Q3, 'D');
    enqueue2(&Q3, 'E');

    printf("\nApakah Q1 dan Q3 sama? : %s\n", isEqualQueue2(Q1, Q3) ? "true" : "false");

    return 0;
}
