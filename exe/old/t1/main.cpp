#include <iostream>
#include <time.h>
void limparDatas(time_t *dataIni);

int main(int argc, char* argv[])
{
	int total,dia[total],mes[total],hora[total],min[total];
    //Tempo inicial e final
    time_t dataIni[total],dataFim[total];
    dataIni[total]=0; dataFim[total]=0;
    
    //Seta o tempo inicial para 25/05/2011 14:20:35
   	tm *dataIniPont=localtime(&dataIni[total]);
	tm *dataFimPont=localtime(&dataFim[total]);
   	
   							printf("\nData e hora de entrada\n");
   							
							dataIniPont->tm_year=2016-1900; //ano=2011 (é necessário subtrair 1900, pois os anos iniciam em 1900)
						    dataIniPont->tm_mon=1; //mês=maio (é necessário subtrair 1, pois os meses iniciam no zero)
						    dataIniPont->tm_mday=1; //dia=25
						    dataIniPont->tm_hour=12; //hora=14
						    dataIniPont->tm_min=1; //minuto=20
						    dataIniPont->tm_sec=0; //segundo=35
						    dataIni[total]=mktime(dataIniPont);
							
							limparDatas(&dataIni[total]);
																				
							printf("\n\n");
							
							dataFimPont->tm_year=2016-1900; //ano=2011 (é necessário subtrair 1900, pois os anos iniciam em 1900)
						    dataFimPont->tm_mon=1; //mês=maio (é necessário subtrair 1, pois os meses iniciam no zero)
						    dataFimPont->tm_mday=1; //dia=25
						    dataFimPont->tm_hour=12; //hora=14
						    dataFimPont->tm_min=2; //minuto=20
						    dataFimPont->tm_sec=0; //segundo=35
						    dataFim[total]=mktime(dataFimPont);

	//Calcula a diferença de tempo (segundos)
    double dif=difftime(dataFim[total], dataIni[total]);
    printf("%f", dif);
    
    
    
    return 0;
}

void limparDatas(int total, time_t *dataIni[total])
{
	printf("OK");
	/*
	int total;
	tm *dataIniPont=localtime(&dataIni[total]);
	  	
	   						dataIniPont->tm_year=0; //ano=2011 (é necessário subtrair 1900, pois os anos iniciam em 1900)
						    dataIniPont->tm_mon=0; //mês=maio (é necessário subtrair 1, pois os meses iniciam no zero)
						    dataIniPont->tm_mday=0; //dia=25
						    dataIniPont->tm_hour=0; //hora=14
						    dataIniPont->tm_min=0; //minuto=20
						    dataIniPont->tm_sec=0; //segundo=35
						    dataIni[total]=mktime(dataIniPont);
						    */
	
}
