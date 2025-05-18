#ifndef TU_DATA_HPP
#define TU_DATA_HPP

#include "../../dominio/Data.hpp"

class TUData {
private:
    const std::string DATA_VALIDA = "20231015";
    const std::string DATA_INVALIDA = "20230229"; // Não bissexto
    Data *objeto;
    int estado;

    void setUp();
    void tearDown();
    void testarCenarioValido();
    void testarCenarioInvalido();

public:
    int run();
};

#endif