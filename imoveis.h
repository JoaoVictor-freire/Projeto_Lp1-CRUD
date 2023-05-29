#include <iostream>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

/**************************************
        superclasse imoveis
**************************************/

#pragma once

class Imoveis {
  protected:
    float preco;
    int tipo;
    float area;
    string disp;
    string endereco;

  public:  
    Imoveis();
    Imoveis(float preco, int tipo, float area, string disp, string endereco);
    virtual void exibe();
    virtual void alterar() = 0;
    virtual string toString() = 0;
    virtual void list() = 0;
    virtual void readAtributes();
    
    void setPreco(float preco);
    void setTipo(int tipo);
    void setArea(float area);
    void setDisp(string disp);
    void setEndereco(string endereco);

    int getTipo();
    string getDisp();
};