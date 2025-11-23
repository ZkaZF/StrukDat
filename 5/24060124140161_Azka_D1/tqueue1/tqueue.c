/* Program   : tqueue.c */
/* Deskripsi : realisasi body modul Queue */
/* NIM/Nama  : 24060124140161/Azka Wayasy Al Hafizh */
/* Tanggal   : 5 Oktober 2025*/
/***********************************/
#include <stdio.h>
#include "tqueue.h"
#include "boolean.h"

/*procedure createQueue ( output Q:tQueue)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi elemen dengan huruf '-', head=tail=0 }*/
void createQueue(tqueue *Q)
{
    int i;
    for (i = 1; i <= 5; i++)
    {
        (*Q).wadah[i] = '-';
    }
    (*Q).head = 0;
    (*Q).tail = 0;
}

/*function infoHead(Q:tQueue)-> character
{mengembalikan nilai elemen terdepan antrian Q} */
/*pikirkan bila antrian kosong*/
int infoHead(tqueue Q)
{
    if (isEmptyQueue(Q))
    {
        return '-';
    }
    else
    {
        return Q.wadah[Q.head];
    }
}

/*function infoTail(Q:tQueue)-> character
{mengembalikan nilai elemen terakhir antrian Q} */
/*pikirkan bila antrian kosong*/
int infoTail(tqueue Q)
{
    if (isEmptyQueue(Q))
    {
        return '-';
    }
    else
    {
        return Q.wadah[Q.tail];
    }
}

/*function sizeQueue(Q:tQueue)-> integer
{mengembalikan panjang antrian Q} */
int sizeQueue(tqueue Q)
{
    if (isEmptyQueue(Q))
    {
        return 0;
    }
    else
    {
        return Q.tail - Q.head + 1;
    }
}

/*procedure printQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua elemen wadah ke layar}*/
void printQueue(tqueue Q)
{
    int i;
    for (i = 1; i <= 5; i++)
    {
        printf("%c", Q.wadah[i]);
        if (i < 5)
        {
            printf(",");
        }
    }
    printf("\n");
}

/*procedure viewQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen tak kosong ke layar}*/
void viewQueue(tqueue Q)
{
    int i;
    if (!isEmptyQueue(Q))
    {
        for (i = Q.head; i <= Q.tail; i++)
        {
            printf("%c", Q.wadah[i]);
            if (i < Q.tail)
            {
                printf(",");
            }
        }
        printf("\n");
    }
}

/*function isEmptyQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue(tqueue Q)
{
    return Q.head == 0;
}

/*function isFullQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue(tqueue Q)
{
    return Q.tail == 5;
}

/*function isOneElement(Q:tQueue) -> boolean
{mengembalikan true jika hanya ada 1 elemen }*/
boolean isOneElement(tqueue Q)
{
    return Q.head == Q.tail && Q.head != 0;
}

/*procedure enqueue( input/output Q:tQueue, input e: character )
{I.S.: Q dan e terdefinisi}
{F.S.: elemen wadah Q bertambah 1, bila belum penuh}
{proses: menambah elemen wadah Q } */
void enqueue(tqueue *Q, char e)
{
    if (!isFullQueue(*Q))
    {
        if (isEmptyQueue(*Q))
        {
            (*Q).head = 1;
        }
        (*Q).tail++;
        (*Q).wadah[(*Q).tail] = e;
    }
}

/*procedure deQueue( input/output Q:tQueue, output e: character )
{I.S.: }
{F.S.: e=infohead(Q) atau e='-' bila Q kosong, elemen wadah Q berkurang 1 }
{proses: mengurangi elemen wadah Q, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail menjadi 0 } */
void dequeue(tqueue *Q, char *e)
{
    int i;
    if (!isEmptyQueue(*Q))
    {
        *e = (*Q).wadah[(*Q).head];
        for (i = (*Q).head; i < (*Q).tail; i++)
        {
            (*Q).wadah[i] = (*Q).wadah[i + 1];
        }
        (*Q).wadah[(*Q).tail] = '-';
        (*Q).tail--;
        if ((*Q).tail == 0)
        {
            (*Q).head = 0;
        }
    }
    else
    {
        *e = '-';
    }
}

/*tambahan, dikerjakan bila cukup waktu */

/*procedure enqueue2( input/output Q1:tQueue, input/output Q2:tQueue, input e: character )
{I.S.: e terdefinisi}
{F.S.: elemen wadah Q1 atau Q2 bertambah 1, bila belum penuh}
{proses: menambah elemen wadah pada antrian terpendek dari Q1 atau Q2} */
void enqueue2(tqueue *Q1, tqueue *Q2, char e)
{
    if (sizeQueue(*Q1) <= sizeQueue(*Q2))
    {
        enqueue(Q1, e);
    }
    else
    {
        enqueue(Q2, e);
    }
}

/*procedure dequeue2( input/output Q1:tQueue, input/output Q2:tQueue, output e: character )
{I.S.: }
{F.S.: e=infohead Q1 atau Q2 atau e='-' bila Q1 dan Q2 kosong, elemen wadah Q1 atau Q2 berkurang 1 }
{proses: mengurangi elemen wadah antrian terpanjang Q1 atau Q2, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail antrian menjadi 0 } */
void dequeue2(tqueue *Q1, tqueue *Q2, char *e)
{
    if (sizeQueue(*Q1) >= sizeQueue(*Q2))
    {
        dequeue(Q1, e);
    }
    else
    {
        dequeue(Q2, e);
    }
}
