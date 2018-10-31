    #include <iostream>
    #include <cstring>
    #include <algorithm>
    #include <fstream>
    #include <random>

    using namespace std;

    // Parámetros de configuración.
    constexpr const char kCaseName[] = "easy";
    constexpr int kNumeroDeCasos = 10;
    constexpr int kMaxN = 50000;
    constexpr int kMaxK = 7000000;

    string build_case_name(const string& case_name, int case_number,
                           const string& extension) {
      char buf[100];
      snprintf(buf, sizeof(buf), "%s_%03d.%s", case_name.c_str(), case_number,
               extension.c_str());
      return string(buf);
    }

    int main() {
      ios_base::sync_with_stdio(0);

      // Fuente de números aleatorios.
      random_device rd;
      mt19937 gen(rd());

      // Distribuciones uniformes en los intervalos [1, kMaxN] y [1, kMaxK].
      uniform_int_distribution<> Nrand(1, kMaxN), Krand(1, kMaxK);

      // Ejemplo de como crear un problema para ordenar un arreglo de números
      // aleatorios de tamaño N.
      for (int caso_actual = 1; caso_actual <= kNumeroDeCasos; caso_actual++) {
      	// Creamos la entrada en memoria.
        int numeros[kMaxN];
      	int N = Nrand(gen);  // Esto asigna a N un número aleatorio en [1, kMaxN].
      	for (int i = 0; i < N; i++)
          numeros[i] = Krand(gen); // Esto asigna un número aleatorio en [1, kMaxK].


        // Aqui crearemos un archivo .in, y ahi escribiremos la entrada.
        {
          ofstream f(build_case_name(kCaseName, caso_actual, "in"));

          // Imprimiremos N seguido de un salto de línea.
          f << N << "\n";
          for (int i = 0; i < N; i++)
            f << numeros[i] << " ";
          // Es deseble siempre terminar los .in con un salto de línea.
          f << "\n";
        }

        // Ahora hay que resolver el problema. En este caso, había que ordenar los
        // enteros.
        sort(numeros, numeros + N);

        // Una vez resuelto el problema hay que escribir la salida en el .out.
        {
          ofstream f(build_case_name(kCaseName, caso_actual, "out"));

          for (int i = 0; i < N; i++)
            f << numeros[i] << " ";
          // También los .out terminarlos con salto de linea
          f << "\n";
        }
      }

      return 0;
    }
