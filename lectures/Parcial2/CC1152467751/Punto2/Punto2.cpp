#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

string convert_word(string word)
{
    string word_to_update;
    for (int i = 0; i < word.length(); i++)
    {
        word_to_update.push_back('X');
    }
    return word_to_update;
}

void updated_word(vector<int> indices, char letter, string &word)
{
    if (!indices.empty())
    {
        for (int i : indices)
        {
            word.at(i) = letter;
        }
    }
}

string select_word(const vector<string> palabras)
{
    srand(time(NULL));
    int indice = 0 + rand() % (palabras.size() + 0 - 1);
    return palabras[indice];
}

int main()
{
    const vector<string> PALABRAS = {"carnaval", "estupefaciente", "hospital", "universidad", "profesional", "aislar", "conversar", "existir", "manzana", "perro", "botella", "cerveza"};
    int intentos = 0;
    int adivinar_pos;
    int num_ocurrencias = 0;
    int posicion;
    string selected_word(select_word(PALABRAS));
    string updatable_word = convert_word(selected_word);
    char choice_letter;
    vector<int> indices;
    int respuesta_adivinar = 0;
    bool adivinado = false;
    int replay = 0;
    while (intentos < 7)
    {
        if (adivinado == true)
        {
            updated_word(indices, choice_letter, updatable_word);
            if (selected_word.compare(updatable_word) == 0)
            {
                cout << "Has ganado el juego, ¡Felicitaciones!" << endl
                     << endl;
                cout << "¿Quieres volver a jugar? Ingresa 1 si quieres volver a jugar o 0 si quieres salir del juego" << endl;
                try
                {
                    cin >> replay;
                    if ((replay != 1) && (replay != 0))
                    {
                        cout << "La opción es incorrecta" << endl;
                        throw replay;
                    }
                }
                catch (int replay)
                {
                    while ((replay != 1) && (replay != 0))
                    {
                        cout << "Ingrese una opción correcta. Ingrese 1 si desea hacerlo o 0 si no desea adivinar: " << endl;
                        cin >> replay;
                    }
                }
                if (replay == 1)
                {
                    cout << "Entendido, ¡El juego comenzará en breve, diviértete!" << endl;
                    intentos = 0;
                    num_ocurrencias = 0;
                    selected_word = select_word(PALABRAS);
                    updatable_word = convert_word(selected_word);
                    respuesta_adivinar = 0;
                    adivinado = false;
                    replay = 0;
                    continue;
                }
                else
                {
                    cout << "Gracias por haber jugado, ¡Hasta pronto!" << endl;
                    break;
                }
            }
            indices.clear();
            adivinado = false;
        }
        cout << "La palabra seleccionada es: " << endl
             << endl
             << updatable_word << endl
             << endl;
        cout << "Intente adivinar una letra de la palabra, recuerde que están en minúsculas: " << endl;
        cin >> choice_letter;
        if (selected_word.find((char)choice_letter) == std::string::npos)
        {
            intentos++;
            cout << "La letra que escogió no está contenida en la palabra, ha perdido un intento y le quedan " << (7 - intentos) << " vuelva a seleccionar otra letra:" << endl;
        }
        else
        {
            adivinado = true;
            cout << "La letra que escogió pertenece a la palabra ";
            num_ocurrencias = 0;
            posicion = 0;
            while ((selected_word.find(choice_letter, posicion) != std::string::npos) && (posicion < selected_word.length()))
            {
                posicion = selected_word.find(choice_letter, posicion);
                indices.push_back(posicion);
                num_ocurrencias++;
                posicion++;
            }
            cout << num_ocurrencias << " veces" << endl
                 << "¿Desea adivinar las ubicaciones? Tendrá 2 oportunidades para hacerlo" << endl
                 << "Ingrese 1 si desea hacerlo o 0 si no desea adivinar: " << endl;
            try
            {
                cin >> respuesta_adivinar;
                if ((respuesta_adivinar != 1) && (respuesta_adivinar != 0))
                {
                    cout << "El valor ingresado es incorrecto" << endl;
                    throw respuesta_adivinar;
                }
            }
            catch (int respuesta_adivinar)
            {
                while ((respuesta_adivinar != 1) && (respuesta_adivinar != 0))
                {
                    cout << "Ingrese una opción correcta. Ingrese 1 si desea hacerlo o 0 si no desea adivinar: " << endl;
                    cin >> respuesta_adivinar;
                }
            }
            while (respuesta_adivinar == 1)
            {
                cout << endl;
                cout << "Ingrese la posición en la que cree que está, la posición va desde 1 hasta la longitud de la palabra: " << endl;
                cin >> adivinar_pos;
                if (adivinar_pos > 0 && adivinar_pos < selected_word.length())
                {
                    if (num_ocurrencias == 1)
                    {
                        if (selected_word.at(adivinar_pos - 1) == choice_letter)
                        {
                            cout << "¡Es correcto!" << endl;
                            break;
                        }
                        else
                        {
                            cout << "No es correcto" << endl;
                        }
                    }
                    else
                    {
                        if (selected_word.at(adivinar_pos - 1) == choice_letter)
                        {
                            cout << "¡Es correcto!" << endl;
                        }
                        else
                        {
                            cout << "No es correcto" << endl;
                        }
                    }
                }
                cout << "¿Quiere seguir adivinando? Ingrese 1 si desea hacerlo o 0 si no desea adivinar:" << endl;
                try
                {
                    cin >> respuesta_adivinar;
                    if ((respuesta_adivinar != 1) && (respuesta_adivinar != 0))
                    {
                        cout << "La opción es incorrecta" << endl;
                        throw respuesta_adivinar;
                    }
                }
                catch (int respuesta_adivinar)
                {
                    while ((respuesta_adivinar != 1) && (respuesta_adivinar != 0))
                    {
                        cout << "Ingrese una opción correcta. Ingrese 1 si desea hacerlo o 0 si no desea adivinar: " << endl;
                        cin >> respuesta_adivinar;
                    }
                }
            }
        }
    }

    return 0;
}