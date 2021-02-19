#ifndef DSA_H_INCLUDED
#define DSA_H_INCLUDED
#include "FuncionesGraficas.h"
int verificacione (struct diputados lelo){
 FILE *p;

 struct diputados reg;
 int x;
 p=fopen("diputados.dat","rb");
 while (fread(&reg,sizeof(diputados),1,p)==1){
  if(lelo.codigo==reg.codigo)/*(strcmp(lelo.codigo,reg.codigo)==0)*/{
    fclose(p);
    x=1; /// ya usado
    return x;
  }

 }
 fclose(p);
    x=0; /// no usado
    return x;
}


void cargardiputado(struct diputados *lelo){
int verificacion;
system("cls");

system("color 45");
recuadro(7, 2, 45, 2, cCIAN_CLARO,cNEGRO);
textcolor(cCIAN_CLARO,cNEGRO);
gotoxy(8,3);
cout<<"Nombre: ";
    cin.ignore(29,'\n');
    cin.getline (lelo->nombre,29);
cout<<endl;

recuadro(55, 2, 45, 2, cCIAN_CLARO,cNEGRO);
textcolor(cCIAN_CLARO,cNEGRO);
gotoxy(56,3);
cout<<"Apellido: ";
    cin.ignore(29,'\n');
    cin.getline (lelo->apellido,29);
cout<<endl;

recuadro(7, 7, 45, 2, cCIAN_CLARO,cNEGRO);
textcolor(cCIAN_CLARO,cNEGRO);
gotoxy(8,8);
cout<<"Codigo: ";
cin>>lelo->codigo;
cout<<endl;
verificacion=verificacione(*lelo);

while(verificacion==1){


recuadro(7, 7, 45, 2, cCIAN_CLARO,cNEGRO);
textcolor(cCIAN_CLARO,cNEGRO);
gotoxy(8,8);
cout << "Codigo no valido. Ingrese nuevamente: ";
cin>>lelo->codigo;
verificacion=verificacione(*lelo);
cout << endl;
}

recuadro(55, 7, 45, 2, cCIAN_CLARO,cNEGRO);
textcolor(cCIAN_CLARO,cNEGRO);
gotoxy(56,8);
cout<<"Inicio de Mandato: ";
cin>>lelo->Ingreso;
cout<<endl;
while(lelo->Ingreso >= 2017){
recuadro(55, 7, 45, 2, cCIAN_CLARO,cNEGRO);
textcolor(cCIAN_CLARO,cNEGRO);
gotoxy(56,8);
cout << "Ingreso no valido. Ingrese nuevamente: ";
cin>>lelo->Ingreso;
cout << endl;
}

recuadro(7, 12, 45, 2, cCIAN_CLARO,cNEGRO);
textcolor(cCIAN_CLARO,cNEGRO);
gotoxy(8,13);
cout<<"Fin de Mandato: ";
cin>>lelo->anio;
cout<<endl;
while(lelo->anio < 2017){
recuadro(7, 12, 45, 2, cCIAN_CLARO,cNEGRO);
textcolor(cCIAN_CLARO,cNEGRO);
gotoxy(8,13);
cout << "Ingreso no valido. Ingrese nuevamente: ";
cin>>lelo->anio;
cout << endl;
}

recuadro(55, 12, 45, 2, cCIAN_CLARO,cNEGRO);
textcolor(cCIAN_CLARO,cNEGRO);
gotoxy(56,13);
cout<<"Partido: ";
cin>>lelo->partido;
cout<<endl;
while(lelo->partido <= 0 || lelo->partido > 10){
recuadro(55, 12, 45, 2, cCIAN_CLARO,cNEGRO);
textcolor(cCIAN_CLARO,cNEGRO);
gotoxy(56,13);
cout << "Ingreso no valido. Ingrese nuevamente: ";
cin>>lelo->partido;
cout<<endl;
}

recuadro(24, 17, 45, 2, cCIAN_CLARO,cNEGRO);
textcolor(cCIAN_CLARO,cNEGRO);
gotoxy(25,18);
cout<<"Provincia: ";
cin>>lelo->provincia;
cout << endl;
while(lelo->provincia <= 0 || lelo->provincia > 24 ){
cout << "Ingreso no valido. Ingrese nuevamente: ";
cin>>lelo->provincia;
cout << endl;

}
lelo->Estado=true;
gotoxy(30,22);
cout<<"Diputado cargado con exito ! " << endl << endl;

PlaySound(TEXT("Diputado Cargado"), NULL, SND_SYNC); ///Introduce sonido

system("pause");
}

void mostrardiputado(struct diputados esa) {
cout << "Nombre y Apellido :"<< esa.nombre;
cout <<" "<<esa.apellido<<endl;
cout << "Codigo :"<< esa.codigo<<endl;
cout << "Codigo de partido :"<< esa.partido<<endl;
cout << "Codigo de Provincia :"<< esa.provincia<<endl;
cout << "Inicio de Mandato :"<< esa.Ingreso<<endl;
cout << "Fin de Mandato :"<< esa.anio<<endl<<endl << endl << endl;
system("pause");
}

int BajaLogica(){
 FILE *p;
 struct diputados reg;
 int codigo;
 p=fopen("diputados.dat","rb+");
 if(p==NULL)
 { cout<<"Error de archivo";
 PlaySound(TEXT("Error de Archivo"), NULL, SND_SYNC);
 return 0; }
 cout<<"Ingrese el codigo: ";
 cin>>codigo;
 while(fread(&reg, sizeof reg, 1, p)==1)
 {
 if(codigo==reg.codigo)/*(strcmp(codigo, reg.codigo)==0)*/
 {
 reg.Estado=false;
 fseek(p, ftell(p)-sizeof reg, 0); ///desplazamiento de p un registro hacia atrás
 fwrite(&reg, sizeof reg, 1, p); /// escritura del registro modificado
 fclose(p);
 return 1;
 }
 }
 fclose(p);
 return 0;
}

void listar()
{
FILE *part;
struct diputados reg;
part=fopen("diputados.dat","rb");
if(part==NULL)
{ cout<<"Error de archivo";
PlaySound(TEXT("Error de Archivo"), NULL, SND_SYNC);
exit(1);
}
while(fread(&reg, sizeof(struct diputados),1,part)==1)
{
    if(reg.Estado==true){
cout << "Nombre y Apellido :"<< reg.nombre<<" "<<reg.apellido<<endl;
cout << "Codigo :"<< reg.codigo<<endl;
cout << "Codigo de partido :"<< reg.partido<<endl;
cout << "Codigo de Provincia :"<< reg.provincia<<endl;
cout << "Inicio de Mandato :"<< reg.Ingreso<<endl;
cout << "Fin de Mandato :"<< reg.anio<<endl<<endl << endl << endl;
}
}
fclose(part);
system("pause");
}
void NuevoDiputado (){
    FILE *p;
struct diputados reg;
    p=fopen("diputados.dat","ab");
    cargardiputado(&reg);
    fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    fread(&reg,sizeof reg,1,p);
    fclose(p);
    mostrardiputado(reg);
}

int switchdiputado(){
    int valor;
    while (true){
        system ("cls");
        system("color B4");
    recuadro(37, 10, 44, 15, cNEGRO, cAMARILLO);
textcolor(cNEGRO, cAMARILLO);

gotoxy(38,11);
cout<<"               MENU DIPUTADOS"<<endl;
gotoxy(38,12);
cout<<"-------------------------------------------"<<endl;
gotoxy(38,14);
cout<<"1 -            NUEVO DIPUTADO"<<endl;
gotoxy(38,16);
cout<<"2 -      LISTAR TODOS LOS DIPUTADOS"<<endl;
gotoxy(38,18);
cout<<"3 -  LISTAR DIPUTADO POR CODIGO DE PARTIDO"<<endl;
gotoxy(38,20);
cout<<"4 -         DAR DE BAJA UN DIPUTADO"<<endl;
gotoxy(38,22);
cout<<"-------------------------------------------"<<endl;
gotoxy(38,24);
cout<<"0 -         VOLVER AL MENU ANTERIOR"<<endl;


recuadro(45,27, 25, 2, cNEGRO, cAMARILLO);
textcolor(cNEGRO, cAMARILLO);
gotoxy(47,28);
cout << "Ingrese la opcion: ";
gotoxy(67,28);
cin>>valor;

switch(valor){
case 1 :
    NuevoDiputado();
    break;
case 2:
listar();
break;
case 3:

    break;
case 4:
    BajaLogica();
    break;
case 0:
    return 0;
    break ;
}


}}



#endif // DSA_H_INCLUDED
