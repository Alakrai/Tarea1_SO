#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PROMPT "usuario@> "

void arte()
{
	printf("                                    _._                                           \n");
	printf("                               _.-=\\\"_-       _                                   \n");
	printf("                          _.-=\"   _-          | ||\"\"\"\"\"\"\"---._______     __..       \n");
	printf("              ___.===\"\"\"\"-.______-,,,,,,,,,,,,`-''----\" \"\"\"\"\"      \"\"\"\"\"  __'      \n");
	printf("       __.--\"\"   __     ,'                 o \\         __       [__|       \n");
	printf("  __-\"\"=======.--\"\"  \"\"--.=================================.--\"\"  \"\"--.=======:   \n");
	printf(" ]     [w] : /      \\ : |========================|  : /     \\ :  [w] :    \n");
	printf(" V___________:|       |: |========================| :|        |:   _-\"     \n");
	printf("  V__________: \\        / :_|=======================/_____: \\       / :__-\\\"      \n");
	printf("  -----------'  \"\"____\"\"  `-------------------------------'  \"\"____\"\"               \n");
}

void limpiar_pantalla()
{
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

int main()
{
	char cadena[20];  
	char Fin[]="exit";
	int i=0, fin=0, segplano=0, guardaStdout = dup(1), guardaStdin = dup(0);
	while(fin==0) 
	{
        close(1); // Cierro la salida que tenga, caso de haber guardado algo en un fichero sera el fichero
        dup(guardaStdout); // Asigno la salida estandar, es decir, la consola.
        close(0); // Cierro la salida que tenga, caso de haber guardado algo en un fichero sera el fichero
        dup(guardaStdin); // Asigno la salida estandar, es decir, la consola.
		printf(PROMPT); // Imprimimos el prompt
		scanf("\n%[^\n]",cadena); // Escaneamos la cadena entera hasta que pulsa intro
		segplano=0;
		if(strncmp(cadena, Fin, 5)==0)  // Comparamos si la cadena es exit, en tal caso sale 
		{
			fin=1;
		}else 
		if(strncmp(cadena, "arte", 5)==0) //comparamos si la cadena es arte, en tal caso imprime un arte ascii
		{
			arte();
		}else
		if(strncmp(cadena, "clear", 6)==0)
		{
			limpiar_pantalla();
		}else printf("comando no reconocido \n");
	}
}

