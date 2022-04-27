//---- limpiar pantalla windows o linux -----
#ifdef _WIN32
  #include<windows.h>
#endif  

void limpiarPantalla()
{
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

FILE* crearAbrirArchivo(char ** argv)
{
	//printf("Aqui pondria mi funcion open... si tuviera una funcional!!");
	
	FILE *fp;
	fp  = fopen (argv[2], "w");//creado en la misma carpeta del codigo fuente

	re.turn fp;
}


FILE* editarArchivo(FILE *fp,char *argv)//argv[2] tiene el texto a agregar en fp
{
	int i;
	//FILE *fp;
	//fp  = fopen (argv[2], "w");//creado en la misma carpeta del codigo fuente

	printf("La entrada es %s",argv[2]);
	
	for (i = 0; argv[i]!='\0' ; i++) 
	{
        /* write to file using fputc() function */
        fputc(argv[2], fp);
    }

	return fp;
}

//recibe argv[n] por parametro // " int ret=cuentaLetras(argv[2]); "
int cuentaLetras(char * argv)
{
	int retorno=0;
	int i;
	
	//printf("\n%s\n", argv);

	for(i=0; argv[i]!='\0'; i++)
	{
		//printf("%c", argv[i]);
		retorno++;
	}
	
	return retorno;
}
