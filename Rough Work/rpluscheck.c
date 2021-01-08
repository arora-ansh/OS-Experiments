#include <stdio.h>

int main(){
	FILE *fptr;
	char *line = NULL;
	size_t len = 0;
	fptr = fopen("abc.txt","w");
	char var[100] = "This is a line";
	char var2[100] = "This is another line";
	fprintf(fptr, "%s\n", var);
	fprintf(fptr, "%s\n", var2);
	while (getline(&line, &len, fptr) != -1) {
        printf("%s", line);
    }
	fclose(fptr);
	fptr = fopen("abc.txt","r");
	while (getline(&line, &len, fptr) != -1) {
        printf("%s", line);
    }
	fclose(fptr);
	return 0;
}