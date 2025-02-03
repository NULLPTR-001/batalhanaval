
#ifndef DADOS_PARTIDAS_A
#define DADOS_PARTIDAS_A

#include <string>
#include <fstream>

class Dados {
private:
    std::string arquivo;
public:
    Dados(std::string arquivo);
    void salvarPartida(std::string vencedor);
    void mostrarDados() const;
};

#endif
