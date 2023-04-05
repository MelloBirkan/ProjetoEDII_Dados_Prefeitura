// Inclui o arquivo de cabeçalho da classe Funcionario.
#include "Funcionario.h"




//Funcionario::Funcionario(int Excecao, const std::string &Nome_completo, const std::string &Cargo_Base,
//              const std::string &Cargo_em_Comissao, double Remuneracao_do_Mes, double Demais_Elementos_da_Remuneracao,
//              double Remuneracao_Bruta, const std::string &Unidade, const std::string &Tp_Log,
//              const std::string &Logradouro, int Numero, const std::string &Complemento,
//              const std::string &Jornada)
//    : Excecao(Excecao), Nome_completo(Nome_completo), Cargo_Base(Cargo_Base),Cargo_em_Comissao(Cargo_em_Comissao),
//      Remuneracao_do_Mes(Remuneracao_do_Mes), Demais_Elementos_da_Remuneracao(Demais_Elementos_da_Remuneracao),
//      Remuneracao_Bruta(Remuneracao_Bruta), Unidade(Unidade), Tp_Log(Tp_Log), Logradouro(Logradouro),
//      Numero(Numero), Complemento(Complemento), Jornada(Jornada) {}

Funcionario::Funcionario(const std::string &Nome_completo, const std::string &Cargo_Base,
                         const std::string &Cargo_em_Comissao, double Remuneracao_do_Mes, double Demais_Elementos_da_Remuneracao,
                         double Remuneracao_Bruta, const std::string &Unidade, const std::string &Tp_Log,
                         const std::string &Logradouro, int Numero, const std::string &Complemento,
                         const std::string &Jornada)
        : Nome_completo(Nome_completo), Cargo_Base(Cargo_Base),Cargo_em_Comissao(Cargo_em_Comissao),
          Remuneracao_do_Mes(Remuneracao_do_Mes), Demais_Elementos_da_Remuneracao(Demais_Elementos_da_Remuneracao),
          Remuneracao_Bruta(Remuneracao_Bruta), Unidade(Unidade), Tp_Log(Tp_Log), Logradouro(Logradouro),
          Numero(Numero), Complemento(Complemento), Jornada(Jornada) {}



//int Funcionario::getExcecao() const { return Excecao; }
const std::string &Funcionario::getNome_completo() const { return Nome_completo; }
const std::string &Funcionario::getCargo_Base() const { return Cargo_Base; }
const std::string &Funcionario::getCargo_em_Comissao() const { return Cargo_em_Comissao; }
double Funcionario::getRemuneracao_do_Mes() const { return Remuneracao_do_Mes; }
double Funcionario::getDemais_Elementos_da_Remuneracao() const { return Demais_Elementos_da_Remuneracao; }
double Funcionario::getRemuneracao_Bruta() const { return Remuneracao_Bruta; }
const std::string &Funcionario::getUnidade() const { return Unidade; }
const std::string &Funcionario::getTp_Log() const { return Tp_Log; }
const std::string &Funcionario::getLogradouro() const { return Logradouro; }
int Funcionario::getNumero() const { return Numero; }
const std::string &Funcionario::getComplemento() const { return Complemento; }
const std::string &Funcionario::getJornada() const { return Jornada; }
