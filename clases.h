
#include <iostream>
#include <fstream>
#include <limits>
#include <stdexcept>
using namespace std;

class Cliente;

class Transaccion {
    public:
    int tipo;
    float monto;
    int mes;
    int ano, caja;
    string titular;

    public:
    Transaccion();
    Transaccion(int mes, int ano, int tipo, float monto, int caja,string titular);
    friend ostream& operator<<(ostream& os, const Transaccion& Tr);
    int getMes();
    int getAño();
    int getTipo();
    float getMonto();
    int getCaja();
    string getTitular();
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
}
;

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

class archivo {
    public:
    archivo();
    void escrituraClientes(Cliente [], int);
    void escrituraTransacciones(Transaccion[], int);
};

class tarjetaCredit {
    public:
    string tarjeta;

    public:
    tarjetaCredit();
};

class Cliente : public Persona, public archivo {
    public:
    int estado, nivel;
    Cuenta cuent;
    tarjetaCredit tarjeta;
    Transaccion transacciones[100];
    int num_transacciones;

    public:
    Cliente();
    Cliente(long dni, string nombre, int nivel, Cuenta cuent);
    Cliente(long dni, string nombre, int añoIngreso, int estado, int nivel, Cuenta cuent);
    void tarjetaCredit(string t);
    long getDni();
    string getNombre();
    int getIngreso();
    int getEstado();
    int getNivel();
    float getCajaPeso();
    float getCajaDolar();
    void bajaCuenta(Cliente[], int);
    void realizTrans(float monto, int tipo, int moneda, int mes1, int ano1, int _caja, string titular_);
    friend ostream& operator<<(ostream& os, const Cliente& Cl);
};

class Empleado : public Persona {
    private:
    string cargo;
    public:
    Empleado();
    Empleado(long dni, string nombre, int añoIngreso, string cargo);
    string getCargo();
    void setCargo(string cargo);
    int getIngreso();
};

class banco {
    private:
    Cliente clientes[100];
    Transaccion transacciones[1000];
    int nroTrans, nroClientes;
    public:
    banco();
    Empleado empleado1;
    Cliente cliente1;
    archivo archivo1;
};