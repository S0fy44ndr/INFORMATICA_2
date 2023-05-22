//Dichiaazione della classe principale
class adt {
	//Attributi privati
	private:
		int *p;
		int size;
    int end;
	
	public:
		//Metodi costruttori
	  adt(int x);
		//Metodi
  bool IsFull();
  bool IsEmpty();
  int GetFine();
  int GetInizio();
  int SommaElementi();
  int Trova(int);
  bool InserisciInPosizione(int, int);
  bool CancellaInPosizione(int);
};
//Creazione della sottoclasse 1
class Coda:public adt{
	//Defenizione metodi
	public:
		Coda(int);
		bool InserciCoda(int);
		bool CancellaCoda();
};
//Creazione della sottoclasse 2
class Pila:public adt{
  private:
    int numIns;
    int numCanc;
  public:
  Pila(int)
  bool InserisciPila (int);
  bool CancellaPila ();
};
