#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>


char *process;

void handler(int num) {
    char *msg = malloc(100);
    switch (num) {
    case SIGTSTP:
        strcpy(msg, ": I am not going any where!\n");
        break;
    default:
        strcpy(msg, ": You can't terminate me!\n");
        break;
    }
    write(STDOUT_FILENO, process, strlen(process));
    write(STDOUT_FILENO, msg, strlen(msg));
    free(msg);
}

int main(int argc, char **argv) {
    
    argv[0][1] = '\n';
    process = argv[0] + 1;

    int signals[] = { SIGINT, SIGTERM, SIGQUIT, SIGCONT, SIGTSTP, SIGUSR1, SIGUSR2 };
    
    printf("%s: kill me if you can without killing my parent (the shell and the terminal emulator)\n", process);
    
    for (int i = 0; i < 6; i++) {
        signal(signals[i], &handler);
    }
    

    while(1) {
    }

    printf("LDP{TH4NK_Y0U_F0R_TH3_M3RCY_KILLING");
    return 0;
}
