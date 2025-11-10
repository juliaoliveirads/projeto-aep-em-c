#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define RESET      "\033[0m"
#define VERMELHO   "\033[1;31m"
#define VERDE      "\033[1;32m"
#define AMARELO    "\033[1;33m"
#define AZUL       "\033[1;34m"
#define YELLOW     "\033[33m"
#define CIANO      "\033[1;36m"
#define LARANJA    "\033[38;5;208m"
#define FUNDO_VERMELHO "\033[41m"

void mostrarCabecalho();
int lerSintomas();
void ordenarSintomas();
void qtdsint();
void sugestaoCuidados();
void diagnosticar();
void legendaGravidade();
void menu();

//-------------------------------------------------------- MAIN -------------------------------------------------------------
int main(){
    setlocale(LC_ALL, "Portuguese");
    menu();
    return 0;
}
//----------------------------------------------------- CABEÇALHO ----------------------------------------------------------
void mostrarCabecalho(){
    printf("***************************************************************************************************\n");
    printf("*                                                                                                 *\n");
    printf("*  >> SINTOMAS:                                                                                   *\n");
    printf("*                                                                                                 *\n");
    printf("* %s[1]%s Febre                                                                                       *\n",AZUL,RESET);
    printf("* %s[2]%s Dor no corpo e nas juntas                                                                   *\n",AZUL,RESET);
    printf("* %s[3]%s Manchas vermelhas                                                                           *\n",AZUL,RESET);
    printf("* %s[4]%s Dor de cabeça                                                                               *\n",AZUL,RESET);
    printf("* %s[5]%s Náusea e vômito                                                                             *\n",AZUL,RESET);
    printf("* %s[6]%s Inchaço e vermelhidão                                                                       *\n",AZUL,RESET);
    printf("* %s[7]%s Diarreia                                                                                    *\n",AZUL,RESET);
    printf("*                                                                                                 *\n");
    printf("***************************************************************************************************\n");
}

//---------------------------------------------------- LEITURA DOS SINTOMAS -------------------------------------------------
int lerSintomas(int sint[]){
    char resp;
    int i = 0;
    int valido;

    printf("*                                                                                                 *\n");

    do {
        do {
            valido = 1; //assume que é válido
            printf("*                                                                                                 *\n");
            printf("*  => DIGITE O ÍNDICE DO SINTOMA QUE VOCÊ APRESENTA %s(1-7)%s:                                        *\n",AMARELO,RESET);
            printf("*                                                                                                 *\n");
            printf("\033[2A"); 
            printf("\033[59C");
            if (scanf("%d", &sint[i]) != 1){
			    sint[i] = -1;  //força erro
			    fflush(stdin); //limpa o buffer
			}else{
    			while (getchar() != '\n'); // limpa o resto da linha (ex: "3fss" -> remove "fss")
			}
            
            //verifica faixa
            if (sint[i] < 1 || sint[i] > 7){
                printf("*                                                                                                 *\n");
                printf("*%s  >> ÍNDICE INVÁLIDO! Digite um valor numérico entre %s1 e 7%s!!                                     %s*\n",FUNDO_VERMELHO, AMARELO, FUNDO_VERMELHO, RESET);
                valido = 0;
            }

            //verifica duplicaçao
            int j;
            for (j = 0; j < i; j++){
                if (sint[i] == sint[j]){
                    printf("*                                                                                                 *\n");
                    printf("*  >> %sVocê já informou esse sintoma! Escolha outro.%s                                               *\n",LARANJA,RESET);
                    valido = 0;
                    break;
                }
            }

        }while (!valido);

        i++;

        if (i >= 5) {
            printf("*                                                                                                 *\n");
            printf("*%s  >> VOCÊ ATINGIU O NÚMERO %sMÁXIMO%s DE 5 SINTOMAS!                                                 %s*\n",FUNDO_VERMELHO, AMARELO, FUNDO_VERMELHO, RESET);
            printf("*                                                                                                 *\n");
            printf("***************************************************************************************************\n");
            printf("\n    Pressione %sENTER%s para ir ao RESULTADO DO DIAGNOSTICO...",AZUL,RESET);
			getchar(); //consome o ENTER que ficou do scanf anterior
            break;
        }

        //pergunta se quer continuar
        do{
            printf("*                                                                                                 *\n");
            printf("*  >> Deseja informar mais algum sintoma %s(S/N)%s?                                                   *\n",AMARELO,RESET);
            printf("*                                                                                                 *\n");
            printf("\033[2A"); 
            printf("\033[49C");
		    scanf(" %c", &resp);
		    while (getchar() != '\n'); // limpa o resto da linha (evita “21”, “33”, etc.)
		    resp = toupper(resp);
		
		    if (resp != 'S' && resp != 'N'){
		        printf("*                                                                                                 *\n");
		        printf("*%s  >> ENTRADA INVÁLIDA! Informe apenas um caractere: %sS ou N.%s                                      %s*\n",FUNDO_VERMELHO, AMARELO, FUNDO_VERMELHO, RESET);
		    }
		}while (resp != 'S' && resp != 'N');;
    }while (resp == 'S');

    return i;
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
//---------------------------------------------------- PAUSA / PARADA ------------------------------------------------------
void stop(){
    printf("\n  Pressione %sENTER%s para voltar ao menu...",AZUL,RESET);
    getchar(); //consome o ENTER que ficou do scanf anterior
    system("cls");//limpa a tela no Windows
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
    } else if (strcmp(gravidade, "MODERADO") == 0){
        printf("*    - Hidrate-se bem (água e soro caseiro).                                                      *\n");
        printf("*    - Evite exposição ao sol.                                                                    *\n");
        printf("*    - Procure posto de saúde se sintomas persistirem.                                            *\n");
    } else if (strcmp(gravidade, "GRAVE") == 0){
        printf("*    - Procure um hospital IMEDIATAMENTE.                                                         *\n");
        printf("*    - Evite automedicação.                                                                       *\n");
    }
    printf("*                                                                                                 *\n");
}
//---------------------------------------------------- DIAGNÓSTICO ------------------------------------------------------------
void diagnosticar(int sint[], int cont, char* gravidade){
	int reconhecido = 0; //0 = reconhecido 1= não reconhecid
	system("cls");//limpa a tela no Windows
	printf("***************************************************************************************************\n");
	printf("*                                                                                                 *\n");
    printf("*%s================================ RESULTADO DO DIAGNÓSTICO =======================================%s*\n",AZUL,RESET);
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
	        printf("*   %sCASO LEVE:%s                                                                                    *\n*   [FEBRE] + [DOR DE CABEÇA] >> Gripe ou virose comum.                                           *\n",VERDE,RESET);
	    }else if((sint[0]==2 && sint[1]==4)){
	        printf("*   %sCASO LEVE:%s                                                                                    *\n*   [DOR NO CORPO/JUNTAS] + [DOR DE CABEÇA] >> Cansaço físico ou virose leve.                     *\n",VERDE,RESET);
	    }else if((sint[0]==5 && sint[1]==7)){
	        printf("*   %sCASO LEVE:%s                                                                                    *\n*   [NÁUSEA/VÔMITO] + [DIARREIA] >> Intoxicação alimentar leve.                                   *\n",VERDE,RESET);
	    }else if((sint[0]==3 && sint[1]==6)){ 
	        printf("*   %sCASO LEVE:%s                                                                                    *\n*   [MANCHAS] + [INCHAÇO] >> Reação a picada ou alergia simples.                                  *\n",VERDE,RESET);																
	    }else if((sint[0]==1 && sint[1]==2)){ 
	        printf("*   %sCASO MODERADO:%s                                                                                *\n*   [FEBRE] + [DOR NO CORPO/JUNTAS] >> Suspeita de dengue, sintomas gripais ou início de          *\n*                                      infecção leve.                                             *\n",LARANJA,RESET);
	    }else if((sint[0]==1 && sint[1]==3)){
	        printf("*   %sCASO MODERADO:%s                                                                                *\n*   [FEBRE] + [MANCHAS VERMELHAS] >> Alta chance de dengue.                                       *\n",LARANJA,RESET);         
	    }else if((sint[0]==1 && sint[1]==5)){ 
	        printf("*   %sCASO MODERADO:%s                                                                                *\n*   [FEBRE] + [NÁUSEA/VÔMITO] >> Infecção viral inicial ou leptospirose.                          *\n",LARANJA,RESET);
	    }else if((sint[0]==1 && sint[1]==6)){ 
	        printf("*   %sCASO MODERADO:%s                                                                                *\n*   [FEBRE] + [INCHAÇO] >> Infecção de pele.                                                      *\n",LARANJA,RESET);
	    }else if((sint[0]==1 && sint[1]==7)){ 
	        printf("*   %sCASO MODERADO:%s                                                                                *\n*   [FEBRE] + [DIARREIA] >> Infecção intestinal ou verminose.                                     *\n",LARANJA,RESET);
	    }else{ 
	        printf("*   %sCOMBINAÇÃO NÃO RECONHECIDA%s >> Observe a evolução e procure orientação médica se necessário.   *\n",VERMELHO,RESET);	 
			reconhecido = 1;
	   	printf("*                                                                                                 *\n");		
		}
	}
	//caso 3 sintomas
	else if(cont == 3){
		qtdsint(cont);
    	
		if ((sint[0]==1 && sint[1]==2 && sint[2]==4)){ 
		    printf("*   %sCASO MODERADO:%s                                                                                *\n*   [FEBRE] + [DOR NO CORPO/JUNTAS] + [DOR DE CABEÇA] >> Início de dengue ou virose forte.        *\n",LARANJA,RESET);
		}else if ((sint[0]==1 && sint[1]==2 && sint[2]==3)){ 
		    printf("*   %sCASO MODERADO:%s                                                                                *\n*   [FEBRE] + [DOR NO CORPO/JUNTAS] + [MANCHAS] >> Dengue clássica.                               *\n",LARANJA,RESET);
		}else if ((sint[0]==1 && sint[1]==2 && sint[2]==5)){ 
		    printf("*   %sCASO MODERADO:%s                                                                                *\n*   [FEBRE] + [DOR NO CORPO/JUNTAS] + [NÁUSEA/VÔMITO] >> Leptospirose inicial.                    *\n",LARANJA,RESET);
		}else if ((sint[0]==1 && sint[1]==5 && sint[2]==7)){ 
		    printf("*   %sCASO MODERADO:%s                                                                                *\n*   [FEBRE] + [NÁUSEA/VÔMITO] + [DIARREIA] >> Infecção intestinal.                                *\n",LARANJA,RESET);
		}else if ((sint[0]==1 && sint[1]==3 && sint[2]==6)){
		    printf("*   %sCASO MODERADO:%s                                                                                *\n*   [FEBRE] + [MANCHAS] + [INCHAÇO] >> Infecção de pele.                                          *\n",LARANJA,RESET);
	    }else{ 
	        printf("*   %sCOMBINAÇÃO NÃO RECONHECIDA%s >> Observe a evolução e procure orientação médica se necessário.  *\n",VERMELHO,RESET);	 
			reconhecido = 1;
	    printf("*                                                                                                 *\n");
		}
	}
	//caso 4 sintomas
	else if (cont == 4){  
		qtdsint(cont);
		    	                                                                                                                                                                                                
	    if ((sint[0]==1 && sint[1]==2 && sint[2]==3 && sint[3]==4)){                                                                                                  
	        printf("*   %sCASO GRAVE:%s                                                                                   *\n*   [FEBRE] + [DOR NO CORPO/JUNTAS] + [MANCHAS] + [DOR DE CABEÇA] >> Dengue hemorrágica ou        *\n*                                                                    febre maculosa.              *\n",VERMELHO,RESET);
	    }else if ((sint[0]==1 && sint[1]==2 && sint[2]==3 && sint[3]==6)){
	        printf("*   %sCASO GRAVE:%s                                                                                   *\n*   [FEBRE] + [DOR NO CORPO/JUNTAS] + [MANCHAS] + [INCHAÇO] >> Leptospirose.                      *\n",VERMELHO,RESET);
	    }else if ((sint[0]==1 && sint[1]==2 && sint[2]==4 && sint[3]==5)){                                                     	                                                                                      
	        printf("*   %sCASO GRAVE:%s                                                                                   *\n*   [FEBRE] + [DOR NO CORPO/JUNTAS] + [DOR DE CABEÇA] + [NÁUSEA/VÔMITO] >> Chikungunya ou         *\n*                                                                          infecção moderada.     *\n",VERMELHO,RESET);
	    }else if ((sint[0]==1 && sint[1]==3 && sint[2]==6 && sint[3]==7)){
	        printf("*   %sCASO GRAVE:%s                                                                                   *\n*   [FEBRE] + [MANCHAS] + [INCHAÇO] + [DIARREIA] >> Infecção bacteriana generalizada.             *\n",VERMELHO,RESET);
	    }else{ 
	        printf("*   %sCOMBINAÇÃO NÃO RECONHECIDA%s >> Observe a evolução e procure orientação médica se necessário.   *\n",VERMELHO,RESET);
			reconhecido = 1;
	    printf("*                                                                                                 *\n");	
		}
	}
    //caso 5 sintomas
	else if (cont == 5){
		qtdsint(cont);
		
	    if (sint[0]==1 && sint[1]==2 && sint[2]==3 && sint[3]==4 && sint[4]==5){                                                                                                                                      
	        printf("*   %sCASO GRAVE:%s                                                                                   *\n*   [FEBRE] + [DOR NO CORPO/JUNTAS] + [MANCHAS] + [DOR DE CABEÇA] + [NÁUSEA/VÔMITO]               *\n*   >> Dengue hemorrágica.                                                                        *\n",VERMELHO,RESET);
	    }else if (sint[0]==1 && sint[1]==2 && sint[2]==3 && sint[3]==6 && sint[4]==7){
	        printf("*   %sCASO GRAVE:%s                                                                                   *\n*   [FEBRE] + [DOR NO CORPO/JUNTAS] + [MANCHAS] + [INCHAÇO] + [DIARREIA] >> Leptospirose avançada.*\n",VERMELHO,RESET);
	    }else if (sint[0]==1 && sint[1]==3 && sint[2]==4 && sint[3]==6 && sint[4]==7){                                                                                                                                   
	        printf("*   %sCASO GRAVE:%s                                                                                   *\n*   [FEBRE] + [MANCHAS] + [DOR DE CABEÇA] + [INCHAÇO] + [DIARREIA] >> Infecção bacteriana         *\n*                                                                      generalizada (sepse).      *\n",VERMELHO,RESET);
	    }else{
	        printf("*   %sCOMBINAÇÃO NÃO RECONHECIDA%s >> Observe a evolução e procure orientação médica se necessário.   *\n",VERMELHO,RESET);
	        reconhecido = 1;
	    printf("*                                                                                                 *\n");	
		}
	}
	

	printf("*                                                                                                 *\n");	
    printf("*%s=================================================================================================%s*\n",LARANJA, RESET);
    printf("*                                                                                                 *\n");
    printf("*   %sIMPORTANTE:%s                                                                                   *\n",AMARELO,RESET);
    printf("*   %s- Este diagnóstico é apenas informativo. %s                                                     *\n",AMARELO,RESET);
    printf("*   %s- Não substitui avaliação médica profissional. %s                                               *\n",AMARELO,RESET);
    printf("*   %s- Observe a evolução dos sintomas e procure atendimento médico se houver piora.%s               *\n",AMARELO,RESET);
    printf("*                                                                                                 *\n");
    printf("*%s=================================================================================================%s*\n",LARANJA, RESET);    time_t t;
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
	printf("***************************************************************************************************\n");
	stop();	
}

//--------------------------- legenda geral de gravidade --------------------------------------------------------------------------
void legendaGravidade(){
	printf("***************************************************************************************************\n");
	printf("*                                                                                                 *\n");
    printf("*  >> LEGENDA DE GRAVIDADE                                                                        *\n");
    printf("*                                                                                                 *\n");
    printf("*     - Casos %sLEVES%s: apenas observação e cuidados simples.                                        *\n",VERDE,RESET);
    printf("*     - Casos %sMODERADOS%s: possível gripe ou dengue — manter hidratação e repouso.                  *\n",LARANJA,RESET);
    printf("*     - Casos %sGRAVES%s: procurar atendimento médico imediato!                                       *\n",VERMELHO,RESET);
    printf("*                                                                                                 *\n");
	printf("***************************************************************************************************\n");
    stop();
}
//-------------------------------------------------------- MENU INTERATIVO ---------------------------------------------------
void menu(){
    int opcao;
    do {
    	printf("***************************************************************************************************\n");
	    printf("*                                                                                                 *\n");
	    printf("*%s                   SISTEMA DE TRIAGEM PARA MORADORES/ TRABALHADORES RURAIS                       %s*\n",AZUL,RESET);
	    printf("*%s                    >> Este sistema não substitui uma avaliação médica.                          %s*\n",AMARELO,RESET);
	    printf("*%s                  >> Procure um posto de saúde para avaliação se necessário.                     %s*\n",AMARELO, RESET);
	    printf("*                                                                                                 *\n");
    	printf("***************************************************************************************************\n");
    	printf("*                                             %sM %sE %sN %sU%s                                             *\n", AZUL,CIANO,AZUL,CIANO,RESET);
        printf("*-------------------------------------------------------------------------------------------------*\n");
        printf("*                                                                                                 *\n");
        printf("*  %s[1]%s Novo diagnóstico                                                                           *\n",AZUL,RESET);
        printf("*  %s[2]%s Legenda de gravidade                                                                       *\n",AZUL,RESET);
        printf("*  %s[3]%s Sair                                                                                       *\n",AZUL,RESET);
        printf("*                                                                                                 *\n");
        printf("*  *-------------*                                                                                *\n");
        printf("*  ¦ Opção:      ¦                                                                                *\n");
        printf("*  *-------------*                                                                                *\n");
        printf("*                                                                                                 *\n");
        printf("***************************************************************************************************\n");
        printf("\033[4A");
        printf("\033[14C");
        
		 if (scanf("%d", &opcao) != 1) {
		    opcao = 0;
		    while (getchar() != '\n'); // limpa tudo até o ENTER
		} else {
		    while (getchar() != '\n'); // limpa ENTER se digitou número
		}
        system("cls");
        
        if (opcao == 1){
            int sint[5], cont;
            mostrarCabecalho();
            cont = lerSintomas(sint); 
            ordenarSintomas(sint, cont);
            
			char gravidade[10];
			if (cont == 1 || cont == 2) strcpy(gravidade, "LEVE");
			else if (cont == 3) strcpy(gravidade, "MODERADO");
			else strcpy(gravidade, "GRAVE");
			
			diagnosticar(sint, cont, gravidade);

        }else if (opcao == 2){
            legendaGravidade();
        }else if (opcao != 3){
            printf("\n    %sOpção inválida!%s\n",VERMELHO,RESET);
        }
    }while (opcao != 3);
    system("cls");
    printf("\n%sEncerrando o sistema... Até mais!%s\n",VERMELHO,RESET);
}
