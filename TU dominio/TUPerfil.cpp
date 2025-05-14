#include "TUPerfil.hpp"

void TUPerfil::setUp() {
    objeto = new Perfil();
    estado = SUCESSO;
}

void TUPerfil::tearDown() {
    delete objeto;
}

void TUPerfil::testarCenarioValido() {
    try {
        objeto->setValor(PERFIL_VALIDO);
        if (objeto->getValor() != PERFIL_VALIDO)
            estado = FALHA;
    } catch (...) {
        estado = FALHA;
    }
}

void TUPerfil::testarCenarioInvalido() {
    try {
        objeto->setValor(PERFIL_INVALIDO);
        estado = FALHA;
    } catch (...) {
        if (objeto->getValor() == PERFIL_INVALIDO)
            estado = FALHA;
    }
}

int TUPerfil::run() {
    setUp();
    testarCenarioValido();
    testarCenarioInvalido();
    tearDown();
    return estado;
}