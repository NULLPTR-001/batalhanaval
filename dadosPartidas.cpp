#include "dadosPartidas.h"
#include <iostream>
#include <fstream>

Dados::Dados(std::string arquivo) : arquivo(arquivo) {
}

void Dados::salvarPartida(std::string vencedor) {
    std::ofstream file(arquivo, std::ios::app);
    if (file.is_open()) {
        file << vencedor << std::endl;
        file.close();
    }
}

void Dados::mostrarDados() const {
    std::ifstream file(arquivo);
    if (!file.is_open()) {
        std::cout << "Nenhum historico de partidas encontrado.\n";
        return;
    }

    std::string linha;
    bool historicoVazio = true;

    while (std::getline(file, linha)) {
        if (!linha.empty()) {
            std::cout << linha << std::endl;
            historicoVazio = false;
        }
    }

    if (historicoVazio) {
        std::cout << "Nenhum historico de partidas encontrado.\n";
    }

    file.close();
}
