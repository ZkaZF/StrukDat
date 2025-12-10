/* File : pohon3.c */
/* Deskripsi : ADT bintree3 berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060124140161 - Azka Wayasy Al Hafizh*/
/* Tanggal : 10 Desember 2025*/

#include "pohon3.h"

/********** PEMBUATAN POHON BARU ***********/
/* function Tree3 (A:bintree3, X:infotype, V:boolean, kiri:bintree3, kanan:bintree3)-> bintree3
{ Menghasilkan sebuah pohon biner dari Akar, Left, dan Right, jika alokasi berhasil, atau pohon kosong (Nil) jika alokasi gagal }*/
bintree3 Tree3(bintree3 A, infotype X, boolean V, bintree3 kiri, bintree3 kanan)
{
    // kamus lokal
    bintree3 P;

    // algoritma
    P = (bintree3)malloc(sizeof(node3));
    if (P != NIL)
    {
        parent(P) = A;
        info(P) = X;
        visited(P) = V;
        left(P) = kiri;
        right(P) = kanan;

        if (kiri != NIL)
        {
            parent(kiri) = P;
        }
        if (kanan != NIL)
        {
            parent(kanan) = P;
        }
    }
    return P;
}

/* penelusuran */
/* procedure printDFS( input P:bintree3)
{mencetak node-node P dari elemen terkiri mendalam baru ke kanan} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/
void printDFS(bintree3 P)
{
    // algoritma
    if (!IsEmptyTree(P))
    {
        printf("%c(", info(P));
        if (!IsEmptyTree(left(P)))
        {
            printDFS(left(P));
        }
        else
        {
            printf("( )");
        }
        printf(",");
        if (!IsEmptyTree(right(P)))
        {
            printDFS(right(P));
        }
        else
        {
            printf("( )");
        }
        printf(")");
    }
}

/* function max2(int a, int b)->integer
{mengembalikan nilai maksimal dari a atau b}*/
int Max2(int a, int b)
{
    // algoritma
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

/* function Tinggi(P:bintree3)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen = 0 }*/
int Tinggi(bintree3 P)
{
    // algoritma
    if (IsEmptyTree(P))
    {
        return -1;
    }
    else if (IsDaun(P))
    {
        return 0;
    }
    else
    {
        return 1 + Max2(Tinggi(left(P)), Tinggi(right(P)));
    }
}

/*procedure PrintLevel(input P:bintree, input N:integer)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N}*/
void PrintLevel(bintree3 P, int N)
{
    // algoritma
    if (!IsEmptyTree(P))
    {
        if (N == 1)
        {
            printf("%c ", info(P));
        }
        else
        {
            PrintLevel(left(P), N - 1);
            PrintLevel(right(P), N - 1);
        }
    }
}

/* procedure PrintBFS( input P:bintree3)
{mencetak node-node P dari generasi paling terkecil ke terbesar}*/
/*contoh: A B C D */
void PrintBFS(bintree3 P)
{
    // kamus lokal
    int i, tinggi;

    // algoritma
    if (!IsEmptyTree(P))
    {
        tinggi = Tinggi(P);
        for (i = 1; i <= tinggi + 1; i++)
        {
            PrintLevel(P, i);
        }
    }
}

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree3) --> boolean
   {mengembalikan true bila bintree3 L kosong} */
boolean IsEmptyTree(bintree3 P)
{
    // algoritma
    return (P == NIL);
}

/* function IsDaun (P:bintree3)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun(bintree3 P)
{
    // algoritma
    if (!IsEmptyTree(P))
    {
        return (IsEmptyTree(left(P)) && IsEmptyTree(right(P)));
    }
    else
    {
        return FALSE;
    }
}

/* function IsBiner (P:bintree3)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner(bintree3 P)
{
    // algoritma
    if (!IsEmptyTree(P))
    {
        return (!IsEmptyTree(left(P)) && !IsEmptyTree(right(P)));
    }
    else
    {
        return FALSE;
    }
}

/* function IsUnerLeft(P:bintree3)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft(bintree3 P)
{
    // algoritma
    if (!IsEmptyTree(P))
    {
        return (!IsEmptyTree(left(P)) && IsEmptyTree(right(P)));
    }
    else
    {
        return FALSE;
    }
}

/* function IsUnerRight(P:bintree3)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight(bintree3 P)
{
    // algoritma
    if (!IsEmptyTree(P))
    {
        return (IsEmptyTree(left(P)) && !IsEmptyTree(right(P)));
    }
    else
    {
        return FALSE;
    }
}

/*PENELUSURAN*/
/*procedure resetVisited( input/output P : bintree3 )
{I.S: P terdefinisi; F.S: -}
{proses mengubah status visited semua node di P menjadi false}*/
void resetVisited(bintree3 P)
{
    // algoritma
    if (!IsEmptyTree(P))
    {
        visited(P) = FALSE;
        resetVisited(left(P));
        resetVisited(right(P));
    }
}

/*procedure printPathX( input P:bintree3, input X:infotype)
{menampilkan jalur dari akar P hingga node bernilai X }*/
void printPathX(bintree3 P, infotype X)
{
    // kamus lokal
    bintree3 temp;

    // algoritma
    if (!IsEmptyTree(P))
    {
        if (info(P) == X)
        {
            temp = P;
            while (temp != NIL)
            {
                printf("%c", info(temp));
                temp = parent(temp);
            }
            printf("\n");
        }
        else
        {
            printPathX(left(P), X);
            printPathX(right(P), X);
        }
    }
}

/*procedure printPathDaunX( input P:bintree3, input X:infotype)
{menampilkan jalur dari akar P hingga daun bernilai X }*/
void printPathDaunX(bintree3 P, infotype X)
{
    // kamus lokal
    bintree3 temp;

    // algoritma
    if (!IsEmptyTree(P))
    {
        if (IsDaun(P) && info(P) == X)
        {
            temp = P;
            while (temp != NIL)
            {
                printf("%c", info(temp));
                temp = parent(temp);
            }
            printf("\n");
        }
        else
        {
            printPathDaunX(left(P), X);
            printPathDaunX(right(P), X);
        }
    }
}

/*procedure printAllPaths( input P:bintree3)
{menampilkan semua jalur yang mungkin dari akar P hingga setiap daun}*/
void printAllPaths(bintree3 P)
{
    // kamus lokal
    bintree3 temp;

    // algoritma
    if (!IsEmptyTree(P))
    {
        if (IsDaun(P))
        {
            temp = P;
            while (temp != NIL)
            {
                printf("%c", info(temp));
                temp = parent(temp);
            }
            printf("\n");
        }
        else
        {
            printAllPaths(left(P));
            printAllPaths(right(P));
        }
    }
}

/* function NbElmTree(P:bintree3) --> integer
{ menghitung banyaknya elemen bintree3 P} */
int NbElmTree(bintree3 P)
{
    // algoritma
    if (IsEmptyTree(P))
    {
        return 0;
    }
    else
    {
        return 1 + NbElmTree(left(P)) + NbElmTree(right(P));
    }
}

/* function NbDaun(P:bintree3)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun(bintree3 P)
{
    // algoritma
    if (IsEmptyTree(P))
    {
        return 0;
    }
    else if (IsDaun(P))
    {
        return 1;
    }
    else
    {
        return NbDaun(left(P)) + NbDaun(right(P));
    }
}

/* function Level(P:bintree3)-> integer
{menghitung tingkat/generasi node pohon P, level akar=1 }*/
int Level(bintree3 P)
{
    // kamus lokal
    int level;

    // algoritma
    if (IsEmptyTree(P))
    {
        return 0;
    }
    else
    {
        level = 1;
        while (parent(P) != NIL)
        {
            level++;
            P = parent(P);
        }
        return level;
    }
}

/*function CountLevelT(P:bintree3, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevelT(bintree3 P, int T)
{
    // algoritma
    if (IsEmptyTree(P))
    {
        return 0;
    }
    else if (T == 1)
    {
        return 1;
    }
    else
    {
        return CountLevelT(left(P), T - 1) + CountLevelT(right(P), T - 1);
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*** operator khusus LIST1 ***/
/*procedure Pconcat( input/output Asli:List1, input Tambahan:List1) */
/*{I.S:- ; F.S: list Asli berubah karena disambung list Tambahan}*/
/*{menyambung list Tambahan ke belakang list Asli}*/
void Pconcat(List1 *Asli, List1 Tambahan)
{
    // kamus lokal

    // algoritma
}

/*function fconcat( Asli:List1, Tambahan:List1) -> List1 */
/*{membentuk list Baru hasil penyambungan list Tambahan ke belakang list Asli}*/
/*{periksa dampaknya, list Asli tidak boleh berubah }*/
List1 Fconcat(List1 Asli, List1 Tambahan)
{
    // kamus lokal

    // algoritma
}

/*** LINEARISASI POHON ***/
/*function linearPrefix(P:bintree3) -> List1
{menghasilkan list node dari P terurut prefix akar,kiri,kanan}*/
List1 LinearPrefix(bintree3 P)
{
    // kamus lokal

    // algoritma
}

/*function linearPosfix(P:bintree3) -> List1
{menghasilkan list node dari P terurut posfix kiri,kanan,akar}*/
List1 LinearPosfix(bintree3 P)
{
    // kamus lokal

    // algoritma
}

/*function linearInfix(P:bintree3) -> List1
{menghasilkan list node dari P terurut infix kiri,akar,kanan}*/
List1 LinearInfix(bintree3 P)
{
    // kamus lokal

    // algoritma
}

/*function linearBreadthFS(P:bintree3) -> List1
{menghasilkan list node dari P terurut level/tingkat}*/
List1 LinearBreadthFS(bintree3 P)
{
    // kamus lokal

    // algoritma
}
