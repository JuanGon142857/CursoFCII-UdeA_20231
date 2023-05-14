# est archivo es para compilar el ejemplo con la ruta:
# g++ main.cpp ../src/espiral.cpp ../src/circular.cpp

import os

os.system("g++ main.cpp ../src/espiral.cpp ../src/circular.cpp")
os.system("./a.out")

# para ver las graficas correr el notebook plotter.ipynb en la carpeta plotting