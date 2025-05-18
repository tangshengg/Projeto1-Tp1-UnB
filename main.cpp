#include "TUDominio.h"
#include "TUEntidades.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    TUCodigo testeCodigo;
    TUCodigoNegociacao testeCodigoNegociacao;
    TUCpf testeCpf;
    TUData testeData;
    TUNome testeNome;
    TUPerfil testePerfil;
    TUDinheiro testeDinheiro;
    TUQuantidade testeQuantidade;
    TUSenha testeSenha;

    TUConta testeConta;
    TUCarteira testeCarteira;
    TUOrdem testeOrdem;

    cout << "=============== TESTES DE UNIDADE ===============" << endl;

    cout << "\n---------- TESTES DE DOMÍNIOS ----------" << endl;

    cout << "Teste de Codigo: ";
    if (testeCodigo.run() == 0)
        cout << "SUCESSO" << endl;
    else
        cout << "FALHA" << endl;

    cout << "Teste de CodigoNegociacao: ";
    if (testeCodigoNegociacao.run() == 0)
        cout << "SUCESSO" << endl;
    else
        cout << "FALHA" << endl;

    cout << "Teste de CPF: ";
    if (testeCpf.run() == 0)
        cout << "SUCESSO" << endl;
    else
        cout << "FALHA" << endl;

    cout << "Teste de Data: ";
    if (testeData.run() == 0)
        cout << "SUCESSO" << endl;
    else
        cout << "FALHA" << endl;

    cout << "Teste de Nome: ";
    if (testeNome.run() == 0)
        cout << "SUCESSO" << endl;
    else
        cout << "FALHA" << endl;

    cout << "Teste de Perfil: ";
    if (testePerfil.run() == 0)
        cout << "SUCESSO" << endl;
    else
        cout << "FALHA" << endl;

    cout << "Teste de Dinheiro: ";
    if (testeDinheiro.run() == 0)
        cout << "SUCESSO" << endl;
    else
        cout << "FALHA" << endl;

    cout << "Teste de Quantidade: ";
    if (testeQuantidade.run() == 0)
        cout << "SUCESSO" << endl;
    else
        cout << "FALHA" << endl;

    cout << "Teste de Senha: ";
    if (testeSenha.run() == 0)
        cout << "SUCESSO" << endl;
    else
        cout << "FALHA" << endl;

    cout << "\n---------- TESTES DE ENTIDADES ----------" << endl;

    cout << "Teste de Conta: ";
    if (testeConta.run() == 0)
        cout << "SUCESSO" << endl;
    else
        cout << "FALHA" << endl;

    cout << "Teste de Carteira: ";
    if (testeCarteira.run() == 0)
        cout << "SUCESSO" << endl;
    else
        cout << "FALHA" << endl;

    cout << "Teste de Ordem: ";
    if (testeOrdem.run() == 0)
        cout << "SUCESSO" << endl;
    else
        cout << "FALHA" << endl;

    cout << "\n===============================================" << endl;

    return 0;
}
