#include "geral.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h> /* system() */
#include <sys/stat.h> /* st */
#include <errno.h>

#if __linux__
	#include <unistd.h> /* readlink */
	#include <pwd.h> /* Pegar pasta corrente */
	#define GetFileAttributes(lixo) printf(" ") /* Definicao desbugante de Linux */
	#define INVALID_FILE_ATTRIBUTES 0 /* Definicao desbugante de Linux */
	#define GetCurrentDir getcwd /* Definicao desbugante de Linux (porque ela não funciona como o esperado) */
#elif _WIN32
	#include <direct.h> /* Pegar pasta corrente */
	#include <windows.h> /* CreateDirectory() */
	#define GetCurrentDir _getcwd
	int readlink(char str[], char dir_base[], int valor);
#endif

void geral_erro() {
	/*
	 * Imprime uma mensagem de erro genérica
	 * Nota: eu queria fazer um uso decente dessa função, mas ela está essa coisa genérica e inútil no momento
	 * 
	 */

	perror("\nErro no programa");
	printf("Aperte qualquer tecla para continuar...\n\n");
	PAUSA;
}

void geral_pausar() {
	/*
	 * Uma pausa para ver as mensagens no terminal
	 * 
	 */

	if (strcmp(SISTEMA,"Linux") == 0)
		printf("\nAperte \"Enter\" para continuar...\n");

	PAUSA;
}

int geral_pegarPastaCorrente(char dir_base[]) {
	/*
	 * Retorna o diretório corrente
	 *
	 * ENTRADA:
	 * dir_base = Variável onde será salvo o endereço do diretório corrente
	 *
	 * RETORNO:
	 * 1 = Pasta corrente obtida com sucesso,
	 * 0 = Falha
	 * 
	 */

	if (strcmp(SISTEMA,"Linux") == 0) {
		int i = 0;

		if (readlink("/proc/self/exe", dir_base, MAX_CHAR_DIR) == -1)
			return 0;
		else {
			i = strlen(dir_base);
			while(dir_base[i] != BARRA2)
				i--;
			dir_base[i] = '\0';
		}
	} else if (strcmp(SISTEMA,"Windows") == 0)
		if (!GetCurrentDir(dir_base, MAX_CHAR_DIR))
			return 0;

	strcat(dir_base, BARRA);

	return 1;
}

int geral_verificarExistencia(char arquivo[]) {
	/*
	 * Verifica a exitência de arquivos
	 *
	 * ENTRADA:
	 * arquivo = Caminho do arquivo
	 *
	 * RETORNO:
	 * 1 = Pasta ou arquivo existe,
	 * 0 = Não existe
	 * 
	 */

	if (strcmp(SISTEMA,"Linux") == 0) {
		struct stat st;
		if(stat(arquivo, &st) == 0)
			return 1;
	} else if (strcmp(SISTEMA,"Windows") == 0) {
		if (GetFileAttributes(arquivo) != INVALID_FILE_ATTRIBUTES)
			return 1;
	}

	return 0;
}

int geral_criarPasta(char pasta[]) {
	/*
	 * Cria pastas
	 *
	 * ENTRADA:
	 * pasta = Caminho de pasta
	 *
	 * RETORNO:
	 * 1 = Criou a pasta,
	 * 2 = Falhou,
	 * 3 = Já existe
	 * 
	 */

	char temp[MAX_CHAR_DIR];

	if (geral_verificarExistencia(pasta) == 2) {
		if (strcmp(SISTEMA,"Linux") == 0) {
			strcat(strcat(strcpy(temp, "mkdir -p \""), pasta), "\"");
			if((system(temp)) != -1)
				return 1;
		} else if (strcmp(SISTEMA,"Windows") == 0) {
			strcat(strcat(strcpy(temp, "@echo off & setlocal enableextensions & md \""), pasta), "\" & endlocal");
			if((system(temp)) != -1)
				return 1;
		}

		return 2;
	}

	return 3;
}

int geral_existeCharXNaStringY(char ch, char array[]) {
	/*
	 * Verifica se existe o char X no array Y
	 *
	 * ENTRADA:
	 * ch = Caracter a ser procurado
	 * array[] = Texto onde procuraremos o caracter
	 *
	 * RETORNO:
	 * 1 = Caracter existe,
	 * 0 = Não existe
	 * 
	 */

	int i;

	for (i = 0; array[i] != '\0'; i++)
		if (array[i] == ch)
			return 1;

	return 0;
}
