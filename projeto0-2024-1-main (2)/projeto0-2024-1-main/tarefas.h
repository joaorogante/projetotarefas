#ifndef TAREFAS_H
#define TAREFAS_H

#define TOTAL 100
#define MAX_CATEGORY 100
#define MAX_DESCRIPTION 300
#define MAX_FILENAME 100

typedef struct {
    int prioridade;
    char categoria[MAX_CATEGORY];
    char descricao[MAX_DESCRIPTION];
} Tarefa;

typedef enum {OK, MAX_TAREFA, SEM_TAREFAS, NAO_ENCONTRADO, ABRIR, FECHAR, ESCREVER, LER, PRIORIDADE_INVALIDA} ERROS;

ERROS criar(Tarefa tarefas[], int *pos);
ERROS deletar(Tarefa tarefas[], int *pos);
ERROS listar(Tarefa tarefas[], int *pos);
ERROS salvar(Tarefa tarefas[], int *pos, const char *filename);
ERROS carregar(Tarefa tarefas[], int *pos, const char *filename);
ERROS exportar(Tarefa tarefas[], int pos, const char *filename);

#endif
