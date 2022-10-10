#include <stdlib.h>
#include <string.h>
#include "process.h"


void insere_processo(process p1, process* &l_process);
void insere_fila(process p, process* &ini_fila, process* &fim_fila);
void exec_filas(process* &ini_fila, process* &fim_fila, int quantum); //Executa os processos de uma fila


/*********** Declaração de variáveis globais ***************/
process *i_f0, *f_f0, *i_f1, *f_f1, *i_f2, *f_f2, *i_f3, *f_f3;

int main(int argc, char **argv){

    //Lista de processos 
    process *l_process = NULL;

    //Processo p que vai ser utilizado na leitura
    process p; 
    
    //Variavel de leitura das linhas
    int n_process;

    //Inicializando as filas
    i_f0 = NULL; 
    f_f0 = NULL;
    i_f1 = NULL;
    f_f1 = NULL;
    i_f2 = NULL;
    f_f2 = NULL;
    i_f3 = NULL;
    f_f3 = NULL;
       
    char nome_arq_entrada[100];
    FILE *arq_entrada; 

    //Início da leitura do arquivo de entrada
    if(argc != 2) 
    {
        printf("O programa foi executado com argumentos incorretos.\n") ;
        printf("Uso: ./main <nome arquivo entrada>\n") ;
        exit(1) ;
    }

    strcpy(nome_arq_entrada, argv[1]);

    arq_entrada = fopen(nome_arq_entrada, "rt");

    if (arq_entrada == NULL) 
    {
		printf("\nArquivo texto de entrada não encontrado\n");
		exit(1) ;
	}

    //Lê quantidade de processos
    fscanf(arq_entrada, "%d", &n_process);
    
    //Lê cada processo
    for(int i = 0; i < n_process; i++) 
    {
        fscanf(arq_entrada, "%d %d %d %d", &p.pid, &p.fila, &p.status, &p.t_exec);
        
        //Insere o processo na lista de processos
        insere_processo(p, l_process); 
    
        if(p.fila == 0)
            insere_fila(p, i_f0, f_f0); //Insere o processo na fila 0
        else if(p.fila == 1)
            insere_fila(p, i_f1, f_f1); //Insere o processo na fila 1
        else if(p.fila == 2)
            insere_fila(p, i_f2, f_f2); //Insere na o processo fila 2
        else 
            insere_fila(p, i_f3, f_f3); //Insere na o processo fila 3
    }
        
    //Imprimindo lista de processos....
    /*process *aux1;
    for (aux1 = l_process; aux1 != NULL; aux1 = aux1->next_p)
        printf("%d %d %d %d\n", aux1->pid, aux1->fila, aux1->status, aux1->t_exec);
    */
    
    //Imprimindo processos de uma fila
    /*process *fila;
    for(fila = i_f0; fila != NULL; fila = fila->next_p)
        printf("%d %d %d %d\n", fila->pid, fila->fila, fila->status, fila->t_exec);
    */

    //Executa filas de prioridade 
    exec_filas(i_f0, f_f0, 1); // Executa fila 0
    exec_filas(i_f1, f_f1, 2); // Executa fila 1
    exec_filas(i_f2, f_f2, 4); // Executa fila 2
    exec_filas(i_f3, f_f3, 8); // Executa fila 3


    return 0;
}

//Insere um novo processo na lista de processos
void insere_processo(process p1, process* &l_process) 
{
    process *novo, *p;

    novo = (process*) malloc(sizeof(process));
    novo->pid = p1.pid;
    novo->fila = p1.fila;
    novo->status = p1.status;
    novo->t_exec = p1.t_exec;
    novo->next_p = NULL;

    if(l_process == NULL) {
        l_process = novo;
    }
    else{
        p = l_process;
        while(p->next_p != NULL)
            p = p->next_p;

        p->next_p = novo;
    }
}

void insere_fila(process p, process* &ini_fila, process* &fim_fila)
{
    process *novo = (process*) malloc(sizeof(process));

    novo->pid = p.pid;
    novo->fila = p.fila;
    novo->status = p.status;
    novo->t_exec = p.t_exec;
    novo->next_p = NULL; 

	if(ini_fila == NULL)
        ini_fila = novo;
    else
        fim_fila->next_p = novo;
	fim_fila = novo;
}

void exec_filas(process* &ini_fila, process* &fim_fila, int quantum)
{
	//process p;
	process *novo;

	//novo = ini_fila;

    for(novo = ini_fila; novo != NULL; novi = novo->next_p)
    {   
       novo->t_exec -= quantum;
       sleep(quantum);

       if(novo->t_exec <= 0)
       {
            ini_fila = novo->next_p;
            printf("processo de PID: %d concluido\n",novo->pid);
            free(novo);
       }
       else
       {    
            //p = &novo;
            if(quantum == 1)
                insere_fila(novo, i_f1, f_f1);
            else if(quantum == 2)
                insere_fila(novo, i_f2, f_f2);
            else if(quantum == 4)
                insere_fila(novo, i_f3, f_f3);
            else 
                insere_fila(novo, i_f3, f_f3);
       }
    }

	if (ini_fila == NULL)
		fim_fila = NULL;
	
}