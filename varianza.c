#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pair{
    float x;
    float prob;
};

typedef struct pair pair_t;


pair_t parse(char* s){
    printf("Parseando\n");
    pair_t res;
    char* s1, *s2;
    int pos = 0;
    for(int i = pos; i < strlen(s); ++i){
        if (s[i] == ','){
            pos = i;
            break;
        }
    }


    s1 = (char*) malloc (pos);
    int l2 = strlen(s)-pos;
    printf("strlen: %d, pos: %d, l2: %d\n", strlen(s), pos, l2);
    s2 = (char*)malloc (l2);
    memcpy(s1, s, pos);
    memcpy(s2, s+pos+1, l2-1);

    s1[pos-1] = '\0';
    s2[l2-1] = '\0';

    res.x = atof(s1);
    res.prob = atof(s2);


    return res;
}
    

float var(pair_t par){
    return par.x*par.x*par.prob;
}

int main(int argc, char* argv[]){

    if (argc < 2){
        printf("Error\n");
        return 0;
    }

    float sol = 0;

    for (int i = 1; i < argc; ++i){
        sol += var(parse(argv[i]));
    }

    printf("La varianza es %f.\n", sol);

    return 0;
}
