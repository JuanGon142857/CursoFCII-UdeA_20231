#include <iostream>
#include <fstream> // flujo de archivo
#include <cstdlib>
//#include <string>
#include <iomanip>
#include <cstring>
#include <stdio.h>
#include <algorithm> 
#include <ctype.h>

using namespace std;

//Variables 
string filename1, filename2, cadena1,cadena2,cadena3,cadena4,cadena5,cadena6, cadena7;
char charsito[40];

//Funciones

string ObtenerCadena();
void EscribirArchivo(string filename), presentacion();
void comparacion(string variable1, string variable2), contar_vocales(string cadena1);
void Recibir_Cadenas(string filename1);
string mayus_vocal(string variable), mayus_conson(string variable), concat(string uno, string dos),cp_string(string variable), change_puntuacion(string varaible), invert(string variable);


int main()
{

cout<<" \n Escriba el nombre del archivo.txt que quiere abrir \n"<<endl;
getline (cin,filename1);

presentacion();
EscribirArchivo(filename1);
Recibir_Cadenas(filename1);
return 0;
}
//Esta funcion obtiene una cadena por entrada
string ObtenerCadena()
{
  cout << "\n ingresar una cadena"<< endl;
  string cadena1;
  getline( cin, cadena1 );
  cout << "\n cadena ingresada"<< endl;
  return cadena1;
}

//Esta funcion toma un archivo y escribe en el 2 lineas con espacios y simbolos
void EscribirArchivo(string filename)
{
  //Definimos un archivo de salida y lo ingresamos
  ofstream outfile;
  
  //Lo abrimos y verificamos que haya sido abierto correctamente
  outfile.open(filename);
  if (!outfile.is_open())
  {
    cerr << "failed to open " << filename << '\n';
    exit;
  }
    
    //Obtenemos 2 cadenas y las ingresamos al archivo de texto
    //cout <<"\n Empezando a escribir \n";
    cadena1= ObtenerCadena();
    //cout <<"Espere \n";
    cadena2= ObtenerCadena();
    outfile << cadena1<< endl;
    outfile << cadena2<< endl;
    outfile.close();


}
//Mensaje de bienvenida
void presentacion()
{
  cout << "\n Bienvendio al curso de Fisica computacional II \n "<<"Vamos a trabajar con string y cadenas, adicional vamos a utilizar la escritura y lectura de archivos. Para un estudio adicional de estos conceptos, revisar el cap 8 y 9 del libro c++ for engineers and scientists \n";

    /*Decir qué cadena es mayor y cuál es menor alfabéticamente
    Contar el número total de vocales en la cadena 1. Imprimir la frecuencia de cada vocal.
    Generar una nueva cadena que será la primera cadena leída, con las vocales convertidas a MAYÚSCULAS
    Generar una nueva cadena que será la segunda cadena leída, con las consonantes convertidas a MAYÚSCULAS
    Generar una nueva cadena concatenando las dos que ya fueron convertidas
    Generar una nueva cadena que contenga la cadena concatenada invertida
    Por ultimo. En la cadena2 reemplace todos los signos de puntuación con espacios.*/


}
//Funcion que comapara dos cadenas y dice cual es mayor al comparar caracteres por orden alfabetico
void comparacion(string variable1, string variable2)
{
    if (variable1.compare(variable2)==1){
        cout << "\n  la cadena 1"<<setw(10)<< " es mayor "<<setw(10)<<"la cadena 2"<< endl;}
    else if(variable1.compare(variable2)==-1){
        cout << " \n la cadena 1"<<setw(10)<< " es menor "<<setw(10)<<"la cadena 2"<< endl;
    }
    else
    {
     cout << " \n Son iguales " << endl;
    }
    
    //Comapara 2 string
    
 
}
//Funcion que cuenta vocales y me dice la frecuencia de cada uno
void contar_vocales(string variable)
{
  int freq_a=0,freq_e=0,freq_i=0,freq_o=0,freq_u=0;
  for (int i = 0; i <size(variable); i++)
  {
  char NEW=variable[i];
  //Convertir mayuscula
  //toupper

    if (NEW=='a')
    {
      freq_a+=1;
    }
    else if (NEW=='e')
    {
       freq_e+=1;
    }
    else if (NEW=='i')
    {
       freq_i+=1;
    }
    else if (NEW=='o')
    {
       freq_o+=1;
    }
    else if (NEW=='u')
    {
       freq_u+=1;
    }
    
  }
cout <<"\n \n Numero total de vocales  :"<<freq_a+freq_e+freq_i+freq_o+freq_u <<endl;
cout << "\n \n Frecuencia vocales de para la cadena : "<< variable <<": \n"<< setw( 4 )<< 'a'<< setw( 4 )<<'e'<< setw( 4 )<<'i'<< setw( 4 )<<'o'<< setw( 4 )<<'u' << setw( 10)<<endl;
cout << setw( 4 )<< freq_a<< setw( 4 )<<freq_e<< setw( 4 )<<freq_i<< setw( 4 )<<freq_o<< setw( 4 )<<freq_u  << setw( 10);
}      
//Esta funcion convierte a mayuscula las vocales
string mayus_vocal(string variable)
{
char vocal[5]={'a','e','i','o','u'};
char vocal_mayus='a';
for (int i = 0; i < size(variable); i++)
{
  for (int j = 0; j < 5; j++)
  {
    if (variable[i]==vocal[j])
    {
      vocal_mayus=vocal[j];
      variable[i]=toupper(vocal_mayus);
    }
  }
}
return variable;
}
//Esta funcion convierte a mayuscula las consonantes
string mayus_conson(string variable)
{
char vocal[5]={'a','e','i','o','u'};
char conso_mayus;
for (int i = 0; i < size(variable); i++)
{
  for (int j = 0; j < 5; j++)
  {
    if (variable[i]==vocal[0]|| variable[i]==vocal[1]||variable[i]==vocal[2] || variable[i]==vocal[3]||variable[i]==vocal[4] )
    {
        //cout<<"Vocal presente :"<<variable[i]<<" "<<vocal[j]<<"\n";

    }
    else
    {
      //cout<<"Consonante presente :"<<variable[i]<<" "<<vocal[j]<<"\n";
      conso_mayus=variable[i];
      variable[i]=toupper(conso_mayus);
    }
    
  }
}
return variable;
}
//Esta funcion concatena dos string
string concat(string uno, string dos)
{string tres;
tres = uno+dos;
return tres;
}
//Esta funcion imprime una cadena
void impre(string cadena,string cadena_name)
{
  cout<<cadena_name<<" \n \n "<<cadena<<setw(4)<<"\n"<<endl;


}
//Copia un string
string cp_string(string str)
{
  char rev[str.length()];
 
   for (int index = 0, len = str.length(); (index < len); index++) 
   {
      rev[index] = str[len-1-index];

    
    }
return rev;
}
string invert(string str){
 
   char ch;
   for (int index = 0, len = str.length(); index < len/2; index++) {
      ch = str[index];
      str[index] = str[len-1-index];
      str[len-1-index] = ch;
   }
   return str;
}
//Camabia signos de puntuacion por espacios
string change_puntuacion(string variable)
{
string punto;
for (int i = 0; i < size(variable); i++)
{

  if(ispunct(variable[i]))
  {
    variable[i]=' ';
  }
}
return variable;
}
//Funcion principal
void Recibir_Cadenas(string filename1)
{
  //Definimos un archivo de entrada y lo ingresamos
  ifstream infile;
  
  //Lo abrimos y verificamos que haya sido abierto correctamente
  infile.open(filename1);
  if (!infile.is_open())
  {
    cerr << "failed to open " << filename1 << '\n';
    exit;
  }
  

//Cadena 1 y 2 con las dos entradas por input
  getline(infile,cadena1);
  getline(infile,cadena2);
 //Cadena 3, vocales mayusculas
  cadena3=mayus_vocal(cadena1);
  //Cadena 4, consonantes mayusculas
  cadena4=mayus_conson(cadena2);
  //Cadena 5, concatenacion de 3 y 4
  cadena5=concat(cadena3,cadena4);
  //Cadena 6, copia de cadena 5;
  cadena6=string(cp_string(cadena5));
  //Invertimos cadena 6
  //reverse(cadena6.begin(),cadena6.end());
  cadena6=invert(cadena5);  //Definimos la cadena 7 como la cadena 2 remplazando sus signos de puntuacion por espacios
  cadena7=change_puntuacion(cadena2);
 
  
  //Impresion de cadenas

  impre(cadena1,"Cadena_1 original"),impre(cadena2,"Cadena_2 original "),impre(cadena3,"Cadena_3 Convertir vocal mayusculas "),impre(cadena4,"Cadena_4  Convertir consonantes mayusculas "),impre(cadena5,"Cadena_5 Concatenando "), impre(cadena6,"Cadena_6 Inviertiendo"), impre(cadena7,"Cadena_7 puntuacion fuera");



  comparacion(cadena1,cadena2);
  contar_vocales(cadena1);
 
  infile.close();
  //
  
}