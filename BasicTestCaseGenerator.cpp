#include<bits/stdc++.h>
using namespace std;

///Apartir de aqui normalmente inician mis codigos , si es que me estas espiando <3
///From here normally my code starts, thats if you are stalking me <3
string k;
string k1;
string vac;
string caseName;
int main ()
{
    ios_base::sync_with_stdio(0);
    long long   int  x=0,z,mal=INF,s=0,a1=0,b1=0,c1,x1,y1,t=-INF,res=0,e,f;
    long long   int  a,b,c,d,y=1,ya=1;
    cin>>caseName;
    ///caseName es hard,easy,etc
    int numeroDeCasos=10;
    random_device rd;
    mt19937 gen(rd()); ///Parámetro que usaremos para los random
    uniform_int_distribution<> Nrand(1,50000),Krand(1,7000000); ///Limites de nuestros casos
    for(int casoActual=0; casoActual<numeroDeCasos; casoActual++)
    {
        existe=vacio;
        x=ya;
        ya++;
        k1=vac;
        while(x)
        {
            k1.push_back((x%10)+'0');
            x/=10;
        }
        reverse(k1.begin(),k1.end());
        k=caseName;
        k+=k1;
        k1=k;
        k1.push_back('.');
        k1.push_back('i');
        k1.push_back('n');
       // k1.push_back('o');
       // k1.push_back('u');
      //  k1.push_back('t');
        fstream troy;
        troy.open (k1.c_str(),fstream::out);

        troy<<

    }
}
