#ifndef QUEUE_H
#define QUEUE_H

#include "boolean.h"

typedef struct {
    char IDProses;
    int BurstTime;
} Proses;

#define MAXQUEUE 5

typedef struct {
    Proses T[MAXQUEUE+1];
    int head;
    int tail;
} Queue;

Proses MakeProses(char id, int bt);

void CreateQueue(Queue *Q);

boolean IsEmptyQueue(Queue Q);

boolean IsFullQueue(Queue Q);

int Head(Queue Q);

int Tail(Queue Q);

Proses InfoHead(Queue Q);

Proses InfoTail(Queue Q);

void Enqueue(Queue *Q, Proses P);

Proses Dequeue(Queue *Q);

void PrintQueue(Queue Q);

void ViewQueue(Queue Q);

void SJFScheduling(Queue Q);

#endif
