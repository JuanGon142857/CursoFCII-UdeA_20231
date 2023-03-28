#include <cstdlib>
#include <ctime>
#include "parcial1_punto2.h"

int main(){
    int num ;
    srand(time(NULL));
    is_num_correct(init_num(),num = rand() % 1000 + 1);
    return 0;
}
