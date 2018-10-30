#include<iostream>
#include<cstring>
#include<algorithm>
#include<fstream>
using namespace std;


string case_name;
string nombre_de_archivo;
string buildcase_name(int temp_num,string type_of_case) ///función para generar el nombre del archivo, por ejemplo "easy1.in".
{
    string temporal_number,temporal_name;
    while(temp_num)
    {
        temporal_number.push_back((temp_num%10)+'0');
        temp_num/=10;
    }
    reverse(temporal_number.begin(),temporal_number.end());
    temporal_name=case_name+temporal_number+type_of_case;
    return temporal_name;

}
int numeros[500010]; ///Arreglo que usaremos para el problema de ejemplo.
int main ()
        {
            ios_base::sync_with_stdio(0);
            case_name="easy"; ///case_name es hard,easy,etc
            int numero_de_casos=10; ///Cuantos casos haremos.
            random_device rd;
            mt19937 gen(rd()); ///Parámetro que usaremos para generar los random
    uniform_int_distribution<> Nrand(1,50000),Krand(1,7000000); ///Limites de nuestros random
    fstream buffer;

    ///Ejemplo de como crear un problema para ordenar un arreglo de números aleatorios de tamaño N
    for(int caso_actual=0; caso_actual<numero_de_casos; caso_actual++)
    {
        ///Aqui crearemos un archivo .in, y ahi escribiremos la entrada
        nombre_de_archivo=buildcase_name(caso_actual+1,".in");
        buffer.open (nombre_de_archivo.c_str(),fstream::out);
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
        nombre_de_archivo=buildcase_name(caso_actual+1,".out");
        buffer.open (nombre_de_archivo.c_str(),fstream::out);
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
