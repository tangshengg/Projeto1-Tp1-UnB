#include "Dominio.h"
#
#include <stdexcept>
#include <regex>
#include <algorithm>
#include <cctype>

#include "Exceptions.h"

using namespace std;

// CÓDIGO

void Codigo::validar(string codigo) {
    if (codigo.length() != 5) {
        throw CodigoException("Codigo deve ter exatamente 5 digitos");
    }

    for (char c : codigo) {
        if (!isdigit(c)) {
            throw CodigoException("Codigo deve conter apenas números");
        }
    }
}

void Codigo::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

string Codigo::getValor() const {
    return valor;
}

// CÓDIGO NEGOCIAÇÃO

void CodigoNegociacao::validar(string codigo) {
    if (codigo.length() > 12 || codigo.empty()) {
        throw CodigoNegociacaoException("Codigo de negociacao deve ter entre 1 e 12 caracteres");
    }

    for (char c : codigo) {
        if (!isdigit(c) && !isalpha(c) && c != ' ') {
            throw CodigoNegociacaoException("Codigo de negociacao deve conter apenas digitos, letras ou espacos");
        }
    }
}

void CodigoNegociacao::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

string CodigoNegociacao::getValor() const {
    return valor;
}

// CPF

void Cpf::validar(string cpf) {
    string cpfLimpo = "";
    for (char c : cpf) {
        if (isdigit(c)) {
            cpfLimpo += c;
        }
    }

    if (cpfLimpo.length() != 11) {
        throw CpfException("CPF deve ter 11 digitos");
    }

    bool todosIguais = true;
    for (int i = 1; i < 11; i++) {
        if (cpfLimpo[i] != cpfLimpo[0]) {
            todosIguais = false;
            break;
        }
    }
    if (todosIguais) {
        throw CpfException("CPF invalido");
    }

    int soma = 0;
    for (int i = 0; i < 9; i++) {
        soma += (cpfLimpo[i] - '0') * (10 - i);
    }
    int resto = soma % 11;
    int dv1 = (resto < 2) ? 0 : (11 - resto);

    if ((cpfLimpo[9] - '0') != dv1) {
        throw CpfException("CPF invalido");
    }

    soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += (cpfLimpo[i] - '0') * (11 - i);
    }
    resto = soma % 11;
    int dv2 = (resto < 2) ? 0 : (11 - resto);

    if ((cpfLimpo[10] - '0') != dv2) {
        throw CpfException("CPF invalido");
    }
}


void Cpf::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

string Cpf::getValor() const {
    return valor;
}



// DATA

void Data::validar(string data) {
    if (data.length() != 8) {
        throw DataException("Data deve estar no formato AAAAMMDD");
    }

    for (char c : data) {
        if (!isdigit(c)) {
            throw DataException("Data deve conter apenas digitos");
        }
    }

    int ano = stoi(data.substr(0, 4));
    int mes = stoi(data.substr(4, 2));
    int dia = stoi(data.substr(6, 2));

    if (mes < 1 || mes > 12) {
        throw DataException("Mes invalido");
    }

    int diasNoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        diasNoMes[2] = 29;
    }

    if (dia < 1 || dia > diasNoMes[mes]) {
        throw DataException("Dia invalido para o mes");
    }
}

void Data::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

string Data::getValor() const {
    return valor;
}

// NOME

void Nome::validar(string nome) {
    if (nome.length() > 20 || nome.empty()) {
        throw NomeException("Nome deve ter entre 1 e 20 caracteres");
    }

    for (size_t i = 0; i < nome.length(); i++) {
        char c = nome[i];
        if (!isdigit(c) && !isalpha(c) && c != ' ') {
            throw NomeException("Nome deve conter apenas digitos, letras ou espacos");
        }

        if (c == ' ' && i < nome.length() - 1 && nome[i+1] == ' ') {
            throw NomeException("Nome nao pode conter espacos em sequencia");
        }
    }
}

void Nome::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

string Nome::getValor() const {
    return valor;
}

// PERFIL

void Perfil::validar(string perfil) {
    if (perfil != "Conservador" && perfil != "Moderado" && perfil != "Agressivo") {
        throw PerfilException("Perfil deve ser Conservador, Moderado ou Agressivo");
    }
}

void Perfil::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

string Perfil::getValor() const {
    return valor;
}


// DINHEIRO

void Dinheiro::validar(string dinheiro) {
    double valor;
    try {
        string temp = dinheiro;
        replace(temp.begin(), temp.end(), ',', '.');
        valor = stod(temp);
    } catch (...) {
        throw DinheiroException("Formato de dinheiro invalido");
    }

    if (valor < 0.01 || valor > 1000000.00) {
        throw DinheiroException("Valor deve estar entre 0,01 e 1.000.000,00");
    }
}

void Dinheiro::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

string Dinheiro::getValor() const {
    return valor;
}


// QUANTIDADE

void Quantidade::validar(string quantidade) {
    int valor;
    try {
        valor = stoi(quantidade);
    } catch (...) {
        throw QuantidadeException("Quantidade deve ser um numero inteiro");
    }

    if (valor < 1 || valor > 1000000) {
        throw QuantidadeException("Quantidade deve estar entre 1 e 1.000.000");
    }
}

void Quantidade::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

string Quantidade::getValor() const {
    return valor;
}

// SENHA

void Senha::validar(string senha) {
    if (senha.length() != 6) {
        throw SenhaException("Senha deve ter exatamente 6 caracteres");
    }

    for (char c : senha) {
        if (!isdigit(c) && !isalpha(c) && c != '#' && c != '$' && c != '%' && c != '&') {
            throw SenhaException("Senha deve conter apenas digitos, letras, #, $, % ou &");
        }
    }

    for (size_t i = 0; i < senha.length(); i++) {
        for (size_t j = i + 1; j < senha.length(); j++) {
            if (senha[i] == senha[j]) {
                throw SenhaException("Senha nao pode conter caracteres duplicados");
            }
        }
    }

    bool temDigito = false;
    for (char c : senha) {
        if (isdigit(c)) {
            temDigito = true;
            break;
        }
    }
    if (!temDigito) {
        throw SenhaException("Senha deve conter pelo menos um digito");
    }

    bool temMaiuscula = false;
    for (char c : senha) {
        if (isupper(c)) {
            temMaiuscula = true;
            break;
        }
    }
    if (!temMaiuscula) {
        throw SenhaException("Senha deve conter pelo menos uma letra maiuscula");
    }

    bool temMinuscula = false;
    for (char c : senha) {
        if (islower(c)) {
            temMinuscula = true;
            break;
        }
    }
    if (!temMinuscula) {
        throw SenhaException("Senha deve conter pelo menos uma letra minuscula");
    }

    bool temEspecial = false;
    for (char c : senha) {
        if (c == '#' || c == '$' || c == '%' || c == '&') {
            temEspecial = true;
            break;
        }
    }
    if (!temEspecial) {
        throw SenhaException("Senha deve conter pelo menos um caractere especial (#, $, % ou &)");
    }
}

void Senha::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

string Senha::getValor() const {
    return valor;
}
