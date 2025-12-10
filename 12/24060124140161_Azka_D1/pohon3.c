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

    // algoritma
}

/* penelusuran */
/* procedure printDFS( input P:bintree3)
{mencetak node-node P dari elemen terkiri mendalam baru ke kanan} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/
void printDFS(bintree3 P)
{
    // algoritma
}

/* function max2(int a, int b)->integer
{mengembalikan nilai maksimal dari a atau b}*/
int Max2(int a, int b)
{
    // algoritma
}

/* function Tinggi(P:bintree3)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen = 0 }*/
int Tinggi(bintree3 P)
{
    // algoritma
}

/*procedure PrintLevel(input P:bintree, input N:integer)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N}*/
void PrintLevel(bintree3 P, int N)
{
    // algoritma
}

/* procedure PrintBFS( input P:bintree3)
{mencetak node-node P dari generasi paling terkecil ke terbesar}*/
/*contoh: A B C D */
void PrintBFS(bintree3 P)
{
    // kamus lokal

    // algoritma
}

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree3) --> boolean
   {mengembalikan true bila bintree3 L kosong} */
boolean IsEmptyTree(bintree3 P)
{
    // algoritma
}

/* function IsDaun (P:bintree3)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun(bintree3 P)
{
    // algoritma
}

/* function IsBiner (P:bintree3)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner(bintree3 P)
{
    // algoritma
}

/* function IsUnerLeft(P:bintree3)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft(bintree3 P)
{
    // algoritma
}

/* function IsUnerRight(P:bintree3)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight(bintree3 P)
{
    // algoritma
}

/*PENELUSURAN*/
/*procedure resetVisited( input/output P : bintree3 )
{I.S: P terdefinisi; F.S: -}
{proses mengubah status visited semua node di P menjadi false}*/
void resetVisited(bintree3 P)
{
    // algoritma
}

/*procedure printPathX( input P:bintree3, input X:infotype)
{menampilkan jalur dari akar P hingga node bernilai X }*/
void printPathX(bintree3 P, infotype X)
{
    // kamus lokal

    // algoritma
}

/*procedure printPathDaunX( input P:bintree3, input X:infotype)
{menampilkan jalur dari akar P hingga daun bernilai X }*/
void printPathDaunX(bintree3 P, infotype X)
{
    // kamus lokal

    // algoritma
}

/*procedure printAllPaths( input P:bintree3)
{menampilkan semua jalur yang mungkin dari akar P hingga setiap daun}*/
void printAllPaths(bintree3 P)
{
    // kamus lokal

    // algoritma
}

/* function NbElmTree(P:bintree3) --> integer
{ menghitung banyaknya elemen bintree3 P} */
int NbElmTree(bintree3 P)
{
    // algoritma
}

/* function NbDaun(P:bintree3)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun(bintree3 P)
{
    // algoritma
}

/* function Level(P:bintree3)-> integer
{menghitung tingkat/generasi node pohon P, level akar=1 }*/
int Level(bintree3 P)
{
    // kamus lokal

    // algoritma
}

/*function CountLevelT(P:bintree3, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevelT(bintree3 P, int T)
{
    // algoritma
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*** operator khusus LIST1 ***/
/*procedure Pconcat( input/output Asli:list1, input Tambahan:list1) */
/*{I.S:- ; F.S: list Asli berubah karena disambung list Tambahan}*/
/*{menyambung list Tambahan ke belakang list Asli}*/
void Pconcat(list1 *Asli, list1 Tambahan)
{
    // kamus lokal

    // algoritma
}

/*function fconcat( Asli:list1, Tambahan:list1) -> list1 */
/*{membentuk list Baru hasil penyambungan list Tambahan ke belakang list Asli}*/
/*{periksa dampaknya, list Asli tidak boleh berubah }*/
list1 Fconcat(list1 Asli, list1 Tambahan)
{
    // kamus lokal

    // algoritma
}

/*** LINEARISASI POHON ***/
/*function linearPrefix(P:bintree3) -> list1
{menghasilkan list node dari P terurut prefix akar,kiri,kanan}*/
list1 LinearPrefix(bintree3 P)
{
    // kamus lokal

    // algoritma
}

/*function linearPosfix(P:bintree3) -> list1
{menghasilkan list node dari P terurut posfix kiri,kanan,akar}*/
list1 LinearPosfix(bintree3 P)
{
    // kamus lokal

    // algoritma
}

/*function linearInfix(P:bintree3) -> list1
{menghasilkan list node dari P terurut infix kiri,akar,kanan}*/
list1 LinearInfix(bintree3 P)
{
    // kamus lokal

    // algoritma
}

/*function linearBreadthFS(P:bintree3) -> list1
{menghasilkan list node dari P terurut level/tingkat}*/
list1 LinearBreadthFS(bintree3 P)
{
    // kamus lokal

    // algoritma
}
