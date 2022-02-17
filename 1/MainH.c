//
// Created by deak.zsolt on 2/17/2022.
//

#include "Labor1.h"

int main(){
    FILE* file;
    file = fopen("be.txt", "rt");
    if(file == NULL){
        printf("File not found!");
        exit -1;
    }
    int csomopont, el;
    fscanf(file, "%i%i", &csomopont, &el);
    EL* elLista = (EL*)malloc((csomopont+1)*sizeof(EL));
    int **matrix = (int**)(calloc(csomopont+1, sizeof(int*)));
    for(int i = 0; i <= csomopont; ++i){
        matrix[i] = (int*)(calloc(csomopont+1, sizeof(int)));
    }
    //ellista_iranyitatlan(file, elLista, el);
    szomszdsagi_matrix_iranyitatlan(file, matrix, el);
    szomszdsagi_matrix_iranyitott(file, matrix,el);
    //kiir_tomb(elLista, el);
    kiir_matrix(matrix, csomopont);
}