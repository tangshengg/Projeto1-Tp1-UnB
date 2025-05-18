#ifndef TU_ORDEM_HPP
#define TU_ORDEM_HPP

#include "../../entidade/Ordem.hpp"
#include "../../dominio/CodigoNegociacao.hpp"
#include "../../dominio/Data.hpp"
#include "../../dominio/Quantidade.hpp"

class TUOrdem {
private:
    const std::string CODIGO_VALIDO = "PETR4";      // Código válido (até 12 chars)
    const std::string DATA_VALIDA = "20231015";      // Data válida (AAAAMMDD)
    const std::string QUANTIDADE_VALIDA = "100";     // Quantidade válida (1-1.000.000)

    Ordem *ordem;
    int estado;

    void setUp();
    void tearDown();
    void testarCenarioValido();
    void testarCenarioInvalido();
    void testarBloqueioEdicao(); // Testa regra "Ordem não pode ser editada" 

public:
    int run();
};
#endif
