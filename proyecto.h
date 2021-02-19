#ifndef PROYECTO_H_INCLUDED
#define PROYECTO_H_INCLUDED

 /*void mostrarproyecdip(int codigo){
struct proyectos xd;
struct diputados reg;
FILE *p,*j;
p=fopen("proyectos.dat","rb");
j=fopen("diputados.dat","rb");
while (fread(&xd,sizeof (proyectos),1,p)==1){
  if(codigo==xd.codigo){
        while (fread(&reg,sizeof(diputados),1,j)==1){
                if(xd.codigo==reg.codigo){
    cout<<"Nombre de Proyecto: "<<xd.nombre<<endl;
    cout<<"Fecha Presentacion: "<<xd.dia<<"/"<<xd.mes<<"/"<<xd.anio<<endl;
    cout<<"Numero de Proyecto: "<<xd.numero<<endl;
    cout << "Nombre y Apellido :"<< reg.nombre;
    cout <<" "<<reg.apellido<<endl;
      pause();
  }}
}
fclose(p);
fclose(j);
}
 }*/

 void mostrarpro(proyectos reg){

         cout << "Proyecto N""\247"":"<< reg.numero<<endl;
        cout << "Nombre del Proyecto :"<< reg.nombre<<endl;
        cout <<"Fecha Presentacion "<<reg.dia<<"/"<<reg.mes<<"/"<<reg.anio<<endl;
        cout << "Codigo de Diputado :"<< reg.codigo<<endl;

 }


int verificaexiste(){
FILE *p;
int c=0;
int codigo;
proyectos reg;
  cout<<"ingrese el codigo de diputado: ";
  cin>>codigo;
p=fopen("proyectos.dat","rb");
while(fread(&reg,sizeof reg,1,p)==1){
      if(codigo==reg.codigo){
       mostrarpro(reg);
        system("pause");
        c++;
      }
      }
      if(c==0){
cout<<"El codigo no existe , o no se presento proyecto "<<endl;
system("pause");}
}


int verificacione (struct proyectos lelo)
{
    FILE *p;

    struct diputados reg;
    int x;
    p=fopen("diputados.dat","rb");
    while (fread(&reg,sizeof(diputados),1,p)==1)
    {
        if(lelo.codigo==reg.codigo && reg.Estado==true)/*(strcmp(lelo.codigo,reg.codigo)==0)*/
        {
            fclose(p);
            x=1; /// si existe
            return x;
        }

    }
    fclose(p);
    x=0; /// no existe
    return x;
}

void cargarproyecto(struct proyectos *xd,int l)
{
    int verificacion ;
    xd->numero=l+1;

    cout << "Proyecto N""\247"":" << xd->numero <<endl;
    cout << "Nombre: ";
    cin.ignore(149,'\n');
    cin.getline (xd->nombre,149);
    cout << "Dia: ";
    cin >>xd->dia;
    cout << "Mes: ";
    cin >>xd->mes;
    cout << "Ano: ";
    cin >>xd->anio;
//cout << xd->presentacion << endl;
    cout << endl << "Codigo de Diputado: ";
    cin >> xd->codigo;
    verificacion=verificacione(*xd);
    while (verificacion==0)
    {
        verificacion=verificacione(*xd);
        cout << "Codigo no valido. Ingrese nuevamente: ";
        cin>>xd->codigo;
        verificacion=verificacione(*xd);
        cout << endl;

    }

    PlaySound(TEXT("Proyecto Cargado"), NULL, SND_SYNC);
    system("pause");
    xd->Estado=true;
}
int BajaAltaLogicaP(int x)
{
    FILE *p;
    struct proyectos reg;
    int numero;
    p=fopen("proyectos.dat","rb+");
    if(p==NULL)
    {
        cout<<"Error de archivo";
        PlaySound(TEXT("Error de Archivo"), NULL, SND_SYNC);
        return 0;
    }
    cout<<"Ingrese el codigo: ";
    cin>>numero;
    while(fread(&reg, sizeof reg, 1, p)==1)
    {
        if(numero==reg.numero && x==0)/*(strcmp(codigo, reg.codigo)==0)*/
        {
            reg.Estado=false;
            fseek(p, ftell(p)-sizeof reg, 0); ///desplazamiento de p un registro hacia atrás
            fwrite(&reg, sizeof reg, 1, p); /// escritura del registro modificado
            fclose(p);
            return 1;
        }
        if(numero==reg.numero && x==1)/*(strcmp(codigo, reg.codigo)==0)*/
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

void NuevoProyecto(int a)
{
    FILE *p;
    struct proyectos reg;
    p=fopen("proyectos.dat","rb");
    while (fread(&reg,sizeof(proyectos),1,p)==1)
    {
        a=reg.numero;
    }
    fclose(p);
    p=fopen("proyectos.dat","ab");
    fseek(p,0,SEEK_END);
    long tot=ftell(p);
    int tam=sizeof(proyectos);
    int l=tot/tam;
    cargarproyecto(&reg,l);
    fwrite(&reg,sizeof reg,1,p);
    fclose(p);

}

void listarproyectos()
{
    FILE *part;
    struct proyectos reg;
    part=fopen("proyectos.dat","rb");
    if(part==NULL)
    {
        cout<<"Error de archivo";
        PlaySound(TEXT("Error de Archivo"), NULL, SND_SYNC);
        exit(1);
    }
    while(fread(&reg, sizeof(struct proyectos),1,part)==1)
    {
        if(reg.Estado==true){
      mostrarpro(reg);
        }
    }

    fclose(part);
    system("pause");
}


int switchproyecto (int c)
{
    int valor,x;
    while (true)
    {
        system ("cls");
        cout<<"MENU PROYECTOS"<<endl;
        cout<<"--------------"<<endl;
        cout<<"1 - NUEVO PROYECTO DE LEY"<<endl;
        cout<<"2 - LISTAR TODOS LOS PROYECTOS DE LEY"<<endl;
        cout<<"3 - LISTAR TODOS LOS PROYECTOS DE LEY POR CODIGO DE DIPUTADO"<<endl;
        cout<<"-----------------"<<endl;
        cout<<"0 - VOLVER AL MENU ANTERIOR"<<endl;
        cin>> valor ;
        switch (valor)
        {
        case 1 :
            NuevoProyecto(c);
            break ;
        case 2 :
            listarproyectos();
            break;
        case 3:
            struct diputados xd;
            int codigo;
            verificaexiste();

            break ;
            case 4:
            x=0;
            BajaAltaLogicaP(x);
                break;
            case 5:
                x=1;
                BajaAltaLogicaP(x);
                break;
        case 0:
            return 0;
            break ;
        }
    }

}

#endif // PROYECTO_H_INCLUDED
