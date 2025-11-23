#include <stdio.h>
#include "queue.h"

int main()
{
    Queue Q;
    Proses P1, P2, P3, P4, P5;

    printf("PENJADWALAN PROSES DI CPU MENGGUNAKAN QUEUE\n");
    printf("Algoritma: SJF (Shortest Job First)\n");
    printf("NIM: 40161\n");
    printf("============================================\n");

    printf("\nPerhitungan Burst Time dari NIM (40161):\n");
    printf(" Digit 1: 4 --> BT Proses 1 = 4\n");
    printf(" Digit 2: 0 --> BT Proses 2 = 7 (digit sebelumnya 4 + 3)\n");
    printf(" Digit 3: 1 --> BT Proses 3 = 1\n");
    printf(" Digit 4: 6 --> BT Proses 4 = 6\n");
    printf(" Digit 5: 1 --> BT Proses 5 = 1\n");

    P1 = MakeProses('P', 4);
    P2 = MakeProses('P', 7);
    P3 = MakeProses('P', 1);
    P4 = MakeProses('P', 6);
    P5 = MakeProses('P', 1);

    CreateQueue(&Q);

    Enqueue(&Q, P1);
    Enqueue(&Q, P2);
    Enqueue(&Q, P3);
    Enqueue(&Q, P4);
    Enqueue(&Q, P5);

    PrintQueue(Q);
    ViewQueue(Q);

    SJFScheduling(Q);

    return 0;
}
