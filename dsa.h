#ifndef DSA_H_INCLUDED
#define DSA_H_INCLUDED
#include "FuncionesGraficas.h"
int verificacione (struct diputados lelo)
{
    FILE *p;

    struct diputados reg;
    int x;
    p=fopen("diputados.dat","rb");
    while (fread(&reg,sizeof(diputados),1,p)==1)
    {
        if(lelo.codigo==reg.codigo)/*(strcmp(lelo.codigo,reg.codigo)==0)*/
        {
            fclose(p);
            x=1; /// ya usado
            return x;
        }

    }
    fclose(p);
    x=0; /// no usado
    return x;
}

void cargardiputado(struct diputados *lelo)
{
    int verificacion;
    system("cls");

    system("color 45");
    recuadro(7, 2, 45, 2, cCIAN_CLARO,cNEGRO);
    textcolor(cCIAN_CLARO,cNEGRO);
    gotoxy(8,3);
    cout<<"Nombre: ";
    //cin.ignore(29,'\n');
    cin >>lelo->nombre;
    cout<<endl;

    recuadro(55, 2, 45, 2, cCIAN_CLARO,cNEGRO);
    textcolor(cCIAN_CLARO,cNEGRO);
    gotoxy(56,3);
    cout<<"Apellido: ";
    cin >>lelo->apellido;
    cout<<endl;

    recuadro(7, 7, 45, 2, cCIAN_CLARO,cNEGRO);
    textcolor(cCIAN_CLARO,cNEGRO);
    gotoxy(8,8);
    cout<<"Codigo: ";
    cin>>lelo->codigo;
    cout<<endl;
    verificacion=verificacione(*lelo);

    while(verificacion==1)///SI ESTA EN USO , ENTRA PARA INGRESAR EL CODIGO
    {

        //verificacion=verificacione(*lelo);
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
    while(lelo->Ingreso >= 2017)
    {
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
    while(lelo->anio < 2017)
    {
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
    while(lelo->partido <= 0 || lelo->partido > 10)
    {
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
    while(lelo->provincia <= 0 || lelo->provincia > 24 )///COMPRUEBA LA PROVINCIA SI ES MENOR A 24
    {
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

void mostrardiputado(struct diputados esa)
{
    cout << "Nombre y Apellido :"<< esa.nombre;
    cout <<" "<<esa.apellido<<endl;
    cout << "Codigo :"<< esa.codigo<<endl;
    cout << "Codigo de partido :"<< esa.partido<<endl;
    cout << "Codigo de Provincia :"<< esa.provincia<<endl;
    cout << "Inicio de Mandato :"<< esa.Ingreso<<endl;
    cout << "Fin de Mandato :"<< esa.anio<<endl<<endl << endl << endl;
    pause();
}

int BajaAltaLogica(int x)
{
    FILE *p;
    struct diputados reg;
    int codigo;
    p=fopen("diputados.dat","rb+");
    if(p==NULL)
    {
        cout<<"Error de archivo";
        PlaySound(TEXT("Error de Archivo"), NULL, SND_SYNC);
        return 0;
    }
    cout<<"Ingrese el codigo: ";
    cin>>codigo;
    while(fread(&reg, sizeof reg, 1, p)==1)
    {
        if(codigo==reg.codigo && x==0)/*(strcmp(codigo, reg.codigo)==0)*/
        {
            reg.Estado=false;
            fseek(p, ftell(p)-sizeof reg, 0); ///desplazamiento de p un registro hacia atrás
            fwrite(&reg, sizeof reg, 1, p); /// escritura del registro modificado
            fclose(p);
            return 1;
        }
        if(codigo==reg.codigo && x==1)/*(strcmp(codigo, reg.codigo)==0)*/
        {
            reg.Estado=true;
            fseek(p, ftell(p)-sizeof reg, 0); ///desplazamiento de p un registro hacia atrás
            fwrite(&reg, sizeof reg, 1, p); /// escritura del registro modificado
            fclose(p);
            return 1;
        }
    }
    fclose(p);
    return 0;
}
int ContarProyectos(struct diputados reg){
FILE *e;
struct proyectos xd;
int x=0;
e=fopen("proyectos.dat","rb");
while(fread(&xd,sizeof(proyectos),1,e)==1){
    if(xd.codigo==reg.codigo){
        x++;
    }
}
fclose(e);
return x;
}

void listarXanio(){
FILE *p,*t;
int anio,C;
bool XD=false;
struct diputados reg;
p=fopen("diputados.dat","rb");
t=fopen("finalizacion.dat","wb");
cout << "Ingrese el a" "\244" "o de finalizacion: ";
cin >> anio;
while(fread(&reg,sizeof(diputados),1,p)==1){
    if(anio==reg.anio){
        fwrite(&reg,sizeof(diputados),1,t);
        XD=true;
    }
}
fclose(p);
fclose(t);
if(XD==true){
t=fopen("finalizacion.dat","rb");
while(fread(&reg,sizeof(diputados),1,t)==1){
    if(reg.Estado==true){
    cout << "Nombre y Apellido :"<< reg.nombre;
    cout <<" "<<reg.apellido<<endl;
    cout << "Codigo :"<< reg.codigo<<endl;
    cout << "Codigo de partido :"<< reg.partido<<endl;
    cout << "Codigo de Provincia :"<< reg.provincia<<endl;
    cout << "Inicio de Mandato :"<< reg.Ingreso<<endl;
    cout << "Fin de Mandato :"<< reg.anio<<endl;
    C=ContarProyectos(reg);
    cout << "Cantidad de Proyectos Presentados: " << C <<endl << endl << endl;
    pause();
}
}
}
else{
    cout << "No hay un diputado en el año ingresado." << endl;
    system ("pause");
}
}
void listar()
{
    FILE *part;
    struct diputados reg;
    part=fopen("diputados.dat","rb");
    if(part==NULL)
    {
        cout<<"Error de archivo";
        PlaySound(TEXT("Error de Archivo"), NULL, SND_SYNC);
        exit(1);
    }
    while(fread(&reg, sizeof(struct diputados),1,part)==1)
    {
        if(reg.Estado==true)
        {
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
void NuevoDiputado ()
{
    FILE *p;
    struct diputados reg;
    p=fopen("diputados.dat","ab");
    cargardiputado(&reg);
    fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    fread(&reg,sizeof reg,1,p);
    fclose(p);
    mostrardiputado(reg);
    pause();
}
void ordenarporcod(struct diputados *xd, int cant,struct diputados aux){
 int i, j, posmin;

        for(i=0;i<cant-1;i++)
             {
            posmin=i;
            for(j=i+1;j<cant;j++){
                if(xd[j].partido<xd[posmin].partido){
                    posmin=j;}
                    }
            aux=xd[i];
            xd[i]=xd[posmin];
            xd[posmin]=aux;
}
        }

void ordenarporfin(struct diputados *xd, int cant,struct diputados aux){
 int i, j, posmin;

        for(i=0;i<cant-1;i++)
             {
            posmin=i;
            for(j=i+1;j<cant;j++){
                if(xd[j].anio<xd[posmin].anio){
                    posmin=j;}
                    }
            aux=xd[i];
            xd[i]=xd[posmin];
            xd[posmin]=aux;
}
        }

void ordenarporape(struct diputados *xd, int cant,struct diputados aux){
        int i,j,posmin;
        for(i=0;i<cant-1;i++){
            posmin=i;
            for(j=i+1;j<cant;j++){
                if(strcmp(xd[j].apellido, xd[posmin].apellido)<0){
                    posmin=j;
                }}
                aux=xd[i];
                xd[i]=xd[posmin];
                xd[posmin]= aux;

       }
}

void MostrarDipornado(struct diputados xd){
            if(xd.Estado==true){
            cout << "Nombre y Apellido :"<< xd.nombre<<" "<<xd.apellido<<endl;
            cout << "Codigo :"<< xd.codigo<<endl;
            cout << "Codigo de partido :"<< xd.partido<<endl;
            cout << "Codigo de Provincia :"<< xd.provincia<<endl;
            cout << "Inicio de Mandato :"<< xd.Ingreso<<endl;
            cout << "Fin de Mandato :"<< xd.anio<<endl<<endl << endl << endl;
   pause();}
}

void ordenardip(int y) {
    FILE *p;
    long l,a;
    int cant;
    struct diputados *xd;
    int i,j,posmin,c=0;
    struct diputados aux;


    p=fopen("diputados.dat","rb");
        if(p==NULL)
    {
        cout<<"Error de archivo";
        PlaySound(TEXT("Error de Archivo"), NULL, SND_SYNC);
        exit(1);
    }
    fseek(p,0,SEEK_END);
    l=ftell(p);
    a=sizeof(diputados);
    cant=l/a;
    cout << cant << endl;
    xd= (diputados*)malloc(cant*sizeof(struct diputados));
   if(xd==NULL){
    cout<<"Error de Memoria" << endl;
   }
fseek(p,0,0);
    fread(xd,sizeof(struct diputados),cant,p);


    fclose(p);
    if(y==0){
    ordenarporcod(xd,cant,aux);
    }
    if(y==1){
        ordenarporape(xd,cant,aux);
    }
    if(y==2){
        ordenarporfin(xd,cant,aux);
    }
  for (i=0;i<cant;i++)
    {
        MostrarDipornado(xd[i]);
    }
    free(xd);
}

int switchdiputado()
{
    int valor,x,y;
    while (true)
    {
        system ("cls");
        system("color B4");
        recuadro(37, 10, 44, 23, cNEGRO, cAMARILLO);
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
        cout<<"5 -        DAR DE ALTA A UN DIPUTADO";
        gotoxy(38,24);
        cout<<"6 -      MOSTRAR POR A" "\245" "O DE FINALIZACION";
        gotoxy(38,26);
        cout<<"7 -          LISTAR POR APELLIDO";
        gotoxy(38,28);
        cout<<"8 -      LISTA POR A" "\245" "O DE FINALIZACION";
        gotoxy(38,30);
        cout<<"-------------------------------------------"<<endl;
        gotoxy(38,32);
        cout<<"0 -         VOLVER AL MENU ANTERIOR"<<endl;


        recuadro(45,35, 25, 2, cNEGRO, cAMARILLO);
        textcolor(cNEGRO, cAMARILLO);
        gotoxy(47,36);
        cout << "Ingrese la opcion: ";
        gotoxy(67,36);
        cin>>valor;

        switch(valor)
        {
        case 1 :
            NuevoDiputado();
            break;
        case 2:
            listar();
            pause();

            break;
        case 3:
            y=0;
            ordenardip(y);

            break;
        case 4:
            x=0;
            BajaAltaLogica(x);
            break;
        case 5:
            x=1;
            BajaAltaLogica(x);
            break;
        case 6:
            listarXanio();
            break;
        case 7:
            y=1;
            ordenardip(y);
            break;
        case 8:
            y=2;
            ordenardip(y);
            break;
        case 0:
            return 0;
            break ;
        }


    }
}


#endif // DSA_H_INCLUDED
