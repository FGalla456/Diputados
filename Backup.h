#ifndef PROYECTO_H_INCLUDED
#define PROYECTO_H_INCLUDED
int verificacione (struct proyectos lelo)
{
    FILE *p;

    struct diputados reg;
    int x;
    p=fopen("diputados.dat","rb");
    while (fread(&reg,sizeof(diputados),1,p)==1)
    {
        if(strcmp(lelo.codigo,reg.codigo)==0)
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



void Fecha(){
  time_t tiempo;
  char cad[80];
  struct tm *tmPtr;

  tiempo = time(NULL);
  tmPtr = localtime(&tiempo);
  printf(/*"FECHA ACTUAL*//* \n*/"%d/%d/%d %d:%d:%d", tmPtr->tm_mday, tmPtr->tm_mon+1, 1900+tmPtr->tm_year, tmPtr->tm_hour, tmPtr->tm_min, tmPtr->tm_sec);

 // strftime(cad, 80, "%A %d de %B de %Y", tmPtr);
 // printf("\n\n%s", cad);
}

void cargarproyecto(struct proyectos *xd,int a){
    a++;
    int verificacion ;
    xd->numero=a;


cout << "Proyecto N""\247"":" << xd->numero <<endl;
cout << "Nombre: ";
cin >> xd->nombre;
cout << "Presentacion: ";
/*xd->presentacion=*/Fecha();
//cout << xd->presentacion << endl;
cout << endl << "Codigo de Diputado: ";
cin >> xd->codigo;
 verificacion=verificacione(*xd);
while (verificacion==0){
  verificacion=verificacione(*xd);
  cout << "Codigo no valido. Ingrese nuevamente: ";
  cin>>xd->codigo;
  cout << endl;

}
PlaySound(TEXT("Base de datos"), NULL, SND_SYNC);
system("pause");
}

void NuevoProyecto(int a){
FILE *p;
struct proyectos reg;
    p=fopen("proyectos.dat","rb");
    while (fread(&reg,sizeof(proyectos),1,p)==1){
    a=reg.numero;
    }
    fclose(p);
    p=fopen("proyectos.dat","ab");
    cargarproyecto(&reg,a);
    fwrite(&reg,sizeof reg,1,p);
    fclose(p);

}

void listarproyectos()
{
FILE *part;
struct proyectos reg;
part=fopen("proyectos.dat","rb");
if(part==NULL)
{ cout<<"Error de archivo";
PlaySound(TEXT("Error de Archivo"), NULL, SND_SYNC);
exit(1);
}
while(fread(&reg, sizeof(struct proyectos),1,part)==1)
{
cout << "Proyecto N""\247"":"<< reg.numero<<endl;
cout << "Nombre del Proyecto :"<< reg.nombre<<endl;
cout << "Presentacion: " << reg.presentacion<<endl;
cout << "Codigo de Diputado :"<< reg.codigo<<endl;
}
fclose(part);
system("pause");
}
int switchproyecto (int c){
int valor;
while (true){
    system ("cls");
cout<<"MENÚ PROYECTOS"<<endl;
cout<<"--------------"<<endl;
cout<<"1 - NUEVO PROYECTO DE LEY"<<endl;
cout<<"2 - LISTAR TODOS LOS PROYECTOS DE LEY"<<endl;
cout<<"3 - LISTAR TODOS LOS PROYECTOS DE LEY POR CODIGO DE DIPUTADO"<<endl;
cout<<"-----------------"<<endl;
cout<<"0 - VOLVER AL MENU ANTERIOR"<<endl;
cin>> valor ;
switch (valor){
case 1 :
    NuevoProyecto(c);
    break ;
case 2 :
    listarproyectos();
    break;
case 3:
    ///Ordenar;
    ///mostrarproyecto;
    break ;
case 0:
    return 0;
    break ;
}}

}

#endif // PROYECTO_H_INCLUDED
