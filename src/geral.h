/*
 * GERAL v1.2 [28/09/2017]
 * por Xalalau Xubilozo
 * https://github.com/xalalau/Xalateca/tree/master/C/Geral
 * Licença: MIT
 * */

#ifndef HEADER_FILE
#define HEADER_FILE
  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h> /* system() */
  #include <sys/stat.h> /* st */
  #include <errno.h>
  #if __linux__
    #include <unistd.h> /* readlink */
    #include <pwd.h> /* Pegar pasta corrente */
  #elif _WIN32
    #include <direct.h> /* Pegar pasta corrente */
    #include <windows.h> /* CreateDirectory() */
  #endif
#endif

#if __linux__
  #define GetCurrentDir getcwd /* Definicao desbugante de Linux (pq ela não funciona como o esperado) */
  #define PULO "\n"
  #define BARRA "/"
  #define BARRA2 '/'
  #define SISTEMA "Linux"
  #define CLRSCR system("clear")
  #define PAUSA system("read pause")
  #define INVALID_FILE_ATTRIBUTES 0 /* Definicao desbugante de Linux */
  #define DPADRAO(pw) pw = getpwuid(getuid())
  #define DPADRAO2(pw, homedir) homedir = pw->pw_dir
  #define GetFileAttributes(lixo) printf(" ") /* Definicao desbugante de Linux */
#elif _WIN32
  #define GetCurrentDir _getcwd
  #define PULO "\r\n"
  #define BARRA "\\"
  #define BARRA2 '\\'
  #define SISTEMA "Windows"
  #define CLRSCR system("cls")
  #define PAUSA system("echo. & pause")
  #define DPADRAO(pw) printf(" ") /* Definicao desbugante de Windows */
  #define DPADRAO2(pw, homedir) printf(" ") /* Definicao desbugante de Windows */
  int readlink(char str[], char dir_base[], int valor);
#endif

#define MAX_CHAR_DIR 255
#define MAX_CHAR_URL 2000

void geral_erro();
void geral_pausar();
int geral_pegarPastaCorrente();
int geral_verificarExistencia(char arquivo[]);
int geral_criarPasta(char pasta[]);
int geral_existeCharXNaStringY(char ch, char array[]);
