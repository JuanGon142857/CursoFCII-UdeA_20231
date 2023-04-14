#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void recibirCadenas(const string &, string &);

int main()
{   
    string linea1{""};
    string linea2{""};
    //Lee el txt
    ifstream texto("text.txt"); 
    //Almacenamos las lineas del txt en variables separadas
    getline(texto, linea1);
    getline(texto, linea2);
    
    cout << linea1 << endl << linea2 << endl;
    recibirCadenas(linea1, linea2);
    return 0;
}

void recibirCadenas(const string &linea1, string &linea2){
    //Compara las cadenas
    cout << "\nCOMPARACION" << endl;
    if(linea1==linea2){
        cout << "Las cadenas son iguales" << endl;
    }
    else if(linea1 > linea2){
        cout << linea1 << " > " << linea2 << endl;
    }
    else{
        cout << linea2 << " < " << linea1 << endl;
    }
    
    //Cuenta las vocales
    unsigned int a{0}, e{0}, i{0}, o{0}, u{0}; //Contadores de vocales
    for(unsigned int j = 0; j < linea1.size(); j++){
        if(linea1.at(j)=='a' || linea1.at(j)=='A'){a++;}
        if(linea1.at(j)=='e' || linea1.at(j)=='E'){e++;}
        if(linea1.at(j)=='i' || linea1.at(j)=='I'){i++;}
        if(linea1.at(j)=='o' || linea1.at(j)=='O'){o++;}
        if(linea1.at(j)=='u' || linea1.at(j)=='U'){u++;}
    }
    cout << "\n CONTEO DE VOCALES" << endl
         << "\t a = " << a << endl
         << "\t e = " << e << endl
         << "\t i = " << i << endl
         << "\t o = " << o << endl
         << "\t u = " << u << endl
         << "\t TOTAL = " << a+e+i+o+u << endl;
         
        //Vocales a mayuscula
    string vocMayus{linea1};
    for(unsigned int j = 0; j < vocMayus.size(); j++){
        if(vocMayus.at(j) == 'a' || vocMayus.at(j) == 'e' || vocMayus.at(j) == 'i' || vocMayus.at(j) == 'o' || vocMayus.at(j) == 'u')
        vocMayus.at(j) = toupper(vocMayus.at(j));
    }
    cout << "\nVOCALES EN MAYUSCULAS" << endl << vocMayus << endl;
    
    string consMayus{linea2};
    for(unsigned int j = 0; j < consMayus.size(); j++){
        if(consMayus.at(j) != 'a' && consMayus.at(j) != 'e' && consMayus.at(j) != 'i' && consMayus.at(j) != 'o' && consMayus.at(j) != 'u')
            consMayus.at(j) = toupper(consMayus.at(j));
    }
    cout << "\nCONSONANTES EN MAYUSCULAS" << endl << consMayus << endl;
    
    //Concatena las cadenas
    string lineasConcat(vocMayus + consMayus);
    cout << "\nLINEAS CONCATENADAS" << endl << lineasConcat << endl;
    
    //Invertir la cadena
    string lineaInvertida("");
    for(unsigned int j=lineasConcat.size()-1; j>0; j--)
        lineaInvertida += lineasConcat.at(j);
    lineaInvertida+=lineasConcat.at(0);
    cout << "\nLINEA CONCATENADA INVERTIDA" << endl;
    cout << lineaInvertida << endl;
    
    //Cambiar signos de puntuacion
    int c1 = linea2.find(","), c2 = linea2.find(".");
    while(c1 != string::npos){
        linea2.replace(c1, 1, " ");
        c1 = linea2.find(",", c1+1);
    }
    while(c2 != string::npos){
        linea2.replace(c2, 1, " ");
        c2 = linea2.find(".", c2+1);
    }
    
    cout << "\nCADENA SIN PUNTUACION" << endl << linea2 << endl;
}