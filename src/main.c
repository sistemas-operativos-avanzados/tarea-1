#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <stdarg.h>

#define printable(ch) (isprint((unsigned char) ch) ? ch : '#')

int enableLog = 0;

static void usageError(char *progName, char *msg, int opt) {
    if (msg != NULL && opt != 0) {
        fprintf(stderr, "%s (-%c)\n", msg, printable(opt));
    }
    fprintf(stderr, "Uso: %s [-v prog] [-V prog]\n", progName);
    exit(EXIT_FAILURE);
}

void logMsg(char *fmt, ...){

    if(enableLog) {
        va_list ap;
        char *p, *sval;
        int ival;
        va_start(ap, fmt);

        for (p = fmt; *p; p++) {
            if (*p != '%') {
                putchar(*p);
                continue;
            }
            switch (*++p) {

                case 'd':
                    ival = va_arg(ap, int);
                    printf("%d", ival);
                    break;
                case 's':
                    for (sval = va_arg(ap, char *); *sval; sval++) {
                        putchar(*sval);
                    }
                    break;
                default:
                    putchar(*p);
                    break;
            }
        }

        va_end(ap);
        printf("\n");
    }
}

void traceCall(int argc, char *argv[]){

    int initialIndex = 2;
    int i = initialIndex;
    int argumentsIndex = 3;
    int argumentsSize = argumentsIndex + (argc - initialIndex) + 1;
    char *arguments[argumentsSize];

    arguments[0] = "strace"; arguments[1] = "-c"; arguments[2] = "-f";
    logMsg("Arg count = %d, i = %d, ArgSize = %d \n", argc, i, argumentsSize);

    while(i < argc){
        //TODO: evitar argumentos -v, -d y -V
//        if(*argv[i] == 'd' || *argv[i] == 'v' || *argv[i] == 'V'){
//            continue;
//        }
        arguments[argumentsIndex] = argv[i];
        logMsg("AA[%d] %s \n", argumentsIndex, arguments[argumentsIndex]);
        argumentsIndex++;
        i++;
    }
    i++;
    arguments[i] = NULL;

    execvp("strace", arguments);
}

int main(int argc, char *argv[]) {


    int opt;
    while((opt = getopt(argc, argv, "-d-v:V")) != EOF) {


        switch (opt) {
            case 'd':
                enableLog = 1;
                logMsg("Log habilitado");
                break;
            case 'v':
                logMsg("-> Llamando a traceCall con -v");
                traceCall(argc, argv);
                break;
            case 'V':
                logMsg("-> Llamando a traceCall con -V");
                puts("Presione cualquier tecla para continuar...");
                getchar();
                traceCall(argc, argv);
                break;
            case ':':
                usageError(argv[0], "Falta argumento", optopt);
            case '?':
                usageError(argv[0], "Opcion invalida", optopt);
            default:
                usageError(argv[0], "Falta argumento", optopt);
        }

        logMsg("opt =%3d (%c); optind = %d", opt, printable(opt), optind);
        if (opt == '?' || opt == ':') {
            logMsg("; optopt =%3d (%c)", optopt, printable(optopt));
        }
    }


    return 0;
}