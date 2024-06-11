#include <iostream>
#include "clases.h"
using namespace std;

void altaCuenta(Cliente array[], int nroCliente, Cliente& cliente) {

    bool encontrado = true;
    for (int j = 0; j < 100; j++) {
        if (array[j].getDni() == nroCliente) {
            encontrado = true;
            cout << "Ese cliente ya posee una cuenta de banco" << endl;
            break;
        }
    }
    if (!encontrado) {
        float saldoPeso, saldoDolar;
        cout << "Ingrese el saldo inicial en pesos: ";
        cin >> saldoPeso;
        cout << "Ingrese el saldo inicial en dolares: ";
        cin >> saldoDolar;
        Cuenta nuevaCuenta(saldoPeso, saldoDolar);
        cliente.cuent = nuevaCuenta;
        cout << "Cuenta creada exitosamente." << endl;
    }
    
}


//VER!!!!!!!!!!!!!!!
void bajaCuenta(Cliente array[], int nroCliente) {
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

void menuCliente(Cliente array[], int &i) {
    //VER (tratar de que solicite los datos del cliente al hacer las altas y bajas)
    int mes, ano, nro;
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

    Cliente Cl(nro, "Juan Perez", 2020, 1, 2, Cu);
    array[i] = Cl;
    i++;
    

    
    switch (op) {
        case 1:{
            altaCuenta(array,nro,array[i-1]);
            break;
        }
        case 2:{
            bajaCuenta(array, nro);
            break;
        }
        case 3: {
            for (int j=0; j < (i-1); j++){
                if ((array[j].getDni() == nro) && (array[j].estado!= 0)){
                    cout << "¿En que caja desea operar? (1=peso, 2=dolar)" << endl;
                    cin >> caja;
                    cout << "¿Que operacion desea realizar?(1=deposito, 2=extraccion)" << endl;
                    cin >> op;
                    cout << "Ingrese el monto" << endl;
                    cin >> monto;
                    solicitarFecha(mes, ano);
                    Cl.realizTrans(monto, op, caja, mes, ano);
                    Transaccion Tr(mes, ano, op, monto);
                    Cl.cuent.t.getMonto();
                }
                if ((array[j].getDni() == nro) && (array[j].estado== 0)){
                cout<<"EL cliente está dado de baja."<<endl;
            }
            }
    
            break;
        }
        default:{
        break;
        }
    }
}

void casetwo(Cliente array[], int i) {
    for (int j = 0; j <= i; j++) {
        cout << array[j] << endl;
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
            cout << "nada" << endl;
            break;
        case 2:
            casetwo(array, 1);
            break;
        case 3:
            cout << "nada" << endl;
            break;
        case 4:
            cout << "nada" << endl;
            break;
        case 5:
            cout << "nada" << endl;
            break;
        case 6:
            cout << "nada" << endl;
            break;
        default:
            break;
    }
}

void menu(Cliente array[100]) {
    
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
                cout << "chau" << endl;
                break;
            default:
                cout << "Opcion no válida, intente otra vez" << endl;
                break;
        }
    }
}

int main() {
    Cliente array[100];

    menu(array);
    
}
