#ifndef CONTA_H_INCLUDED
#define CONTA_H_INCLUDED

#include "Dominio.h"

class Conta{
private:

    Cpf cpf;
    Nome nome;
    Senha senha;

public:

    void setCpf(Cpf);
    Cpf getCpf() const;

    void setNome(Nome);
    Nome getNome() const;

    void setSenha(Senha);
    Senha getSenha() const;
};


#endif // CONTA_H_INCLUDED
