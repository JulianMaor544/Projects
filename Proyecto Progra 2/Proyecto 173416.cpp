//Proyecto de Programación 1.
//José Julián Martinez Ornelas. 173416

//Declaracion de librerias
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

//Hay un archivo FILE para cada archivo 
FILE *archivo1;
FILE *archivo2;
FILE *archivo3;

//Variables globales para ser sustituidas
char nombre[30],dire[60], tipoboleto[15]={};
char codigo[5];

//Declaracion de funciones
void ventaboletos(int &,int &,int &, int ,int ,int , int &,int &,int &,int &,int &,int &);
void menu(int &, int &, int &, int ,int ,int , int &, int &,int &,int &,int &, int &);
void punto2();
void punto3();
void punto4();
void punto5(int &, int &, int &,int &,int &,int &);

//Gotoxy
void gotoxy(int x,int y){
 HANDLE hcon;
 hcon = GetStdHandle(STD_OUTPUT_HANDLE);
 COORD dwPos;
 dwPos.X = x;
 dwPos.Y= y;
 SetConsoleCursorPosition(hcon,dwPos); 
}

//Aqui revisa si algun numero diferente de 0 esta dentro de la matriz
bool revisa(int matriz[5][5],int fila, int columna)	{
	if(matriz[fila][columna]!=0)	{
		return true;
	}else	{
		return false;
	}

}

//Parte de las pruebas 
bool revisa2(int matriz2[5][5],int corx, int cory)	{
	if(matriz2[corx][cory]!=254)	{
		return true;
	}else	{
		return false;
			
	}
}

main(){
	srand(time(NULL));
	int usuario=0,gananciatotal=0;
	int inversion1=25,inversion2=50,inversion3=100,inversionx=0,ganancia, sumadinero=0;
	int boleto1=10,boleto2=5,boleto3=2;
	int oportunidades2;
		
		//Se abren archivos para poder crear o sobreescribir los existentes con el "w+" , y poder cear los titulos de cada uno
		archivo1=fopen("punto2.txt", "w+");
		if(archivo1==NULL)	{
			printf("\nEl archivo prueba no existe \n\n");
			getch();
			exit(1);
		}
		fprintf(archivo1, "Nombre\t\t\t\tDomicilio\t\t\t\tCodigo\t\tTipo Boleto\n");
		fclose(archivo1);
		
		
		//Punto 3
		//Creacion de los titulos punto 3
		archivo2=fopen("punto3.txt", "w+");
		if(archivo2==NULL)	{
			printf("\nEl archivo prueba no existe \n\n");
			getch();
			exit(1);
		}
		fprintf(archivo2, "Nombre\t\t\tCodigo\t\tTipo Boleto\tPremio\n");	
		fclose(archivo2);
		
				
		//Punto 4
		//Creaccion de los titulos punto 4
		archivo3=fopen("punto4.txt", "w+");
		if(archivo3==NULL)	{
			printf("\nEl archivo prueba no existe \n\n");
			getch();
			exit(1);
		}
		fprintf(archivo3, "Codigo\t\tTipo Boleto\tInversion\tPremio\t  Ganancia\n");	
		fclose(archivo3);
		
		//Manda a llamar la funcion menu, es la primera vez que se ejecuta		
		menu(usuario,gananciatotal,sumadinero,inversion1,inversion2,inversion3,ganancia,inversionx,boleto1,boleto2,boleto3,oportunidades2);
		
	return 0;
}


void menu(int &usuario, int &gananciatotal,int &sumadinero, int inversion1,int inversion2,int inversion3, int &ganancia,int &inversionx,int &boleto1,int &boleto2, int &boleto3,int &oportunidades2)	{
	int opc;
	
	//Menu 
    printf("\tSorteo!!\n\n");
	printf("Elige una de las siguientes opciones...\n\n");
	printf("1) Venta de boletos\n");
	printf("2) Consulta de boletos vendidos\n");
	printf("3) Consulta de premios ganados\n");
	printf("4) Fondos recaudados\n");
	printf("5) Configuracion\n");
	printf("6) Salir\n");
	printf("\tOPC: ");
	scanf("%d", &opc);
	
	switch(opc)
	{
		case 1:
		usuario++;
		ventaboletos(usuario,gananciatotal,sumadinero,inversion1,inversion2,inversion3,ganancia,inversionx,boleto1,boleto2,boleto3,oportunidades2);
		
		//Se llenan los datos en el archivo luego de hacer el proceso de venta de boletos 
		//Punto 2 donde almacena los datos en el archivo
		archivo1=fopen("punto2.txt", "a+");
		if(archivo1==NULL)	{
			printf("\nEl archivo prueba no existe \n\n");
			getch();
			exit(1);
		}
		fprintf(archivo1, "%s\t\t %s \t\t %s \t\t %s  \n", nombre,dire, codigo,tipoboleto);
		
		fclose(archivo1);
		
		//Punto 3 donde almacena los datos en el archivo
		archivo2=fopen("punto3.txt", "a+");
		if(archivo2==NULL)	{
			printf("\nEl archivo prueba no existe \n\n");
			getch();
			exit(1);
		}
		fprintf(archivo2, "%s\t\t%s\t\t%s\t\t%d\n",nombre,codigo,tipoboleto,sumadinero);	
		fclose(archivo2);
		
		//para la generacion de la ganancia 
		ganancia=sumadinero-inversionx;
		//Parte de las pruebas
		gananciatotal+=ganancia;
		
		//Punto 4 donde almacena los datos en el archivo
		archivo3=fopen("punto4.txt", "a+");
		if(archivo3==NULL)	{
			printf("\nEl archivo prueba no existe \n\n");
			getch();
			exit(1);
		}
		fprintf(archivo2, "%s\t\t%s\t\t%d\t\t%d\t\t%d\n",codigo,tipoboleto,inversionx,sumadinero,ganancia);
				
		fclose(archivo3);
			
			
			menu(usuario,gananciatotal,sumadinero,inversion1,inversion2,inversion3,ganancia,inversionx,boleto1,boleto2,boleto3,oportunidades2);
			break;
		case 2:
			//Se invoca la funcion y luego de completarlo da paso al menu de nuevo, eso en cada uno de los puntos 
			//Punto 2 muestra nombre,domicilio,,codigo y tipo de boleto
			punto2();
			getch();
			system("cls");
			menu(usuario,gananciatotal,sumadinero,inversion1,inversion2,inversion3,ganancia,inversionx,boleto1,boleto2,boleto3,oportunidades2);
			break;
		case 3:
			//Punto 3 muestra nombre,codigo,tipo de boleto y premio
			punto3();
			getch();
			system("cls");
			menu(usuario,gananciatotal,sumadinero,inversion1,inversion2,inversion3,ganancia,inversionx,boleto1,boleto2,boleto3,oportunidades2);
			break;
		case 4:
			//Punto 4 muestra codigo, tipo de boleto,inverison, premio y ganancia
			punto4();
			getch();
			system("cls");
			menu(usuario,gananciatotal,sumadinero,inversion1,inversion2,inversion3,ganancia,inversionx,boleto1,boleto2,boleto3,oportunidades2);
			break;
		case 5:
			//Punto 5 aqui se configuran los datos de variables que se usaran en el programa 
			punto5(inversion1,inversion2,inversion3,boleto1,boleto2,boleto3);
			system("cls");
			menu(usuario,gananciatotal,sumadinero,inversion1,inversion2,inversion3,ganancia,inversionx,boleto1,boleto2,boleto3,oportunidades2);
			break;
		case 6:
			printf("Gracias por usar este programa!");
			break;
		default:
			printf("No ingresaste un numero valido");
			break;
	}
	
}

void ventaboletos(int &usuario,int &gananciatotal,int &sumadinero, int inversion1,int inversion2,int inversion3,int &ganancia,int &inversionx,int &boleto1, int &boleto2,int &boleto3,int &oportunidades2)	{
	int opc_cate,oportunidades=0, fila,columna, n=0,x=0,contador=0,matriz[5][5]={0},corx=0,cory=0,matriz2[5][5]={0},oportunidades1=0,elemento=254;
	int eleccion;
	
		system("cls");
		
		//Ingreso de datos
		printf("Usuario: %d", usuario);
		fflush(stdin);
		printf("\nCual es tu nombre?(Un Nombre y un apellido): ");
		gets(nombre);
		printf("Cual es tu domicilio?(Maximo 60 palabras): ");
		gets(dire);
		
		//Ciclo for para la generacion de el numero de boleto con un arreglo
		printf("\nNumero de boleto: ");
		for(int i=0;i<5;i++)	{
			codigo[i]=65+rand()%(90-65)+1;
			printf("%c", codigo[i]);
		}
			
		//Seleccion de categoria 
		printf("\nQue boleto deseas comprar?: ");
		printf("\n1.Categoria basica\n2.Categoria premium\n3.Categoria oro");
		scanf("%d", &opc_cate);
		
		//Aqui se le da valor a las oportunidades	
		switch(opc_cate)	{
			case 1:
				//Aqui dependiendo del si el valor del boleto llegue a 0 se hacen todas las cosas que ahi marca 
				if(boleto1!=0)	{
				strcpy(tipoboleto, "Basico"); //Se copia en la variable tipo de boleto el nombre de ese boleto
				inversionx=inversion1; //Se almacena el valor de la inversion en una variable que se estara usando mas adelante para calcular ciertos datos 
				oportunidades2=1; //Se asigna el valor a oportunidades 2
				oportunidades=1;
				boleto1--; //Se resta lo del boleto
				}else	{
					//Se da un mensaje de despedida y da paso a la funcion menu para volvera escoger alguna otra opcion
					printf("No hay mas boletos disponibles!, vuelve y elige otra opcion!\n\n\n");
					menu(usuario,gananciatotal,sumadinero,inversion1,inversion2,inversion3,ganancia,inversionx,boleto1,boleto2,boleto3,oportunidades2);
				}
				break;
			case 2: 
			//Ocurre lo mismo que con el case 1
				if(boleto2!=0)	{
				strcpy(tipoboleto, "Premium");
				inversionx=inversion2;	
				oportunidades2=3;
				oportunidades=3;
				boleto2--;
				}else	{
					printf("No hay mas boletos disponibles!, vuelve y elige otra opcion!\n\n\n");
					menu(usuario,gananciatotal,sumadinero,inversion1,inversion2,inversion3,ganancia,inversionx,boleto1,boleto2,boleto3,oportunidades2);
				}
				break;
			case 3:
				if(boleto3!=0)	{
				strcpy(tipoboleto, "Oro");
				inversionx=inversion3;
				oportunidades2=5;
				oportunidades=5;
				boleto3--;
				}else	{
					printf("No hay mas boletos disponibles!, vuelve y elige otra opcion!\n\n\n");
					menu(usuario,gananciatotal,sumadinero,inversion1,inversion2,inversion3,ganancia,inversionx,boleto1,boleto2,boleto3,oportunidades2);
				}
				
				break;
			default:
				printf("No seleccionaste un numero valido"); 
				break;		
		}
		
						
		system("cls");
			
		contador=0;
		//Aqui se llena el primer arreglo de los numeros aleatorios en posiciones aleatorias 
		for(int i=0;i<5;i++)	{
			for(int j=0;j<5;j++)	{	
				if(contador<10)	{
				do	{
				fila=rand()%4; //Aleatori de la fila
				columna=rand()%4; //Aleatorio de la columna
				n=5+rand()%(251-5);	
				}while((revisa(matriz,fila, columna)==true)); //Revisa si dentro del arreglo y en la fila y columna aleatoria existe algun numero ya puesto
					matriz[fila][columna]=n;
					contador++;
				}	
			}
		}
		
		//Aqui se imprime el valor elemento, que tiene como valor 254, para poder imprimir el caracter del codigo ascci	
		for(int i=0;i<5;i++)	{
			for(int j=0;j<5;j++)	{
				printf("[  %c   ] ", elemento);
			}
			printf("\n");
		}
	
		oportunidades1=oportunidades;
		
		//Aqui se llena el arreglo con el valor 254, porque?, principalmente porque ese es el numero del codigo ascci de ese caracter, al llenar con 
		//ese numero siempre al imprimir con %c saldra el caracter al imprimir pantalla, mas adelante se sustituye el numero 254, por el numero verdadero de la
		//Casilla y posicion	
		for(int i=0;i<5;i++)	{
				for(int j=0;j<5;j++)	{
				matriz2[i][j]=254;
			}
		}	
			
		printf("\n");
		
		//Pedida de la primera entrada de coordenadas	
		printf("Oportunidades: %d", oportunidades);
		printf("\nDame las coordenadas x & y: ");
		scanf(" %d ", &corx);
		scanf("%d", &cory);
			
		oportunidades--; //Primera resta de oportunidades
			
		system("cls");
			
		do	{
			for(int i=0;i<5;i++)	{
				for(int j=0;j<5;j++)	{			
					if(i==corx && j==cory)	{
						matriz2[i][j]=0; //Aqui al encontrar el valor que es igual de i y j con coordenadas, se sustituye por un 0
						matriz2[i][j]=matriz[i][j]; //Luego se sustituye con el valor real del otro arreglo
						sumadinero=sumadinero+matriz2[i][j];
					}
					
					if(matriz2[i][j]!=254)	{
						printf("[ %d ] ", matriz2[i][j]); //Aqui si el valor es diferente de 254 que es el valor del codigo ascci se imprimira el valor con %d
					}else	{
						printf("[  %c  ] ", matriz2[i][j]); //Sino se imprimira en forma de caracter
					}	
			}
			printf("\n");
		}	
		//Despues de cumplir los for se hace esto para pedir de nuevo las coordenadas
			
			printf("Oportunidades: %d", oportunidades);
			printf("\nTotal acumulado hasta el momento: %d", sumadinero); //El total acumulado se almacena en la variable sumadinero
			
			if(oportunidades!=0)	{
			printf("\nDame las coordenadas x & y: ");
			scanf(" %d ", &corx);
			scanf("%d", &cory);
			if(matriz2[corx][cory]!=254)	{
				oportunidades=oportunidades; //Si en la posicion hay un numero diferente de 254 se queda igual las oprtunidades
			}else	{
				oportunidades--;
			}
			
			system("cls"); //Se limpia la pantalla para mostrar de nuevo el arreglo desde el principio
			}else	{
			
				
					
				
			}	
			
					
		}while(oportunidades!=0); //Hasta que las oportunidades sean igual o mayor que 0 se dejara de hacer la accion

}

void punto2()	{
	char buffer;
	//Se abre el archivo y se lee, luego se imprime caracter por caracter, esto con los puntos 2,3 y 4
	archivo1=fopen("punto2.txt","r");
	if (archivo1==NULL){  
		printf("\nEl archivo prueba no existe \n\n"); //Señala si hubo un error al abrir el archivo prueba 
		getch();
		exit(1); //salir
	}

	system("cls");
	while(!feof(archivo1))	{ //feof sirve para dejar de imprimir si hay un salto de linea, entonces hasta no sea distinto de, dejara de imprimir
		
		buffer = fgetc(archivo1);
		printf("%c",buffer);
	}
	
	fclose(archivo1); //Se cierra el archivo
}

void punto3()	{
	char buffer;
	//Se hace todo lo que se hizo en el punto 3
	archivo1=fopen("punto3.txt","r");
	if (archivo1==NULL){  
		printf("\nEl archivo prueba no existe \n\n");
		getch();
		exit(1);
	}

	system("cls");
	
	while(!feof(archivo1))	{
		
		buffer = fgetc(archivo1);
		printf("%c",buffer);
	}
	
	fclose(archivo1);
}

void punto4()	{
	char buffer;
	
	archivo1=fopen("punto4.txt","r");
	if (archivo1==NULL){  
		printf("\nEl archivo prueba no existe \n\n");
		getch();
		exit(1);
	}

	system("cls");
	
	while(!feof(archivo1))	{
		
		buffer = fgetc(archivo1);
		printf("%c",buffer);
	}
	
	fclose(archivo1);
}

void punto5(int &inversion1, int &inversion2, int &inversion3, int &boleto1, int &boleto2, int &boleto3)	{
	int opc1,opc2,opc3;
	int valornuevo;
	int boletonuevo;
	
	system("cls");
	printf("Que deseas cambiar?: \n1.Participantes\n2.Costos\n");
	printf("OPC: ");
	scanf("%d", &opc1);
	
	//Se selecciona con un switch y dependiendo de que boleto escojas se cambia el valor de dicho boleto, lo mismo a la hora de elegir la inversion
	switch(opc1)	{
		case 1:
			printf("\nCual boleto deseas cambiar?: \n1.Basico\n2.Premium\n3.Oro\n");
			printf("OPC: ");
			scanf("%d", &opc3);
			
			switch(opc3)	{
				case 1:
					printf("\nCual es el nuevo valor maximo de boletos a vender de este boleto?: ");
					scanf("%d", &boletonuevo);
					boleto1=boletonuevo; //Se sutituye el valor de boleto 1, que es el valor del boleto basico
					printf("Nuevo valor del boleto: %d", boleto1);
					break;
				case 2:
					printf("\nCual es el nuevo valor maximo de boletos a vender de este boleto?: ");
					scanf("%d", &boletonuevo);
					boleto2=boletonuevo; //Se sutituye el valor de boleto 2, que es el valor del boleto Premium
					printf("Nuevo valor del boleto: %d", boleto2);
					break;
				case 3:
					printf("\nCual es el nuevo valor maximo de boletos a vender de este boleto?: ");
					scanf("%d", &boletonuevo);
					boleto3=boletonuevo; //Se sutituye el valor de boleto 3, que es el valor del boleto Oro
					printf("Nuevo valor del boleto: %d", boleto3);
					break;
				default:
					printf("No elegiste un numero valido");
					break;			
			}
			break;
		case 2:
			printf("Que costo deseas cambiar?: \n1.Basico\n2.Premium\n3.Oro\n");
			printf("OPC: ");
			scanf("%d", &opc2);
			
			switch(opc2)	{
				case 1:
					printf("\nCual es el nuevo costo?: ");
					scanf("%d", &valornuevo);
					inversion1=valornuevo; //Se sutituye el valor de boleto 1, que es el valor del boleto basico
					printf("\nValor nuevo: %d", inversion1);
					break;
				case 2:
					printf("\nCual es el nuevo costo?: ");
					scanf("%d", &valornuevo);
					inversion2=valornuevo; //Se sutituye el valor de boleto 2, que es el valor del boleto premium
					printf("\nValor nuevo: %d", inversion2);
					break;
				case 3:
					printf("\nCual es el nuevo costo?: ");
					scanf("%d", &valornuevo);
					inversion3=valornuevo; //Se sutituye el valor de boleto 3, que es el valor del boleto oro
					printf("\nValor nuevo: %d", inversion3);
					break;
				default:
					printf("No elegiste un numero valido");
					break;			
			}
			break;
		default:
			printf("No seleccionaste un numero valido ");
			break;	 
	}		
}

