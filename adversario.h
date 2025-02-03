#ifndef ADVERSARIO_A
#define ADVERSARIO_A

#include "jogadores.h"

class Adversario : public Jogadores {
public:
    Adversario(std::string nome);
    Disparo disparar() override;
};

#endif
