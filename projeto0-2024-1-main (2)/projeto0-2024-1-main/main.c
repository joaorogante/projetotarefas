#include <stdio.h>
#include "tarefas.h"

int main() {
    Tarefa tarefas[TOTAL];
    int pos = 0;
    ERROS erro;

    erro = carregar(tarefas, &pos, "tarefas.bin");
    if (erro != OK) {
        printf("Erro ao carregar tarefas: %d\n", erro);
        pos = 0;
    }

    int opcao;
    do {
        printf("\nMENU\n");
        printf("1. Criar tarefa\n");
        printf("2. Deletar tarefa\n");
        printf("3. Listar tarefas\n");
        printf("4. Salvar tarefas\n");
        printf("5. Exportar tarefas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                erro = criar(tarefas, &pos);
                if (erro != OK)
                    printf("Erro ao criar tarefa: %d\n", erro);
                break;
            case 2:
                erro = deletar(tarefas, &pos);
                if (erro != OK)
                    printf("Erro ao deletar tarefa: %d\n", erro);
                break;
            case 3:
                erro = listar(tarefas, &pos);
                if (erro != OK)
                    printf("Erro ao listar tarefas: %d\n", erro);
                break;
            case 4:
                erro = salvar(tarefas, &pos, "tarefas.bin");
                if (erro != OK)
                    printf("Erro ao salvar tarefas: %d\n", erro);
                break;
            case 5:
                {
                    char filename[MAX_FILENAME];
                    printf("Informe o nome do arquivo de exportação: ");
                    scanf(" %[^\n]s", filename);
                    erro = exportar(tarefas, pos, filename);
                    if (erro != OK)
                        printf("Erro ao exportar tarefas: %d\n", erro);
                }
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != 0);

    erro = salvar(tarefas, &pos, "tarefas.bin");
    if (erro != OK)
        printf("Erro ao salvar tarefas: %d\n", erro);

    return 0;
}
