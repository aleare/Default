#include "libreria_principale.h"

void hello_world(void) {
    printf("Hello, World!\n");
}
//Funzioni su FILE [FILE]

int FILE_leggi_file_caratteri(FILE *fp, int r, int c, char mat[MAX_MAT_R][MAX_MAT_C]) {
    assert(fp!=NULL); assert(r<MAX_MAT_R+1); assert(c<MAX_MAT_C+1);
    char ch; //Carattere di debug
    int n=0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (feof(fp))
                return -1;
            ch=fgetc(fp);
            mat[i][j]=ch;
            ch=fgetc(fp); //Legge spazio o /n
        }
        fgetc(fp); //Legge /r
        n++;
    }
    return n;
}
int FILE_leggi_file_dec(FILE *fp, int r, int c, int mat[MAX_MAT_R][MAX_MAT_C]) {
    assert(fp!=NULL); assert(r<MAX_MAT_R+1); assert(c<MAX_MAT_C+1);
    int n=0; //Carattere di debug
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (feof(fp))
                return -1;
            fscanf(fp," %d ",&mat[i][j]);
            n++;
        }
    }
    return n;
}
int FILE_leggi_file_float(FILE *fp, int r, int c, float mat[MAX_MAT_R][MAX_MAT_C]) {
    assert(fp!=NULL); assert(r<MAX_MAT_R+1); assert(c<MAX_MAT_C+1);
    int n=0; //Carattere di debug
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (feof(fp))
                return -1;
            fscanf(fp," %d ",&mat[i][j]);
            n++;
        }
    }
    return n;
}
//Funzioni di ricerca [find]
int find_ricerca_stringa_matrice(const char mat[MAX_MAT_R][MAX_MAT_C], int r, int c, char *s) {
    int t=0; int k=0; int grandezza=strlen(s);
    assert(s!=NULL);
    assert(mat!=NULL);
    assert(grandezza<MAX_MAT_R&&grandezza<MAX_MAT_C);
    //Ricerca per Righe
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (mat[i][j]==s[k]){
                k++;
                if (k==grandezza){
                    t++; k=0;
                }
            }
            else{
                k=0;
                if(mat[i][j]==s[0]) //Se il primo elemento è giusto...
                    k=1;
            }
        }
    }
    //Ricerca per Colonne
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < r; ++j) {
            if (mat[j][i]==s[k]){
                k++;
                if (k==grandezza){
                    t++; k=0;
                }
            }
            else{
                k=0;
                if(mat[j][i]==s[0]) //Se il primo elemento è giusto...
                    k=1;
            }
        }
    }
    return t;
}
//Funzioni su Vettori [vett]
int vett_crea_vettore_tastiera(int *v) {
    int d; //Dimensione del vettore da inserire
    assert(v!=NULL);
    do{
        printf("Inserire la dimensione del vettore:\n");
        fscanf(stdin,"%d",&d);
        if(d<0) printf("Dimensione Errata! Riprovare...\n");
    } while (d<0);
    printf("Inserire i dati del vettore:\n");
    for (int i = 0; i < d; ++i) {
        fscanf(stdin,"%d",&v[i]);
    }
    //Debug
#ifdef DEBUG
    printf("Il vettore acquisito e'...:\n");
#endif
    for (int i = 0; i < d; ++i) {
        printf("%d ",v[i]);
    }
    printf("\n");
    return d;
}
int vett_crea_vettore_tastiera_DMAX(int *v, const int DMAX) {
    assert(v!=NULL);
    int d; //Dimensione del vettore da inserire
    do{
        printf("Inserire la dimensione del vettore:\n");
        fscanf(stdin,"%d",&d);
        if(d<0) printf("Dimensione Errata! Riprovare...\n");
        if(d>DMAX) printf("La dimensione supera quella massima consentita! Riprovare...\n");
    } while (d<0||d>DMAX);
    printf("Inserire i dati del vettore:\n");
    for (int i = 0; i < d; ++i) {
        fscanf(stdin,"%d",&v[i]);
    }
    //Debug
#ifdef DEBUG
    printf("Il vettore acquisito e'...:\n");
    for (int i = 0; i < d; ++i) {
        printf("%d ",v[i]);
    }
    printf("\n");
#endif
    return d;
}
int vett_media_mobile(const int *V, int dim, int k, float *M) {
    assert(V!=NULL); assert(M!=NULL);
    assert(sizeof(V)==sizeof(M));
    float media=0;
    for (int i = 0; i < dim - 1; ++i) {
        for (int j = i; j < i+k; ++j) {
            media=media+V[j];
        }
        M[i]=media/k;
        media=0;
    }
    return 0;
}
void vett_stampa_vettore(int *v, int dim) {
    for (int i = 0; i < dim; ++i) {
        printf("%d ",v[i]);
    }
}
void vett_stampa_vettore_float(float *v, int dim) {
    for (int i = 0; i < dim; ++i) {
        printf("%f ",v[i]);
    }
}
void vett_stampa_vettore_l_r_float(float v[], int l, int r) {
    for (int i = l; i < r+1; ++i) {
        printf("%f ",v[i]);
    }
}
void vett_stampa_vettore_l_r(int v[], int l, int r) {
    for (int i = l; i < r+1; ++i) {
        printf("%d ",v[i]);
    }
}
//Funzioni su Insiemi [ins]
void ins_crea_insieme(int *v, int size) {
    assert(v!=NULL);
    assert(MAX_VETT>size);
    int v1[MAX_VETT];
    int insieme[MAX_VETT]={0};
    if(size>MAX_VETT){
        fprintf(stderr,"La dimensione del vettore supera quella massima... Aggiornare le costanti della libreria!");
        exit(EXIT_FAILURE);
    }
    int f=0,k=0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if(v[i]==insieme[j]) f=1;
        }
        if (v[i]!=0&&f!=1){
            insieme[k]=v[i];
            k++;
        }
        f=0;
    }
    for (int l = 0; l < size; ++l) {
        v[l]=insieme[l];
    }
}
int ins_intersezione_insiemi(const int *v1, const int *v2, int *res, int size) { //Funzione usata nelle altre funzioni
    assert(v1!=NULL&&v2!=NULL&&res!=NULL);
    int k=0; //Usato per res
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (v1[i] == v2[j] && v1[i] != 0) {
                res[k] = v1[i];
                k++;
            }
        }
    }
    if(k==0){ return 1;}
    else {return 0;}
}
int ins_stampa_unione_insiemi(int *v1, int *v2, int size) { //Dato che non richiesto, la stampa avviene non in ordine, ma un sort è facilmente implementabile con l'utilizzo di un vettore all'interno di questa funzione
    int inter[MAX_VETT]={0}; //Vettore Intersezione
    assert(v1!=NULL&&v2!=NULL);
    assert(MAX_VETT>size);
    int f=0; //Flag
    printf("L'unione di A e B e'...:\n");
    if(ins_intersezione_insiemi(v1, v2, inter, size)==1){ //Trova A int. B in inter. Se l'int. è vuota passa subito all'unione
        for (int i = 0; i < size; ++i) {
            if (v1[i]!=0) printf("%d",v1[i]);
        }
        for (int i = 0; i < size; ++i) {
            if (v2[i]!=0)   printf("%d",v2[i]);
        }
        return 1;
    }
    else {  //Se l'int. non è vuota ...
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if(v1[i]==inter[j]) f=1;
            }
            if (f!=1)   printf("%d ",v1[i]);
            f=0; //Reset Flag
            for (int j = 0; j < size; ++j) {
                if(v2[i]==inter[j]) f=1;
            }
            if (f!=1)   printf("%d ",v2[i]);
            f=0; //Reset Flag
        }
        for (int k = 0; k < size && inter[k]!=0; ++k) { //Stampa gli elementi dell'intersezione
            printf("%d ",inter[k]);
        }
        return 0;
    }
    printf("\n");
}
int ins_unione_insiemi(int *v1, int *v2, int *u, int size) {//Il vettore creato non è ordinato
    assert(MAX_VETT>size);
    assert(v1!=NULL&&v2!=NULL&&u!=NULL);
    int inter[MAX_VETT]={0}; //Vettore Intersezione
    int f=0; //Flag
    int l=0;
    //Come si capisce la dimensione max del vettore?
    printf("L'unione di A e B e'...:\n");
    if(ins_intersezione_insiemi(v1, v2, inter, size)==1){ //Trova A int. B in inter. Se l'int. è vuota passa subito all'unione
        for (int i = 0; i < size; ++i) {
            if (v1[i]!=0){ u[l]=v1[i]; l++; }
        }
        for (int i = 0; i < size; ++i) {
            if (v2[i]!=0){ u[l]=v2[i]; l++; }
        }
        return 1;
    }
    else {  //Se l'int. non è vuota ...
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if(v1[i]==inter[j]) f=1;
            }
            if (f!=1)  { u[l]=v1[i]; l++; }
            f=0; //Reset Flag
            for (int j = 0; j < size; ++j) {
                if(v2[i]==inter[j]) f=1;
            }
            if (f!=1)   { u[l]=v2[i]; l++; }
            f=0; //Reset Flag
        }
        for (int k = 0; k < size && inter[k]!=0; ++k) { //Stampa gli elementi dell'intersezione
            { u[l]=inter[k]; l++; }
        }
        return 0;
    }
}
//Funzioni di selezione [sel]
int selezione_stringa_2(char *string1, char *string2) {
    int OVER_LNG=strlen(string1)<MAX_STR&&strlen(string2)<MAX_STR;
    assert(OVER_LNG);
    char scelta[MAX_STR]; int f=0;
    //Rendo le scelte in minuscolo
    for (int i = 0; i < strlen(string1); ++i) {
        string1[i]=tolower(string1[i]);;
    }
    for (int j = 0; j < strlen(string2); ++j) {
        string2[j]=tolower(string2[j]);
    }
    //Acquisisco la scelta...
    scanf("%s",scelta);
    for (int k = 0; k < strlen(scelta); ++k) {
        scelta[k]=tolower(scelta[k]);
    }
    if(!strcmp(string1,scelta)) f=1;
    else if(!strcmp(string2,scelta)) f=2;
    else f=0;
    return f;
}
int selezione_stringa_3(char *string1, char *string2, char *string3) {
    int OVER_LNG=strlen(string1)<MAX_STR&&strlen(string2)<MAX_STR&&strlen(string3)<MAX_STR;
    assert(OVER_LNG);
    char scelta[MAX_STR]; int f=0;
    //Rendo le scelte in minuscolo
    for (int a = 0; a < strlen(string1); ++a) {
        string1[a]=tolower(string1[a]);
    }
    for (int b = 0; b < strlen(string2); ++b) {
        string2[b]=tolower(string2[b]);
    }
    for (int c = 0; c < strlen(string3); ++c) {
        string3[c]=tolower(string3[c]);
    }
    //Acquisisco la scelta...
    scanf("%s",scelta);
    for (int k = 0; k < strlen(scelta); ++k) {
        scelta[k]=tolower(scelta[k]);
    }
    if(!strcmp(string1,scelta)) f=1;
    else if(!strcmp(string2,scelta)) f=2;
    else if(!strcmp(string3,scelta)) f=3;
    else f=0;
    return f;
}
int selezione_stringa_4(char *string1, char *string2, char *string3, char *string4) {
    int OVER_LNG=strlen(string1)<MAX_STR&&strlen(string2)<MAX_STR&&strlen(string3)<MAX_STR&&strlen(string4)<MAX_STR;
    assert(OVER_LNG);
    char scelta[MAX_STR]; int f=0;
    //Rendo le scelte in minuscolo
    for (int a = 0; a < strlen(string1); ++a) {
        string1[a]=tolower(string1[a]);
    }
    for (int b = 0; b < strlen(string2); ++b) {
        string2[b]=tolower(string2[b]);
    }
    for (int c = 0; c < strlen(string3); ++c) {
        string3[c]=tolower(string3[c]);
    }
    for (int d = 0; d < strlen(string4); ++d) {
        string4[d]=tolower(string4[d]);
    }
    //Acquisisco la scelta...
    scanf("%s",scelta);
    for (int k = 0; k < strlen(scelta); ++k) {
        scelta[k]=tolower(scelta[k]);
    }
    if(!strcmp(string1,scelta)) f=1;
    else if(!strcmp(string2,scelta)) f=2;
    else if(!strcmp(string3,scelta)) f=3;
    else if(!strcmp(string4,scelta)) f=4;
    else f=0;
    return f;
}
int selezione_stringa_5(char *string1, char *string2, char *string3, char *string4, char *string5) {
    int OVER_LNG=strlen(string1)<MAX_STR&&strlen(string2)<MAX_STR&&strlen(string3)<MAX_STR&&strlen(string4)<MAX_STR&&strlen(string5)<MAX_STR;
    assert(OVER_LNG);
    char scelta[MAX_STR]; int f=0;
    //Rendo le scelte in minuscolo
    for (int a = 0; a < strlen(string1); ++a) {
        string1[a]=tolower(string1[a]);
    }
    for (int b = 0; b < strlen(string2); ++b) {
        string2[b]=tolower(string2[b]);
    }
    for (int c = 0; c < strlen(string3); ++c) {
        string3[c]=tolower(string3[c]);
    }
    for (int d = 0; d < strlen(string4); ++d) {
        string4[d]=tolower(string4[d]);
    }
    for (int e = 0; e < strlen(string5); ++e) {
        string5[e]=tolower(string5[e]);
    }
    //Acquisisco la scelta...
    scanf("%s",scelta);
    for (int k = 0; k < strlen(scelta); ++k) {
        scelta[k]=tolower(scelta[k]);
    }
    if(!strcmp(string1,scelta)) f=1;
    else if(!strcmp(string2,scelta)) f=2;
    else if(!strcmp(string3,scelta)) f=3;
    else if(!strcmp(string4,scelta)) f=4;
    else if(!strcmp(string5,scelta)) f=5;
    else f=0;
    return f;
}
int selezione_stringa_6(char *string1, char *string2, char *string3, char *string4, char *string5, char *string6) {
    int OVER_LNG=strlen(string1)<MAX_STR&&strlen(string2)<MAX_STR&&strlen(string3)<MAX_STR&&strlen(string4)<MAX_STR&&
                 strlen(string5)<MAX_STR&&strlen(string6)<MAX_STR;
    assert(OVER_LNG);
    char scelta[MAX_STR]; int f=0;
    //Rendo le scelte in minuscolo
    for (int a = 0; a < strlen(string1); ++a) {
        string1[a]=tolower(string1[a]);
    }
    for (int b = 0; b < strlen(string2); ++b) {
        string2[b]=tolower(string2[b]);
    }
    for (int c = 0; c < strlen(string3); ++c) {
        string3[c]=tolower(string3[c]);
    }
    for (int d = 0; d < strlen(string4); ++d) {
        string4[d]=tolower(string4[d]);
    }
    for (int e = 0; e < strlen(string5); ++e) {
        string5[e]=tolower(string5[e]);
    }
    for (int g = 0; g < strlen(string6); ++g) {
        string6[g]=tolower(string6[g]);
    }
    //Acquisisco la scelta...
    scanf("%s",scelta);
    for (int k = 0; k < strlen(scelta); ++k) {
        scelta[k]=tolower(scelta[k]);
    }
    if(!strcmp(string1,scelta)) f=1;
    else if(!strcmp(string2,scelta)) f=2;
    else if(!strcmp(string3,scelta)) f=3;
    else if(!strcmp(string4,scelta)) f=4;
    else if(!strcmp(string5,scelta)) f=5;
    else if(!strcmp(string6,scelta)) f=6;
    else f=0;
    return f;
}
int selezione_stringa_7(char *string1, char *string2, char *string3, char *string4, char *string5, char *string6,
                        char *string7) {
    int OVER_LNG=strlen(string1)<MAX_STR&&strlen(string2)<MAX_STR&&strlen(string3)<MAX_STR&&strlen(string4)<MAX_STR&&
                 strlen(string5)<MAX_STR&&strlen(string6)<MAX_STR&&strlen(string7)<MAX_STR;
    assert(OVER_LNG);
    char scelta[MAX_STR]; int f=0;
    //Rendo le scelte in minuscolo
    for (int a = 0; a < strlen(string1); ++a) {
        string1[a]=tolower(string1[a]);
    }
    for (int b = 0; b < strlen(string2); ++b) {
        string2[b]=tolower(string2[b]);
    }
    for (int c = 0; c < strlen(string3); ++c) {
        string3[c]=tolower(string3[c]);
    }
    for (int d = 0; d < strlen(string4); ++d) {
        string4[d]=tolower(string4[d]);
    }
    for (int e = 0; e < strlen(string5); ++e) {
        string5[e]=tolower(string5[e]);
    }
    for (int g = 0; g < strlen(string6); ++g) {
        string6[g]=tolower(string6[g]);
    }
    for (int h = 0; h < strlen(string7); ++h) {
        string7[h]=tolower(string7[h]);
    }
    //Acquisisco la scelta...
    scanf("%s",scelta);
    for (int k = 0; k < strlen(scelta); ++k) {
        scelta[k]=tolower(scelta[k]);
    }
    if(!strcmp(string1,scelta)) f=1;
    else if(!strcmp(string2,scelta)) f=2;
    else if(!strcmp(string3,scelta)) f=3;
    else if(!strcmp(string4,scelta)) f=4;
    else if(!strcmp(string5,scelta)) f=5;
    else if(!strcmp(string6,scelta)) f=6;
    else if(!strcmp(string7,scelta)) f=7;
    else f=0;
    return f;
}
int str_toalnum(char *s) {
    char s1[MAX_VETT]={'\0'};  int j=0;  int f=0;  int x;
    assert(strlen(s)<MAX_VETT);
    assert(s!=NULL);
    for (int i = 0; i < strlen(s); ++i) {
        if (isalnum(s[i])){s1[j]=s[i]; j++; f++;}
    }
    if(f==0) {fprintf(stderr,"\nLa stringa era gia' alfanumerica...\n"); return f;} //Debug
    else
#ifdef DEBUG
        fprintf(stderr,"\nIl numero di caratteri modificati e'... %d\n",f);
#endif
    x=strlen(s);
    for (int l = 0; l <x; ++l) {
        s[l]='\0';
    }
    for (int k = 0; k < strlen(s1); ++k) {
        s[k]=s1[k];
    }
    return strlen(s);
}
int str_toupper(char *s) {
    char s1[MAX_VETT]; int j=0; int f=0;
    assert(strlen(s)<MAX_VETT);
    assert(s!=NULL);
    str_toalnum(s);
    for (int i = 0; i < strlen(s); ++i) {
        if (!isupper(s[i])){
            s[i]=toupper(s[i]);
            f++;
        }
    }
    if(f==0) {
#ifdef DEBUG
        fprintf(stderr,"\nLa stringa era gia' minuscola...\n"); //Debug
#endif
        return f;
    }
    else{
#ifdef DEBUG
        fprintf(stderr,"\nIl numero di caratteri modificati e'... %d\n",f); //Debug
#endif
        return strlen(s);
    }
}
int str_tolower(char *s) {
    char s1[MAX_VETT]; int j=0; int f=0;
    assert(strlen(s)<MAX_VETT);
    assert(s!=NULL);
    str_toalnum(s);
    for (int i = 0; i < strlen(s); ++i) {
        if (!islower(s[i])){
            s[i]=tolower(s[i]);
            f++;
        }
    }
    if(f==0) {
#ifdef DEBUG
        fprintf(stderr,"\nLa stringa era gia' maiuscola...\n"); //Debug
#endif
        return f;
    }
    else{
#ifdef DEBUG
        fprintf(stderr,"\nIl numero di caratteri modificati e'... %d\n",f); //Debug
#endif
        return strlen(s);
    }
}

int stampa_matrice_dec(int r, int c, const int mat [MAX_MAT_R][MAX_MAT_C]) {
    assert(c<MAX_MAT_R+1&&r<MAX_MAT_R+1);
    assert(r>1&c>1);
    assert(*mat!=NULL);
    printf(" ");
    for (int i = 0; i < (c * 3) + c - 1; ++i) {
        printf("_");
    }
    printf("\n");
    for (int j = 0; j < r; ++j) {
        for (int k = 0; k < c; ++k) {
            if (mat[j][k]<10&&mat[j][k]>-10) printf("| %d ",mat[j][k]);
            else if (mat[j][k]<100&&mat[j][k]>-100) printf("| %d",mat[j][k]);
            else if (mat[j][k]<1000&&mat[j][k]>-1000) printf("|%d",mat[j][k]);
            else return -1;
        }
        printf("|\n");
    }
    return 1;
}

int somma_matrice_dec(int rx, int ry, int cx, int cy, int mat[MAX_MAT_R][MAX_MAT_C]) {
    //Implementare Assert
    assert(*mat!=NULL);
    int somma=0;
    for (int i = rx; i < ry; ++i) {
        for (int j = cx; j < cy; ++j) {
            somma += mat[i][j];
        }
    }
    return somma;
}