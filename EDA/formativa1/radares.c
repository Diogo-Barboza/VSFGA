#include <stdio.h>

double calculaVelocidadeMedia(int tA, int tB, double distancia){
    double a = tA / 3600.00;
    double b = tB / 3600.00;
    double varT = (b - a);

    double vm = distancia / varT;

    return vm;
}

int levouMulta(int tA, int tB, double distancia, double velocidadeMaxima){
    double s = calculaVelocidadeMedia(tA, tB, distancia);
    int saida;

    if (s > velocidadeMaxima)
    {
        saida = 1;
    }else{
        saida = 0;
    }
    return saida;
}
