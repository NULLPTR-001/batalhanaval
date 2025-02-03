#include "adversario.h"
#include <cstdlib>
#include <ctime>

Adversario::Adversario(std::string nome) : Jogadores(nome) {
    srand(static_cast<unsigned int>(time(0)));
}

Disparo Adversario::disparar() {
    int linha = rand() % 10; 
    int coluna = rand() % 10; 
    return Disparo(Coordenada(linha, coluna)); 
}
