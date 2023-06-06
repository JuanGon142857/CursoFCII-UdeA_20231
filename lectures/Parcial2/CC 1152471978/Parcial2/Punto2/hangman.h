/* Para jugar al ahorcado escriba un programa . El programa debe elegir una palabra (que se
codifica diretamente en el programa) y mostrar lo siguiente:
adivine la palabra: xxxxx
cada x representa una letra. El usuario tratara de adivinar las letras en la palabra. Debera
mostrarce la respuesta apropiada (si la letra pertenece o no) despues de cada intento. Si la
letra pertenece a la palabra buscada dele la opotunidad de adivinar si el desea. Despues de
siete intentos incorrectos (ya sean palabra o letras) el usuario sera colgado.
Gane o pierda dele la opcion al usuario de jugar de nuevo.*/
#pragma once

#include <string>

class Hangman{

    public:
        Hangman();
        ~Hangman();

    private:

    std::string get_word();

    void get_letter();
    std::string save_letter();
    void check_letter();
    void right_word();
    void guess_word();
    void print_word();
    void print_hangman(int);

    void play_again();

    int errors;
    std::string letter;
    std::string word;
    std::string input_letters;

    

  





};


