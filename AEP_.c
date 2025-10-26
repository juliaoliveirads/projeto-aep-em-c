#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <string.h>

//----------------------------------------------------- CABEÇALHO ----------------------------------------------------------
void mostrarCabecalho(){
    printf("***************************************************************************************************\n");
    printf("*                                                                                                 *\n");
    printf("*  >> SINTOMAS:                                                                                   *\n");
    printf("*                                                                                                 *\n");
    printf("*  [1] Febre                                                                                      *\n");
    printf("*  [2] Dor no corpo e nas juntas                                                                  *\n");
    printf("*  [3] Manchas vermelhas                                                                          *\n");
    printf("*  [4] Dor de cabeça                                                                              *\n");
    printf("*  [5] Náusea e vômito                                                                            *\n");
    printf("*  [6] Inchaço e vermelhidão                                                                      *\n");
    printf("*  [7] Diarreia                                                                                   *\n");
    printf("*                                                                                                 *\n");
    printf("***************************************************************************************************\n");
}

//-------------------------------------------------- MENU DE ESCOLHA --------------------------------------------------------
int mostrarIndice(){
    int cont;
    do{
        printf("*                                                                                                 *\n");
        printf("*  >> QUANTOS DOS SINTOMAS ACIMA VOCÊ GOSTARIA DE SELECIONAR?                                     *\n");
        printf("*                                                                                                 *\n");
        printf("*  [1] UM                                                                                         *\n");
        printf("*  [2] DOIS                                                                                       *\n");
        printf("*  [3] TRÊS                                                                                       *\n");
        printf("*  [4] QUATRO                                                                                     *\n");
        printf("*  [5] CINCO                                                                                      *\n");
        printf("*                                                                                                 *\n");
        printf("*  *-------------*                                                                                *\n");
        printf("*  ¦  Opção:     ¦                                                                                *\n");
        printf("*  *-------------*                                                                                *\n");
        printf("*                                                                                                 *\n");
        printf("***************************************************************************************************\n");
        printf("\033[4A");
        printf("\033[14C");
        scanf("%d", &cont);
        printf("\033[2B\033[100D");

        if (cont < 1 || cont > 5){
            printf("*  OPÇÃO INVÁLIDA! Digite um número entre 1 e 5 !!!                                               *\n");
            printf("*                                                                                                 *\n");
            printf("***************************************************************************************************\n");
        }
    }while (cont < 1 || cont > 5);
    return cont;
}

//---------------------------------------------------- LEITURA DOS SINTOMAS -------------------------------------------------
void lerSintomas(int sint[], int cont){
	int i;
	printf("***************************************************************************************************\n");
    for (i = 0; i < cont; i++){
        do{
            if (cont == 1){
                printf("*                                                                                                 *\n");
                printf("*  => DIGITE O ÍNDICE DO SINTOMA ISOLADO QUE VOCÊ APRESENTA:                                      *\n");
                printf("*                                                                                                 *\n");
                printf("\033[2A"); 
                printf("\033[61C");
            }else{
                printf("*                                                                                                 *\n");
                printf("*  => DIGITE O ÍNDICE DO %dº SINTOMA QUE VOCÊ APRESENTA:                                           *\n", i + 1);
                printf("*                                                                                                 *\n");
                printf("\033[2A"); 
                printf("\033[57C");
            }
            scanf("%d", &sint[i]);

            if (sint[i] < 1 || sint[i] > 7) {
                printf("*                                                                                                 *\n");
                printf("*  >> ÍNDICE INVÁLIDO! Digite um valor entre 1 e 7!!                                              *\n");
            }
        }while (sint[i] < 1 || sint[i] > 7);
        printf("*                                                                                                 *\n");
    }
}

//--------------------------------------------------- ORDENAR OS SINTOMAS ---------------------------------------------------
void ordenarSintomas(int sint[], int cont){
	int i;
    for (i = 0; i < cont - 1; i++){
    	int j;
        for (j = i + 1; j < cont; j++) {
            if (sint[i] > sint[j]) {
                int temp = sint[i];
                sint[i] = sint[j];
                sint[j] = temp;
            }
        }
    }
}
//-------------------------------------------------------------QTD SINTOMAS INFORMADOS ----------------------------------------
void qtdsint(int cont){
    printf("*   Você informou %d sintomas.                                                                     *\n", cont);
    printf("*                                                                                                 *\n");
}
//--------------------------- sugestões de cuidados conforme gravidade ---------------------------------------------------
	void sugestaoCuidados(char* gravidade){
	printf("*                                                                                                 *\n");
    printf("*  >> SUGESTÕES DE CUIDADOS                                                                       *\n");
    printf("*                                                                                                 *\n");

    if (strcmp(gravidade, "LEVE") == 0){
        printf("*    - Beba bastante água.                                                                        *\n");
        printf("*    - Descanse e evite esforço físico.                                                           *\n");
        printf("*    - Alimente-se de forma leve e equilibrada.                                                   *\n");
    }else if (strcmp(gravidade, "MODERADO") == 0){
        printf("*    - Hidrate-se bem (água e soro caseiro).                                                      *\n");
        printf("*    - Evite exposição ao sol.                                                                    *\n");
        printf("*    - Procure posto de saúde se sintomas persistirem.                                            *\n");
    }else if (strcmp(gravidade, "GRAVE") == 0){
        printf("*    - Procure um hospital IMEDIATAMENTE.                                                         *\n");
        printf("*    - Evite automedicação.                                                                       *\n");
    }
    printf("*                                                                                                 *\n");
}
//---------------------------------------------------- DIAGNÓSTICO ------------------------------------------------------------
void diagnosticar(int sint[], int cont, char* gravidade){
	int reconhecido = 0; //0 = reconhecido 1= não reconhecido
	printf("*                                                                                                 *\n");
    printf("*-------------------------------- RESULTADO DO DIAGNÓSTICO ---------------------------------------*\n");
	printf("*                                                                                                 *\n");
    //caso 1 sintoma
    if (cont == 1){
        switch (sint[0]){
            case 1: printf("*  [FEBRE]: Pode indicar gripe ou infecção.                                                       *\n"); break;
            case 2: printf("*  [DOR NO CORPO/JUNTAS]: Pode indicar esforço físico excessivo, gripe ou dengue.                 *\n"); break;
            case 3: printf("*  [MANCHAS VERMELHAS]: Pode indicar alergia, picada de inseto ou sarampo.                        *\n"); break;
            case 4: printf("*  [DOR DE CABEÇA]: Pode indicar gripe, desidratação ou tensão.                                   *\n"); break;
            case 5: printf("*  [NÁUSEA E VÔMITO]: Pode indicar intoxicação alimentar ou infecção.                             *\n"); break;
            case 6: printf("*  [INCHAÇO/VERMELHIDÃO]: Pode indicar alergia, ferida ou reação a picada.                        *\n"); break;
            case 7: printf("*  [DIARREIA]: Pode indicar intoxicação alimentar ou infecção intestinal.                         *\n"); break;
        }
    }
	//caso 2 sintomas
	else if(cont == 2){
		qtdsint(cont);			  				  

	    if((sint[0]==1 && sint[1]==4)){
	        printf("*   CASO LEVE:                                                                                    *\n*   [FEBRE] + [DOR DE CABEÇA] >> Gripe ou virose comum.                                           *\n");
	    }else if((sint[0]==2 && sint[1]==4)){
	        printf("*   CASO LEVE:                                                                                    *\n*   [DOR NO CORPO/JUNTAS] + [DOR DE CABEÇA] >> Cansaço físico ou virose leve.                     *\n");
	    }else if((sint[0]==5 && sint[1]==7)){
	        printf("*   CASO LEVE:                                                                                    *\n*   [NÁUSEA/VÔMITO] + [DIARREIA] >> Intoxicação alimentar leve.                                   *\n");
	    }else if((sint[0]==3 && sint[1]==6)){ 
	        printf("*   CASO LEVE:                                                                                    *\n*   [MANCHAS] + [INCHAÇO] >> Reação a picada ou alergia simples.                                  *\n");																
	    }else if((sint[0]==1 && sint[1]==2)){ 
	        printf("*   CASO MODERADO:                                                                                *\n*   [FEBRE] + [DOR NO CORPO/JUNTAS] >> Suspeita de dengue, sintomas gripais ou início de          *\n*                                      infecção leve.                                             *\n");
	    }else if((sint[0]==1 && sint[1]==3)){
	        printf("*   CASO MODERADO:                                                                                *\n*   [FEBRE] + [MANCHAS VERMELHAS] >> Alta chance de dengue.                                       *\n");         
	    }else if((sint[0]==1 && sint[1]==5)){ 
	        printf("*   CASO MODERADO:                                                                                *\n*   [FEBRE] + [NÁUSEA/VÔMITO] >> Infecção viral inicial ou leptospirose.                          *\n");
	    }else if((sint[0]==1 && sint[1]==6)){ 
	        printf("*   CASO MODERADO:                                                                                *\n*   [FEBRE] + [INCHAÇO] >> Infecção de pele.                                                      *\n");
	    }else if((sint[0]==1 && sint[1]==7)){ 
	        printf("*   CASO MODERADO:                                                                                *\n*   [FEBRE] + [DIARREIA] >> Infecção intestinal ou verminose.                                     *\n");
	    }else{ 
	        printf("*  COMBINAÇÃO NÃO RECONHECIDA >> Observe a evolução e procure orientação médica se necessário.    *\n");
	        reconhecido = 1;
	   	printf("*                                                                                                 *\n");		
		}
	}
	//caso 3 sintomas
	else if(cont == 3){
		qtdsint(cont);
    	
		if ((sint[0]==1 && sint[1]==2 && sint[2]==4)){ 
		    printf("*   CASO MODERADO:                                                                                *\n*   [FEBRE] + [DOR NO CORPO/JUNTAS] + [DOR DE CABEÇA] >> Início de dengue ou virose forte.        *\n");
		}else if ((sint[0]==1 && sint[1]==2 && sint[2]==3)){ 
		    printf("*   CASO MODERADO:                                                                                *\n*   [FEBRE] + [DOR NO CORPO/JUNTAS] + [MANCHAS] >> Dengue clássica.                               *\n");
		}else if ((sint[0]==1 && sint[1]==2 && sint[2]==5)){ 
		    printf("*   CASO MODERADO:                                                                                *\n*   [FEBRE] + [DOR NO CORPO/JUNTAS] + [NÁUSEA/VÔMITO] >> Leptospirose inicial.                    *\n");
		}else if ((sint[0]==1 && sint[1]==5 && sint[2]==7)){ 
		    printf("*   CASO MODERADO:                                                                                *\n*   [FEBRE] + [NÁUSEA/VÔMITO] + [DIARREIA] >> Infecção intestinal.                                *\n");
		}else if ((sint[0]==1 && sint[1]==3 && sint[2]==6)){
		    printf("*   CASO MODERADO:                                                                                *\n*   [FEBRE] + [MANCHAS] + [INCHAÇO] >> Infecção de pele.                                          *\n");
	    }else{ 
	        printf("*  COMBINAÇÃO NÃO RECONHECIDA >> Observe a evolução e procure orientação médica se necessário.    *\n");
	        reconhecido = 1;
	    printf("*                                                                                                 *\n");
		}
	}
	//caso 4 sintomas
	else if (cont == 4){  
		qtdsint(cont);
		    	                                                                                                                                                                                                
	    if ((sint[0]==1 && sint[1]==2 && sint[2]==3 && sint[3]==4)){                                                                                                  
	        printf("*   CASO GRAVE:                                                                                   *\n*   [FEBRE] + [DOR NO CORPO/JUNTAS] + [MANCHAS] + [DOR DE CABEÇA] >> Dengue hemorrágica ou        *\n*                                                                    febre maculosa.              *\n");
	    }else if ((sint[0]==1 && sint[1]==2 && sint[2]==3 && sint[3]==6)){
	        printf("*   CASO GRAVE:                                                                                   *\n*   [FEBRE] + [DOR NO CORPO/JUNTAS] + [MANCHAS] + [INCHAÇO] >> Leptospirose.                      *\n");
	    }else if ((sint[0]==1 && sint[1]==2 && sint[2]==4 && sint[3]==5)){                                                     	                                                                                      
	        printf("*   CASO GRAVE:                                                                                   *\n*   [FEBRE] + [DOR NO CORPO/JUNTAS] + [DOR DE CABEÇA] + [NÁUSEA/VÔMITO] >> Chikungunya ou         *\n*                                                                          infecção moderada.     *\n");
	    }else if ((sint[0]==1 && sint[1]==3 && sint[2]==6 && sint[3]==7)){
	        printf("*   CASO GRAVE:                                                                                   *\n*   [FEBRE] + [MANCHAS] + [INCHAÇO] + [DIARREIA] >> Infecção bacteriana generalizada.             *\n");
	    }else{ 
	        printf("*  COMBINAÇÃO NÃO RECONHECIDA >> Observe a evolução e procure orientação médica se necessário.    *\n");
	        reconhecido = 1;
	    printf("*                                                                                                 *\n");	
		}
	}
    //caso 5 sintomas
	else if (cont == 5){
		qtdsint(cont);
		
	    if (sint[0]==1 && sint[1]==2 && sint[2]==3 && sint[3]==4 && sint[4]==5){                                                                                                                                      
	        printf("*   CASO GRAVE:                                                                                   *\n*   [FEBRE] + [DOR NO CORPO/JUNTAS] + [MANCHAS] + [DOR DE CABEÇA] + [NÁUSEA/VÔMITO]               *\n*   >> Dengue hemorrágica.                                                                        *\n");
	    }else if (sint[0]==1 && sint[1]==2 && sint[2]==3 && sint[3]==6 && sint[4]==7){
	        printf("*   CASO GRAVE:                                                                                   *\n*   [FEBRE] + [DOR NO CORPO/JUNTAS] + [MANCHAS] + [INCHAÇO] + [DIARREIA] >> Leptospirose avançada.*\n");
	    }else if (sint[0]==1 && sint[1]==3 && sint[2]==4 && sint[3]==6 && sint[4]==7){                                                                                                                                   
	        printf("*   CASO GRAVE:                                                                                   *\n*   [FEBRE] + [MANCHAS] + [DOR DE CABEÇA] + [INCHAÇO] + [DIARREIA] >> Infecção bacteriana         *\n*                                                                      generalizada (sepse).      *\n");
	    }else{
	        printf("*  COMBINAÇÃO NÃO RECONHECIDA >> Observe a evolução e procure orientação médica se necessário.    *\n");
	        reconhecido = 1;
	    printf("*                                                                                                 *\n");	
		}
	}
	

	printf("*                                                                                                 *\n");	
    printf("*=================================================================================================*\n");
    printf("*                                                                                                 *\n");
    printf("*   IMPORTANTE:                                                                                   *\n");
    printf("*   - Este diagnóstico é apenas informativo.                                                      *\n");
    printf("*   - Não substitui avaliação médica profissional.                                                *\n");
    printf("*   - Observe a evolução dos sintomas e procure atendimento médico se houver piora.               *\n");
    printf("*                                                                                                 *\n");
    printf("*=================================================================================================*\n");
    time_t t;
	struct tm *data_atual;
	t = time(NULL);
	data_atual = localtime(&t);
	
	if (!reconhecido){
    	sugestaoCuidados(gravidade);
	}	

	printf("*                                                                                                 *\n");
	printf("*                                                                           Ass: DR. ChatBot      *\n");
	printf("*                                                                           Data: %02d/%02d/%d      *\n", 
    data_atual->tm_mday, data_atual->tm_mon + 1, data_atual->tm_year + 1900);
    printf("*                                                                                                 *\n");
	printf("*                                                                                                 *\n");	
}

//--------------------------- legenda geral de gravidade --------------------------------------------------------------------------
void legendaGravidade(){
	printf("***************************************************************************************************\n");
	printf("*                                                                                                 *\n");
    printf("*  >> LEGENDA DE GRAVIDADE                                                                        *\n");
    printf("*                                                                                                 *\n");
    printf("*     - Casos LEVES: apenas observação e cuidados simples.                                        *\n");
    printf("*     - Casos MODERADOS: possível gripe ou dengue — manter hidratação e repouso.                  *\n");
    printf("*     - Casos GRAVES: procurar atendimento médico imediato!                                       *\n");
    printf("*                                                                                                 *\n");
    printf("*                                                                                                 *\n");
}
//-------------------------------------------------------- MENU INTERATIVO ---------------------------------------------------
void menu(){
    int opcao;
    do {
    	printf("***************************************************************************************************\n");
	    printf("*                                                                                                 *\n");
	    printf("*                   SISTEMA DE TRIAGEM PARA MORADORES/ TRABALHADORES RURAIS                       *\n");
	    printf("*                     >> Este sistema não substitui uma avaliação médica.                         *\n");
	    printf("*                  >> Procure um posto de saúde para avaliação se necessário.                     *\n");
	    printf("*                                                                                                 *\n");
    	printf("***************************************************************************************************\n");
    	printf("*                                           M E N U                                               *\n");
        printf("*-------------------------------------------------------------------------------------------------*\n");
        printf("*                                                                                                 *\n");
        printf("*   [1] Novo diagnóstico                                                                          *\n");
        printf("*   [2] Legenda de gravidade                                                                      *\n");
        printf("*   [3] Sair                                                                                      *\n");
        printf("*                                                                                                 *\n");
        printf("*  *-------------*                                                                                *\n");
        printf("*  ¦  Opção:     ¦                                                                                *\n");
        printf("*  *-------------*                                                                                *\n");
        printf("*                                                                                                 *\n");
        printf("***************************************************************************************************\n");
        printf("\033[4A");
        printf("\033[14C");
        scanf("%d", &opcao);
        printf("\033[2B\033[100D");

        
        
        if (opcao == 1){
            int sint[5], cont;
            mostrarCabecalho();
            cont = mostrarIndice();
            lerSintomas(sint, cont);
            ordenarSintomas(sint, cont);
            
			char gravidade[10];
			if (cont == 1 || cont == 2) strcpy(gravidade, "LEVE");
			else if (cont == 3) strcpy(gravidade, "MODERADO");
			else strcpy(gravidade, "GRAVE");
			
			diagnosticar(sint, cont, gravidade);

        }else if (opcao == 2){
            legendaGravidade();
        }else if (opcao != 3){
        	printf("*                                                                                                 *\n");
            printf("\n* Opção inválida!                                                                                 *\n");
        }
    }while (opcao != 3);
    printf("\nEncerrando o sistema... Até mais!\n");
}

//-------------------------------------------------------- MAIN -------------------------------------------------------------
int main(){
    setlocale(LC_ALL, "Portuguese");
    menu();
    return 0;
}
