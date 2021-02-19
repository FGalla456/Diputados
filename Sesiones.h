#ifndef SESIONES_H_INCLUDED
#define SESIONES_H_INCLUDED
int verificacione (struct sesiones lelo)
{
    FILE *p;

    struct proyectos reg;
    int x;
    p=fopen("proyectos.dat","rb");
    while (fread(&reg,sizeof(proyectos),1,p)==1)
    {
        if(lelo.codigoP==reg.numero && reg.Estado==true)/*(strcmp(lelo.codigo,reg.codigo)==0)*/
        {
            fclose(p);
            x=1; /// existe
            return x;
        }

    }
    fclose(p);
    x=0; /// no existe
    return x;
}

int listarSP(){
FILE *p;
int codigoS,codigoP;
struct sesiones reg;
p=fopen("sesiones.dat","rb");
cout << "Codigo de Sesion: " << endl;
cin >> codigoS;
cout << "Codigo de Proyecto: " << endl;
cin >> codigoP;
while(fread(&reg,sizeof(sesiones),1,p)==1){
    if (codigoS==reg.codigoS && codigoP==reg.codigoP && codigoP!=0 && codigoS!=0){
     cout << "Codigo de Sesion: "<< reg.codigoS<<endl;
        cout << "Codigo de Proyecto: "<< reg.codigoP <<endl;
    //  cout << "Fecha: "<<reg.dia<<"/"<<reg.mes<<"/"<<reg.anio<<endl;
        cout << "Cantidad de votos Afirmativos: "<< reg.CVA <<endl;
        cout << "Cantidad de Votos Negativos: " << reg.CVN << endl;
        cout << "Cantidad de Abstenciones: " << reg.CA << endl;
        system("pause");
    return 0;
 }
}
cout << "No existe esa combinacion" << endl;
system("pause");
return 0;
}



void cargarSesiones(struct sesiones *reg)
{
    int verificacion;

    cout << "Codigo de Sesion: ";
    cin >> reg->codigoS;

    cout << "Fecha: " << endl;
    cout << "Dia: ";
    cin >>reg->dia;
    cout << "Mes: ";
    cin >>reg->mes;
    cout << "Ano: ";
    cin >>reg->anio;
    cout << "Codigo de Proyecto: ";
    cin >> reg->codigoP;
    verificacion=verificacione(*reg);
    while (verificacion==0)
    {
        cout << "Codigo Inexistente.Ingrese nuevamente: ";
        cin >> reg->codigoP;
        verificacion=verificacione(*reg);
    }
    cout << "Cantidad de Votos Afirmativos:";
    cin >> reg->CVA;
    while(reg->CVA < 0)
    {
        cout << "Cantidad de Votos Afirmativos:";
        cin >> reg->CVA;
    }
    cout << "Cantidad de Votos Negativos:";
    cin >> reg->CVN;
    while(reg->CVN < 0)
    {
        cout << "Cantindad de Votos Negativos:";
        cin >> reg->CVN;
    }
    cout << "Cantidad de Abstenciones:";
    cin >> reg->CA;
    while(reg->CA < 0)
    {
        cout << "Cantidad de Abstenciones:";
        cin >> reg->CA;
    }
}

int EditarSesion()
{
    FILE *p;
    struct sesiones reg;
    int codigoS,codigoP;
    p=fopen("sesiones.dat","rb+");
    if(p==NULL)
    {
        cout<<"Error de archivo";
        PlaySound(TEXT("Error de Archivo"), NULL, SND_SYNC);
        return 0;
    }
    cout<<"Ingrese el Codigo de Sesion: ";
    cin>>codigoS;
    cout << "Ingrese el Codigo de Proyecto: ",
         cin >>codigoP;
    while(fread(&reg, sizeof reg, 1, p)==1)
    {
        if(codigoS==reg.codigoS && codigoP==reg.codigoP)/*(strcmp(codigo, reg.codigo)==0)*/
        {
            cout << "Cantidad de Votos Afirmativos:";
            cin >> reg.CVA;
            while(reg.CVA < 0)
            {
                cout << "Cantidad de Votos Afirmativos:";
                cin >> reg.CVA;
            }
            cout << "Cantidad de Votos Negativos:";
            cin >> reg.CVN;
            while(reg.CVN < 0)
            {
                cout << "Cantindad de Votos Negativos:";
                cin >> reg.CVN;
            }
            cout << "Cantidad de Abstenciones:";
            cin >> reg.CA;
            while(reg.CA < 0)
            {
                cout << "Cantidad de Abstenciones:";
                cin >> reg.CA;
            }
            fseek(p, ftell(p)-sizeof reg, 0); ///desplazamiento de p un registro hacia atrás
            fwrite(&reg, sizeof reg, 1, p); /// escritura del registro modificado
            fclose(p);
            return 1;
        }
    }
    fclose(p);
    return 0;
}

void SesionNueva()
{
    FILE *p;
    struct sesiones reg;
    p=fopen("sesiones.dat","ab");
    cargarSesiones(&reg);
    fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    fread(&reg,sizeof reg,1,p);
    fclose(p);
///    mostrardiputado(reg);

}

void mostratsesiones()
{
   FILE *part;
    struct sesiones reg;
    part=fopen("sesiones.dat","rb");
    if(part==NULL)
    {
        cout<<"Error de archivo";
        PlaySound(TEXT("Error de Archivo"), NULL, SND_SYNC);
        exit(1);
    }
    while(fread(&reg, sizeof(struct sesiones),1,part)==1)
    {
        cout << "Codigo de Sesion: "<< reg.codigoS<<endl;
        cout << "Codigo de Proyecto: "<< reg.codigoP <<endl;
    //   cout << "Fecha: "<<reg.dia<<"/"<<reg.mes<<"/"<<reg.anio<<endl;
        cout << "Cantidad de votos Afirmativos: "<< reg.CVA <<endl;
        cout << "Cantidad de Votos Negativos: " << reg.CVN << endl;
        cout << "Cantidad de Abstenciones: " << reg.CA << endl;
    }
    fclose(part);
    system("pause");
}
int switchSesiones()
{
    int opcion;
    while(true)
    {
        system("cls");
        cout << "MENU SESIONES" << endl;
        cout << "--------------" << endl;
        cout << "1 - NUEVA SESION" << endl;
        cout << "2 - EDITAR SESION" << endl;
        cout << "3 - LISTAR SESIONES" << endl;
        cout << "4 - LISTAR SESION POR CODIGO" << endl;
        cout << "-----------------" << endl;
        cout << "0 - VOLVER AL MENU ANTERIOR" << endl;
        cin >> opcion;
        switch(opcion)
        {
        case 1:
            SesionNueva();
            break;
        case 2:
            EditarSesion();

            break;
        case 3:

           mostratsesiones();
            break;
        case 4:
        listarSP();
            break;
        case 0:
            return 0;
            break;
        }
    }
}
#endif // SESIONES_H_INCLUDED
