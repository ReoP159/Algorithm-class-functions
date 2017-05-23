#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;



int length(string s){
	int c = 0;
	char a = s[0];
	while(a != '\0'){
		c++;
		a = s[c];
	}
	return c;
}	
string substring(string s, int d, int h){
	string cadena;
	for(int i = d; i < h; i++){
		cadena+=s[i];
	}
	return cadena;
}

string substring (string s,int d){
	string cadena;
	for (int i = d; i < length(s); i++){
		cadena+=s[i];
	}
	return cadena;
}

int indexOf(string s , char c){
	for(int i = 0; i < length(s); i++){
		if(s[i] == c){
			return i;
		}
	}
	return -1;
}

int indexOf (string s, char c, int offSet){
	string chain = substring(s, offSet);
	return indexOf(s, c);
}


int indexOfN(string s, char c, int n){
	int z;
	for (int i=0; i<n;i++){
		z += indexOf(s, c, z)+1;
	}
	return z;
}

int charCount(string input,char caracter){
	int c = 0;
	
	for(int i=0; i<length (input); i++)
	{
		
		if(input[i]== caracter)
		{
		c++;
		}
	}		
		return c;
	}


int pow (int x,int y){	
	int pow=x;
	for(int i=1;i<y;i++){	
		pow=pow*x;		
	}	
	pow=y==0?1:pow;	
	return pow;
}


int getDigit(int n, int i){
	
	return (n%pow(10,i+1))/pow(10,i);		
	
}

int charToInt(char c){
	
	return (int)c - 48 ; 
	
}

int intToChar(int i){
	
	return '0'+i; 
	
}

int digitCount(int i){
	
	int contador=0;
	
	while(i!=0){
		
		i=i/10;
		contador++;
		
	}
	
	return contador;
	
}

string intToString(int i){
	
	int digitos=digitCount(i);
	string numero="";
	
	for(int d=0;d<digitos;d++){
		char caracter=intToChar(getDigit(i,d));
		numero=caracter+numero;
	}
	
	return numero;

}

string charToString(char c){
	
	string s="";
	s=s+c;
	return s;
	
}

char stringToChar(string s){
	return s[0];	
}

string doubleToString(double i){
	
	int digitos=digitCount(i);
	int entero=i;
	int decimalesE;
	double decimales=i-entero;
	
	string numero="";
	
	for(int d=0;d<digitos;d++){
		char caracter=intToChar(getDigit(i,d));
		numero=caracter+numero;
	}
	
	return numero;

} 

int stringToInt(string s, int b){

	int num = 0;
		for(int i = 0; i < length(s); i++ ){
			num += charToInt( s[ length(s) - i -1 ] )*(pow(b, i)); 
			
		
		}
	return num;
}

int main(){



	return 1;
}
