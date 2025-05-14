#ifndef TU_CODIGO_HPP
#define TU_CODIGO_HPP

#include "../../dominio/Codigo.hpp"

class TUCodigo {
private:
    const std::string CODIGO_VALIDO = "12345";
    const std::string CODIGO_INVALIDO = "1234A";
    Codigo *objeto;
    int estado; // SUCESSO ou FALHA

    void setUp();
    void tearDown();
    void testarCenarioValido();
    void testarCenarioInvalido();

public:
    int run();
};

#endif