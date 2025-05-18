#ifndef TU_CONTA_HPP
#define TU_CONTA_HPP

#include "../../entidade/Conta.hpp"
#include "../../dominio/CPF.hpp"
#include "../../dominio/Nome.hpp"
#include "../../dominio/Senha.hpp"

class TUConta {
private:
    // Constantes para valores de teste (alinhados com as regras do PDF)
    const std::string CPF_VALIDO = "529.982.247-25";   // CPF válido (formato XXX.XXX.XXX-XX)
    const std::string CPF_INVALIDO = "111.111.111-11"; // CPF inválido (dígitos iguais)
    const std::string NOME_VALIDO = "Joao Silva";      // Nome válido (sem espaços duplos)
    const std::string SENHA_VALIDA = "A1b$C2";         // Senha válida (6 chars com mistura)

    Conta *conta;      // Objeto sob teste
    int estado;        // SUCESSO=1, FALHA=0 

    void setUp();      // Configura ambiente de teste
    void tearDown();   // Limpa ambiente
    void testarCenarioValido();  // Teste com valores válidos 
    void testarCenarioInvalido();// Teste com valores inválidos 
    void testarAssociacaoCarteiras(); // Verifica vinculação Conta-Carteira 

public:
    int run(); 
};
#endif
