//
// Created by S2290 on 18/11/2017.
//
#include "File.h"

FILE *FILE_apri_file(int MAX_FILENAME_SIZE, char *TYPE) {
    FILE *fp=NULL;
    int TYPE_ERR=strcmp("w",TYPE)*strcmp("r",TYPE)*strcmp("rw",TYPE);
    assert(TYPE_ERR==0);
    char* nomefile;
    do{
        printf("Inserire il nome del file...\n");
        fgets(nomefile,MAX_FILENAME_SIZE,stdin);
        fp=fopen(nomefile,TYPE);
        if (fp==NULL){
            printf("File non aperto/creato correttamente... Riprovare");
        }
    }   while (fp==NULL);
    return fp;
}
