#include <stdio.h>

int sudoku[9][9];
int resolve(int, int);
int verColuna(int coluna, int num) {
	int linha;
	for (linha = 0; linha <= 8; linha++) {
		if (sudoku[linha][coluna] == num){
			return 0;
		}
	}
	return 1;
}

int verLinha(int linha, int num) {
	int coluna;
	for (coluna = 0; coluna <= 8; coluna++) {
		if (sudoku[linha][coluna] == num) {
			return 0;
		}
	}
	
	return 1;
}

int verIndividual(int linha, int coluna, int num) {
	linha = (linha/3)*3;
	coluna = (coluna/3)*3;
	int i, j;
	for (i = 0; i <= 2; i++) {
		for (j = 0; j <= 2; j++) {
			if (sudoku[linha+i][coluna+j] == num) {
				return 0;
			}
		}
	}
	
	return 1;
}

int prox(int linha, int coluna) {
	if (coluna <= 7) {
		resolve(linha, coluna+1);
	} 
	else {
		resolve(linha+1, 0);
	}
	return 0;
}

int montagem(int matriz[9][9]) {
	int linha, coluna;

	for (linha = 0; linha <= 8; linha++) {
		if ( linha == 3 || linha == 6) {
			printf("- - - - - - - - - - -\n");
		}
		for (coluna = 0; coluna <= 8; coluna++) {
			if (coluna == 8) {
				printf("%d", matriz[linha][coluna]);
			} else {
				printf("%d ", matriz[linha][coluna]); 
			}
			if (coluna == 2 || coluna == 5) {
                printf("| ");
			}
		}
		printf("\n");
	}
	return 0;
}

int resolve(int linha, int coluna) {
	if (sudoku[linha][coluna] != 0) {
		prox(linha, coluna);
	}
	else {
		int contagem;
		for (contagem = 1; contagem <= 9; contagem++) {
			if (( (verColuna(coluna, contagem) == 1) && verLinha(linha, contagem) == 1) && (verIndividual(linha, coluna, contagem) == 1)) {
				sudoku[linha][coluna] = contagem;
				prox(linha, coluna);
			}
		}
		sudoku[linha][coluna] = 0;
	}
	if (linha > 8) {
		montagem(sudoku);
	}
	return 0;
}

int main() {
	char temporario;
	int numero;
	int linha, coluna;
	for (linha = 0; linha <= 8; linha++) {
		for (coluna = 0; coluna <= 8; coluna++) {
			scanf("%c", &temporario);
			if (coluna <= 8) {
			getchar ();
			}
			if (temporario == 'X') {
				sudoku[linha][coluna] = 0;
			} else {
				numero = temporario - '0';	
				sudoku[linha][coluna] = numero;	
			}
		}
	} 

	resolve(0,0);
	return 0;
}