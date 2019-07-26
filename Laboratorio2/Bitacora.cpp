#include <vector>
#include <iostream>

using namespace std;

#ifndef BITACORA_CPP
#define BITACORA_CPP

class Bitacora
{
	private:
		vector<string> s;
		vector<bool> b;
	protected:
		
	public:
		Bitacora()
		{
			s.push_back("");
			b.push_back(false);
		}
		void addEntrada(string g, bool h)
		{
			s.begin();
			b.begin();
			s.push_back(g);
			b.push_back(h);
		}
		void getEntrada(int p)
		{
			cout<<p<<". "<<s.at(p)<<": ";
			if(b.at(p))
				cout<<"Exitoso"<<endl;
			else
				cout<<"Fallido"<<endl;
			
		}
		void imprimirTodo()
		{
			if(s.size()!=1)
				for(unsigned int i=1; i<s.size();i++)
				{
					getEntrada(i);
				}
			else
				cout<<"No hay bitacora aun.";
		}
};


#endif
