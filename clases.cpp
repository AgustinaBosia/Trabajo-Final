#include <iostream>
#include "clases.h"
using namespace std;

//Fecha
Fecha::Fecha(){
    dia=01;
    mes=01;
    año=1900;
}
Fecha::Fecha(int _dia, int _mes, int _año){
    dia=_dia;
    mes=_mes;
    año=_año;
}
void Fecha::setDia(int _dia){
    dia=_dia;
}
void Fecha::setMes(int _mes){
    mes=_mes;
}
void Fecha::setAño(int _año){
    año=_año;
}
int Fecha::getDia(){
    return dia;
}
int Fecha::getMes(){
    return mes;
}
int Fecha::getAño(){
    return año;
}


//Transaccion
Transaccion::Transaccion(Fecha _fecha, int _tipo, float _monto){
    fecha=_fecha;
    tipo=_tipo;
    monto=_monto;
}
int Transaccion::getDia(){
    return fecha.getDia();
}
int Transaccion::getMes(){
    return fecha.getMes();
}
int Transaccion::getAño(){
    return fecha.getAño();
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
Cliente::Cliente(long _dni, string _nombre, int _añoIngreso, int _estado, int _nivel, Cuenta _cuenta): Persona(_dni, _nombre,_añoIngreso){
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
void Cliente::realizTrans(float _monto, int _tipo, int _moneda, Fecha _fecha) {
    if (_tipo == 1) {
        cuenta.depositar(_monto, _moneda);
    } else if (_tipo== 2) {
        cuenta.extraer(_monto, _moneda);
    }
    Transaccion trans(_fecha, _tipo, _monto);
    // Aquí se registraría la transacción en el archivo correspondiente
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