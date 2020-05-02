#include <fstream> 
#include <iostream> 
#include <string> 
#include <vector> 
 
using namespace std; 
 
//Declaración de estructura de tipo Jugad 
 
struct Jug{ 
string nom; 
string ape; 
int edad; 
string Guatemal; 
float suel; 
}; 
 
//Creación de vector de tipo estructura de Jug 
std::vector<Jug> jugad; 
 
//Función encargada de agregar jug a archivos 
void agregarJug(){ 
 
Jug jugadores; 
string guatemalteco; 
 
 
 

 
cout << "----------------------------Registro de jugador----------------------------" << endl; 
cout << "Ingrese nom del jugad: " << "\n"; 
cin >> jugadores.nom; 
cout << "Ingrese ape del jugad: " << "\n"; 
cin >> jugadores.ape; 
cout << "Ingrese edad del jugad: " << "\n"; 
cin >> jugadores.edad; 
cout << "¿El jugad es de nacionalidad guatemalteca? (Si/No)" << "\n"; 
cin >> jugadores.Guatemal; 
cout << "Ingrese el suel del jugad: " << "\n"; 
cin >> jugadores.suel; 
 
if (jugadores.Guatemal == "si" || jugadores.Guatemal == "si" || jugadores.Guatemal == "si" || jugadores.Guatemal == "si"){ 
jugadores.Guatemal = "Guatemalteco"; 
} 
else{ 
jugadores.Guatemal = "Extranjero"; 
jugadores.suel = jugadores.suel + 500.00; 
} 
 
 
 
 
 
 
 
 

 
/* 
Verificación a las edades de los jugadores para el aumento del salario. 
*/ 
if (jugadores.edad >= 15 and jugadores.edad <= 20){ 
jugadores.suel = jugadores.suel + 1400.00; 
} 
else if(jugadores.edad >= 21 and jugadores.edad <= 25){ 
jugadores.suel = jugadores.suel + 1500.00; 
} 
else if(jugadores.edad >= 26 and jugadores.edad <= 30){ 
jugadores.suel = jugadores.suel + 1200.00; 
} 
else if(jugadores.edad >30){ 
jugadores.suel = jugadores.suel + 800.00; 
} 
 
//Grabar Jugadores en el archivo 
ofstream archivoJugad("Archivojugadores.txt", std::ios_base::app); 
archivoJugad <<jugadores.nom << "\t"<< jugadores.ape << "\t" << jugadores.edad << "\t" << 
jugadores.Guatemal << "\t" << jugadores.suel<< endl; 
archivoJugad.close(); 
} 
 
 
 
 
 
 

 
void totalP(){ 
float total = 0.00; 
for (int i = 0; i <= jugad.size(); i++){ 
total = total + jugad[i].suel; 
} 
 
 
cout << "-------------------------------------------------------" << "\n"; 
cout << "EL TOTAL A PAGAR DEL JUGADOR ES DE: $." << total << endl; 
cout << "-------------------------------------------------------" << "\n"; 
 
return; 
} 
 
 
void edadMR(){ 
 
 
string RangoE;  
float sum15_20 = 0.00; 
float sum21_25 = 0.00;  
float sum26_30 = 0.00;  
float sum30 = 0.00;  
int total15_20 = 0;  
int total21_25 = 0; 
int total26_29 = 0; 
int totalM30 = 0;  
float remune = 0.00;  

 
for (int i = 0; i <= jugad.size(); i ++){ 
if(jugad[i].edad >= 15 and jugad[i].edad <= 20){ 
sum15_20 = sum15_20 + jugad[i].suel; 
total15_20 = total15_20 +1; 
} 
else if(jugad[i].edad >= 21 and jugad[i].edad <= 25){ 
sum21_25 = sum21_25 + jugad[i].suel; 
total21_25 = total21_25 + 1; 
} 
else if(jugad[i].edad >= 26 and jugad[i].edad <= 30){ 
sum26_30 = sum26_30 + jugad[i].suel; 
total26_30 = total26_30 + 1; 
} 
else if(jugad[i].edad > 30){ 
sumM30 = sumM30 + jugad[i].suel; 
totalM30 = totalM30 +1; 
} 
} 
float ArregTotal[4] = { sum15_20, sum21_25, sum26_30, sumM30 }; 
 
/* 
Iteración del arreglo para determinar cuál es la mayor 
remuneración de salario y determinar en qué rango de edades. 
*/ 
for (int i = 0; i <= 3; i++){ 
if (ArregTotal[i] > remun){ 
remun = ArregTotal[i]; 
if (i = 0){ 
RangoE = "15 - 20 AÑOS"; 
} 
else if (i = 1){ 
RangoE = "21 - 25 AÑOS"; 
} 
else if (i = 2){ 
RangoE = "26 - 30 AÑOS"; 
} 
else if (i = 3){ 
RangoE = "MAYOR A30 AÑOS"; 
} 
} 
} 
 
//Salida en consola de la función 
cout << "EL TOTAL ENTRE 15 A 20 AÑOS" << total15_20 << endl; 
cout << "EL TOTAL ENTRE 21 A 25 AÑOS " << total21_25 << endl; 
cout << "EL TOTAL ENTRE 26 A 30 AÑOS" << total26_30 << endl; 
cout << "EL TOTAL MAYORES A 30 AÑOS ES " << totalM30 << endl; 
cout << "RANGO DE EDAD MÁS REMUNERADO ES: " << RangoE << " CON UN TOTAL $" << remun <<  endl; 
return; 
} 
 
void leerArchivo(){ 
ifstream archivoJug; 
Jug stJug; 
 
 
archivoJug.open("ArchivoJug.txt", ios::in); 
 
while(archivoJug >> stJug.nom >> stJug.ape >> stJug.edad >> stJug.Guatemal >> stJug.suel){ 
jugad.push_back(stJug); 
} 
 
archivoJug.close(); 
 
return; 
} 
 
//Función principal 
int main(){ 
 string opcion; 
string vacio;  
bool terminar = false;  
do { 
cin.clear(); 
 
cout << "---------------------“JUGADORES”---------------------" << endl; 
cout << "1. Agregar jug" << "\n" 
<< "2. El total a pagar en planilla" << "\n" 
<< "3. Rango de edad más remunerado y total de los  jugadores por edad" << "\n" 
<< "4. Salir" << endl; 
cout << "Elija una opción (1 a la 4)" << endl; 
cin >> opcion; 
 
switch(opcion){ 
case '1': 
agregarJug(); 
break; 
case '2': 
leerArchivo(); 
totalPlanilla(); 
break; 
case '3': 
leerArchivo(); 
edadMasRemunerada(); 
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
 
 
