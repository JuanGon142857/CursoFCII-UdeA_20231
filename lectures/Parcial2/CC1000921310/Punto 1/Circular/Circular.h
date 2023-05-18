#ifndef CIRCULAR_H
#define CIRCULAR_H

class Circular{
  public:
    Circular( float = 1, float = 1, float = 1, int = 5, float = 0); // constructor predeterminado
    ~Circular();    //Destructor
    
    void Set_R( float );
    void Set_omega( float );
    void Set_tf( float );
    void Set_N( int );
    void Set_alpha( float );

    float Get_R() const;
    float Get_omega() const;
    float Get_tf() const;
    float Get_dt() const;
    int Get_N() const;
    float Get_alpha() const;
    
    float xpos( float ) const;
    float ypos( float ) const;

    void Imprimir_coor() const;

  private:
    float R;              //radio
    float omega;          //frecuencia angular
    float tf;             //tiempo total
    float dt;             //intervalo de tiempo
    int N;                //número de intervalos de tiempo tenidos en cuenta
    float alpha;          //fase inicial
};

#endif