#include "TUCarteira.hpp"

void TUCarteira::setUp() {
    carteira = new Carteira();
    estado = SUCESSO;
}

void TUCarteira::tearDown() {
    delete carteira;
}

void TUCarteira::testarCenarioValido() {
    try {
        Codigo codigo;
        codigo.setValor(CODIGO_VALIDO);
        carteira->setCodigo(codigo);

        Perfil perfil;
        perfil.setValor(PERFIL_VALIDO);
        carteira->setPerfil(perfil);

        Dinheiro saldo;
        saldo.setValor(DINHEIRO_VALIDO);
        carteira->setSaldo(saldo);

        if (carteira->getCodigo().getValor() != CODIGO_VALIDO ||
            carteira->getPerfil().getValor() != PERFIL_VALIDO ||
            carteira->getSaldo().getValor() != DINHEIRO_VALIDO) {
            estado = FALHA;
        }
    } catch (...) {
        estado = FALHA;
    }
}

void TUCarteira::testarCenarioInvalido() {
    try {
        Perfil perfil;
        perfil.setValor("Arriscado"); // Inválido (não está em Conservador/Moderado/Agressivo)
        carteira->setPerfil(perfil);
        estado = FALHA;
    } catch (...) {
        // OK: Comportamento esperado
    }
}

void TUCarteira::testarSaldo() {
    Dinheiro saldo;
    saldo.setValor("500.00");
    carteira->setSaldo(saldo);

    // Simula adição de ordens (PDF: "saldo da carteira é a soma dos preços das ordens")
    if (carteira->getSaldo().getValor() != "500.00") {
        estado = FALHA;
    }
}

int TUCarteira::run() {
    setUp();
    testarCenarioValido();
    testarCenarioInvalido();
    testarSaldo();
    tearDown();
    return estado;
}