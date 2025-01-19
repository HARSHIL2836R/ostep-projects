#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    for(int i = 0; argv[i] ;i++){
        if (i == 0) continue;
        FILE *fp = fopen(argv[i],"r");
        // printf("\n-----%s-----\n\n",argv[i]);
        // printf("Hi %s\n",argv[i]);
        if (fp == NULL){
            printf("wcat: cannot open file\n");
            exit(1);
        }
        char buff[100];
        while (fgets(buff,sizeof(buff),fp)){ //fget can lead to buffer overflow
            printf("%s",buff);
        }
        // printf("\n");
        fclose(fp);
    }
    exit(0);
}