#include <stdio.h>
#include <locale.h>
#include <string.h>

void mostrarCabecalho(){
    printf("-----------------------------------------------------\n");
    printf("SISTEMA DE TRIAGEM PARA MORADORES/ TRABALHADORES RURAIS\n");
    printf(">> Esse sistema não substitui uma avaliação médica.\n");
    printf(">> Procure um posto de saúde para uma avaliação.\n");
    printf("-----------------------------------------------------\n\n");
}

void mostrarSintomas(){
    printf(">> SINTOMAS\n");
    printf("[1] Febre\n");
    printf("[2] Dor muscular e nas articulações\n");
    printf("[3] Manchas vermelhas\n");
    printf("[4] Dor de cabeça\n");
    printf("[5] Náusea e vômito\n");
    printf("[6] Inchaço e vermelhidão\n");
    printf("[7] Diarreia\n");
}

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	int i , cont, sint[5]; 
	
	mostrarCabecalho();
	mostrarSintomas();
	do{
		printf("\nQUANTOS DOS SINTOMAS ACIMA VOCÊ GOSTARIA DE SELECIONAR?\n");
		printf("[1] UM\n");
		printf("[2] DOIS\n");
		printf("[3] TRÊS\n");
		printf("[4] QUATRO\n");
		printf("[5] CINCO\n");
		printf("Opção: ");
		scanf("%d", &cont);
		if(cont < 1 || cont > 5){
			printf("\nOPÇÃO INVÁLIDA. DIGITE UMA DAS OPÇÕES ABAIXO:\n");
		}
	}while (cont < 1 || cont > 5);
	
	printf("\n------------------------------ DIAGNÓSTICO --------------------------------------\n");
	printf("\nDIGITE O ÍNDICE DO SINTOMA QUE VOCÊ APRESENTA: ");
	scanf("%d", &sint[i]);

    if(cont == 1){
		for(i = 0; i < cont; i++){
	        switch(sint[i]){
	            case 1: 
					printf(">> [FEBRE]: pode indicar gripe ou infecção\n"); 
					break;
	            case 2: 
					printf(">> [DOR MUSCULAR/ARTICULAR]: pode indicar esforço físico, gripe ou dengue\n"); 
					break;
	            case 3: 
					printf(">> [MANCHAS VERMELHAS]: alergia, picada de inseto ou sarampo\n"); 
					break;
	            case 4: 
					printf(">> [DOR DE CABEÇA]: gripe, desidratação ou tensão\n"); 
					break;
	            case 5: 
					printf(">> [NAUSEA E VOMITO]: intoxicação alimentar ou gastroenterite\n"); 
					break;
	            case 6: 
					printf(">> [INCHAÇO E VERMELHIDÃO]: alergia, ferida ou reação a picada de inseto\n"); 
					break;
	            case 7: 
					printf(">> [DIARREIA]: intoxicação alimentar ou infecção intestinal\n"); 
					break;
	            default: 
					printf(">> Sintoma inválido\n"); 
					break;
            }
        }
    }else{
        printf("Você informou %d sintomas.\n", cont);
        printf("Com base nos sintomas informados, podem existir várias condições possíveis, incluindo:\n");
		if (cont == 2){// para quando for 2 sintomas
			if (sint == 1 && sint == 4){
				printf("***************************************************************************************\n");
				printf("[FEBRE] + [DOR DE CABEÇA]:\n >> Gripe ou virose comum!\n");
				printf("***************************************************************************************\n");
			}else if(sint == 2 && sint ==4){
				printf("***************************************************************************************\n");
				printf("[DOR MUSCULAR] + [DOR DE CABEÇA]:\n >> Cansaço físico, gripe ou virose leve!\n");
				printf("***************************************************************************************\n");
			}else if(sint
				//...vou continuar ps: julia oliveira
		}else if(cont == 3){
			// para quando por 3 sintoms
			// ...continuar aqui
		}else if(cont == 4){
			// para quando por 4 sintoms
			//...continuar aqui
		}else if(cont == 5){
			// para quando por 5 sintoms
			//...continuar aqui
		}
	} else { 
		int febre=0, dor=0, manchas=0, cabeca=0, nausea=0, inchaco=0, diarreia=0, fraqueza=0, olhos=0;

		for (i=0; i< cont; i++) {
			switch(sint[i]){
				case 1: febre = 1; break;
				case 2: dor = 1; break;
				case 3: manchas = 1; break;
				case 4: cabeca = 1; break;
                case 5: nausea = 1; break;
                case 6: inchaco = 1; break;
                case 7: diarreia = 1; break;
                case 8: fraqueza = 1; break;
                case 9: olhos = 1; break;
			}
		}

		printf ("\n De acordo com os sintomas infromas, é recomendável a ida ao hospital e consulta profissional");
		printf ("Possiveis condições de acordo com os sintomas informados:\n");

		if (febre && dor && manchas && cabeca && nausea ) {
			printf ("***********************************************************************************************************");
			printf ("Febre + dor muscular + manchas vermelhas + dor de cabeça + naúsea >> Dengue hemorrágica ou febre maculosa "); 
				}
		else if (febre && dor && inchaco && diarreia ) {
			printf ("***********************************************************************************************************");
			printf ("Febre + dor muscular + inchaço + vermelhidão + diarreia >> Leptospirose avançada");
				}
		else if(febre && cabeca && inchaco && olhos){
			printf ("***********************************************************************************************************");
            printf ("Febre + dor de cabeça + inchaço + olhos amarelados >> Hepatite ou leptospirose grave");
        }
        else if(febre && cabeca && manchas && nausea && fraqueza){
			printf ("***********************************************************************************************************");
            printf("Febre + dor de cabeça + manchas + vômito + fraqueza >> Febre maculosa, chikungunya ou infecção séria");
        }
        else if(febre && inchaco && fraqueza){
			printf ("***********************************************************************************************************");
            printf(" Febre + inchaço + vermelhidão + fraqueza extrema >> Infecção bacteriana generalizada (sepse)");
        }
        else{
            printf("Combinação de sintomas fora dos padrões graves cadastrados.\n");
        }
	printf("ATENÇÃO: Este diagnóstico é apenas informativo e não substitui avaliação médica.\n");
    printf("--------------------------------------------------------------------------------------------------------------\n");
	
	return 0;
}//int main 



