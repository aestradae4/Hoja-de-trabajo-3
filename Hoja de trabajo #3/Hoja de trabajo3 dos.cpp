#include <fstream> 
#include <iostream> 
#include <string> 
#include <vector> 
 
using namespace std; 
 
struct Pizzas{ 
 string TP; 
 float PU; 
 float des; 
 float precioP; 
}; 
 
 
std::vector<Pizzas> vecPizza; 
 
void agregarPizza(){ 
 
Pizzas stPiz; 
int tipo; 
cout << "--------------------------------------COMPRAR PIZZA--------------------------------------" << endl; 
  
cout << "Por favor seleccione el tipo Pizza " << "\n"  
<< "1. Pizza Grande ----------- Q80.00" << "\n" 
<< "2. Pizza Familiar ---------- Q115.00" << "\n" 
<< "3. Pizza Fiesta -------------Q100.00" << endl; 
cout << "Seleccione la opción (1 a la 3)" << endl; 
cin >> tipo; 
 
 
if (tipo == 1){ 
stPiz.TP = "Grande"; 
stPiz.PU = 80.00; 
stPiz.des = stPiz.PU * 0.1; 
stPiz.precioP = stPiz.PU - stPiz.des; 
} 
else if (tipo == 2){ 
stPiz.TP = "Familiar"; 
stPiz.PU = 115.00; 
stPiz.des = stPiz.PU * 0.15; 
stPiz.precioP = stPiz.PU - stPiz.des; 
} 
else if (tipo == 3){ 
stPiz.TP = "Fiesta"; 
stPiz.PU = 80.00; 
stPiz.des = stPiz.PU * 0.2; 
stPiz.precioP = stPiz.PU - stPiz.des; 
} 
 
cout << "------------------------------------------------------------------" << endl; 
cout << "Compra realizada por una piza " << stPiz.TP << " con un total a pagar de Q" << stPiz.precioP << endl; 
cout << "------------------------------------------------------------------" << endl; 
 
ofstream archivoPizzas("PIZZAS.txt", std::ios_base::app); 
 
//Ingresar datos de pizza a archivo 
archivoPizzas << stPiz.TP << "\t" << stPiz.PU << "\t" << stPiz.precioP << "\t" << stPiz.des << endl; 
 
archivoPizzas.close(); 
 
return; 
 
} 
 
void leerArchivo(){ 
ifstream archivoPizzas; 
 
Pizzas stPiz; 
 
archivoPizzas.open("PIZZAS.txt", ios::in); 
 
while (archivoPizzas >> stPiz.TP >> stPiz.PU >>  stPiz.precioP >> stPiz.des){ 
vecPizza.push_back(stPiz); 
} 
 
archivoPizzas.close(); 
 
return; 
 
} 
 
void ventaTotalDia(){ 
float total = 0.00; 
 
leerArchivo(); 
 
 
for (int i = 0; i <= vecPizza.size(); i ++){ 
total = total + vecPizza[i].precioP; 
} 
 
cout <<"El total de la venta del dia es: Q" << total << endl; 
 
} 
 
void totalPorProducto(){float totalG = 0.00; 
float desGrande = 0.00; 
 
float desF = 0.00; 
float desF = 0.00; 
 
float desFiesta = 0.00; 
float desFiesta = 0.00; 
 
leerArchivo(); 
 
for (int i = 0; i < vecPizza.size(); i ++){ 
 
if(vecPizza[i].TP == "Grande"){ 
totalG = totalG + vecPizza[i].precioP; 
desGrande = desGrande + vecPizza[i].des; 
} 
else if(vecPizza[i].TP == "Familiar"){ 
desF = desF + vecPizza[i].precioP; 
desF = desF + vecPizza[i].des; 
} 
else if(vecPizza[i].TP == "Fiesta"){ 
desFiesta = desFiesta + vecPizza[i].precioP; 
desFiesta = desFiesta + vecPizza[i].des; 
} 
} 
 
cout << "-------------------------------------------------" << endl; 
cout << "PIZZA" << "\t" << "PAGADO" << "\t" << "DES" << endl; 
cout << "GRANDE" << "\t" << totalG << "\t" << desGrande << endl; 
cout << "FAM." << "\t" << desF << "\t" << desF << endl; 
cout << "FIESTA" << "\t" << desFiesta << "\t" << desFiesta << endl; 
cout << "-------------------------------------------------" << endl; 
 
} 
 
int main(){ 
 
char opcion; //Guarda la opción ingresada por el usuario 
string vacio; //Variable encargada de obtener un valor vacío para selección de opción en menú 
bool terminar = false; //Variable bandera para terminar ejecución de programa 
 
do { 
cin.clear(); 
 
cout << "---------------------PIZZERÍA EL GRAN SABOR---------------------" << endl; 
cout << "1. Comprar" << "\n" 
<< "2. Mostrar total de venta del día" << "\n" 
<< "3. Total vendido por producto" << "\n" 
<< "4. Salir" << endl; 
cout << "Elija una opción (1-4)" << endl; 
cin >> opcion; 
 
switch(opcion){ 
case '1': 
agregarPizza(); 
break; 
case '2': 
ventaTotalDia(); 
break; 
case '3': 
totalPorProducto(); 
break; 
case '4': 
terminar = true; 
break; 
default: 
cout << "Opción inválida"; 
getchar(); 
getline(cin, vacio); 
break; 
} 
 
}while(terminar != true); 
return 0; 
} 
