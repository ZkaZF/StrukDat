/* File : pohon2.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* pohon2 melengkapi operator ADT bintree yang ada dalam pohon1 */
/* NIM & Nama : 24060124140161 - Azka Wayasy Al Hafizh*/
/* Tanggal : 3 Desember 2025*/

#include "pohon2.h"

/*PENELUSURAN*/
/* procedure PrintTreeInden (input P : BinTree, input H : integer)
{ I.S. P terdefinisi, h adalah jarak indentasi subpohon }
{ F.S. Semua simpul P ditulis dengan indentasi berjenjang,mirip file explorer} */
void PrintTreeInden(bintree P, int H)
{
    // Kamus lokal
    int i;

    // Algoritma
    if (!IsEmptyTree(P))
    {
        printf("%c\n", info(P));

        if (!IsEmptyTree(GetLeft(P)))
        {
            for (i = 1; i <= H; i++)
            {
                printf("  ");
            }
            PrintTreeInden(GetLeft(P), 2 * H);
        }

        if (!IsEmptyTree(GetRight(P)))
        {
            for (i = 1; i <= H; i++)
            {
                printf("  ");
            }
            PrintTreeInden(GetRight(P), 2 * H);
        }
    }
}

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateAllX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y. Mengganti semua elemen bernilai X menjadi Y}*/
void UpdateAllX(bintree *P, infotype X, infotype Y)
{
    // algoritma
    if (!IsEmptyTree(*P))
    {
        if (info(*P) == X)
        {
            info(*P) = Y;
        }

        if (!IsEmptyTree(GetLeft(*P)))
        {
            UpdateAllX(&left(*P), X, Y);
        }

        if (!IsEmptyTree(GetRight(*P)))
        {
            UpdateAllX(&right(*P), X, Y);
        }
    }
}

/******* PENAMBAHAN ELEMEN bintree ********/
/*procedure AddDaunTerkiri (input/output P : BinTree, input X : infotype)
{ I.S. P boleh kosong }
{ F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri }*/
void AddDaunTerkiri(bintree P, infotype X)
{
    // algoritma
    if (!IsEmptyTree(P))
    {
        if (IsEmptyTree(GetLeft(P)))
        {
            left(P) = Tree(X, NIL, NIL);
        }
        else
        {
            AddDaunTerkiri(GetLeft(P), X);
        }
    }
}

/*procedure AddDaun (input/Output P : BinTree, input X, Y : infotype, input Kiri : boolean)
{ I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P }
{ F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri), atau sebagai anak Kanan X (jika not Kiri) }*/
void AddDaun(bintree P, infotype X, infotype Y, boolean Kiri)
{
    // algoritma
    if (!IsEmptyTree(P))
    {
        if (info(P) == X && IsDaun(P))
        {
            if (Kiri)
            {
                left(P) = Tree(Y, NIL, NIL);
            }
            else
            {
                right(P) = Tree(Y, NIL, NIL);
            }
        }
        else
        {
            if (!IsEmptyTree(GetLeft(P)))
            {
                AddDaun(GetLeft(P), X, Y, Kiri);
            }
            if (!IsEmptyTree(GetRight(P)))
            {
                AddDaun(GetRight(P), X, Y, Kiri);
            }
        }
    }
}

/*procedure InsertX (input/output P : BinTree, input X : infotype)
{ Menghasilkan sebuah pohon P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
void InsertX(bintree *P, infotype X)
{
    // algoritma
    if (IsEmptyTree(*P))
    {
        *P = Tree(X, NIL, NIL);
    }
    else
    {
        if (IsEmptyTree(GetLeft(*P)))
        {
            left(*P) = Tree(X, NIL, NIL);
        }
        else if (IsEmptyTree(GetRight(*P)))
        {
            right(*P) = Tree(X, NIL, NIL);
        }
        else
        {
            InsertX(&left(*P), X);
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*procedure DelDaunTerkiri (input/output P : BinTree, output X : infotype)
{ I.S. P tidak kosong }
{ F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang
semula disimpan pada daun terkiri yang dihapus }*/
void DelDaunTerkiri(bintree *P, infotype X)
{
    // kamus lokal
    bintree temp;

    // algoritma
    if (!IsEmptyTree(*P))
    {
        if (IsDaun(*P))
        {
            X = info(*P);
            temp = *P;
            *P = NIL;
            DealokasiTree(&temp);
        }
        else if (!IsEmptyTree(GetLeft(*P)))
        {
            if (IsDaun(GetLeft(*P)))
            {
                X = info(GetLeft(*P));
                temp = GetLeft(*P);
                left(*P) = NIL;
                DealokasiTree(&temp);
            }
            else
            {
                DelDaunTerkiri(&left(*P), X);
            }
        }
        else if (!IsEmptyTree(GetRight(*P)))
        {
            DelDaunTerkiri(&right(*P), X);
        }
    }
}

/*procedure DelDaun (input/output P : BinTree, input X : infotype)
{ I.S. P tidak kosong, X adalah salah satu daun }
{ F.S. X dihapus dari P }*/
void DelDaun(bintree *P, infotype X)
{
    // kamus lokal
    bintree temp;

    // algoritma
    if (!IsEmptyTree(*P))
    {
        if (IsDaun(*P) && info(*P) == X)
        {
            temp = *P;
            *P = NIL;
            DealokasiTree(&temp);
        }
        else
        {
            if (!IsEmptyTree(GetLeft(*P)))
            {
                if (IsDaun(GetLeft(*P)) && info(GetLeft(*P)) == X)
                {
                    temp = GetLeft(*P);
                    left(*P) = NIL;
                    DealokasiTree(&temp);
                }
                else
                {
                    DelDaun(&left(*P), X);
                }
            }

            if (!IsEmptyTree(GetRight(*P)))
            {
                if (IsDaun(GetRight(*P)) && info(GetRight(*P)) == X)
                {
                    temp = GetRight(*P);
                    right(*P) = NIL;
                    DealokasiTree(&temp);
                }
                else
                {
                    DelDaun(&right(*P), X);
                }
            }
        }
    }
}

/*procedure DeleteX (input/output P : BinTree, input X : infotype)
{ Menghapus simpul bernilai X bila ada dari P, HATI-HATI! }*/
void DeleteX(bintree *P, infotype X)
{
    // kamus lokal
    bintree temp;

    // algoritma
    if (!IsEmptyTree(*P))
    {
        if (info(*P) == X)
        {
            if (IsDaun(*P))
            {
                temp = *P;
                *P = NIL;
                DealokasiTree(&temp);
            }
            else if (IsUnerLeft(*P))
            {
                temp = *P;
                *P = GetLeft(*P);
                DealokasiTree(&temp);
            }
            else if (IsUnerRight(*P))
            {
                temp = *P;
                *P = GetRight(*P);
                DealokasiTree(&temp);
            }
            else
            {
                temp = GetLeft(*P);
                while (!IsEmptyTree(GetRight(temp)))
                {
                    temp = GetRight(temp);
                }
                info(*P) = info(temp);
                DeleteX(&left(*P), info(temp));
            }
        }
        else
        {
            DeleteX(&left(*P), X);
            DeleteX(&right(*P), X);
        }
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*KONSTRUKTOR*/
/*function BuildBalanceTree (n : integer) -> BinTree
{ Menghasilkan balanced tree dengan n node, nilai setiap node dibaca dari keyboard }*/
bintree BuildBalanceTree(int n)
{
    // kamus lokal
    infotype X;

    // algoritma
    if (n == 0)
    {
        return NIL;
    }
    else
    {
        printf("Masukkan karakter: ");
        scanf(" %c", &X);
        return Tree(X, BuildBalanceTree(n / 2), BuildBalanceTree(n - n / 2 - 1));
    }
}

/*PREDIKAT*/
/*function IsBalanceTree (P : BinTree) -> boolean
{ Menghasilkan true jika P seimbang, banyak node kiri ~= kanan }*/
boolean IsBalanceTree(bintree P)
{
    // kamus lokal
    int countLeft, countRight;

    // algoritma
    if (IsEmptyTree(P))
    {
        return TRUE;
    }
    else
    {
        countLeft = NbElm(GetLeft(P));
        countRight = NbElm(GetRight(P));

        if (countLeft == countRight || countLeft == countRight + 1 || countLeft + 1 == countRight)
        {
            return IsBalanceTree(GetLeft(P)) && IsBalanceTree(GetRight(P));
        }
        else
        {
            return FALSE;
        }
    }
}

/* function maxTree(P:bintree)->character
{mengembalikan huruf "maksimal" dari elemen P, A<B<C<..<Z }*/
int maxTree(bintree P)
{
    // kamus lokal
    int maxLeft, maxRight;

    // algoritma
    if (IsEmptyTree(P))
    {
        return 0;
    }
    else if (IsDaun(P))
    {
        return info(P);
    }
    else
    {
        maxLeft = maxTree(GetLeft(P));
        maxRight = maxTree(GetRight(P));

        if (info(P) >= maxLeft && info(P) >= maxRight)
        {
            return info(P);
        }
        else if (maxLeft >= maxRight)
        {
            return maxLeft;
        }
        else
        {
            return maxRight;
        }
    }
}

/* function minTree(P:bintree)->character
{mengembalikan huruf "minimal" dari elemen P, A<B<C<..<Z }*/
int minTree(bintree P)
{
    // kamus lokal
    int minLeft, minRight;

    // algoritma
    if (IsEmptyTree(P))
    {
        return 127;
    }
    else if (IsDaun(P))
    {
        return info(P);
    }
    else
    {
        minLeft = minTree(GetLeft(P));
        minRight = minTree(GetRight(P));

        if (info(P) <= minLeft && info(P) <= minRight)
        {
            return info(P);
        }
        else if (minLeft <= minRight)
        {
            return minLeft;
        }
        else
        {
            return minRight;
        }
    }
}

/*{ Operator KHUSUS Binary Search Tree, node kiri selalu lebih kecil daripada node kanan }

/*function BSearch (P : BinTree, X : infotype) → boolean
{ Mengirimkan true jika ada node dari pohon binary search P yang bernilai X }*/
boolean BSearch(bintree P, infotype X)
{
    // kamus lokal

    // algoritma
    if (IsEmptyTree(P))
    {
        return FALSE;
    }
    else if (info(P) == X)
    {
        return TRUE;
    }
    else if (X < info(P))
    {
        return BSearch(GetLeft(P), X);
    }
    else
    {
        return BSearch(GetRight(P), X);
    }
}

/*function InsSearch (P : BinTree, X : infotype) → BinTree
{ Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
bintree InsSearch(bintree P, infotype X)
{
    // kamus lokal

    // algoritma
    if (IsEmptyTree(P))
    {
        return Tree(X, NIL, NIL);
    }
    else if (X < info(P))
    {
        left(P) = InsSearch(GetLeft(P), X);
        return P;
    }
    else
    {
        right(P) = InsSearch(GetRight(P), X);
        return P;
    }
}

/*procedure DelBtree (input/output P : BinTree, input X : infotype)
{ I.S. Pohon binary search P tidak kosong }
{ F.S. Nilai X yang dihapus pasti ada }
{ Sebuah node dg nilai X dihapus }*/
void DelBtree(bintree *P, infotype X)
{
    // kamus lokal
    bintree temp;

    // algoritma
    if (!IsEmptyTree(*P))
    {
        if (X < info(*P))
        {
            DelBtree(&left(*P), X);
        }
        else if (X > info(*P))
        {
            DelBtree(&right(*P), X);
        }
        else
        {
            if (IsDaun(*P))
            {
                temp = *P;
                *P = NIL;
                DealokasiTree(&temp);
            }
            else if (IsUnerLeft(*P))
            {
                temp = *P;
                *P = GetLeft(*P);
                DealokasiTree(&temp);
            }
            else if (IsUnerRight(*P))
            {
                temp = *P;
                *P = GetRight(*P);
                DealokasiTree(&temp);
            }
            else
            {
                temp = GetLeft(*P);
                while (!IsEmptyTree(GetRight(temp)))
                {
                    temp = GetRight(temp);
                }
                info(*P) = info(temp);
                DelBtree(&left(*P), info(temp));
            }
        }
    }
}
