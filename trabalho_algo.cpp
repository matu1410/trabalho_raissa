#include<stdio.h>
#include<cstdlib>
#include<locale.h>
#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;



int cabecalho (){
	printf("*************************** Via��o Cometa SA *************************\n", setlocale(LC_ALL, ""));
	//printf("Integrantes: xxxxxxxxx / xxxxxxxxx / xxxxxxxxxx/ xxxxxxxxx / xxxxxxxxxx/ xxxxx");
}

int finalizar(){
		//declara��o de vari�veis
	int matriz [6][4];
	int i, j, op, cont_GL = 0, contL = 0, cont=1, total_ass=0,total_geral=0, total_GL=0, total_L=0;
	FILE *arq;
	cabecalho (); //fun��o que traz o cabecalho
	
	printf("* Ol�, abaixo segue o relat�rio de suas reservas *\n");
	
	arq = fopen("Assentos.txt","r");//abre arquivo de assentos no modo de leitura
		if(arq ==  NULL){//verifica abertura do arquivo
		printf("N�o foi poss�vel carregar o arquivo, tente mais tarde ou,\n entre em contato com o administrador do sistema");
	}else{
			fflush(arq); //limpa memoria
			for(i=0; i<6; i++){ //percorre linhas da matriz
				for(j=0; j<4; j++){ //percorre colunas da matriz
					fscanf(arq, "%d", &matriz[i][j]);
		
				}
				printf("\n"); //pula linha no final do arquivo
			}
	}
	
	//estrutura que faz a contabiliza��o dos assentos reservados
	for (i=0;i<6;i++){
		for(j=0;j<4;j++){
			if(matriz[i][j] == 1 && cont <= 8){
				cont_GL = cont_GL + 1;
				total_GL = cont_GL * 250;
			}if(matriz[i][j] == 1 && cont > 8){
				contL = contL + 1;
				total_L = contL * 180;
			}
			cont = cont + 1;
		}
		
	}
	//mostra para o usu�rio o relat�rio final
	total_geral = total_GL + total_L;
	total_ass = cont_GL + contL;
	printf("Voc� reservou um total de %d assentos \n\n", total_ass);
	printf("%d Assentos GRAND LUXE: total: R$ %d\n\n", cont_GL, total_GL);
	printf("%d Assentos LUXE: total: R$ %d\n\n", contL, total_L);
	printf("Total Geral R$ %d\n\n", total_geral);
	return 0;
}

int cancela_assento (){
	//declara��o de vari�veis
	int matriz [6][4];
	int i, j, op, cont = 1;
	FILE *arq;
	cabecalho (); //fun��o que traz o cabecalho
	
	printf("* Ol�, voc� est� na p�gina para cancelar um assento em nosso onibus *\n\n");
	printf("Escolha o assento que deseja: ");
	scanf("%d", &op);
	
	arq = fopen("Assentos.txt","r");//abre arquivo de assentos no modo de leitura
	if(arq ==  NULL){//verifica abertura do arquivo
		printf("N�o foi poss�vel carregar o arquivo, tente mais tarde ou,\n entre em contato com o administrador do sistema");
	}else{
		fflush(arq); //limpa memoria
			for(i=0; i<6; i++){ //percorre linhas da matriz
				for(j=0; j<4; j++){ //percorre colunas da matriz
					fscanf(arq, "%d", &matriz[i][j]); //insere na matriz dados lidos do arquiov
						if (matriz[i][j] == 0 && op == cont){ //condi��o que verifica se o assento selecionado est� livre ou n�o
							printf("O assento que voc� escolheu est� vazio, caso deseje reservar o mesmo, se direcionar pagina de reservas\n");
						}else if (op == cont){ //condi��o que verifica se o assento escolhido � a posi��o da matriz
							matriz[i][j] = 0; //posi��o recebe 0 (que indica que o assento est� dispon�vel)
							printf("O assento %d foi cancelado com sucesso\n", op); 
						}
						cont = cont + 1; //vari�vel para contar posi��es da matriz
				}
				printf("\n"); //pula linha no final do arquivo
			}
			fclose(arq); //fecha o arquivo
			getch();
	}
	
	arq = fopen("Assentos.txt","w"); //abre o arquivo novamente, agora limpando todos os dados anteriormente presentes nele
		fflush (arq); //limpa memoria
			for(i=0; i<6; i++){ //percorre linhas da matriz
				for(j=0; j<4; j++){ //percorre colunas da matriz
					fprintf(arq, "%d ", matriz [i][j]); //escreve no arquivo os dados da matriz
				}
					fprintf(arq, "\n"); //pula linha no arquivo
			}
			fclose(arq); //fecha o arquivo
			getch();
}

int reserva_assento (){
	//declara��o de vari�veis
	int matriz [6][4];
	int i, j, op, cont = 1, conf =2;
	FILE *arq;
	int livre =0, ocupado = 0; //vari�veis que far� a contagem de assentos livres e ocupados
	cabecalho (); //fun��o que traz o cabecalho
	
	printf("* Ol�, voc� est� na p�gina para reservar um assento em nosso onibus *\n\n");
	printf("* Abaixo est�o os assentos dispon�veis *\n\n");
	arq = fopen("Assentos.txt", "r"); //abre arquivo de assentos no modo de leitura
	if (arq == NULL){ //verifica abertura do arquivo
		printf("N�o foi poss�vel carregar o arquivo, tente mais tarde ou,\n entre em contato com o administrador do sistema");
	}else{
		fflush(arq); //limpa memoria
			for(i=0; i<6; i++){ //estrutura de repeti��o para percorrer linhas da matriz
				for(j=0; j<4; j++){ //estrutura de repeti��o para percorrer colunas da matriz
					fscanf(arq, "%d", &matriz[i][j]); //pega linhas do arquivo e adiciona na matriz
					printf(" %d ", matriz[i][j]);
					
				}
				
				printf("\n");
			}
		fclose(arq);
		getch();

	}	
	
	while(conf != 1){
	printf("Escolha um assento: "); //pede para o usu�rio informar o numero do assento a ser reservado
	scanf("%d", &op);
	
	printf("Tem certeza que deseja reservar esse assento? 1 - Sim / 2 - N�o\n");
	scanf("%d", &conf);	
	}
	


		for(i=0; i<6; i++){
			for(j=0;j<4;j++){
				if(matriz [i][j] == 1 && op == cont){ //condi��o que verifica se o assento escolhido j� est� reservado
				printf("Infelizmente n�o � poss�vel reservar o assento %d o mesmo j� se encontra reservado", op);
					}else if(op == cont){ //caso contrario, marca 1 na posi��o escolhida pelo cliente
							if(conf == 1){
								matriz[i][j] = 1;
								printf("Assento %d reservado com sucesso\n", op);
							}else {
								break;
							}

				}
					cont = cont + 1; //variavel para contar posi��es da matriz
					}
			}

	
	arq = fopen("Assentos.txt", "w"); //abre o arquivo novamente, apagando todos os dados presentes nele
		fflush (arq); //limpa memoria
			for(i=0; i<6; i++){ //estrutura de repeti��o para percorrer linhas da matriz
				for(j=0; j<4; j++){ //estrutura de repeti��o para percorrer colunas da matriz
					fprintf(arq, "%d ", matriz[i][j]); //escreve no arquivo a matriz alterada com os assentos selecionados
				}
				fprintf(arq,"\n"); //insere uma linha em branco no arquivo
		}
	
	fclose(arq); //fecha o arquivo
}

int consulta_assentos (){
	//declara��o de variaveis
	int matriz [6][4];
	int g =0, i, j;
	int livre = 0, ocupado = 0; //vari�veis que far� a contagem de assentos livres e ocupados
	cabecalho(); //fun��o que traz o cabecalho
	printf("************ Mapa de assentos dispon�veis do onibus!! *****************\n\n");
	
	//abertura do arquivo que cont�m as informa��es sobre os assentos
	FILE *arq = fopen("Assentos.txt", "r");
	//condi��o que verifica a veracidade da abertura do arquivo
	if (arq == NULL){
		printf("N�o foi poss�vel carregar o arquivo, tente mais tarde ou,\n entre em contato com o administrador do sistema");
	}else{
			
			fflush(arq);
				for (i=0; i<6; i++){ //percorre linhas da matriz
					for(j=0; j<4; j++){ //percorre colunas da matriz
						fscanf(arq, "%d", &matriz[i][j]); //pega os dados do arquivo e insere na matriz	
						printf(" %d ", matriz[i][j]); //imprime a matriz
						if (matriz[i][j] == 0) //condi��o que verifica assentos livres
							livre = livre + 1;
						if (matriz[i][j] == 1) //condi��o que verifica assentos ocupados
							ocupado = ocupado + 1;
						//g += matriz [i][j];
						
					}	
					printf("\n");
				}
				fclose(arq); //fecha arquiv9
				printf("\n");
				printf("Atualmente o onibus possui: %d assentos livres e %d assentos ocupados\n\n" , livre, ocupado); //mensagem que mostra quantidade de assentos
				printf("Legenda:\n 0 (assentos livres)\n 1 (assentos ocupados)\n");
			getch();
			return (0);
	}

	
}


int main()
{
    int continuar=1;

    do
    {
        printf("\n\tMenu de op��es\n\n", setlocale(LC_ALL,""));
        printf("1. Consultar assentos\n"); //ok
        printf("2. Reservar assento\n"); //ok
        printf("3. Cancelar reserva\n"); //ok
        printf("4. Finalizar\n");

        scanf("%d", &continuar);
        system("cls || clear");

        switch(continuar)
        {
            case 1:
                consulta_assentos();
                break;

            case 2:
                reserva_assento();
                break;

            case 3:
                cancela_assento();
                break;
            case 4:
            	finalizar();
                break;

            default:
                printf("Digite uma opcao valida\n");
        }
    } while(continuar);
}

