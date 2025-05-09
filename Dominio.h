#ifndef DOMINIO_H_INCLUDED
#define DOMINIO_H_INCLUDED

#include <string>
using std::string;

class Cpf {
private:
    string valor;
    void validar(string);
public:
    void setValor(string);
    string getValor() const;
};

class Nome {
private:
    string valor;
    void validar(string);
public:
    void setValor(string);
    string getValor() const;
};


class Codigo {
private:
    string valor;
    void validar(string);
public:
    void setValor(string);
    string getValor() const;
};

class CodigoNegociacao {
private:
    string valor;
    void validar(string);
public:
    void setValor(string);
    string getValor() const;
};

class Data {
private:
    string valor;
    void validar(string);
public:
    void setValor(string);
    string getValor() const;
};

class Perfil {
private:
    string valor;
    void validar(string);
public:
    void setValor(string);
    string getValor() const;
};

class Dinheiro {
private:
    string valor;
    void validar(string);
public:
    void setValor(string);
    string getValor() const;
};

class Quantidade {
private:
    string valor;
    void validar(string);
public:
    void setValor(string);
    string getValor() const;
};

class Senha {
private:
    string valor;
    void validar(string);
public:
    void setValor(string);
    string getValor() const;
};

#endif // DOMINIO_H_INCLUDED
