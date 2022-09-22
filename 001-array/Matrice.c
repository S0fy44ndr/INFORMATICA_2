/*                                           *
*            Andreeva Sofya                  *
*          15/09/2022                        *
*                4^H                         *   
*          Gestione matrici                 */

//Inclusione delle librerie utili
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

//Definizione delle costanti
#define R 3
#define C 3
#define max 100
#define min 0

int menu (void);
void carica_randvet (int [], int); //Carica con numeri random un vettore
void carica_randmat (int mat[][C], int, int); //Carica la matrice
void stampa (int mat[][C],int, int); //Funzione per la stampa
void ordconriga (int mat[][C], int ,int); //Ordina riga chiesta dall'utente
void ordvettore (int vet[],int); //Ordine crescente vettore
int ricerca(int vet[],int,int); //Ricerca la riga chiesta dall'utente
int mas(int mat[][C],int, int); //Max
int mini (int mat[][C],int,int); //Min
void caricaColrandom(int mat[][C],int r,int x); //Funzioni per le colonne
void stampaCol(int mat[][C],int r,int x);
int ricercaCol(int mat[][C],int r,int x,int y); 

//Inizio programma
int main()
{
	//Dichiarazione delle variabili. m=matrice, a/b per risultati delle funzioni, r=risultato
	int m[R][C], a, b, r; 
	
	do {   
		r=menu();
		switch(r)   //Controllo scelta dell'utente
		{
			case 0: 
				printf ("Uscendo..");    //Uscita dal ciclo
			    break;
			case 1: 
				carica_randmat(m,R,C);   //Caricare random la matrice
	            break;
	        case 2: 
				stampa(m,R,C);                   //Stampa della matrice
	            break;
	        case 3: 
				printf("Inserisci la riga su cui vuoi riordinare\n");  //Riordinare una riga scelta dall'utente. Scelta riga da riordinare
	            scanf("%d",&a);                               
	            ordconriga(m,a,C);             
	            stampa(m,R,C);                    //Stampa per controllare
	            break;
	        case 4: 
				printf("Inserisci la riga su cui vuoi ricercare l'elemento\n");   //Scelta riga dove si cerca l'elemento
	            scanf("%d",&a);
	            printf("Inserisci il numero da cercare\n");                       //Scelta dell'elemento da cercare
	            scanf("%d",&b);
	            r=ricerca(m[a],R,b);                                             //Funzione di ricerca
	            printf("Nell'indice %d\n",r);                                    //Stampa dell'indice dove si trova il valore. se =-1 allora non c'è
	            break;
	        case 5: 
				r=mas(m,R,C); 					//Massimo valore nella matrice
	  	        printf("Il maggiore:%d\n",r);
	            r=mini(m,R,C),   				//Minimo valore nella matrice
	            printf("Il minore:%d\n",r);
	            break;
	        case 6: 
				printf("Inserisci la colonna su cui vuoi caricare la matrice\n");  //Scelta colonna che verrà caricata
	            scanf("%d",&a);
	            caricaColrandom(m,R,a);
	            stampa(m,R,C);
	            break;
	        case 7: 
				printf("Inserisci la colonna che vuoi stampare\n");
		        scanf("%d",&a);
		        stampaCol(m,R,a);
		        break;
		    case 8: 
				printf("Inserisci la colonna dove effettuare la ricerca e il numero da cercare\n");
		        scanf("%d%d",&a,&b);
		        r=ricercaCol(m,R,a,b);
		        printf("Il numero e' in posizione :%d\n",r);          
		        break;
		    case 9: 
				//inserimento_ordinato(m,R);
		        break;
		}
	} while (r!=0);
	
	//fine programma
	return 0;
}

int menu ()
{
	int a;
	printf ("Inserisci 1 per caricare la matrice con numeri casuali\n");
	printf ("Inserisci 2 per stampare la matrice\n");
	printf ("Inserisci 3 per ordinare una riga\n");
	printf ("Inserisci 4 per trovare un valore\n");
	printf ("Inserisci 5 per trovare il maggiore e il minore\n");
	printf ("Inserisci 6 per caricare una colonna\n");
	printf ("Inserisci 7 per stampare una colonna\n");
	printf ("Inserisci 8 per trovare un valore nella colonna\n");
	printf ("Inserisci 0 se vuoi uscire\n");
	scanf ("%d", &a);
	return a;
}

/*
	Carichiamo la matrice mat con numeri random  
*/
void carica_randmat(int mat[][C], int righe, int colonne)
{
	int i;
	for(i=0; i<colonne; i++) //scorrere tutte le colonne della matrice
	{
		carica_randvet(mat[i], colonne);
    }
}

/* 
	Carica random del vettore
*/
void carica_randvet(int vet[], int dim)
{
	int i;
	for(i=0;i<dim;i++)
	{
		vet[i]=rand()%(max-min+1)+min; //formula per inserire un certo numero rand
	}
}
void stampa (int mat[][C],int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
	 for(j=0;j<c;j++)
	 {
	 	printf("%d  ",mat[i][j]);
	 }
	 printf ("\n");
	}
}

void ordconriga (int mat[][C] ,int r ,int c)
{
	int i;
	for(i=0;i<c;i++)
	{
		ordvettore(mat[i],c);
	}
	
}

void ordvettore (int vet[],int dim)
{
	int app=0,scambio,i;
	do{
		scambio=0;
		for(i=0;i<dim-1;i++)
		{
			if(vet[i]>vet[i+1])
			{
				app=vet[i];
				vet[i]=vet[i+1];
				vet[i+1]=app;
				scambio=1;
			}
			
		}
		
	  }while(scambio==1);
	
	
}

int ricerca(int vet[],int dim,int x)
{
	int i,indice=-1;
	for(i=0;i<dim;i++)
	{
		if(vet[i]==x)	
		{
			indice=i;
		}
		
	}
	
	return indice;
}

int mas (int mat[][C],int riga,int colonne)
{
	int i,j,m=INT_MIN;
	for(i=0;i<riga;i++)
	{
		for(j=0;j<colonne;j++)
		{
			if(mat[i][j]>m)
			{
				m=mat[i][j];
			}
		}
	}
	
	return m;
}

int mini (int mat[][C],int riga,int colonne)
{
	int i,j,m=INT_MAX;
	for(i=0;i<riga;i++)
	{
		for(j=0;j<colonne;j++)
		{
			if(mat[i][j]<m)
			{
				m=mat[i][j];
			}
		}
	}
	
	return m;
}

void caricaColrandom(int mat[][C],int r,int x)
{
	int j;

		for(j=0;j<r;j++)
		{
			mat[j][x]=rand()%(max-min+1)+min;
		}	
}

void stampaCol(int mat[][C],int r, int x)
{
	int j,i;
	for(i=0;i<r;i++)
	{
		printf("%d\n",mat[i][x]);
	}
}

int ricercaCol(int mat[][C],int r,int x,int y)
{
	int i,indice=-1;
	for(i=0;i<r;i++)
	{
		if(mat[i][x]==y)
		{
			indice=i;
		}
	}
	
	return indice;
	
}

/*void inserimento_ordinato(int vet[],int r)
{
		
	int i,temp=0,j=0;

	for(i=1;i<10;i++)
	{ 
            temp=vet[i]; 
            j=i-1; 
            while(j>=0 && vet[j]>temp){
		vet[j+1]=vet[j];		
		j--;		
	}
	vet[j+1]=temp;
	}

	for(i=0;i<10;i++){
		printf("%d \t", vet[i]);
	}
		
}*/
