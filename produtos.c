#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

#define MAX_PRODUTOS 100
#define TAM_NOME 50

// Estrutura para representar um produto
typedef struct {
    int codigo;
    wchar_t nome[TAM_NOME];
    float preco;
    int quantidade;
} Produto;

// Função para ler os produtos do arquivo CSV
int lerProdutos(Produto produtos[]) {
    FILE *arquivo;
    int i = 0;

    arquivo = fopen("produtos.csv", "r");
    if (arquivo == NULL) {
        wprintf(L"Erro ao abrir o arquivo.\n");
        exit(1);
    }

    while (fwscanf(arquivo, L"%d,%49[^,],%f,%d\n", &produtos[i].codigo, produtos[i].nome, &produtos[i].preco, &produtos[i].quantidade) == 4) {
        i++;
    }

    fclose(arquivo);
    return i;
}

// Função para escrever os produtos no arquivo CSV
void escreverProdutos(Produto produtos[], int numProdutos) {
    FILE *arquivo;

    arquivo = fopen("produtos.csv", "w");
    if (arquivo == NULL) {
        wprintf(L"Erro ao abrir o arquivo.\n");
        exit(1);
    }

    for (int i = 0; i < numProdutos; i++) {
        fwprintf(arquivo, L"%d,%ls,%.2f,%d\n", produtos[i].codigo, produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
    }

    fclose(arquivo);
}

// Função para adicionar um novo produto
void adicionarProduto(Produto produtos[], int *numProdutos) {
    wprintf(L"Digite o código do produto: ");
    scanf("%d", &produtos[*numProdutos].codigo);
    wprintf(L"Digite o nome do produto: ");
    scanf("%ls", produtos[*numProdutos].nome);
    wprintf(L"Digite o preço do produto: ");
    scanf("%f", &produtos[*numProdutos].preco);
    wprintf(L"Digite a quantidade do produto: ");
    scanf("%d", &produtos[*numProdutos].quantidade);

    (*numProdutos)++;
}

// Função para buscar um produto pelo código
int buscarProduto(Produto produtos[], int numProdutos, int codigo) {
    for (int i = 0; i < numProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            return i;
        }
    }
    return -1; // Produto não encontrado
}

// Função para editar um produto
void editarProduto(Produto produtos[], int numProdutos) {
    int codigo, indice;

    wprintf(L"Digite o código do produto a ser editado: ");
    scanf("%d", &codigo);

    indice = buscarProduto(produtos, numProdutos, codigo);

    if (indice != -1) {
        wprintf(L"Digite o novo nome do produto: ");
        scanf("%ls", produtos[indice].nome);
        wprintf(L"Digite o novo preço do produto: ");
        scanf("%f", &produtos[indice].preco);
        wprintf(L"Digite a nova quantidade do produto: ");
        scanf("%d", &produtos[indice].quantidade);
        wprintf(L"Produto editado com sucesso!\n");
    } else {
        wprintf(L"Produto não encontrado.\n");
    }
}

// Função para excluir um produto
void excluirProduto(Produto produtos[], int *numProdutos) {
    int codigo, indice;

    wprintf(L"Digite o código do produto a ser excluído: ");
    scanf("%d", &codigo);

    indice = buscarProduto(produtos, *numProdutos, codigo);

    if (indice != -1) {
        // Substitui o produto pelo último da lista e decrementa o número de produtos
        produtos[indice] = produtos[(*numProdutos) - 1];
        (*numProdutos)--;
        wprintf(L"Produto excluído com sucesso!\n");
    } else {
        wprintf(L"Produto não encontrado.\n");
    }
}

int main() {
    setlocale(LC_ALL, "");  // Configuração para usar a codificação local

    Produto produtos[MAX_PRODUTOS];
    int numProdutos = 0;
    int opcao;

    // Lê os produtos do arquivo CSV
    numProdutos = lerProdutos(produtos);

    do {
        // Menu de opções
        wprintf(L"\nMenu:\n");
        wprintf(L"1. Adicionar Produto\n");
        wprintf(L"2. Editar Produto\n");
        wprintf(L"3. Excluir Produto\n");
        wprintf(L"4. Listar Produtos\n");
        wprintf(L"0. Sair\n");
        wprintf(L"Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarProduto(produtos, &numProdutos);
                break;
            case 2:
                editarProduto(produtos, numProdutos);
                break;
            case 3:
                excluirProduto(produtos, &numProdutos);
                break;
            case 4:
                wprintf(L"\nLista de Produtos:\n");
                for (int i = 0; i < numProdutos; i++) {
                    wprintf(L"Código: %d, Nome: %ls, Preço: %.2f, Quantidade: %d\n", produtos[i].codigo, produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
                }
                break;
            case 0:
                wprintf(L"Saindo...\n");
                break;
            default:
                wprintf(L"Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    // Escreve os produtos de volta no arquivo CSV antes de sair
    escreverProdutos(produtos, numProdutos);

    return 0;
}
