// Daniela Brazolin Flauto - 42130581
// Júlia Rampani -	42119529
// Marcello Gonzatto Birkan -	42020034
// Raphael Iniesta  Reis -	42143128

#include "BSTFuncionario.h"
#include "Funcionario.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// void imprimirFuncionario(Funcionario* funcionario) {
void imprimirFuncionario(const Funcionario &funcionario) {
  // cout << "Excecao: " << funcionario.getExcecao() << endl;
  cout << "Nome completo: " << funcionario.getNome_completo() << endl;
  cout << "Cargo base: " << funcionario.getCargo_Base() << endl;
  cout << "Cargo em comissao: " << funcionario.getCargo_em_Comissao() << endl;
  cout << "Remuneracao do mes: " << funcionario.getRemuneracao_do_Mes() << endl;
  cout << "Demais elementos da remuneracao: "
       << funcionario.getDemais_Elementos_da_Remuneracao() << endl;
  cout << "Remuneracao bruta: " << funcionario.getRemuneracao_Bruta() << endl;
  cout << "Unidade: " << funcionario.getUnidade() << endl;
  cout << "Tp_Log: " << funcionario.getTp_Log() << endl;
  cout << "Logradouro: " << funcionario.getLogradouro() << endl;
  cout << "Numero: " << funcionario.getNumero() << endl;
  cout << "Complemento: " << funcionario.getComplemento() << endl;
  cout << "Jornada: " << funcionario.getJornada() << endl;
}

// função para abrir o arquivo

void leituraCSV(BSTFuncionario &bst, const std::string &nomeArquivo) {

  std::ifstream arquivo(nomeArquivo);
  if (arquivo.is_open()) {
    // Descarta a primeira linha do arquivo que contém os nomes dos atributos
    std::string linha;
    std::getline(arquivo, linha);

    // Lê cada linha do arquivo e cria um objeto Funcionario para cada linha
    while (std::getline(arquivo, linha)) {
      std::istringstream ss(linha);
      std::string valor;

      // Lê cada valor separado por ';'
      // int Excecao;
      std::string Nome_completo, Cargo_Base, Cargo_em_Comissao, Unidade, Tp_Log,
          Logradouro, Complemento, Jornada;
      double Remuneracao_do_Mes, Demais_Elementos_da_Remuneracao,
          Remuneracao_Bruta;
      int Numero;

      // Lê cada valor separado por ';'
      std::getline(ss, valor, ';');
      // Excecao = std::stoi(valor);

      std::getline(ss, Nome_completo, ';');
      // std::cout << Nome_completo << std::endl;
      std::getline(ss, Cargo_Base, ';');
      std::getline(ss, Cargo_em_Comissao, ';');

      std::getline(ss, valor, ';');
      Remuneracao_do_Mes = std::stod(valor);

      std::getline(ss, valor, ';');
      Demais_Elementos_da_Remuneracao = std::stod(valor);

      std::getline(ss, valor, ';');
      Remuneracao_Bruta = std::stod(valor);

      std::getline(ss, Unidade, ';');
      std::getline(ss, Tp_Log, ';');
      std::getline(ss, Logradouro, ';');

      std::getline(ss, valor, ';');
      Numero = std::stoi(valor);

      std::getline(ss, Complemento, ';');
      std::getline(ss, Jornada, ';');

      Funcionario funcionario(
          Nome_completo, Cargo_Base, Cargo_em_Comissao, Remuneracao_do_Mes,
          Demais_Elementos_da_Remuneracao, Remuneracao_Bruta, Unidade, Tp_Log,
          Logradouro, Numero, Complemento, Jornada);

      bst.inserir(funcionario);
      std::cout << "Funcionario " << Nome_completo << " adicionado com sucesso!"
                << std::endl
                << std::endl;
    }

    arquivo.close();
  } else {
    std::cout << "Nao foi possivel abrir o arquivo " << nomeArquivo
              << std::endl;
  }
}

void salvarEmCSV(const std::string &nomeArquivo, const BSTFuncionario &bst) {

  std::ofstream arquivo(nomeArquivo);

  // Escreve a primeira linha com os nomes das colunas
  arquivo << "Nome completo;Cargo Base;Cargo em Comissão;Remuneração do "
             "Mês;Demais Elementos da Remuneração;Remuneração "
             "Bruta;Unidade;Tp. Log;Logadrouro;Número;Complemento;Jornada\n";

  // Percorre a árvore em ordem
  bst.percursoInOrder([&](const Funcionario &func) {
    // Escreve as informações do funcionário no arquivo de saída
    arquivo << func.getNome_completo() << ";" << func.getCargo_Base() << ";"
            << func.getCargo_em_Comissao() << ";"
            << func.getRemuneracao_do_Mes() << ";"
            << func.getDemais_Elementos_da_Remuneracao() << ";"
            << func.getRemuneracao_Bruta() << ";" << func.getUnidade() << ";"
            << func.getTp_Log() << ";" << func.getLogradouro() << ";"
            << func.getNumero() << ";" << func.getComplemento() << ";"
            << func.getJornada() << "\n";
  });
};

void imprimirFuncionario2(const Funcionario &f) {
  std::cout << f.getNome_completo() << " - " << std::endl;
}

int main() {

  BSTFuncionario bst;
  // Criação da árvore binária de busca de funcionários

  int opcao;
  do {
    // Exibe o menu de opções
    std::cout << "Menu:" << std::endl;
    std::cout << "1 - Listar funcionarios em ordem crescente de nome"
              << std::endl;
    std::cout << "2 - Calcular gasto com salarios" << std::endl;
    std::cout << "3 - Maior e menor salarios" << std::endl;
    std::cout << "4 - Gasto por tipo de cargo" << std::endl;
    std::cout << "5 - Gasto por funcao" << std::endl;
    std::cout << "6 - Inserir funcionario" << std::endl;
    std::cout << "7 - Funcionarios por cargo" << std::endl;
    std::cout << "0 - Sair" << std::endl;

    std::cout << "22 - Abrir arquivo" << std::endl;
    std::cout << "23 - Buscar por nome" << std::endl;
    std::cout << "24 - Salvar dados em novo arquivo" << std::endl;
    std::cout << "25 - Limpar arvore" << std::endl;
    std::cout << "26 - Remove funcionario" << std::endl;

    std::cout << "Digite a opcao desejada: ";
    // Lê a opção escolhida pelo usuário
    std::cin >> opcao;

    // Executa a ação correspondente à opção escolhida
    switch (opcao) {
    case 1:
      // Listar funcionários em ordem crescente de NOME
      std::cout << "Funcionários em ordem:" << std::endl << std::endl;
      bst.percursoInOrder(imprimirFuncionario2);
      break;
    case 2: {
      // Calcular gasto total com salários
      double gastoTotalSalarios = bst.calcularGastoSalarios();
      std::cout << "Gasto total com salarios: R$" << gastoTotalSalarios
                << std::endl
                << std::endl;

      // bst.imprimirInOrder();

      break;
    }
    case 3: {

      double TotalSalarios = bst.quemGastoSalarios();

      break;
    }
    case 4: {
      double totalGasto = bst.gastoFuncao();

      break;
    }
    case 5: {
      double totalGasto = bst.gastoFuncao2();

      break;
    }
    case 6: {
      // Adicionar funcionário

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

      std::cout << "Informe o nome completo do funcionario: ";
      std::cin.ignore(); // Limpar o buffer do teclado
      std::getline(std::cin, Nome_completo);

      std::cout << "Informe o cargo base do funcionario: ";
      std::cin.ignore(); // Limpar o buffer do teclado
      std::getline(std::cin, Cargo_Base);

      std::cout << "Informe o cargo em comissao do funcionario: ";
      std::cin.ignore(); // Limpar o buffer do teclado
      std::getline(std::cin, Cargo_em_Comissao);

      std::cout << "Informe a renumeracao  do mes do funcionario: ";
      std::cin >> Remuneracao_do_Mes;

      std::cout
          << "Informe os demais elementos da renumeracao do funcionario: ";
      std::cin >> Demais_Elementos_da_Remuneracao;

      std::cout << "Informe a renumeracao bruta do funcionario: ";
      std::cin >> Remuneracao_Bruta;

      std::cout << "Informe a unidade do funcionario: ";
      std::cin.ignore(); // Limpar o buffer do teclado
      std::getline(std::cin, Unidade);

      std::cout << "Informe o tipo de logradouro do funcionario: ";
      std::cin.ignore(); // Limpar o buffer do teclado
      std::getline(std::cin, Tp_Log);

      std::cout << "Informe o logradouro do funcionario: ";
      std::cin.ignore(); // Limpar o buffer do teclado
      std::getline(std::cin, Logradouro);

      std::cout << "Informe o numero do logradouro do funcionario: ";
      std::cin >> Numero;

      std::cout << "Informe o complemento do logradouro do funcionario: ";
      std::cin.ignore(); // Limpar o buffer do teclado
      std::getline(std::cin, Complemento);

      std::cout << "Informe a jornada de trabalho do funcionario: ";
      std::cin.ignore(); // Limpar o buffer do teclado
      std::getline(std::cin, Jornada);

      Funcionario novoFuncionario(
          Nome_completo, Cargo_Base, Cargo_em_Comissao, Remuneracao_do_Mes,
          Demais_Elementos_da_Remuneracao, Remuneracao_Bruta, Unidade, Tp_Log,
          Logradouro, Numero, Complemento, Jornada);
      bst.inserir(novoFuncionario);

      std::cout << "Funcionario adicionado com sucesso!" << std::endl
                << std::endl;
      break;
    }

    case 7: {
      bst.calcularFuncionariosPorCargo();
      break;
    }

    case 22: {

      std::string nomeArquivo;

      // BSTFuncionario bst;
      std::cout << "Digite o nome do arquivo a ser lido: ";
      std::cin >> nomeArquivo;
      // std::string nomeArquivo = "data.csv";
      leituraCSV(bst, nomeArquivo);
      break;
    }
    case 23: {
      std::string nome_completo;
      std::cout << "Digite o nome completo do funcionario a ser buscado: ";
      std::cin.ignore(); // descarta o caractere de nova linha deixado pelo
                         // último std::cin >>
      std::getline(std::cin, nome_completo);
      Funcionario *funcionario = bst.buscar(nome_completo);
      if (funcionario != nullptr) {
        std::cout << "Funcionario encontrado: "
                  << funcionario->getNome_completo() << std::endl;
        imprimirFuncionario(*funcionario);
      } else {
        std::cout << "Funcionario não encontrado." << std::endl;
      }
      break;
    }
    case 24: {

      std::string nomeArquivo;
      std::cout << "Digite o nome do arquivo: ";
      std::cin >> nomeArquivo;
      salvarEmCSV(nomeArquivo, bst);

      break;
    }

    case 25: {
      bst.limparArvore();
      break;
    }

    case 26: {
      std::string nome_completo;
      std::cout << "Digite o nome completo do funcionário a ser removido: ";
      std::cin.ignore(); // descarta o caractere de nova linha deixado pelo
                         // último std::cin >>
      std::getline(std::cin, nome_completo);
      // bst.buscarEremover( nome_completo );

      break;
    }

    case 0:
      // Sair do programa
      std::cout << "Saindo..." << std::endl;
      break;
    default:
      // Opção inválida
      std::cout << "Opcao invalida!" << std::endl << std::endl;
      break;
    }
  } while (opcao != 0); // Repete até que a opção "Sair" seja escolhida

  return 0;
}
