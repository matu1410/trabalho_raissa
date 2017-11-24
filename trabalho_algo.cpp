#include<stdio.h>
#include<cstdlib>
#include<locale.h>
#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;



int cabecalho (){
	printf("*************************** Viação Cometa SA *************************\n", setlocale(LC_ALL, ""));
	//printf("Integrantes: xxxxxxxxx / xxxxxxxxx / xxxxxxxxxx/ xxxxxxxxx / xxxxxxxxxx/ xxxxx");
}

int finalizar(){
		//declaração de variáveis
	int matriz [6][4];
	int i, j, op, cont_GL = 0, contL = 0, cont=1, total_ass=0,total_geral=0, total_GL=0, total_L=0;
	FILE *arq;
	cabecalho (); //função que traz o cabecalho
	
	printf("* Olá, abaixo segue o relatório de suas reservas *\n");
	
	arq = fopen("Assentos.txt","r");//abre arquivo de assentos no modo de leitura
		if(arq ==  NULL){//verifica abertura do arquivo
		printf("Não foi possível carregar o arquivo, tente mais tarde ou,\n entre em contato com o administrador do sistema");
	}else{
			fflush(arq); //limpa memoria
			for(i=0; i<6; i++){ //percorre linhas da matriz
				for(j=0; j<4; j++){ //percorre colunas da matriz
					fscanf(arq, "%d", &matriz[i][j]);
		
				}
				printf("\n"); //pula linha no final do arquivo
			}
	}
	
	//estrutura que faz a contabilização dos assentos reservados
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
	//mostra para o usuário o relatório final
	total_geral = total_GL + total_L;
	total_ass = cont_GL + contL;
	printf("Você reservou um total de %d assentos \n\n", total_ass);
	printf("%d Assentos GRAND LUXE: total: R$ %d\n\n", cont_GL, total_GL);
	printf("%d Assentos LUXE: total: R$ %d\n\n", contL, total_L);
	printf("Total Geral R$ %d\n\n", total_geral);
	return 0;
}

int cancela_assento (){
	//declaração de variáveis
	int matriz [6][4];
	int i, j, op, cont = 1;
	FILE *arq;
	cabecalho (); //função que traz o cabecalho
	
	printf("* Olá, você está na página para cancelar um assento em nosso onibus *\n\n");
	printf("Escolha o assento que deseja: ");
	scanf("%d", &op);
	
	arq = fopen("Assentos.txt","r");//abre arquivo de assentos no modo de leitura
	if(arq ==  NULL){//verifica abertura do arquivo
		printf("Não foi possível carregar o arquivo, tente mais tarde ou,\n entre em contato com o administrador do sistema");
	}else{
		fflush(arq); //limpa memoria
			for(i=0; i<6; i++){ //percorre linhas da matriz
				for(j=0; j<4; j++){ //percorre colunas da matriz
					fscanf(arq, "%d", &matriz[i][j]); //insere na matriz dados lidos do arquiov
						if (matriz[i][j] == 0 && op == cont){ //condição que verifica se o assento selecionado está livre ou não
							printf("O assento que você escolheu está vazio, caso deseje reservar o mesmo, se direcionar pagina de reservas\n");
						}else if (op == cont){ //condição que verifica se o assento escolhido é a posição da matriz
							matriz[i][j] = 0; //posição recebe 0 (que indica que o assento está disponível)
							printf("O assento %d foi cancelado com sucesso\n", op); 
						}
						cont = cont + 1; //variável para contar posições da matriz
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
	//declaração de variáveis
	int matriz [6][4];
	int i, j, op, cont = 1, conf =2;
	FILE *arq;
	int livre =0, ocupado = 0; //variáveis que fará a contagem de assentos livres e ocupados
	cabecalho (); //função que traz o cabecalho
	
	printf("* Olá, você está na página para reservar um assento em nosso onibus *\n\n");
	printf("* Abaixo estão os assentos disponíveis *\n\n");
	arq = fopen("Assentos.txt", "r"); //abre arquivo de assentos no modo de leitura
	if (arq == NULL){ //verifica abertura do arquivo
		printf("Não foi possível carregar o arquivo, tente mais tarde ou,\n entre em contato com o administrador do sistema");
	}else{
		fflush(arq); //limpa memoria
			for(i=0; i<6; i++){ //estrutura de repetição para percorrer linhas da matriz
				for(j=0; j<4; j++){ //estrutura de repetição para percorrer colunas da matriz
					fscanf(arq, "%d", &matriz[i][j]); //pega linhas do arquivo e adiciona na matriz
					printf(" %d ", matriz[i][j]);
					
				}
				
				printf("\n");
			}
		fclose(arq);
		getch();

	}	
	
	while(conf != 1){
	printf("Escolha um assento: "); //pede para o usuário informar o numero do assento a ser reservado
	scanf("%d", &op);
	
	printf("Tem certeza que deseja reservar esse assento? 1 - Sim / 2 - Não\n");
	scanf("%d", &conf);	
	}
	


		for(i=0; i<6; i++){
			for(j=0;j<4;j++){
				if(matriz [i][j] == 1 && op == cont){ //condição que verifica se o assento escolhido já está reservado
				printf("Infelizmente não é possível reservar o assento %d o mesmo já se encontra reservado", op);
					}else if(op == cont){ //caso contrario, marca 1 na posição escolhida pelo cliente
							if(conf == 1){
								matriz[i][j] = 1;
								printf("Assento %d reservado com sucesso\n", op);
							}else {
								break;
							}

				}
					cont = cont + 1; //variavel para contar posições da matriz
					}
			}

	
	arq = fopen("Assentos.txt", "w"); //abre o arquivo novamente, apagando todos os dados presentes nele
		fflush (arq); //limpa memoria
			for(i=0; i<6; i++){ //estrutura de repetição para percorrer linhas da matriz
				for(j=0; j<4; j++){ //estrutura de repetição para percorrer colunas da matriz
					fprintf(arq, "%d ", matriz[i][j]); //escreve no arquivo a matriz alterada com os assentos selecionados
				}
				fprintf(arq,"\n"); //insere uma linha em branco no arquivo
		}
	
	fclose(arq); //fecha o arquivo
}

int consulta_assentos (){
	//declaração de variaveis
	int matriz [6][4];
	int g =0, i, j;
	int livre = 0, ocupado = 0; //variáveis que fará a contagem de assentos livres e ocupados
	cabecalho(); //função que traz o cabecalho
	printf("************ Mapa de assentos disponíveis do onibus!! *****************\n\n");
	
	//abertura do arquivo que contém as informações sobre os assentos
	FILE *arq = fopen("Assentos.txt", "r");
	//condição que verifica a veracidade da abertura do arquivo
	if (arq == NULL){
		printf("Não foi possível carregar o arquivo, tente mais tarde ou,\n entre em contato com o administrador do sistema");
	}else{
			
			fflush(arq);
				for (i=0; i<6; i++){ //percorre linhas da matriz
					for(j=0; j<4; j++){ //percorre colunas da matriz
						fscanf(arq, "%d", &matriz[i][j]); //pega os dados do arquivo e insere na matriz	
						printf(" %d ", matriz[i][j]); //imprime a matriz
						if (matriz[i][j] == 0) //condição que verifica assentos livres
							livre = livre + 1;
						if (matriz[i][j] == 1) //condição que verifica assentos ocupados
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
        printf("\n\tMenu de opções\n\n", setlocale(LC_ALL,""));
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

