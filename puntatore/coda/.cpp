/******************************************************************************************
* \mainpage 		coda.cpp
*
* @author 			Andreeva Sofya
* @date 			11/05/2023
* @version 1.0 		11/05/2023
*/

#include <iostream>
#include "coda.h"
using namespace std;

//Costruttore
Coda::Coda(int x){
	size=x;
	array=new int [size];
	primo=-1;
	ultimo=-1;
	num_elementi=0;
}

bool Coda::full(){
	return (num_elementi==size);
}

bool Coda::empty(){
	return (num_elementi==0);
}

bool Coda::push(){
	if (full()){
		return false;
	} else {
		int valore;
		cout<<"Inserisci fra"<<endl;
		cin>>valore;
		if (empty()) {
			primo=0;
			ultimo=0;
		} else {
			ultimo=(ultimo+1)%size;
		}
		array[ultimo]=valore;
		num_elementi++;
		return true;
	}
}
