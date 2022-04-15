/* File : driverListString.h */
/* contoh ADT list berkait dengan representasi fisik pointer */
/* Representasi address dengan pointer */
/* infotype adalah integer */
/* NIM/Nama  : 24060120120012/Adinda Destifany Zenniar*/
/* Tanggal   : 9 November 2021*/
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include "listString.h"

int main(){
    /*Kamus main*/
    List A,B;
    address P,Q,R;
    infotype X,Y;

    /*Algoritma*/
    printf("=====Create List=====\n");
    CreateList(&A);

    P=Alokasi("Jl Kartini");
    InsertFirst(&A,P);
    printf("=====Insert First=====\n");
    PrintInfo(A);
    printf("\n");

    P=Alokasi("Jl Sartini");
    InsertFirst(&A,P);
    printf("=====Insert First=====\n");
    PrintInfo(A);
    printf("\n");

    R=Alokasi("Jl A.Yani");
    InsertLast(&A,R);
    printf("=====Insert Last=====\n");
    PrintInfo(A);
    printf("\n");

    Q=Alokasi("Jl Soekarno");
    InsertAfter(&A,Q,P);
    printf("=====Insert After=====\n");
    PrintInfo(A);
    printf("\n");

    printf("jumlah elemen list = %d\n", NbElmt(A));
    printf("\n");

    DelFirst(&A,&P);
    printf("=====Del First=====\n");
    PrintInfo(A);
    printf("P=%d\n",info(P));
    printf("\n");

    DelLast(&A,&P);
    printf("=====Del Last=====\n");
    PrintInfo(A);
    printf("\n");

    DelAfter(&A,&P,First(A));
    printf("=====Del After=====\n");
    PrintInfo(A);
    printf("\n");

    InsVFirst(&A,"Jl Fatmawati");
    printf("=====Ins V First=====\n");
    PrintInfo(A);
    printf("\n");

    InsVLast(&A,"Jl Fatahillah");
    printf("=====Ins V Last=====\n");
    PrintInfo(A);
    printf("\n");

    InsVAfter(&A,"Jl Hatta");
    printf("=====Ins V After=====\n");
    PrintInfo(A);
    printf("\n");

    if(ListEmpty(A)){
        printf("List kosong\n");
    }
    else{
        printf("List tidak kosong\n");
    }
    printf("\n");

    DelVFirst(&A,&Y);
    printf("=====Del V First=====\n");
    PrintInfo(A);
    printf("Y=%d\n",Y);
    printf("\n");

    DelVLast(&A,&Y);
    printf("=====Del V Last=====\n");
    PrintInfo(A);
    printf("Y=%d\n",Y);
    printf("\n");

    DelVAfter(&A,&Y);
    printf("=====Del V After=====\n");
    PrintInfo(A);
    printf("Y=%d\n",Y);
    printf("\n");

    return 0;
}

