#include "dadosPartidas.h"
#include <ctime>
#include <iostream>
#include <fstream>

Dados::Dados(std::string arquivo) : arquivo(arquivo) {
}

void Dados::salvarPartida(std::string vencedor) {
    // Criar diretório "data" caso não exista
    #ifdef _WIN32
        system("if not exist data mkdir data");
    #else
        system("mkdir -p data");
    #endif

    std::ofstream file(arquivo, std::ios::app);
    if (file.is_open()) {
        file << vencedor << std::endl;
        file.close();
    }
}

void Dados::mostrarDados() const {
    // Verifica se o arquivo existe antes de tentar abrir
    std::ofstream temp(arquivo, std::ios::app); temp.close();
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
