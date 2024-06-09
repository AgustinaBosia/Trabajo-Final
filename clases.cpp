#include <iostream>
#include "clases.h"
using namespace std;



//Transaccion
Transaccion::Transaccion(int mes1, int ano1, int _tipo, float _monto){
    mes=mes1;
    ano=ano1;
    tipo=_tipo;
    monto=_monto;
}


Transaccion::Transaccion(){
    mes=0;
    ano=0;
    tipo=0;
    monto=0;
}

int Transaccion::getMes(){
    return mes;
}
int Transaccion::getAño(){
    return ano;
}
int Transaccion::getTipo(){
    return tipo;
}
float Transaccion::getMonto(){
    return monto;
}

//Cuenta
Cuenta::Cuenta(){
    cajaDolar=0;
    cajaPeso=0;
}
Cuenta::Cuenta(float _cajaPeso, float _cajaDolar){
    cajaPeso=_cajaPeso;
    cajaDolar=_cajaDolar;
}
void Cuenta::depositar(float monto, int moneda) {
    if (moneda == 1) {
        cajaPeso += monto;
    }
    else if (moneda == 2){
        cajaDolar += monto;
    }
}
void Cuenta::extraer(float monto, int moneda) {
    // excepción

    if(monto<0){
        throw "error: negativo";
    }
    
    if (moneda == 1) {
        cajaPeso -= monto;
    }
    else if (moneda == 2){
        cajaDolar -= monto;
    }

}
float Cuenta::getCajaPeso(){
    return cajaPeso;
}
float Cuenta::getCajaDolar(){
    return cajaDolar;
}


//Persona
Persona::Persona(long _dni, string _nombre, int _añoIngreso){
    dni=_dni;
    nombre=_nombre;
    añoIngreso=_añoIngreso;
}
long Persona::getDni(){
    return dni;
}
string Persona::getNombre(){
    return nombre;
}
int Persona::getIngreso(){
    return añoIngreso;
}


//Cliente
Cliente::Cliente(long _dni, string _nombre, int _añoIngreso, int _estado, int _nivel, Cuenta _cuenta): Persona(_dni, _nombre,_añoIngreso)
{
    estado=_estado;
    nivel=_nivel;
    cuenta=_cuenta;
}
long Cliente::getDni(){
    return Persona::getDni();
}
string Cliente::getNombre(){
    return Persona::getNombre();
}
int Cliente::getIngreso(){
    return Persona::getIngreso();
}
int Cliente::getEstado(){
    return estado;
}
int Cliente::getNivel(){
    return nivel;
}
float Cliente::getCajaPeso(){
    return cuenta.getCajaPeso();
}
float Cliente::getCajaDolar(){
    return cuenta.getCajaDolar();
}
void Cliente::realizTrans(float _monto, int _tipo, int _moneda, int mes1,int ano1 ) {
    if (_tipo == 1) {
        cuenta.depositar(_monto, _moneda);
    } else if (_tipo== 2) {
        cuenta.extraer(_monto, _moneda);
    }
    Transaccion trans(0,0, _tipo, _monto);
    //**
}


//Empleado
Empleado::Empleado(long _dni, string _nombre, int _añoIngreso, string _cargo): Persona(_dni, _nombre, _añoIngreso){
    cargo=_cargo;
}
string Empleado::getCargo(){
    return cargo;
}
int Empleado::getIngreso(){
    return Persona::getIngreso();
}
void Empleado::setCargo(string _cargo){
    cargo=_cargo;
}



void archivo::escritura(){

// abre el archivo para escritura 
    ofstream variableescribe ("clientes.txt");

// verifica existencia de archivo
    if (!variableescribe){
        cout << "error al abrir el archivo"<< endl;

        exit (EXIT_FAILURE);
    }

    int num;

    cout << "ingrese el numero a multiplicar: ";
    cin >> num;


//escribe archivo
    variableescribe << num << " ";
        
    variableescribe<<endl;
    
}

void archivo::lectura(){
    ifstream variablelectura ("clientes.txt");
// verifica erchivo
    if (!variablelectura.is_open()){
        cout << "error" <<endl;
        exit (EXIT_FAILURE);
    }

    int valor;

    int i = 0;

 // lee datos en archivo
    while (variablelectura >> valor){
        cout << valor;
    }
}