#include <iostream>
#include "Matriz.cpp"
#include "Bitacora.cpp"

using namespace std;

Matriz *m = NULL;
Matriz *m2 = NULL;
Bitacora *b = NULL;


void imprimirMatriz(Matriz*);

int main()
{
	srand(time(0));
	b=new Bitacora();
	int opcion=0;
	m=new Matriz();
	while(opcion!=1 && opcion!=2)
	{
		cout<<"Matriz\n\nDesea darle tamano a la matriz?\n\n1.Si\n2.No\nSeleccion: ";
		cin>>opcion;
	}
	
	if(opcion==1)
	{
		cout<<"\n\nFilas: ";
		int f;
		cin>>f;
		cout<<"Columnas: ";
		int c;
		cin>>c;
		delete m;
		//m.~Matriz();
		m= new Matriz(f,c);
	}
	opcion=0;
	
	while(opcion!=6)
	{
		cout<<"\n\n1.Imprimir matriz\n2.Sumar\n3.Restar\n4.Multiplicar\n5.Bitacora\n6.Salir\n\nSeleccion: ";
		cin>>opcion;
		if(opcion==1)
		{
			cout<<"\n\n";
			imprimirMatriz(m);
		}
		else if(opcion==2)
		{
			int f,c;
			cout<<"Ingresar nueva matriz\n\nFilas: ";
			cin>>f;
			cout<<"Columnas: ";
			cin>>c;
			delete(m2);
			m2=new Matriz(f,c);
			cout<<"\n\nNueva Matriz: \n";
			imprimirMatriz(m2);
			if(m->suma(m2))
			{
				cout<<"\n\nMatriz resultado: \n";
				imprimirMatriz(m);
				b->addEntrada("Suma",true);
			}
			else
			{
				cout<<"\n\nLas matrices no coinciden en tamanio.";
				b->addEntrada("Suma",false);
			}
		}
		else if(opcion==3)
		{
			int f,c;
			cout<<"Ingresar nueva matriz\n\nFilas: ";
			cin>>f;
			cout<<"Columnas: ";
			cin>>c;
			delete(m2);
			m2=new Matriz(f,c);
			cout<<"\n\nNueva Matriz: \n";
			imprimirMatriz(m2);
			if(m->resta(m2))
			{
				cout<<"\n\nMatriz resultado:\n";
				imprimirMatriz(m);
				b->addEntrada("Resta",true);
			}
			else
			{
				cout<<"\n\nLas matrices no coinciden en tamanio.";
				b->addEntrada("Resta",false);
			}
			
		}
		else if(opcion==4)
		{
			int n;
			cout<<"Ingrese numero para multiplicar en la matriz: ";
			cin>>n;
			m->multiplicacion(n);
			cout<<"\n\nMatriz resultado: \n";
			imprimirMatriz(m);
			b->addEntrada("Multiplicacion",true);
		}
		else if(opcion==5)
		{
			cout<<"\n\n";
			b->imprimirTodo();
		}
	}
	
	return 0;
}

void imprimirMatriz(Matriz* _m)
{
	for(int x=0;x<_m->getFilas();x++){
		for(int y=0;y<_m->getColumnas();y++)
			cout<<_m->getValor(x,y)<<" ";
		cout<<endl;
	}
			
}


