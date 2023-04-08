// Daniela Brazolin Flauto - 42130581
// Júlia Rampani -	42119529
// Marcello Gonzatto Birkan -	42020034
// Raphael Iniesta  Reis -	42143128

/*
Esta implementação inclui os métodos da classe `BSTFuncionario` que trabalham
com os funcionários armazenados na árvore binária de busca.

- O construtor e o destrutor estão implementados.
- O método `inserir` chama o método `inserirNo`, que insere um funcionário na
árvore de acordo com sua identificação.
- O método `percursoInOrder` chama o método `percursoInOrderNo`, que percorre a
árvore em ordem (in-order) e processa os funcionários usando uma função passada
como argumento.

*/

// Inclui o arquivo de cabeçalho da classe BSTFuncionario.
#include "BSTFuncionario.h"
#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <unordered_map>
#include <vector>

// Implementação do construtor e destrutor da classe BSTFuncionario.
BSTFuncionario::BSTFuncionario() : raiz(nullptr) {}
BSTFuncionario::~BSTFuncionario() {}

// Implementação do método inserir da classe BSTFuncionario.
void BSTFuncionario::inserir(const Funcionario &funcionario) {
  inserirNo(raiz, funcionario);
}

// Implementação do método percursoInOrder da classe BSTFuncionario.
void BSTFuncionario::percursoInOrder(
    std::function<void(const Funcionario &)> processar) const {
  percursoInOrderNo(raiz.get(), processar);
}

// Implementação do construtor da estrutura No da classe BSTFuncionario.
BSTFuncionario::No::No(const Funcionario &funcionario)
    : funcionario(funcionario), esquerda(nullptr), direita(nullptr) {}

// Implementação do método inserirNo da classe BSTFuncionario.
void BSTFuncionario::inserirNo(std::unique_ptr<No> &no,
                               const Funcionario &funcionario) {
  if (!no) {
    no = std::unique_ptr<No>(new No(funcionario));
  } else if (funcionario.getNome_completo() <
             no->funcionario.getNome_completo()) {
    inserirNo(no->esquerda, funcionario);
  } else {
    inserirNo(no->direita, funcionario);
  }
}

// Implementação do método percursoInOrderNo da classe BSTFuncionario.
void BSTFuncionario::percursoInOrderNo(
    No *no, std::function<void(const Funcionario &)> processar) const {
  if (!no) {
    return;
  }

  percursoInOrderNo(no->esquerda.get(), processar);
  processar(no->funcionario);
  percursoInOrderNo(no->direita.get(), processar);
}

// Implementação do método calcularGastoSalarios da classe BSTFuncionario.
double BSTFuncionario::calcularGastoSalarios() const {
  double totalSalarios = 0.0;
  auto processar = [&totalSalarios](const Funcionario &funcionario) {
    totalSalarios += funcionario.getRemuneracao_Bruta();
  };
  percursoInOrder(processar);
  return totalSalarios;
}

double BSTFuncionario::quemGastoSalarios() const {
  double totalSalarios = 0.0;
  double maxSalario = std::numeric_limits<double>::min();
  double minSalario = std::numeric_limits<double>::max();
  std::string nomeMaiorSalario, nomeMenorSalario;

  auto processar = [&](const Funcionario &funcionario) {
    totalSalarios += funcionario.getRemuneracao_Bruta();

    if (funcionario.getRemuneracao_Bruta() > maxSalario) {
      maxSalario = funcionario.getRemuneracao_Bruta();
      nomeMaiorSalario = funcionario.getNome_completo();
    }

    if (funcionario.getRemuneracao_Bruta() < minSalario) {
      minSalario = funcionario.getRemuneracao_Bruta();
      nomeMenorSalario = funcionario.getNome_completo();
    }
  };

  percursoInOrder(processar);

  std::cout << "Maior salario: " << nomeMaiorSalario << " - R$ " << maxSalario
            << std::endl;
  std::cout << "Menor salario: " << nomeMenorSalario << " - R$ " << minSalario
            << std::endl;

  return totalSalarios;
}

double BSTFuncionario::gastoFuncao() const {
  double totalSalarios = 0.0;
  double totalCargoBase = 0.0;
  double totalCargoComissao = 0.0;

  auto processar = [&](const Funcionario &funcionario) {
    double salario = funcionario.getRemuneracao_Bruta();

    if (funcionario.getCargo_Base() != "nd") {
      totalCargoBase += salario;
    }

    if (funcionario.getCargo_em_Comissao() != "nd") {
      totalCargoComissao += salario;
    }

    totalSalarios += salario;
  };

  percursoInOrder(processar);

  double percentualCargoBase = (totalCargoBase / totalSalarios) * 100;
  double percentualCargoComissao = (totalCargoComissao / totalSalarios) * 100;

  std::cout << "Total de remuneracao bruta do cargo base: R$ " << totalCargoBase
            << " (" << percentualCargoBase << "%)" << std::endl;
  std::cout << "Total de remuneracao bruta do cargo em comissao: R$ "
            << totalCargoComissao << " (" << percentualCargoComissao << "%)"
            << std::endl;
  std::cout << "Total de remuneração bruta: R$ " << totalSalarios << std::endl;

  return totalSalarios;
}

double BSTFuncionario::gastoFuncao2() const {
  double totalSalarios = 0.0;
  double totalCargoBase = 0.0;
  double totalCargoComissao = 0.0;
  std::map<std::string, double> totaisPorCargo;

  auto processar = [&](const Funcionario &funcionario) {
    double salario = funcionario.getRemuneracao_Bruta();

    if (funcionario.getCargo_Base() != "nd") {
      totalCargoBase += salario;
      totaisPorCargo[funcionario.getCargo_Base()] += salario;
    }

    if (funcionario.getCargo_em_Comissao() != "nd") {
      totalCargoComissao += salario;
      totaisPorCargo[funcionario.getCargo_em_Comissao()] += salario;
    }

    totalSalarios += salario;
  };

  percursoInOrder(processar);

  std::cout << "Total de remuneração bruta do cargo base: R$ " << totalCargoBase
            << " (" << ((totalCargoBase / totalSalarios) * 100) << "%)"
            << std::endl;
  std::cout << "Total de remuneração bruta do cargo em comissão: R$ "
            << totalCargoComissao << " ("
            << ((totalCargoComissao / totalSalarios) * 100) << "%)"
            << std::endl;
  std::cout << "Total de remuneração bruta: R$ " << totalSalarios << std::endl;

  for (const auto &p : totaisPorCargo) {
    const std::string &cargo = p.first;
    double total = p.second;
    double percentualCargo = (total / totalSalarios) * 100;
    std::cout << "Total de remuneração bruta do cargo " << cargo << ": R$ "
              << total << " (" << percentualCargo << "%)" << std::endl;
  }

  return totalSalarios;
}

void BSTFuncionario::calcularFuncionariosPorCargo() const {
  std::vector<std::pair<std::string, int>> totaisPorCargo;
  auto processar = [&](const Funcionario &funcionario) {
    bool adicionou = false;

    // Tenta adicionar o cargo base
    for (auto &par : totaisPorCargo) {
      if (par.first == funcionario.getCargo_Base()) {
        par.second++;
        adicionou = true;
        break;
      }
    }

    // Se não encontrou, adiciona um novo elemento ao vetor
    if (!adicionou && funcionario.getCargo_Base() != "nd") {
      totaisPorCargo.push_back(std::make_pair(funcionario.getCargo_Base(), 1));
    }

    adicionou = false;

    // Tenta adicionar o cargo em comissão
    for (auto &par : totaisPorCargo) {
      if (par.first == funcionario.getCargo_em_Comissao()) {
        par.second++;
        adicionou = true;
        break;
      }
    }

    // Se não encontrou, adiciona um novo elemento ao vetor
    if (!adicionou && funcionario.getCargo_em_Comissao() != "nd") {
      totaisPorCargo.push_back(
          std::make_pair(funcionario.getCargo_em_Comissao(), 1));
    }
  };

  percursoInOrder(processar);

  // Ordena o vetor por ordem decrescente de quantidade de funcionários
  std::sort(
      totaisPorCargo.begin(), totaisPorCargo.end(),
      [](const std::pair<std::string, int> &a,
         const std::pair<std::string, int> &b) { return a.second > b.second; });

  int totalFuncionarios = std::count_if(
      totaisPorCargo.begin(), totaisPorCargo.end(),
      [](const std::pair<std::string, int> &par) { return par.second > 0; });

  // Mostra o resultado
  for (const auto &par : totaisPorCargo) {
    if (par.second > 0) {
      double percentualCargo =
          (par.second / static_cast<double>(totalFuncionarios)) * 100;
      std::cout << "Total de funcionários do cargo " << par.first << ": "
                << par.second << " (" << percentualCargo << "%)" << std::endl;
    }
  }
}

Funcionario *BSTFuncionario::buscar(const std::string &nome) const {
  No *no_atual = raiz.get();
  while (no_atual != nullptr) {
    if (no_atual->funcionario.getNome_completo() == nome) {
      std::cout << "Funcionário encontrado: "
                << no_atual->funcionario.getNome_completo() << std::endl;
      return &no_atual->funcionario;
    } else if (no_atual->funcionario.getNome_completo() > nome) {
      no_atual = no_atual->esquerda.get();
    } else {
      no_atual = no_atual->direita.get();
    }
  }
  std::cout << "Funcionário não encontrado." << std::endl;
  return nullptr;
}

void BSTFuncionario::imprimirInOrder() const {
  percursoInOrder([](const Funcionario &f) {
    std::cout << f.getNome_completo() << std::endl;
  });
}

void BSTFuncionario::limparArvore() {
  limparNo(raiz);
  raiz = nullptr;
}

void BSTFuncionario::limparNo(std::unique_ptr<No> &no) {
  if (no) {
    limparNo(no->esquerda);
    limparNo(no->direita);
    no.reset();
  }
}
