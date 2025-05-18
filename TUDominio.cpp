#include "TUDominio.h"
#include "Dominio.h"
#include "Exceptions.h"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

// Implementação dos testes para Codigo
void TUCodigo::setUp() {
    objeto = new Codigo();
    estado = SUCESSO;
}

void TUCodigo::tearDown() {
    delete objeto;
}

void TUCodigo::testarCenarioValido() {
    try {
        objeto->setValor(VALOR_VALIDO);
        if (objeto->getValor() != VALOR_VALIDO)
            estado = FALHA;
    } catch (std::exception &e) {
        estado = FALHA;
    }
}

void TUCodigo::testarCenarioInvalidoTamanho() {
    try {
        objeto->setValor(VALOR_INVALIDO_TAMANHO);
        estado = FALHA;
    } catch (CodigoException &e) {
        // Esperado
    }
}

void TUCodigo::testarCenarioInvalidoCaractere() {
    try {
        objeto->setValor(VALOR_INVALIDO_CARACTERE);
        estado = FALHA;
    } catch (CodigoException &e) {
        // Esperado
    }
}

int TUCodigo::run() {
    setUp();
    testarCenarioValido();
    if (estado == FALHA)
        return estado;

    testarCenarioInvalidoTamanho();
    if (estado == FALHA)
        return estado;

    testarCenarioInvalidoCaractere();
    tearDown();

    return estado;
}

// Implementação dos testes para CodigoNegociacao
void TUCodigoNegociacao::setUp() {
    objeto = new CodigoNegociacao();
    estado = SUCESSO;
}

void TUCodigoNegociacao::tearDown() {
    delete objeto;
}

void TUCodigoNegociacao::testarCenarioValido() {
    try {
        objeto->setValor(VALOR_VALIDO);
        if (objeto->getValor() != VALOR_VALIDO)
            estado = FALHA;
    } catch (std::exception &e) {
        estado = FALHA;
    }
}

void TUCodigoNegociacao::testarCenarioInvalidoTamanhoVazio() {
    try {
        objeto->setValor(VALOR_INVALIDO_TAMANHO);
        estado = FALHA;
    } catch (CodigoNegociacaoException &e) {
        // Esperado
    }
}

void TUCodigoNegociacao::testarCenarioInvalidoTamanhoGrande() {
    try {
        objeto->setValor(VALOR_INVALIDO_TAMANHO_GRANDE);
        estado = FALHA;
    } catch (CodigoNegociacaoException &e) {
        // Esperado
    }
}

void TUCodigoNegociacao::testarCenarioInvalidoCaractere() {
    try {
        objeto->setValor(VALOR_INVALIDO_CARACTERE);
        estado = FALHA;
    } catch (CodigoNegociacaoException &e) {
        // Esperado
    }
}

int TUCodigoNegociacao::run() {
    setUp();
    testarCenarioValido();
    if (estado == FALHA)
        return estado;

    testarCenarioInvalidoTamanhoVazio();
    if (estado == FALHA)
        return estado;

    testarCenarioInvalidoTamanhoGrande();
    if (estado == FALHA)
        return estado;

    testarCenarioInvalidoCaractere();
    tearDown();

    return estado;
}

// Implementação dos testes para Cpf
void TUCpf::setUp() {
    objeto = new Cpf();
    estado = SUCESSO;
}

void TUCpf::tearDown() {
    delete objeto;
}

void TUCpf::testarCenarioValido() {
    try {
        objeto->setValor(VALOR_VALIDO);
        if (objeto->getValor() != VALOR_VALIDO)
            estado = FALHA;
    } catch (std::exception &e) {
        estado = FALHA;
    }
}

void TUCpf::testarCenarioInvalidoDigito() {
    try {
        objeto->setValor(VALOR_INVALIDO_DIGITO);
        estado = FALHA;
    } catch (CpfException &e) {
        // Esperado
    }
}

void TUCpf::testarCenarioInvalidoRepetido() {
    try {
        objeto->setValor(VALOR_INVALIDO_REPETIDO);
        estado = FALHA;
    } catch (CpfException &e) {
        // Esperado
    }
}

int TUCpf::run() {
    setUp();
    testarCenarioValido();
    if (estado == FALHA)
        return estado;

    testarCenarioInvalidoDigito();
    if (estado == FALHA)
        return estado;

    testarCenarioInvalidoRepetido();
    tearDown();

    return estado;
}

// Implementação dos testes para Data
void TUData::setUp() {
    objeto = new Data();
    estado = SUCESSO;
}

void TUData::tearDown() {
    delete objeto;
}

void TUData::testarCenarioValido() {
    try {
        objeto->setValor(VALOR_VALIDO);
        if (objeto->getValor() != VALOR_VALIDO)
            estado = FALHA;
    } catch (std::exception &e) {
        estado = FALHA;
    }
}

void TUData::testarCenarioInvalidoFormato() {
    try {
        objeto->setValor(VALOR_INVALIDO_FORMATO);
        estado = FALHA;
    } catch (DataException &e) {
        // Esperado
    }
}

void TUData::testarCenarioInvalidoDia() {
    try {
        objeto->setValor(VALOR_INVALIDO_DIA);
        estado = FALHA;
    } catch (DataException &e) {
        // Esperado
    }
}

void TUData::testarCenarioInvalidoMes() {
    try {
        objeto->setValor(VALOR_INVALIDO_MES);
        estado = FALHA;
    } catch (DataException &e) {
        // Esperado
    }
}

int TUData::run() {
    setUp();
    testarCenarioValido();
    if (estado == FALHA)
        return estado;

    testarCenarioInvalidoFormato();
    if (estado == FALHA)
        return estado;

    testarCenarioInvalidoDia();
    if (estado == FALHA)
        return estado;

    testarCenarioInvalidoMes();
    tearDown();

    return estado;
}

// Implementação dos testes para Nome
void TUNome::setUp() {
    objeto = new Nome();
    estado = SUCESSO;
}

void TUNome::tearDown() {
    delete objeto;
}

void TUNome::testarCenarioValido() {
    try {
        objeto->setValor(VALOR_VALIDO);
        if (objeto->getValor() != VALOR_VALIDO)
            estado = FALHA;
    } catch (std::exception &e) {
        estado = FALHA;
    }
}

void TUNome::testarCenarioInvalidoTamanhoGrande() {
    try {
        objeto->setValor(VALOR_INVALIDO_TAMANHO);
        estado = FALHA;
    } catch (NomeException &e) {
        // Esperado
    }
}

void TUNome::testarCenarioInvalidoVazio() {
    try {
        objeto->setValor(VALOR_INVALIDO_VAZIO);
        estado = FALHA;
    } catch (NomeException &e) {
        // Esperado
    }
}

void TUNome::testarCenarioInvalidoCaractere() {
    try {
        objeto->setValor(VALOR_INVALIDO_CARACTERE);
        estado = FALHA;
    } catch (NomeException &e) {
        // Esperado
    }
}

void TUNome::testarCenarioInvalidoEspacos() {
    try {
        objeto->setValor(VALOR_INVALIDO_ESPACOS);
        estado = FALHA;
    } catch (NomeException &e) {
        // Esperado
    }
}

int TUNome::run() {
    setUp();
    testarCenarioValido();
    if (estado == FALHA)
        return estado;

    testarCenarioInvalidoTamanhoGrande();
    if (estado == FALHA)
        return estado;

    testarCenarioInvalidoVazio();
    if (estado == FALHA)
        return estado;

    testarCenarioInvalidoCaractere();
    if (estado == FALHA)
        return estado;

    testarCenarioInvalidoEspacos();
    tearDown();

    return estado;
}

// Implementação dos testes para Perfil
void TUPerfil::setUp() {
    objeto = new Perfil();
    estado = SUCESSO;
}

void TUPerfil::tearDown() {
    delete objeto;
}

void TUPerfil::testarCenarioValidoConservador() {
    try {
        objeto->setValor(VALOR_VALIDO_CONSERVADOR);
        if (objeto->getValor() != VALOR_VALIDO_CONSERVADOR)
            estado = FALHA;
    } catch (std::exception &e) {
        estado = FALHA;
    }
}

void TUPerfil::testarCenarioValidoModerado() {
    try {
        objeto->setValor(VALOR_VALIDO_MODERADO);
        if (objeto->getValor() != VALOR_VALIDO_MODERADO)
            estado = FALHA;
    } catch (std::exception &e) {
        estado = FALHA;
    }
}

void TUPerfil::testarCenarioValidoAgressivo() {
    try {
        objeto->setValor(VALOR_VALIDO_AGRESSIVO);
        if (objeto->getValor() != VALOR_VALIDO_AGRESSIVO)
            estado = FALHA;
    } catch (std::exception &e) {
        estado = FALHA;
    }
}

void TUPerfil::testarCenarioInvalido() {
    try {
        objeto->setValor(VALOR_INVALIDO);
        estado = FALHA;
    } catch (PerfilException &e) {
        // Esperado
    }
}

int TUPerfil::run() {
    setUp();
    testarCenarioValidoConservador();
    if (estado == FALHA)
        return estado;

    testarCenarioValidoModerado();
    if (estado == FALHA)
        return estado;

    testarCenarioValidoAgressivo();
    if (estado == FALHA)
        return estado;

    testarCenarioInvalido();
    tearDown();

    return estado;
}

// Implementação dos testes para Dinheiro
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
    } catch (std::exception &e) {
        estado = FALHA;
    }
}

void TUDinheiro::testarCenarioValidoPonto() {
    try {
        objeto->setValor(VALOR_VALIDO_PONTO);
        if (objeto->getValor() != VALOR_VALIDO_PONTO)
            estado = FALHA;
    } catch (std::exception &e) {
        estado = FALHA;
    }
}

void TUDinheiro::testarCenarioInvalidoMinimo() {
    try {
        objeto->setValor(VALOR_INVALIDO_MINIMO);
        estado = FALHA;
    } catch (DinheiroException &e) {
        // Esperado
    }
}

void TUDinheiro::testarCenarioInvalidoMaximo() {
    try {
        objeto->setValor(VALOR_INVALIDO_MAXIMO);
        estado = FALHA;
    } catch (DinheiroException &e) {
        // Esperado
    }
}

void TUDinheiro::testarCenarioInvalidoFormato() {
    try {
        objeto->setValor(VALOR_INVALIDO_FORMATO);
        estado = FALHA;
    } catch (DinheiroException &e) {
        // Esperado
    }
}

int TUDinheiro::run() {
    setUp();
    testarCenarioValido();
    if (estado == FALHA)
        return estado;

    testarCenarioValidoPonto();
    if (estado == FALHA)
        return estado;

    testarCenarioInvalidoMinimo();
    if (estado == FALHA)
        return estado;

    testarCenarioInvalidoMaximo();
    if (estado == FALHA)
        return estado;

    testarCenarioInvalidoFormato();
    tearDown();

    return estado;
}

// Implementação dos testes para Quantidade
void TUQuantidade::setUp() {
    objeto = new Quantidade();
    estado = SUCESSO;
}

void TUQuantidade::tearDown() {
    delete objeto;
}

void TUQuantidade::testarCenarioValido() {
    try {
        objeto->setValor(VALOR_VALIDO);
        if (objeto->getValor() != VALOR_VALIDO)
            estado = FALHA;
    } catch (std::exception &e) {
        estado = FALHA;
    }
}

void TUQuantidade::testarCenarioInvalidoMinimo() {
    try {
        objeto->setValor(VALOR_INVALIDO_MINIMO);
        estado = FALHA;
    } catch (QuantidadeException &e) {
        // Esperado
    }
}

void TUQuantidade::testarCenarioInvalidoMaximo() {
    try {
        objeto->setValor(VALOR_INVALIDO_MAXIMO);
        estado = FALHA;
    } catch (QuantidadeException &e) {
        // Esperado
    }
}

void TUQuantidade::testarCenarioInvalidoFormato() {
    try {
        objeto->setValor(VALOR_INVALIDO_FORMATO);
        estado = FALHA;
    } catch (QuantidadeException &e) {
        // Esperado
    }
}

int TUQuantidade::run() {
    setUp();
    testarCenarioValido();
    if (estado == FALHA)
        return estado;

    testarCenarioInvalidoMinimo();
    if (estado == FALHA)
        return estado;

    testarCenarioInvalidoMaximo();
    if (estado == FALHA)
        return estado;

    testarCenarioInvalidoFormato();
    tearDown();

    return estado;
}

// Implementação dos testes para Senha
void TUSenha::setUp() {
    objeto = new Senha();
    estado = SUCESSO;
}

void TUSenha::tearDown() {
    delete objeto;
}

void TUSenha::testarCenarioValido() {
    try {
        objeto->setValor(VALOR_VALIDO);
        if (objeto->getValor() != VALOR_VALIDO)
            estado = FALHA;
    } catch (std::exception &e) {
        estado = FALHA;
    }
}

void TUSenha::testarCenarioInvalidoTamanho() {
    try {
        objeto->setValor(VALOR_INVALIDO_TAMANHO);
        estado = FALHA;
    } catch (SenhaException &e) {
        // Esperado
    }
}

void TUSenha::testarCenarioInvalidoCaractere() {
    try {
        objeto->setValor(VALOR_INVALIDO_CARACTERE);
        estado = FALHA;
    } catch (SenhaException &e) {
        // Esperado
    }
}

void TUSenha::testarCenarioInvalidoDuplicado() {
    try {
        objeto->setValor(VALOR_INVALIDO_DUPLICADO);
        estado = FALHA;
    } catch (SenhaException &e) {
        // Esperado
    }
}

void TUSenha::testarCenarioInvalidoSemDigito() {
    try {
        objeto->setValor(VALOR_INVALIDO_SEM_DIGITO);
        estado = FALHA;
    } catch (SenhaException &e) {
        // Esperado
    }
}

void TUSenha::testarCenarioInvalidoSemMaiuscula() {
    try {
        objeto->setValor(VALOR_INVALIDO_SEM_MAIUSCULA);
        estado = FALHA;
    } catch (SenhaException &e) {
        // Esperado
    }
}

void TUSenha::testarCenarioInvalidoSemMinuscula() {
    try {
        objeto->setValor(VALOR_INVALIDO_SEM_MINUSCULA);
        estado = FALHA;
    } catch (SenhaException &e) {
        // Esperado
    }
}

void TUSenha::testarCenarioInvalidoSemEspecial() {
    try {
        objeto->setValor(VALOR_INVALIDO_SEM_ESPECIAL);
        estado = FALHA;
    } catch (SenhaException &e) {
        // Esperado
    }
}

int TUSenha::run() {
    setUp();
    testarCenarioValido();
    if (estado == FALHA)
        return estado;

    testarCenarioInvalidoTamanho();
    if (estado == FALHA)
        return estado;

    testarCenarioInvalidoCaractere();
    if (estado == FALHA)
        return estado;

    testarCenarioInvalidoDuplicado();
    if (estado == FALHA)
        return estado;

    testarCenarioInvalidoSemDigito();
    if (estado == FALHA)
        return estado;

    testarCenarioInvalidoSemMaiuscula();
    if (estado == FALHA)
        return estado;

    testarCenarioInvalidoSemMinuscula();
    if (estado == FALHA)
        return estado;

    testarCenarioInvalidoSemEspecial();
    tearDown();

    return estado;
}
