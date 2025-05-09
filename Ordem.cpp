#include "Ordem.h"

void Ordem::setCodigo(Codigo codigo) {
    this->codigo = codigo;
}

Codigo Ordem::getCodigo() const {
    return codigo;
}

void Ordem::setCodigoNegociacao(CodigoNegociacao codigoNegociacao) {
    this->codigoNegociacao = codigoNegociacao;
}

CodigoNegociacao Ordem::getCodigoNegociacao() const {
    return codigoNegociacao;
}

void Ordem::setData(Data data) {
    this->data = data;
}

Data Ordem::getData() const {
    return data;
}

void Ordem::setPreco(Dinheiro preco) {
    this->preco = preco;
}

Dinheiro Ordem::getPreco() const {
    return preco;
}

void Ordem::setQuantidade(Quantidade quantidade) {
    this->quantidade = quantidade;
}

Quantidade Ordem::getQuantidade() const {
    return quantidade;
}

void Ordem::setCarteira(Carteira* carteira) {
    this->carteira = carteira;
}

Carteira* Ordem::getCarteira() const {
    return carteira;
}
