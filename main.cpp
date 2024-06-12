#include <iostream>
#include "clases.h"
#include <string>
using namespace std;

void activarCuenta(Cliente array[],long nroCliente, int j){
    array[j].estado=1;
}

void altaCuenta(Cliente array[], long nroCliente, int& i) {
    bool encontrado = false;
    int op;
    int posCliente = -1;
    for (int j = 0; j < i; j++) {
        if (array[j].getDni() == nroCliente) {
            encontrado = true;
            posCliente = j;
            break;
        }
    }
    if (encontrado) {
        if (array[posCliente].getEstado() == 1) {
            cout << "Ese cliente ya posee una cuenta de banco activa" << endl;
        } else if (array[posCliente].getEstado() == 0) {
            cout << "Ese cliente ya posee una cuenta de banco, pero no se encuentra activa, ¿desea activarla? (0=no; 1=si)" << endl;
            cin >> op;
            if (op == 1) {
                activarCuenta(array, nroCliente, posCliente);
                cout << "Cuenta reactivada exitosamente." << endl;
            }
        }
    } else {
        string nombre;
        float saldoPeso, saldoDolar;
        int nivel;

        cout << "Ingrese su nombre: ";
        cin >> nombre;
        cout << "Ingrese su saldo inicial en pesos: ";
        cin >> saldoPeso;
        cout << "Ingrese su saldo inicial en dólares: ";
        cin >> saldoDolar;

        cout << "¿Qué nivel desea que tenga su cuenta?: " << endl;
        cout << "1. Plata (No tarjeta de crédito)" << endl;
        cout << "2. Oro (Límite de crédito de 250,000)" << endl;
        cout << "3. Platino (Límite de crédito de 500,000)" << endl;
        cin >> nivel;

        if (nivel < 1 || nivel > 3) {
            cout << "Opción no válida" << endl;
        } else {
            Cuenta nuevaCuenta(saldoPeso, saldoDolar);
            Cliente nuevoCliente(nroCliente, nombre, 2024, 1, nivel, nuevaCuenta);
            array[i] = nuevoCliente;
            i++;
            cout << "Cuenta creada exitosamente." << endl;
        }
    }
}
    
void bajaCuenta(Cliente array[], long nroCliente) {
    bool encontrado = false;
    for (int j = 0; j < 100; j++) {
        if (array[j].getDni() == nroCliente) {
            encontrado = true;
            array[j].estado = 0;
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


//AGREGAR EXCEPCION (si el monto de la extraccion sobrepasa el saldo disponible, no se hace)
void operacion(Cliente array[], Transaccion vector[], int nro, int i, int& p){
    
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

                    array[j].realizTrans(monto, op, caja, mes, ano, caja);
                    Transaccion Tr(mes, ano, op, monto, caja);
                    array[j].cuent.t.getMonto();
                    vector[p] = Transaccion(mes, ano, op, monto,caja);
                    p++;
                }
                if ((array[j].getDni() == nro) && (array[j].estado== 0)){
                cout<<"EL cliente está dado de baja."<<endl;
            }
        }
}

void menuCliente(Cliente array[], Transaccion vector[], int &i, int& p) {
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
            operacion(array,vector, nro, i, p);
            break;
        }
        default:{
            cout<<"Saliendo al menú principal..."<<endl;
        break;
        }
    }
}

//Casos del menu empleado
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
/*
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

void casesix (Transaccion vector[],int p){
    cout << "Todas las transacciones: "<< endl;
    for (int j=0;j<=p;j++){
       cout<<vector[j]<<endl;
    }
}

void menuEmpleado(Cliente array[], int i, Transaccion vector[],int p) {
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
        /*
            casethree (array, i);
            */
           break;
        case 4:
            casefour (array,i);
            break;
        case 5:
            casefive (array,i);
            break;
        case 6:
            casesix (vector,p);
        default:
            cout<<"Opción no válida. Saliendo al menú incial..."<<endl;
            break;
    }
}

void menu(Cliente array[100], Transaccion vector[], int &i, int& p) {
    int local_i = 0;
    int op = 5;
    while (op != 3) {
        cout << "¿Que desea hacer?" << endl;
        cout << "1. Cliente" << endl;
        cout << "2. Empleado" << endl;
        cout << "3. Salir" << endl;
        cin >> op;
        switch (op) {
            case 1:
                menuCliente(array,vector,i, p);
                break;
            case 2:
                menuEmpleado(array, i, vector, p);
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

void inicializarArchivoClientes(){
    ofstream archivoClientes("clientes.txt");
    if (!archivoClientes) {
        cerr << "Error al abrir el archivo para escribir los encabezados." << endl;
        return;
    }
    archivoClientes << "dni nombre ingreso estado nivel saldo_pesos saldo_dolares" << endl;
    archivoClientes.close();
}

void inicializarArchivoTrans(){
    ofstream archivoTrans("transacciones.txt");
    if (!archivoTrans) {
        cerr << "Error al abrir el archivo para escribir los encabezados." << endl;
        return;
    }
    archivoTrans << "Mes Año Tipo Caja Monto "<< endl;
    archivoTrans.close();
}

int main() {
    int i=0;
    int p=0;
    banco B;
    Cliente array[100];
    Transaccion vector[100];
    menu(array,vector,i,p);
    inicializarArchivoClientes();
    inicializarArchivoTrans();
    B.archivo1.escrituraClientes(array, i);
    B.archivo1.escrituraTransacciones(vector, p);
}