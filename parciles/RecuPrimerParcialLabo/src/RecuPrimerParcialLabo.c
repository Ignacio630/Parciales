#include "utn_funciones.h"

//defines
#define OCUPADO 1
#define LIBRE 0
#define TAM 10

typedef struct{
	int idConsulta;
	char descripcion[50];
	int fechaAtencion;
	char diagnostico[50];
	int estado;
} eConsulta;

static int incrementalId();
static int incrementalId(){
	static int id = 1005;
	return id++;
}
int isEmptyArray(eConsulta*, int);
int initArrayStatus(eConsulta*, int);
int altaConsulta(eConsulta* ,int ,int* ,char* ,int ,char* );
void imprimirConsultas(eConsulta*,int);
int main(void) {
	setbuf(stdout,NULL);

	//Inicializacion de variables, funciones y estructuras;

	//Variables
	int opcionesMenu;
	//Estructuras
	eConsulta listaConsultas[TAM];

	//Funciones
	initArrayStatus(listaConsultas,TAM);


	//Menu
	do{
		puts("**************************Menu**************************");
		puts("1-ALTA CONSULTA");
		puts("2-MODIFICAR CONSULTA");
		puts("3-CANCELAR CONSULTA");
		puts("4-DIAGNOSTICAR CONSULTA");
		puts("5-LISTAR");
		puts("6-Salir");
	}while(opcionesMenu != 6);

	altaConsulta(listaConsultas,TAM,&listaConsultas->idConsulta,listaConsultas->descripcion ,listaConsultas->fechaAtencion ,listaConsultas->diagnostico);

	imprimirConsultas(listaConsultas,TAM);

	return EXIT_SUCCESS;
}

int initArrayStatus(eConsulta* listaConsultas, int tam){
	int retorno;
	retorno = -1;

	if(listaConsultas != NULL && tam >= 0){
		for(int i=0;i<tam;i++){
			listaConsultas[i].estado = LIBRE;
			retorno = 0;
		}
	}

	return retorno;
}

int isEmptyArray(eConsulta* listaConsultas, int tam){
	int retorno;
	retorno = -1;

	if(listaConsultas != NULL && tam >= 0){
		for(int i=0;i<tam;i++){
			if(listaConsultas[i].estado == LIBRE){
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int altaConsulta(eConsulta* listaConsulta,int tam,int* id, char* desc,int fecha,char*diag){
	int retorno;
	int index;

	retorno = -1;
	index = isEmptyArray(listaConsulta, tam);
	if(listaConsulta != NULL && tam > 0){
		for(int i = 0;i<tam;i++){
			if(index >= 0){
				listaConsulta[index].idConsulta = incrementalId();
				PedirCadena(desc, "Ingrese la descripcion");
				strcpy(listaConsulta[index].descripcion,desc);
				utn_GetEntero(&fecha, "Ingrese la fecha de la consulta", "Error, fecha invalida", 0, 3000, 99);
				listaConsulta[index].fechaAtencion = fecha;
				listaConsulta[index].estado = OCUPADO;
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

void imprimirConsultas(eConsulta* listaConsultas,int tam){
	if(listaConsultas != NULL && tam >= 0){
		for(int i=0;i<tam;i++){
			if(listaConsultas[i].estado == OCUPADO){
				printf("%d-%s-%d-%s\n",listaConsultas[i].idConsulta,listaConsultas[i].descripcion ,listaConsultas[i].fechaAtencion ,listaConsultas[i].diagnostico);
			}
		}
	}
}






