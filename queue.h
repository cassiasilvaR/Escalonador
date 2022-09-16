/*CRIAÇÃO DA ESTRUTURA DAS FILAS DE PROCESSO*/
#include <stdio.h>
#include "process.h"

typedef struct Cells {
    int *current_pid; //Endereço que armazena o PID do processo
    process *process; //Lista de processos 
    struct cell *next; //Ponteiro para a próxima fila 
} cell;