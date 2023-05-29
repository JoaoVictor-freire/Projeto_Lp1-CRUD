#include "casa.h"

Casa::Casa(){ }
Casa::Casa(float preco, float area, string disp, string endereco, int nQuartos, int nBanheiros, int vagasGaragem, float areaConst) : Imoveis(preco, 1, area, disp, endereco){

  this->nQuartos = nQuartos;
  this->nBanheiros = nBanheiros;
  this->vagasGaragem = vagasGaragem;
  this->areaConst = areaConst;
}


float Casa::calcularAreaExterna(){
  return area - areaConst;
}

string Casa::toString(){
  return to_string(tipo) + ";" + to_string(preco) + ";" + to_string(area) + ";" + disp + ";" + endereco + ";" + to_string(nQuartos) + ";" + to_string(nBanheiros) + " ;" + to_string(vagasGaragem) + ";" + to_string(areaConst);
}

void Casa::readAtributes(){
  Imoveis::readAtributes();
  cout << "Quantidade de quartos: ";
  cin >> nQuartos;

  cout << "Quantida de banheiros: ";
  cin >> nBanheiros;

  cout << "Carros comportados pela garagem: ";
  cin >> vagasGaragem;

  cout << "Área construida (m2): ";
  cin >> areaConst;
}

void Casa::exibeCasa(){
  
  cout << "\nCasa\n"; //break;
  
  cout << "Preço: " << preco << endl;
  cout << "Área: " << area << endl;
  cout << "Disponível para: " << disp << endl;
  cout << "Endereço: " << endereco << endl;
  
  cout << "Quartos: " << nQuartos << endl;
  cout << "Banheiros: " << nBanheiros << endl;
  cout << "Vagas: " << vagasGaragem << endl;
  cout << "Área construída: " << areaConst << endl;
}

void Casa::setNQuartos(int nQuartos) {this->nQuartos = nQuartos; }
void Casa::setNBanheiros(int nBanheiros) { this->nBanheiros = nBanheiros; }
void Casa::setVagasGaragem(int vagasGaragem) { this->vagasGaragem = vagasGaragem; }
void Casa::setAreaConst(float areaConst) { this->areaConst = areaConst; }

int Casa::getQuartos() {return nQuartos;}
int Casa::getBanheiros() {return nBanheiros;}
int Casa::getVagasGaragem() {return vagasGaragem;}
int Casa::getAreaConst(){return areaConst;}

void Casa::list(){
  cout << preco << "\t" << area << "\t\t" << disp << "\t\t" << nQuartos << "\t\t" << nBanheiros << "\t\t\t" << vagasGaragem << "\t" << areaConst<< "\t\t" << endereco<< endl;
}

void Casa::alterar(){
  int option;

  system("clear");
  cout << "Selecione oque será alterado:\n"
          "1- Preço.\n"
          "2- Área.\n"
          "3- Disponibilidade.\n"
          "4- Endereço.\n"
          "5- Nº de Quartos.\n"
          "6- Nº de Banheiros.\n"
          "7- Nº de vagas.\n"
          "8- Área construída.\n";
  
  cin >> option; cin.ignore();
  system("clear");

  switch(option){
      case 1: cout << "Preço: " ;              cin >> preco; break;
      case 2: cout << "Área: " ;               cin >> area; break;
      case 3: cout << "Disponibilidade: " ;    getline(cin, disp); break;
      case 4: cout << "Endereço: " ;           getline(cin, endereco); break;
      case 5: cout << "Nº de quartos: " ;      cin >> nQuartos; break;
      case 6: cout << "Nº de banheiros: " ;    cin >> nBanheiros; break;
      case 7: cout << "Vagas na garagem: " ;   cin >> vagasGaragem; break;
      case 8: cout << "Área construida: " ;    cin >> areaConst; break;
      default: cout << "Opção inválida.\n";
  }
}