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

string substring(string s, int d, int h){
   string cadena;
   for(int i = d; i < h; i++){
      cadena+=s[i];
   }
   return cadena;
}

//overload
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

//overload
int indexOf (string s, char c, int offSet){
   string chain = substring(s, offSet);
   return indexOf(chain,c)+offSet;
}

int indexOfN(string s, char c, int n){
   int p = 0;
   for (int i=0; i<n;i++){
      p = indexOf(s, c, p+1);
   }
   return p;
}

int pow (int x,int y){
   int pow=x;
   for(int i=1;i<y;i++){
      pow=pow*x;
   }
   pow=y==0?1:pow;
   return pow;
}

int charToInt(char c){

   return (int)c - 48 ;

}

int intToChar(int i){

   return '0'+i;

}

int getDigit(int n, int i){

   return (n%pow(10,i+1))/pow(10,i);

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

int stringToInt(string s){
   int b = 1;
   int num = 0;
      for(int i = 0; i < length(s); i++ ){
         num += charToInt( s[ length(s) - i -1 ] )* b;
         b*=10;

      }
   return num;
}

//overload
int stringToInt(string s, int b){

   int num = 0;
      for(int i = 0; i < length(s); i++ ){
         num += charToInt( s[ length(s) - i -1 ] )*(pow(b, i));


      }
   return num;
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

   int entero=i;
   int digitos=digitCount(i);
   double decimales=i-entero;
//   double decimalesN = decimales;
//   double decimalesEncontrados = 0;
//   int contadorDeDecimales = 1;
   string numD = "";
   string numero="";

   int d = decimales*1000000000;

   while (getDigit(d,0) == 0){
      d = d/10;
   }
   numD = intToString(d);

   for(int d=0;d<digitos;d++){
   char caracter=intToChar(getDigit(i,d));
   numero=caracter+numero;
   }

   return numero +"."+ numD;

}

double stringToDouble(string s){
   string floor;
   string integer;
   integer = substring(s, 0, indexOf(s, '.'));
   floor = substring(s, indexOf(s, '.')+1);
   return indexOf(s, '.')<1 ? stringToInt(floor) : stringToInt(integer) + ((double)stringToInt(floor)/pow(10,length(floor)));

}

bool isEmpty(string s){
   return length(s)==0 ? true : false;
}

bool contains(string s, char c){
   return indexOf(s, c)<0 ? false : true;
}

string replace(string s, char oldChar, char newChar){
   string newString;
   for(int i = 0; i < length(s); i++){
      newString += s[i]==oldChar ? newChar : oldChar;
   }

   return newString;

}

string insertAt(string s, int pos, char c){
   return substring(s, 0, pos) + c + substring(s, pos);
}

string removeAt(string s, int pos){
   return substring(s, 0, pos) + substring(s, pos+1);
}

string ltrim(string s){
   int spaces = 0;
   char n = s[spaces];
   while (n == ' '){
      spaces++;
      n = s[spaces];
   }

   return substring(s, spaces);
}

string rtrim(string s){
   int spaces = length(s);
   char n = s[spaces];
   while (n == ' '){
      spaces--;
      n = s[spaces];
   }

   return substring(s, 0, spaces);

}

string trim(string s){
   return rtrim(ltrim(s));

}

string replicate(int n, char c){
   string a;
   for(int i = 0; i < n; i++){
      a += c;
   }

   return a;
}

string lpad(string s, int n, char c){
   if(length(s) > n){
      return substring(s, 0, n);
   }else{
      return replicate(n -length(s), c) + s;
   }
}

string rpad(string s, int n, char c){
   if(length(s) > n){
      return substring(s, 0, n);
   }else{
      return s + replicate(n -length(s), c);
   }
}

string cpad(string s, int n, char c){
   if(length(s) > n){
      return substring(s, 0, n);
   }else{
      string t = lpad(s, length(s) + n/2, c);
      t = rpad(t, length(t) + n/2, c);
      return t;
   }
}

bool isDigit(char c){
   return charToInt(c)<=9 && charToInt(c)>=0 ? true : false;
}

bool isLeter(char c){
   return ( (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ) ? true : false;
}

bool isUpperCase(char c){
   return (c >= 'A' && c <= 'Z') ? true : false;
}

bool isLowerCase(char c){
   return (c >= 'a' && c <= 'z') ? true : false;
}

char toUpperCase(char c){
   return isUpperCase(c) ? c : c - 32;
}

char toLowerCase(char c){
   return isLowerCase(c) ? c : c + 32;
}
