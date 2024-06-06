#include <iostream>
#include <fstream>
using namespace std;

class Transaccion{
    private:
    int tipo;
    float monto;
    int mes;
    int ano;

    public:
    Transaccion();
    Transaccion(int mes, int ano,int,float);
    int getDia();
    int getMes();
    int getAño();
    int getTipo();
    float getMonto();
};

class Cuenta{
    private:
    float cajaPeso, cajaDolar;
    public:

    Cuenta();
    Cuenta(float,float);
    void depositar(float, int);
    void extraer(float, int);
    float getCajaPeso();
    float getCajaDolar();
};

class Persona{
    private:
    long dni;
    int añoIngreso;
    string nombre;
    public:
    Persona(long,string,int);
    virtual long getDni();
    virtual string getNombre();
    virtual int getIngreso();
};

class Cliente : public Persona{
    public:
    int estado,nivel;
    Cuenta cuenta;
    Transaccion t;
    public:
    Cliente(long,string,int,int,int,Cuenta);
    long getDni(); 
    string getNombre();
    int getIngreso();
    int getEstado();//0baja 1alta
    int getNivel();// 1plata 2oro 3platino
    float getCajaPeso();
    float getCajaDolar();
    void realizTrans(float, int, int, int mes, int ano);
};

class Empleado : public Persona{
    private:
    string cargo;
    public:
    Empleado(long,string,int,string);
    string getCargo();
    void setCargo(string);
    int getIngreso();
};

class archivo{
    private:

    protected:
    void escritura();
    void lectura();

};

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


class banco {
    public:
    Empleado empleado1;
    Cliente cliente1;
    archivo archivo1;

};