#ifndef USUARIO_A
#define USUARIO_A

#include "jogadores.h"

class Usuario : public Jogadores {
public:
    Usuario(std::string nome);
    Disparo disparar() override;
};

#endif
