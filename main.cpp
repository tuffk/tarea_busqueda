#include <cstdlib>
#include <sstream>
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

int funcion(string c,ifstream &a){ 
	int o=0,p=1;
	string l; 
		
	while(getline(a,l)){ 
		if(l.find(c)!=string::npos){ 
			cout<<"Cadena encontrada en la linea "<<p<<endl; 
			o++;
		} 
		p++;
	} 
	a.close(); 
	return o;
} 

int main() { 
	char nom[30],ar[50];
	int cantidad;
	string cadena; 

	cout<<"Ingrese el nombre del archivo: "; 
	cin>>nom; 
	cout<<"Ingrese la cadena a buscar: "; 
	cin>>cadena; 
	
	strcpy(ar,"C:\\");
	strcat(ar,nom); 
	strcat(ar,".txt"); 
	ifstream archi(ar); 
	
	if(!archi.is_open()) 
		cout<<"El archivo no existe.\n"; 
	else{ 
		cantidad=funcion(cadena,archi); 
		if(cantidad) 
			cout<<"Cantidad de ocurrencias: "<<cantidad<<endl; 
		else 
			cout<<"Cadena no encontrada.\n";
	} 
	system("pause"); 
	return 0;
}