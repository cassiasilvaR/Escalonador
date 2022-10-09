/*CRIAÇÃO DA ESTRUTURA DAS FILAS DE PROCESSO*/
#include <stdio.h>
#include "process.h"

typedef struct cell {
    int c_pid; //PID do processo atual ou processo inicial/final
    int t_exec; //Tempo restante de execução
    struct cell *next_p; //Endereço do próximo da fila
} cell;