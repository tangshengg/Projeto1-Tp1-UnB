#include "TUSenha.hpp"

void TUSenha::setUp() {
    objeto = new Senha();
    estado = SUCESSO;
}

void TUSenha::tearDown() {
    delete objeto;
}

void TUSenha::testarCenarioValido() {
    try {
        objeto->setValor(SENHA_VALIDA);
        if (objeto->getValor() != SENHA_VALIDA)
            estado = FALHA;
    } catch (...) {
        estado = FALHA;
    }
}

void TUSenha::testarCenarioInvalido() {
    try {
        objeto->setValor(SENHA_INVALIDA);
        estado = FALHA;
    } catch (...) {
        if (objeto->getValor() == SENHA_INVALIDA)
            estado = FALHA;
    }
}

int TUSenha::run() {
    setUp();
    testarCenarioValido();
    testarCenarioInvalido();
    tearDown();
    return estado;
}