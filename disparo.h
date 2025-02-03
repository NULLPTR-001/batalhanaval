#ifndef DISPARO_A
#define DISPARO_A

#include "coordenadas.h"
#include <iostream>

class Disparo {
private:
    Coordenada coordenada;
public:
    Disparo(Coordenada coordenada);
    Coordenada getCoordenada() const;
};

#endif
