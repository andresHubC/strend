#include <stdio.h>
#define MAXLEN 151	/* Longitud de caracteres en la linea s y en la linea t, incluyendo el caracter nulo */
void readline(char line[], int);
int strend(char *, char *); 

int main(void)
{
	char s[MAXLEN], t[MAXLEN];
	printf("El programa busca que la linea de caracteres t se encuentre al final de la linea de caracteres s.\n");
	printf("Las dos lineas de caracteres se solicitan al usuario antes de realizar la busqueda.\n");
	printf("El resultado sera mostrado al usuario despues de finalizar la busqueda.\n\n");
	readline(s, MAXLEN);
	readline(t, MAXLEN);
	if (strend(s, t))
		printf("La linea t:\"%s\" se encuentra al final de la linea s:\"%s\".\n", t, s);
	else
		printf("La linea t:\"%s\" no se encuentra al final de la linea s:\"%s\".\n", t, s);
	return 0;
}

#define LINES 2	     /* Numero de lineas que el programa solicita al usuario */
int getline(char line[], int);

/* readline: Lee las lineas de texto ingresadas y maneja los errores que presenten */
void readline(char line[], int maxlen)
{
	static int i = 0;	/* i es un indice que se usa para acceder a un elemento de linename */
	char *linename[LINES] = {"s", "t"};	 /* linename tiene el nombre de cada linea que solicita el programa */
	int len;      /* len contiene el total de caracteres de la linea de texto obtenida con getline */
	
	do {
		printf("Ingresa la linea %s:", linename[i]);
		len = getline(line, maxlen);
		if (len > maxlen - 1) 	/* Se notifica al usuario que la linea es muy larga para almacenarla */
			printf("La linea %s excede los %d caracteres permitidos.\n\n", linename[i], maxlen - 1);
		else if (len == 0)	/* Se notifica al usuario que no ingreso la linea */
			printf("No se ingreso la linea %s.\n\n", linename[i]);
	}
	while (len == 0 || len > maxlen - 1);
	i++;
}	

/* getline: toma la linea de entrada y la guarda en line, devuelve la longitud de caracteres de la linea */
int getline(char line[], int lim)
{
	/* i contabiliza el total de caracteres. */
	int c, i;			
	
	while ((c = getchar()) == ' ' || c == '\t')		/* El programa omite los espacios en blanco al inicio */
		;
	for (i = 0; c != EOF && c != '\n'; i++) {
		if (i < lim - 1)		/* El programa aparta un espacio en arreglo para el caracter nulo */
			line[i] = c;
		c = getchar();
	}
	if (i < lim)	/* El programa guarda el caracter nulo en la posicion siguiente del ultimo caracter ingresado */
		line[i] = '\0';
	else 
		line[lim - 1] = '\0';
	return i;		
}

#include <string.h>

/* strend: Busca que la linea t se encuentre al final de la linea s. Se retorna 1 en caso positivo y 0 en caso contrario */
int strend(char *s, char *t)
{
	int pos;
	
	pos = strlen(s) - strlen(t);  /* El programa busca la posicion donde es posible que comience la linea t en la linea s */
	if (pos >= 0) {	   /* Si pos es negativo, quiere decir que la linea t es muy larga para estar en la linea s */
		for (s += pos; *t != '\0' && *s == *t; s++, t++)
			;
		if (*t == '\0')
			return 1;
	}
	return 0;
}