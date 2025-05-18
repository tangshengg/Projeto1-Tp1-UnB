#ifndef TUENTIDADES_H_INCLUDED
#define TUENTIDADES_H_INCLUDED

#include "Dominio.h"
#include "Conta.h"
#include "Carteira.h"
#include "Ordem.h"
#include "Exceptions.h"
#include <string>

class TUConta {
private:
    const static int SUCESSO = 0;
    const static int FALHA = -1;

    Cpf cpf;
    Nome nome;
    Senha senha;

    Conta* conta;
    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();

public:
    int run();
};

class TUCarteira {
private:
    const static int SUCESSO = 0;
    const static int FALHA = -1;

    Codigo codigo;
    Nome nome;
    Perfil perfil;
    Conta* conta;
    Ordem* ordem;

    Carteira* carteira;
    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarAdicionarOrdem();
    void testarRemoverOrdem();

public:
    int run();
};

class TUOrdem {
private:
    const static int SUCESSO = 0;
    const static int FALHA = -1;

    Codigo codigo;
    CodigoNegociacao codigoNegociacao;
    Data data;
    Dinheiro preco;
    Quantidade quantidade;
    Carteira* carteira;

    Ordem* ordem;
    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();

public:
    int run();
};

#endif
