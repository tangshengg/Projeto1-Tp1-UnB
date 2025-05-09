#ifndef ORDEM_H_INCLUDED
#define ORDEM_H_INCLUDED

#include "Dominio.h"
#include "Carteira.h"

class Ordem{
private:

    Codigo codigo;
    CodigoNegociacao codigoNegociacao;
    Data data;
    Dinheiro preco;
    Quantidade quantidade;
    Carteira* carteira;

public:

    void setCodigo(Codigo);
    Codigo getCodigo() const;

    void setCodigoNegociacao(CodigoNegociacao);
    CodigoNegociacao getCodigoNegociacao() const;

    void setData(Data);
    Data getData() const;

    void setPreco(Dinheiro);
    Dinheiro getPreco() const;

    void setQuantidade(Quantidade);
    Quantidade getQuantidade() const;

    void setCarteira(Carteira*);
    Carteira* getCarteira() const;


};



#endif // ORDEM_H_INCLUDED
