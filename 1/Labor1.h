//
// Created by deak.zsolt on 2/17/2022.
//

#ifndef PROG2_LABOR1_H
#define PROG2_LABOR1_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


typedef struct{
    int in,out;
}EL;

void ellista_iranyitatlan(FILE* file, EL* elLista, int el);
void ellista_iranyitott(FILE * file, EL* elLista, int el);
void szomszdsagi_matrix_iranyitatlan(FILE* file, int**matrix, int el);
void szomszdsagi_matrix_iranyitott(FILE* file, int**matrix, int el);
void szomszedsagi_lista_iranyitatlan();
void szomszedsagi_lista_iranyitott();
void fokszamok_iranyiatlan();
void ki_be_fokszam_iranyitott();
bool teljes_graf_iranyitatlan();
void forrasok_iranyitott();
void nyelok_iranyitott();
int szuperforras_iranyitott();
int szupernyelo_iranyitott();
bool van_e_izolalt_iranyitatlan();
bool van_e_level_iranyitatlan();
void csucsmatrixol_ellista_iranyitatlan();
void kiir_matrix(int** matrix, int csomopont);
void kiir_tomb(EL* elLista, int csomopont);


#endif //PROG2_LABOR1_H
