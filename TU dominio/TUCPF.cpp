#include "TUCPF.hpp"

void TUCPF::setUp() {
    objeto = new CPF();
    estado = SUCESSO;
}

void TUCPF::tearDown() {
    delete objeto;
}

void TUCPF::testarCenarioValido() {
    try {
        objeto->setValor(CPF_VALIDO);
        if (objeto->getValor() != CPF_VALIDO)
            estado = FALHA;
    } catch (...) {
        estado = FALHA;
    }
}

void TUCPF::testarCenarioInvalido() {
    try {
        objeto->setValor(CPF_INVALIDO);
        estado = FALHA;
    } catch (...) {
        if (objeto->getValor() == CPF_INVALIDO)
            estado = FALHA;
    }
}

int TUCPF::run() {
    setUp();
    testarCenarioValido();
    testarCenarioInvalido();
    tearDown();
    return estado;
}