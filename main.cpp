#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <windows.h>
using namespace std;
struct diputados{
char nombre[30];
char apellido[30];
int Ingreso;    /// Inicio de Mandato
int anio;       ///Fin de Mandato
int codigo;
int partido;
int provincia;
bool Estado;    ///True = Activo - False = Inactivo
};
struct proyectos{
int numero;       /// Proyecto Nº "X"
char nombre[150]; /// Nombre del Proyecto
int dia;
int mes;
int anio; /// Fecha de presentacion
int codigo;   /// Codigo del Diputado
bool Estado;
};
struct sesiones{
int codigoS;    ///Codigo de Sesion
int dia;
int mes;
int anio;
int codigoP;    ///Codigo de Proyecto
int CVA;        ///Cant de votos Afirmativos
int CVN;        ///Cant de votos Negativos
int CA;         ///Cant de Abstensiones
};

#include "dsa.h"
#include "FuncionesGraficas.h"
#include "proyecto.h"
#include "Sesiones.h"
#include "Configuracion.h"
int main()
{
int valor;
int C=0;
bool X=false;
while (true){
system("cls");

        system("color 34");

recuadro(44, 10, 25, 17, cBLANCO, cVERDE);
textcolor(cBLANCO, cVERDE);

gotoxy(45,11);
cout<<"     MENU PRINCIPAL"<<endl;
gotoxy(45,12);
cout<<"------------------------"<<endl;
gotoxy(45,14);
cout<<"1 -    DIPUTADOS"<<endl;
gotoxy(45,16);
cout<<"2 -    PROYECTOS"<<endl;
gotoxy(45,18);
cout<<"3 -    VOTACIONES"<<endl;
gotoxy(45,20);
cout<<"4 -    REPORTES"<<endl;
gotoxy(45,22);
cout<<"5 -    CONFIGURACION"<<endl;
gotoxy(45,24);
cout<<"------------------------"<<endl;
gotoxy(45,26);
cout<<"0 - SALIR DEL PROGRAMA"<<endl;

recuadro(44,31, 25, 2, cBLANCO, cVERDE);
textcolor(cBLANCO, cVERDE);
gotoxy(45,32);
cout << "Ingrese la opcion: ";
gotoxy(65,32);
cin>>(valor);
switch (valor){
case 1:
    switchdiputado();

break;
case 2:
    switchproyecto(C);
    break;
case 3:
    switchSesiones();
    break;
case 4:

    break;
case 5:
    switchconfiguracion();
    break;
case 0:
    return 0;
    break;
}
}}
