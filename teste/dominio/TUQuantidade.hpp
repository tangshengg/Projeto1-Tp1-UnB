#ifndef TU_QUANTIDADE_HPP
#define TU_QUANTIDADE_HPP

#include "../../dominio/Quantidade.hpp"

class TUQuantidade {
private:
    const std::string QTD_VALIDA = "500";
    const std::string QTD_INVALIDA = "0";
    Quantidade *objeto;
    int estado;

    void setUp();
    void tearDown();
    void testarCenarioValido();
    void testarCenarioInvalido();

public:
    int run();
};

#endif