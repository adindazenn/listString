/* File : listString.c */
/* contoh ADT list berkait dengan representasi fisik pointer */
/* Representasi address dengan pointer */
/* infotype adalah integer */
/* NIM/Nama  : 24060120120012/Adinda Destifany Zenniar*/
/* Tanggal   : 9 November 2021*/
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include "listString.h"

/*Prototype*/
/* ----- Test List Kosong ----- */
/* Mengirim true jika list kosong */
boolean ListEmpty (List L){
    /*Kamus lokal*/

    /*Algoritma*/
    return First(L)==Nil;
}

/* ----- Pembuatan List Kosong ----- */
/* I.S.		: sembarang
   F.S.		: Terbentuk list kosong */
void CreateList (List *L){
    /*Kamus lokal*/

    /*Algoritma*/
    First(*L)=Nil;
}

/* ----- Manajemen Memori ----- */
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil,
   dan misalnya menghasilkan P, maka
   Info(P) = X, Next(P) = Nil
   Jika alokasi gagal, mengirimkan Nil */
address Alokasi (infotype X){
    /*Kamus lokal*/
    address P;

    /*Algoritma*/
    P = (address) malloc(sizeof(ElmtList));
    if (P != Nil )
    {
        info(P) = X;
        next(P) = Nil;
    }
    return P;
}

/* I.S.		: P terdefinisi
   F.S.		: P dikembalikan ke sistem
   Melakukan dealokasi/pengembalian address P */
void Dealokasi (address *P){
    /*Kamus lokal*/

    /*Algoritma*/
    info(*P)=0;
    next(*P)=Nil;
    free(*P);
}

/* ----- Primitif Berdasarkan Alamat ------ */
/* Penambahan Elemen Berdasarkan Alamat */
/* I.S. 	: Sembarang, P sudah dialokasi
   F.S.		: Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertFirst (List *L, address P){
    /*Kamus lokal*/

    /*Algoritma*/
    next(P)=First(*L);
    First(*L)=P;
}

/* I.S.		: Prec pastilah elemen list dan bukan elemen terakhir,
			  P sudah dialokasi
   F.S. 	: Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertAfter (List *L, address P, address Prec){
    /*Kamus lokal*/

    /*Algoritma*/
    next(P)=next(Prec);
    next(Prec)=P;
}

/* I.S.		: Sembarang, P sudah dialokasi
   F.S.		: P ditambahkan sebagai elemen terakhir yang baru */
void InsertLast (List *L, address P){
    /*Kamus lokal*/
    address Last;

    /*Algoritma*/
    if(First(*L)==Nil){
        InsertFirst(&(*L),P);
    }
    else{
        Last=First(*L);
        while(next(Last)!=Nil){
            Last=next(Last);
        }
        InsertAfter(&(*L),P,Last);
    }
}

/* Penghapusan Sebuah Elemen */
/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen pertama list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              First element yang baru adalah suksesor elemen pertama yang
              lama */
void DelFirst (List *L, address *P){
    /*Kamus lokal*/

    /*Algoritma*/
    *P=First(*L);
    First(*L)=next(First(*L));
}

/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen terakhir list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              Last element baru adalah predesesor elemen pertama yang
              lama, jika ada */
void DelLast (List *L, address *P){
    /*Kamus lokal*/
    address Last, PrecLast;

    /*Algoritma*/
    Last=First(*L);
    PrecLast=Nil;
    while(next(Last)!=Nil){
        PrecLast=Last;
        Last=next(Last);
    }
    *P=Last;
    if(PrecLast==Nil){
        First(*L)=Nil;
    }
    else{
        next(PrecLast)=Nil;
    }
}

/* I.S.     : List tidak kosong. Prec adalah anggota list L.
   F.S.     : Menghapus Next(Prec :
              Pdel adalah alamat elemen list yang dihapus*/
void DelAfter (List *L, address * Pdel, address Prec){
    /*Kamus lokal*/

    /*Algoritma*/
    *Pdel=next(Prec);
    next(Prec)=next(next(Prec));
    next(*Pdel)=Nil;
}

/* ----- Primitif Berdasarkan Nilai ----- */
/* Penambahan Elemen */
/* I.S.		: L mungkin kosong
   F.S. 	: X ditambahkan sebagai elemen pertama L
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen
   			  pertama dengan nilai X jika alokasi berhasil.
   			  Jika alokasi gagal, maka I.S.= F.S. */
void InsVFirst (List *L, infotype X){
    /*Kamus lokal*/
    address P;

    /*Algoritma*/
    P=Alokasi(X);
    if(P!=Nil){
        next(P)=First(*L);
        First(*L)=P;
    }
}

/* I.S. 	: L mungkin kosong
   F.S.		: X ditambahkan sebagai elemen terakhir L
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen list
   			  di akhir yaitu
   			  jika alokasi berhasil, elemen terakhir yang baru bernilai X
   			  Jika alokasi gagal, maka I.S.= F.S. */
void InsVLast (List *L, infotype X){
    /*Kamus lokal*/
    address P;

    /*Algoritma*/
    P=Alokasi(X);
    if(P!=Nil){
        InsertLast(&(*L),P);
    }
}

/* I.S. 	: L mungkin kosong
   F.S.		: X ditambahkan sebagai elemen setelah Prec
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen list
   			  setelah Prec yaitu
   			  jika alokasi berhasil, elemen setelah Prec yang baru bernilai X
   			  Jika alokasi gagal, maka I.S.= F.S. */
void InsVAfter (List *L, infotype X){
    /*Kamus lokal*/
    address P,Prec,Last;

    /*Algoritma*/
    if(!ListEmpty(*L)){
        AdrLast(&(*L),&Prec,&Last);
        P=Alokasi(X);
        if(P!=Nil){
            InsertAfter(&(*L),P,Prec);
        }
    }
    else{
        InsVFirst(&(*L),X);
    }
}

/*mencari alamat elemen terakhir dan sebelumnya*/
void AdrLast(List *L, address *Prec, address *Last){
    /*Kamus lokal*/

    /*Algoritma*/
    *Last=First(*L);
    *Prec=Nil;
    while(next(*Last)!=Nil){
        *Prec=*Last;
        *Last=next(*Last);
    }
}

/* Penghapusan ELemen */
/* I.S.		: List L tidak kosong
   F.S.		: Elemen pertama list dihapus den nilai info disimpan pada X
   			 dan alamat elemen pertama di-dealokasi */
void DelVFirst (List *L, infotype *X){
    /*Kamus lokal*/
    address P;

    /*Algoritma*/
    P=First(*L);
    *X=info(P);
    First(*L)=next(P);
    Dealokasi(&P);
}

/* I.S.		: List L tidak kosong
   F.S.		: Elemen terakhir list dihapus : nilai info disimpan pada X
   			  dan alamat elemen terakhir di-dealokasi */
void DelVLast (List *L, infotype *X){
    /*Kamus lokal*/
    address P,Prec,Last;

    /*Algoritma*/
    DelLast(&(*L),&P);
    *X=info(P);
    Dealokasi(&P);
}

/* I.S.		: List L tidak kosong
   F.S.		: Elemen list setelah Prec dihapus : nilai info disimpan pada X
   			  dan alamat elemen setelah Prec di-dealokasi */
void DelVAfter (List *L, infotype *X){
    /*Kamus lokal*/
    address P, Prec, Last;

    /*Algoritma*/
    AdrLast(&(*L),&Prec,&Last);
    DelAfter(&(*L),&P,Prec);
    *X=info(P);
    Dealokasi(&P);
}

/* ----- Proses Semua Elemen List ----- */
/* I.S.     : List mungkin kosong
   F.S.     : Jika list tidak kosong, semua info yg disimpan pada elemen
              list diprint
              Jika list kosong, hanya menuliskan "list kosong" */
void PrintInfo (List L){
    /*Kamus lokal*/
    address P;

    /*Algoritma*/
    if(ListEmpty(L)){
        printf("list kosong\n");
    }
    else{
        P=First(L);
        while(P!=Nil){
            printf("%s -> ", info(P));
            P=next(P);
        }
        printf("\n");
    }
}

/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
int NbElmt (List L){
    /*Kamus lokal*/
    address P;
    int num;

    /*Algoritma*/
    num = 0;
    P = First(L);
    while(P!=Nil){
        num++;
        P = next(P);
    }
    return num;
}
