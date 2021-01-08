#include <stdio.h>
#include <stdlib.h> // For exit() function
int main() {
    char *line = NULL;
    FILE *fptr;
    size_t len = 0;
    if ((fptr = fopen("hello.c", "r")) == NULL) {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);
    }

    // reads text until newline is encountered
    while(getline(&line, &len, fptr) != -1){
        printf("%s", line);
    }
    printf("\n");
    fclose(fptr);
    return 0;
}