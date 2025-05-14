#include "TUQuantidade.hpp"

void TUQuantidade::setUp() {
    objeto = new Quantidade();
    estado = SUCESSO;
}

void TUQuantidade::tearDown() {
    delete objeto;
}

void TUQuantidade::testarCenarioValido() {
    try {
        objeto->setValor(QTD_VALIDA);
        if (objeto->getValor() != QTD_VALIDA)
            estado = FALHA;
    } catch (...) {
        estado = FALHA;
    }
}

void TUQuantidade::testarCenarioInvalido() {
    try {
        objeto->setValor(QTD_INVALIDA);
        estado = FALHA;
    } catch (...) {
        if (objeto->getValor() == QTD_INVALIDA)
            estado = FALHA;
    }
}

int TUQuantidade::run() {
    setUp();
    testarCenarioValido();
    testarCenarioInvalido();
    tearDown();
    return estado;
}