/*
 ============================================================================
 Name        : Ignacio Javier Medici
 Division	 : C

	1. Realizar una función que reciba como parámetro un número entero.
	La misma deberá retornar la cantidad de divisores del numero que hay entre la unidad (incluida) y el mismo numero (incluido).

	2.Elegir 5 de los siguientes conceptos y armar un párrafo en donde se vea la relación entre los mismos. No se aceptarán definiciones copy-pasteadas.
	(Marcar los conceptos en la lista y entregar el párrafo en el gdb)

 	3. Crear una función que reciba como parámetro una cadena.
 	Dicha función  deberá ordenar alfabéticamente la cadena y LUEGO reemplazar los espacios por un asterisco. Por ej: "el arbol" -> "*abellor".
 	Hardcodear otro ejemplo.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int divisores(int);
void intercambio(char[]);

int main(void) {
	setbuf(stdout,NULL);
	int numero;
	int contadorDivisores;
	char cadena[50] = "El arbol";


	printf("Ingrese un Numero: ");
	scanf("%d", &numero);
	contadorDivisores = divisores(numero);

	printf("La cantidad de divisores de %d es %d\n",numero,contadorDivisores);

	intercambio(cadena);


	/*
	 * La relacion entre estructura repetitiva, vector, pasaje por valor, por referencia, direccion de memoria es que cada una se utiliza para la manipulacion de otra osea:
	 * las estructuras repetitivas se usan para poder obtener el valor de cada indice del vector.
	 *
	 * los pasajes por valor estan relacionado con los pasajes con referencia y direcciones de memoria ya que los que son por valor solo copian el contenido que les estas pasando,
	 * en cambio los pasajes por referencia obtienen la direccion de memoria de lo que le estas pasando, asi poder manipular directamente el contenido sin necesidad de compiarlo e igualarlo a
	 * una variable auxiliar.
	 *
	 *
	 * */


	return EXIT_SUCCESS;
}

void intercambio(char* cadena){

	char* aux = strlwr(cadena);
	char aux2;
	int tam;
	int i;
	int j;
	tam = strlen(cadena);

	if(cadena != NULL)
	{
		for(i=0;i<tam-1;i++)
		{
			for(j=i+1;j<tam;j++)
			{
				if(aux[i]>aux[j])
				{
					aux2= cadena[i];
					cadena[i]=cadena[j];
					cadena[j]=aux2;
				}
			}
		}

		for(int k=0;k<tam;k++)
		{
			if(isspace(cadena[k])){
			   cadena[k] = '*';
			}
		}
		printf("Cadena: %s",cadena);
	}
}
int divisores(int numero){
	int contador;
	contador=1;

	for(int i=1;i<=numero/2;i++){
		if(numero%i == 0){
			contador++;
		}
	}



	return contador;
}
