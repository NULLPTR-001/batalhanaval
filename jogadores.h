#ifndef JOGADORES_A
#define JOGADORES_A

#include <string>
#include "disparo.h"

class Jogadores {
protected:
    std::string nome;
    int vidas;
public:
    Jogadores(std::string nome);
    virtual Disparo disparar() = 0; 
    std::string getNome() const;
    int getVidas() const;
    void perderVida();
};

#endif
