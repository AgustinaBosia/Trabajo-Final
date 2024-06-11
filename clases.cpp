#include "clases.h"

// Implementación de los constructores y métodos de Transaccion

Transaccion::Transaccion(int mes1, int ano1, int _tipo, float _monto) {
    mes = mes1;
    ano = ano1;
    tipo = _tipo;
    monto = _monto;
}

Transaccion::Transaccion() {
    mes = 0;
    ano = 0;
    tipo = 0;
    monto = 0;
}

int Transaccion::getMes() {
    return mes;
}

int Transaccion::getAño() {
    return ano;
}

int Transaccion::getTipo() {
    return tipo;
}

float Transaccion::getMonto() {
    return monto;
}

// Implementación de los constructores y métodos de Cuenta

Cuenta::Cuenta() {
    cajaDolar = 0;
    cajaPeso = 0;
}

Cuenta::Cuenta(float _cajaPeso, float _cajaDolar) {
    cajaPeso = _cajaPeso;
    cajaDolar = _cajaDolar;
}

void Cuenta::depositar(float monto, int moneda) {
    if (moneda == 1) {
        cajaPeso += monto;
    }
    else if (moneda == 2) {
        cajaDolar += monto;
    }
}

void Cuenta::extraer(float monto, int moneda) {
    if (monto < 0) {
        throw "error: monto negativo";
    }
    if (moneda == 1) {
        cajaPeso -= monto;
    }
    else if (moneda == 2) {
        cajaDolar -= monto;
    }
}

float Cuenta::getCajaPeso() {
    return cajaPeso;
}

float Cuenta::getCajaDolar() {
    return cajaDolar;
}

//  constructores y métodos de PERSONA

Persona::Persona() {}

Persona::Persona(long _dni, string _nombre, int _añoIngreso) {
    dni = _dni;
    nombre = _nombre;
    añoIngreso = _añoIngreso;
}

long Persona::getDni() {
    return dni;
}

string Persona::getNombre() {
    return nombre;
}

int Persona::getIngreso() {
    return añoIngreso;
}

// Implementación de los constructores y métodos de Cliente

Cliente::Cliente() : Persona() {
    estado = 0;
    nivel = 0;
}

Cliente::Cliente(long _dni, string _nombre, int _añoIngreso, int _estado, int _nivel, Cuenta _cuenta) : Persona(_dni, _nombre, _añoIngreso) {
    estado = _estado;
    nivel = _nivel;
    cuent = _cuenta;
}

long Cliente::getDni() {
    return Persona::getDni();
}

string Cliente::getNombre() {
    return Persona::getNombre();
}

int Cliente::getIngreso() {
    return Persona::getIngreso();
}

int Cliente::getEstado() {
    return estado;
}

int Cliente::getNivel() {
    return nivel;
}

float Cliente::getCajaPeso() {
    return cuent.getCajaPeso();
}

float Cliente::getCajaDolar() {
    return cuent.getCajaDolar();
}

void Cliente::realizTrans(float _monto, int _tipo, int _moneda, int mes1, int ano1) {
    if (_tipo == 1) {
        cuent.depositar(_monto, _moneda);
    }
    else if (_tipo == 2) {
        cuent.extraer(_monto, _moneda);
    }
    Transaccion trans(mes1, ano1, _tipo, _monto);
}

ostream& operator<<(ostream& os, const Cliente& Cl) {
    string tip;
    if (Cl.nivel == 1) {
        tip = "plata";
    }
    else if (Cl.nivel == 2) {
        tip = "oro";
    }
    else if (Cl.nivel == 3) {
        tip = "platino";
    }

    string est;
    if (Cl.estado == 1) {
        est = "alta";
    }
    else if (Cl.estado == 0) {
        est = "baja";
    }

    os << "( nro: " << Cl.dni << ", nombre: " << Cl.nombre << ", año de ingreso: " << Cl.añoIngreso << ", estado: " << est << ", nivel: " << tip << ", cuenta pesos: " << "Cl.getCajaPeso()" << ", cuenta dolares: " << "a" << " )";
    return os;
}

// Implementación de los constructores y métodos de Empleado

Empleado::Empleado(long _dni, string _nombre, int _añoIngreso, string _cargo) : Persona(_dni, _nombre, _añoIngreso) {
    cargo = _cargo;
}

string Empleado::getCargo() {
    return cargo;
}

int Empleado::getIngreso() {
    return Persona::getIngreso();
}

void Empleado::setCargo(string _cargo) {
    cargo = _cargo;
}

// Implementación de métodos de archivo

void archivo::escrituraClientes(Cliente clientes[], int numClientes) {
        ofstream variableescribe("clientes.txt");

        if (!variableescribe) {
            cout << "Error al abrir el archivo" << endl;
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < numClientes; ++i) {
            variableescribe << clientes[i].getDni() << " "
                            << clientes[i].getNombre() << " "
                            << clientes[i].getIngreso() << " "
                            << clientes[i].getEstado() << " "
                            << clientes[i].getNivel() << " "
                            << clientes[i].getCajaPeso() << " "
                            << clientes[i].getCajaDolar() << endl;
        }
    }

void archivo::escrituraTransacciones(Transaccion transacciones[], int numTransacciones, const string& archivo) {
        ofstream variableescribe(archivo);

        if (!variableescribe) {
            cout << "Error al abrir el archivo" << endl;
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < numTransacciones; ++i) {
            variableescribe << transacciones[i].getMes() << " "
                            << transacciones[i].getAño() << " "
                            << transacciones[i].getTipo() << " "
                            << transacciones[i].getMonto() << endl;
        }
    }


//no se necesita esto i think
void archivo::lectura() {
    ifstream variablelectura("clientes.txt");

    if (!variablelectura.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    }

    int valor;
    while (variablelectura >> valor) {
        cout << valor << " ";
    }
    cout << endl;
}

// Implementación de tarjetaCredit

tarjetaCredit::tarjetaCredit() {
    tarjeta = "";
}

tarjetaCredit::tarjetaCredit(string t) {
    tarjeta = t;
}

void tarjetaCredit::tarCred() {
    if (tarjeta == "plata" || tarjeta == "Plata") {
        cout << "No tienes acceso a tarjetas de credito" << endl;
    }
    else if (tarjeta == "oro" || tarjeta == "Oro") {
        cout << "Puedes acceder a la tarjeta de crédito Credix con límite de crédito 250000" << endl;
    }
    else if (tarjeta == "Platino" || tarjeta == "platino") {
        cout << "Puedes acceder a la tarjeta de crédito Premium con límite de crédito 500000" << endl;
    }
}
