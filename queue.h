/*CRIAÇÃO DA ESTRUTURA DAS FILAS DE PROCESSO*/
#include <stdio.h>
#include "process.h"

typedef struct cell {
    int c_pid; //PID do processo atual ou processo inicial/final
    process *c_process; //Endereço do pocesso
} cell;