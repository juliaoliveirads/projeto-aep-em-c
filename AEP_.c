#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	int cont, sint1, sint2, sint3;
	
	printf("-----------------------------------------------------\n");
	printf("SISTEMA DE TRIAGEM PARA MOREDORES/ TRABALHADORES RURAIS\n");
	printf(">> Esse sistema não substitui uma avaliação média.\n");
	printf(">> Procure um posto de saúde para uma avaliação.\n");
	printf("-----------------------------------------------------\n");
	
	printf(">> SINTOMAS\n");
	printf("[1] Febre\n");
	printf("[2] Dor muscular e nas articulações\n");
	printf("[3] Manchas vermelhas\n");
	printf("[4] Dor de cabeça\n");
	printf("[5] Náusea e vômito\n");
	printf("[6] Náusea e vômito\n");
	printf("[7] Inchaço e vermelhidão\n");
	printf("[8] Diarreia\n");
	
	printf("\nQUANTOS DOS SINTOMAS ACIMA VOCÊ GOSTARIA DE SELECIONAR?\n");
	do{
		printf("[1] UM\n");
		printf("[2] DOIS\n");
		printf("[3] TRÊS\n");
		printf("Opção: ");
		scanf("%d", &cont);
		if(cont!=1 &&cont!=2 && cont!=3){
			printf("\nOPÇÃO INVÁLIDA. DIGITE UMA DAS OPÇÕES ABAIXO:\n");
		}
	}while(cont!=1 &&cont!=2 && cont!=3);
	
	if(cont==1){
		printf("\nDIGITE O ÍNDICE DO SINTOMA QUE VOCÊ APRESENTA: ");
		scanf("%d", &sint1);	
	}else if(cont==2){
		printf("\nDIGITE O ÍNDICE DO 1° SINTOMA QUE VOCÊ APRESENTA: ");
		scanf("%d", &sint1);
		printf("\nDIGITE O ÍNDICE DO 2° SINTOMA QUE VOCÊ APRESENTA: ");
		scanf("%d", &sint2);		
	}else if(cont==3){
		printf("\nDIGITE O ÍNDICE DO 1° SINTOMA QUE VOCÊ APRESENTA: ");
		scanf("%d", &sint1);
		printf("\nDIGITE O ÍNDICE DO 2° SINTOMA QUE VOCÊ APRESENTA: ");
		scanf("%d", &sint2);
		printf("\nDIGITE O ÍNDICE DO 3° SINTOMA QUE VOCÊ APRESENTA: ");
		scanf("%d", &sint3);		
	}
	
	
}
