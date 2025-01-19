#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    char *searchterm;
    FILE *fp;
    if (argc == 1) {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }
    else if (argc == 2){
        searchterm = argv[1];
        fp = stdin;
    }
    else {
        searchterm = argv[1];
        fp = fopen(argv[2],"r");
        // printf("\n-----%s-----\n\n",argv[i]);
        // printf("Hi %s\n",argv[i]);
        if (fp == NULL){
            printf("wgrep: cannot open file\n");
            exit(1);
        }
    }
    char* line;
    __ssize_t nread;
    size_t len = 0;
    while ((nread = getline(&line,&len,fp) != -1)){ //fget can lead to buffer overflow
        // Search for word in line
        if (strstr(line,searchterm)) printf("%s",line);
    }
    //printf("\n");
    fclose(fp);
    exit(0);
}