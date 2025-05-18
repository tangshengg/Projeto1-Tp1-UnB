#include "TUOrdem.hpp"
#include <stdexcept>

void TUOrdem::setUp() {
    ordem = new Ordem();
    estado = SUCESSO;
}

void TUOrdem::tearDown() {
    delete ordem;
}

void TUOrdem::testarCenarioValido() {
    try {
        CodigoNegociacao codigo;
        codigo.setValor(CODIGO_VALIDO);
        ordem->setCodigoNegociacao(codigo);

        Data data;
        data.setValor(DATA_VALIDA);
        ordem->setData(data);

        Quantidade qtd;
        qtd.setValor(QUANTIDADE_VALIDA);
        ordem->setQuantidade(qtd);

        if (ordem->getCodigoNegociacao().getValor() != CODIGO_VALIDO ||
            ordem->getData().getValor() != DATA_VALIDA ||
            ordem->getQuantidade().getValor() != QUANTIDADE_VALIDA) {
            estado = FALHA;
        }
    } catch (...) {
        estado = FALHA;
    }
}

void TUOrdem::testarCenarioInvalido() {
    try {
        CodigoNegociacao codigo;
        codigo.setValor("CODIGO_INVALIDO_123"); // Inválido (mais de 12 caracteres)
        ordem->setCodigoNegociacao(codigo);
        estado = FALHA;
    } catch (...) {
        // OK: Comportamento esperado
    }
}

void TUOrdem::testarBloqueioEdicao() {
    CodigoNegociacao codigo;
    codigo.setValor(CODIGO_VALIDO);
    ordem->setCodigoNegociacao(codigo); // Primeira definição 

    // Tentativa de edição (deve falhar)
    CodigoNegociacao novoCodigo;
    novoCodigo.setValor("VALE3");
    try {
        ordem->setCodigoNegociacao(novoCodigo); // Deve lançar std::logic_error
        estado = FALHA;
    } catch (std::logic_error& e) {
        
    } catch (...) {
        estado = FALHA; // Falhou se lançou outra exceção
    }
}

int TUOrdem::run() {
    setUp();
    testarCenarioValido();
    testarCenarioInvalido();
    testarBloqueioEdicao();
    tearDown();
    return estado;
}
