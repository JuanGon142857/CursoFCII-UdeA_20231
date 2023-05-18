/*Clases y Herencia.
a) Diseñe una clase llamada "Circular" con los datos para el radio del circulo en el plano xy,
la frecuencia angular de la particula que se mueve en el circulo, un pequeño intervalo
de tiempo, el tiempo total que durara el movimiento del cuerpo, el numero de intervalos
de tiempo tenidos en cuenta y una fase. Tambien deben aparecer el constructor y el de-
structor de la clase, las funciones miembros "xpos" y "ypos" que calculan las posiciones
xy dado el tiempo. Las siguientes son las ecuaciones que debe codificar para xpos y ypos:
xpos = Rcos(wt + α)
ypos = Rsin(wt + α)
b) Ahora diseñe la clase "Expiral", que sera derivada de la clase Circular, para que herede el
movimiento circular y adicione el movimiento en la direcion del eje z, de acuerdo con la
ecuacion:
z = z 0 + v z ∗ t
Nota: por favor dibuje el movimiento 3D (en el lenguaje de su preferencia).
*/

#include <vector>
#include <string>

class Circular
{
private:
    float R, w, dt, t, alpha;
    

    std::vector<float> x;
    std::vector<float> y;
    std::vector<float> xpos();
    std::vector<float> ypos();

public:

        Circular(float , float , float , float , float );
        ~Circular();

        int N;
        std::vector<float> get_xpos();
        std::vector<float> get_ypos();

        int get_N();
        float get_dt();

        void save_data(std::string);

};

class Expiral: public Circular
{
private:
    float z0, vz;
    std::vector<float> z;
    std::vector<float> zpos();

public:

    Expiral(float , float , float , float , float , float , float  );
    ~Expiral();

    std::vector<float> get_zpos();
    void save_data(std::string);

};
