/******************************************************************************************
* \mainpage 		coda.h
*
* @author 			Andreeva Sofya
* @date 			11/05/2023
* @version 1.0 		11/05/2023
*/

//Dichiarazione della classe principale
class Coda{
	private:
		int* array;		//Puntatore
		int primo;
		int ultimo;
		int num_elementi;
		int size;
	public:
		Coda (int x);	//Costruttore
		bool full ();	//Controllo se array pieno
		bool empty();	//Controllo se array vuoto
		bool push();	//Inserire nell'array
		bool pop();		//Cancellare dall'array
		int top();		//Return primo elemento che verrà servito
};
