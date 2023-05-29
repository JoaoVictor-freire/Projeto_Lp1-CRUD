#include "imoveis.h"

#pragma once

class Apartamento : public Imoveis{

  private:  
    int andar, nQuartos, nBanheiros, numero;

  public:  
    Apartamento();
    Apartamento(float preco, float area, string disp, string endereco, int andar, int nQuartos, int nBanheiros, int numero);  

    int getAndar();
    int getnQuartos();
    int getnBanheiros();
    int getNumero();
    void exibeApartamento();
    void alterar();

    string toString();
    void readAtributes();
    void list();
};