#include "imoveis.h"

#pragma once

class Casa : public Imoveis{

  private:
    int nQuartos, nBanheiros, vagasGaragem;
    float areaConst;

  public:
    Casa();
    Casa(float preco, float area, string disp, string endereco, int nQuartos, int nBanheiros, int vagasGaragem, float areaConst);

  
    void setNQuartos(int nQuartos);
    void setNBanheiros(int nBanheiros);
    void setVagasGaragem(int vagasGaragem);
    void setAreaConst(float areaConst);
    int getQuartos();
    int getBanheiros();
    int getVagasGaragem();
    int getAreaConst();

    float calcularAreaExterna();
    void exibeCasa();
    void alterar();
    string toString();
    void readAtributes();
    void list();
    
};