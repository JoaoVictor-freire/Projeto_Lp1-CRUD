#include "apartamento.h"

Apartamento::Apartamento(){ }


Apartamento::Apartamento(float preco, float area, string disp, string endereco, int andar, int nQuartos, int nBanheiros, int numero):Imoveis(preco, 2, area, disp, endereco){

  this->andar = andar;
  this->nQuartos = nQuartos;
  this->nBanheiros = nBanheiros;
  this->numero = numero;
}

int Apartamento::getAndar() { return andar;}
int Apartamento::getnQuartos() {return nQuartos;}
int Apartamento::getnBanheiros() {return nBanheiros;}
int Apartamento::getNumero() {return numero;}

string Apartamento::toString(){
  return to_string(tipo) + ";" + to_string(preco) + ";" + to_string(area) + ";" +  disp + ";" + endereco + ";" + to_string(andar) + ";" + to_string(nQuartos) + ";" + to_string(nBanheiros) + ";" + to_string(numero);
}

void Apartamento::readAtributes(){
  Imoveis::readAtributes();

  cout << "Andar: ";
  cin >> andar;

  cout << "Quantidade de quartos: ";
  cin >> nQuartos;

  cout << "Quanridade de banheiros: ";
  cin >> nBanheiros;

  cout << "Número: ";
  cin >> numero;
}

void Apartamento::exibeApartamento(){
  cout << "\nApartamento\n";
   
  cout << "Preço: " << preco << endl;
  cout << "Área: " << area << endl;
  cout << "Disponível para: " << disp << endl;
  cout << "Endereço: " << endereco << endl;
  
  cout << "Andar: " << andar << endl;
  cout << "Quartos :" << nQuartos << endl;
  cout << "Banheiros: " << nBanheiros << endl;
  cout << "Número apt: " << numero << endl;
}

void Apartamento::list(){
  cout << preco << "\t" << area << "\t\t" << disp << "\t\t" << nQuartos << "\t\t" << nBanheiros << "\t\t" << andar << "\t\t" << numero<< "\t\t" << endereco << endl;
}

void Apartamento::alterar(){
  int option;
  
  system("clear");
  cout << "Selecione oque será alterado:\n"
            "1- Preço.\n"
            "2- Área.\n"
            "3- Disponibilidade.\n"
            "4- Endereço.\n"
            "5- Andar.\n"
            "6- Nº de Quartos.\n"
            "7- Nº de Banheiros.\n"
            "8- Nº do apartamento.\n";

  cin >> option; cin.ignore();
  system("clear");

    switch(option){
      case 1: cout << "Preço: " ;              cin >> preco; break;
      case 2: cout << "Área: " ;               cin >> area; break;
      case 3: cout << "Disponibilidade: " ;    getline(cin, disp); break;
      case 4: cout << "Endereço: " ;           getline(cin, endereco); break;
      case 5: cout << "Andar: " ;              cin >> andar; break;
      case 6: cout << "Nº de quartos: " ;      cin >> nQuartos; break;
      case 7: cout << "Nº de banheiros: " ;    cin >> nBanheiros; break;
      case 8: cout << "Número do apt: " ;      cin >> numero; break;
      default: cout << "Opção inválida.\n";
    }
}