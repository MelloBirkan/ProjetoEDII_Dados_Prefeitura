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

    Funcionario* buscar(const std::string& nome) const;

    void inserir(const Funcionario &funcionario);
    //void inserir(const std::string& excecao, const std::string& nome_completo, const std::string& cargo_base, const std::string& cargo_comissao, double remuneracao_mes, const std::string& demais_elementos, double remuneracao_bruta, const std::string& unidade, const std::string& tp_log, const std::string& logradouro, int numero, const std::string& complemento, const std::string& jornada);

    void percursoInOrder(std::function<void(const Funcionario &)> processar) const;



    void imprimirInOrder() const;
    double calcularGastoSalarios() const;
    double quemGastoSalarios() const;
    double gastoFuncao() const;
    double gastoFuncao2() const;
    void calcularFuncionariosPorCargo() const;


private:
    //Declaração da estrutura No.
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
    percursoInOrderNo(No *no,std::function<void(const Funcionario &)> processar) const;
};

// Finaliza a verificação da diretiva de pré-processador.
#endif // BSTFUNCIONARIO_H
