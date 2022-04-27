#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcionesDeDiego.h"

//Este ocupa write, read, open y close


//Prueba de argumentos

int main (int numArg, char ** argv)	//  argv[0] = nombre programa    argv[1] = primer argumento
{
	int ret; //retorno, variable auxiliar que recibe valores entregados por strcmp
	FILE *fp;//archivo FILE que usaremos para manejar archivos
		
	//--------------------- primeras pruebas -----------------------------------
	if(1==0)//1 == 1 encendido     1==0 (o cualquier cosa) apagado
	{
		int result,n;
		
		printf("\nEjecutando pruebas.c \n");
		
		printf("\nLista de parametros ingresados: \n");
		for ( n = 0; n < numArg; n++)
		{
	       printf("%2d) %s\n", n, argv[n]);
		}
	}	
	
	// --------------------- Comando clear ---------------------------------
	ret = strcmp(argv[1],"clear");		//Comparamos a ver si el argumento argv[1] = "clear"
	
	if(ret==0)//aplicar clear aqui
	{		
		limpiarPantalla();				//Esto esta en funcionesDeDiego.h   Ocupa cls o clear dependiendo del SO
		//printf("(clear aplicado exitosamente)\n\n");	
	}else{/*printf("\nno se pudo aplicar clear\n");*/}
	
	// --------------------- Crear/abrir archivo ---------------------------------

	ret = strcmp(argv[1],"open");		//Comparamos a ver si el argv[1] = "open"
	
	if(ret==0)
	{
		printf("El nombre del archivo creado sera %s",argv[2]);		// "argv[2] = nombreArchivo.txt"
		
		fp = crearAbrirArchivo(argv);	//Esto esta en funcionesDeDiego.h
		
		//printf("(open aplicado exitosamente)\n\n");	
	}else{/*printf("\nno se pudo aplicar open\n");*/}
	
	// --------------------- Editar archivo ---------------------------------

	ret = strcmp(argv[1],"add");		//Comparamos a ver si el argv[1] = "add"
	//printf("%s",argv[2]);
	//la entrada dedeberia ser argv[2]
	
	char entrada[] = "Guru99 Rocks\n";
	
	if(ret==0)
	{
		//printf("El ingresado sera '%s'",argv[2]);
		
		ret=cuentaLetras(argv[2]);
		
		printf("\nNro letras %i", ret);
		
		fp = editarArchivo(fp,argv);
		
		//printf("(add aplicado)\n\n");	
	}else{/*printf("\nno se pudo aplicar add\n");*/}

	
	// --------------------- Imprimir archivo ---------------------------------
	
	return 0;
}
