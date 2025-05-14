#include "TUDinheiro.hpp"

void TUDinheiro::setUp() {
    objeto = new Dinheiro();
    estado = SUCESSO;
}

void TUDinheiro::tearDown() {
    delete objeto;
}

void TUDinheiro::testarCenarioValido() {
    try {
        objeto->setValor(VALOR_VALIDO);
        if (objeto->getValor() != VALOR_VALIDO)
            estado = FALHA;
    } catch (...) {
        estado = FALHA;
    }
}

void TUDinheiro::testarCenarioInvalido() {
    try {
        objeto->setValor(VALOR_INVALIDO);
        estado = FALHA;
    } catch (...) {
        if (objeto->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUDinheiro::run() {
    setUp();
    testarCenarioValido();
    testarCenarioInvalido();
    tearDown();
    return estado;
}