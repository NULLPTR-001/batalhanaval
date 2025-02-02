#ifndef COORDENADAS_A
#define COORDENADAS_A

class Coordenada {
private:
    int linha, coluna;
public:
    Coordenada(int linha, int coluna);
    int getLinha() const;
    int getColuna() const;
};
#endif
