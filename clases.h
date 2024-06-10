#include <iostream>
#include <fstream>
using namespace std;

class Transaccion{
    private:
    int tipo;
    float monto;
    int mes;
    int ano;

    public:
    Transaccion();
    Transaccion(int mes, int ano,int,float);
    int getDia();
    int getMes();
    int getAño();
    int getTipo();
    float getMonto();
};

class Cuenta{
    public:
    float cajaPeso, cajaDolar;
    Transaccion t;

    public:
    Cuenta();
    Cuenta(float,float);
    void depositar(float, int);
    void extraer(float, int);
    float getCajaPeso();
    float getCajaDolar();
};

class Persona{
    public:
    long dni;
    int añoIngreso;
    string nombre;
    public:
    Persona();
    Persona(long,string,int);
    virtual long getDni();
    virtual string getNombre();
    virtual int getIngreso();
};

class Cliente : public Persona{
    public:
    int estado,nivel;
    Cuenta cuent;
    tarjetaCredit tarjeta;
    

    public:
    Cliente();
    Cliente(long dni,string nombre,int tipo,int añoIng,int estado,Cuenta c);
    long getDni(); 
    string getNombre();
    int getIngreso();
    int getEstado();//0baja 1alta
    int getNivel();// 1plata 2oro 3platino
    float getCajaPeso();
    float getCajaDolar();
    void realizTrans(float, int, int, int mes, int ano);
};

class tarjetaCredit{
    public:
    string tarjeta;

    public:
    tarjetaCredit();
    tarjetaCredit(string t);
    void tarCred();
};
tarjetaCredit::tarjetaCredit(){
    tarjeta="";
}

tarjetaCredit::tarjetaCredit(string t){
    tarjeta=t;
}

void tarjetaCredit::tarCred(){
    if(tarjeta=="plata" or tarjeta=="Plata"){
        cout<<"No tienes acceso a tarjetas de credito"<<endl;
    }
    else if(tarjeta=="oro" or tarjeta=="Oro"){
        cout <<"puedes acceder a la tarjeta de crédito Credix con límite de crédito 250000"<<endl;
    }
    else if (tarjeta=="Platino" or tarjeta=="platino"){
        cout <<"puedes acceder a la tarjeta de crédito Premium con límite de crédito 500000"<<endl;
    }
}

class Empleado : public Persona{
    private:
    string cargo;
    public:
    Empleado(long,string,int,string);
    string getCargo();
    void setCargo(string);
    int getIngreso();
};

class archivo{
    private:
// arreglos?
    protected:
    void escritura();
    void lectura();

};

class banco {
    public:
    Empleado empleado1;
    Cliente cliente1;
    archivo archivo1;

};