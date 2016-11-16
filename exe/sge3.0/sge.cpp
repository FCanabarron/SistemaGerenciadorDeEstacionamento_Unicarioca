#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <float.h>

void limparVagas(int *vaga, int *num);
void converterTempo(double diffTemp, int *hr, int *min, int *seg);
void limparVaga(int *vaga, int *num);

int main()
{
	int user;
	user=0;
	int num,vaga[51],opcao;
	int diaS[user],mesS[user],horaS[user],minS[user];
	int hr,min,seg,preco;
	int i,count;
	char placa[user][8], cor[user][16], modelo[user][16];
	float vhr,vmin,vt;
	//ctime
	time_t dataIni[user], dataFim[user];
	tm *dataFimPnt=localtime(&dataFim[user]); //seta
	double diffTemp;
	struct tm *dataIniPnt;
	//ctime

	
	
						
	limparVagas(vaga, &num);
	
	do
	{
	
		printf ("\n\n\t823 - INTRODUCAO A PROGRAMACAO 2016/2\n");
		printf ("\t2016200484 - Lucas Moreira Peres Barga\n");
		printf ("\tSistema Gerenciador de Estacionamento\n");
		
		printf ("\nValores: \n");
		printf ("Para uma hora sera cobrado: R$ 15,00\n");
		printf ("Para cada 30 min sera cobrado: R$ 7,50\n");
		printf ("Para cada 01 min sera cobrado: R$ 0,25\n");
		
		printf ("\nMenu: \n");
		printf ("1- Entrada veiculo\n");
		printf ("2- Saida veiculo\n");
		printf ("3- Relacao veiculos\n");
		printf ("0- Sair do programa\n");
		
		printf("\nOpcao: ");
		scanf("%d",&opcao);
		
		switch(opcao)
		{
			case 1:
				//ENTRADA
				printf("\n Numero da vaga (1~50): ");
				scanf ("%d", &num);
				user=num;
				
				if(num<=50)
				{
					if(vaga[num] == 0)
					{
						
						printf("\n Vaga Disponivel!\n");
						
						printf("\nInformacoes do veiculo\n");
						printf("Placa:");
						scanf("%s", &placa[user]);
						printf("Cor:");
						scanf("%s", &cor[user]);
						printf("Modelo:");
						scanf("%s", &modelo[user]);
						
						time(&dataIni[user]);
						dataIniPnt = localtime(&dataIni[user]);
						
						printf("\n\tEntrada: %2d/%2d/%4d - %2d:%2d:%2d \n\n",dataIniPnt->tm_mday, dataIniPnt->tm_mon+1,dataIniPnt->tm_year+1900, dataIniPnt->tm_hour, dataIniPnt->tm_min, dataIniPnt->tm_sec);
						
						vaga[num]=num; //ATIVA_VAGA
						
					}
					else
					{
						printf("\n\nVaga ocupada, escolha outra vaga.\n\n");
					}
				}
				else
				{
					printf("\n\nVaga nao existente!\n\n");
				}
			
			system("pause");
			system("cls");	
			break;
			
			case 2:
				//SAIDA
				printf("\nNumero da vaga (1~50): ");
				scanf ("%d", &num);
				user=num;
				
				if(num<=50)
				{
					if(vaga[num] != 0)
					{
					
						printf("\nData e hora de saida\n");
						printf("Dia:");
						scanf("%d", &diaS[user]);
						printf("Mes:");
						scanf("%d", &mesS[user]);
						printf("Horas:");
						scanf("%d", &horaS[user]);
						printf("Minutos:");
						scanf("%d", &minS[user]);
						
						//atribui valores - dataFim
						dataFimPnt->tm_year=2016-1900; //ano=2016 (é necessário subtrair 1900, pois os anos iniciam em 1900)
						dataFimPnt->tm_mon=mesS[user]-1; //mês=maio (é necessário subtrair 1, pois os meses iniciam no zero)
						dataFimPnt->tm_mday=diaS[user]; //
						dataFimPnt->tm_hour=horaS[user]; //
						dataFimPnt->tm_min=minS[user]; //
						dataFimPnt->tm_sec=0; //printf("\year - %d",ty);
						dataFim[user]=mktime(dataFimPnt); //salva os valores
					
						//calcula diferenca
						diffTemp = difftime(dataFim[user], dataIni[user]);
						converterTempo(diffTemp, &hr, &min, &seg);
						
						vhr = hr * 15;
						vmin = min * 0.25;
						vt = vhr+vmin;
						
						printf("\nO veiculo ficou alocado por: %dH : %dM :%dS \n",hr,min,seg);
						printf("\nO VALOR A SER PAGO E: R$%.2f\n",vt); // IMPRESSÃO DO PRECO
						
						vaga[num]=0;//DESATIVA_VAGA
					}
					else
					{
						printf("\n\nVaga vazia!\n\n");
					}
					
				}
				else
				{
					printf("\n\nVaga nao existente!\n\n");
				}
				
				system("pause");
				system("cls");
				break;
				
				case 3:
					// RELACAO
					printf("|------------RELACAO DE VEICULOS ALOCADOS------------|\n");
					printf("| Vaga | Placa | Cor | Modelo | Data de Entrada\n");
					count=0;
					
					for (i = 1; i <=50 ;i++)
					{
						if(vaga[i] != 0)
						{
							//time(&dataIni[user]);
							dataIniPnt = localtime(&dataIni[i]);
						
							printf("|  %d  |  %s  |  %s  |  %s  | %2d/%2d/%4d - %2d:%2d:%2d | \n",vaga[i],placa[i],cor[i],modelo[i],dataIniPnt->tm_mday, dataIniPnt->tm_mon+1,dataIniPnt->tm_year+1900, dataIniPnt->tm_hour, dataIniPnt->tm_min, dataIniPnt->tm_sec);
						    count++;
						}						
					}
					
					printf("|----------------------------------------------------|\n ");
					printf(" TOTAL DE CARROS => %d \n\n",count);
					
				system("pause");
				system("cls");
				break;
			
				default:
					if(opcao==0)
					{
					   	printf("Programa encerrdo com sucesso.\n");	
					}
					else
					{
						printf("Codigo Inexistente.\n");
						system("pause");
						system("cls");
					}
		}
	}
	while(opcao!=0);
	
return 0;

}

void limparVagas(int *vaga, int *num)
{	
	for (*num = 1; *num <= 50;*num=*num+1)
	{
		vaga[*num] = 0;;
	}
}

void converterTempo(double diffTemp, int *hr, int *min, int *seg)
{
	*hr = (diffTemp/3600);
	*min = (diffTemp -(3600* *hr))/60;
	*seg = (diffTemp -(3600 * *hr)-(*min * 60));
}
