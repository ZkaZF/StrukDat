/* File : list2.c */
/* Deskripsi : realisasi body ADT list berkait sirkular representasi fisik pointer */
/* NIM & Nama :24060124140161_Azka Wayasy Al Hafizh */
/* Tanggal : 12 November 2025 */
#include "list2.h"
#include <stdlib.h>
#include <stdio.h>
#include "boolean.h"

/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E} */
address Alokasi(infotype E)
{
    // kamus lokal
    address P;
    // algoritma
    P = (address)malloc(sizeof(Elm)); // casting
    if (P != NULL)
    {
        info(P) = E;
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
    // kamus lokal

    // algoritma
    if (*P != NIL)
    {
        next(*P) = NIL;
    }
    free(*P);
    *P = NIL;
}

/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List2)
   {I.S.: - ; F.S.: L list kosong}
   {proses: membuat list kosong}*/
void CreateList(List2 *L)
{
    First(*L) = NIL;
}

/****************** TEST KONDISI LIST ******************/
/* function IsEmptyList(L:List2) --> boolean
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList(List2 L)
{
    return (First(L) == NIL);
}

/* function IsOneElm(L:List2) --> boolean
   {mengembalikan true bila list L hanya punya satu elemen} */
boolean IsOneElm(List2 L)
{
    return (First(L) != NIL && next(First(L)) == NIL);
}

/*********** PENELUSURAN ***********/
/*procedure PrintList(input L:List2)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen list L} */
void PrintList(List2 L)
{
    // kamus lokal
    address P;
    // algoritma
    P = First(L);
    if (P != NIL)
    {
        address start = P;
        do
        {
            printf("%c ", info(P));
            P = next(P);
        } while (P != start);
    }
}

/*function NbElm(L:List2) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List2 L)
{
    // kamus lokal
    address P;
    int count = 0;
    // algoritma
    P = First(L);
    while (P != NIL)
    {
        count = count + 1;
        P = next(P);
    }
    return count;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List2 *L, infotype V)
{
    // Kamus lokal
    address last;
    address P;

    // Algoritma
    P = Alokasi(V);
    if (IsEmptyList(*L))
    {
        First(*L) = P;
        next(P) = First(*L);
    }
    else
    {
        last = First(*L);
        do
        {
            last = next(last);
        } while (next(last) != First(*L));
        next(P) = First(*L);
        First(*L) = P;
        next(last) = P;
    }
}

/*Procedure InsertVLast(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V, next(P)=First(L)}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List2 *L, infotype V)
{
    // Kamus lokal
    address last;
    address P;

    // Algoritma
    P = Alokasi(V);
    if (IsEmptyList(*L))
    {
        First(*L) = P;
        next(P) = First(*L);
    }
    else
    {
        last = First(*L);
        do
        {
            last = next(last);
        } while (next(last) != First(*L));
        next(last) = P;
        next(P) = First(*L);
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen pertama list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List2 *L, infotype *V)
{
    // kamus lokal
    address P;
    address last;
    // algoritma
    if (!IsEmptyList(*L))
    {
        P = First(*L);
        *V = info(P);
        if (next(P) == First(*L))
        {
            First(*L) = NIL;
        }
        else
        {
            last = First(*L);
            do
            {
                last = next(last);
            } while (next(last) != First(*L));
            First(*L) = next(P);
            next(last) = First(*L);
        }
        Dealokasi(&P);
    }
    else
    {
        *V = '#';
    }
}

/*Procedure DeleteVLast(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List2 *L, infotype *V)
{
    // kamus lokal
    address P;
    address last;
    address beforeLast;
    // algoritma
    if (!IsEmptyList(*L))
    {
        last = First(*L);
        beforeLast = NIL;
        while (next(last) != First(*L))
        {
            beforeLast = last;
            last = next(last);
        }
        P = last;
        *V = info(P);
        if (beforeLast == NIL)
        {
            First(*L) = NIL;
        }
        else
        {
            next(beforeLast) = First(*L);
        }
        Dealokasi(&P);
    }
    else
    {
        *V = '#';
    }
}

/*Procedure DeleteX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Elemen bernilai X dihapus, dan didealokasi.
List mungkin menjadi kosong. }*/
void DeleteX(List2 *L, infotype X)
{
    // kamus lokal
    address P;
    address beforeP;
    // algoritma
    if (!IsEmptyList(*L))
    {
        P = First(*L);
        beforeP = NIL;
        do
        {
            if (info(P) == X)
            {
                if (beforeP == NIL)
                {
                    DeleteVFirst(L, &X);
                    P = First(*L);
                }
                else
                {
                    next(beforeP) = next(P);
                    if (P == First(*L))
                    {
                        First(*L) = next(P);
                    }
                    Dealokasi(&P);
                    P = next(beforeP);
                }
            }
            else
            {
                beforeP = P;
                P = next(P);
            }
        } while (P != First(*L) && P != NIL);
    }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List2, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List2 L, infotype X, address *A)
{
    // kamus lokal
    address P;
    boolean found;
    // algoritma
    P = First(L);
    found = false;
    *A = NIL;
    if (P != NIL)
    {
        address start = P;
        do
        {
            if (info(P) == X)
            {
                *A = P;
                found = true;
                break;
            }
            P = next(P);
        } while (P != start);
    }
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List2, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List2 *L, infotype X, infotype Y)
{
    // kamus lokal
    address P;
    // algoritma
    P = First(*L);
    if (P != NIL)
    {
        address start = P;
        do
        {
            if (info(P) == X)
            {
                info(P) = Y;
            }
            P = next(P);
        } while (P != start);
    }
}

/*Procedure Invers(input/output L:List2)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik,
misal {'A','B','C'} menjadi {'C','B','A'} }*/
void Invers(List2 *L)
{
    // kamus lokal
    address prev, current, nextNode, start, last;
    // algoritma
    if (!IsEmptyList(*L) && !IsOneElm(*L))
    {
        prev = NIL;
        current = First(*L);
        start = First(*L);
        last = First(*L);
        do
        {
            last = next(last);
        } while (next(last) != First(*L));
        do
        {
            nextNode = next(current);
            next(current) = prev;
            prev = current;
            current = nextNode;
        } while (current != start);
        next(start) = prev;
        First(*L) = prev;
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*function CountX(L:List2, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List2 L, infotype X)
{
    // kamus lokal
    address P;
    int count = 0;
    // algoritma
    P = First(L);
    if (P != NIL)
    {
        address start = P;
        do
        {
            if (info(P) == X)
            {
                count = count + 1;
            }
            P = next(P);
        } while (P != start);
    }
    return count;
}

/*function FrekuensiX(L:List2, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List2 L, infotype X)
{
    // kamus lokal
    int countX;
    int totalElm;
    float frequency;
    // algoritma
    totalElm = NbElm(L);
    if (totalElm == 0)
    {
        return 0.0;
    }
    countX = CountX(L, X);
    frequency = (float)countX / (float)totalElm;
    return frequency;
}

/*function CountVocal(L:List2) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List2 L)
{
    // kamus lokal
    address P;
    int count = 0;
    // algoritma
    P = First(L);
    if (P != NIL)
    {
        address start = P;
        do
        {
            if (info(P) == 'A' || info(P) == 'E' || info(P) == 'I' || info(P) == 'O' || info(P) == 'U' ||
                info(P) == 'a' || info(P) == 'e' || info(P) == 'i' || info(P) == 'o' || info(P) == 'u')
            {
                count = count + 1;
            }
            P = next(P);
        } while (P != start);
    }
    return count;
}

/*function CountNG(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List2 L)
{
    // kamus lokal
    address P;
    int count = 0;
    // algoritma
    P = First(L);
    if (P != NIL)
    {
        address start = P;
        do
        {
            if (info(P) == 'N' && info(next(P)) == 'G')
            {
                count = count + 1;
            }
            P = next(P);
        } while (P != start);
    }
    return count;
}

/*Procedure InsertVAfterX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List2 *L, infotype X, infotype V)
{
    // kamus lokal
    address P, Q;
    // algoritma
    P = First(*L);
    if (P != NIL)
    {
        address start = P;
        do
        {
            if (info(P) == X)
            {
                Q = Alokasi(V);
                next(Q) = next(P);
                next(P) = Q;
                if (next(Q) == First(*L))
                {
                    next(Q) = First(*L);
                }
                break;
            }
            P = next(P);
        } while (P != start);
    }
}

/*Procedure InsertVBeforeX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List2 *L, infotype X, infotype V);

/*Procedure DeleteVAfterX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List2 *L, infotype X, infotype *V);

/*Procedure DeleteVBeforeX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List2 *L, infotype X, infotype *V);

/*Procedure DeleteAllX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Semua elemen bernilai X dihapus, dan didealokasi.
List mungkin menjadi kosong. }*/
void DeleteAllX(List2 *L, infotype X);

/*Procedure SearchAllX(input L:List2, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List2 L, infotype X);

/*function MaxMember(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List2 L);

/*function Modus(L:List2) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List2 L);

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List2, input L2:List2, output L:List2)
{I.S.: L1,L2 terdefinisi ;
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List2 L1, List2 L2, List2 *L);

/*Procedure SplitList(input L:List2, output L1:List2, output L2:List2)
{I.S.: L terdefinisi ;
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List2 L, List2 *L1, List2 *L2);

/*Procedure CopyList(input L1:List2, output L2:List2)
{I.S.: L1 terdefinisi;
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List2 L1, List2 *L2);
