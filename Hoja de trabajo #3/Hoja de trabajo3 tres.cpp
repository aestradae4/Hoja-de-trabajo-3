#include <fstream> 
#include <iostream> 
#include <string> 
#include <vector> 
 
using namespace std; 
 
struct Vehiculos{ 
int edad; 
string modelo; 
string color; 
float precio; 
float importe; 
}; 
 
//Agregar vehiculo a Archivo 
void agregarVehiculo(){ 
 
Vehiculos stVehiculo; 
int tipo; 
int color; 
 
cout << "---------REGISTRAR VEHICULO-----------" << endl; 
 
 
cout << "Ingrese la edad del conductor: "<< endl; 
cin >> stVehiculo.edad; 
cout << "Por favor seleccione el modelo del vehiculo " << "\n" 
<< "1. A" << "\n" 
<< "2. B" << endl; 
cout << "Seleccione una opcion (1-2)" << endl; 
cin >> tipo; 
 
 
if (tipo == 1){ 
stVehiculo.modelo = "A"; 
cout << "Ingrese color:" << "\n" 
<< "1. Blanco-----------Q240.50" << "\n" 
<< "2. Metalizado-------Q330.00" << "\n" 
<< "3. Otros------------Q270.50" << endl; 
cin >> color; 
 
switch (color){ 
case 1: 
stVehiculo.color = "Blanco"; 
stVehiculo.precio = 240.50; 
break; 
case 2: 
stVehiculo.color = "Metalizado"; 
stVehiculo.precio = 330.00; 
break; 
case 3: 
stVehiculo.color = "Otros"; 
stVehiculo.precio = 270.50; 
break; 
} 
 
} 
else if (tipo == 2){ 
stVehiculo.modelo = "B"; 
cout << "Ingrese color:" << "\n" 
<< "1. Blanco-----------Q300.00" << "\n" 
<< "2. Metalizado-------Q360.00" << "\n" 
<< "3. Otros------------Q330.00" << endl; 
cin >> color; 
 
switch (color){ 
case 1: 
stVehiculo.color = "Blanco"; 
stVehiculo.precio = 300.00; 
break; 
case 2: 
stVehiculo.color = "Metal."; 
stVehiculo.precio = 360.00; 
break; 
case 3: 
stVehiculo.color = "Otros"; 
stVehiculo.precio = 330.50; 
break; 
} 
} 
 
if (stVehiculo.edad < 31){ 
stVehiculo.importe = stVehiculo.precio + (stVehiculo.precio * 0.25); 
} 
else if(stVehiculo.edad >= 31 and stVehiculo.edad <= 65){ 
stVehiculo.importe = stVehiculo.precio + (stVehiculo.precio * 0.00); 
} 
else if(stVehiculo.edad > 65){ 
stVehiculo.importe = stVehiculo.precio + (stVehiculo.precio * 0.30); 
} 
 
cout << "El importe a pagar del vehiculo es:  Q" << stVehiculo.importe << endl; 
 
//Abrir archivo 
ofstream archivoVehiculo("VEHICULOS.txt", std::ios_base::app); 
 
archivoVehiculo 
<< stVehiculo.edad << "\t" << stVehiculo.modelo << "\t" << stVehiculo.color 
<< "\t" << stVehiculo.precio << "\t" << stVehiculo.importe << endl; 
 
archivoVehiculo.close(); 
 
return; 
 
} 
 
int main(){ 
 
string opción 
string vacio;  
bool terminar = false;  
 
 
 
do { 
cin.clear(); 
 
cout << "---------------------SEGURO DEL VEHICULO---------------------" << endl; 
cout << "1. Importe a pagar" << "\n" 
<< "2. Salir" << endl; 
cout << "Elija una opción (1-2)" << endl; 
cin >> opcion; 
 
switch(opcion){ 
case '1': 
agregarVehiculo(); 
break; 
case '2': 
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
