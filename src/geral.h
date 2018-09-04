/*
 * GERAL v1.0 [10/06/2016]
 * por Xalalau Xubilozo
 *
 * Licensa: CC BY-NC-SA 4.0
 * http://creativecommons.org/licenses/by-nc-sa/4.0/
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
  #define GetFileAttributes(lixo) printf("Nada") /* Definicao desbugante de Linux */
#elif _WIN32
  #define GetCurrentDir _getcwd
  #define PULO "\r\n"
  #define BARRA "\\"
  #define BARRA2 '\\'
  #define SISTEMA "Windows"
  #define CLRSCR system("cls")
  #define PAUSA system("echo. & pause")
  #define DPADRAO(pw) printf("Nada") /* Definicao desbugante de Windows */
  #define DPADRAO2(pw, homedir) printf("Nada") /* Definicao desbugante de Windows */
#endif

#define MAX_CHAR_DIR 255
#define MAX_CHAR_URL 2000

void geral_erro(void);
void geral_pausar(void);
int geral_pegarPastaCorrente(char dir_base[]);
int geral_verificarExistencia(char arquivo[]);
int geral_criarPasta(char pasta[], char temp[]);
int geral_existeCharXNoArrayY(char ch, char array[]);
