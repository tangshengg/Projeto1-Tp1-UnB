#include "TUCodigo.hpp"

void TUCodigo::setUp() {
    objeto = new Codigo();
    estado = SUCESSO;
}

void TUCodigo::tearDown() {
    delete objeto;
}

void TUCodigo::testarCenarioValido() {
    try {
        objeto->setValor(CODIGO_VALIDO);
        if (objeto->getValor() != CODIGO_VALIDO)
            estado = FALHA;
    } catch (...) {
        estado = FALHA;
    }
}

void TUCodigo::testarCenarioInvalido() {
    try {
        objeto->setValor(CODIGO_INVALIDO);
        estado = FALHA;
    } catch (...) {
        if (objeto->getValor() == CODIGO_INVALIDO)
            estado = FALHA;
    }
}

int TUCodigo::run() {
    setUp();
    testarCenarioValido();
    testarCenarioInvalido();
    tearDown();
    return estado;
}