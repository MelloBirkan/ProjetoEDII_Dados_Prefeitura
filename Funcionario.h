// Verifica se o símbolo FUNCIONARIO_H já foi definido, caso contrário, o
// define.
#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

// Inclui a biblioteca de strings do C++ para manipulação de strings.
#include <string>

// Declaração da classe Funcionario.
class Funcionario {
public:
    // Construtor da classe Funcionario com os parâmetros necessários.


    //Funcionario(int Excecao, const std::string &Nome_completo, const std::string &Cargo_Base,
    //            const std::string &Cargo_em_Comissao, double Remuneracao_do_Mes, double Demais_Elementos_da_Remuneracao,
    //            double Remuneracao_Bruta, const std::string &Unidade, const std::string &Tp_Log,
    //            const std::string &Logradouro, int Numero, const std::string &Complemento,
    //            const std::string &Jornada);



    Funcionario(const std::string &Nome_completo, const std::string &Cargo_Base,
                const std::string &Cargo_em_Comissao, double Remuneracao_do_Mes, double Demais_Elementos_da_Remuneracao,
                double Remuneracao_Bruta, const std::string &Unidade, const std::string &Tp_Log,
                const std::string &Logradouro, int Numero, const std::string &Complemento,
                const std::string &Jornada);





    //int getExcecao() const;
    const std::string &getNome_completo() const;
    const std::string &getCargo_Base() const;
    const std::string &getCargo_em_Comissao() const;
    double getRemuneracao_do_Mes() const;
    double getDemais_Elementos_da_Remuneracao() const;
    double getRemuneracao_Bruta() const;
    const std::string &getUnidade() const;
    const std::string &getTp_Log() const;
    const std::string &getLogradouro() const;
    int getNumero() const;
    const std::string &getComplemento() const;
    const std::string &getJornada() const;

private:

    int Excecao;
    std::string Nome_completo;
    std::string Cargo_Base;
    std::string Cargo_em_Comissao;
    double Remuneracao_do_Mes;
    double Demais_Elementos_da_Remuneracao;
    double Remuneracao_Bruta;
    std::string Unidade;
    std::string Tp_Log;
    std::string Logradouro;
    int Numero;
    std::string Complemento;
    std::string Jornada;

};

// Finaliza a verificação da diretiva de pré-processador.
#endif // FUNCIONARIO_H
