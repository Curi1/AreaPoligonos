#include "ponto.h"

Ponto criarPonto(float X, float Y) {
    Ponto ponto;
    ponto.X = X;
    ponto.Y = Y;
    return ponto;
}

float calcularDistancia(Ponto A, Ponto B) {
    return sqrt(pow(B.X - A.X, 2) + pow(B.Y - A.Y, 2));
}
