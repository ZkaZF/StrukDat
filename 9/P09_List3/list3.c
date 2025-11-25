/* File : list3.c */
/* Deskripsi : realisasi body ADT list berkait ganda representasi fisik pointer */
/* NIM & Nama : 24060124140161/Azka Wayasy Al Hafizh */
/* Tanggal : 20 November 2025 */
#include "list3.h"
#include <stdlib.h>
#include <stdio.h>

/*OPERATOR ALOKASI*/
/****************** Manajemen Memori ******************/
/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E)
{
    address P = (address)malloc(sizeof(Elm));
    if (P != NIL)
    {
        info(P) = E;
        prev(P) = NIL;
        next(P) = NIL;
    }
    return P;
}

/* procedure Dealokasi (input/output P:address) */
/* {I.S. P terdefinisi
    F.S. P dikembalikan ke sistem
    Proses: Melakukan pengembalian address P} */
void Dealokasi(address *P)
{
    free(*P);
    *P = NIL;
}

/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List3)
   {I.S.: - ; F.S.: L list kosong}
   {proses: membuat list kosong}*/
void CreateList(List3 *L)
{
    First(*L) = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List3) --> boolean
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList(List3 L)
{
    return First(L) == NIL;
}

/*PENELUSURAN*/
/*procedure PrintList(input L:List3)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan semua elemen list L} */
void PrintList(List3 L)
{
    address P = First(L);
    while (P != NIL)
    {
        printf("%c ", info(P));
        P = next(P);
    }
    printf("\n");
}

/*function NbElm(L:List3) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List3 L)
{
    int count = 0;
    address P = First(L);
    while (P != NIL)
    {
        count++;
        P = next(P);
    }
    return count;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List3 *L, infotype V)
{
    address P = Alokasi(V);
    if (P != NIL)
    {
        next(P) = First(*L);
        if (First(*L) != NIL)
        {
            prev(First(*L)) = P;
        }
        First(*L) = P;
    }
}

/*Procedure InsertVLast(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List3 *L, infotype V)
{
    address P = Alokasi(V);
    if (P != NIL)
    {
        if (IsEmptyList(*L))
        {
            First(*L) = P;
        }
        else
        {
            address last = First(*L);
            while (next(last) != NIL)
            {
                last = next(last);
            }
            next(last) = P;
            prev(P) = last;
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List3, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List3 *L, infotype *V)
{
    if (!IsEmptyList(*L))
    {
        address P = First(*L);
        *V = info(P);
        First(*L) = next(P);
        if (First(*L) != NIL)
        {
            prev(First(*L)) = NIL;
        }
        Dealokasi(&P);
    }
    else
    {
        *V = '#';
    }
}

/*Procedure DeleteVLast(input/output L:List3, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List3 *L, infotype *V)
{
    if (!IsEmptyList(*L))
    {
        address last = First(*L);
        while (next(last) != NIL)
        {
            last = next(last);
        }
        *V = info(last);
        if (prev(last) != NIL)
        {
            next(prev(last)) = NIL;
        }
        else
        {
            First(*L) = NIL;
        }
        Dealokasi(&last);
    }
    else
    {
        *V = '#';
    }
}

/*Procedure DeleteX(input/output L:List3, input X:infotype)
{ I.S. List L terdefinisi }
{ F.S. List mungkin menjadi kosong, atau berkurang 1 elemen. }
{ Proses: Elemen bernilai X dihapus, dan didealokasi. }*/
void DeleteX(List3 *L, infotype X)
{
    address P = First(*L);
    while (P != NIL && info(P) != X)
    {
        P = next(P);
    }
    if (P != NIL)
    {
        if (prev(P) != NIL)
        {
            next(prev(P)) = next(P);
        }
        else
        {
            First(*L) = next(P);
        }
        if (next(P) != NIL)
        {
            prev(next(P)) = prev(P);
        }
        Dealokasi(&P);
    }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List3, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X. }
{ Proses : Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List3 L, infotype X, address *A)
{
    *A = First(L);
    while (*A != NIL && info(*A) != X)
    {
        *A = next(*A);
    }
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List3, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.}
{ Proses : Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List3 *L, infotype X, infotype Y)
{
    address P = First(*L);
    while (P != NIL)
    {
        if (info(P) == X)
        {
            info(P) = Y;
        }
        P = next(P);
    }
}

/*Procedure Invers(input/output L:List3)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {3,5,6} menjadi {6,5,3} }*/
void Invers(List3 *L)
{
    address current = First(*L);
    address prevNode = NIL;
    address nextNode;
    while (current != NIL)
    {
        nextNode = next(current);
        next(current) = prevNode;
        prev(current) = nextNode;
        prevNode = current;
        current = nextNode;
    }
    First(*L) = prevNode;
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*Procedure InsertVAfterX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List3 *L, infotype X, infotype V)
{
    address P = First(*L);
    while (P != NIL && info(P) != X)
    {
        P = next(P);
    }
    if (P != NIL)
    {
        address Q = Alokasi(V);
        if (Q != NIL)
        {
            next(Q) = next(P);
            prev(Q) = P;
            if (next(P) != NIL)
            {
                prev(next(P)) = Q;
            }
            next(P) = Q;
        }
    }
}

/*Procedure InsertVBeforeX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List3 *L, infotype X, infotype V)
{
    address P = First(*L);
    while (P != NIL && info(P) != X)
    {
        P = next(P);
    }
    if (P != NIL)
    {
        address Q = Alokasi(V);
        if (Q != NIL)
        {
            prev(Q) = prev(P);
            next(Q) = P;
            if (prev(P) != NIL)
            {
                next(prev(P)) = Q;
            }
            else
            {
                First(*L) = Q;
            }
            prev(P) = Q;
        }
    }
}

/*Procedure DeleteVAfterX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List3 *L, infotype X, infotype *V)
{
    address P = First(*L);
    while (P != NIL && info(P) != X)
    {
        P = next(P);
    }
    if (P != NIL && next(P) != NIL)
    {
        address Q = next(P);
        *V = info(Q);
        next(P) = next(Q);
        if (next(Q) != NIL)
        {
            prev(next(Q)) = P;
        }
        Dealokasi(&Q);
    }
    else
    {
        *V = '#';
    }
}

/*Procedure DeleteVBeforeX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List3 *L, infotype X, infotype *V)
{
    address P = First(*L);
    while (P != NIL && info(P) != X)
    {
        P = next(P);
    }
    if (P != NIL && prev(P) != NIL)
    {
        address Q = prev(P);
        *V = info(Q);
        if (prev(Q) != NIL)
        {
            next(prev(Q)) = P;
        }
        else
        {
            First(*L) = P;
        }
        prev(P) = prev(Q);
        Dealokasi(&Q);
    }
    else
    {
        *V = '#';
    }
}

/*function CountX(L:List3, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List3 L, infotype X)
{
    int count = 0;
    address P = First(L);
    while (P != NIL)
    {
        if (info(P) == X)
        {
            count++;
        }
        P = next(P);
    }
    return count;
}

/*function FrekuensiX(L:List3, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List3 L, infotype X)
{
    int total = NbElm(L);
    if (total == 0)
        return 0.0;
    return (float)CountX(L, X) / total;
}

/*function MaxMember(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List3 L)
{
    int max = 0;
    for (char c = 'A'; c <= 'Z'; c++)
    {
        int count = CountX(L, c);
        if (count > max)
            max = count;
    }
    for (char c = 'a'; c <= 'z'; c++)
    {
        int count = CountX(L, c);
        if (count > max)
            max = count;
    }
    return max;
}

/*function Modus(L:List3) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List3 L)
{
    char modus = '#';
    int max = 0;
    for (char c = 'A'; c <= 'Z'; c++)
    {
        int count = CountX(L, c);
        if (count > max)
        {
            max = count;
            modus = c;
        }
    }
    for (char c = 'a'; c <= 'z'; c++)
    {
        int count = CountX(L, c);
        if (count > max)
        {
            max = count;
            modus = c;
        }
    }
    return modus;
}

/*function CountVocal(L:List3) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List3 L)
{
    int count = 0;
    address P = First(L);
    while (P != NIL)
    {
        char c = info(P);
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
            c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            count++;
        }
        P = next(P);
    }
    return count;
}

/*function CountNG(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List3 L)
{
    int count = 0;
    address P = First(L);
    while (P != NIL && next(P) != NIL)
    {
        if (info(P) == 'N' && info(next(P)) == 'G')
        {
            count++;
        }
        P = next(P);
    }
    return count;
}

/*Procedure SearchAllX(input L:List3, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. - }
{ Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List3 L, infotype X)
{
    address P = First(L);
    int pos = 1;
    boolean found = false;
    while (P != NIL)
    {
        if (info(P) == X)
        {
            printf("%d ", pos);
            found = true;
        }
        P = next(P);
        pos++;
    }
    if (!found)
    {
        printf("0");
    }
    printf("\n");
}

/*Procedure DeleteAllX(input/output L:List3, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. List mungkin menjadi kosong. }
{ Proses: Semua elemen bernilai X dihapus, dan didealokasi. }*/
void DeleteAllX(List3 *L, infotype X)
{
    address P = First(*L);
    while (P != NIL)
    {
        if (info(P) == X)
        {
            P = next(P);
            DeleteX(L, X);
        }
        else
        {
            P = next(P);
        }
    }
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List3, input L2:List3, output L:List3)
{I.S.: L1,L2 terdefinisi ;
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List3 L1, List3 L2, List3 *L)
{
    CreateList(L);
    address P = First(L1);
    while (P != NIL)
    {
        InsertVLast(L, info(P));
        P = next(P);
    }
    P = First(L2);
    while (P != NIL)
    {
        InsertVLast(L, info(P));
        P = next(P);
    }
}

/*Procedure SplitList(input L:List3, output L1:List3, output L2:List3)
{I.S.: L terdefinisi ;
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List3 L, List3 *L1, List3 *L2)
{
    CreateList(L1);
    CreateList(L2);
    address P = First(L);
    int count = 0;
    while (P != NIL)
    {
        if (count % 2 == 0)
        {
            InsertVLast(L1, info(P));
        }
        else
        {
            InsertVLast(L2, info(P));
        }
        P = next(P);
        count++;
    }
}

/*Procedure CopyList(input L1:List3, output L2:List3)
{I.S.: L1 terdefinisi;
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List3 L1, List3 *L2)
{
    CreateList(L2);
    address P = First(L1);
    while (P != NIL)
    {
        InsertVLast(L2, info(P));
        P = next(P);
    }
}