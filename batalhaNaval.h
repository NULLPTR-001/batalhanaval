#ifndef BATALHA_NAVAL_H
#define BATALHA_NAVAL_H

#include <vector>
#include "coordenadas.h"
#include "navio.h"
#include "plataforma.h"
#include "partida.h"
#include "dadosPartidas.h"
#include "usuario.h"
#include "adversario.h"

class BatalhaNaval {
private:
    Dados dados;
public:
    BatalhaNaval();
    void iniciar(); 
    std::vector<Coordenada> gerarPosicaoAleatoria(int tamanhoNavio, int tamanhoTabuleiro, std::vector<std::vector<bool>>& tabuleiro);
};

#endif
