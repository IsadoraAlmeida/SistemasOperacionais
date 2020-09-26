/*
Objetivo: Implementar um programa que crie uma cadeia de processos N processos (além do pai). A cadeia deve
obedecer a seguinte sequência: 1o processo cria o 2o processo, 2o processo cria o 3o processo, ..., No – 1
processo cria o No processo. Cada processo deve imprimir seu PID e o PID do seu pai (ou PPID). Garanta
que a informação exibida na tela ocorrerá na ordem inversa da criação dos processos, ou seja, inicialmente
aparece as informações do No processo (PID e PPID), depois do No – 1, ..., depois do 2o e por fim do 1o.
/*

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    pid_t parent, pid;
    int n, i;
    int *v_parent, *v_son;
 
    printf("\nInsira o numero de processos: ");
    scanf("%d", &n);

    v_parent = (int *) malloc (n * sizeof(int));
    v_son = (int *) malloc (n * sizeof(int));

    for (i = 0; i <n; i++) {
        parent = getpid();
        pid = fork();

        if (pid < 0) {
            printf("ERRO\n");
            return 1;
        } else if (pid == 0) {
            v_parent[i] = parent;
            v_son[i] = getpid();
        } else {
            return 0;
        }
    }

    printf("\n\n");

    for (i = n-1; i >= 0; i--) {
        printf("Processo [%d] -> Parent-ppid: %d    |   Son-pid: %d\n", i+1, v_parent[i], v_son[i]);
    }

    return 0;

}
