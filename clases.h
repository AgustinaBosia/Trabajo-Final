#include <iostream>
using namespace std;

class Fecha{
    private:
    int dia,mes,año;
    public:
    Fecha(int,int,int);
    Fecha();
    void setDia(int);
    void setMes(int);
    void setAño(int);
    int getDia();
    int getMes();
    int getAño();
};

class Transaccion{
    private:
    int tipo;
    float monto;
    Fecha fecha;
    public:
    Transaccion(Fecha,int,float);
    int getDia();
    int getMes();
    int getAño();
    int getTipo();
    float getMonto();
};

class Cuenta{
    private:
    float cajaPeso, cajaDolar;
    public:
    Cuenta();
    Cuenta(float,float);
    void depositar(float, int);
    void extraer(float, int);
    float getCajaPeso();
    float getCajaDolar();
};

class Persona{
    private:
    long dni;
    int añoIngreso;
    string nombre;
    public:
    Persona(long,string,int);
    virtual long getDni();
    virtual string getNombre();
    virtual int getIngreso();
};

class Cliente : public Persona{
    private:
    int estado,nivel;
    Cuenta cuenta;
    public:
    Cliente(long,string,int,int,int,Cuenta);
    long getDni(); 
    string getNombre();
    int getIngreso();
    int getEstado();//0 baja, 1alta
    int getNivel();// 1 plata, 2 oro, 3 platino
    float getCajaPeso();
    float getCajaDolar();
    void realizTrans(float, int, int, Fecha);
};

class Empleado : public Persona{
    private:
    string cargo;
    public:
    Empleado(long,string,int,string);
    string getCargo();
    void setCargo(string);
    int getIngreso();
};