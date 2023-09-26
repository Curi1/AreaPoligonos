#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

float calcularAreaTriangulo(Ponto A, Ponto B, Ponto C) {
    return 0.5 * fabs((A.X * (B.Y - C.Y) + B.X * (C.Y - A.Y) + C.X * (A.Y - B.Y)));
}

int main() {
    FILE *arquivo;
    int numVertices;
    Ponto *vertices;

    arquivo = fopen("DadosPoligono.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    fscanf(arquivo, "%d", &numVertices);

    vertices = (Ponto *)malloc(numVertices * sizeof(Ponto));
    if (vertices == NULL) {
        perror("Erro de alocação de memória");
        return 1;
    }

    for (int i = 0; i < numVertices; i++) {
        fscanf(arquivo, "%f %f", &vertices[i].X, &vertices[i].Y);
    }

    fclose(arquivo);

    float area = 0.0;
    for (int i = 1; i < numVertices - 1; i++) {
        area += calcularAreaTriangulo(vertices[0], vertices[i], vertices[i + 1]);
    }


    printf("A area do poligono e %.2f\n", area);

    free(vertices);

    return 0;
}
