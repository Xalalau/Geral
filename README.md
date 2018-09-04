# Biblioteca geral_*

Funciona no Windows e no Linux.

void **geral_erro** () { }
```
Imprime mensagens de erro
```
void **geral_pausar** () { }
```
Uma pausa para ver as mensagens no terminal
```
void **geral_pegarPastaCorrente** (char dir_base[ ]) { }
```
Retorna o diretório corrente

"RETORNO":

Se dir_base[ ] ficar com um diretório = Sucesso,
Se dir_base[ ] ficar igual = Falhou
```

int **geral_verificarExistencia** (char arquivo[ ]) { }
```
Verifica a exitencia de arquivos

ENTRADA:

arquivo[ ] = Caminho do arquivo
 
RETORNO:

1 = Pasta ou arquivo existe,
2 = Não existe
```
int **geral_criarPasta** (char pasta[ ]) { }
```
Cria pastas

ENTRADA:

pasta[ ] = Caminho de pasta

RETORNO:

1 = Criou a pasta,
2 = Falhou,
3 = Já existe
```
int **geral_existeCharXNaStringY** (char ch, char array[ ]) { }
```
Verifica se existe o char X no array Y

ENTRADA:

ch = Caracter a ser procurado
array[ ] = Texto onde procuraremos o caracter

RETORNO:

1 = Caracter existe,
2 = Não existe
```
