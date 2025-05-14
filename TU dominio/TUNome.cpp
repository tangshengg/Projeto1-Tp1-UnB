#include "TUNome.hpp"

void TUNome::setUp() {
    objeto = new Nome();
    estado = SUCESSO;
}

void TUNome::tearDown() {
    delete objeto;
}

void TUNome::testarCenarioValido() {
    try {
        objeto->setValor(NOME_VALIDO);
        if (objeto->getValor() != NOME_VALIDO)
            estado = FALHA;
    } catch (...) {
        estado = FALHA;
    }
}

void TUNome::testarCenarioInvalido() {
    try {
        objeto->setValor(NOME_INVALIDO);
        estado = FALHA;
    } catch (...) {
        if (objeto->getValor() == NOME_INVALIDO)
            estado = FALHA;
    }
}

int TUNome::run() {
    setUp();
    testarCenarioValido();
    testarCenarioInvalido();
    tearDown();
    return estado;
}