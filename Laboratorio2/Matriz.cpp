#include <iostream>
#include <ctime>
#include <cstdlib>

#ifndef MATRIZ_CPP
#define MATRIZ_CPP

using namespace std;

class Matriz
{
	private:
		int ** matriz;
		int columnas;
		int filas;
	
	protected:
		
	public:
		Matriz()
		{
			columnas=5;
			filas=5;
			matriz=new int*[5];
			for(int x=0;x<5;x++)
			{
				matriz[x]=new int[5];
			}
			llenarMatriz(5,5);
		}
		Matriz(int f, int c)
		{
			filas=f;
			columnas=c;
			matriz=new int*[f];
			for(int x=0;x<f;x++)
			{
				matriz[x]=new int[c];
			}
			llenarMatriz(f,c);
		}
		int getValor(int f, int c)
		{
			return matriz[f][c];
		}
		void setFilas(int f)
		{
			filas=f;
		}
		void setColumnas(int c)
		{
			columnas=c;
		}
		int getFilas()
		{
			return filas;
		}
		int getColumnas()
		{
			return columnas;
		}
		void llenarMatriz(int f, int c)
		{
			for(int x=0;x<f;x++)
				for(int y=0;y<c;y++)
				{
					int r = (rand() % 10) + 1;
					matriz[x][y]=r;
				}
		}
		bool suma(Matriz *_matriz)
		{
			if(_matriz->getFilas()==filas && _matriz->getColumnas()==columnas)
			{
				for(int x=0;x<filas;x++)
					for(int y=0;y<columnas;y++)
						matriz[x][y]=matriz[x][y]+_matriz->getValor(x,y);
				
				return true;
			}
			else
				return false;
		}
		bool resta(Matriz *_matriz)
		{
			if(_matriz->getFilas()==filas && _matriz->getColumnas()==columnas)
			{
				for(int x=0;x<filas;x++)
					for(int y=0;y<columnas;y++)
						matriz[x][y]=matriz[x][y]-_matriz->getValor(x,y);
				return true;
			}
			else
				return false;
		}
		void multiplicacion(int n)
		{
			for(int x=0;x<filas;x++)
				for(int y=0;y<columnas;y++)
					matriz[x][y]=matriz[x][y]*n;
		}
		
		~Matriz(){}
		
		
};

#endif
