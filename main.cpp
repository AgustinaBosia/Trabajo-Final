#include <iostream>
#include "clases.h"
using namespace std;

void solicitarFecha(int& _dia, int& _mes, int& _año) {
    int dia, mes, año;
    bool fechaValida = false;

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

void menuCliente(){
    int dia,mes,año;
    Cuenta Cu(1000, 500);
    Cliente Cl(12345678, "Juan Perez", 2020, 1, 2, Cu);
    int caja,op, monto;
    cout<<"¿En que caja desea operar? (1=peso , 2=dolar)"<<endl;
    cin>>caja;
    cout<<"¿Que operacion desea realizar?(1= deposito, 2=extraccion)"<<endl;
    cin>>op;
    cout<<"Ingrese el monto"<<endl;
    cin>>monto;
    solicitarFecha(dia,mes,año);
    Fecha F(dia,mes,año);
    Cl.realizTrans(monto, op, caja, F);
}
    
void menuEmpleado(){
    Empleado(43385086, "JUan Bergia", 2024, "Gerente");
}

void menuDueño(){}

void menu(){
    int op=5;
    while(op>4||op<0){
        cout<<"¿Que desea hacer?"<<endl;
        cout<<"1. Cliente"<<endl;
        cout<<"2. Empleado"<<endl;
        cout<<"3. Dueño"<<endl;
        cout<<"4. Salir"<<endl;
        cin>>op;
        switch (op)
        {
        case 1:
            menuCliente();
            break;
        case 2:
            menuEmpleado();
            break;
        case 3:
            menuDueño();
            break;
        case 4:
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