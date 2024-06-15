#include <iostream>
#include "clases.h"
using namespace std;

void verifInt(int& dato){
    while (true){
        try{
            cin>>dato;
            if (cin.fail()){
                throw invalid_argument ("Se esperaba un dato del tipo entero.");
            } else {
                break;
            }
        }
    catch (const invalid_argument& e) {
            cin.clear(); // limpia el estado de error del cin>>
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignora los datos erroneos q quedaton en el buffer
            cout << "Error: " << e.what() << endl;
            cout << "Por favor, ingrese un número válido." << endl;
        }
    }
}

//MENU CLIENTE (ALTAS BAJAS Y OP)

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
            verifInt(op);
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
            

            nombre=array[i].getNombre();

            if (array[i].getNivel()==1){
                
                nombre="plata";
                array[i].tarjetaCredit(nombre);
            }
            else if(array[i].getNivel()==2){
                
                nombre="oro";
                array[i].tarjetaCredit(nombre);
            }
            else if(array[i].getNivel()==3){
                
                nombre="platino";
                array[i].tarjetaCredit(nombre);
            }

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

void operacion(Cliente array[], Transaccion vector[], int nro, int i, int& p, int &a) {
    bool clienteEncontrado = false;
    string titular;
    try {
        for (int j = 0; j < i; j++) {
            if (array[j].getDni() == nro) {
                titular = array[j].getNombre();
                clienteEncontrado = true;

                if (array[j].estado == 0) {
                    throw "El cliente está dado de baja.";
                }

                int mes, ano, caja, op;
                float monto;
                solicitarFecha(mes, ano);
                cout << "¿En qué caja desea operar? (1=peso, 2=dólar)" << endl;
                cin >> caja;
                cout << "¿Qué operación desea realizar? (1=depósito, 2=extracción)" << endl;
                cin >> op;
                cout << "Ingrese el monto: " << endl;
                cin >> monto;

                if (((monto > array[j].getCajaPeso()) && (op == 2) && (caja == 1)) || 
                    ((monto > array[j].getCajaDolar()) && (op == 2) && (caja == 2))) {
                    throw "El monto de la extracción no puede superar la cantidad de dinero disponible en caja.";
                } else if (monto <= 0) {
                    throw "El monto a depositar debe ser mayor a 0.";
                } else {
                    array[j].realizTrans(monto, op, caja, mes, ano, caja, titular);
                    Transaccion Tr(mes, ano, op, monto, caja, titular);
                    vector[p] = Tr;
                    array[j].transacciones[a] = Tr;
                    p++;
                    a++;
                    cout << "Transacción realizada exitosamente." << endl;
                }
                return;
            }
        }
        if (!clienteEncontrado) {
            throw "El DNI ingresado no corresponde a ningún cliente del banco.";
        }
    } catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }
}

void menuCliente(Cliente array[], Transaccion vector[], int &i, int& p, int &a) {
    long nro;
    int op;

    cout << "Ingrese el nro de Cliente (su DNI): "<<endl;

    while (true) {
        try {
            cin >> nro;
            if (cin.fail()) {
                throw invalid_argument("Se esperaba un dato del tipo long.");
            } else {
                break;
            }
        }
        catch (const invalid_argument& e) {
            cin.clear(); // Limpia el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora los caracteres restantes en el buffer
            cout << "Error: " << e.what() << endl;
            cout << "Por favor, ingrese un número válido." << endl;
        }
    }
    

    cout << "Desea: " << endl;
    cout << "1=Dar de alta una cuenta" << endl;
    cout << "2=Dar de baja una cuenta" << endl;
    cout << "3=Realizar una operación en una cuenta existente" << endl;
    cout << "4=Salir" << endl;
    cin >> op;
    
    try {
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
            operacion(array,vector, nro, i, p, a);
            break;
        }
        case 4:
            cout<<"Saliendo al menú principapl..."<<endl;
            break;
        default:
            throw "Opción no válida.";
        break;
        }
    }
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }
}

//CMENU EMPLEADO (CASOS)
void caseone(Cliente array[], int i){
    int a,b=-1;
    cout <<"Ingrese el nÚmero de cliente a buscar: "<<endl;
    cin>> a;
    try {
    for (int j = 0; j <= i; j++) {
        if (array[j].dni == a){
            b=j;
        }
    }
    if(b!=-1){
        cout<<"Aquí los detalles del cliente buscado:"<<endl;
        cout << array[b] << endl;
    }
    else{
        throw "No existe cliente con ese número.";
    }
}
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }
}

void casetwo(Cliente array[], int i) {
    for (int j = 0; j < i; j++) {
        cout<<j+1<<") "<<"cliente nro: "<<array[j].dni<<", nombre: "<<array[j].nombre<<endl;
    }
}

void casethree (Transaccion vector [], int p, Cliente array[], int a){
    long dni; 
    bool encontrado= false;
    cout << "Ingrese el número de cliente (DNI) para ver sus transacciones: "<<endl;
    cin >> dni;
    try {
    cout << "Transacciones del cliente con DNI "<<dni<< ":"<<endl;
    for (int j=0; j<p;j++){
        if (array [j].getDni()==dni){
            encontrado=true;
            for(int i=0; i<a-1; i++){
                cout << "Mes: "<<array[j].transacciones[i]<<endl;
            }
            
        }
    }
    if (!encontrado){
        throw "El número ingresado no pertenece a ningun cliente del banco.";
    }
    }
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }
}

void casefour (Transaccion vector[], int p){
    int mes,ano; 
    try {
    cout << "Ingrese el mes (1-12): ";
    cin >> mes;
        if ((mes<1)||mes>12){
            throw "El mes no puede ser mayor a 12 ni menor a 1.";
        } else {
            cout << "Transacciones en el mes "<<mes<< ":"<<endl;
            for (int j=0;j<p;j++){
                if (vector[j].getMes()==mes){
                    cout<<vector[j]<<endl;
                }
            }
        }
    }
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }
}

void casefive (Transaccion vector [],int p){
    int ano;
    try {
    cout << "Ingrese el año: ";
    cin >> ano;
    if (ano<1){
        throw "El año no puede ser menor a 1.";
    } else {
        cout << "Transacciones en el año"<< ano<< ":"<<endl;
        for (int j=0;j<p;j++){
            if (vector[j].getAño()==ano){
                cout<<vector[j]<<endl;
            }
        }
    }
    }
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }
}

void casesix (Transaccion vector[],int p){
    cout << "Todas las transacciones: "<< endl;
    for (int j=0;j<p;j++){
       cout<<vector[j]<<endl;
    }
}

void menuEmpleado(Cliente array[], int i, Transaccion vector[],int p, int a) {
    int op;
    Empleado(43385086, "Juan Bergia", 2024, "Gerente");
    cout << "¿que desea hacer?" << endl;
    cout << "1. Detalle de cliente por numero de cliente" << endl;
    cout << "2. Listado de todos los clientes en el banco" << endl;
    cout << "3. Listado de transacciones por cliente" << endl;
    cout << "Informes de extracciones y depósitos según los siguiente criterios:" << endl;
    cout << "   4. En un mes determinado" << endl;
    cout << "   5. En un año determinado" << endl;
    cout << "   6. Todas" << endl;
    cout << "   7. Salir" << endl;

    cin >> op;
    try{
    switch (op) {
        case 1:
            caseone(array,i);
            break;
        case 2:
            casetwo(array, 1);
            break;
        case 3:
        
            casethree (vector, p, array,a);
            
           break;
        case 4:
            casefour (vector,p);
            break;
        case 5:
            casefive (vector,p);
            break;
        case 6:
            casesix (vector,p);
            break;
        case 7:
            cout<<"Saliendo al menú principal..."<<endl;
        default:
            throw "Opción no válida.";
            break;
    }
    }
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }
}

void menu(Cliente array[100], Transaccion vector[], int &i, int& p, int&a) {
    int local_i = 0;
    int op = 5;
    while (op != 3) {
        cout << "¿Que desea hacer?" << endl;
        cout << "1. Cliente" << endl;
        cout << "2. Empleado" << endl;
        cout << "3. Salir" << endl;
        cin >> op;
        try{
        switch (op) {
            case 1:
                menuCliente(array,vector,i, p,a);
                break;
            case 2:
                menuEmpleado(array, i, vector, p,a);
                break;
            case 3:
                cout << "Saliendo..." << endl;
                break;
            default:
                throw "Opción no válida";
        }
        }
        catch (const char* msg) {
        cout << "Error: " << msg << endl;
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
    archivoTrans << "Mes Año Tipo Caja Monto Titular"<< endl;
    archivoTrans.close();
}

int main() {
    int i=0;
    int p=0;
    int a=0;
    banco B;
    Cliente array[100];
    Transaccion vector[100];
    inicializarArchivoClientes();
    inicializarArchivoTrans(); 

    menu(array,vector,i,p,a);
    
    B.archivo1.escrituraClientes(array, i);
    B.archivo1.escrituraTransacciones(vector, p);
}