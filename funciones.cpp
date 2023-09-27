#include "funciones.h"


int random(int max,int min){
    int numero;
    numero= rand() % (max-min) + min;
    return numero;
};

void imprime_arreglo(char a[],int num){

    cout<<"arreglo: ";
    for(int i=0;i<num;i++){
        a[i]=char(random(91,65));
        cout<<a[i];
    }
    cout<<endl;
}

void imprime_letrascantidad(char b[]){

    int contador=0;
    for(char i=65;i<91;i++){
        for(int j=0;j<200;j++){
            if(b[j]==i){
                contador++;
            }
        }
        if (contador!=0){
            cout<<i<<": "<<contador<<endl;
        }
        contador=0;
    }

}

bool comparacionCadena(char a[],char b[])
{
    int log=0;
    while ((a[log]!='\0')||(b[log]!='\0')) {//operador 'or' para llegar hasta cadena más larga y obtener longitud
        log++;//obtenemos longitud
    }
    for(int i=0;i<log;i++){
        if(a[i]!=b[i]){//comparamos caracter a caracter
            return 0;
        }
    }

    return 1;//todos son iguales y retorna 1
}

long long convertirChar_int(char *p, int tam)
{
    int valor=1;
    int min=0;
    int suma=0;
    int multiplicador=1;

    if(p[0]==45){
        valor=-1;
        min=1;
    }

    for(int i=tam;i>0+min;i--){
        suma+=int(p[i-1]-48)*multiplicador;
        multiplicador*=10;
    }
    if(valor==-1){
        return suma*valor;
    }

    return suma;
}

void convertirInt_Char(char *p, unsigned long int numero, int &i)
{
    while (numero>0) {//sale del ciclo cuando sea 0
        p[i]=(numero%10)+48;//número modulo 10 + 48 en ascii representa mismo número
        numero/=10;//reducimos numero de su ultima cifra
        i++;//contamos para el tamaño del arreglo
    }
    invertirArray(p,i);//como se obtiene arreglo al contrario, este se invierte
}

void invertirArray(char a[],int tam){
    int f, l;
    for (f = 0, l = tam -1; f < l; f++, l--) {
        char tmp = a[f];//tmp copia primer caracter
        a[f] = a[l];//primer caracter copia ultimo caracter
        a[l] = tmp;//ultimo caracter copia a tmp
    }
};

void imprimirArray(char a[],int tam){
    for(int i=0;i<tam;i++){
        cout<<a[i];
    }
    cout<<endl;
}

void cambiarMinuscula_Mayuscula(char *p, int &i)
{
    for (int itr=0;itr<i ;itr++) {
        if((p[itr]>96)&&(p[itr]<123)){
            p[itr]-=32;
        }
    }
}
void imprime_arreglo_original(char a[],int num){
    cout<<"arreglo: ";
    for(int i=0;i<num;i++){
        cout<<a[i];
    }
    cout<<endl;
}
void imprime_arreglo_original_sin_repetir(char c[],int num){
    int cont=0;
    cout<<"sin repetir: ";
    //este for sirve para ver si un caracter se repite más de una vez.
    //desde la posicion del array comparandose con los anteriores.

    for(int j=0;j<num;j++){
        cont=0;
        for(int k=0;k<=j;k++){
            if(c[k]==c[j]){//se compara, ambas posiciones son iguales y cont=1.
                cont++;
            }
        }
        if(cont==1){
            cout<<c[j];//si aparece que tiene caracteres repetidos más de una vez no imprime.
        }

    }

    cout<<endl;
}

void imprime_arreglo_original_entero(int a[],int num){
    cout<<"arreglo: ";
    for(int i=0;i<num;i++){
        cout<<a[i];
    }
    cout<<endl;
}

void convertirRomano(char RA[])
{
    char romanos[7]={'M','D','C','L','X','V','I'};
    int opcion=0;
    bool correcto=true;

    while (opcion!=1) {

        cout<<"1.salir\n2.convertir\n";
        cout<<"opcion: ";cin>>opcion;

        if(opcion!=1){
            cout<<"ingrese numero romano en Mayuscula: ";
            cin>>RA;
        }

        int cont=0;
        int len=0;
        int sumatoria=0;


        if(correcto==false)
            cin>>RA;

        while (RA[len]!='\0') {
            len++;
        }


        if(opcion==2){


            for(int i=0;i<len;i++){

                for(int j=0;j<7;j++){
                    if(RA[i]==romanos[j])
                        cont++;
                }
                if(cont==0){
                    cout<<"ingrese un numero romano valido"<<endl;
                    correcto=false;
                    break;
                }
                cont=0;

            }
            if(correcto==true){

                sumatoria=calcularConversion(RA,len);
                imprimirArray(RA,len);
                cout<<"= "<<sumatoria<<endl;

            }


        }


    }
}

int calcularConversion(char RA[],int len){
    int sum=0;
    int A[len];
    for(int indx=0;indx<len;indx++){
        switch (RA[indx]) {
        case 'M': A[indx]=1000;
            break;
        case 'D': A[indx]=500;
            break;
        case 'C': A[indx]=100;
            break;
        case 'L': A[indx]=50;
            break;
        case 'X': A[indx]=10;
            break;
        case 'V': A[indx]=5;
            break;
        default: A[indx]=1;

        }
    }



    for(int i=(len-1);i>=0;i--){
        if(i==(len-1)){
            sum=A[i];
        }
        else if (A[i]<A[i+1]) {
            sum-=A[i];
        }
        else {
            sum+=A[i];
        }
    }


    return sum;

};

void cancelar_asiento(char a[][20]){
    cout<<"****CANCELAR ASIENTO**** "<<endl;
    char f;
    int c=0;
    cout<<"ingrese fila desde A-O: ";cin>>f;
    cout<<"ingrese el numeral del asiento: ";cin>>c;
    *(*(a+int(f-65))+(c-1))='o';


}
void reservar_cine(char a[][20]){
    cout<<"****RESERVAR ASIENTO**** "<<endl;
    char f;
    int c=0;
    cout<<"ingrese fila desde A-O: ";cin>>f;
    cout<<"ingrese el numeral del asiento: ";cin>>c;
    *(*(a+int(f-65))+(c-1))='*';

}
void cine_desocupar(char a[][20]){
    for(int j=0;j<15;j++){
        for(int i=0;i<20;i++){
            *(*(a+j)+i)='o';
        }

    }
}
void mostrar_cine(char a[][20]){

    cout<<endl;
    for(int j=0;j<15;j++){
        cout<<char(j+65)<<"-> ";
        for(int i=0;i<20;i++){
            cout<<*(*(a+j)+i)<<"  ";
        }
        cout<<endl;
    }
}
void cuadradoMagico(int tam)
{
    int **a=NULL;
    a=new int*[tam]{NULL};
    for(int i=0;i<tam;i++){
        a[i]=new int [tam];
    }

    cout<<endl;

    for(int i=0;i<tam;i++){
        cout<<"ingrese numeros de fila "<<i+1<<" : "<<endl;//enter en cada numero ingresado
        for(int j=0;j<tam;j++){
            cin>>a[i][j];
        }
    }

    cout<<"impresion de matiz de datos"<<endl;
    for(int i=0;i<tam;i++){
        for(int j=0;j<tam;j++){
            cout<<"["<<a[i][j]<<"]";
            cout.flush();
        }
        cout<<endl;
    }

    //determinar si es cuadrado magico

    int sumatoria=0;
    int aux=0;
    bool correcto=true;

    for(int i=0;i<((tam+tam)+2);i++){

        if(i<tam){
            for(int j=0;j<tam;j++){//sumatoria por filas
                sumatoria+=(a[i][j]);
                if(i==0 && j==(tam-1)){
                    aux=sumatoria;
                }
            }
            if(sumatoria != aux){
                correcto=false;
            }
            sumatoria=0;
        }

        else if (i>=tam && i<(tam+tam)) {//sumatoria por columnas

            for(int j=0;j<tam;j++){
                sumatoria+=(a[j][i-tam]);
            }
            if(sumatoria != aux){
                correcto=false;
            }
            sumatoria=0;

        }

        else if(i==(tam*2)){//sumatoria por diagonal negativa
            for(int j=0;j<tam;j++){
                sumatoria+=(a[j][j]);
            }
            if(sumatoria != aux){
                correcto=false;
            }
            sumatoria=0;

        }

        else {//sumatoria diagonal positiva

            for(int j=0;j<tam;j++){
                sumatoria+=(a[j][tam-(j+1)]);
            }
            if(sumatoria != aux){
                correcto=false;
            }
            sumatoria=0;
        }


        if(correcto==false){
            cout<<"no es cuadro magico"<<endl;
            break;
        }

    }

    if(correcto==true){
        cout<<"****es cuadro magrico ****"<<endl;
    }

    delete []a;
}
int BuscarEstrellas(int **a,int h,int anc)
{
    //ingreso de datos a la matriz
    cout<<"ingrese los datos de la matriz:"<<endl<<endl;
    int cont=0;
    for(int i=0;i<h;i++){
        cout<<"ingrese numeros de fila "<<i+1<<" : "<<endl;//enter en cada numero ingresado
        for(int j=0;j<anc;j++){
            cin>>a[i][j];
        }
    }

    cout<<"impresion de matiz de datos"<<endl;
    for(int i=0;i<h;i++){
        for(int j=0;j<anc;j++){
            cout<<"["<<a[i][j]<<"]\t";
            if( (i!=0) && (i!=(h-1)) && (j!=0) && (j!=(anc-1) )){//omite calculo de bordes
                float estrella=(a[i][j]+a[i][j-1]+a[i][j+1]+a[i-1][j]+a[i+1][j]);//float para guargar sumatoria de valores adyacentes
                if((estrella/5)>6){// si resultado en estrella es mayor que 6, es una estrella
                    cont++;
                }
            }

            cout.flush();
        }
        cout<<endl;
    }
    cout<<endl;

    return cont;
}

void matrix_random(int m[][5]){
    for(int j=0;j<5;j++){
        for(int i=0;i<5;i++){
            *(*(m+j)+i)=random(26,1);
        }
    }
}
void mostrar_matrix_random(int c[5][5]){
    cout<<endl;
    for(int j=0;j<5;j++){
        for(int i=0;i<5;i++){
            cout<<*(*(c+j)+i)<<"\t";
        }
        cout<<endl<<endl;
    }
}
void girar_matrix(int c[5][5]){
    int mTem[5][5];
    int t;
    //este for usa la matriz temporal para copiar de la original y a su vez girar a la derecha.
    for(int i = 0; i < 5; i++){//fila
        t = 0;
        for(int j = 5-1; j >= 0;j--){//fila nueva
            mTem[i][t] = c[j][i];//inferior izquierda sera superior izquierda en la primera iteración
            t++;
        }
    }
    //la matriz original copia los elementos de la temporal.
    for(int i = 0; i < 5; i++){//fila
        for(int j = 0; j < 5; j++){//columna
            c[i][j] = mTem[i][j];
        }
    }

}
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void permute(char *a, int l, int r,int *p)
{
    int i;
    if (l == r){
        (*p)--;
        if(*p==0){
            cout<< a<<endl;
        }


    }

    else
    {
        for (i = l; i <= r; i++)
        {
            swap((a+l), (a+i));
            permute(a, l+1, r,p);
            swap((a+l), (a+i)); //backtrack
        }
    }
}

int tamaArreglo(char *a)
{
    int tam=0;
    while (a[tam]!='\0') {
        tam++;
    }
    return tam;
}

void interseccion(int a[], int b[], int n[])
{
    if((b[0]<=a[2])&&(b[1]<=a[3])){
        n[0]=b[0];
        n[1]=b[1];
        n[2]=a[2]-b[0];
        n[3]=a[3]-b[1];
        cout<<"interseccion: {"<<n[0]<<","<<n[1]<<","<<n[2]<<","<<n[3]<<"}"<<endl;
    }
    else {
        n[0]=0;
        n[1]=0;
        n[2]=0;
        n[3]=0;
        cout<<"no existe interseccion."<<endl;
    }
}
int potencia(int x, int y){
    int s=1;
    for(int i=0;i<y;i++){
        s*=x;
    }
    return s;
};
