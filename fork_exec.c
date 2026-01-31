#include <stdio.h>
#include <unistd.h>

int main() {
    int f = fork();

    if (f == 0) {
        // Proceso Hijo
        execl("./hola", "hola", (char *)NULL);
    } else {
        // Proceso Padre
        printf("PID del padre antes de execl: %d\n", (int)getpid());
        execl("./hola", "hola", (char *)NULL);
    }
    return 0;
}