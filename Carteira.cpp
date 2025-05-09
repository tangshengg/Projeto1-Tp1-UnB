#include "Carteira.h"
#include "Ordem.h"
#include <algorithm>

void Carteira::setCodigo(Codigo codigo) {
    this->codigo = codigo;
}

Codigo Carteira::getCodigo() const {
    return codigo;
}

void Carteira::setNome(Nome nome) {
    this->nome = nome;
}

Nome Carteira::getNome() const {
    return nome;
}

void Carteira::setPerfil(Perfil perfil) {
    this->perfil = perfil;
}

Perfil Carteira::getPerfil() const {
    return perfil;
}

void Carteira::setConta(Conta* conta) {
    this->conta = conta;
}

Conta* Carteira::getConta() const {
    return conta;
}

void Carteira::adicionarOrdem(Ordem* ordem) {
    ordens.push_back(ordem);
}

void Carteira::removerOrdem(Ordem* ordem) {
    auto it = std::find(ordens.begin(), ordens.end(), ordem);
    if (it != ordens.end()) {
        ordens.erase(it);
    }
}

vector<Ordem*> Carteira::getOrdens() const {
    return ordens;
}
