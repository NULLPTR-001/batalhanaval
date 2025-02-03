#include "disparo.h"

Disparo::Disparo(Coordenada coordenada) : coordenada(coordenada) {}

Coordenada Disparo::getCoordenada() const {
    std::cout << "Disparo nas coordenadas ("
        << coordenada.getLinha() << ", "
        << coordenada.getColuna() << ")" << std::endl;
    return coordenada;
}
