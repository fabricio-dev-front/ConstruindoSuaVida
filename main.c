#include "construindo.h"
#include <stdio.h>

#define MAX_USUARIOS 10

int main()
{
    struct UsuarioNode *usuarios = NULL;
    int totalUsuarios = 0;
    bool logado = false;

    struct ProdutoNode *produtos = carregarProdutos();
    int totalProdutos = 0;

    int opcao;
    do
    {
        printf("\n=== MENU DE USUARIO ===\n");
        printf("1. Cadastrar usuario\n");
        printf("2. Fazer login\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrarUsuario(&usuarios, &totalUsuarios);
            break;
        case 2:
            fazerLogin(usuarios, &logado);
            break;
        case 3:
            printf("Saindo...\n");
            return 0;
        }
    } while (!logado);

    do
    {
        printf("\n=== MENU DE PRODUTOS ===\n");
        printf("1. Exibir tabela de produtos\n");
        printf("2. Adicionar produto\n");
        printf("3. Remover produto\n");
        printf("4. Buscar produto por codigo\n");
        printf("5. Salvar produtos\n");
        printf("6. Ordenar produtos\n");
        printf("7. Sair\n");
        printf("---------------------------------------------------------------\n");
        printf("ANTES DE SAIR, ORDENE O ARQUIVO NA OPCAO 6 (Ordenar produtos)\n");
        printf("---------------------------------------------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            exibirTabelaDeProdutos(produtos);
            break;
        case 2:
            adicionarProduto(&produtos, &totalProdutos);
            break;
        case 3:
            removerProduto(&produtos, &totalProdutos);
            break;
        case 4:
            buscarProdutoPorCodigo(produtos);
            break;
        case 5:
            salvarProdutos(produtos);
            printf("Produtos salvos com sucesso!\n");
            break;
        case 6:
            ordenarProdutos(&produtos);
            printf("Produtos ordenados com sucesso!\n");
            break;
        case 7:
            printf("saindo...\n");
            logado = 0;
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (logado);

    return 0;
}