//Falcari
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int N;
    printf("Inserisci numero di processi da creare: ");
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("Errore nella fork");
            exit(1);
        }

        if (pid == 0) {
            //processo figlio
            printf("Processo figlio %d | PID: %d | PPID: %d\n",
                   i, getpid(), getppid());
            exit(0); //evita altri processi da aprte del figlio
        }
    }

    //padre, attende figli
    for (int i = 0; i < N; i++) {
        wait(NULL);
    }

    return 0;
}