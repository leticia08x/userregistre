#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>

#define MAX_USUARIOS 5
#define TAM_NOME 100

typedef struct {
    char nome[TAM_NOME];
    int idade;
} Usuario;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastrarUsuario(Usuario usuarios[], int *totalUsuarios) {
    if (*totalUsuarios >= MAX_USUARIOS) {
        printf("\n⚠️  Limite máximo de %d usuários atingido!\n", MAX_USUARIOS);
        printf("Não é possível cadastrar mais usuários.\n");
        return;
    }
    
    printf("\n--- CADASTRAR NOVO USUÁRIO ---\n");
    
    printf("Digite o nome: ");
    fgets(usuarios[*totalUsuarios].nome, TAM_NOME, stdin);
    usuarios[*totalUsuarios].nome[strcspn(usuarios[*totalUsuarios].nome, "\n")] = 0;
    
    printf("Digite a idade: ");
    scanf("%d", &usuarios[*totalUsuarios].idade);
    limparBuffer();
    
    printf("\n✅ Usuário cadastrado com sucesso!\n");
    printf("Olá, %s! Você tem %d anos.\n", 
           usuarios[*totalUsuarios].nome, 
           usuarios[*totalUsuarios].idade);
    
    (*totalUsuarios)++;
}

void listarUsuarios(Usuario usuarios[], int totalUsuarios) {
    if (totalUsuarios == 0) {
        printf("\n⚠️  Nenhum usuário cadastrado ainda.\n");
        return;
    }
    
    printf("\n--- LISTA DE USUÁRIOS CADASTRADOS ---\n");
    printf("Total: %d usuário(s)\n\n", totalUsuarios);
    
    for (int i = 0; i < totalUsuarios; i++) {
        printf("%d. Nome: %s | Idade: %d anos\n", 
               i + 1, 
               usuarios[i].nome, 
               usuarios[i].idade);
    }
}

void buscarUsuario(Usuario usuarios[], int totalUsuarios) {
    if (totalUsuarios == 0) {
        printf("\n⚠️  Nenhum usuário cadastrado ainda.\n");
        return;
    }
    
    char nomeBusca[TAM_NOME];
    printf("\n--- BUSCAR USUÁRIO ---\n");
    printf("Digite o nome para buscar: ");
    fgets(nomeBusca, TAM_NOME, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = 0;
    
    int encontrado = 0;
    for (int i = 0; i < totalUsuarios; i++) {
        if (strcasecmp(usuarios[i].nome, nomeBusca) == 0) {
            printf("\n✅ Usuário encontrado!\n");
            printf("Nome: %s\n", usuarios[i].nome);
            printf("Idade: %d anos\n", usuarios[i].idade);
            encontrado = 1;
            break;
        }
    }
    
    if (!encontrado) {
        printf("\n⚠️  Usuário '%s' não encontrado.\n", nomeBusca);
    }
}

void exibirMenu() {
    printf("\n");
    printf("╔════════════════════════════════════╗\n");
    printf("║   SISTEMA DE CADASTRO DE USUÁRIOS  ║\n");
    printf("╠════════════════════════════════════╣\n");
    printf("║  1. Cadastrar usuário              ║\n");
    printf("║  2. Listar todos os usuários       ║\n");
    printf("║  3. Buscar usuário por nome        ║\n");
    printf("║  4. Sair                           ║\n");
    printf("╚════════════════════════════════════╝\n");
    printf("Escolha uma opção: ");
}

int main() {
    Usuario usuarios[MAX_USUARIOS];
    int totalUsuarios = 0;
    int opcao;
    
    printf("🧾 BEM-VINDO AO SISTEMA DE CADASTRO DE USUÁRIOS\n");
    printf("═══════════════════════════════════════════════\n");
    
    do {
        exibirMenu();
        scanf("%d", &opcao);
        limparBuffer();
        
        switch (opcao) {
            case 1:
                cadastrarUsuario(usuarios, &totalUsuarios);
                break;
            case 2:
                listarUsuarios(usuarios, totalUsuarios);
                break;
            case 3:
                buscarUsuario(usuarios, totalUsuarios);
                break;
            case 4:
                printf("\n👋 Encerrando o programa...\n");
                printf("Obrigado por usar o sistema!\n\n");
                break;
            default:
                printf("\n❌ Opção inválida! Tente novamente.\n");
        }
        
    } while (opcao != 4);
    
    return 0;
}
