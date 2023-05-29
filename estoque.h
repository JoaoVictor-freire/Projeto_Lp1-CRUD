#include "apartamento.h"
#include "casa.h"
#include "imoveis.h"
#include "terreno.h"
#include <vector>

class Estoque {

private:
  vector<Imoveis *> estoque;

public:
  Estoque();
  void inserirImovel(Imoveis *im);
  void removerImovel(int index);
  void alterarImovel(int index);
  void listarTodos();
  void pesquisaNome(string nome);
  void exibeUm(int index);
  void geraRelatorio();
  vector<Imoveis *> getEstoque();
};