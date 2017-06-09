#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int seleccionarTamanio();
void llenarArreglo(int [], int);
void llenarAleatoriamente(int [], int);
void llenarCargandoDatos(int [], int);
void imprimirDatos(int [], int);
void imprimir(int [], int);
void ascendente(int [], int);
void ascendenteBurbuja(int [], int);
void ascendenteInsercion(int [], int);
void ascendenteSeleccion(int [], int, bool);
void ascendenteConteo(int [], int);
void descendente(int [], int);
void descendenteBurbuja(int [], int);
void descendenteInsercion(int [], int);
void descendenteSeleccion(int [], int);
void descendenteConteo(int [], int);
void busqueda(int [], int);
void busqueda_binaria(int [], int);
void busqueda_secuencial(int [], int);


bool ordenado = false;

int main(){
	int tamanio;
	tamanio = seleccionarTamanio();
	int arreglo[tamanio];
	llenarArreglo(arreglo, tamanio);
	imprimirDatos(arreglo, tamanio);
	busqueda(arreglo, tamanio);
}

int seleccionarTamanio(){
	int tamanio;
	printf("\nIndique el tamanio del arreglo");
	printf("\n1. 1'000.000");
	printf("\n2. 2'000.000");
	printf("\n3. 5'000.000");
	printf("\n4. 10'000.000");
	printf("\n5. 20'000.000");
	printf("\n0. Salir");
	printf("\nIngrese su opcion: ");
	scanf("%d", &tamanio);
	switch(tamanio){
		case 1:  tamanio = 1000;
			break;
		case 2:  tamanio = 2000000;
		  	break;
		case 3:  tamanio = 5000000;
			break;
		case 4:  tamanio = 10000000;
			break;
		case 5:  tamanio = 20000000;
			break;
		case 0: exit(0);
			break;
		default: system("cls");
			printf("\nOpcion no valida");
			return seleccionarTamanio();
	}
	return tamanio;
}

void llenarArreglo(int arreglo[] , int tamanio){
	int opcion;
	printf("\nComo desea llenar el arreglo");
	printf("\n1. Aleatoriamente");
	printf("\n2. Cargar Datos");
	printf("\n0. Salir");
	printf("\nOpcion: ");
	scanf("%d", &opcion);
	switch(opcion){
		case 1: llenarAleatoriamente(arreglo,tamanio);
			 break;
		case 2: llenarCargandoDatos(arreglo,tamanio);
			break;
		case 0: exit(0);
			 break;
		default: system("cls");
			printf("\nOpcion no valida ");
			llenarArreglo(arreglo,tamanio);
			break;
	}
}
void llenarAleatoriamente(int arreglo[] , int tamanio){
	srand(time(NULL));
	for(int i = 0; i < tamanio; i++){
		arreglo[i] = rand()%1999999 - 999999; // [-999999 , +999999]
	}
	if(!ordenado){
		int opt = 1;
		bool opcValida = false;
		do{
			printf("Desea guardar los elementos de forma ordenada? 1: Si ------ 2: No : ");
			scanf("%d", &opt);
			opcValida = (opt == 1 || opt == 2);
			if(!opcValida){
				printf("Opcion no valida...Intente de nuevo\n");
			}
		}while(!opcValida);
		if(opt == 1){
			printf("Se ha guardado ordenadamente.\n");
			ascendenteSeleccion(arreglo, tamanio, false);
			ordenado = true;
		}else{
			printf("Se ha guardado sin ordenar.\n");
		}
	}
}
void llenarCargandoDatos(int arreglo[] , int tamanio){
	FILE *entrada;
	int tam = tamanio/1000000;	//tam , variable temporal.
	printf("\nAsegurese de que su archivo se llame 'millon%d.txt'.\nAprete enter para continuar: ", tam);
	system ("pause");

	switch(tam){
		case 1: if ((entrada = fopen("millon1.txt", "w")) == NULL){
					printf("arrchivo no encontrado....intente nuevamente...\n");
					llenarCargandoDatos(arreglo,tamanio);
				}
      			break;

      	case 2: if ((entrada = fopen("millon2.txt", "w")) == NULL){
					printf("arrchivo no encontrado....intente nuevamente...\n");
					llenarCargandoDatos(arreglo,tamanio);
				}
      			break;

      	case 5: if ((entrada = fopen("millon5.txt", "w")) == NULL){
					printf("arrchivo no encontrado....intente nuevamente...\n");
					llenarCargandoDatos(arreglo,tamanio);
				}
      			break;

      	case 10: if ((entrada = fopen("millon10.txt", "w")) == NULL){
					printf("arrchivo no encontrado....intente nuevamente...\n");
					llenarCargandoDatos(arreglo,tamanio);
				}
      			break;

      	case 20: if ((entrada = fopen("millon20.txt", "w")) == NULL){
					printf("arrchivo no encontrado....intente nuevamente...\n");
					llenarCargandoDatos(arreglo,tamanio);
				}
      			break;
	}
	for (int i = 0; i < tamanio; i++){
      if (fscanf(entrada, "%d", &arreglo[i]) != 1)
         break;
   }
   fclose(entrada);
}
void imprimirDatos(int arreglo[],int tamanio){
	int opcion;
	printf("\nMostrar datos");
	printf("\n1. De forma ascendente");
	printf("\n2. De forma descendente");
	printf("\n3. Sin ordenar");
	printf("\n4. Salir");
	printf("\nIngrese La Opcion Deseada: ");
	scanf("%d", &opcion);
	switch(opcion){
		case 1: ascendente(arreglo, tamanio);
			break;
		case 2: descendente(arreglo, tamanio);
		    break;
		case 3: imprimir(arreglo, tamanio);
			break;
		case 4: exit(0);
			break;
		default: system("cls");
			printf("\nOpcion no valida ");
			imprimirDatos(arreglo,tamanio);
			break;
	}
}
void imprimir(int arreglo[], int tamanio){
	for(int i = 0; i < tamanio; i++){
		printf("%d\n", arreglo[i]);
	}
}

//	Metedos para ordenar de forma ascendente

void ascendente(int arreglo[], int tamanio){
	int opcion;
	printf("\nMostrar datos ordenados de forma ascendente");
	printf("\n1. Metodo burbuja");
	printf("\n2. Metodo insercion");
	printf("\n3. Metodo seleccion");
	printf("\n4. Metodo conteo");
	printf("\n0. Salir");
	printf("\nIngrese La Opcion Deseada: ");
	scanf("%d", &opcion);
	switch(opcion){
		case 1: ascendenteBurbuja(arreglo, tamanio);
			break;
		case 2: ascendenteInsercion(arreglo, tamanio);
			break;
		case 3: ascendenteSeleccion(arreglo, tamanio, true);
			break;
		case 4: ascendenteConteo(arreglo, tamanio);
			break;
		case 0: exit(0);
		default: system("cls");
			printf("\nOpcion no valida");
			ascendente(arreglo, tamanio);
			break;
	}
}
void ascendenteBurbuja(int arreglo[], int tamanio){
	int aux;
	for(int i = 0; i < tamanio; i++){
		for(int j = i + 1; j < tamanio; j++){
			if(arreglo[i] > arreglo[j]){
				aux = arreglo[i];
				arreglo[i] = arreglo[j];
				arreglo[j] = aux;
			}
		}
	}
	imprimir(arreglo, tamanio);
}
void ascendenteInsercion(int arreglo[], int tamanio){
    int i, aux;
    for(int j = 1; j < tamanio; j++){
        int key = arreglo[j];
        i = j - 1;
        while(i >= 0 && arreglo[i] > key){
            arreglo[i+1] = arreglo[i];
            --i;
        }
        arreglo[i + 1] = key;
    }
    imprimir(arreglo, tamanio);
}
void ascendenteSeleccion(int arreglo[], int tamanio, bool imp){
    int min_id, aux;
    for (int i = 0; i < tamanio - 1; i++){
        min_id = i;
        for (int j = i + 1; j < tamanio; j++){
            if (arreglo[min_id] > arreglo[j]){
                min_id = j;
            }
        }

        aux = arreglo[i];
        arreglo[i] = arreglo[min_id];
        arreglo[min_id] = aux;
    }
    if(imp) imprimir(arreglo, tamanio);
}

int menor(int arreglo[], int tamanio){
	int aux = 0;
	for(int i = 1; i < tamanio; i++){
		if(arreglo[aux] > arreglo[i]) aux = i;
	}
	return aux;
}
int mayor(int arreglo[], int tamanio){
	int aux = 0;
	for(int i = 1; i < tamanio; i++){
		if(arreglo[aux] < arreglo[i]) aux = i;
	}
	return aux;
}
void ascendenteConteo(int arreglo[], int tamanio){
    int min = menor(arreglo,tamanio), max = mayor(arreglo,tamanio);
    int tam = max - min + 1;
    int cont[tam];
    for(int i = 0; i < tam; i++){ cont[i] = 0; }
    for(int i = 0;i < tamanio; i++){ cont[arreglo[i] - min]++; }

    for(int i = 0, j = 0; i < tam; i++){
    	if(cont[i] > 0){
    		while(cont[i] --){
    			arreglo[j] = i + min;
    			j++;
    		}
    	}
    }
    imprimir(arreglo, tamanio);
}

//	Metedos para ordenar de forma descendente

void descendente(int arreglo[], int tamanio){
	int opcion;
	printf("\nMostrar datos ordenados de forma descendente");
	printf("\n1. Metodo burbuja");
	printf("\n2. Metodo insercion");
	printf("\n3. Metodo seleccion");
	printf("\n4. Metodo conteo");
	printf("\n0. Salir");
	printf("\nIntroduzca su eleccion: ");
	scanf("%d", &opcion);
	switch(opcion){
		case 1: descendenteBurbuja(arreglo, tamanio);
			break;
		case 2: descendenteInsercion(arreglo, tamanio);
			break;
		case 3: descendenteSeleccion(arreglo, tamanio);
			break;
		case 4: descendenteConteo(arreglo, tamanio);
			break;
		case 0: exit(0);
		default: system("cls");
			printf("\nOpcion no valida ");
			descendente(arreglo, tamanio);
			break;
	}
}
void descendenteBurbuja(int arreglo[], int tamanio){
	int aux;
	for(int i = 0; i < tamanio; i++){
		for(int j = i + 1; j < tamanio; j++){
			if(arreglo[i] < arreglo[j]){
				aux = arreglo[i];
				arreglo[i] = arreglo[j];
				arreglo[j] = aux;
			}
		}
	}
	imprimir(arreglo, tamanio);
}
void descendenteInsercion(int arreglo[], int tamanio){
    int i, aux;
    for(int j = 1; j < tamanio; j++){
        int key = arreglo[j];
        i = j - 1;
        while(i >= 0 && arreglo[i] < key){
            arreglo[i + 1] = arreglo[i];
            --i;
        }
        arreglo[i + 1] = key;
    }
    imprimir(arreglo, tamanio);
}

void descendenteSeleccion(int arreglo[], int tamanio){
    int max_id, aux;
    for (int i = 0; i < tamanio-1; i++){
        max_id = i;
        for (int j = i + 1; j < tamanio; j++){
            if (arreglo[max_id] > arreglo[j]){
                max_id = j;
            }
        }

        aux = arreglo[i];
        arreglo[i] = arreglo[max_id];
        arreglo[max_id] = aux;
    }
}

void descendenteConteo(int arreglo[], int tamanio){
    int min = menor(arreglo, tamanio), max = mayor(arreglo, tamanio);
    int tam = max - min + 1;
    int cont[tam];
    for(int i = 0; i < tam; i++){ cont[i] = 0; }
    for(int i = 0; i < tamanio; i++){ cont[arreglo[i] - min]++; }

    for(int i = tam - 1, j = 0; i >= 0; i--){
    	if(cont[i] > 0){
    		while(cont[i] --){
    			arreglo[j] = i + min;
    			j++;
    		}
    	}
    }
    imprimir(arreglo, tamanio);
}

void busqueda(int arreglo[], int tamanio){
	int opcion;
	printf("\nQue Metodo Desea Usar Para Buscar Un Dato");
	printf("\n1. Binario");
	printf("\n2. Secuencial");
	printf("\n0. Salir");
	printf("\nIngrese su opcion: ");
	scanf("%d", &opcion);
	switch(opcion){
		case 1: busqueda_binaria(arreglo, tamanio);
			break;
		case 2: busqueda_secuencial(arreglo, tamanio);
			break;
		case 0: exit(0);
			break;
		default: printf("\nOpcion Invalida ");
			break;
	}
}

void busqueda_binaria(int arreglo[], int tamanio){
	if(!ordenado){
		printf("Su arreglo no está ordenado... Se procedera a ordenar automaticamente\n");
		ascendenteConteo(arreglo,tamanio);
	}
	int sup, inf, mitad, dato;
    bool estado = false;
    inf = -99999999;
    sup = 99999999;
    int i = 0;
    printf("\nIngrese El Dato A Buscar ");
    scanf("%d", &dato);
    while(inf <= sup && i < tamanio){
        mitad = (inf + sup) / 2;
        if(arreglo[mitad] == dato){
            estado = true;
            break;
        }
        if(arreglo[mitad] > dato){
            sup = mitad;
        }
        if(arreglo[mitad] < dato){
            inf = mitad;
        }
        i++;
    }
    if(estado == true){
        printf("Dato Encontrado");
    }else {
        printf("Dato No Encontrado");
    }
}

void busqueda_secuencial(int arreglo[], int tamanio){
	int i, dato;
    bool estado = false;
    printf("\nIngrese El Dato A Buscar ");
    scanf("%d", &dato);
    for(i = 0; i < 5; i++){
        if(arreglo[i] == dato){
            estado = true;
            break;
        }
    }
    if(estado == true){
        printf("dato encontrado \n");
    } else {
        printf("dato no encontrado");
    }
}


