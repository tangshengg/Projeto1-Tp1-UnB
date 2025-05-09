#ifndef CARTEIRA_H_INCLUDED
#define CARTEIRA_H_INCLUDED

#include "Dominio.h"
#include "Conta.h"

#include <vector>

using std::vector;

class Ordem;

class Carteira {
private:
    Codigo codigo;
    Nome nome;
    Perfil perfil;
    Conta* conta;
    vector<Ordem*> ordens;

public:

    void setCodigo(Codigo);
    Codigo getCodigo() const;

    void setNome(Nome);
    Nome getNome() const;

    void setPerfil(Perfil);
    Perfil getPerfil() const;


    void setConta(Conta*);
    Conta* getConta() const;

    void adicionarOrdem(Ordem*);
    void removerOrdem(Ordem*);
    vector<Ordem*> getOrdens() const;
};


#endif // CARTEIRA_H_INCLUDED
