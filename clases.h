#include <iostream>
#include <fstream>
using namespace std;

class Transaccion {
    private:
    int tipo;
    float monto;
    int mes;
    int ano;

    public:
    Transaccion();
    Transaccion(int mes, int ano, int tipo, float monto);
    int getDia();
    int getMes();
    int getAño();
    int getTipo();
    float getMonto();
};

class Cuenta {
    public:
    float cajaPeso, cajaDolar;
    Transaccion t;

    public:
    Cuenta();
    Cuenta(float cajaPeso, float cajaDolar);
    void depositar(float monto, int moneda);
    void extraer(float monto, int moneda);
    float getCajaPeso();
    float getCajaDolar();
};

class Persona {
    public:
    long dni;
    int añoIngreso;
    string nombre;
    
    public:
    Persona();
    Persona(long dni, string nombre, int añoIngreso);
    virtual long getDni();
    virtual string getNombre();
    virtual int getIngreso();
};

class tarjetaCredit {
    public:
    string tarjeta;

    public:
    tarjetaCredit();
    tarjetaCredit(string t);
    void tarCred();
};

class Cliente : public Persona, archivo{
    public:
    int estado, nivel;
    Cuenta cuent;
    tarjetaCredit tarjeta;

    public:
    Cliente();
    Cliente(long dni, string nombre, int añoIngreso, int estado, int nivel, Cuenta cuent);
    long getDni();
    string getNombre();
    int getIngreso();
    int getEstado();
    int getNivel();
    float getCajaPeso();
    float getCajaDolar();
    void realizTrans(float monto, int tipo, int moneda, int mes1, int ano1);

    friend ostream& operator<<(ostream& os, const Cliente& Cl);
};

class Empleado : public Persona{
    private:
    string cargo;
    public:
    Empleado(long dni, string nombre, int añoIngreso, string cargo);
    string getCargo();
    void setCargo(string cargo);
    int getIngreso();
};

class archivo {
    private:
    protected:
    static void escrituraClientes(Cliente[], int);
    static void escrituraTransacciones(Transaccion[], int, const string&);
    void escritura();
    void lectura();
};

class banco {
    public:
    Empleado empleado1;
    Cliente cliente1;
    archivo archivo1;
};
