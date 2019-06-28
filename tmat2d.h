#ifndef TMAT2D_H
#define TMAT2D_H

typedef struct tmat2d tmat2d;

tmat2d *cria_matriz(int linhas, int colunas);
void libera_matriz(tmat2d *matriz);
int escreve_elem(tmat2d *m, int i, int j, int elem);
int acessa_elem(tmat2d *m, int i, int j, int *valor);
int preenche_aleatorio(tmat2d *m, int maximo, int minimo);
int soma_matrizes(tmat2d *mat1, tmat2d *mat2, tmat2d *resultado);
int mult_matrizes(tmat2d *mat1, tmat2d *mat2, tmat2d *resultado);
int mult_const(tmat2d *m, int multiplicador, tmat2d *resultado);
int traco_matriz(tmat2d *m, int *traco);
int *soma_linhas(tmat2d *mat1);
int *soma_colunhas(tmat2d *mat1);
void imprime_matriz(tmat2d *matriz);
tmat2d *open_file_txt(char *userparam);
tmat2d *open_file_bin(char *userparam);
void convert_file(char *userparam, char*userparam2, tmat2d *mat);
void save_bin(char*userparam2, tmat2d *mat);
void segment(tmat2d *mat, int valor);
void connected(char *userparam2, tmat2d *mat);
void imprime_arq(int *vet, int nlin, int ncol);
void lab(char *userparam, tmat2d *matriz);
void save_txt(char*userparam2, tmat2d *mat);
#endif
