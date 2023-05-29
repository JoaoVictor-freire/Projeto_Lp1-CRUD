#include "terreno.h"

Terreno::Terreno(){ }

Terreno::Terreno(float preco, float area, string disp, string endereco, string desnivel):Imoveis(preco, 3, area, disp, endereco){
  this -> desnivel = desnivel;
  calculaValorMetro();
}

string Terreno::getDesnivel(){ return desnivel; }
float Terreno::getValorMetro() { return valorMetro; }

void Terreno::calculaValorMetro(){
  valorMetro = preco/area;
}

void Terreno::readAtributes(){
  Imoveis::readAtributes();
  cout << "Aclive, declive ou nivelado: ";
  cin >> desnivel;
}

string Terreno::toString(){
  return to_string(tipo) + ";" + to_string(preco) + ";" + to_string(area) + ";" +  disp + ";" + endereco + ";" + desnivel;
}

void Terreno::exibeTerreno(){
  
  cout << "\nTerreno\n";
  
  cout << "Preço: " << preco << endl;
  cout << "Área: " << area << endl;
  cout << "Disponível para: " << disp << endl;
  cout << "Endereço: " << endereco << endl;
  cout << "Desnivel: " << desnivel << endl;
}

void Terreno::list(){
  cout << preco << "\t" << area << "\t\t" << disp << "\t\t" << desnivel<<"\t\t" << endereco << endl;
}

void Terreno::alterar(){
  int option;

  system("clear");
  cout << "Selecione oque será alterado:\n"
          "1- Preço.\n"
          "2- Área.\n"
          "3- Disponibilidade.\n"
          "4- Endereço.\n"
          "5- Desnível\n";

  cin >> option; cin.ignore();
  system("clear");

  switch(option){
    case 1: cout << "Preço: ";               cin >> preco; break;
    case 2: cout << "Área: " ;               cin >> area; break;
    case 3: cout << "Disponibilidade: " ;    getline(cin, disp); break;
    case 4: cout << "Endereço: " ;           getline(cin, endereco); break;
    case 5: cout << "Desnível: " ;           cin >> desnivel; break;
    default: cout << "Opção inválida.\n";
  }
}