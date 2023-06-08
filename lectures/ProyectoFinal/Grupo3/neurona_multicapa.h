#ifndef NEURONA_MULTICAPA_H
#define NEURONA_MULTICAPA_H

#include <iostream>
#include <cmath>

class neurona_multicapa {
private:
    int capaEntrada;                   // Tamaño de la capa de entrada
    int capaOculta;                  // Tamaño de la capa oculta
    int capaSalida;                  // Tamaño de la capa de salida
    double** pesosiniciales;     // Pesos entre la capa de entrada y la capa oculta
    double** pesosfinales;    // Pesos entre la capa oculta y la capa de salida

public:
    neurona_multicapa(int capaEntrada, int capaOculta, int capaSalida) {
        this->capaEntrada = capaEntrada;
        this->capaOculta = capaOculta;
        this->capaSalida = capaSalida;

        // Inicialización de los pesos entre la capa de entrada y la capa oculta
        pesosiniciales = new double*[capaOculta];
        for (int i = 0; i < capaOculta; i++) {
            pesosiniciales[i] = new double[capaEntrada + 1];
            for (int j = 0; j <= capaEntrada; j++) {
                pesosiniciales[i][j] = getpesoaleatorio();  // Asignar pesos aleatorios
            }
        }

        // Inicialización de los pesos entre la capa oculta y la capa de salida
        pesosfinales = new double*[capaSalida];
        for (int i = 0; i < capaSalida; i++) {
            pesosfinales[i] = new double[capaOculta + 1];
            for (int j = 0; j <= capaOculta; j++) {
                pesosfinales[i][j] = getpesoaleatorio(); // Asignar pesos aleatorios
            }
        }
    }

    ~neurona_multicapa() {
        // Liberar la memoria utilizada por los pesos
        for (int i = 0; i < capaOculta; i++) {
            delete[] pesosiniciales[i];
        }
        delete[] pesosiniciales;

        for (int i = 0; i < capaSalida; i++) {
            delete[] pesosfinales[i];
        }
        delete[] pesosfinales;
    }

    double sigmoide(double z) {
        return 1.0 / (1.0 + exp(-z));  // Función de activación sigmoidee
    }

    double sigmoide_derivada(double z) {
        double sigmoideZ = sigmoide(z);
        return sigmoideZ * (1.0 - sigmoideZ);  // Derivada de la función de activación sigmoide
    }

    double getpesoaleatorio() {
        return ((double)rand() / RAND_MAX) * 2.0 - 1.0;  // Generar un peso aleatorio en el rango [-1, 1]
    }

    void entrenamiento(double** X, double** y, double eta, int epocas, int tam_entrenamiento) {
        for (int epoca = 0; epoca < epocas; epoca++) {
            for (int i = 0; i < tam_entrenamiento; i++) {
                // Forward propagation

                // Calcular la entrada de la capa oculta
                double* int_capaOculta = new double[capaOculta];
                for (int j = 0; j < capaOculta; j++) {
                    int_capaOculta[j] = 0.0;
                    for (int k = 0; k <= capaEntrada; k++) {
                        int_capaOculta[j] += X[i][k] * pesosiniciales[j][k];
                    }
                }

                // Aplicar la función de activación a la capa oculta
                double* out_capaOculta = new double[capaOculta];
                for (int j = 0; j < capaOculta; j++) {
                    out_capaOculta[j] = sigmoide(int_capaOculta[j]);
                }

                // Calcular la entrada de la capa de salida
                double* int_capaSalida = new double[capaSalida];
                for (int j = 0; j < capaSalida; j++) {
                    int_capaSalida[j] = 0.0;
                    for (int k = 0; k <= capaOculta; k++) {
                        int_capaSalida[j] += out_capaOculta[k] * pesosfinales[j][k];
                    }
                }

                // Aplicar la función de activación a la capa de salida
                double* out_capaSalida = new double[capaSalida];
                for (int j = 0; j < capaSalida; j++) {
                    out_capaSalida[j] = sigmoide(int_capaSalida[j]);
                }

                // Backpropagation

                // Calcular el error en la capa de salida
                double* error_capaSalida = new double[capaSalida];
                for (int j = 0; j < capaSalida; j++) {
                    error_capaSalida[j] = out_capaSalida[j] - y[i][j];
                }

                // Calcular el error en la capa oculta
                double* error_capaOculta = new double[capaOculta];
                for (int j = 0; j < capaOculta; j++) {
                    error_capaOculta[j] = 0.0;
                    for (int k = 0; k < capaSalida; k++) {
                        error_capaOculta[j] += error_capaSalida[k] * pesosfinales[k][j];
                    }
                    error_capaOculta[j] *= sigmoide_derivada(int_capaOculta[j]);
                }

                // gradiente descendente

                // Actualizar los pesos entre la capa oculta y la capa de salida
                for (int j = 0; j < capaSalida; j++) {
                    for (int k = 0; k <= capaOculta; k++) {
                        pesosfinales[j][k] -= eta * error_capaSalida[j] * out_capaOculta[k];
                    }
                }

                // Actualizar los pesos entre la capa de entrada y la capa oculta
                for (int j = 0; j < capaOculta; j++) {
                    for (int k = 0; k <= capaEntrada; k++) {
                        pesosiniciales[j][k] -= eta * error_capaOculta[j] * X[i][k];
                    }
                }

                // Liberar la memoria utilizada por las capas de la red neuronal
                delete[] int_capaOculta;
                delete[] out_capaOculta;
                delete[] int_capaSalida;
                delete[] out_capaSalida;
                delete[] error_capaSalida;
                delete[] error_capaOculta;
            }
        }
    }

    double* predecir(double** X, int tamano_datos) {
        double* prediciones = new double[tamano_datos];
        for (int i = 0; i < tamano_datos; i++) {
            // Forward propagation

            // Calcular la entrada de la capa oculta
            double* int_capaOculta = new double[capaOculta];
            for (int j = 0; j < capaOculta; j++) {
                int_capaOculta[j] = 0.0;
                for (int k = 0; k <= capaEntrada; k++) {
                    int_capaOculta[j] += X[i][k] * pesosiniciales[j][k];
                }
            }

            // Aplicar la función de activación a la capa oculta
            double* out_capaOculta = new double[capaOculta];
            for (int j = 0; j < capaOculta; j++) {
                out_capaOculta[j] = sigmoide(int_capaOculta[j]);
            }

            // Calcular la entrada de la capa de salida
            double* int_capaSalida = new double[capaSalida];
            for (int j = 0; j < capaSalida; j++) {
                int_capaSalida[j] = 0.0;
                for (int k = 0; k <= capaOculta; k++) {
                    int_capaSalida[j] += out_capaOculta[k] * pesosfinales[j][k];
                }
            }

            // Aplicar la función de activación a la capa de salida
            double* out_capaSalida = new double[capaSalida];
            for (int j = 0; j < capaSalida; j++) {
                out_capaSalida[j] = sigmoide(int_capaSalida[j]);
            }

            // Almacenar la predicción
            prediciones[i] = out_capaSalida[0];

            // Liberar la memoria utilizada por las capas de la red neuronal
            delete[] int_capaOculta;
            delete[] out_capaOculta;
            delete[] int_capaSalida;
            delete[] out_capaSalida;
        }

        return prediciones;
    }
};

#endif