#ifndef TU_CPF_HPP
#define TU_CPF_HPP

#include "../../dominio/CPF.hpp"

class TUCPF {
private:
    const std::string CPF_VALIDO = "529.982.247-25";
    const std::string CPF_INVALIDO = "111.111.111-11";
    CPF *objeto;
    int estado;

    void setUp();
    void tearDown();
    void testarCenarioValido();
    void testarCenarioInvalido();

public:
    int run();
};

#endif