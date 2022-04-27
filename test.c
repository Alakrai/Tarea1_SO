#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROMPT "#usuario> "

void comandos(char cadena[20])
{
	printf("Comandos ejecutados");
}

int main()
{
	char cadena[20];  
	int i=0, fin=0,  guardaStdout = dup(1), guardaStdin = dup(0), a;
	
	while(fin==0) 
	{
        close(1); // Cierro la salida que tenga, caso de haber guardado algo en un fichero sera el fichero
        dup(guardaStdout); // Asigno la salida estandar, es decir, la consola.
        close(0); // Cierro la salida que tenga, caso de haber guardado algo en un fichero sera el fichero
        dup(guardaStdin); // Asigno la salida estandar, es decir, la consola.
		
		printf(PROMPT); // Imprimimos el prompt
	
		scanf("\n%[^\n]",cadena); // Escaneamos la cadena entera hasta que pulsa enter

		//esto es como el comando close
		if(strcmp(cadena, "exit")==0)//osea a=close
		{
			fin=1;//esto detiene el while y cierra el programa
		} // Comparamos si la cadena es exit, en tal caso sale


		//Desde aqui se definen los Comandos(cadena); //si no es exit, entra en la funcion Comandos
		comandos(cadena);

	}
}
