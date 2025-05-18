#include <iostream>
#include <vector>
#include "dominios/TUCodigo.hpp"
#include "dominios/TUCPF.hpp"
#include "dominios/TUData.hpp"
#include "dominios/TUDinheiro.hpp"
#include "dominios/TUNome.hpp"
#include "dominios/TUPerfil.hpp"
#include "dominios/TUQuantidade.hpp"
#include "dominios/TUSenha.hpp"

int main() {
    std::vector<std::pair<std::string, int>> testes = {
        {"Código", TUCodigo().run()},
        {"CPF", TUCPF().run()},
        {"Data", TUData().run()},
        {"Dinheiro", TUDinheiro().run()},
        {"Nome", TUNome().run()},
        {"Perfil", TUPerfil().run()},
        {"Quantidade", TUQuantidade().run()},
        {"Senha", TUSenha().run()}
    };

    bool falha = false;
    for (auto &[nome, resultado] : testes) {
        if (resultado != SUCESSO) {
            std::cerr << "[FALHA] " << nome << std::endl;
            falha = true;
        } else {
            std::cout << "[OK] " << nome << std::endl;
        }
    }

    return falha ? 1 : 0;
}