#ifndef MET_H
#define MET_H

#include <stdbool.h>

struct Usuario{
    char nome[50];
    char email[50];
    char senha[20];
};

struct Produto{
    int codigo;
    char nome[50];
    float preco;
}; struct ProdutoNode* carregarProdutos();

struct UsuarioNode{
    struct Usuario data;
    struct UsuarioNode *next;
};

struct ProdutoNode{
    struct Produto data;
    struct ProdutoNode *next;
};

bool validarEmail(const char *email);
struct ProdutoNode* carregarProdutos();
void cadastrarUsuario(struct UsuarioNode **head, int *totalUsuarios);
void fazerLogin(struct UsuarioNode *head, bool *logado);
void exibirTabelaDeProdutos(struct ProdutoNode *head);
void adicionarProduto(struct ProdutoNode **head, int *totalProdutos);
void removerProduto(struct ProdutoNode **head, int *totalProdutos);
void buscarProdutoPorCodigo(struct ProdutoNode *head); 
void salvarProdutos(struct ProdutoNode *head);

void ordenarProdutos();

#endif 
