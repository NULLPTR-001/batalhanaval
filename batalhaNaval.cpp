#include "batalhaNaval.h"
#include <iostream>
#include <cstdlib>  
#include <ctime>   

BatalhaNaval::BatalhaNaval() : dados("data/historico.txt") {
    srand(static_cast<unsigned int>(time(0)));
}

std::vector<Coordenada> BatalhaNaval::gerarPosicaoAleatoria(int tamanhoNavio, int tamanhoTabuleiro, std::vector<std::vector<bool>>& tabuleiro) {
    std::vector<Coordenada> posicoes;
    bool posicaoValida = false;

    while (!posicaoValida) {
        posicoes.clear();
        bool horizontal = rand() % 2;
        int linha, coluna;

        if (horizontal) {
            linha = rand() % tamanhoTabuleiro;
            coluna = rand() % (tamanhoTabuleiro - tamanhoNavio + 1);
            for (int i = 0; i < tamanhoNavio; i++) {
                if (tabuleiro[linha][coluna + i]) break;
                posicoes.push_back(Coordenada(linha, coluna + i));
            }
        }
        else {
            linha = rand() % (tamanhoTabuleiro - tamanhoNavio + 1);
            coluna = rand() % tamanhoTabuleiro;
            for (int i = 0; i < tamanhoNavio; i++) {
                if (tabuleiro[linha + i][coluna]) break;
                posicoes.push_back(Coordenada(linha + i, coluna));
            }
        }

        if (posicoes.size() == tamanhoNavio) {
            posicaoValida = true;
            for (const auto& coord : posicoes) {
                tabuleiro[coord.getLinha()][coord.getColuna()] = true; 
            }
        }
    }

    return posicoes;
}

void BatalhaNaval::iniciar() {
    Usuario player1("Player 1");
    Adversario player2("Player 2 (IA)");

    int tamanhoTabuleiro = 10;
    std::vector<std::vector<bool>> tabuleiro(tamanhoTabuleiro, std::vector<bool>(tamanhoTabuleiro, false));

    std::vector<Coordenada> posicoesNavio1 = gerarPosicaoAleatoria(3, tamanhoTabuleiro, tabuleiro);
    std::vector<Coordenada> posicoesNavio2 = gerarPosicaoAleatoria(3, tamanhoTabuleiro, tabuleiro);

    Navio navio1(3, posicoesNavio1);
    Navio navio2(3, posicoesNavio2);

    Plataforma plataforma;
    plataforma.posicaoDoNavio(navio1);
    plataforma.posicaoDoNavio(navio2);

    Partida partida(plataforma, &player1, &player2);
    partida.iniciar();

    dados.salvarPartida(partida.getVencedor());

}

