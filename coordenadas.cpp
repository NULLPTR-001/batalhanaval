#include "coordenadas.h"

Coordenada::Coordenada(int linha, int coluna) : linha(linha), coluna(coluna) {}

int Coordenada::getLinha() const {
    return linha;
}

int Coordenada::getColuna() const {
    return coluna;
}
