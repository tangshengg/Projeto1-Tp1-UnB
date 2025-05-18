#ifndef TU_DOMINIO_HPP
#define TU_DOMINIO_HPP

#include "Dominio.h"
#include <string>

using std::string;// Testes unitários para Codigo
class TUCodigo {
private:
    const static int SUCESSO = 0;
    const static int FALHA = -1;

    // Valores para teste
    const std::string VALOR_VALIDO = "12345";
    const std::string VALOR_INVALIDO_TAMANHO = "123";
    const std::string VALOR_INVALIDO_CARACTERE = "1234A";

    Codigo* objeto;
    int estado;

    void setUp();
    void tearDown();
    void testarCenarioValido();
    void testarCenarioInvalidoTamanho();
    void testarCenarioInvalidoCaractere();

public:
    int run();
};

// Testes unitários para CodigoNegociacao
class TUCodigoNegociacao {
private:
    const static int SUCESSO = 0;
    const static int FALHA = -1;

    // Valores para teste
    const std::string VALOR_VALIDO = "ABC123";
    const std::string VALOR_INVALIDO_TAMANHO = ""; // Vazio
    const std::string VALOR_INVALIDO_TAMANHO_GRANDE = "123456789012345"; // > 12 caracteres
    const std::string VALOR_INVALIDO_CARACTERE = "ABC@123";

    CodigoNegociacao* objeto;
    int estado;

    void setUp();
    void tearDown();
    void testarCenarioValido();
    void testarCenarioInvalidoTamanhoVazio();
    void testarCenarioInvalidoTamanhoGrande();
    void testarCenarioInvalidoCaractere();

public:
    int run();
};

// Testes unitários para Cpf
class TUCpf {
private:
    const static int SUCESSO = 0;
    const static int FALHA = -1;

    // Valores para teste
    const std::string VALOR_VALIDO = "529.982.247-25"; // CPF válido
    const std::string VALOR_INVALIDO_DIGITO = "529.982.247-24"; // Dígito verificador incorreto
    const std::string VALOR_INVALIDO_FORMATO = "52998224725"; // Sem formatação
    const std::string VALOR_INVALIDO_REPETIDO = "111.111.111-11"; // Dígitos repetidos

    Cpf* objeto;
    int estado;

    void setUp();
    void tearDown();
    void testarCenarioValido();
    void testarCenarioInvalidoDigito();
    void testarCenarioInvalidoRepetido();

public:
    int run();
};

// Testes unitários para Data
class TUData {
private:
    const static int SUCESSO = 0;
    const static int FALHA = -1;

    // Valores para teste
    const std::string VALOR_VALIDO = "20240510"; // 10/05/2024
    const std::string VALOR_INVALIDO_FORMATO = "2024-05-10"; // Formato inválido
    const std::string VALOR_INVALIDO_DIA = "20240532"; // Dia inválido
    const std::string VALOR_INVALIDO_MES = "20241310"; // Mês inválido

    Data* objeto;
    int estado;

    void setUp();
    void tearDown();
    void testarCenarioValido();
    void testarCenarioInvalidoFormato();
    void testarCenarioInvalidoDia();
    void testarCenarioInvalidoMes();

public:
    int run();
};

// Testes unitários para Nome
class TUNome {
private:
    const static int SUCESSO = 0;
    const static int FALHA = -1;

    // Valores para teste
    const std::string VALOR_VALIDO = "Joao Silva";
    const std::string VALOR_INVALIDO_TAMANHO = "Nome muito grande para o sistema testar falha"; // > 20
    const std::string VALOR_INVALIDO_VAZIO = ""; // Vazio
    const std::string VALOR_INVALIDO_CARACTERE = "Joao@Silva"; // Caractere inválido
    const std::string VALOR_INVALIDO_ESPACOS = "Joao  Silva"; // Espaços em sequência

    Nome* objeto;
    int estado;

    void setUp();
    void tearDown();
    void testarCenarioValido();
    void testarCenarioInvalidoTamanhoGrande();
    void testarCenarioInvalidoVazio();
    void testarCenarioInvalidoCaractere();
    void testarCenarioInvalidoEspacos();

public:
    int run();
};

// Testes unitários para Perfil
class TUPerfil {
private:
    const static int SUCESSO = 0;
    const static int FALHA = -1;

    // Valores para teste
    const std::string VALOR_VALIDO_CONSERVADOR = "Conservador";
    const std::string VALOR_VALIDO_MODERADO = "Moderado";
    const std::string VALOR_VALIDO_AGRESSIVO = "Agressivo";
    const std::string VALOR_INVALIDO = "Neutro";

    Perfil* objeto;
    int estado;

    void setUp();
    void tearDown();
    void testarCenarioValidoConservador();
    void testarCenarioValidoModerado();
    void testarCenarioValidoAgressivo();
    void testarCenarioInvalido();

public:
    int run();
};

// Testes unitários para Dinheiro
class TUDinheiro {
private:
    const static int SUCESSO = 0;
    const static int FALHA = -1;

    // Valores para teste
    const std::string VALOR_VALIDO = "1000,50";
    const std::string VALOR_VALIDO_PONTO = "1000.50";
    const std::string VALOR_INVALIDO_MINIMO = "0,00";
    const std::string VALOR_INVALIDO_MAXIMO = "1000001,00";
    const std::string VALOR_INVALIDO_FORMATO = "mil reais";

    Dinheiro* objeto;
    int estado;

    void setUp();
    void tearDown();
    void testarCenarioValido();
    void testarCenarioValidoPonto();
    void testarCenarioInvalidoMinimo();
    void testarCenarioInvalidoMaximo();
    void testarCenarioInvalidoFormato();

public:
    int run();
};

// Testes unitários para Quantidade
class TUQuantidade {
private:
    const static int SUCESSO = 0;
    const static int FALHA = -1;

    // Valores para teste
    const std::string VALOR_VALIDO = "100";
    const std::string VALOR_INVALIDO_MINIMO = "0";
    const std::string VALOR_INVALIDO_MAXIMO = "1000001";
    const std::string VALOR_INVALIDO_FORMATO = "cem";

    Quantidade* objeto;
    int estado;

    void setUp();
    void tearDown();
    void testarCenarioValido();
    void testarCenarioInvalidoMinimo();
    void testarCenarioInvalidoMaximo();
    void testarCenarioInvalidoFormato();

public:
    int run();
};

// Testes unitários para Senha
class TUSenha {
private:
    const static int SUCESSO = 0;
    const static int FALHA = -1;

    // Valores para teste
    const std::string VALOR_VALIDO = "A1b2$c";
    const std::string VALOR_INVALIDO_TAMANHO = "A1b$";
    const std::string VALOR_INVALIDO_CARACTERE = "A1b2+c";
    const std::string VALOR_INVALIDO_DUPLICADO = "A1b2$$";
    const std::string VALOR_INVALIDO_SEM_DIGITO = "Abc$ef";
    const std::string VALOR_INVALIDO_SEM_MAIUSCULA = "a1b2$c";
    const std::string VALOR_INVALIDO_SEM_MINUSCULA = "A1B2$C";
    const std::string VALOR_INVALIDO_SEM_ESPECIAL = "A1b2c3";

    Senha* objeto;
    int estado;

    void setUp();
    void tearDown();
    void testarCenarioValido();
    void testarCenarioInvalidoTamanho();
    void testarCenarioInvalidoCaractere();
    void testarCenarioInvalidoDuplicado();
    void testarCenarioInvalidoSemDigito();
    void testarCenarioInvalidoSemMaiuscula();
    void testarCenarioInvalidoSemMinuscula();
    void testarCenarioInvalidoSemEspecial();

public:
    int run();
};

#endif // TU_DOMINIO_HPP
