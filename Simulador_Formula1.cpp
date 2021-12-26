#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;
/*
A continuación se declaran las funciones globales, 4 variables de estado que ayudan al codigo a funcionar globalmente y son manipuladas por funciones locales. 
Y tambien declaramos aqui la matriz puesto que no la podemos modificar desde una función al no saber punteros.
*/
bool flag_campeon = false;
int carreras_globales = 0;
int usuarios_globales = 12;
string campeon_global;
string nombres_globales[14] = {"Marcos", "Juan", "Felipe", "Esteban",
                               "Lucas", "Pablo", "Pedro", "Eduardo",
                               "Ulises", "Omar", "Abdul", "Miguel"};
int edad_global[14] = {18, 24, 23, 42,
                       21, 36, 23, 27,
                       20, 34, 25, 54};
string nacionalidad_global[14] = {"Italiano", "Holandes", "Mexicano", "Español",
                                  "Peruano", "Americano", "Canadiense", "Aleman",
                                  "Panameño", "Libanes", "Arabe", "Portugues"};
string equipos_globales[14] = {"mercedes", "alpine", "red_bull", "mclaren",
                               "aston_martin", "ferrari", "alfa_romeo", "alphatauri",
                               "williams", "haas", "ferrari", "mclaren"};
string equipos_unicos[14] = {};
int numeros_globales[14] = {15, 2, 3, 7,
                            32, 5, 6, 8,
                            46, 21, 9, 4};
int puntos_globales[14] = {};
int dinero_equipos[14] = {};
int victorias_globales[14] = {};
int carreras_individuales[14] = {};

//Esta función imprime una linea para separar texto 

void formato()
{
    for(int i = 0; i < 60; i++)
    {
        cout << "-";
    }
    cout << "\n";
    cout << endl;
}

//Esta función cuenta las ocurrencias unicas de una lista, y regresa su conteo, comparando los equipos contra su arreglo global.
int lenUnico()
{
    int count; int matches = 0; int doubles = 0;
    for(int i = 0; i < usuarios_globales; i++)
    {
        count = 0;
        for (int j = 0; j < usuarios_globales; ++j)
        {
            if (equipos_globales[i] == equipos_globales[j])
            {
                count +=1;
            }
        }
        if(count == 2)
        {
            doubles += 1;
        }
        else
        {
            matches += 1;
        }
    }
    return matches + (doubles/2);
}

//Esta funcion regresa si un string existe ya en una lista, y regresa un booleano.

bool coincidencia(string buscar, string lista[])
{
    for (int i = 0; i < usuarios_globales; i++)
    {
        if (buscar == lista[i])
        {
            return true;
        }
    }
    return false;
}

//Esta funcion actualiza la lista de los equipos sin duplicados.

void actualizarEquipos()
{
    int indice = 0;
    for (int i = 0; i < 14; ++i)
    {
        equipos_unicos[i] = "0";
    }
    for(int i = 0; i < 14; i++)
    {
        if(coincidencia(equipos_globales[i], equipos_unicos) == 0)
        {
            equipos_unicos[indice] = equipos_globales[i];
            indice+=1;
        }
    }
}

//Esta funcion busca si ya existe un entero en una lista y regresa un booleano

bool coincidencia(int buscar, int lista[])
{
    for (int i = 0; i < usuarios_globales; i++)
    {
        if (buscar == lista[i])
        {
            return true;
        }
    }
    return false;
}

//Esta funcion regresa el indice de un string que coincida en una lista y regresa un booleano

int index(string lista[], string nombre)
{
    for(int i = 0; i < usuarios_globales; i++)
    {
        if(nombre == lista[i])
        {
            return i;
        }
    }
    return -1;
}

//Esta funcion regresa el indice de un entero que coincida en una lista y regresa un entero

int index(int lista[], int nombre)
{
    for(int i = 0; i < usuarios_globales; i++)
    {
        if(nombre == lista[i])
        {
            return i;
        }
    }
    return -1;
}

//Esta funcion regresa si un elemento tiene dos coincidencias y regresa un booleano

bool ocurrencias(string nombre, string lista[])
{
    int contador = 0;
    for(int i = 0; i < usuarios_globales; i++)
    {
        if(nombre == lista[i])
        {
            contador += 1;
        }
    }
    if (contador == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Esta funcion da de alta a los pilotos y actualiza la base de datos conectada con la matriz.

void altaPilotos()
{
    if(usuarios_globales < 14)
    {
        int edad_piloto, numero_piloto; string nacionalidad_piloto, equipo_piloto, nombre_piloto;
        cout << "Ingresa la edad del piloto: "; cin >> edad_piloto;
        cout << "Ingresa la nacionalidad del piloto: "; cin >> nacionalidad_piloto;
        cout << "Ingresa el nombre del piloto (Primera mayuscula): "; cin >> nombre_piloto;
        cout << "Ingresa el equipo del piloto: ";cin >> equipo_piloto;
        if(ocurrencias(equipo_piloto, equipos_globales) == 1)
        {
            while(true)
            {
                cout << "El equipo ya esta lleno, por favor ingresa otro: "; cin >> equipo_piloto;
                if(ocurrencias(equipo_piloto, equipos_globales) == 0)
                {
                    break;
                }
            }
        }

        cout << "Ingresa el numero del piloto: " ; cin >> numero_piloto; cout << endl;
        if(coincidencia(numero_piloto, numeros_globales) == 1)
        {
            while(true)
            {
                cout << "El número ya esta en uso, porfavor ingresa otro: "; cin >> numero_piloto;
                if(coincidencia(numero_piloto, numeros_globales) == 0)
                {
                    break;
                }
            }
        }

        edad_global[usuarios_globales] = edad_piloto;
        numeros_globales[usuarios_globales] = numero_piloto;
        nacionalidad_global[usuarios_globales] = nacionalidad_piloto;
        equipos_globales[usuarios_globales] = equipo_piloto;
        nombres_globales[usuarios_globales] = nombre_piloto;
        usuarios_globales += 1;
        actualizarEquipos();
    }

    else
    {
        cout << "La base de datos ya tiene 14 usuarios" << endl;
    }
}

//Esta funcion cambia dos enteros en una lista

void cambiar(int lista[], int indice1, int indice2)
{
    int temporal = lista[indice2];
    lista[indice2] = lista[indice1];
    lista[indice1] = temporal;
}

//Esta funcion cambia dos strings en una lista

void cambiar(string lista[], int indice1, int indice2)
{
    string temporal = lista[indice2];
    lista[indice2] = lista[indice1];
    lista[indice1] = temporal;
}

//Esta funcion asigna el dinero global de los equipos y lo imprime.

void dinero(string equipo, bool modo)
{
    int indice_local = index(equipos_unicos, equipo);
    if(modo == true)
    {
        dinero_equipos[indice_local] += 10000;
    }
    else
    {
        dinero_equipos[indice_local] += 6000;
    }
}

//Esta funcion genera las fallas aleatoriamente en las carreras y regresa un booleano, Los autos tendrán 3 posibles fallas, las llantas de 20%, el motor de 30% y el sistema electrónico de 40%.

bool fallas()
{
    bool flag = false;
    int contador = 0;
    int llantas = rand() % 10 + 1;
    int motor = rand() % 10 + 1;
    int sistema = rand() % 10 + 1;
    if(llantas > 8)
    {
        contador+=1;
    }
    if(motor > 7)
    {
        contador +=1;
    }
    if (sistema > 6)
    {
        contador +=1;
    }
    if(contador >= 2)
    {
        flag = true;
    }
    return flag;
}

//Esta funcion asigna los puntajes globales, utilizando el índice de la lista de corredores.

void puntaje(string nombres_local[], int puntajes[])
{
    int indice;
    for(int i = 0; i < usuarios_globales; i++){
        if(fallas() == 0){
            indice = index(nombres_globales, nombres_local[i]);
            puntos_globales[indice] += puntajes[i];
            dinero(equipos_globales[indice], true);
            carreras_individuales[indice] += 1;
            if(puntajes[i] != 0){
                victorias_globales[indice] += 1;
            }
        }
        else{
            cout << "El corredor " << nombres_local[i] << " fue penalizado por fallas \n";
            indice = index(nombres_globales, nombres_local[i]);
            puntos_globales[indice] += puntajes[i];
            dinero(equipos_globales[indice], false);
            carreras_individuales[indice] += 1;
            if(puntajes[i] != 0){
                victorias_globales[indice] += 1;
            }
        }
    }
    for(int i = 0; i < 5;i++){
        cout << i+1 << " " << nombres_local[i] << "  " << puntajes[i] << "\n";
    }
}

//Esta funcion asigna el orden de los pilotos en los que competiran y no repite posiciones.

void pilotosenOrden()
{
    int numero_local[14];
    for(int i = 0; i < usuarios_globales; i++)
    {
        numero_local[i] = numeros_globales[i];
    }
    int indice1; int indice2;
    for(int i = 0; i < usuarios_globales; i++)
    {
        indice1 = rand() % usuarios_globales;
        indice2 = rand() % usuarios_globales;
        cambiar(numero_local, indice1, indice2);
    }
    cout << "Las posiciones de pilotos son: \n";
    for(int i = 0; i < usuarios_globales; i++){
        cout << i+1 << " " << numero_local[i] << "\n";
    }
}

//Esta funcion asigna a los campeones basado en el rubro del primero de llegar a 50 puntos, en caso de que 2 o más lleguén, se toma el de puntaje total más alto.

void campeon()
{
    if(flag_campeon == false){
        for (int i = 0; i < usuarios_globales; ++i) {
            if(puntos_globales[i] >= 50){
                int maximo = 0;
                int indice;
                for (int j = 0; j < usuarios_globales; ++j) {
                    if(puntos_globales[i] > maximo){
                        maximo = puntos_globales[i];
                        indice = i;
                    }
                }
                cout << "El campeon es: " << nombres_globales[indice] << endl;
                flag_campeon = true;
                campeon_global = nombres_globales[i];
                break;
            }
            else{
                if(carreras_globales >= 5){
                    int max = 0;
                    int indice;
                    for (int j = 0; j < usuarios_globales; ++j) {
                        if(puntos_globales[i] > max){
                            max = puntos_globales[i];
                            indice = i;
                        }
                    }
                    cout << "El flag_campeon es: " << nombres_globales[indice] << "\n";
                    flag_campeon = true;
                }
            }
        }
    }
}

//Esta funcion simula la carrera, agarrando el indice de la lista de corredores y haciendo aleatorio el resultado.

void simularCarrera()
{
    string circuito;
    cout << "Ingresa el nombre del circuito \n";
    cin >> circuito;
    cout << "circuito " << circuito << "\n";
    formato();
    pilotosenOrden();
    formato();
    string nombres_local[14];
    for(int i = 0; i < usuarios_globales; i++){
        nombres_local[i] = nombres_globales[i];
    }
    int puntajes[14] = {25,18,15,12,10};
    int indice1; int indice2;
    for(int i = 0; i < usuarios_globales; i++){
        indice1 = rand() % usuarios_globales;
        indice2 = rand() % usuarios_globales;
        cambiar(nombres_local, indice1, indice2);
    }
    puntaje(nombres_local,puntajes);
    campeon();
}

//Esta funcion ordena la base de datos de manera ascendente y descendente, por nombre o por número.

void ordenar()
{
    cout << "Deseas ordenar los nombres (1) o numeros (0): ";
    int opcion;
    cin >> opcion;
    if(opcion == 1)
    {
        int orden;
        string lista_temp[usuarios_globales];
        string temp;
        cout << "Deseas orden ascendente (1) o descendente (0): ";
        cin >> orden;
        for(int i = 0; i < usuarios_globales; i++)
        {
            lista_temp[i] = nombres_globales[i];
        }
        for (int j = 0; j < usuarios_globales - 1; j++)
        {
            for(int i = 0; i < usuarios_globales - 1; i++)
            {
                if(int(lista_temp[i][0]) > int(lista_temp[i+1][0]))
                {
                    temp = lista_temp[i];
                    lista_temp[i] = lista_temp[i+1];
                    lista_temp[i+1] = temp;
                }
            }
        }
        if(orden == 1)
        {
            for(int x = 0; x < usuarios_globales; x++)
            {
                cout << lista_temp[x] << endl;
            }
        }
        else if(orden == 0)
        {
            for (int i = usuarios_globales - 1; i >= 0; --i)
            {
                cout << lista_temp[i] << endl;
            }
        }
        else
        {
            cout << "Ingresa una opción valida \n";
        }
    }

    else if (opcion == 0)
    {
        int orden;
        int lista_temporal[usuarios_globales];
        int temporal;
        cout << "Deseas orden ascendente (1) o descendente (0): ";
        cin >> orden;
        for(int i = 0; i < usuarios_globales; i++)
        {
            lista_temporal[i] = numeros_globales[i];
        }
        for (int j = 0; j < usuarios_globales - 1; j++)
        {
            for(int i = 0; i < usuarios_globales - 1; i++)
            {
                if(int(lista_temporal[i]) > int(lista_temporal[i + 1]))
                {
                    temporal = lista_temporal[i];
                    lista_temporal[i] = lista_temporal[i + 1];
                    lista_temporal[i + 1] = temporal;
                }
            }
        }

        if(orden == 1)
        {
            for(int x = 0; x < usuarios_globales; x++)
            {
                cout << lista_temporal[x] << " " << nombres_globales[index(numeros_globales, lista_temporal[x])] << endl;
            }
        }
        else if(orden == 0)
        {
            for (int i = usuarios_globales - 1; i >= 0; --i)
            {
                cout << lista_temporal[i] << " " << nombres_globales[index(numeros_globales, lista_temporal[i])] << endl;
            }
        }
    }
    else
    {
        cout << "Ingresa una opción valida \n";
    }
}

//Esta funcion filtra 

void filtro_equipo()
{
    string buscar;
    formato();
    cout << "Ingresa tu equipo a buscar: ";
    cin >> buscar;
    for (int i = 0; i < usuarios_globales; ++i)
    {
        if(buscar == equipos_globales[i])
        {
            cout << " " << nombres_globales[i] << " " << edad_global[i] << " " << nacionalidad_global[i] << " " << equipos_globales[i] << " " << puntos_globales[i] << " " << carreras_individuales[i] << "\n";
        }
    }
    formato();
}
//Esta funcion filtra por nombre

void filtro_nombre()
{
    string buscar;
    formato();
    cout << "Ingresa tu nombre a buscar: ";
    cin >> buscar;
    for (int i = 0; i < usuarios_globales; ++i)
    {
        if(buscar == nombres_globales[i])
        {
            cout << " " << nombres_globales[i] << " " << edad_global[i] << " " << nacionalidad_global[i] << " " << equipos_globales[i] << " " << puntos_globales[i] << " " << carreras_individuales[i] << "\n";
        }
    }
    formato();
}
//Esta funcion filtra por nacionalidad

void filtro_nacionalidad()
{
    string buscar;
    formato();
    cout << "Ingresa tu nacionalidad a buscar: ";
    cin >> buscar;
    for (int i = 0; i < usuarios_globales; ++i)
    {
        if(buscar == nacionalidad_global[i])
        {
            cout << " " << nombres_globales[i] << " " << edad_global[i] << " " << nacionalidad_global[i] << " " << equipos_globales[i] << " " << puntos_globales[i] << " " << carreras_individuales[i] << "\n";
        }
    }
    formato();
}
//Esta funcion filtra por edad

void filtro_edad()
{
    int buscar;
    formato();
    cout << "Ingresa tu edad a buscar: ";
    cin >> buscar;
    for (int i = 0; i < usuarios_globales; ++i)
    {
        if(buscar == edad_global[i])
        {
            cout << " " << nombres_globales[i] << " " << edad_global[i] << " " << nacionalidad_global[i] << " " << equipos_globales[i] << " " << puntos_globales[i] << " " << carreras_individuales[i] << "\n";
        }
    }
    formato();
}
//Esta funcion filtra por numero

void filtro_numero()
{
    int buscar;
    formato();
    cout << "Ingresa tu numeros a buscar: ";
    cin >> buscar;
    for (int i = 0; i < usuarios_globales; ++i)
    {
        if(buscar == numeros_globales[i])
        {
            cout << " " << nombres_globales[i] << " " << edad_global[i] << " " << nacionalidad_global[i] << " " << equipos_globales[i] << " " << puntos_globales[i] << " " << carreras_individuales[i] << "\n";
        }
    }
    formato();
}
//Esta funcion termina e imprime los resultados en orden de puntaje, no necesariamente el campeón es el más alto puesto que se puede correr el código 5 veces, pero el criterio para el campeon es quien llegue primero a los 50 puntos.
void terminar(){
    cout<<"Los resultados son: \n ";
    formato();
    cout << "El campeon es " << campeon_global << "\n";
    formato();
    cout << "Nombre, equipos, puntaje, victorias, carreras competidas \n";
    formato();
    int lista_temp[14] = {}; int temp2; string temp; int indice_local; string nombres_local[14] = {};
    for (int i = 0; i < usuarios_globales; ++i) {
        lista_temp[i] = puntos_globales[i];
    }
    for (int i = 0; i < usuarios_globales; ++i) {
        nombres_local[i] = nombres_globales[i];
    }

    for (int j = 0; j < usuarios_globales - 1; j++)
    {
        for(int i = 0; i < usuarios_globales - 1; i++)
        {
            if(int(lista_temp[i]) < int(lista_temp[i+1]))
            {
                temp2 = lista_temp[i];
                lista_temp[i] = lista_temp[i+1];
                lista_temp[i+1] = temp2;
                temp = nombres_local[i];
                nombres_local[i] = nombres_local[i+1];
                nombres_local[i+1] = temp;
            }
        }
    }
    for (int i = 0; i < usuarios_globales; ++i)
    {
        indice_local = index(nombres_globales, nombres_local[i]);
        cout << nombres_globales[indice_local] << " " << equipos_globales[indice_local] << " " << puntos_globales[indice_local] << "pts " << victorias_globales[indice_local] << "V " << carreras_individuales[indice_local] << "cc" << "\n";
    }
}

//Esta funcion filtra pilotos
void filtrarPilotos(){
    int opcion;
    cout << "Ingresa el filtro que deseas Nombre (1), Numero (2), Edad (3)," << endl << "Nacionalidad (4), Equipo (5): " << endl;
    cin >> opcion;
    cout << "Se desplegará: Nombre/Edad/Nacionalidad/Equipo/Puntos/Carreras" << endl;
    switch (opcion)
    {
        case 1:
            filtro_nombre();
            break;
        case 2:
            filtro_numero();
            break;
        case 3:
            filtro_edad();
            break;
        case 4:
            filtro_nacionalidad();
            break;
        case 5:
            filtro_equipo();
            break;
        default:
            cout << "Ingresa una opcion valida";
    }
}

//Codigo por Eduardo Ulises y Miguel Herrera

int main()
{
    srand(time(NULL));
    actualizarEquipos();
    int opcion; bool run = true;
    while(run)
    {
        formato();
        cout << "Bienvenido al menu, selecciona la opcion deseada \n";
        formato();
        cout << "Alta de pilotos (1) \n";
        cout << "Simulacion de carrera (2) \n";
        cout << "Filtrar Pilotos (3) \n";
        cout << "Imprimir pilotos en orden(4) \n";
        cout << "Dinero generado (5) \n";
        cout << "Para salir del programa e imprimir la base de datos (0) \n";
        formato();
        cin >> opcion;
        switch (opcion)
        {
            case 1:
                altaPilotos();
                break;
            case 2:
                if(carreras_globales < 5){
                    simularCarrera();
                    carreras_globales += 1;
                }
                else{
                    cout << "El circuito ya llego a las 5 carreras, selecciona otra opcion \n";
                }
                break;
            case 3:
                filtrarPilotos();
                break;
            case 4:
                ordenar();
                break;
            case 5:
                for (int i = 0; i < lenUnico(); ++i)
                {
                    cout << equipos_unicos[i] << " " << dinero_equipos[i] << "\n";
                }
                break;
            case 0:
                run = false;
                break;
            default:
                cout << "porfavor ingresa una opcion correcta";
                break;
        }
    }
    terminar();
}