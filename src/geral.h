/*
 * GERAL v1.3 [04/09/2018]
 * por Xalalau Xubilozo
 * https://github.com/xalalau/Xalateca/tree/master/C/Geral
 * Licença: MIT
 * */

#ifndef GERAL_H
#define GERAL_H
	#define MAX_CHAR_DIR 255
	#define MAX_CHAR_URL 2000

	#if __linux__
		#define PULO "\n"
		#define BARRA "/"
		#define BARRA2 '/'
		#define SISTEMA "Linux"
		#define CLRSCR system("clear")
		#define PAUSA system("read pause")
	#elif _WIN32
		#define PULO "\r\n"
		#define BARRA "\\"
		#define BARRA2 '\\'
		#define SISTEMA "Windows"
		#define CLRSCR system("cls")
		#define PAUSA system("echo. & pause")
	#endif
#endif //GERAL_H

void geral_erro();
void geral_pausar();
int geral_pegarPastaCorrente();
int geral_verificarExistencia(char arquivo[]);
int geral_criarPasta(char pasta[]);
int geral_existeCharXNaStringY(char ch, char array[]);
