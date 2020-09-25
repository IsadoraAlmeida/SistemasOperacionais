/*
    Objetivo:  Implemente um programa que crie N processos, todos filhos do mesmo pai. N é um valor fornecido pelo
usuário. Todos os processos devem imprimir seu PID e PPID.
/*

#include <stdio.h>
#include <unistd.h>

int main() {

    int n, i;
    pid_t pid;

    printf("\nInsira o numero de processos filhos: ");
    scanf("%d", &n);
    printf("\n\n");

    printf("                [Parent]          [Sons]\n");

    for (i = 0; i < n; i++) {  
        pid = fork();
        
        if (pid < 0) {
            printf("ERRO\n");
            return 1;
        } else if (pid == 0) { 
            printf("Processo [%d] -> ppid: %d    |   pid: %d\n", i+1, getppid(), getpid());
            return 0; 
        } else {
            wait(NULL);
        }
    }	

    printf("\n\n");

}
