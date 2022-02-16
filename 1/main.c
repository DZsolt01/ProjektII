#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void levelekSzama(int * fokszamok, int csomopontok){
    printf("\nLevelek szama:");
    for(int i = 1; i <= csomopontok; ++i){
        if(fokszamok[i] == 1){
            printf("%i ", i);
        }
    }
}

void izolaltPontok(const int* in, const int* out, int csomopontok){
    printf("\nIzolalt pontok:");
    for(int i = 1; i <= csomopontok; ++i){
        if(in[i] == 0 && out[i] == 0){
            printf("%i ", i);
        }
    }
}

bool szuperForras(const int* in, const int* out, int csomopontok){
    for(int i = 1; i <= csomopontok; ++i){
        if( (in[i] != 0 && out[i] == csomopontok-1) || (in[i] == 1 && out[i] == 0)){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}

int szuperNyelo(const int* in, const int* out, int csomopontok){
    for(int i = 1; i <= csomopontok; ++i){
        if( (in[i] == csomopontok-1 && out[i] == 0) || (in[i] == 0 && out[i] == 1)){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}

void nyelo(const int* in, const int* out, int csomopontok){ //REALLOC int array
        printf("\nNyelok:");
        for(int i = 1; i <= csomopontok; ++i){
            if(in[i] > 0 && out[i] == 0){
                printf("%i ", i);
            }
        }
}

void forras(const int* in, const int* out, int csomopontok){ //REALLOC int array
    printf("\nForrasok:");
    for(int i = 1; i <= csomopontok; ++i){
        if(in[i] == 0 && out[i] > 0){
            printf("%i ", i);
        }
    }
}


bool teljesGrafe(const int* fokszamok, int csomopont){
    for(int i = 1; i <= csomopont; ++i){
        if(fokszamok[i] != csomopont-1){
            return false;
        }
    }
    return true;
}

int main() {
    FILE *file;
    file = fopen("be.txt", "rt");
    if(file == NULL){
        printf("File not found!");
        return -1;
    }
    int csomopont, el;
    fscanf(file, "%i%i", &csomopont, &el);
    printf("%i csomopont ; %i el\n", csomopont, el);

    int * fokszamok = (int*)calloc(csomopont+1, sizeof(int));
    int * inFok = (int*)calloc(csomopont+1, sizeof(int));
    int * outFok = (int*)calloc(csomopont+1, sizeof(int));


    for(int i = 0; i < el; ++i){
        int in,out;
        fscanf(file, "%i%i", &in, &out);
        inFok[out]++;
        outFok[in]++;
        fokszamok[in]++;
        fokszamok[out]++;
    }
    for(int i = 1; i <= csomopont; ++i){
        printf("%i csomopont: %i\n", i, fokszamok[i]);
    }
    printf("KI fokszamok:\n");
    for(int i = 1; i <= csomopont; ++i){
        printf("%i csomopont: %i\n", i, outFok[i]);
    }
    printf("BE fokszamok:\n");
    for(int i = 1; i <= csomopont; ++i){
        printf("%i csomopont: %i\n", i, inFok[i]);
    }

    if(teljesGrafe(fokszamok, csomopont)){
        printf("Teljes graf!\n");
    }
    else{
        printf("Nem teljes graf!\n");
    }
    forras(inFok,outFok,csomopont);
    nyelo(inFok, outFok, csomopont);
    if(szuperForras(inFok,outFok, csomopont)){
        printf("\nVan szuperforras!");
    }
    if(szuperNyelo(inFok, outFok, csomopont)){
        printf("\nVan szupernyelo!");
    }
    izolaltPontok(inFok, outFok, csomopont);
    levelekSzama(fokszamok, csomopont);


    return 0;
}