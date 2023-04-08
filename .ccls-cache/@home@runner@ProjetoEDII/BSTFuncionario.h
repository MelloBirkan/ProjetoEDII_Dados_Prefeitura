// Daniela Brazolin Flauto - 42130581
// Júlia Rampani -	42119529
// Marcello Gonzatto Birkan -	42020034
// Raphael Iniesta  Reis -	42143128

// Verifica se o símbolo BSTFUNCIONARIO_H já foi definido, caso contrário, o
// define.
#ifndef BSTFUNCIONARIO_H
#define BSTFUNCIONARIO_H

// Inclui o arquivo de cabeçalho da classe Funcionario.
#include "Funcionario.h"

// Inclui a biblioteca para funções funcionais e ponteiros inteligentes.
#include <functional>
#include <memory>

// Declaração da classe BSTFuncionario.
class BSTFuncionario {
public:
  // Construtor e destrutor da classe BSTFuncionario.
  BSTFuncionario();
  ~BSTFuncionario();

  Funcionario *buscar(const std::string &nome) const;

  void inserir(const Funcionario &funcionario);

  void
  percursoInOrder(std::function<void(const Funcionario &)> processar) const;

  void imprimirInOrder() const;
  double calcularGastoSalarios() const;
  double quemGastoSalarios() const;
  double gastoFuncao() const;
  double gastoFuncao2() const;
  void calcularFuncionariosPorCargo() const;
  void limparArvore();

private:
  // Declaração da estrutura No.
  struct No {
    Funcionario funcionario;
    std::unique_ptr<No> esquerda;
    std::unique_ptr<No> direita;

    No(const Funcionario &funcionario);
  };

  // Atributo privado da classe BSTFuncionario.
  std::unique_ptr<No> raiz;

  // Métodos privados da classe BSTFuncionario.
  void inserirNo(std::unique_ptr<No> &no, const Funcionario &funcionario);

  void
  percursoInOrderNo(No *no,
                    std::function<void(const Funcionario &)> processar) const;
  void limparNo(std::unique_ptr<No> &no);
};

// Finaliza a verificação da diretiva de pré-processador.
#endif // BSTFUNCIONARIO_H
