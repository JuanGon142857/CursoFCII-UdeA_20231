#include "tarea_2.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void RecibirCadenas(string cadena1, string cadena2){

    //string c1=cadena1;
    string c2=cadena2;

    cout << "Las cadenas ingresadas son: " << endl;
    cout << "Cadena 1 : "<<cadena1 << endl;
    cout << "Cadena 2 : "<<cadena2 << endl;
    cout<<endl;

    mayor(cadena1,cadena2); 
    cout<<endl;
    
    contar_vocales(cadena1);
    
    vocales_a_mayus(cadena1);
    consonantes_a_mayus(cadena2);

    string cadena3=cadena1+cadena2;
    cout<<"La cadena concatenada es: "<<cadena3<<endl;
    cout<<endl;

    cout<<"La cadena concatenada invertida es: ";
    invertir(cadena3);
    cout<<endl;

    reemplazar(c2);


}

void mayor(string cadena1, string cadena2){
    if(cadena1>cadena2){
        cout<<"La cadena 1 es mayor que la cadena 2"<<endl;
    }
    else if(cadena1<cadena2){
        cout<<"La cadena 2 es mayor que la cadena 1"<<endl;
    }
    else{
        cout<<"Las cadenas son iguales"<<endl;
    }
}

void contar_vocales(string cadena){

    int a=0,e=0,i=0,o=0,u=0;
    for(int j=0;j<cadena.length();j++){
        if(cadena[j]=='a'){
            a++;
        }
        else if(cadena[j]=='e'){
            e++;
        }
        else if(cadena[j]=='i'){
            i++;
        }
        else if(cadena[j]=='o'){
            o++;
        }
        else if(cadena[j]=='u'){
            u++;
        }
    }
    cout<<"La frecuencia de las vocales en la cadena : "<<endl;
    cout<<cadena<<endl;
    cout<<"es: "<<endl;
    cout<<"a: "<<a<<endl;
    cout<<"e: "<<e<<endl;
    cout<<"i: "<<i<<endl;
    cout<<"o: "<<o<<endl;
    cout<<"u: "<<u<<endl;
    cout<<endl;
}

void vocales_a_mayus(string& cadena){
    string vocales="aeiou";
    cout<<"La cadena :"<<cadena<<endl;
    for(int i=0;i<cadena.length();i++){
        for(int j=0;j<vocales.length();j++){
            if(cadena[i]==vocales[j]){
                cadena[i]=toupper(cadena[i]);
            }
        }
    }
    
    cout<< "con las vocales en mayusculas es: "<<endl;
    cout<<cadena<<endl;
    cout<<endl;


}

void consonantes_a_mayus(string& cadena){

    string vocales="aeiou";
    bool es_vocal=false;

    cout<<"La cadena :"<<cadena<<endl;

    for(int i=0;i<cadena.length();i++){
        for(int j=0;j<vocales.length();j++){
            if(cadena[i]!=vocales[j]){
                es_vocal=false;
            }
            else{
                es_vocal=true;
                break;
            }
        }
        if(es_vocal==false){
            cadena[i]=toupper(cadena[i]);
        }
    }
    
    cout<< "con las consonantes en mayusculas es: "<<endl;
    cout<<cadena<<endl;
    cout<<endl;
}


void invertir(string cadena){
    for(int i=cadena.length();i>=0;i--){
        cout<<cadena[i];
    }
    cout<<endl;
}

void reemplazar(string cadena){

    cout<<"La cadena :"<<cadena<<endl;
    
    for(int i=0;i<cadena.length();i++){
        if(cadena[i]==' '||cadena[i]==','||cadena[i]=='?'||cadena[i]=='!'||cadena[i]==';'||cadena[i]==':'||cadena[i]=='-'){
            cadena[i]='.';
        }
    }
    
    cout<<"con los signos de puntuacion reemplazados por puntos es: "<<cadena<<endl;
    cout<<endl;
}


