#include <stdio.h>
#include <string.h>
#define MAX_ALUNOS 50

typedef struct {
    char nome[50], sobrenome[50], curso[10], email[100], cpf[11], ra[9];
    int ativo;
} Aluno;

Aluno alunos[MAX_ALUNOS];

void menu();
void cadastrar();
void remover();
void pesquisar();
void listar();

int main(int argt, char const *argv[]) {
    menu();
    return 0;
}

void menu() {
    system("clear");
    int op;
    do {
        system("SISTEMA CADASTRO\\n");
        printf("1- cadastrar aluno\\n2- remover aluno\\n3- pesquisar aluno\\n4- Listar alunos\\n0- sair\\n");
        scanf("%d", &op);
        getchar();
        switch (op) {
            case 1:
                cadastrar();
                break;
            case 2:
                remover();
                break;
            case 3:
                pesquisar();
                break;
            case 4:
                listar();
                break;
        }
        getchar();
    } while (op != 0);
}

void cadastrar() {
    char nome[50], sobrenome[50], curso[10], email[100], cpf[12], ra[9];
    int op;
    do {
        system("clear");
        printf("CADASTRAR NOVO ALUNO\\n");
        printf("Nome: ");
        fgets(nome, sizeof(nome), stdin);
        printf("Sobrenome: ");
        fgets(sobrenome, sizeof(sobrenome), stdin);
        printf("RA: ");
        fgets(ra, sizeof(ra), stdin);
        printf("Email: ");
        fgets(email, sizeof(email), stdin);
        printf("Curso: ");
        fgets(curso, sizeof(curso), stdin);
        printf("CPF: ");
        fgets(cpf, sizeof(cpf), stdin);
        printf("\\n1 - continuar\\n0 - sair\\n");
        for (int i = 0; i < MAX_ALUNOS; ++i) {
            if (alunos[i].ativo == 0) {
                strcpy(alunos[i].nome, nome);
                strcpy(alunos[i].sobrenome, sobrenome);
                strcpy(alunos[i].ra, ra);
                strcpy(alunos[i].email, email);
                strcpy(alunos[i].curso, curso);
                strcpy(alunos[i].cpf, cpf);
                alunos[i].ativo = 1;
                break;
            }
        }
        scanf("%d", &op);
        getchar();
    } while (op != 0);
}

void remover() {
    // Implementar função de remover aluno
}

void pesquisar() {
    system("clear");
    char nome[50];
    printf("Digite o nome do aluno para pesquisar: ");
    fgets(nome, sizeof(nome), stdin);
    for (int i = 0; i < MAX_ALUNOS; ++i) {
        if (strstr(alunos[i].nome, nome) != NULL) {
            printf("\\nNome: %s", alunos[i].nome);
            printf("\\nSobrenome: %s", alunos[i].sobrenome);
            printf("\\nRA: %s", alunos[i].ra);
            printf("\\nEmail: %s", alunos[i].email);
            printf("\\nCurso: %s", alunos[i].curso);
            printf("\\nCPF: %s", alunos[i].cpf);
            printf("\\n-------------------------\\n");
        }
    }
}

void listar() {
    system("clear");
    printf("LISTA DE ALUNOS\\n");
    for (int i = 0; i < MAX_ALUNOS; i++) {
        if (alunos[i].ativo == 1) {
            printf("---------------------------\\n");
            printf("\\nNome: %s", alunos[i].nome);
            printf("\\nSobrenome: %s", alunos[i].sobrenome);
            printf("\\nRA: %s", alunos[i].ra);
            printf("\\nEmail: %s", alunos[i].email);
            printf("\\nCurso: %s", alunos[i].curso);
            printf("\\nCPF: %s", alunos[i].cpf);
            printf("\\n-------------------------\\n");
        }
    }
}
