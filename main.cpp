#include <iostream>
#include "clases.h"
#include <string>
using namespace std;

void altaCuenta(Cliente array[], long nroCliente, int& i) {
    bool encontrado = true;
    for (int j = 0; j < 100; j++) {
        if (array[j].getDni() == nroCliente) {
            encontrado = true;
            cout << "Ese cliente ya posee una cuenta de banco" << endl;
            break;
        }
    }
    string nombre;
    float saldoPeso, saldoDolar;
    int nivel;
    cout << "Ingrese su nombre: ";
    cin>>nombre;
    cout<<"Ingrese su saldo inicial en pesos:"<<endl;
    cin>>saldoPeso;
    cout<<"Ingrese su saldo inicial en dolares:"<<endl;
    cin>>saldoDolar;
    cout<<"Que nivel desea que tenga su cuenta?:"<<endl;
    cout<<"1. Plata (No tarj de crédito)"<<endl;
    cout<<"2. Oro (Límite de ...)"<<endl;
    cout<<"3. Platino (Límite de ...)"<<endl;
    cin>>nivel;
    Cuenta nuevaCuenta(saldoPeso,saldoDolar);
    Cliente Cl(nroCliente, nombre, nivel, nuevaCuenta);
    array[i] = Cl;
    i++;
    cout << "Cuenta creada exitosamente." << endl;
}
    
//VER!!!!!!!!!!!!!!!
void bajaCuenta(Cliente array[], long nroCliente) {
    bool encontrado = false;
    for (int j = 0; j < 100; j++) {
        if (array[j].getDni() == nroCliente) {
            encontrado = true;
            array[j].estado= 0;
            cout << "Cliente dado de baja exitosamente." << endl;
            break;
        }
    }
    if (!encontrado) {
        cout << "No hay un cliente del banco con ese número." << endl;
    }
}


void solicitarFecha(int& _mes, int& _ano) {
    int mes, ano;
    bool fechaValida = false;
    
    while (!fechaValida) {
        try {
            cout << "Ingrese el mes: ";
            cin >> mes;
            cout << "Ingrese el año: ";
            cin >> ano;
            if (mes > 12 || mes < 1 || ano < 1) {
                throw "Fecha inválida. Intente nuevamente.";
            } else {
                _mes = mes;
                _ano = ano;
                fechaValida = true;
            }
        } catch (const char* msg) {
            cout << "Error: " << msg << endl;
        }
    }
}

void operacion(Cliente array[], int nro, int i){
    for (int j=0; j < (i); j++){
                if ((array[j].getDni() == nro) && (array[j].estado!= 0)){
                    int mes,ano, caja, op;
                    float monto;
                    
                    cout << "¿En que caja desea operar? (1=peso, 2=dolar)" << endl;
                    cin >> caja;
                    cout << "¿Que operacion desea realizar?(1=deposito, 2=extraccion)" << endl;
                    cin >> op;
                    cout << "Ingrese el monto" << endl;
                    cin >> monto;
                    solicitarFecha(mes, ano);

                    array[j].realizTrans(monto, op, caja, mes, ano);
                    Transaccion Tr(mes, ano, op, monto);
                    array[j].cuent.t.getMonto();
                }
                if ((array[j].getDni() == nro) && (array[j].estado== 0)){
                cout<<"EL cliente está dado de baja."<<endl;
            }
        }
}

void menuCliente(Cliente array[], int &i) {
    int mes, ano;
    long nro;
    int caja, op, monto;
    Cuenta Cu(1000, 500);
    
    cout << "Desea: " << endl;
    cout << "1=Dar de alta una cuenta" << endl;
    cout << "2=Dar de baja una cuenta" << endl;
    cout << "3=Realizar una operación en una cuenta existente" << endl;
    cout << "4=Salir" << endl;
    cin >> op;

    cout << "Ingrese el nro de Cliente (su DNI): "<<endl;
    cin >> nro;
     
    switch (op) {
        case 1:{
            altaCuenta(array, nro, i);
            break;
        }
        case 2:{
            bajaCuenta(array, nro);
            break;
        }
        case 3: {
            operacion(array, nro, i);
            break;
        }
        default:{
        break;
        }
    }
}
void caseone(Cliente array[], int i){
    int a,b=-1;
    cout <<"ingrese el numero de cliente a buscar: "<<endl;
    cin>> a;

    for (int j = 0; j <= i; j++) {
        if (array[j].dni == a){
            b=j;
        }
    }
    if(b!=-1){
        cout<<"aqui los detalles del cliente buscado:"<<endl;
        cout << array[b] << endl;
    }
    else{
        cout<<"no existe cliente con ese numero"<<endl;
    }
}

void casetwo(Cliente array[], int i) {
    for (int j = 0; j <= i; j++) {
        cout<<j<<") "<<"cliente nro: "<<array[j].dni<<", nombre: "<<array[j].nombre<<endl;
    }
}


void casethree(Cliente array[], int i){
    int a,b=-1;
    cout <<"ingrese el numero de cliente a buscar: "<<endl;
    cin>> a;
}
/* Agus fijate si te gusta 
void casethree(Cliente array[], int i) {
    long nroCliente;
    cout << "Ingrese el número de cliente: ";
    cin >> nroCliente;

    bool clienteEncontrado = false;
    for (int j = 0; j < i; j++) {
        if (array[j].getDni() == nroCliente && array[j].getEstado() != 0) {
            clienteEncontrado = true;
            cout << "Transacciones del cliente: " << array[j].getNombre() << endl;
            // Obtener las transacciones del cliente
            Transaccion* transaccionesCliente = array[j].cuent.t;
            int numTransacciones = sizeof(transaccionesCliente) / sizeof(transaccionesCliente[0]);

            // Mostrar las transacciones del cliente
            for (int k = 0; k < numTransacciones; k++) {
                cout << "Transacción " << k + 1 << ":" << endl;
                cout << "Tipo: " << (transaccionesCliente[k].getTipo() == 1 ? "Depósito" : "Extracción") << endl;
                cout << "Monto: " << transaccionesCliente[k].getMonto() << endl;
                cout << "Mes: " << transaccionesCliente[k].getMes() << endl;
                cout << "Año: " << transaccionesCliente[k].getAño() << endl;
                cout << endl;
            }
            break;
        }
    }

    if (!clienteEncontrado) {
        cout << "Cliente no encontrado o dado de baja." << endl;
    }
}
*/
void casefour (Cliente array [], int i){
    int mes,ano; 
    cout << "Ingrese el mes (1-12): ";
    cin >> mes;
    cout << "Ingrese el año: ";
    cin >> ano;
    cout << "Transacciones en el mes "<<mes<< "del año" << ano<< ":"<<endl;
    for (int j=0;j<=i;j++){
        array [j].mostrar_transacciones (mes,ano);
    }
}
void casefive (Cliente array [],int i){
    int ano;
    cout << "Ingrese el año: ";
    cin >> ano;
    cout << "Transacciones en el año"<< ano<< ":"<<endl;
    for (int j=0; j <=i;j++){
        array[j].mostrar_transacciones (0,ano);
    }
}
void casesix (Cliente array [], int i){
    cout << "Todas las transacciones: "<< endl;
    for (int j=0;j<=i;j++){
        array[j].mostrar_transacciones (0,0);
    }
}
void menuEmpleado(Cliente array[], int i) {
    int op;
    Empleado(43385086, "Juan Bergia", 2024, "Gerente");
    cout << "¿que desea hacer?" << endl;
    cout << "1. Detalle de cliente por numero de cliente" << endl;
    cout << "2. Listado de todos los clientes en el banco" << endl;
    cout << "3. Listado de transacciones por cliente" << endl;
    cout << "Informes de extracciones y depósitos según los siguiente criterios:" << endl;
    cout << " 4. En un mes determinado" << endl;
    cout << " 5. En un año determinado" << endl;
    cout << " 6. Todas" << endl;

    cin >> op;
    switch (op) {
        case 1:
            caseone(array,i);
            break;
        case 2:
            casetwo(array, 1);
            break;
        case 3:
            break;
        case 4:
            casefour (array,i);
            break;
        case 5:
            casefive (array,i);
            break;
        case 6:
            casesix (array,i);
        default:
            break;
    }
}

void menu(Cliente array[100], Transaccion vector[], int &i) {
    
    int i = 0;
    int op = 5;
    while (op != 3) {
        cout << "¿Que desea hacer?" << endl;
        cout << "1. Cliente" << endl;
        cout << "2. Empleado" << endl;
        cout << "3. Salir" << endl;
        cin >> op;
        switch (op) {
            case 1:
                menuCliente(array, i);
                break;
            case 2:
                menuEmpleado(array, i);
                break;
            case 3:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no válida, intente otra vez" << endl;
                break;
        }
    }
}

int main() {
    int i=0;
    int p=0;
    banco B;
    Cliente array[100];
    Transaccion vector[100];
    menu(array,vector,i);
    B.archivo1.escrituraClientes(array,i);
    B.archivo1.escrituraTransacciones(vector,p);
}
