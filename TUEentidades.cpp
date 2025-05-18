#include "TUEntidades.h"
#include <iostream>

using std::cout;
using std::endl;

void TUConta::setUp() {
    cpf.setValor("529.982.247-25");
    nome.setValor("Usuario Teste");
    senha.setValor("Ab1$cd");

    conta = new Conta();
    estado = SUCESSO;
}

void TUConta::tearDown() {
    delete conta;
}

void TUConta::testarCenarioSucesso() {
    try {
        conta->setCpf(cpf);
        conta->setNome(nome);
        conta->setSenha(senha);

        if (conta->getCpf().getValor() != cpf.getValor())
            estado = FALHA;

        if (conta->getNome().getValor() != nome.getValor())
            estado = FALHA;

        if (conta->getSenha().getValor() != senha.getValor())
            estado = FALHA;

    } catch (std::exception& e) {
        estado = FALHA;
    }
}

int TUConta::run() {
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}

void TUCarteira::setUp() {
    codigo.setValor("12345");
    nome.setValor("Carteira Teste");
    perfil.setValor("Conservador");

    conta = new Conta();
    Cpf cpf;
    cpf.setValor("529.982.247-25");
    Nome nomeConta;
    nomeConta.setValor("Usuario Teste");
    Senha senha;
    senha.setValor("Ab1$cd");
    conta->setCpf(cpf);
    conta->setNome(nomeConta);
    conta->setSenha(senha);

    ordem = new Ordem();
    Codigo codigoOrdem;
    codigoOrdem.setValor("54321");
    CodigoNegociacao codigoNegociacao;
    codigoNegociacao.setValor("ABCD123");
    Data data;
    data.setValor("20240510");
    Dinheiro preco;
    preco.setValor("1000,50");
    Quantidade quantidade;
    quantidade.setValor("100");
    ordem->setCodigo(codigoOrdem);
    ordem->setCodigoNegociacao(codigoNegociacao);
    ordem->setData(data);
    ordem->setPreco(preco);
    ordem->setQuantidade(quantidade);

    carteira = new Carteira();
    estado = SUCESSO;
}

void TUCarteira::tearDown() {
    delete carteira;
    delete conta;
    delete ordem;
}

void TUCarteira::testarCenarioSucesso() {
    try {
        carteira->setCodigo(codigo);
        carteira->setNome(nome);
        carteira->setPerfil(perfil);
        carteira->setConta(conta);

        if (carteira->getCodigo().getValor() != codigo.getValor())
            estado = FALHA;

        if (carteira->getNome().getValor() != nome.getValor())
            estado = FALHA;

        if (carteira->getPerfil().getValor() != perfil.getValor())
            estado = FALHA;

        if (carteira->getConta() != conta)
            estado = FALHA;

    } catch (std::exception& e) {
        estado = FALHA;
    }
}

void TUCarteira::testarAdicionarOrdem() {
    try {
        carteira->adicionarOrdem(ordem);

        vector<Ordem*> ordens = carteira->getOrdens();
        if (ordens.size() != 1 || ordens[0] != ordem)
            estado = FALHA;

    } catch (std::exception& e) {
        estado = FALHA;
    }
}

void TUCarteira::testarRemoverOrdem() {
    try {
        carteira->adicionarOrdem(ordem);
        carteira->removerOrdem(ordem);

        vector<Ordem*> ordens = carteira->getOrdens();
        if (ordens.size() != 0)
            estado = FALHA;

    } catch (std::exception& e) {
        estado = FALHA;
    }
}

int TUCarteira::run() {
    setUp();
    testarCenarioSucesso();
    if (estado == FALHA)
        return estado;

    testarAdicionarOrdem();
    if (estado == FALHA)
        return estado;

    testarRemoverOrdem();
    tearDown();
    return estado;
}

void TUOrdem::setUp() {
    codigo.setValor("12345");
    codigoNegociacao.setValor("PETR4");
    data.setValor("20240510");
    preco.setValor("25,75");
    quantidade.setValor("100");

    carteira = new Carteira();
    Codigo codigoCarteira;
    codigoCarteira.setValor("54321");
    Nome nomeCarteira;
    nomeCarteira.setValor("Carteira Teste");
    Perfil perfilCarteira;
    perfilCarteira.setValor("Moderado");
    carteira->setCodigo(codigoCarteira);
    carteira->setNome(nomeCarteira);
    carteira->setPerfil(perfilCarteira);

    ordem = new Ordem();
    estado = SUCESSO;
}

void TUOrdem::tearDown() {
    delete ordem;
    delete carteira;
}

void TUOrdem::testarCenarioSucesso() {
    try {
        ordem->setCodigo(codigo);
        ordem->setCodigoNegociacao(codigoNegociacao);
        ordem->setData(data);
        ordem->setPreco(preco);
        ordem->setQuantidade(quantidade);
        ordem->setCarteira(carteira);

        if (ordem->getCodigo().getValor() != codigo.getValor())
            estado = FALHA;

        if (ordem->getCodigoNegociacao().getValor() != codigoNegociacao.getValor())
            estado = FALHA;

        if (ordem->getData().getValor() != data.getValor())
            estado = FALHA;

        if (ordem->getPreco().getValor() != preco.getValor())
            estado = FALHA;

        if (ordem->getQuantidade().getValor() != quantidade.getValor())
            estado = FALHA;

        if (ordem->getCarteira() != carteira)
            estado = FALHA;

    } catch (std::exception& e) {
        estado = FALHA;
    }
}

int TUOrdem::run() {
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}
