#ifndef tabel_c
#define tabel_c
#include "tabel.h"
/* Deskripsi : tabel*/
/* NIM/Nama : 24060124140161/Azka Wayasy Al Hafizh */
/* Tanggal : 15 September 2025*/

/************************KONSTRUKTOR*************************/
/* procedure createTable( output T: Tabel)
    {I.S.: -}
    {F.S.: size=0, setiap elemen wadah dengan 1 karakter spasi, spasi dianggap karakter kosong}
    {Proses: menginisialisasi T} */
void createTable(Tabel *T)
{
    int i;
    T->size = 0;
    for (i = 1; i <= 10; i++)
    {
        T->wadah[i] = ' ';
    }
}

/************************SELEKTOR*************************/
/* function getSize( T: Tabel) -> integer
    {mengembalikan banyak elemen pengisi T } */
int getSize(Tabel T)
{
    return T.size;
}

/*************************PREDIKAT*************************/
/* function isEmptyTable( T: Tabel) -> boolean
    {mengembalikan True jika T kosong } */
boolean isEmptyTable(Tabel T)
{
    if (T.size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* function isFullTable( T: Tabel) -> boolean
    {mengembalikan True jika T penuh } */
boolean isFullTable(Tabel T)
{
    if (T.size == 10)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*************************OPERASI PENCARIAN*************************/
/*  procedure searchX (input T:Tabel, input X:character, output pos:integer )
    {I.S.: T terdefinisi, x terdefinisi }
    {F.S.: pos berisi posisi ketemu di T.wadah, atau -999 jika tidak ketemu }
    {Proses: mencari elemen bernilai x dalam T.wadah} */
void searchX(Tabel T, char x, int *pos)
{
    int i;
    boolean ada = false;
    *pos = -999;
    for (i = 1; i <= T.size; i++)
    {
        if (T.wadah[i] == x)
        {
            *pos = i;
            ada = true;
            break;
        }
    }
    if (!ada)
    {
        *pos = -999;
    }
}

/* function countX (T:Tabel, x:character) -> integer
    {mengembalikan banyaknya elemen bernilai X dalam T.wadah} */
int countX(Tabel T, char x)
{
    int i, count = 0;
    for (i = 1; i <= T.size; i++)
    {
        if (T.wadah[i] == x)
        {
            count++;
        }
    }
    return count;
}

/* function countVocal(T: Tabel) -> integer
    {mengembalikan banyak elemen T yang berupa karakter huruf vocal } */
int countVocal(Tabel T)
{
    int i, count = 0;
    for (i = 1; i <= T.size; i++)
    {
        if (T.wadah[i] == 'a' || T.wadah[i] == 'i' || T.wadah[i] == 'u' || T.wadah[i] == 'e' || T.wadah[i] == 'o' ||
            T.wadah[i] == 'A' || T.wadah[i] == 'I' || T.wadah[i] == 'U' || T.wadah[i] == 'E' || T.wadah[i] == 'O')
        {
            count++;
        }
    }
    return count;
}

/*************************MUTATOR*************************/
/* procedure addXTable (input/output T:Tabel, input x: character)
    {I.S.: T terdefinisi, x terdefinisi }
    {F.S.: isi T.wadah bertambah 1 elemen jika belum penuh}
    {Proses: mengisi elemen T.wadah dengan nilai x}*/
void addXTable(Tabel *T, char x)
{
    if (!isFullTable(*T))
    {
        T->size++;
        T->wadah[T->size] = x;
    }
}

/* procedure addUniqueXTable (input/output T:Tabel, input x: character)
    {I.S.: T terdefinisi, x terdefinisi }
    {F.S.: isi T.wadah bertambah 1 elemen jika x unik dan tabel belum penuh}
    {Proses: mengisi elemen T.wadah dengan nilai unik x}*/
void addUniqueXTable(Tabel *T, char x)
{
    int pos;
    searchX(*T, x, &pos);
    if (pos == -999)
    {
        addXTable(T, x);
    }
}

/* procedure delXTable (input/output T:Tabel, input x:character)
    {I.S.: T terdefinisi, x terdefinisi}
    {F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
    {Proses: menghapus 1 elemen bernilai x, geser semua elemen sisa}*/
void delXTable(Tabel *T, char x)
{
    int i, pos;
    searchX(*T, x, &pos);
    if (pos != -999)
    {
        for (i = pos; i < T->size; i++)
        {
            T->wadah[i] = T->wadah[i + 1];
        }
        T->wadah[T->size] = ' ';
        T->size--;
    }
}

/* procedure delTable (input/output T:Tabel, input idx:integer)
    {I.S.: T terdefinisi, idx antara 1...getSize(T)}
    {F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
    {Proses: menghapus 1 elemen pada posisi idx, geser semua elemen sisa}*/
void delTable(Tabel *T, int idx)
{
    int i;
    if (!isEmptyTable(*T) && idx >= 1 && idx <= T->size)
    {
        for (i = idx; i < T->size; i++)
        {
            T->wadah[i] = T->wadah[i + 1];
        }
        T->wadah[T->size] = ' ';
        T->size--;
    }
}

/* procedure delAllXTable (input/output T:Tabel, input x:character)
    {I.S.: T terdefinisi}
    {F.S.: isi T.wadah berkurang semua elemen bernilai X jika belum kosong}
    {Proses: menghapus semua elemen bernilai X, geser elemen sisa}*/
void delAllXTable(Tabel *T, char x)
{
    int i;
    for (i = 1; i <= T->size; i++)
    {
        if (T->wadah[i] == x)
        {
            delTable(T, i);
            i--;
        }
    }
}

/*************************OPERASI BACA/TULIS*************************/
/* procedure printTable (input T:Tabel)
    {I.S.: T terdefinisi}
    {F.S.: -}
    {Proses: menampilkan semua elemen T ke layar} */
void printTable(Tabel T)
{
    int i;
    for (i = 1; i <= 10; i++)
    {
        printf("%c ", T.wadah[i]);
    }
    printf("\n");
}

/* procedure viewTable (input T:Tabel)
    {I.S.: T terdefinisi}
    {F.S.: -}
    {Proses: menampilkan elemen T yang terisi ke layar} */
void viewTable(Tabel T)
{
    int i;
    for (i = 1; i <= T.size; i++)
    {
        printf("%c ", T.wadah[i]);
    }
    printf("\n");
}

/* procedure populateTable (input/output T:Tabel, input N: integer)
    {I.S.: T terdefinisi, N terdefinisi dalam rentang 1..10}
    {F.S.: T.wadah terisi sebanyak N elemen }
    {Proses: mengisi elemen T.wadah sebanyak N kali dari keyboard}
    {Syarat: angka-angka masukan keyboard > 0 }*/
void populateTable(Tabel *T, int N)
{
    int i;
    char x;
    if (N >= 1 && N <= 10)
    {
        for (i = 1; i <= N; i++)
        {
            scanf(" %c", &x);
            addXTable(T, x);
        }
    }
}

/*************************OPERASI STATISTIK*************************/
/*function Modus (T:Tabel ) -> integer
    {mengembalikan elemen pengisi T yang paling banyak muncul } */
/*asumsi: bila terdapat banyak yang sama maka yang diambil yang pertama*/
int Modus(Tabel T)
{
    int i, j;
    int count[10];
    int max = 0;
    int posisi = 0;
    for (i = 1; i <= T.size; i++)
    {
        count[i - 1] = 0;
        for (j = 1; j <= T.size; j++)
        {
            if (T.wadah[i] == T.wadah[j])
            {
                count[i - 1] = count[i - 1] + 1;
            }
        }
        if (count[i - 1] > max)
        {
            max = count[i - 1];
            posisi = i;
        }
    }
    return T.wadah[posisi];
}

/*************************OPERASI RELASIONAL*************************/
/* function IsEqualTable (T1:Tabel, T2: Table ) -> boolean
    {mengembalikan true jika T1 memiliki elemen dan urutan yang sama dengan T2 } */
boolean isEqualTable(Tabel T1, Tabel T2)
{
    int i;
    boolean equal = true;
    if (T1.size != T2.size)
    {
        equal = false;
    }
    else
    {
        for (i = 1; i <= T1.size; i++)
        {
            if (T1.wadah[i] != T2.wadah[i])
            {
                equal = false;
                break;
            }
        }
    }
    return equal;
}

/*************************OPERASI LAINNYA*************************/
/* function getInverseTable(T:Tabel) -> Tabel
    {mengembalikan tabel baru dengan isi elemen yang berkebalikan dengan tabel T } */
Tabel getInverseTable(Tabel T)
{
    Tabel inv;
    int i, j;
    createTable(&inv);
    for (i = T.size; i >= 1; i--)
    {
        addXTable(&inv, T.wadah[i]);
    }
    return inv;
}

/* procedure inverseTable(input/output T:Tabel)
    {I.S.: T terdefinisi}
    {F.S.: elemen dalam T.wadah memiliki isi berkabalikan dengan isi tabel semula}
    {Proses: membalik isi elemen pada tabel T}*/
void inverseTable(Tabel *T)
{
    int i;
    char temp;
    for (i = 1; i <= T->size / 2; i++)
    {
        temp = T->wadah[i];
        T->wadah[i] = T->wadah[T->size - i + 1];
        T->wadah[T->size - i + 1] = temp;
    }
}

/*************************OPERASI PENGURUTAN*************************/
/* procedure SortAsc ( input/output T:Tabel)
    {I.S.: T terdefinisi}
    {F.S.: elemen dalam T.wadah terurut dari huruf abjad awal ke akhir}
    {Proses: mengurutkan elemen dalam T.wadah dari huruf abjad awal ke akhir}*/
void sortAsc(Tabel *T)
{
    int i, j;
    char temp;
    for (i = 1; i < T->size; i++)
    {
        for (j = i + 1; j <= T->size; j++)
        {
            if (T->wadah[i] > T->wadah[j])
            {
                temp = T->wadah[i];
                T->wadah[i] = T->wadah[j];
                T->wadah[j] = temp;
            }
        }
    }
}

/* procedure SortDesc ( input/output T:Tabel)
    {I.S.: T terdefinisi}
    {F.S.: elemen dalam T.wadah terurut dari huruf abjad akhir ke awal}
    {Proses: mengurutkan elemen dalam T.wadah dari huruf abjad akhir ke awal}*/
void sortDesc(Tabel *T)
{
    int i, j;
    char temp;
    for (i = 1; i < T->size; i++)
    {
        for (j = i + 1; j <= T->size; j++)
        {
            if (T->wadah[i] < T->wadah[j])
            {
                temp = T->wadah[i];
                T->wadah[i] = T->wadah[j];
                T->wadah[j] = temp;
            }
        }
    }
}
#endif