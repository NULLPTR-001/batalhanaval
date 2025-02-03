#ifndef PLATAFORMA_A
#define PLATAFORMA_A

#include <vector>
#include "navio.h"
#include "disparo.h"

class Plataforma {
private:
    char** grid; 
    char** mascara; 
    std::vector<Navio> navios;
public:
    Plataforma();
    ~Plataforma(); 
    void posicaoDoNavio(Navio navio);
    bool registroDisparo(Disparo disparo);
    void exibeTabuleiro() const; 
    bool naviosDestruidos() const;
    bool tabuleiroCompleto() const;
};

#endif
