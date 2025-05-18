#include "TUConta.hpp"

void TUConta::setUp() {
    conta = new Conta(); // Aloca objeto para teste (preparação)
    estado = SUCESSO;    // Estado inicial (presume sucesso)
}

void TUConta::testarCenarioValido() {
    try {
        CPF cpf;
        cpf.setValor(CPF_VALIDO); // Testa setter com CPF válido
        conta->setCpf(cpf);       // Requisito 14: testar todos os métodos públicos

        if (conta->getCpf().getValor() != CPF_VALIDO) // Verifica getter
            estado = FALHA; // Falha se valor não foi armazenado
    } catch (...) {
        estado = FALHA; // Falha se lançou exceção com valor válido
    }
}

void TUConta::testarCenarioInvalido() {
    try {
        CPF cpf;
        cpf.setValor(CPF_INVALIDO); // CPF inválido (deve lançar exceção)
        conta->setCpf(cpf);
        estado = FALHA; // Se não lançou exceção, falhou (requisito 7 do PDF)
    } catch (...) {
        // OK! Comportamento esperado
    }
}

void TUConta::testarAssociacaoCarteiras() {
    Carteira carteira;
    Codigo codigo;
    codigo.setValor("12345"); // Código válido (5 dígitos)
    carteira.setCodigo(codigo);

    conta->adicionarCarteira(carteira); // Testa vinculação (PDF: "associações")
    if (conta->getCarteiras().empty()) // Verifica se a carteira foi adicionada
        estado = FALHA; // Falha se não associou
}

int TUConta::run() {
    setUp();
    testarCenarioValido();   // Teste obrigatório (requisito 12)
    testarCenarioInvalido(); // Teste obrigatório (requisito 12)
    testarAssociacaoCarteiras(); // Teste específico do sistema
    tearDown();
    return estado; // Retorna resultado (SUCESSO/FALHA)
}