#include "batalhaNaval.h"
#include "dadosPartidas.h"
#include <iostream>

void mostrarMenu() {
    std::cout << "Bem-vindo ao Jogo de Batalha Naval!" << std::endl;
    std::cout << "1 - Jogar" << std::endl;
    std::cout << "2 - Sobre" << std::endl;
    std::cout << "3 - Ver Historico de Partidas" << std::endl;
    std::cout << "4 - Sair" << std::endl;
    std::cout << "Escolha uma opcao e tecle ENTER: ";
}

int main() {
    Dados dados("data/historico.txt"); 
    int opcao;

    do {
        mostrarMenu();
        std::cin >> opcao;

        switch (opcao) {
        case 1: {
            BatalhaNaval jogo;
            jogo.iniciar();
            break;
        }
        case 2: {
            std::cout << "\nSobre o Jogo:\n";
            std::cout << "Este eh um jogo de batalha naval onde dois jogadores se enfrentam.\n";
            std::cout << "Cada jogador tem 5 vidas. O vencedor eh o jogador que acertar a maior quantidade de navios antes de perder todas suas vidas.\n";
            std::cout << "Divirta-se!\n\n";
            break;
        }
        case 3: {
            std::cout << "\nHistorico de Partidas:\n";
            dados.mostrarDados(); 
            std::cout << "\n";
            break;
        }
        case 4: {
            std::cout << "Saindo do jogo. Ate mais!\n";
            break;
        }
        default: {
            std::cout << "Opcao invalida! Tente novamente.\n";
            break;
        }
        }
    } while (opcao != 4);

    return 0;
}
