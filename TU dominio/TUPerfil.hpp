#ifndef TU_PERFIL_HPP
#define TU_PERFIL_HPP

#include "../../dominio/Perfil.hpp"

class TUPerfil {
private:
    const std::string PERFIL_VALIDO = "Moderado";
    const std::string PERFIL_INVALIDO = "Arriscado";
    Perfil *objeto;
    int estado;

    void setUp();
    void tearDown();
    void testarCenarioValido();
    void testarCenarioInvalido();

public:
    int run();
};

#endif