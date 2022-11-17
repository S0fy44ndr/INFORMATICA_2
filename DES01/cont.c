/** ****************************************************************************************
* \mainpage c_conta.c
*
* @brief Conto numero caratteri, parole e righe
* 
* @author 	Andreeva Sofya
* @date 	14/11/2022 
* @version 	1.0  14/11/2022 Versione iniziale
*/

//IMPORTANTE: SCRIVI SE DOPPIO SPAZIO, SEGNI DI PUNTEGGIATURA CONTANO COME DIVISO DI PAROLE E SE IL DOPPIO SPAZIO CONTA COME UNO
//Dichiarazione librerie:
#include <stdio.h>  //fopen, printf, ...
#include <limits.h>

int main ()
{
	//Dichiarazione della stringhe per salvare il nome del file
	char nomeFileIN[]="c_testo.txt";
	//Variabili d'appoggio
	int c;
	int err, contChar=0, c2=0, contRighe=0; //contChar= caratteri, c2= parole, contRighe=righe
	//Dichiarazione dei puntatori
	FILE *fileIN;
	
	/*Apertura del file in lettura + controllo 
	che sia andato a buon fine*/
	fileIN = fopen(nomeFileIN, "r");
	if(fileIN==NULL) 
	{
		printf("\nErrore nell'apertura del fileIN");
	} 
	else
	{
		printf("\nFile aperto correttamente.");
	} 
	
	//Leggiamo tutti i caratteri fino alla fine
	//del file
	while(c=fgetc(fileIN)!=EOF)
	{
		
		printf("%c ",(char)c);
		//Considero come carettere i codici ascii
		//tra 32 (lo spazio) e 126 (~)
	    if (c>=32 && c<=126)
		{
			contChar++;
		}
		//Se troviamo un a capo significa che abbiamo una
		//nuova riga
		if (c=='\n')
		{
			contRighe++;
		}
	}
	//Controllo che il file si sia chiuso senza problemi
	err=fclose(fileIN);
	if(err!=NULL) 
	{
		printf("\nErrore nella chiusura del fileIN\n");
	} 
	
	printf ("\nI caratteri sono: %d", contChar);
	printf ("\nLe parole sono: %d", c2);
	printf ("\nLe righe sono: %d", contRighe);
	return 0;
}

		/*	switch (c)
			{
				case '\n':
					contRighe++;
					break;
				case ' ':
					c2++;
					break;
				case ',':
				case '.':
				case '!':
				case '?':
				case ':':
				case ';': 
					c2++;
					contChar++;
					break;
			}*/
