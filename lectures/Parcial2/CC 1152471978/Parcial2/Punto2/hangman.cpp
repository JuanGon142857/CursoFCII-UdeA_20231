#include "hangman.h"
#include <fstream>
#include <iostream>
#include <ostream>
//#include <boost/algorithm/string.hpp>


Hangman::Hangman()
{
    errors = 0;
    std::string input_letters="";
    std::string letter="";

    word = get_word();

    std::cout << "La palabra es : ";
    for (char letra : word){std::cout << "x";}
    std::cout << std::endl<<std::endl;

    check_letter();
    
}

Hangman::~Hangman()
{
}

//sacar la palabra del archivo
std::string Hangman::get_word()
{
    std::ifstream file("words_source.dat");
    if( file.fail() )
    {
        std::cerr << "Error: no se pudo abrir el archivo" << std::endl;
        exit(1);
    }

    int n = 0;
    int min = 1;
    int max = 503;

    int random = min + (std::rand() % (max - min + 1)); //elige una palabra al azar
    while (file >> word)
    {
        n++;
        if (n == random){return word;}
    }
    return word;
}

// recive una palabra del user
void Hangman::get_letter()
{
    std::string letra;
    std::cout << "Ingrese una letra: ";
    std::cin >> letra;

    // comporbar que no ingrese mas de una letra, ñ se cuenta como dos caracteres
    if (letra.length() > 1)
    {
        if (letra=="ñ"){letter = letra;}
        else
        {
            std::cout << "Ingrese solo una letra" << std::endl;
            get_letter();
        }
    }

    else{letter = letra;}
}

// juntar todas las letras ingresadas
std::string Hangman::save_letter()
{
    input_letters += letter;

    std::cout << "Letras ingresadas: " << input_letters << std::endl;
    return input_letters;
}

// revisa si ya se adivinaron todas las letras
void Hangman::right_word()
{
    bool win = true;
    for (char letra : word){

        if (input_letters.find(letra) != std::string::npos){win = true;}

        else
        {
            win = false;
            break;
        }
    }
    if (win)
    {   
        std::cout << "La palabra era: "<<std::endl;
        std::cout <<"*** " <<word <<" ***"<< std::endl;
        std::cout << std::endl;
        std::cout << "Ganaste, yei!" << std::endl;

        play_again();
    }
}

// imprime la palabra a cada paso del juego
void Hangman::print_word()
{
    std::cout<<"La palabra es: ";
    for (char letra : word){

        if (input_letters.find(letra) != std::string::npos){std::cout << letra;}

        else{std::cout << " _";}
    }
    std::cout<<std::endl;
 }

// adivinar la palabra
void Hangman::guess_word()
{
    std::string guess;
    std::cout << "Introduzca la palabra: ";
    std::cin >> guess;

    if (guess == word)
    {
        std::cout << "Ganaste, yei!" << std::endl;
        play_again();
    }
    else
    {   
        std::cout << "Bu! Esa no era. Una vida menos, por pendejo!" << std::endl<<std::endl;
        errors++;
        check_letter();
    }
}

 // si se quiere jugar otra vez
void Hangman::play_again()
{
    std::string answer;
    std::cout << "Desea jugar de nuevo? (y/n): ";
    std::cin >> answer;

    if (answer == "y"){Hangman();}

    else
    {
        std::cout << "Gracias por jugar" << std::endl;
        exit(0);
    }
}

//revisar si la letra está en la palabra
void Hangman::check_letter(){

    get_letter();
    save_letter();
    print_word();
    std::cout<<std::endl<<std::endl;

    if (word.find(letter) != std::string::npos)
    {
        std::cout << "La letra " << letter << " está en la palabra" << std::endl;

        right_word();

        std::cout << "Desea adivinar la palabra? (y/n): ";
        std::string answer;
    
        std::getline(std::cin >> std::ws, answer);

        if (answer == "y"){guess_word();}
        else {check_letter();}

        
    }
    else
    {
        std::cout << "La letra " << letter << " no esta en la palabra" << std::endl;
        errors++;

        if (errors == 7)
        {
            std::cout << "Perdiste el juego y la vida" << std::endl;
            std::cout << "La palabra era: "<<std::endl;
            std::cout <<"*** " <<word <<" ***"<< std::endl;
            play_again();
        }
        else
        {
            print_hangman(errors);
            std::cout << " Te quedan " << 7 - errors << " vidas" << std::endl<<std::endl<<std::endl;
            check_letter();
            
        }

    }

}


void Hangman::print_hangman(int errors)
{
    if (errors == 0)
    {
            std::cout << "------AHORCADO------" << std::endl;
            std::cout << " |                |" << std::endl;
            std::cout << " |                |" << std::endl;
            std::cout << " |                |" << std::endl;
            std::cout << " |                |" << std::endl;
            std::cout << " |                |" << std::endl;
            std::cout << "_|_" << std::endl;
            std::cout << "---------------------" << std::endl;}

     if (errors == 1)
    {       std::cout << "------AHORCADO------" << std::endl;
            std::cout << " |                |" << std::endl;
            std::cout << " |                O" << std::endl;
            std::cout << " |                 " << std::endl;
            std::cout << " |                 " << std::endl;
            std::cout << " |                 " << std::endl;
            std::cout << "_|_" << std::endl;
            std::cout << "---------------------" << std::endl;}

    if (errors==2)
    {
            std::cout << "------AHORCADO------" << std::endl;
            std::cout << " |                |" << std::endl;
            std::cout << " |                O" << std::endl;
            std::cout << " |                |" << std::endl;
            std::cout << " |                 " << std::endl;
            std::cout << " |                 " << std::endl;
            std::cout << "_|_" << std::endl;
            std::cout << "---------------------" << std::endl;}

    if (errors==3)
    {       std::cout << "------AHORCADO------" << std::endl;
            std::cout << " |                |" << std::endl;
            std::cout << " |                O" << std::endl;
            std::cout << " |                |" << std::endl;
            std::cout << " |                |" << std::endl;
            std::cout << " |                 " << std::endl;
            std::cout << "_|_" << std::endl;
            std::cout << "---------------------" << std::endl;}
    if (errors==4)
    {      std::cout << "------AHORCADO------" << std::endl;
            std::cout << " |                |" << std::endl;
            std::cout << " |                O" << std::endl;
            std::cout << " |               /|" << std::endl;
            std::cout << " |                |" << std::endl;
            std::cout << " |                 " << std::endl;
            std::cout << "_|_" << std::endl;
            std::cout << "---------------------" << std::endl;}
    
    if (errors==5)
    {       std::cout << "------AHORCADO------" << std::endl;
            std::cout << " |                |" << std::endl;
            std::cout << " |                O" << std::endl;
            std::cout << " |               /|\\" << std::endl;
            std::cout << " |                |" << std::endl;
            std::cout << " |                 " << std::endl;
            std::cout << "_|_" << std::endl;
            std::cout << "---------------------" << std::endl;}
    
    if (errors==6)
    {       std::cout << "------AHORCADO------" << std::endl;
            std::cout << " |                |" << std::endl;
            std::cout << " |                O" << std::endl;
            std::cout << " |               /|\\" << std::endl;
            std::cout << " |                |" << std::endl;
            std::cout << " |               / " << std::endl;
            std::cout << "_|_" << std::endl;
            std::cout << "---------------------" << std::endl;}
    
    if (errors==7)
    {       std::cout << "------AHORCADO------" << std::endl;
            std::cout << " |                |" << std::endl;
            std::cout << " |                O" << std::endl;
            std::cout << " |               /|\\" << std::endl;
            std::cout << " |                |" << std::endl;
            std::cout << " |               / \\" << std::endl;
            std::cout << "_|_" << std::endl;
            std::cout << "---------------------" << std::endl;}
    
}


