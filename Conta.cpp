#include "Conta.h"

void Conta::setCpf(Cpf cpf) {
    this->cpf = cpf;
}

Cpf Conta::getCpf() const {
    return cpf;
}

void Conta::setNome(Nome nome) {
    this->nome = nome;
}

Nome Conta::getNome() const {
    return nome;
}

void Conta::setSenha(Senha senha) {
    this->senha = senha;
}

Senha Conta::getSenha() const {
    return senha;
}
