#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

char **parse_args(char *line){
    int i = 0;
    int totalDelim = 1;
    while(line[i]){
        if (line[i] == ' '){
            totalDelim++;
        }
        i++;
    }
    char **result = malloc(totalDelim * sizeof(char *));
    char *current;
    i = 0;
    while (current = strsep(&line, " \n"))
    {
        if (*current){
            result[i] = current;
            i++;
        }
    }
    result[i] = NULL;
    return result;
}

int main(){
    while(1){
        char line[100] = {0};
        printf("Put an terminal command here...\n");
        read(STDIN_FILENO, line, 100);
        char **args = parse_args(line);
        execvp(args[0], args);
    }
}
