#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	int cont, sint1, sint2, sint3;
	
	printf("-----------------------------------------------------\n");
	printf("SISTEMA DE TRIAGEM PARA MOREDORES/ TRABALHADORES RURAIS\n");
	printf(">> Esse sistema n�o substitui uma avalia��o m�dia.\n");
	printf(">> Procure um posto de sa�de para uma avalia��o.\n");
	printf("-----------------------------------------------------\n");
	
	printf(">> SINTOMAS\n");
	printf("[1] Febre\n");
	printf("[2] Dor muscular e nas articula��es\n");
	printf("[3] Manchas vermelhas\n");
	printf("[4] Dor de cabe�a\n");
	printf("[5] N�usea e v�mito\n");
	printf("[6] N�usea e v�mito\n");
	printf("[7] Incha�o e vermelhid�o\n");
	printf("[8] Diarreia\n");
	
	printf("\nQUANTOS DOS SINTOMAS ACIMA VOC� GOSTARIA DE SELECIONAR?\n");
	do{
		printf("[1] UM\n");
		printf("[2] DOIS\n");
		printf("[3] TR�S\n");
		printf("Op��o: ");
		scanf("%d", &cont);
		if(cont!=1 &&cont!=2 && cont!=3){
			printf("\nOP��O INV�LIDA. DIGITE UMA DAS OP��ES ABAIXO:\n");
		}
	}while(cont!=1 &&cont!=2 && cont!=3);
	
	if(cont==1){
		printf("\nDIGITE O �NDICE DO SINTOMA QUE VOC� APRESENTA: ");
		scanf("%d", &sint1);	
	}else if(cont==2){
		printf("\nDIGITE O �NDICE DO 1� SINTOMA QUE VOC� APRESENTA: ");
		scanf("%d", &sint1);
		printf("\nDIGITE O �NDICE DO 2� SINTOMA QUE VOC� APRESENTA: ");
		scanf("%d", &sint2);		
	}else if(cont==3){
		printf("\nDIGITE O �NDICE DO 1� SINTOMA QUE VOC� APRESENTA: ");
		scanf("%d", &sint1);
		printf("\nDIGITE O �NDICE DO 2� SINTOMA QUE VOC� APRESENTA: ");
		scanf("%d", &sint2);
		printf("\nDIGITE O �NDICE DO 3� SINTOMA QUE VOC� APRESENTA: ");
		scanf("%d", &sint3);		
	}
	
	
}
