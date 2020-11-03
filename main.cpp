#include <iostream>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *der;
    Nodo *izq;
}
;

Nodo *arbol = nullptr;
Nodo *crear_nodo(int);
void insertar_nodo(Nodo *&,int);
void preorden(Nodo *);
void inorden(Nodo *);
void postorden(Nodo *);

int main()
{
    unsigned int opc;
    int dat;
    while(true)
    {
        cout<<"\t\t Menu"<<endl;
        cout<<"\n 1.- Agregar"<<endl;
        cout<<"2.- Recorrido en PreOrden"<<endl;
        cout<<"3.- Recorrido en PostOrden"<<endl;
        cout<<"4.- Recorrido en InOrden"<<endl;
        cout<<"5.- Salir "<<endl;
        cout<<"\n Selecione opcion -> ";
        cin>>opc;
        if(opc==1){
            cout<<"\n\t\t Agregar dato al arbol \n"<<endl;
            cout<<" Ingrese un numero: ";
            cin>>dat;
            insertar_nodo(arbol,dat);
            cout<<"\n Dato agregado al arbol "<<endl;}
        else if(opc==2){
            if(arbol == nullptr)
                cout<<"\n Arbol vacio"<<endl;
            else
            {
                cout<<"\n Recorrido en PreOrden \n"<<endl;

                cout<<"\n\n";
                system("pause");
            }
        }
        else if(opc==3)
        {
            if(arbol == nullptr)
                cout<<"\n Arbol vacio"<<endl;
            else
            {
                cout<<"\n Recorrido en PostOrden \n"<<endl;

                cout<<"\n\n";
                system("pause");
            }
        }
        else if(opc==4)
        {
            if(arbol == nullptr)
                cout<<"\n Arbol vacio"<<endl;
            else
            {
                cout<<"\n Recorrido en InOrden \n"<<endl;

                cout<<"\n\n";
                system("pause");
            }

        }
        else if(opc==5)
        {
            break;
        }
    }
    return 0;
}

Nodo *crear_nodo(int dato)
{
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = dato;
    nuevo_nodo->der = nullptr;
    nuevo_nodo->izq = nullptr;

    return nuevo_nodo;
}

void insertar_nodo(Nodo *&arbol, int dato)
{
    if (arbol == nullptr)
    {
        Nodo *nuevo_nodo = crear_nodo(dato);
        arbol = nuevo_nodo;
    }
    else
    {
        int raiz = arbol->dato;
        if(dato < raiz)
            insertar_nodo(arbol->izq,dato);
        else
            insertar_nodo(arbol->der,dato);
    }
}

void preorden(Nodo *arbol)
{
    if(arbol == nullptr)
        return;
    else
    {
        cout<<arbol->dato<<" - ";
        preorden(arbol->izq);
        preorden(arbol->der);
    }
}

void inorden(Nodo *arbol)
{
    if(arbol == nullptr)
        return;
    else
    {
        inorden(arbol->izq);
        cout<<arbol->dato<<" - ";
        inorden(arbol->der);
    }
}

void postorden(Nodo *arbol)
{
    if(arbol == nullptr)
        return;
    else
    {
        postorden(arbol->izq);
        postorden(arbol->der);
        cout<<arbol->dato<<" - ";
    }
}
