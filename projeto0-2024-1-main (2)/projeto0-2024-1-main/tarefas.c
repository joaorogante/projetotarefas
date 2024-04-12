#include <stdio.h>
#include <string.h>
#include "tarefas.h"

ERROS criar(Tarefa tarefas[], int *pos) {
    
    if (*pos >= TOTAL)
        return MAX_TAREFA;

    printf("Entre com a prioridade (1-10): ");
    scanf("%d", &tarefas[*pos].prioridade);
    if (tarefas[*pos].prioridade < 1 || tarefas[*pos].prioridade > 10) {
        printf("Prioridade deve estar entre 1 e 10.\n");
        return PRIORIDADE_INVALIDA;
    }

    printf("Entre com a categoria: ");
    fgets(tarefas[*pos].categoria, MAX_CATEGORY, stdin);
    tarefas[*pos].categoria[strcspn(tarefas[*pos].categoria, "\n")] = '\0'; 

    printf("Entre com a descrição: ");
    fgets(tarefas[*pos].descricao, MAX_DESCRIPTION, stdin);
    tarefas[*pos].descricao[strcspn(tarefas[*pos].descricao, "\n")] = '\0'; 
    (*pos)++; 
    return OK;
}


ERROS deletar(Tarefa tarefas[], int *pos) {
    
    if (*pos == 0)
        return SEM_TAREFAS;

    int pos_deletar;
    printf("Entre com a posição da tarefa a ser deletada: ");
    scanf("%d", &pos_deletar);
    pos_deletar--; 

   
    if (pos_deletar >= *pos || pos_deletar < 0)
        return NAO_ENCONTRADO;

    
    for (int i = pos_deletar; i < *pos - 1; i++) {
        tarefas[i] = tarefas[i + 1];
    }

    (*pos)--; 
    return OK;
}

ERROS listar(Tarefa tarefas[], int *pos) {
    
    if (*pos == 0)
        return SEM_TAREFAS;

    char categoria[MAX_CATEGORY];
    printf("Informe a categoria (deixe vazio para listar todas): ");
    fgets(categoria, MAX_CATEGORY, stdin);
    categoria[strcspn(categoria, "\n")] = '\0'; 

    int count = 0;
    printf("Tarefas:\n");
    for (int i = 0; i < *pos; i++) {
        if (strcmp(categoria, "") == 0 || strcmp(categoria, tarefas[i].categoria) == 0) {
            printf("Pos: %d, Prioridade: %d, Categoria: %s, Descrição: %s\n",
                   i + 1, tarefas[i].prioridade, tarefas[i].categoria, tarefas[i].descricao);
            count++;
        }
    }

    if (count == 0)
        printf("Nenhuma tarefa encontrada na categoria informada.\n");

    return OK;
}

ERROS salvar(Tarefa tarefas[], int *pos){
    FILE *f = fopen("tarefas.bin", "wb");
    if(f == NULL)
        return ABRIR;

    int qtd = fwrite(tarefas, TOTAL, sizeof(Tarefa), f);
    if(qtd == 0)
        return ESCREVER;

    qtd = fwrite(pos, 1, sizeof(int), f);
    if(qtd == 0)
        return ESCREVER;

    if(fclose(f))
        return FECHAR;

    return OK;
}

ERROS carregar(Tarefa tarefas[], int *pos){
    FILE *f = fopen("tarefas.bin", "rb");
    if(f == NULL)
        return ABRIR;

    int qtd = fread(tarefas, TOTAL, sizeof(Tarefa), f);
    if(qtd == 0)
        return LER;

    qtd = fread(pos, 1, sizeof(int), f);
    if(qtd == 0)
        return LER;

    if(fclose(f))
        return FECHAR;

    return OK;

}

void clearBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
