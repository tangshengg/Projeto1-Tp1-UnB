#ifndef TU_DINHEIRO_HPP
#define TU_DINHEIRO_HPP

#include "../../dominio/Dinheiro.hpp"

class TUDinheiro {
private:
    const std::string VALOR_VALIDO = "1500.50";
    const std::string VALOR_INVALIDO = "-100.00";
    Dinheiro *objeto;
    int estado;

    void setUp();
    void tearDown();
    void testarCenarioValido();
    void testarCenarioInvalido();

public:
    int run();
};

#endif