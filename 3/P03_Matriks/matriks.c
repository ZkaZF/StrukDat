/* Program   : matriks.c */
/* Deskripsi : file BODY modul matriks integer */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/

#include <stdio.h>
#include "matriks.h"
#include "boolean.h"
/* KONSTRUKTOR */
/* procedure initMatriks(output M: Matriks)
    {I.S.: - }
    {F.S.: Matriks M terdefinisi}
    {Proses mengisi elemen cell dengan -999, nbaris 0, nkolom 0} */
void initMatriks(Matriks *M)
{
    int i, j;
    M->nbaris = 0;
    M->nkolom = 0;
    for (i = 0; i < 11; i++)
    {
        for (j = 0; j < 11; j++)
        {
            M->cell[i][j] = -999;
        }
    }
}

/* SELEKTOR */
/* function getNBaris(M: Matriks) -> integer
    {mengembalikan banyak baris matriks M yang terisi } */
int getNBaris(Matriks M)
{
    return M.nbaris;
}

/* function getNKolom(M: Matriks) -> integer
    {mengembalikan banyak kolom matriks M yang terisi } */
int getNKolom(Matriks M)
{
    return M.nkolom;
}

/* PREDIKAT */
/* function isEmptyMatriks(M: Matriks) -> boolean
    {mengembalikan True jika matriks M kosong } */
boolean isEmptyMatriks(Matriks M)
{
    return (M.nbaris == 0 && M.nkolom == 0);
}

/* function isFullMatriks(M: Matriks) -> boolean
    {mengembalikan True jika matriks M penuh } */
boolean isFullMatriks(Matriks M)
{
    return (M.nbaris == 10 && M.nkolom == 10);
}

/* MUTATOR */
/* procedure addX (input/output M:Matriks, input X:integer, row:integer, col:integer)
    {I.S.: M terdefinisi, X terdefinisi }
    {F.S.: isi M.cell bertambah 1 elemen pada baris ke-row dan kolom ke-col jika belum penuh}
    {Proses: mengisi elemen M.cell dengan nilai X} */
void addX(Matriks *M, int X, int row, int col)
{
    if (!isFullMatriks(*M) && row >= 1 && row <= 10 && col >= 1 && col <= 10)
    {
        M->cell[row][col] = X;
        if (row > M->nbaris)
        {
            M->nbaris = row;
        }
        if (col > M->nkolom)
        {
            M->nkolom = col;
        }
    }
}

/* procedure delX (input/output M:Matriks, input X:integer )
    {I.S.: M terdefinisi, X terdefinisi}
    {F.S.: elemen M.cell berkurang 1}
    {Proses: menghapus 1 elemen bernilai X dari M.cell*/
void delX(Matriks *M, int X)
{
    int i, j;
    boolean found = false;
    for (i = 1; i <= M->nbaris && !found; i++)
    {
        for (j = 1; j <= M->nkolom && !found; j++)
        {
            if (M->cell[i][j] == X)
            {
                M->cell[i][j] = -999;
                found = true;
            }
        }
    }
}

/* procedure isiMatriksRandom(input/output M: Matriks, input x: integer, input y: integer)
    {I.S.: M terdefinisi}
    {F.S.: M terisi dengan bilangan random sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
    {proses: mengisi matriks dengan bilangan integer random dengan jumlah baris x dan kolom y} */
void isiMatriksRandom(Matriks *M, int x, int y)
{
    int i, j;
    if (x >= 1 && x <= 10 && y >= 1 && y <= 10)
    {
        M->nbaris = x;
        M->nkolom = y;
        for (i = 1; i <= x; i++)
        {
            for (j = 1; j <= y; j++)
            {
                M->cell[i][j] = rand() % 100; // Mengisi dengan bilangan random antara 0-99
            }
        }
    }
}

/* procedure isiMatriksIdentitas(input/output M: Matriks, input n: integer)
    {I.S.: M terdefinisi}
    {F.S.: M terisi dengan matriks identitas berukuran n x n, nbaris=nkolom=n}
    {proses: mengisi matriks dengan matriks identitas berukuran n x n} */
void isiMatriksIdentitas(Matriks *M, int n)
{
    int i, j;
    if (n >= 1 && n <= 10)
    {
        M->nbaris = n;
        M->nkolom = n;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (i == j)
                {
                    M->cell[i][j] = 1;
                }
                else
                {
                    M->cell[i][j] = 0;
                }
            }
        }
    }
}

/* OPERASI BACA/TULIS */
/* procedure populateMatriks(input/output M: Matriks, input x: integer, input y: integer)
{I.S.: M terdefinisi}
{F.S.: M terisi dengan inputan dari keybord sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
{proses: mengisi matriks dengan meminta inputan dari keyboard dengan jumlah baris x dan kolom y} */
void populateMatriks(Matriks *M, int x, int y)
{
    int i, j;
    if (x >= 1 && x <= 10 && y >= 1 && y <= 10)
    {
        M->nbaris = x;
        M->nkolom = y;
        for (i = 1; i <= x; i++)
        {
            for (j = 1; j <= y; j++)
            {
                printf("Masukkan elemen [%d][%d]: ", i, j);
                scanf("%d", &M->cell[i][j]);
            }
        }
    }
}

/* procedure printMatriks(input M:Matriks)
    {I.S.: M terdefinisi}
    {F.S.: -}
    {Proses: menampilkan semua elemen M.cell ke layar} */
void printMatriks(Matriks M)
{
    int i, j;
    for (i = 1; i <= M.nbaris; i++)
    {
        for (j = 1; j <= M.nkolom; j++)
        {
            printf("%d ", M.cell[i][j]);
        }
        printf("\n");
    }
}

/* procedure viewMatriks (input M:Matriks)
    {I.S.: M terdefinisi}
    {F.S.: -}
    {Proses: menampilkan elemen M.cell yang terisi ke layar} */
void viewMatriks(Matriks M)
{
    int i, j;
    for (i = 1; i <= M.nbaris; i++)
    {
        for (j = 1; j <= M.nkolom; j++)
        {
            if (M.cell[i][j] != -999)
            {
                printf("%d ", M.cell[i][j]);
            }
            else
            {
                printf(". ");
            }
        }
        printf("\n");
    }
}

/* OPERASI ARITMATIKA */
/* function addMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil penjumlahan matriks M1 dengan M2} */
Matriks addMatriks(Matriks M1, Matriks M2)
{
    Matriks M3;
    initMatriks(&M3);
    int i, j;
    initMatriks(&M3);
    if (M1.nbaris == M2.nbaris && M1.nkolom == M2.nkolom)
    {
        M3.nbaris = M1.nbaris;
        M3.nkolom = M1.nkolom;
        for (i = 1; i <= M1.nbaris; i++)
        {
            for (j = 1; j <= M1.nkolom; j++)
            {
                M3.cell[i][j] = M1.cell[i][j] + M2.cell[i][j];
            }
        }
    }
    return M3;
}

/* function subMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil pengurangan antara matriks M1 dengan M2} */
Matriks subMatriks(Matriks M1, Matriks M2)
{
    Matriks M3;
    int i, j;
    initMatriks(&M3);
    if (M1.nbaris == M2.nbaris && M1.nkolom == M2.nkolom)
    {
        M3.nbaris = M1.nbaris;
        M3.nkolom = M1.nkolom;
        for (i = 1; i <= M1.nbaris; i++)
        {
            for (j = 1; j <= M1.nkolom; j++)
            {
                M3.cell[i][j] = M1.cell[i][j] - M2.cell[i][j];
            }
        }
    }
    return M3;
}

/* function kaliMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil perkalian antara matriks M1 dengan M2} */
Matriks kaliMatriks(Matriks M1, Matriks M2)
{
    Matriks M3;
    int i, j, k;
    initMatriks(&M3);
    if (M1.nkolom == M2.nbaris)
    {
        M3.nbaris = M1.nbaris;
        M3.nkolom = M2.nkolom;
        for (i = 1; i <= M1.nbaris; i++)
        {
            for (j = 1; j <= M2.nkolom; j++)
            {
                M3.cell[i][j] = 0;
                for (k = 1; k <= M1.nkolom; k++)
                {
                    M3.cell[i][j] += M1.cell[i][k] * M2.cell[k][j];
                }
            }
        }
    }
    return M3;
}

/* function kaliSkalarMatriks(M: Matriks, x: integer) -> Matriks
{mengembalikan perkalian antara matriks M dengan nilai skalar x} */
Matriks kaliSkalarMatriks(Matriks M1, int x)
{
    Matriks M2;
    int i, j;
    initMatriks(&M2);
    M2.nbaris = M1.nbaris;
    M2.nkolom = M1.nkolom;
    for (i = 1; i <= M1.nbaris; i++)
    {
        for (j = 1; j <= M1.nkolom; j++)
        {
            M2.cell[i][j] = M1.cell[i][j] * x;
        }
    }
    return M2;
}

/* OPERASI LAINNYA */
/* procedure transposeMatriks(input/output M: Matriks)
    {I.S.: M terdefinisi}
    {F.S.: Matriks M sudah ditukar susunan baris dan kolomnya (Transpose)}
    {proses: mengubah susunan cell matriks, M.cell[i,j] menjadi M.cell[j,i]} */
void transposeMatriks(Matriks *M)
{
    int i, j;
    Matriks MT;
    initMatriks(&MT);
    MT.nbaris = M->nkolom;
    MT.nkolom = M->nbaris;
    for (i = 1; i <= M->nbaris; i++)
    {
        for (j = 1; j <= M->nkolom; j++)
        {
            MT.cell[j][i] = M->cell[i][j];
        }
    }
    *M = MT;
}

/* function getTransposeMatriks(M: Matriks)
    {menghasilkan sebuah matriks yang merupakan hasil transpose dari matriks M} */
Matriks getTransposeMatriks(Matriks M)
{
    Matriks MT;
    int i, j;
    initMatriks(&MT);
    MT.nbaris = M.nkolom;
    MT.nkolom = M.nbaris;
    for (i = 1; i <= M.nbaris; i++)
    {
        for (j = 1; j <= M.nkolom; j++)
        {
            MT.cell[j][i] = M.cell[i][j];
        }
    }
    return MT;
}

/* function addPadding(M: Matriks, input n:integer)
    {menghasilkan matriks baru dari M yang ditambahkan padding 0 sesuai dengan ukuran padding n */
Matriks addPadding(Matriks M, int n)
{
    Matriks MP;
    int i, j;
    initMatriks(&MP);
    if (n >= 0 && n <= 10 && M.nbaris + 2 * n <= 10 && M.nkolom + 2 * n <= 10)
    {
        MP.nbaris = M.nbaris + 2 * n;
        MP.nkolom = M.nkolom + 2 * n;
        for (i = 1; i <= MP.nbaris; i++)
        {
            for (j = 1; j <= MP.nkolom; j++)
            {
                if (i > n && i <= M.nbaris + n && j > n && j <= M.nkolom + n)
                {
                    MP.cell[i][j] = M.cell[i - n][j - n];
                }
                else
                {
                    MP.cell[i][j] = 0;
                }
            }
        }
    }
    return MP;
}

/* function maxPooling(M: Matriks, input size:integer)
    {menghasilkan matriks hasil max pooling matriks M dengan pool size = size  */
Matriks maxPooling(Matriks M, int size)
{
    Matriks MP;
    int i, j, m, n;
    initMatriks(&MP);
    if (size > 0 && size <= 10 && M.nbaris % size == 0 && M.nkolom % size == 0)
    {
        MP.nbaris = M.nbaris / size;
        MP.nkolom = M.nkolom / size;
        for (i = 0; i < MP.nbaris; i++)
        {
            for (j = 0; j < MP.nkolom; j++)
            {
                int maxVal = M.cell[i * size + 1][j * size + 1];
                for (m = 0; m < size; m++)
                {
                    for (n = 0; n < size; n++)
                    {
                        if (M.cell[i * size + m + 1][j * size + n + 1] > maxVal)
                        {
                            maxVal = M.cell[i * size + m + 1][j * size + n + 1];
                        }
                    }
                }
                MP.cell[i + 1][j + 1] = maxVal;
            }
        }
    }
    return MP;
}

/* function avgPooling(M: Matriks, input size:integer)
    {menghasilkan matriks hasil average pooling matriks M dengan pool size = size  */
Matriks avgPooling(Matriks M, int size)
{
    Matriks MP;
    int i, j, m, n;
    initMatriks(&MP);
    if (size > 0 && size <= 10 && M.nbaris % size == 0 && M.nkolom % size == 0)
    {
        MP.nbaris = M.nbaris / size;
        MP.nkolom = M.nkolom / size;
        for (i = 0; i < MP.nbaris; i++)
        {
            for (j = 0; j < MP.nkolom; j++)
            {
                int sumVal = 0;
                for (m = 0; m < size; m++)
                {
                    for (n = 0; n < size; n++)
                    {
                        sumVal += M.cell[i * size + m + 1][j * size + n + 1];
                    }
                }
                MP.cell[i + 1][j + 1] = sumVal / (size * size);
            }
        }
    }
    return MP;
}

/* function conv(M: Matriks, K:Matriks)
    {menghasilkan matriks hasil konvolusi matriks M dengan kernel K  */
Matriks conv(Matriks M, Matriks K);

/* OPERASI PENCARIAN*/
/* procedure searchX( input M:Matriks, input X: integer, output row: integer, output col: integer )
    {I.S.: M terdefinisi, X terdefinisi }
    {F.S.: row berisi indeks baris dan col berisi indeks kolom ketemu X di M.cell, atau -999 jika tidak ketemu}
    {Proses: mencari elemen bernilai X dalam M.cell} */
void searchX(Matriks M, int X, int *row, int *col);

/* function countX (M:Matriks, X: integer) -> integer
    {mengembalikan banyaknya elemen bernilai X dalam M.cell} */
int countX(Matriks M, int X);