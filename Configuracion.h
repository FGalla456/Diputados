#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED

int switchconfiguracion(){
int valor;
FILE *p,*t,*s,*bd,*bp,*bs;
struct diputados BD;
struct proyectos BP;
struct sesiones BS;
    while (true){
        system ("cls");
        system("color 43");
    recuadro(37, 10, 44, 19, cNEGRO, cAMARILLO);
textcolor(cNEGRO, cAMARILLO);

gotoxy(38,11);
cout<<"              MENU CONFIGURACION"<<endl;
gotoxy(38,12);
cout<<"-------------------------------------------"<<endl;
gotoxy(38,14);
cout<<"1 -         REINICIO DE DIPUTADOS"<<endl;
gotoxy(38,16);
cout<<"2 -         REINICIO DE PROYECTOS"<<endl;
gotoxy(38,18);
cout<<"3 -         REINICIO DE SESIONES" << endl;
gotoxy(38,20);
cout<<"4 -          RESTAURAR DIPUTADOS "<<endl;
gotoxy(38,22);
cout<<"5 -          RESTAURAR PROYECTOS " << endl;
gotoxy(38,24);
cout<<"6 -          RESTAURAR SESIONES"<< endl;
gotoxy(38,26);
cout<<"-------------------------------------------"<<endl;
gotoxy(38,28);
cout<<"0 -         VOLVER AL MENU ANTERIOR"<<endl;


recuadro(45,31, 25, 2, cNEGRO, cAMARILLO);
textcolor(cNEGRO, cAMARILLO);
gotoxy(47,32);
cout << "Ingrese la opcion: ";
gotoxy(67,32);
cin>>valor;

switch(valor){

case 1:
    bd=fopen("BackupDiputados.dat","wb");
    p=fopen("diputados.dat","rb");
    while(fread(&BD,sizeof(diputados),1,p)==1){
    fwrite(&BD,sizeof(diputados),1,bd);
    }
    fclose(bd);
    fclose(p);
    p=fopen("diputados.dat","wb");
    fclose(p);
    PlaySound(TEXT("Reiniciado Correctamente 1"), NULL, SND_SYNC);

    break;

case 2:
    bp=fopen("BackupProyectos.dat","wb");
    t=fopen("proyectos.dat","rb");
    while(fread(&BP,sizeof(proyectos),1,t)==1){
    fwrite(&BP,sizeof(proyectos),1,bp);
    }
    fclose(bp);
    fclose(t);
    t=fopen("proyectos.dat","wb");
    fclose(t);
   PlaySound(TEXT("Reiniciado Correctamente 2"), NULL, SND_SYNC);
    break;
case 3:
    bs=fopen("BackupSesiones.dat","wb");
    s=fopen("sesiones.dat","rb");
    while(fread(&BS,sizeof(sesiones),1,s)==1){
    fwrite(&BS,sizeof(sesiones),1,bs);
    }
    fclose(bs);
    fclose(s);
    s=fopen("sesiones.dat","wb");
    fclose(s);
   /// PlaySound(TEXT("Reiniciado Correctamente 2"), NULL, SND_SYNC);
    break;

case 4:
    bd=fopen("BackupDiputados.dat","rb");
    p=fopen("diputados.dat","ab");
    while(fread(&BD,sizeof(diputados),1,bd)==1){
    fwrite(&BD,sizeof(diputados),1,p);
    }
    fclose(bd);
    fclose(p);
    break;

case 5:
    bp=fopen("BackupProyectos.dat","rb");
    t=fopen("proyectos.dat","ab");
    while(fread(&BP,sizeof(proyectos),1,bp)==1){
    fwrite(&BP,sizeof(proyectos),1,t);
    }
    fclose(bp);
    fclose(t);
    break;

case 6:
    bs=fopen("BackupSesiones.dat","rb");
    s=fopen("sesiones.dat","ab");
    while(fread(&BS,sizeof(sesiones),1,bs)==1){
    fwrite(&BS,sizeof(sesiones),1,s);
    }
    fclose(bs);
    fclose(s);
    break;

case 0:
    return 0;
    break;

default:
    cout << "Opcion Invalida. Por Favor Ingrese Nuevamente." << endl << endl;
    break;

}
}
}

#endif // CONFIGURACION_H_INCLUDED
