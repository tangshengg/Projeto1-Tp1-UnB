#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED

#include <stdexcept>
#include <string>

using namespace std;

class CodigoException : public invalid_argument {
public:
    CodigoException(const string& msg) : invalid_argument(msg) {}
};

class CodigoNegociacaoException : public invalid_argument {
public:
    CodigoNegociacaoException(const string& msg) : invalid_argument(msg) {}
};

class CpfException : public invalid_argument {
public:
    CpfException(const string& msg) : invalid_argument(msg) {}
};

class DataException : public invalid_argument {
public:
    DataException(const string& msg) : invalid_argument(msg) {}
};

class NomeException : public invalid_argument {
public:
    NomeException(const string& msg) : invalid_argument(msg) {}
};

class PerfilException : public invalid_argument {
public:
    PerfilException(const string& msg) : invalid_argument(msg) {}
};

class DinheiroException : public invalid_argument {
public:
    DinheiroException(const string& msg) : invalid_argument(msg) {}
};

class QuantidadeException : public invalid_argument {
public:
    QuantidadeException(const string& msg) : invalid_argument(msg) {}
};

class SenhaException : public invalid_argument {
public:
    SenhaException(const string& msg) : invalid_argument(msg) {}
};

#endif
