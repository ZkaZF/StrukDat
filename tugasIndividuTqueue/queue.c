#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Proses MakeProses(char id, int bt)
{
    Proses p;
    p.IDProses = id;
    p.BurstTime = bt;
    return p;
}

void CreateQueue(Queue *Q)
{
    Q->head = 0;
    Q->tail = 0;
    for (int i = 1; i <= MAXQUEUE; i++)
    {
        Q->T[i].IDProses = ' ';
        Q->T[i].BurstTime = -1;
    }
}

boolean IsEmptyQueue(Queue Q)
{
    return Q.head == 0;
}

boolean IsFullQueue(Queue Q)
{
    return Q.tail == MAXQUEUE;
}

int Head(Queue Q)
{
    return Q.head;
}

int Tail(Queue Q)
{
    return Q.tail;
}

Proses InfoHead(Queue Q)
{
    if (!IsEmptyQueue(Q))
    {
        return Q.T[Q.head];
    }
    return (Proses){' ', -1};
}

Proses InfoTail(Queue Q)
{
    if (!IsEmptyQueue(Q))
    {
        return Q.T[Q.tail];
    }
    return (Proses){' ', -1};
}

void Enqueue(Queue *Q, Proses P)
{
    if (IsFullQueue(*Q))
        return;

    if (IsEmptyQueue(*Q))
    {
        Q->head = 1;
    }
    Q->tail++;
    Q->T[Q->tail] = P;
}

Proses Dequeue(Queue *Q)
{
    Proses P = (Proses){' ', -1};

    if (IsEmptyQueue(*Q))
        return P;

    P = Q->T[Q->head];

    for (int i = Q->head; i < Q->tail; i++)
    {
        Q->T[i] = Q->T[i + 1];
    }

    Q->T[Q->tail] = (Proses){' ', -1};
    Q->tail--;

    if (Q->tail == 0)
    {
        Q->head = 0;
    }

    return P;
}

void PrintQueue(Queue Q)
{
    for (int i = 1; i <= MAXQUEUE; i++)
    {
        printf("[%c, BT:%d] ", Q.T[i].IDProses, Q.T[i].BurstTime);
    }
    printf("\n");
}

void ViewQueue(Queue Q)
{
    printf("Banyak elemen: %d\n", Q.tail - Q.head + 1);
    printf("Head: %d, Tail: %d\n", Q.head, Q.tail);

    for (int i = Q.head; i <= Q.tail; i++)
    {
        printf("Proses %d: IDProses=%c, BurstTime=%d\n",
               i - Q.head + 1, Q.T[i].IDProses, Q.T[i].BurstTime);
    }
}

void SJFScheduling(Queue Q)
{
    if (IsEmptyQueue(Q))
    {
        printf("Queue kosong!\n");
        return;
    }

    Queue temp;
    CreateQueue(&temp);

    for (int i = Q.head; i <= Q.tail; i++)
    {
        Enqueue(&temp, Q.T[i]);
    }

    printf("\n=== SJF SCHEDULING ALGORITHM ===\n");
    printf("%-10s %-12s %-10s %-10s\n", "Proses", "Burst", "Mulai", "Selesai");
    printf("=====================================\n");

    int waktuSekarang = 0;
    int totalWaktu = 0;
    int jumlahProses = 0;
    int turnaround[MAXQUEUE];
    char proses_id[MAXQUEUE];

    while (!IsEmptyQueue(temp))
    {
        int idx_min = 0;
        int burst_min = temp.T[temp.head].BurstTime;

        for (int j = temp.head + 1; j <= temp.tail; j++)
        {
            if (temp.T[j].BurstTime < burst_min)
            {
                burst_min = temp.T[j].BurstTime;
                idx_min = j - temp.head;
            }
        }

        Proses proses_terpilih;

        if (idx_min == 0)
        {
            proses_terpilih = Dequeue(&temp);
        }
        else
        {
            proses_terpilih = temp.T[temp.head + idx_min];

            Queue newTemp;
            CreateQueue(&newTemp);
            for (int k = temp.head; k <= temp.tail; k++)
            {
                if (k != temp.head + idx_min)
                {
                    Enqueue(&newTemp, temp.T[k]);
                }
            }
            temp = newTemp;
        }

        int waktu_mulai = waktuSekarang;
        int waktu_selesai = waktuSekarang + proses_terpilih.BurstTime;
        waktuSekarang = waktu_selesai;

        printf("%-10c %-12d %-10d %-10d\n",
               proses_terpilih.IDProses, proses_terpilih.BurstTime,
               waktu_mulai, waktu_selesai);

        turnaround[jumlahProses] = waktu_selesai;
        proses_id[jumlahProses] = proses_terpilih.IDProses;
        totalWaktu += proses_terpilih.BurstTime;
        jumlahProses++;
    }

    printf("=====================================\n");
    printf("Total Burst Time: %d\n", totalWaktu);
    printf("Rata-rata Turnaround Time: %.2f\n",
           (float)waktuSekarang / jumlahProses);
    printf("Total Proses: %d\n", jumlahProses);
}