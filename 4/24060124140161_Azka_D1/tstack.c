/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : 24060124140161/Azka Wayasy Al Hafizh*/
/* Tanggal   : 24 September 2025*/
/***********************************/

#include <stdio.h>

#include "tstack.h"
#include "boolean.h"
/*procedure createStack( output T: Tstack)
    {I.S.: -}
    {F.S.: T terdefinisi, semua nilai elemen T.wadah = '#' }
    {Proses: menginisialisasi T} */
void createStack(Tstack *T)
{
    int i;

    for (i = 1; i <= 10; i++)
    {
        (*T).wadah[i] = '#';
    }
    (*T).top = 0;
}

/*function top( T: Tstack) -> integer
    {mengembalikan posisi puncak stack } */
// int top (Tstack T);
// dalam praktikum ini, fungsi dapat direalisasikan
// menjadi macro dalam bahasa C.
#define top(T) (T).top

/*function infotop( T: Tstack) -> character
    {mengembalikan nilai elemen top stack } */
// char infotop (Tstack T);
#define infotop(T) (T).wadah[(T).top]

/*function isEmptyStack( T: Tstack) -> boolean
    {mengembalikan True jika T kosong } */
boolean isEmptyStack(Tstack T)
{
    if (top(T) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*function isFullStack( T: Tstack) -> boolean
    {mengembalikan True jika T penuh } */
boolean isFullStack(Tstack T)
{
    if (top(T) == 10)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*procedure push ( input/output T:Tstack, input E: character )
    {I.S.: T,E terdefinisi}
    {F.S.: infotop tetap, atau berisi nilai E }
    {Proses: mengisi elemen top baru, bila belum penuh }*/
void push(Tstack *T, char E)
{
    if (!isFullStack(*T))
    {
        top(*T) = top(*T) + 1;
        (*T).wadah[top(*T)] = E;
    }
}

/*procedure pop ( input/output T:Tstack, output X: character )
    {I.S.: T terdefinisi}
    {F.S.: X= infotop stack lama, atau '#' }
    {Proses: mengambil elemen top, bila belum kosong }*/
void pop(Tstack *T, char *X)
{
    if (!isEmptyStack(*T))
    {
        *X = infotop(*T);
        (*T).wadah[top(*T)] = '-';
        (*T).top = top(*T) - 1;
    }
}

/*procedure printStack ( input T:Tstack )
    {I.S.: T terdefinisi}
    {F.S.: -}
    {Proses: menampilkan kondisi wadah T ke layar}
    {setiap elemen dipisah tanda titik koma } */
void printStack(Tstack T)
{
    int i;
    for (i = 1; i <= 10; i++)
    {
        printf("%c", T.wadah[i]);
        if (i < top(T))
        {
            printf(",");
        }
    }
}

/*procedure viewStack ( input T:Tstack )
    {I.S.: T terdefinisi}
    {F.S.: -}
    {Proses: menampilkan elemen tak kosong T ke layar}
    {setiap elemen dipisah tanda titik koma } */
void viewStack(Tstack T)
{
    int i;
    if (!(isEmptyStack(T)))
    {
        for (i = 1; i <= top(T); i++)
        {
            printf("%c", T.wadah[i]);
            if (i < top(T))
            {
                printf(",");
            }
        }
        printf("\n");
    }
}

/* boolean isPalindrom(kata:String)
   {mengembalikan true jika kata merupakan palindrom, false jika tidak},
   {asumsi panjang kata maksimum adalah 30 karakter} */
boolean isPalindrom(char kata[30])
{
    Tstack S1;
    int p = 0;
    int i;
    char X;
    boolean isSama = true;

    while (kata[p] != '\0')
    {
        p++;
    }
    p--;

    if (p >= 0)
    {
        createStack(&S1);

        for (i = 0; i < (p + 1) / 2; i++)
        {
            push(&S1, kata[i]);
        }

        i = p - ((p + 1) / 2 - 1);

        while (isSama && i <= p)
        {
            pop(&S1, &X);

            if (X != kata[i])
            {
                isSama = false;
            }
            else
            {
                i++;
            }
        }
    }
    return isSama;
}

/*procedure pushN ( input/output T:Tstack, input N: integer )
    {I.S.: T,N terdefinisi}
    {F.S.: infotop tetap, atau top=N }
    {Proses: mengisi elemen top baru N kali dari keyboard, bila belum penuh }*/
void pushN(Tstack *T, int N)
{
    int i = 1;
    char X;
    while (i <= N && !(isFullStack(*T)))
    {
        scanf(" %c", &X);
        push(T, X);
        i = i + 1;
    }
}
