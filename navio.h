#ifndef NAVIO_A
#define NAVIO_A

#include <vector>
#include <iostream>
#include "coordenadas.h"

class Navio {
private:
    int tamanho;
    std::vector<Coordenada> lugares;
    std::vector<bool> atingido;
public:
    Navio(int tamanho, std::vector<Coordenada> lugares);
    bool atingir(Coordenada coord);
    bool foiDestruido() const;
    std::vector<Coordenada> getPosicoes() const; 
};
#endif
