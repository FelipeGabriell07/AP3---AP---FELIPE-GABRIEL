#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTES 50

typedef struct {
    int codigo;
    char nome[100];
    char email[100];
    int idade;
} Cliente;

Cliente clientes[MAX_CLIENTES];
int totalClientes = 0;

void exibirMenu();
void adicionarCliente();
void listarClientes();

int main() {
    int opcao;

    do {
        exibirMenu();
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                adicionarCliente();
                break;
            case 2:
                listarClientes();
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

        if (opcao != 0) {
            printf("\nPressione Enter para continuar...");
            getchar();
        }

    } while (opcao != 0);

    return 0;
}

void exibirMenu() {
    system("clear || cls");
    printf("==================================\n");
    printf("      SISTEMA DE CADASTRO\n");
    printf("==================================\n");
    printf("1 - Adicionar Cliente\n");
    printf("2 - Listar Clientes\n");
    printf("0 - Sair\n");
    printf("==================================\n");
    printf("Escolha uma opcao: ");
}

void adicionarCliente() {
    if (totalClientes >= MAX_CLIENTES) {
        printf("Limite de clientes atingido.\n");
        return;
    }

    clientes[totalClientes].codigo = totalClientes + 1;

    printf("Nome: ");
    fgets(clientes[totalClientes].nome, sizeof(clientes[totalClientes].nome), stdin);
    strtok(clientes[totalClientes].nome, "\n");

    printf("Email: ");
    fgets(clientes[totalClientes].email, sizeof(clientes[totalClientes].email), stdin);
    strtok(clientes[totalClientes].email, "\n");

    printf("Idade: ");
    scanf("%d", &clientes[totalClientes].idade);
    getchar();

    totalClientes++;
    printf("Cliente adicionado com sucesso.\n");
}

void listarClientes() {
    if (totalClientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    for (int i = 0; i < totalClientes; i++) {
        printf("-------------------------------\n");
        printf("Codigo: %d\n", clientes[i].codigo);
        printf("Nome: %s\n", clientes[i].nome);
        printf("Email: %s\n", clientes[i].email);
        printf("Idade: %d\n", clientes[i].idade);
    }
    printf("-------------------------------\n");
}
