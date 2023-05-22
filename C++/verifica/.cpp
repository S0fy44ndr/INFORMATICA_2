#include <iostream>
#include ".h"

using namespace std;

adt::adt (int x)
{
  size=x;
  p=new int [size];
  end= -1;
}

bool adt::IsFull() {
  return (end==size);
}

bool adt::IsEmpty () {
  return (end==-1);
}

int adt::GetFine () {
  if (end!=-1)
  {return p[end];}
  return end;
} 

int adt:: GetInizio (){
  if (IsEmpty())
  {return -1}
  return p[0];
}

