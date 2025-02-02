#ifndef PARTIDA_A
#define PARTIDA_A

#include "jogadores.h"
#include "plataforma.h"
#include "adversario.h"
#include <string>

class Partida {
private:
    Plataforma& plataforma;  
    Jogadores* player1;
    Jogadores* player2;
    std::string vencedor;
public:
    Partida(Plataforma& plataforma, Jogadores* player1, Jogadores* player2);
    void iniciar();
    std::string getVencedor() const;
};

#endif
