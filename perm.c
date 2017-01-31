#include <stdio.h>
#include <stdlib.h>

int fact(int n){
    if(n < 2)
        return 1;
    return n * fact(n-1);
}

int main(int argc, char* argv[]){
    if(argc != 3){
        printf("Numero de argumentos invalido.\n");
        return 0;
    }
    int n, r, sol;

    n = atoi(argv[1]);
    r = atoi(argv[2]);

    sol = fact(n);
    sol = sol / fact(n-r);
    printf("Permutacion de %d en grupos de %d = %d\n", n, r, sol);


    return 0;
}

