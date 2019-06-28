/**
* @file main.c
* @brief Menu para chamar todas as funcionalidades do programa
*
* Trabalho Final de ED1
* @author Gabriel Oliveira Souza
* @author Leonardo Marinho de Melo Júnior
* @author Vinícius Lopes Dias
* @date 15/06/2019
* @bugs Nenhum atualmente.
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tmat2d.h"

int whichparam(char *userparam);
int main(int argc, char *argv[])
{
    tmat2d *mat;
	if(argc < 3){
        printf("ERROR: Não passou as operações que devem ser feitas\n");
        exit(1);
        }else{
        	    int resp;
        	    char *rettt, txt[] = ".txt", imm[] = ".imm";
            	int result = whichparam(argv[1]);
            	switch(result){
			case 0: rettt = strstr(argv[2], txt);
                    if(rettt)
                       resp = 0;// txt case
                    else {
                        rettt = strstr(argv[2], imm);
                        if(rettt)
                            resp = 1; // bin case
                        else{
                            printf("ERROR: Arquivo desconhecido(Não segue o padrão de uso)\n");
                            exit(1);
                        }
                    }
                    if(resp == 0){
			            mat = open_file_txt(argv[2]);
						imprime_matriz(mat);
						libera_matriz(mat);}
			        else{
			        	mat = open_file_bin(argv[2]);
						imprime_matriz(mat);
						libera_matriz(mat);}
				    break;
			case 1: mat = open_file_txt(argv[2]);
					convert_file(argv[2], argv[3], mat);
					imprime_matriz(mat);
					libera_matriz(mat);
				    break;
			case 2: mat = open_file_bin(argv[3]);
					segment(mat, atoi(argv[2]));
					save_bin(argv[4], mat);
					libera_matriz(mat);
				    break;
			case 3: mat = open_file_bin(argv[2]);
					connected(argv[3], mat);
					libera_matriz(mat);
				    break;
			case 4: mat = open_file_txt(argv[2]);
					lab(argv[3], mat);
					libera_matriz(mat);
				    break;
			default: printf("ERROR: %s nao eh uma opçao valida\n",argv[1]);
				 exit(1);
		}
	}
    return 0;
}
/**
* @brief função que define qual foi o parâmetro passado pelo usuário.
*/
int whichparam(char *userparam){
    char *param[] = {"-open", "-convert", "-segment", "-cc", "-lab"};
    int i = 0;
    for(; i < 5;i++)
    	if(strcmp(userparam, param[i])== 0) return i;
    return -1;
}
