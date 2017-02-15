#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#define printable(ch) (isprint((unsigned char) ch) ? ch : '#')


void usage(int i){
    fprintf(stderr, "Uso: %d [-v] [-V] \n", i);
}

int main(int argc, char *argv[]) {

    int opt;
    while((opt = getopt(argc, argv, "-vV")) != EOF) {
;
        printf("opt =%3d (%c); optind = %d ", opt, printable(opt), optind);
        if (opt == '?' || opt == ':')
            printf("; optopt =%3d (%c)", optopt, printable(optopt));
        printf("\n");


        switch (opt) {
            case 'v':
                printf("Mensaje de system call \n");
                //TODO
                break;
            case 'V':
                puts("Presione cualquier tecla para continuar...");
                getchar();
                break;
            case ':':
                fprintf(stderr, "Uso: %s [-v] [-V] \n", argv[0]);
                exit(EXIT_FAILURE);
            case '?':
                usage(22);
                exit(EXIT_FAILURE);
            default:
                exit(EXIT_FAILURE);
        }
    }


    return 0;
}


