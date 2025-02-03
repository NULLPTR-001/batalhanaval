#include "navio.h"
#include <iostream>

Navio::Navio(int tamanho, std::vector<Coordenada> lugares)
    : tamanho(tamanho), lugares(lugares), atingido(lugares.size(), false) {
}

bool Navio::atingir(Coordenada coord) {
    for (int i = 0; i < lugares.size(); i++) {
        
        if (lugares[i].getLinha() == coord.getLinha() && lugares[i].getColuna() == coord.getColuna()) {
            if (!atingido[i]) {
                atingido[i] = true; 
                return true;
            }
        }
    }
    return false;
}

bool Navio::foiDestruido() const {
    for (bool parteAtingida : atingido) {
        if (!parteAtingida) {
            return false; 
        }
    }
    return true; 
}

std::vector<Coordenada> Navio::getPosicoes() const {
    return lugares;
}
