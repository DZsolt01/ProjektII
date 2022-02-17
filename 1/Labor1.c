//
// Created by deak.zsolt on 2/17/2022.
//

#include "Labor1.h"

void ellista_iranyitatlan(FILE * file, EL* elLista, int el){
    for(int i = 1; i <= el; ++i){
        int in, out;
        fscanf(file, "%i%i", &in, &out);
        elLista[i].in = out;
        elLista[i].out = in;
    }
}
void ellista_iranyitott(FILE * file, EL* elLista, int el){
    for(int i = 1; i <= el; ++i){
        int in, out;
        fscanf(file, "%i%i", &in, &out);
        elLista[i].in = out;
        elLista[i].out = in;
    }
}

void szomszdsagi_matrix_iranyitatlan(FILE* file, int**matrix, int el){
    for(int i = 1; i <= el; ++i){
        int in, out;
        fscanf(file, "%i%i", &in, &out);
        matrix[in][out]++;
        matrix[out][in]++;
    }
}
void szomszdsagi_matrix_iranyitott(FILE* file, int**matrix, int el){
    for(int i = 1; i <= el; ++i){
        int in, out;
        fscanf(file, "%i%i", &in, &out);
        matrix[in][out]++;
    }
}
void kiir_matrix(int** matrix, int csomopont){
    for(int i =1; i <= csomopont; ++i){
        for(int j = 1; j <= csomopont; ++j){
            printf("%i ", matrix[i][j]);
        }
        printf("\n");
    }
}

void kiir_tomb(EL* elLista, int el){
    for(int i=1; i <= el; ++i){
        printf("%i - %i\n", elLista[i].out, elLista[i].in);
    }
}