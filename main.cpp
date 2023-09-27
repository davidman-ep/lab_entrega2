#include <iostream>
#include "funciones.h"
#include <ctime>

using namespace std;
#define CASE 17


int main()
{
#if CASE==1
    //enlace del problema 1, https://www.tinkercad.com/things/hBERpL5YC14-problema1lab2
    //enlace del problema 6,https://www.tinkercad.com/things/jBqWs9RL3rK-problema6lab2
    //enlace del problema 10, https://www.tinkercad.com/things/fv2aQcrMwvo-problema10lab2
    //enlace del problema 17,https://www.tinkercad.com/things/kSUsyDeWTda-problema17lab2

#endif
#if CASE==2
    //Elabore un programa que genere un arreglo de 200 letras mayúsculas aleatorias,
    //imprima este arreglo y luego imprima cuantas veces se repite cada letra en el arreglo.
    //Ej: supóngase que se genera el arreglo de 10 elementos: ABARSECAAB. El programa debe imprimir:
    //ABARSECAAB
    srand(time(NULL));
    char array[200];
    imprime_arreglo(array,200);
    imprime_letrascantidad(array);

#endif
#if CASE==3
    //    Haga una función que compare 2 cadenas de caracteres y
    //    retorno un valor lógico verdadero si son
    //    iguales y falso en caso contrario,
    //    tener en cuenta la longitud de las cadenas.
    cout<<"comparar dos cadenas de caracteres maximo 100 caracteres"<<endl<<endl;
    bool comparacion=true;
    char a[100]={0};
    char b[100]={0};//considerar cadena maximo 100 caracteres

    cout<<"ingrese 1th cadena de caracteres: ";cin>>a;
    cout<<"ingrese 2th cadena de caracteres: ";cin>>b;//ingreso de ambas cadenas a comparar
    comparacion=comparacionCadena(a,b);//función de comparación

    if(comparacion==1)//si retorna 1, es verdadero
        cout<<"las cadenas de caracteres son iguales"<<endl;
    else //si retorna 0, es falso
        cout<<"las cadenas de caracteres no son iguales"<<endl;

#endif
#if CASE==4
    //Haz una función que reciba una cadena de caracteres numéricos,
    //la convierta a un número entero y retorne dicho número. Escribe un programa de prueba.
    char *cad=nullptr;
    cad=new char;
    int tam=0;
    long long int num;
    cout<<"digite cadena de caracteres: ";cin>>cad;
    while (cad[tam]!='\0') {
        tam++;
    }
    num=convertirChar_int(cad,tam);
    cout<<"entero: "<<num<<endl;

    delete cad;

#endif

#if CASE==5
    //    Haga una función que reciba un numero entero (int) y lo convierta a cadena de caracteres.
    //    Use parámetros por referencia para retornar la cadena. Escriba un programa de prueba.

    unsigned long int num;
    int i=0;
    char *array=nullptr;
    array=new char;

    cout<<"ingrese un numero entero para convertir a cadena de caracteres: ";cin>>num;
    convertirInt_Char(array,num,i);
    imprimirArray(array,i);

#endif
#if CASE==6
    //    Escribe un programa que reciba una cadena de caracteres y cambie las letras minúsculas
    //    por mayúsculas, los demás caracteres no deben ser alterados.
    char *array=nullptr;
    array=new char;
    int i=0;

    cout<<"ingrese cadena de caracteres: ";cin>>array;
    while (array[i]!='\0') {
        i++;
    }
    cambiarMinuscula_Mayuscula(array,i);
    imprimirArray(array,i);
    delete array;

// https://www.tinkercad.com/things/0O3WK9FFJ54-grand-jarv/editel?tenant=circuits

#endif
#if CASE==7

    //    Escriba un programa que reciba una cadena de caracteres y elimine los caracteres repetidos.
    //    Ej: se recibe bananas debe mostrar bans.

    char original[100];
    int i=0;
    cout<<"ingrese su cadena maximo 100 caracteres y sin espacios."<<endl;
    cin>>original;
    while (original[i]!='\0') {
        i++;
    }//este bucle cuenta cuantos caracteres fueron asignados.
    imprime_arreglo_original(original,i);
    imprime_arreglo_original_sin_repetir(original,i);


#endif

#if CASE==8
    //    Escriba un programa que reciba una cadena de caracteres y
    //    separe los números del resto de caracteres, generando una
    //    cadena que no tiene números y otra con los números que había en la cadena original.

    cout<<"ingrese una cadena alfanumerica que no supere los 100 caracteres y sin espacios."<<endl;
    char alfanum[100];
    int i=0,j=0,k=0,l=0,p=0;
    cin>>alfanum;
    while (alfanum[i]!='\0') {
        if((alfanum[i]>='A'&& alfanum[i]<='Z')||(alfanum[i]>='a'&& alfanum[i]<='z')){
            j++;
        }
        else{
            k++;
        }
        i++;
    }//este bucle cuenta cuantos caracteres fueron asignados
    int num[k];
    char alfa[j];

    for(int f=0;f<i;f++){

        if((alfanum[f]>='A'&& alfanum[f]<='Z')||(alfanum[f]>='a'&& alfanum[f]<='z')){
            alfa[p]=alfanum[f];
            p++;
        }
        else{
            num[l]=int(alfanum[f]-48);
            l++;
        }
    }

    cout<<"original ";
    imprime_arreglo_original(alfanum,i);
    cout<<endl;
    cout<<"texto ";
    imprime_arreglo_original(alfa,j);
    cout<<endl;
    cout<<"numero ";
    imprime_arreglo_original_entero(num,k);
    cout<<endl;

#endif
#if CASE==9

    //ingresar un numero n, un arreglo de caracteres numericos
    int num,tam=0;
    int multiplicador=1;
    int suma=0,sumaboque=0;
    char *array=nullptr;
    array=new char;
    cout<<"ingrese numero: ";cin>>num;
    cout<<"ingrese cadena de caracteres: ";cin>>array;
    tam=tamaArreglo(array);
    cout<<"original: ";imprimirArray(array,tam);

    if(tam%num!=0){
        invertirArray(array,tam);
        for (int j=0;j<(num-(tam%num));j++) {
            array[tam+j]='0';
        }
        tam+=((num-(tam%num)));
        invertirArray(array,tam);
        array[tam]='\0';
    }
    for (int i=tam-1;i>=0;i-=num) {
        for (int k=0;k<num ;k++ ) {
            sumaboque+=(int(array[i-k])-48)*multiplicador;
            multiplicador*=10;
        }
        multiplicador=1;
        suma+=sumaboque;
        sumaboque=0;
    }
    cout<<"suma: "<<suma<<endl;


#endif
#if CASE==10
    //    programa que permita convertir un número en el sistema romano al sistema arábigo
    //    usado actualmente. A continuación se encuentran los caracteres usados en el sistema
    //    romano y su equivalente arábigo:
    //   M: 1000
    //   D: 500
    //   C: 100
    //   L: 50
    //   X: 10
    //   V: 5
    //   I: 1

    char rom[14];
    convertirRomano(rom);

//https://www.tinkercad.com/things/bBoWTSZWxY8-funky-densor-albar/editel?tenant=circuits


#endif
#if CASE==11

    //    Escriba un programa que permita manejar las reservas de asientos en una sala de cine,
    //    los asientos de la sala de cine están organizados en 15 filas con 20 asientos cada una.
    //    El programa debe mostrar una representación de la sala que indique que asientos están
    //    disponibles y cuales se encuentran reservados. Además debe permitir realizar reservas o
    //    cancelaciones al ingresar la fila (letras A-O) y el número del asiento (números 1-20).


    char silla_cine[15][20];
    int menu=0;
    cine_desocupar(silla_cine);

    do {

        cout<<"************+CINE*****************++"<<endl;
        cout<<"menu:\n1-desocupar cine.\n2-reservar asiento.\n3-cancelar asiento.\n4-mostrar sala\n0-salir";
        cout<<"\ningrese opcion: ";cin>>menu;
        switch (menu) {
        case 1:
            cine_desocupar(silla_cine);
            break;
        case 2:
            reservar_cine(silla_cine);
            break;
        case 3:
            cancelar_asiento(silla_cine);
            break;
        case 4:
            mostrar_cine(silla_cine);
            break;
        default:
            break;
        }




    } while (menu!=0);



#endif
#if CASE==12
    //    Un cuadrado mágico es una matriz de números enteros sin repetir,
    //    en la que la suma de los números
    //    en cada columna, cada fila y cada diagonal principal tienen
    //    como resultado la misma constante

    cout<<"programa para determinar si es un cuadrado magico."<<endl;
    int dimension=3;
    cout<<"\ningrese la dimension del cuadrado: ";cin>>dimension;

    cuadradoMagico(dimension);

#endif
#if CASE==13
    //buscar número de estrellas en una matriz
    int alto=0,ancho=0,numeroEstrellas=0;

    cout<<"Se obtendra numero de estrellas en la matriz ingresada"<<endl<<endl;
    cout<<"ingrese el alto de matriz: ";cin>>alto;
    cout<<"ingrese el ancho de la matriz: ";cin>>ancho;
    cout<<endl;
    int **foto=new int *[alto];
    for(int i=0;i<ancho;i++){
        foto[i]=new int[ancho];
    }
    numeroEstrellas=BuscarEstrellas(foto,alto,ancho);

    cout<<"\nEl numero de estrellas en la foto son: "<<numeroEstrellas<<endl;
    delete []foto;
#endif
#if CASE==14

    srand(time(NULL));
    int matrix[5][5];
    matrix_random(matrix);

    int menu;

    do {

        cout<<"menu:\n1-mostrar matriz.\n2-girar 90 grados.\n3-girar 180 grados.\n4-girar 270 grados.\n-5nueva matriz random.\n0-salir.\n";
        cin>>menu;
        switch (menu) {
        case 0:
            break;
        case 1:
            mostrar_matrix_random(matrix);//imprime matriz
            break;
        case 2:
            girar_matrix(matrix);//gira 90ª negativos
            break;
        case 3:
            girar_matrix(matrix);//llama función 2 veces para giro de 180ª
            girar_matrix(matrix);
            break;
        case 4:
            girar_matrix(matrix);//llama función 3 veces para giro de 270ª
            girar_matrix(matrix);
            girar_matrix(matrix);
            break;
        case 5:
            matrix_random(matrix);//generar nueva matriz aleatoria
        default:
            cout<<"error******"<<endl;
        }

    } while (menu!=0);

#endif
#if CASE==15

    //Representa los rectángulos como arreglos de 4 datos de la siguiente manera:
    //● Los primeros 2 datos corresponden a las coordenadas de
    //la esquina superior izquierda del rectángulo (x,y) como se observa en la figura
    //● Los siguientes 2 datos representan el ancho y la altura del rectángulo
    int rec1[4];
    int rec2[4];
    int recn[4];
    cout<<"Datos de rectangulo 1: ";
    cout<<"x1_pos: ";cin>>rec1[0];
    cout<<"y1_pos: ";cin>>rec1[1];
    cout<<"ancho: ";cin>>rec1[2];
    cout<<"altura: ";cin>>rec1[3];

    cout<<"\nDatos de rectangulo 1: ";
    cout<<"x2_pos: ";cin>>rec2[0];
    cout<<"y2_pos: ";cin>>rec2[1];
    cout<<"ancho: ";cin>>rec2[2];
    cout<<"altura: ";cin>>rec2[3];
    interseccion(rec1,rec2,recn);

#endif
#if CASE==16

    //    En una malla de 2x2, realizando únicamente movimientos hacia la derecha y
    //    hacia abajo hay 6 posibles caminos para llegar de la esquina superior izquierda
    //    a la inferior derecha:
    //    Escriba un programa que reciba un numero n y calcule el número de caminos
    //    posibles en una cuadricula de nxn.


    long long int n,numerador=1,divisor=1;
    cout<<"ingrese un numero para su maya de orden nxn: ";cin>>n;
    //el factorial de la suma de dos de sus lados (l+l)!
    //dividido con la multiplicacion de sus lados factoriales l! x l!
    //no superar un n>10

    for(int i=1;i<=(n*2);i++){
        numerador*=i;
        if(i<=n){
            divisor*=i;
        }
    }
    cout<<"una maya de "<<n<<"x"<<n<<" puntos hay "<<numerador/(divisor*divisor)<<" caminos"<<endl;


#endif
#if CASE==17

    //  programa que reciba un número y halla la suma
    // de todos los números amigables menores al número ingresado.
    unsigned int num;
    unsigned int amigo1=0,amigo2=0;
    unsigned int sum1=0,sum2=0;
    unsigned int suma=0;

    cout<<"ingrese numero: "<<endl;
    cin>>num;

    for (unsigned int i=1;i<num ;i++) {

        amigo1=i;
        for (unsigned int j=1;j<amigo1;j++) {
            if(amigo1%j==0)
                sum1+=j;
        }
        amigo2=sum1;
        for (unsigned int j=1;j<amigo2;j++) {
            if(amigo2%j==0)
                sum2+=j;
        }

        if((amigo1!=amigo2)&&(sum2==amigo1)){
            i=amigo2;
            suma+=(sum1+sum2);
            cout<<"pareja"<<endl;
        }
        sum1=0;sum2=0;

    }

    cout<<"\nel resultado de la suma es: "<<suma<<endl;


#endif
#if CASE==18
    //    Las permutaciones lexicográficas son permutaciones ordenadas numérica o
    //    alfabéticamente, por ejemplo las permutaciones lexicográficas de 0,1 y 2 son:
    //    012, 021, 102, 120, 201, 210. Escribir un programa que reciba un número n y halle
    //    la enésima permutación lexicográfica de los números entre 0 y 9.



    char str[] = "0123456789";
    int n =0;
    while (str[n]!='\0') {
        n++;
    }
    int niter;
    int *ptr=&niter;
    cin>>niter;

    permute(str, 0, n-1,ptr);

#endif

    return 0;
}
