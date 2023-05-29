#include "imoveis.h"

#pragma once

class Terreno : public Imoveis{
  private:
    string desnivel;
    float valorMetro;
  public:
    Terreno();
    Terreno(float preco, float area, string disp, string endereco, string desnivel);

    string getDesnivel();
    float getValorMetro();
    void exibeTerreno();
    void alterar();
    void list();

    void calculaValorMetro();
    void readAtributes();
    string toString();
};