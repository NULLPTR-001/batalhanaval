#include "usuario.h"
#include <limits>
#include <iostream>

Usuario::Usuario(std::string nome) : Jogadores(nome) {}

Disparo Usuario::disparar() {
    int linha, coluna;

    while (true) {
        std::cout << "Digite a linha (0 a 9) em que deseja disparar: ";
        if (std::cin >> linha && linha >= 0 && linha <= 9) {
            break;
        }
        else {
            std::cin.clear();  
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
            std::cout << "Linha invalida! Digite uma linha entre 0 e 9." << std::endl;
        }
    }

    while (true) {
        std::cout << "Digite a coluna (0 a 9) em que deseja disparar: ";
        if (std::cin >> coluna && coluna >= 0 && coluna <= 9) {
            break;
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Coluna inválida! Digite uma coluna entre 0 e 9." << std::endl;
        }
    }

    return Disparo(Coordenada(linha, coluna));
}
