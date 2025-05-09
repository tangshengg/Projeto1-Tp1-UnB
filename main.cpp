#include <iostream>
#include "Exceptions.h"
#include "Conta.h"
#include "Carteira.h"
#include "Ordem.h"
#include "Dominio.h"

using namespace std;


template<typename T>
void testarDominio(string nomeTeste, T& objeto, string valorValido, string valorInvalido) {
    cout << "\n=== Testando " << nomeTeste << " ===" << endl;


    try {
        objeto.setValor(valorValido);
        cout << "SUCESSO: Valor válido aceito: " << objeto.getValor() << endl;
    } catch (const invalid_argument& e) {
        cout << "ERRO: Valor válido rejeitado: " << e.what() << endl;
    }


    try {
        objeto.setValor(valorInvalido);
        cout << "ERRO: Valor inválido aceito: " << objeto.getValor() << endl;
    } catch (const invalid_argument& e) {
        cout << "SUCESSO: Exceção capturada: " << e.what() << endl;
    }
}


void testarAssociacoes() {
    cout << "\n=== Testando Associações entre Classes ===" << endl;

    try {

        Conta conta;
        Cpf cpf;
        cpf.setValor("529.982.247-25");
        Nome nome;
        nome.setValor("João Silva");
        Senha senha;
        senha.setValor("Ab1#cd");

        conta.setCpf(cpf);
        conta.setNome(nome);
        conta.setSenha(senha);


        Carteira carteira;
        Codigo codigo;
        codigo.setValor("12345");
        Perfil perfil;
        perfil.setValor("Moderado");

        carteira.setCodigo(codigo);
        carteira.setNome(nome);
        carteira.setPerfil(perfil);
        carteira.setConta(&conta);


        Ordem ordem;
        CodigoNegociacao codigoNeg;
        codigoNeg.setValor("PETR4");
        Data data;
        data.setValor("20230415");
        Dinheiro preco;
        preco.setValor("35,50");
        Quantidade qtd;
        qtd.setValor("100");

        ordem.setCodigo(codigo);
        ordem.setCodigoNegociacao(codigoNeg);
        ordem.setData(data);
        ordem.setPreco(preco);
        ordem.setQuantidade(qtd);
        ordem.setCarteira(&carteira);


        carteira.adicionarOrdem(&ordem);

        cout << "SUCESSO: Associações criadas corretamente!" << endl;
        cout << "Conta: " << conta.getNome().getValor() << endl;
        cout << "Carteira: " << carteira.getCodigo().getValor() << ", "
             << carteira.getPerfil().getValor() << endl;
        cout << "Ordem: " << ordem.getCodigoNegociacao().getValor() << ", "
             << ordem.getPreco().getValor() << ", "
             << ordem.getQuantidade().getValor() << endl;
    } catch (const invalid_argument& e) {
        cout << "ERRO durante teste de associações: " << e.what() << endl;
    }
}

int main() {
    cout << "Iniciando testes das classes de domínio..." << endl;


    Codigo codigo;
    testarDominio("Codigo", codigo, "12345", "123");

    CodigoNegociacao codigoNeg;
    testarDominio("CodigoNegociacao", codigoNeg, "PETR4", "PETR4@");

    Cpf cpf;
    testarDominio("CPF", cpf, "529.982.247-25", "111.111.111-11");

    Data data;
    testarDominio("Data", data, "20230415", "20230231");

    Nome nome;
    testarDominio("Nome", nome, "João Silva", "João  Silva");

    Perfil perfil;
    testarDominio("Perfil", perfil, "Moderado", "Cauteloso");

    Dinheiro dinheiro;
    testarDominio("Dinheiro", dinheiro, "35,90", "2000000,00");

    Quantidade quantidade;
    testarDominio("Quantidade", quantidade, "500", "0");

    Senha senha;
    testarDominio("Senha", senha, "Ab1#cd", "123456");


    testarAssociacoes();

    cout << "\nTestes concluídos!" << endl;
    return 0;
}
