#include "imoveis.h"

Imoveis::Imoveis(){ }

Imoveis::Imoveis(float preco, int tipo, float area, string disp, string endereco){
  this -> preco = preco;
  this -> tipo = tipo;
  this -> area = area;
  this -> disp = disp;
  this -> endereco = endereco;
}

void Imoveis::readAtributes(){
  cout << "Valor do imovel(R$): ";
  cin >> preco;

  cout << "Insira a área(m2): ";
  cin >> area;
  getchar();

  cout << "Aluguel ou venda: ";
  getline(cin, disp);

  cout << "Endereço: ";
  getline(cin, endereco);
}

void Imoveis::setPreco(float preco) {this->preco = preco; }
void Imoveis::setTipo(int tipo) { this->tipo = tipo; }
void Imoveis::setArea(float area) { this->area = area; }
void Imoveis::setDisp(string disp) { this->disp = disp; }
void Imoveis::setEndereco(string endereco) { this->endereco = endereco; }

int Imoveis::getTipo() {return tipo;}

void Imoveis::exibe(){ }

string Imoveis::getDisp(){ return disp;}