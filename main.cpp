#include <iostream>
#include "clases.h"
using namespace std;

void solicitarFecha(int& _dia, int& _mes, int& _año) {
    int dia, mes, año;
    bool fechaValida = false;


    //hacer con excepciones 
    while (!fechaValida) {
        cout << "Ingrese el día: ";
        cin >> dia;
        cout << "Ingrese el mes: ";
        cin >> mes;
        cout << "Ingrese el año: ";
        cin >> año;
        bool esBisiesto = (año % 4 == 0 && año % 100 != 0) || (año % 400 == 0);
        if (año >= 1 && mes >= 1 && mes <= 12 && dia >= 1) {
            int diasEnMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if (mes == 2 && esBisiesto) {
                if (dia <= 29) fechaValida = true;
            } else {
                if (dia <= diasEnMes[mes - 1]) fechaValida = true;
            }
        }
        if (!fechaValida) {
            cout << "Fecha no válida. Inténtelo de nuevo." << endl;
        }
    }
    _dia=dia;
    _mes=mes;
    _año=año;
}

void menuCliente(Cliente array[]){
    int dia,mes,año;
    Cuenta Cu(1000, 500);
    Cliente Cl(12345678, "Juan Perez", 2020, 1, 2, Cu);
    array[0]=Cl;
    int caja,op, monto;

    cout<<"desea abrir una nueva cuenta o dar de baja una existente? (1=nueva, 2=baja)"<<endl;
    cin>>op;
    switch (op)
    {
    case 1:
        cout<<"¿En que caja desea operar? (1=peso , 2=dolar)"<<endl;
        cin>>caja;
        cout<<"¿Que operacion desea realizar?(1= deposito, 2=extraccion)"<<endl;
        cin>>op;
        cout<<"Ingrese el monto"<<endl;
        cin>>monto;
        solicitarFecha(dia,mes,año);

        Cl.realizTrans(monto, op, caja, mes,año);
        Transaccion Tr(mes, año,op, monto );
        Cl.cuent.t.getMonto();
        break;
    
    case 2:
        // ESTABLECER METODO DE BUSQUEDA DE CLIENTE
        break;
    default:
        break;
    }


    
}
    
void menuEmpleado(){
    int op;
    Empleado(43385086, "JUan Bergia", 2024, "Gerente");
    cout<<"¿que desea hacer?"<<endl;
    cout<<"1. Detalle de cliente por numero de cliente"<<endl;
    cout<<"2. Listado de todos los clientes en el banco"<<endl;
    cout<<"3. Listado de transacciones por cliente"<<endl;
    cout<<"Informes de extracciones y depósitos según los siguiente criterios:"<<endl;
    cout<<" 4. En un mes determinado"<<endl;
    cout<<" 5. En un año determinado"<<endl;
    cout<<" 6. Todas"<<endl;

    cin>>op;
    switch (op)
    {
    case 1:
        
        break;
    case 2:
        
        break;
    case 3:
        
        break;
    case 4:
        
        break;
    case 5:
        
        break;
    case 6:
        
        break;

    default:
        break;
    }
}

void menu(){
    Cliente array[100];
    int op=5;
    while(op!=3){
        cout<<"¿Que desea hacer?"<<endl;
        cout<<"1. Cliente"<<endl;
        cout<<"2. Empleado"<<endl;
        cout<<"3. Salir"<<endl;
        cin>>op;
        switch (op)
        {
        case 1:
            menuCliente(array);
            break;
        case 2:
            menuEmpleado();
            break;
        case 3:
            break;
        default:
        cout<<"Opcion no válida, intente otra vez"<<endl;
            break;
        }
    }
}


int main() {
    menu();
}