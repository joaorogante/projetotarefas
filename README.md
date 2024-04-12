O Gerenciador de Tarefas tem as seguintes funcionalidades principais:

Criar Tarefas: O usuário pode cadastrar novas tarefas, informando a prioridade (1 a 10), categoria e descrição.
Excluir Tarefas: Quando necessário, o usuário pode selecionar e remover tarefas da lista.
Listar Tarefas: O programa permite visualizar todas as tarefas cadastradas, podendo filtrar por categoria.
Salvar Tarefas: Todas as tarefas são automaticamente salvas em um arquivo binário chamado "tarefas.bin". Ao iniciar o programa, as tarefas são carregadas deste arquivo.
Exportar Tarefas: O usuário pode exportar a lista de tarefas para um arquivo de texto, com cada tarefa em uma linha separada.
As tarefas são armazenadas em um array de estruturas "Tarefa", com campos como prioridade, categoria e descrição.

O programa usa funções implementadas em "tarefas.c" para realizar as operações, declaradas em "tarefas.h". O arquivo "main.c" cuida da interação com o usuário, exibindo o menu e chamando as funções.

Ao sair do programa, as tarefas são automaticamente salvas no arquivo "tarefas.bin".
