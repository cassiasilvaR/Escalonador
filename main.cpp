#include <stdlib.h>
#include <string.h>
#include "queue.h"

void insere_processo(process p1, process* &l_process);
void insere_fila(process *l_process, cell *fim_fila);
int main(int argc, char **argv){

    //Filas de prioridade com início e fim
    //cell *i_f0, *f_f0;

    //Lista de processos 
    process *l_process = NULL;
    //Processo p que vai ser utilizado na leitura
    process p; 
    
    //Variáveis de leitura das linhas
    int n_process;

    //Início e fim da fila sem processos
    //i_f0 = NULL, f_f0 = NULL;
       
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
		printf("\nArquivo texto de entrada não encontrado\n") ;
		exit(1) ;
	}

    //Lê quantidade de processos
    fscanf(arq_entrada, "%d", &n_process);
    
    //Lê cada processo
    for(int i = 0; i < n_process; i++){
        fscanf(arq_entrada, "%d %d %d", &p.pid, &p.fila, &p.status);
        insere_processo(p, l_process);
    }
        
    /* Imprimindo lista de processos....
    process *aux;
    for (aux = l_process; aux != NULL; aux = aux->next_p)
        printf("%d %d %d\n", aux->pid, aux->fila, aux->status);
    */
    return 0;
}

//Insere um novo processo na lista de processos
void insere_processo(process p1, process* &l_process){
    process *novo, *p;

    novo = (process*) malloc(sizeof(process));
    novo->pid = p1.pid;
    novo->fila = p1.fila;
    novo->status = p1.status;
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