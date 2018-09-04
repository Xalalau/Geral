#include "geral.h"

void geral_erro(void) {
  // Imprime mensagens de erro

  perror("\nErro no programa");
  printf("Aperte qualquer tecla para continuar...\n\n");
  PAUSA;
}

void geral_pausar(void) {
  // Uma pausa para ver as mensagens no terminal

  if (strcmp(SISTEMA,"Linux") == 0)
    printf("\nAperte \"Enter\" para continuar...\n");
  PAUSA;  
}

int geral_pegarPastaCorrente(char dir_base[]) {
  // Define o diretorio base como o corrente
  // 1 = Conseguiu pegar o diretorio, 2 = Nao conseguiu pegar o diretorio

  if (strcmp(SISTEMA,"Linux") == 0) {
    int i = 0;

    if (readlink("/proc/self/exe", dir_base, MAX_CHAR_DIR) == -1)
      return 2;
    else {
      i = strlen(dir_base);
      while(dir_base[i] != BARRA2)
        i--;
      dir_base[i] = '\0';
    }
  } else if (strcmp(SISTEMA,"Windows") == 0) {
    if (!GetCurrentDir(dir_base, MAX_CHAR_DIR))
      return 2;
  }
  strcat(dir_base, BARRA);
  return 1;  
}

int geral_verificarExistencia(char arquivo[]) {
  // Verifica a exitencia de arquivos
  // 1 = Pasta ou arquivo existe, 2 = Nao existe

  if (strcmp(SISTEMA,"Linux") == 0) {
    struct stat st;
    if(stat(arquivo, &st) == 0)
      return 1;
  } else if (strcmp(SISTEMA,"Windows") == 0) {
    if (GetFileAttributes(arquivo) != INVALID_FILE_ATTRIBUTES) {
      return 1;
    }
  }
  return 2;
}

int geral_criarPasta(char pasta[], char temp[]) {
  // Cria pastas
  // 1 = Deu certo, 2 = Falhou, 3 = Ja existe

  if (geral_verificarExistencia(pasta) == 2) {
    if (strcmp(SISTEMA,"Linux") == 0) {
      strcat(strcat(strcpy(temp, "mkdir -p \""), pasta), "\"");
      if((system(temp)) != -1) {
        return 1;
      }
    } else if (strcmp(SISTEMA,"Windows") == 0) {
      strcat(strcat(strcpy(temp, "@echo off & setlocal enableextensions & md \""), pasta), "\" & endlocal");
      if((system(temp)) != -1) {
        return 1;
      }
    }
    return 2;
  }
  return 3;
}

int geral_existeCharXNoArrayY(char ch, char array[]) {
  // Verifica se existe o char X no array Y
  // 1 = Existe, 2 = Nao existe
  
  int i;

  for (i = 0; array[i] != '\0'; i++) {
    if (array[i] == ch)
      return 1;
  }
  return 0;
}

/*
// Funcao main para testes:
void main(void) {
  char dir_base[MAX_CHAR_DIR];
  int i = 0, c;

  geral_pegarPastaCorrente(dir_base);
  
  printf("%s\n", dir_base);
}
*/
