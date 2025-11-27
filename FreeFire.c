#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10

// ------------------------------------------------------
// STRUCT Item: representa cada objeto da mochila
// ------------------------------------------------------
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Vetor de itens (mochila do jogador)
Item mochila[MAX_ITENS];
int totalItens = 0;

// ------------------------------------------------------
// Função: inserirItem()
// Cadastra um novo item na mochila
// ------------------------------------------------------
void inserirItem() {
    if (totalItens >= MAX_ITENS) {
        printf("\n❌ Mochila cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    Item novo;

    printf("\nDigite o nome do item: ");
    scanf("%s", novo.nome);

    printf("Digite o tipo (arma, municao, cura, etc): ");
    scanf("%s", novo.tipo);

    printf("Digite a quantidade: ");
    scanf("%d", &novo.quantidade);

    mochila[totalItens] = novo;
    totalItens++;

    printf("\n✅ Item adicionado com sucesso!\n");
}

// ------------------------------------------------------
// Função: removerItem()
// Remove um item pelo nome
// ------------------------------------------------------
void removerItem() {
    if (totalItens == 0) {
        printf("\n❌ Mochila vazia! Nada para remover.\n");
        return;
    }

    char nomeRemover[30];
    printf("\nDigite o nome do item a remover: ");
    scanf("%s", nomeRemover);

    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeRemover) == 0) {

            // desloca itens para preencher o espaço
            for (int j = i; j < totalItens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }

            totalItens--;
            printf("\n🗑️ Item removido com sucesso!\n");
            return;
        }
    }

    printf("\n❌ Item não encontrado.\n");
}

// ------------------------------------------------------
// Função: listarItens()
// Mostra todos os itens cadastrados
// ------------------------------------------------------
void listarItens() {
    printf("\n===== ITENS NA MOCHILA =====\n");

    if (totalItens == 0) {
        printf("A mochila está vazia.\n");
        return;
    }

    for (int i = 0; i < totalItens; i++) {
        printf("\nItem %d:\n", i + 1);
        printf("Nome: %s\n", mochila[i].nome);
        printf("Tipo: %s\n", mochila[i].tipo);
        printf("Quantidade: %d\n", mochila[i].quantidade);
    }

    printf("\n============================\n");
}

// ------------------------------------------------------
// Função: buscarItem()
// Busca sequencial por nome
// ------------------------------------------------------
void buscarItem() {
    char nomeBusca[30];
    printf("\nDigite o nome do item para buscar: ");
    scanf("%s", nomeBusca);

    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("\n🔍 Item encontrado!\n");
            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);
            return;
        }
    }

    printf("\n❌ Item não encontrado.\n");
}

// ------------------------------------------------------
// Função principal
// ------------------------------------------------------
int main() {
    int opcao;

    do {
        printf("\n============================");
        printf("\n   MOCHILA DO JOGADOR");
        printf("\n============================\n");
        printf("1 - Adicionar item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirItem();
                listarItens();
                break;
            case 2:
                removerItem();
                listarItens();
                break;
            case 3:
                listarItens();
                break;
            case 4:
                buscarItem();
                break;
            case 0:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\n❌ Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}