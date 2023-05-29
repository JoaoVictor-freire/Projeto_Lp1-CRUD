#include "estoque.h"

Estoque::Estoque() {}

void Estoque::inserirImovel(Imoveis *im) { estoque.push_back(im); }

void Estoque::removerImovel(int index) {
  if (index - 1 >= 0 && index - 1 <= estoque.size()) {
    exibeUm(index);
  } else {
    system("clear");
    cout << "Indice não encontrado.\n";
    getchar();
    return;
  }
  cout << "Deseja remover o imóvel acima? [s/n]: ";
  char resposta;
  while (true) {
    cin >> resposta;
    getchar();
    if (resposta == 'n') {
      system("clear");
      cout << "Solicitação cancelada.\n";
      return;
    } else if (resposta == 's') {
      estoque.erase(estoque.begin() + (index - 1));
      system("clear");
      cout << "Imóvel removido com sucesso!\n" << endl;
      return;
    } else
      cout << "Resposta inválida, insira apenas s (sim) ou n (não)  \n";
  }
}

void Estoque::alterarImovel(int index) { estoque[index - 1]->alterar(); }

void Estoque::listarTodos() {
  int index = 1;

  cout << "\nCasas:\n----------------------------------------------------------"
          "------------------------------------------------\n";
  cout << "Indice\tPreço\tArea\tDisp\tQuartos\tBanheiros\tGaragem\tÁrea\tEndere"
          "ço\n";
  cout << "\n------------------------------------------------------------------"
          "----------------------------------------\n";
  for (int i = 0; i < estoque.size(); i++) {
    if (estoque[i]->getTipo() == 1) {
      cout << i + 1 << "\t\t";
      estoque[i]->list();
    }
  }
  cout << endl;
  cout << "\nApartamentos:\n---------------------------------------------------"
          "-------------------------------------------------------\n";
  cout << "Indice\tPreço\tArea\tDisp\tQuartos\tBanheiros\tAndar\tNumero\tEndere"
          "ço\n";
  cout << "\n------------------------------------------------------------------"
          "----------------------------------------\n";
  for (int i = 0; i < estoque.size(); i++) {
    if (estoque[i]->getTipo() == 2) {
      cout << i + 1 << "\t\t";
      estoque[i]->list();
    }
  }
  cout << endl;
  cout << "\nTerrenos::\n------------------------------------------------------"
          "----------------------------------------------------\n";
  cout << "Indice\tPreço\tArea\tDisp\t\tDesnive\t\t\tEndereço\n";
  cout << "\n------------------------------------------------------------------"
          "----------------------------------------\n";
  for (int i = 0; i < estoque.size(); i++) {
    if (estoque[i]->getTipo() == 3) {
      cout << i + 1 << "\t\t";
      estoque[i]->list();
    }
  }
  cout << endl;
}

void Estoque::pesquisaNome(string nome) {
  
    for (int i = 0; i < estoque.size(); i++) {
      if (estoque[i]->toString().find(nome) != string::npos){
        Estoque::exibeUm(i + 1);
      }
    }
   
}

void Estoque::exibeUm(int index) {
  Imoveis *aux;

  switch (estoque[index - 1]->getTipo()) {

  case 1:
    Casa *auxCS;
    auxCS->exibeCasa();
    break;

  case 2:
    Apartamento *auxAPT;
    auxAPT->exibeApartamento();
    break;

  case 3:
    Terreno *auxT;
    auxT->exibeTerreno();
    break;
  }
}

vector<Imoveis *> Estoque::getEstoque() { return estoque; }

void Estoque::geraRelatorio(){
  int i, j, k;
  i = j = k = 0;
  system("clear");
  cout << "Total de imóveis cadastrados: " << estoque.size() << endl;

  for(Imoveis *im : estoque){
    if(im->getDisp() == "venda"){
      i++;
    }else{
      j++;
    }
  }

  cout << "Disponíveis para venda: " << i << endl;
  cout << "Disponíveis para aluguel: " << j << endl;

  i = j = k = 0;
  for(Imoveis *im : estoque){
    if(im->getTipo() == 1){
      i++;
    }else if (im->getTipo() == 2){
      j++;
    }else
      k++;
  }

  cout << "Total de casas: " << i << endl;
  cout << "Total de apartamentos: " << j << endl;
  cout << "Total de terrenos: " << k << endl;
}