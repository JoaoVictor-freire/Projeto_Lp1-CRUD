#include "apartamento.h"
#include "casa.h"
#include "estoque.h"
#include "imoveis.h"
#include "terreno.h"

void VoltaMenu() {
  cout << "Pressione ENTER para voltar ao menu";
  string key;
  getline(cin, key);
}

void FecharPrograma(Estoque *estoque) {
  fstream stream;
  vector<Imoveis *> acessoEstoque = estoque->getEstoque();

  stream.open("arquivo.txt");
  if (!stream.is_open()) {
    cout << "Erro ao abrir o arquivo";
    stream.close();
    return;
  }

  for (int i = 0; i < acessoEstoque.size(); i++) {
    stream << acessoEstoque[i]->toString();
    if (i != acessoEstoque.size() - 1)
      stream << endl;
  }
  cout << "Programa finalizado, dados salvos com sucesso\n";
  stream.close();
}

vector<string> split(string line, char separator) {
  vector<string> dados;
  string str;

  // ss is an object of stringstream that references the line string.
  stringstream ss(line);

  // Use while loop to check the getline() function condition.
  while (getline(ss, str, separator))
    // `str` is used to store the token string while ' ' whitespace is used as
    // the delimiter.
    dados.push_back(str);
  return dados;
}

void AbrirPrograma(Estoque *estoque) {
  fstream stream;
  Imoveis *im;

  stream.open("arquivo.txt");
  if (!stream.is_open()) {
    cout << "Estoque zerado, por favor insira novos imóveis.\n";
    stream.close();
    return;
  }

  while (!stream.eof()) {
    string line;
    getline(stream, line);
    vector<string> dados = split(line, ';');

    switch (stoi(dados[0])) {
    case 1: {
      im = new Casa(stof(dados[1]), stof(dados[2]), dados[3], dados[4],
                    stoi(dados[5]), stoi(dados[6]), stoi(dados[7]),
                    stof(dados[8]));
      estoque->inserirImovel(im);
      break;
    }
    case 2: {
      im = new Apartamento(stof(dados[1]), stof(dados[2]), dados[3], dados[4],
                           stoi(dados[5]), stoi(dados[6]), stoi(dados[7]),
                           stoi(dados[8]));
      estoque->inserirImovel(im);
      break;
    }
    case 3:
      im = new Terreno(stof(dados[1]), stoi(dados[2]), dados[3], dados[4],
                       dados[5]);
      estoque->inserirImovel(im);
      break;
    }
  }
  stream.close();
}

void showMenu() {
  system("clear");
  cout << "Qual operação deseja fazer?\n"
          "1. Inserir.\n"
          "2. Alterar.\n"
          "3. Pesquisar por nome.\n"
          "4. Remover.\n"
          "5. Listar todos.\n"
          "6. Exibir um.\n"
          "7. Gerar relatório.\n"
          "8. Fechar programa.\n";
}

void Insere(Estoque *estoque) {
  Imoveis *im;
  int tipo;

  system("clear");
  cout << "Selecione o ímovel que deseja inserir:\n"
          "1 - Casa.\n"
          "2 - Apartamento.\n"
          "3 - Terreno.\n";
  cin >> tipo;
  cin.ignore();

  switch (tipo) {
  case 1:
    im = new Casa();
    im->setTipo(tipo);
    im->readAtributes();
    estoque->inserirImovel(im);
    break;

  case 2:
    im = new Apartamento();
    im->setTipo(tipo);
    im->readAtributes();
    estoque->inserirImovel(im);
    break;

  case 3:
    im = new Terreno();
    im->setTipo(tipo);
    im->readAtributes();
    estoque->inserirImovel(im);
    break;

  default:
    cout << "Tipo requisitado não esxiste.\n";
  }
}

int main() {
  Estoque *estoque = new Estoque();
  int option;

  AbrirPrograma(estoque);

  while (true) {

    showMenu();
    cin >> option;
    cin.ignore();

    switch (option) {

    case 1: {
      system("clear");
      Insere(estoque);
      break;
    }
    case 2: {
      system("clear");
      cout << "Qual o índice do imóvel que deseja alterar? ";
      int aux;
      cin >> aux;
      // cin.ignore();
      estoque->alterarImovel(aux);
      break;
    }
    case 3: {
      system("clear");
      cout << "O que deseja pesquisar? ";
      string search;
      getchar();
      getline(cin, search);
      estoque->pesquisaNome(search);
      VoltaMenu();
      break;
    }
    case 4: {
      system("clear");
      estoque->listarTodos();
      cout << "Qual o índice do imóvel que deseja remover? ";
      int index;
      cin >> index;
      estoque->removerImovel(index);
      VoltaMenu();
      break;
    }
    case 5: {
      system("clear");
      estoque->listarTodos();
      VoltaMenu();
      break;
    }
    case 6: {
      system("clear");
      int index;
      cout << "Digite o índice do imóvel que deseja exibir: ";
      cin >> index;
      cin.ignore();
      estoque->exibeUm(index);
      VoltaMenu();
      break;
    }
    case 7: {
      estoque->geraRelatorio();
      VoltaMenu();
      break;
    }
    case 8: {
      FecharPrograma(estoque);
      return 0;
    }
    default: {
      system("clear");
      cout << "Opção inválida, pressione ENTER para tentar novamente.\n";
      string key;
      getline(cin, key);
      break;
    }
    }
  }

  return 0;
}