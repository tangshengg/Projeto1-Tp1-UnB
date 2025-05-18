#include "TUConta.hpp"

void TUConta::setUp() {
    conta = new Conta(); // 
    estado = SUCESSO;    // Estado inicial (presume sucesso)
}

void TUConta::testarCenarioValido() {
    try {
        CPF cpf;
        cpf.setValor(CPF_VALIDO); // Testa setter com CPF válido
        conta->setCpf(cpf);       // testar todos os métodos públicos

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
        estado = FALHA; // Se não lançou exceção, falhou 
    } catch (...) {
        // OK! Comportamento esperado
    }
}

void TUConta::testarAssociacaoCarteiras() {
    Carteira carteira;
    Codigo codigo;
    codigo.setValor("12345"); // Código válido (5 dígitos)
    carteira.setCodigo(codigo);

    conta->adicionarCarteira(carteira); 
    if (conta->getCarteiras().empty()) // Verifica se a carteira foi adicionada
        estado = FALHA; // Falha se não associou
}

int TUConta::run() {
    setUp();
    testarCenarioValido();   
    testarCenarioInvalido(); 
    testarAssociacaoCarteiras(); 
    tearDown();
    return estado; // Retorna resultado (SUCESSO/FALHA)
}
