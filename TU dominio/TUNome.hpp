#ifndef TU_NOME_HPP
#define TU_NOME_HPP

#include "../../dominio/Nome.hpp"

class TUNome {
private:
    const std::string NOME_VALIDO = "João Silva";
    const std::string NOME_INVALIDO = "João  Silva"; // Espaço duplo
    Nome *objeto;
    int estado;

    void setUp();
    void tearDown();
    void testarCenarioValido();
    void testarCenarioInvalido();

public:
    int run();
};

#endif