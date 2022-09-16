/*CRIAÇÃO DA ESTRUTURA DE UM PROCESSO*/
#include <stdio.h>
#include <stdbool.h>

/*PID, fila atual, estado [0=terminou execução, 1=não terminou execução]*/
typedef struct Processes { 
    int pid; //ID do processo
    //Por enquanto a fila é um int f0 = 0, f1 = 1, etc. 
    int q;  //Fila atual do processo
    bool status; //Estado de execução
} process;