#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int fact(int i){
    if(i < 2)
        return 1;
    return i*fact(i-1);
}

float combinacion(int n, int r){
    float res;

    res = fact(n);
    res = res / (fact(r)*fact(n-r));

    return res;
}

int main(int argc, char* argv[]){
    int x, r, p;
        if(argc != 4){
            printf("Formato: x intentos, r positivos, p probabilidad\n");
            exit(0);
        }

        x = atoi(argv[1]);
        r = atoi(argv[2]);
        p = atof(argv[3]);

        float  res = combinacion(x,r)*pow((double)p,(double)r)*pow((double)1-p,(double) x-r);

        printf("Result: %f\n", res);

    return 0;
}



