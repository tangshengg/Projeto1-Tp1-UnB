#include "TUData.hpp"

void TUData::setUp() {
    objeto = new Data();
    estado = SUCESSO;
}

void TUData::tearDown() {
    delete objeto;
}

void TUData::testarCenarioValido() {
    try {
        objeto->setValor(DATA_VALIDA);
        if (objeto->getValor() != DATA_VALIDA)
            estado = FALHA;
    } catch (...) {
        estado = FALHA;
    }
}

void TUData::testarCenarioInvalido() {
    try {
        objeto->setValor(DATA_INVALIDA);
        estado = FALHA;
    } catch (...) {
        if (objeto->getValor() == DATA_INVALIDA)
            estado = FALHA;
    }
}

int TUData::run() {
    setUp();
    testarCenarioValido();
    testarCenarioInvalido();
    tearDown();
    return estado;
}