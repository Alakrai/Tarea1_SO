#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PROMPT "#@> "

void comandos(){
	
}

int main()
{
	char cadena[20];  
	char Fin[]="exit";
	int i=0, fin=0, segplano=0, guardaStdout = dup(1), guardaStdin = dup(0), a;
	while(fin==0) 
	{
        close(1); // Cierro la salida que tenga, caso de haber guardado algo en un fichero sera el fichero
        dup(guardaStdout); // Asigno la salida estandar, es decir, la consola.
        close(0); // Cierro la salida que tenga, caso de haber guardado algo en un fichero sera el fichero
        dup(guardaStdin); // Asigno la salida estandar, es decir, la consola.
	printf(PROMPT); // Imprimimos el prompt
	scanf("\n%[^\n]",cadena); // Escaneamos la cadena entera hasta que pulsa intro
	segplano=0;
	for(i=0;cadena[i] != '\0'; i++)
	{
		if(cadena[i] == '&') 
		{
			cadena[i] = '\0';
			segplano = 1;
		}
	}
		a=strncmp(cadena, Fin, 5);
		if(a==0)
		{
			fin=1;
		} // Comparamos si la cadena es exit, en tal caso sale
	//Comandos(cadena,segplano); //si no es exit, entra en la funcion Comandos
	}
}
