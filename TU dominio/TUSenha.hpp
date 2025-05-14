#ifndef TU_SENHA_HPP
#define TU_SENHA_HPP

#include "../../dominio/Senha.hpp"

class TUSenha {
private:
    const std::string SENHA_VALIDA = "A1b$C2";
    const std::string SENHA_INVALIDA = "senhafraca";
    Senha *objeto;
    int estado;

    void setUp();
    void tearDown();
    void testarCenarioValido();
    void testarCenarioInvalido();

public:
    int run();
};

#endif