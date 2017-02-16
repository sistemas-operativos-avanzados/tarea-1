#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#define printable(ch) (isprint((unsigned char) ch) ? ch : '#')


static void usageError(char *progName, char *msg, int opt) {
    if (msg != NULL && opt != 0) {
        fprintf(stderr, "%s (-%c)\n", msg, printable(opt));
    }
    fprintf(stderr, "Uso: %s [-v prog] [-V prog]\n", progName);
    exit(EXIT_FAILURE);
}

void traceCall(int argc, char *argv[]){

    int initialIndex = 2;
    int i = initialIndex;
    int argumentsIndex = 3;
    int argumentsSize = argumentsIndex + (argc - initialIndex) + 1;
    char *arguments[argumentsSize];

    arguments[0] = "strace"; arguments[1] = "-c"; arguments[2] = "-f";
//    printf("Arg count = %d, i = %d, ArgSize = %d \n", argc, i, argumentsSize);

    while(i < argc){
        arguments[argumentsIndex] = argv[i];
//        printf("AA[%d] %s \n", argumentsIndex, arguments[argumentsIndex]);
        argumentsIndex++;
        i++;
    }
    i++;
    arguments[i] = NULL;

    execvp("strace", arguments);
}

int main(int argc, char *argv[]) {

    int opt;
    while((opt = getopt(argc, argv, "-v:V:")) != EOF) {
        printf("opt =%3d (%c); optind = %d ", opt, printable(opt), optind);
        if (opt == '?' || opt == ':') {
            printf("; optopt =%3d (%c)", optopt, printable(optopt));
        }
        printf("\n");

        switch (opt) {
            case 'v':
                traceCall(argc, argv);
                break;
            case 'V':
                puts("Presione cualquier tecla para continuar...");
                getchar();
                traceCall(argc, argv);
                break;
            case ':':
                usageError(argv[0], "Falta argumento", optopt);
            case '?':
                usageError(argv[0], "Opcion invalida", optopt);
            default:
                exit(EXIT_FAILURE);
        }
    }


    return 0;
}


