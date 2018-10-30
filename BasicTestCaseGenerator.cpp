#include<bits/stdc++.h>
using namespace std;


string caseName;
string nombreDeArchivo;
string buildCaseName(int tempNum,string typeOfCase) ///función para generar el nombre del archivo, por ejemplo "easy1.in".
{
    string temporalnumber,temporalName;
    while(tempNum)
    {
        temporalnumber.push_back((tempNum%10)+'0');
        tempNum/=10;
    }
    reverse(temporalnumber.begin(),temporalnumber.end());
    temporalName=caseName+temporalnumber+typeOfCase;
    return temporalName;

}
int numeros[500000]; ///Arreglo que usaremos para el problema de ejemplo.
int main ()
        {
            ios_base::sync_with_stdio(0);
            caseName="easy"; ///caseName es hard,easy,etc
            int numeroDeCasos=10; ///Cuantos casos haremos.
            random_device rd;
            mt19937 gen(rd()); ///Parámetro que usaremos para generar los random
    uniform_int_distribution<> Nrand(1,50000),Krand(1,7000000); ///Limites de nuestros random
    fstream buffer;

    ///Ejemplo de como crear un problema para ordenar un arreglo de números aleatorios de tamaño N
    for(int casoActual=0; casoActual<numeroDeCasos; casoActual++)
    {
        ///Aqui crearemos un archivo .in, y ahi escribiremos la entrada
        nombreDeArchivo=buildCaseName(casoActual+1,".in");
        buffer.open (nombreDeArchivo.c_str(),fstream::out);
        int n=Nrand(gen); ///Esto asigna a n un número aleatorio entre el rango 1-50000
        buffer<<n<<endl; ///imprimiremos N seguido de un salto de linea
        for(int i=0; i<n; i++)
        {
            if(i!=0)
                buffer<<" "; ///espacio para separar los números

            numeros[i]=Krand(gen);
            buffer<<numeros[i];
        }
        buffer<<endl; ///Importante siempre terminar nuestros archivos con un salto de linea
        buffer.close();
        ///Ahora haremos la salida
        nombreDeArchivo=buildCaseName(casoActual+1,".out");
        buffer.open (nombreDeArchivo.c_str(),fstream::out);
        sort(numeros,numeros+n);
        for(int i=0; i<n; i++)
        {
            if(i!=0)
                buffer<<" ";
            buffer<<numeros[i];
        }
        buffer<<endl; ///También los .out terminarlos con salto de linea
        buffer.close();





    }
}
