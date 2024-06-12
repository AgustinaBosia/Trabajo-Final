#include "clases.h"
using namespace std;

// -------------------------------------------------------------------------------------------------TRANSACCION

Transaccion::Transaccion(int mes1, int ano1, int _tipo, float _monto, int _caja, string titular_)
{
    mes = mes1;
    ano = ano1;
    tipo = _tipo;
    monto = _monto;
    caja=_caja;
    titular=titular_;
}

Transaccion::Transaccion()
{
    mes = 0;
    ano = 0;
    tipo = 0;
    monto = 0;
}
ostream &operator<<(ostream &os, const Transaccion &Tr)
{
    os<<" Mes: "<<Tr.mes<<" Año: "<<Tr.ano<<" Monto: "<<Tr.monto <<" Caja: "<<Tr.caja;
   return os;
}
int Transaccion::getMes()
{
    return mes;
}

int Transaccion::getAño()
{
    return ano;
}

int Transaccion::getTipo()
{
    return tipo;
}

float Transaccion::getMonto()
{
    return monto;
}
int Transaccion::getCaja()
{
    return caja;
}

string Transaccion::getTitular(){
    return titular;
}

// -------------------------------------------------------------------------------------------------CUENTA 

Cuenta::Cuenta()
{
    cajaDolar = 0;
    cajaPeso = 0;
}

Cuenta::Cuenta(float _cajaPeso, float _cajaDolar)
{
    cajaPeso = _cajaPeso;
    cajaDolar = _cajaDolar;
}

void Cuenta::depositar(float monto, int moneda)
{
    if (moneda == 1)
    {
        cajaPeso += monto;
    }
    else if (moneda == 2)
    {
        cajaDolar += monto;
    }
}

void Cuenta::extraer(float monto, int moneda)
{
    if (monto < 0)
    {
        throw "error: monto negativo";
    }
    if (moneda == 1)
    {
        cajaPeso -= monto;
    }
    else if (moneda == 2)
    {
        cajaDolar -= monto;
    }
}

float Cuenta::getCajaPeso()
{
    return cajaPeso;
}

float Cuenta::getCajaDolar()
{
    return cajaDolar;
}






//  -------------------------------------------------------------------------------------------------PERSONA

Persona::Persona() {}

Persona::Persona(long _dni, string _nombre, int _añoIngreso)
{
    dni = _dni;
    nombre = _nombre;
    añoIngreso = _añoIngreso;
}

long Persona::getDni()
{
    return dni;
}

string Persona::getNombre()
{
    return nombre;
}

int Persona::getIngreso()
{
    return añoIngreso;
}

// -------------------------------------------------------------------------------------------------CLIENTE

Cliente::Cliente()
{
    estado = 0;
    nivel = 0;
}

Cliente::Cliente(long _dni, string _nombre, int _nivel, Cuenta _cuent){
    dni=_dni;
    nombre=_nombre;
    estado=1;
    nivel=_nivel;
    añoIngreso=2024;
    cuent=_cuent;
}

Cliente::Cliente(long _dni, string _nombre, int _añoIngreso, int _estado, int _nivel, Cuenta _cuenta) : Persona(_dni, _nombre, _añoIngreso)
{
    estado = _estado;
    nivel = _nivel;
    cuent = _cuenta;
}

long Cliente::getDni()
{
    return Persona::getDni();
}

string Cliente::getNombre()
{
    return Persona::getNombre();
}

int Cliente::getIngreso()
{
    return Persona::getIngreso();
}

int Cliente::getEstado()
{
    return estado;
}

int Cliente::getNivel()
{
    return nivel;
}

float Cliente::getCajaPeso()
{
    return cuent.getCajaPeso();
}

float Cliente::getCajaDolar()
{
    return cuent.getCajaDolar();
}

void Cliente::bajaCuenta(Cliente clientes[], int nroCliente) {


    int a=0;
    
    for(int j=0; j<100; j++){
        if (nroCliente==clientes[j].dni){
            clientes[j].estado=0;
            a=1;
            cout<<clientes[j];
        }

        if(a!=0){
            cout<<"no hay tal cliente"<<endl;
        }
        
    }

}

void Cliente::realizTrans(float _monto, int _tipo, int _moneda, int mes1, int ano1, int _caja, string _titular)
{
    if (_tipo == 1)
    {
        cuent.depositar(_monto, _moneda);
    }
    else if (_tipo == 2)
    {
        cuent.extraer(_monto, _moneda);
    }
    Transaccion trans(mes1, ano1, _tipo, _monto, _caja, "a");
}

ostream &operator<<(ostream &os, const Cliente &Cl)
{
    string tip;
    if (Cl.nivel == 1)
    {
        tip = "plata";
    }
    else if (Cl.nivel == 2)
    {
        tip = "oro";
    }
    else if (Cl.nivel == 3)
    {
        tip = "platino";
    }

    string est;
    if (Cl.estado == 1)
    {
        est = "alta";
    }
    else if (Cl.estado == 0)
    {
        est = "baja";
    }

    os << "( nro: " << Cl.dni << ", nombre: " << Cl.nombre << ", año de ingreso: " << Cl.añoIngreso << ", estado: " << est << ", nivel: " << tip << ", cuenta pesos: " << Cl.cuent.cajaPeso<< ", cuenta dolares: " << Cl.cuent.cajaDolar << " )";
    return os;
}

// -------------------------------------------------------------------------------------------------EMPLEADO

Empleado::Empleado(){
    dni=0;
}

Empleado::Empleado(long _dni, string _nombre, int _añoIngreso, string _cargo) : Persona(_dni, _nombre, _añoIngreso)
{
    cargo = _cargo;
}

string Empleado::getCargo()
{
    return cargo;
}

int Empleado::getIngreso()
{
    return Persona::getIngreso();
}

void Empleado::setCargo(string _cargo)
{
    cargo = _cargo;
}

// -------------------------------------------------------------------------------------------------ARCHIVO

archivo::archivo() {}


void archivo::escrituraClientes(Cliente clientes[], int numClientes)
{
    ofstream variableescribe("clientes.txt", ios::app);

    if (!variableescribe)
    {
        cout << "Error al abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numClientes; ++i)
    {
        variableescribe << clientes[i].getDni() << " "
                        << clientes[i].getNombre() << " "
                        << clientes[i].getIngreso() << " "
                        << clientes[i].getEstado() << " "
                        << clientes[i].getNivel() << " "
                        << clientes[i].getCajaPeso() << " "
                        << clientes[i].getCajaDolar() << endl;
    }
}

void archivo::escrituraTransacciones(Transaccion transacciones[], int numTransacciones)
{
    ofstream variableescribe("transacciones.txt", ios::app);

    if (!variableescribe)
    {
        cout << "Error al abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numTransacciones; ++i)
    {
        variableescribe << transacciones[i].getMes() << " "
                        << transacciones[i].getAño() << " "
                        << transacciones[i].getTipo() << " "
                        << transacciones[i].getCaja() << " "
                        << transacciones[i].getMonto() << " "                       
                        << transacciones[i].getTitular() << endl;
    }
}

// -------------------------------------------------------------------------------------------------TARJETA

tarjetaCredit::tarjetaCredit()
{
    tarjeta = "";
}

void Cliente::tarjetaCredit(string t)
{
    if (t=="plata"){
        cout<<"no tiene acceso a tarjeta de credito"<<endl;
        tarjeta.tarjeta="plata";
    }
    else if(t=="oro"){
        
        tarjeta.tarjeta="oro";
    }
    else if(t=="platino"){
        
        tarjeta.tarjeta="platino";
    }
}



// --------------------------------------------------------------------------------------------------BANCO

banco::banco(){
    
}