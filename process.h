/*CRIAÇÃO DA ESTRUTURA DE UM PROCESSO*/
#include <stdio.h>
#include <stdbool.h>

/*PID, fila atual, estado [0=terminou execução, 1=não terminou execução]*/
typedef struct process { 
    int pid; //ID do processo
    //Por enquanto a fila é um int f0 = 0, f1 = 1, etc. 
    int fila;  //Fila atual do processo
    int status; //Estado de execução
    int t_exec; //Tempo necessário de CPU
    struct process *next_p; //Próximo proceso da lista de processos
} process;