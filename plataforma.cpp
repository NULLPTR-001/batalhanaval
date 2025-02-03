#include "plataforma.h"
#include <iostream>
#ifdef _WIN32
#else
#include <unistd.h>  
#endif
using namespace std;

void limparTela() {
#ifdef _WIN32
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
#else
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
#endif
}

Plataforma::Plataforma() {

    grid = new char* [10];
    mascara = new char* [10];
    for (int i = 0; i < 10; i++) {
        grid[i] = new char[10];
        mascara[i] = new char[10];
        for (int j = 0; j < 10; j++) {
            grid[i][j] = ' ';
            mascara[i][j] = '*';
        }
    }
}

Plataforma::~Plataforma() {

    for (int i = 0; i < 10; i++) {
        delete[] grid[i];
        delete[] mascara[i];
    }
    delete[] grid;
    delete[] mascara;
}

void Plataforma::posicaoDoNavio(Navio navio) {
    navios.push_back(navio);
    for (const Coordenada& coord : navio.getPosicoes()) {
        if (coord.getLinha() >= 0 && coord.getLinha() < 10 && coord.getColuna() >= 0 && coord.getColuna() < 10) {
            grid[coord.getLinha()][coord.getColuna()] = 'P';
        }
    }
}

bool Plataforma::registroDisparo(Disparo disparo) {
    Coordenada coord = disparo.getCoordenada();

    for (Navio& navio : navios) {
        if (navio.atingir(coord)) {
            grid[coord.getLinha()][coord.getColuna()] = 'N';
            mascara[coord.getLinha()][coord.getColuna()] = 'N';
            return true;
        }
    }

    grid[coord.getLinha()][coord.getColuna()] = 'A';
    mascara[coord.getLinha()][coord.getColuna()] = 'A';
    return false;
}

void Plataforma::exibeTabuleiro() const {
    limparTela();

    const char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
    const char green[] = { 0x1b, '[', '1', ';', '3', '2', 'm', 0 };
    const char normal[] = { 0x1b, '[', '1', ';', '3', '9', 'm', 0 };

    cout << "     ";
    for (int j = 0; j < 10; j++) {
        cout << j << " ";
    }
    cout << "\n";

    for (int i = 0; i < 10; i++) {
        cout << i << " - ";
        for (int j = 0; j < 10; j++) {
            char celula = mascara[i][j];

            if (celula == 'N') {
                cout << green << " N" << normal;
            }
            else if (celula == 'A') {
                cout << blue << " A" << normal;
            }
            else {
                cout << " *";
            }
        }
        cout << "\n";
    }
}

bool Plataforma::naviosDestruidos() const {
    for (const Navio& navio : navios) {
        if (!navio.foiDestruido()) {
            return false;
        }
    }
    return true;
}

bool Plataforma::tabuleiroCompleto() const {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (mascara[i][j] == '*') {
                return false;
            }
        }
    }
    return true;
} 
