#ifndef TU_CARTEIRA_HPP
#define TU_CARTEIRA_HPP

#include "../../entidade/Carteira.hpp"
#include "../../dominio/Codigo.hpp"
#include "../../dominio/Perfil.hpp"
#include "../../dominio/Dinheiro.hpp"

class TUCarteira {
private:
    const std::string CODIGO_VALIDO = "12345";
    const std::string PERFIL_VALIDO = "Moderado";
    const std::string DINHEIRO_VALIDO = "1500.00";

    Carteira *carteira;
    int estado;

    void setUp();
    void tearDown();
    void testarCenarioValido();
    void testarCenarioInvalido();
    void testarSaldo();

public:
    int run();
};

#endif