#include "partida.h"
#include <iostream>

Partida::Partida(Plataforma& plataforma, Jogadores* player1, Jogadores* player2)
    : plataforma(plataforma), player1(player1), player2(player2), vencedor("") {
}

void Partida::iniciar() {
    int acertosJogador1 = 0, acertosJogador2 = 0;
    int rodadas = 0;

    std::cout << "\n";
    std::cout << "Tabuleiro inicial:" << std::endl;
    plataforma.exibeTabuleiro();

    while (rodadas < 5 || (player1->getVidas() > 0 && player2->getVidas() > 0)) {
        rodadas++;

        // Rodada do jogador 1
        std::cout << "\n";
        std::cout << "Vez de " << player1->getNome() << " (" << player1->getVidas() << " vidas restantes):" << std::endl;
        Disparo disparoJogador1 = player1->disparar();
        bool acertoJogador1 = plataforma.registroDisparo(disparoJogador1);

        if (acertoJogador1) {
            std::cout << player1->getNome() << " acertou um navio!" << std::endl;
            acertosJogador1++;
        }
        else {
            std::cout << player1->getNome() << " acertou a  gua!" << std::endl;
            player1->perderVida();
        }

        plataforma.exibeTabuleiro();

        if (player1->getVidas() == 0) {
            std::cout << player1->getNome() << " perdeu todas as vidas." << std::endl;
        }

        // Verifica  o da quinta rodada sem acertos
        if (rodadas == 5 && acertosJogador1 == 0 && acertosJogador2 == 0) {
            if (player1->getVidas() == 1 && player2->getVidas() >= 2) {
                break;
            }
        }

        // Rodada do jogador 2
        std::cout << "\n";
        std::cout << "Vez de " << player2->getNome() << " (" << player2->getVidas() << " vidas restantes):" << std::endl;
        Disparo disparoJogador2 = player2->disparar();
        bool acertoJogador2 = plataforma.registroDisparo(disparoJogador2);

        if (acertoJogador2) {
            std::cout << player2->getNome() << " acertou um navio!" << std::endl;
            acertosJogador2++;
        }
        else {
            std::cout << player2->getNome() << " acertou a  gua!" << std::endl;
            player2->perderVida();
        }

        plataforma.exibeTabuleiro();

        if (player2->getVidas() == 0) {
            std::cout << "\n";
            std::cout << player2->getNome() << " perdeu todas as vidas." << std::endl;
        }

        // Condi  o para encerrar na quinta rodada se ambos erraram
        if (rodadas == 5 && acertosJogador1 == 0 && acertosJogador2 == 0) {
            vencedor = "Empate";
            break;
        }

        // Verifica  o de vencedor com base nos acertos
        if (rodadas == 5 && (acertosJogador1 > 0 || acertosJogador2 > 0)) {
            vencedor = (acertosJogador1 > acertosJogador2) ? player1->getNome() : player2->getNome();
            break;
        }

        // Se um jogador tem 1 vida e o outro tem 2 ou mais, o jogo pode terminar
        if (rodadas >= 5 && player1->getVidas() == 0 && player2->getVidas() > 1) {
            vencedor = player2->getNome();
            break;
        }
        if (rodadas >= 5 && player2->getVidas() == 0 && player1->getVidas() > 1) {
            vencedor = player1->getNome();
            break;
        }
    }

    // Imprime o resultado final
    std::cout << player1->getNome() << " acertou " << acertosJogador1 << " partes do navio." << std::endl;
    std::cout << player2->getNome() << " acertou " << acertosJogador2 << " partes do navio." << std::endl;
    std::cout << "\n";
    std::cout << "Fim de jogo! Vencedor: " << vencedor << std::endl;
    std::cout << "\n";
}

std::string Partida::getVencedor() const {
    return vencedor;
}
