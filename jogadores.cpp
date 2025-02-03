#include "jogadores.h"

Jogadores::Jogadores(std::string nome) : nome(nome), vidas(5) {}

std::string Jogadores::getNome() const {
    return nome;
}

int Jogadores::getVidas() const {
    return vidas;
}

void Jogadores::perderVida() {
    if (vidas > 0) {
        vidas--;
    }
}