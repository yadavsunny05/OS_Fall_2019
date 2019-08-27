#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char *argv[]){
    int i;
    if(argc <=1){
        printf("wgrep: searchterm [file ...]\n");
	exit(1);}
    int BS = 4096;
    char buffer[BS];
    if(argc == 2){
        while(fgets(buffer, BS, stdin) != NULL){
        if(strstr(buffer,argv[1])!=NULL){
            printf("%s",buffer);
        }
    }
        return(0);
    }
    for (i = 2; i < argc; i++) {
    FILE *fp = fopen(argv[i], "r");
    if (fp == NULL) {
        printf("wgrep: cannot open file\n");
        exit(1);}

    while(fgets(buffer, BS, fp) != NULL){
        if(strstr(buffer,argv[1])!=NULL){
            printf("%s",buffer);
        }
    }

    fclose(fp);
    }

    return 0;
}
