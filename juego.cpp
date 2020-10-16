#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>  // Crear numeros aleatorios, para el modo 1 jugador
#include <fstream> // Crear el archivo para guardar las letras erroneas
#include <locale.h>

using namespace std;

//Listado de palabras para un jugador
string listado[]={"Energia","Logica","Zapato", "Java", "Computador", "Impresion", "Biblioteca", "Programacion", "Ahorcado", "Internet", "Colombia", "Casa",
 "Tiburon", "Montura", "Mascota", "Dinosaurio"};

//Variables globales
string palabra, palabra1, espacio[20], ganar[20], espacio1[20], ganar1[20];
int longitud, longitud1, dato, fallos=0, fallos1=0;

//Funciones a usar

void menu();
void unJugador();
void fastJugadores();
void dosJugadores();
int adivinar(int);
void dibujo(int);
void perdio(string);
void gano(string, int);
void ganoFast(string, int, string, int, int, int);

void crearHistorial();
void historial(char);			void verHistorial();
void crearHistorial1();
void historial1(char);			void verHistorial1();


int main(){
	setlocale(LC_ALL,"spanish");
	crearHistorial();
	menu();
	
	cout<<endl<<endl;
	system("pause");
	return 0;
}

void menu(){
	fallos=0;
	fallos1=0;
	
	int Elegir=0;
	cout<<"============================"<<endl;
	cout<<" E L   A H O R C A D O  2.0"<<endl<<endl;
	cout<<" 1: Un jugador"<<endl;
	cout<<" 2: Dos jugadores"<<endl<<endl;
	cout<<" 3: Salir"<<endl<<endl;
	cout<<"============================"<<endl;
	cout<<" -> ";
	fflush(stdin);
	cin>>Elegir;
	switch(Elegir){
		case 1:
			system("cls");
			crearHistorial();
			unJugador();
			break;
		case 2:
			Elegir=0;
			system("cls");
			crearHistorial();
			crearHistorial1();
			cout<<"============================"<<endl;
			cout<<"Opciones de 2 jugadores:"<<endl<<endl;
			cout<<" 1: Player vs Player Word"<<endl;
			cout<<" 2: Player vs Player"<<endl<<endl;
			cout<<" 3: Volver"<<endl<<endl;
			cout<<"============================"<<endl;
			cout<<" -> ";
			fflush(stdin);
			cin>>Elegir;
			switch(Elegir){
				case 1:
					system("cls");
					dosJugadores();
					break;
				case 2:
					system("cls");
					fastJugadores();
					break;
				case 3:
					system("cls");
					menu();
				default:
					system("cls");
					cout<<"**ERROR**"<<endl;
					getch();
					menu();
					break;
			}
			break;
		case 3:
			cout<<endl<<"Cerrando....";
			break;
		default:
			system("cls");
			cout<<"**ERROR**"<<endl;
			getch();
			menu();
			break;
	}
}

void unJugador(){
	bool win=false, gameover=false;
	char auxpalabra[20];
	
	int cantidad = sizeof(listado)/sizeof(string);
	
	srand(time(NULL));
	dato = 0+rand()%(cantidad);
	
	strcpy(auxpalabra,listado[dato].c_str());
	
	longitud = strlen(auxpalabra);
	strupr(auxpalabra);
	palabra=auxpalabra;
	
	for(int i=0;i<longitud;i++){
		espacio[i]=" _ ";
	}
	
	for(int i=0;i<longitud;i++){
		ganar[i]="X";
	}
	
	while(win==false && gameover==false){
		int resultado;
		system("cls");
		resultado=adivinar(1);
		if(resultado==1){
			win=true;
		}
		if(resultado==2){
			gameover=true;
		}
	}
	
	if(gameover==true){
		perdio(palabra);
	}
	if(win==true){
		gano(palabra, fallos);
	}
}

void dosJugadores(){
	bool win=false, gameover=false;
	char auxpalabra[20];
	cout<<"======================================================================"<<endl;
	cout<<" Ingrese la palabra a adivinar: (20 letras Maximo, Sin espacios)"<<endl;
	cout<<"======================================================================"<<endl;
	fflush(stdin);
	cout<<" -> ";
	cin>>palabra;
	
	strcpy(auxpalabra,palabra.c_str());
	strupr(auxpalabra);
	
	system("cls");
	longitud = strlen(auxpalabra);
	palabra=auxpalabra;
	
	for(int i=0;i<longitud;i++){
		espacio[i]=" _ ";
	}
	
	for(int i=0;i<longitud;i++){
		ganar[i]="X";
	}
	
	while(win==false && gameover==false){
		int resultado;
		system("cls");
		resultado=adivinar(1);
		if(resultado==1){
			win=true;
		}
		if(resultado==2){
			gameover=true;
		}
	}
	if(gameover==true){
		perdio(palabra);
	}
	if(win==true){
		gano(palabra, fallos);
	}
}

void fastJugadores(){
	bool win=false, gameover=false, win1=false, gameover1=false;
	char auxpalabra[20], auxpalabra1[20];
	
	cout<<"==================================================================================="<<endl;
	cout<<" Ingrese la palabra a adivinar del jugador 1: (20 letras Maximo, Sin espacios)"<<endl;
	cout<<"==================================================================================="<<endl;
	fflush(stdin);
	cout<<" -> ";
	cin>>palabra;
	system("cls");
	cout<<"==================================================================================="<<endl;
	cout<<" Ingrese la palabra a adivinar del jugador 2: (20 letras Maximo, Sin espacios)"<<endl;
	cout<<"==================================================================================="<<endl;
	fflush(stdin);
	cout<<" -> ";
	cin>>palabra1;
	
	// preparando el primer jugador=====================================
	strcpy(auxpalabra,palabra.c_str());
	strupr(auxpalabra);
	
	longitud = strlen(auxpalabra);
	palabra=auxpalabra;
	
	for(int i=0;i<longitud;i++){
		espacio[i]=" _ ";
	}
	
	for(int i=0;i<longitud;i++){
		ganar[i]="X";
	}
	
	// preparando el segundo jugador=====================================
	strcpy(auxpalabra1, palabra1.c_str());
	strupr(auxpalabra1);
	
	longitud1 = strlen(auxpalabra1);
	palabra1=auxpalabra1;
	
	for(int i=0;i<longitud1;i++){
		espacio1[i]=" _ ";
	}
	
	for(int i=0;i<longitud1;i++){
		ganar1[i]="X";
	}
	
	while(win==false && gameover==false && win1==false && gameover1==false){
		int resultado;
		system("cls");
		cout<<"	Turno del jugador 1:"<<endl<<endl;
		resultado=adivinar(1);
		if(resultado==1){
			win=true;
		}
		if(resultado==2){
			gameover=true;
		}
		if(gameover==true){
			ganoFast(palabra1,fallos1,palabra,fallos,2,1);
		}
		if(win==true){
			ganoFast(palabra,fallos,palabra1,fallos1,1,2);
		}
		system("cls");
		cout<<"	Turno del jugador 2:"<<endl<<endl;
		resultado=adivinar(2);
		if(resultado==1){
			win1=true;
		}
		if(resultado==2){
			gameover1=true;
		}
		if(gameover1==true){
			ganoFast(palabra,fallos,palabra1,fallos1,1,2);
		}
		if(win1==true){
			ganoFast(palabra1,fallos1,palabra,fallos,2,1);
		}
	}
}

int adivinar(int num){
	char letra[1], auxpalabra[20];
	int error=0, resultado=0, bien=0;
	if(num==1){
		strcpy(auxpalabra,palabra.c_str());
		
		cout<<"==========================================================================================================="<<endl;
		cout<<" E L   A H O R C A D O "<<endl<<endl;
		dibujo(fallos);
		cout<<"     Su palabra de "<<longitud<<" letras es:  ";
		for(int i=0;i<longitud;i++){
			cout<<espacio[i];
		}
		cout<<endl<<endl<<"    Fallos:"<<endl<<fallos<<"/10"<<"        ";
		for(int i=0;i<fallos;i++){
			cout<<" X ";
		}
		cout<<endl<<"    Letras: ";
		verHistorial();
		cout<<"==========================================================================================================="<<endl;
		cout<<endl<<endl<<"Ingrese una letra: "<<endl;
		fflush(stdin);
		cout<<" -> ";
		cin>>letra[0];
		strupr(letra);
		for(int i=0;i<longitud;i++){
			if(letra[0]==auxpalabra[i]){
				espacio[i]=letra[0];
				ganar[i]="V";
			}
			else{
				error++;
			}
		}
		for(int i=0;i<longitud;i++){
			if(ganar[i]=="V"){
				bien++;
			}
		}
		
		if(error==longitud){
			fallos++;
			historial(letra[0]);
		}
		if(fallos==10){
			resultado=2;
		}
		if(bien==longitud){
			resultado=1;
		}
	}
	else{
		strcpy(auxpalabra,palabra1.c_str());
		
		cout<<"==========================================================================================================="<<endl;
		cout<<" E L   A H O R C A D O "<<endl<<endl;
		dibujo(fallos1);
		cout<<"     Su palabra de "<<longitud1<<" letras es:  ";
		for(int i=0;i<longitud1;i++){
			cout<<espacio1[i];
		}
		cout<<endl<<endl<<"    Fallos:"<<endl<<fallos1<<"/10"<<"        ";
		for(int i=0;i<fallos1;i++){
			cout<<" X ";
		}
		cout<<endl<<"    Letras: ";
		verHistorial1();
		cout<<"==========================================================================================================="<<endl;
		cout<<endl<<endl<<"Ingrese una letra: "<<endl;
		fflush(stdin);
		cout<<" -> ";
		cin>>letra[0];
		strupr(letra);
		for(int i=0;i<longitud1;i++){
			if(letra[0]==auxpalabra[i]){
				espacio1[i]=letra[0];
				ganar1[i]="V";
			}
			else{
				error++;
			}
		}
		for(int i=0;i<longitud1;i++){
			if(ganar1[i]=="V"){
				bien++;
			}
		}
		
		if(error==longitud1){
			fallos1++;
			historial1(letra[0]);
		}
		if(fallos1==10){
			resultado=2;
		}
		if(bien==longitud1){
			resultado=1;
		}
	}
	
	return resultado;
}

void ganoFast(string palabras, int fallas, string palabras1, int fallas1, int ganador, int perdedor){
	system("cls");
	cout<<"========================================="<<endl;
	cout<<"    F I N  D E L  J U E G O"<<endl<<endl;
	cout<<"  GANO El jugador "<<ganador<<",    con "<<fallas<<" fallos."<<endl;
	cout<<"  La palabra era: "<<palabras<<endl<<endl<<endl;
	
	cout<<"  PERDIO El jugador "<<perdedor<<",    con "<<fallas1<<" fallos."<<endl;
	cout<<"  La palabra era: "<<palabras1<<endl;
	cout<<"========================================="<<endl;
	getch();
	system("cls");
	remove("Historial1.txt");
	menu();
}

void gano(string palabra, int fallas){
	system("cls");
	cout<<"========================================="<<endl;
	cout<<"    F I N  D E L  J U E G O"<<endl<<endl;
	cout<<"  GANO,"<<"    con "<<fallas<<" fallos."<<endl<<endl;
	cout<<"  la palabra era: "<<palabra<<endl;
	cout<<"========================================="<<endl;
	getch();
	system("cls");
	remove("Historial1.txt");
	menu();
}


void perdio(string palabra){
	system("cls");
	cout<<"========================================="<<endl;
	cout<<"    F I N  D E L  J U E G O"<<endl<<endl;
	cout<<"  PERDIO"<<endl<<endl;
	cout<<"  la palabra era: "<<palabra<<endl;
	cout<<"========================================="<<endl;
	getch();
	system("cls");
	remove("Historial1.txt");
	menu();
}

void crearHistorial(){
	ofstream crear;
	
	crear.open("Historial.txt",ios::out);
	
	if(crear.fail()){
		cout<<endl<<"**No se pudo crear el archivo**"<<endl;
	}
	crear.close();
}

void historial(char letra){
	ofstream Historial;
	
	Historial.open("Historial.txt",ios::app);
	
	if (Historial.fail()){
		cout<<endl<<"**No se pudo abrir el archivo**"<<endl;
		getch();
		system("cls");
		menu();
	}
	Historial<<" "<<letra<<" ";
	
	Historial.close();
}

void verHistorial(){
	ifstream Historial;
	string Texto;
	
	Historial.open("Historial.txt",ios::in);
	
	if (Historial.fail()){
		cout<<endl<<"**El archivo no existe**"<<endl;
		getch();
		system("cls");
		menu();
	}
	
	while(!Historial.eof()){
		getline(Historial,Texto);
		cout<<Texto<<endl;
	}
	
	Historial.close();
}

void crearHistorial1(){
	ofstream crear;
	
	crear.open("Historial1.txt",ios::out);
	
	if(crear.fail()){
		cout<<endl<<"**No se pudo crear el archivo**"<<endl;
	}
	crear.close();
}

void historial1(char letra){
	ofstream Historial;
	
	Historial.open("Historial1.txt",ios::app);
	
	if (Historial.fail()){
		cout<<endl<<"**No se pudo abrir el archivo**"<<endl;
		getch();
		system("cls");
		menu();
	}
	Historial<<" "<<letra<<" ";
	
	Historial.close();
}

void verHistorial1(){
	ifstream Historial;
	string Texto;
	
	Historial.open("Historial1.txt",ios::in);
	
	if (Historial.fail()){
		cout<<endl<<"**El archivo no existe**"<<endl;
		getch();
		system("cls");
		menu();
	}
	
	while(!Historial.eof()){
		getline(Historial,Texto);
		cout<<Texto<<endl;
	}
	
	Historial.close();
}

void dibujo(int error){
	if(error==0){
		cout<<"                 +======+"<<endl;
		cout<<"                        ¦"<<endl;
		cout<<"                        ¦"<<endl;
		cout<<"                        ¦"<<endl;
		cout<<"                        ¦"<<endl;
		cout<<"                        ¦"<<endl;
		cout<<"                        ¦"<<endl;
		cout<<"                        ¦"<<endl;
		cout<<"                      ¦¯¯¯¦"<<endl;
		cout<<"                      ¦___¦"<<endl<<endl;
	}
	if(error==1){
		cout<<"                 +======+"<<endl;
		cout<<"                 ¦      ¦"<<endl;
		cout<<"                        ¦"<<endl;
		cout<<"                        ¦"<<endl;
		cout<<"                        ¦"<<endl;
		cout<<"                        ¦"<<endl;
		cout<<"                        ¦"<<endl;
		cout<<"                        ¦"<<endl;
		cout<<"                      ¦¯¯¯¦"<<endl;
		cout<<"                      ¦___¦"<<endl<<endl;
	}
	if(error==2){
		cout<<"                 +======+"<<endl;
		cout<<"                 ¦      ¦"<<endl;
		cout<<"               ¦¯¯¯¦    ¦"<<endl;
		cout<<"                        ¦"<<endl;
		cout<<"                        ¦"<<endl;
		cout<<"                        ¦"<<endl;
		cout<<"                        ¦"<<endl;
		cout<<"                        ¦"<<endl;
		cout<<"                      ¦¯¯¯¦"<<endl;
		cout<<"                      ¦___¦"<<endl<<endl;
	}
	if(error==3){
		cout<<"                 +======+"<<endl;
		cout<<"                 ¦      ¦"<<endl;
		cout<<"               ¦¯¯¯¦    ¦"<<endl;
		cout<<"               ¦* *¦    ¦"<<endl;
		cout<<"                        ¦"<<endl;
		cout<<"                        ¦"<<endl;
		cout<<"                        ¦"<<endl;
		cout<<"                        ¦"<<endl;
		cout<<"                      ¦¯¯¯¦"<<endl;
		cout<<"                      ¦___¦"<<endl<<endl;
	}
	if(error==4){
		cout<<"                 +======+"<<endl;
		cout<<"                 ¦      ¦"<<endl;
		cout<<"               ¦¯¯¯¦    ¦"<<endl;
		cout<<"               ¦* *¦    ¦"<<endl;
		cout<<"               ¦_¯_¦    ¦"<<endl;
		cout<<"                        ¦"<<endl;
		cout<<"                        ¦"<<endl;
		cout<<"                        ¦"<<endl;
		cout<<"                      ¦¯¯¯¦"<<endl;
		cout<<"                      ¦___¦"<<endl<<endl;
	}
	if(error==5){
		cout<<"                 +======+"<<endl;
		cout<<"                 ¦      ¦"<<endl;
		cout<<"               ¦¯¯¯¦    ¦"<<endl;
		cout<<"               ¦* *¦    ¦"<<endl;
		cout<<"               ¦_¯_¦    ¦"<<endl;
		cout<<"             ____¦____  ¦"<<endl;
		cout<<"                        ¦"<<endl;
		cout<<"                        ¦"<<endl;
		cout<<"                      ¦¯¯¯¦"<<endl;
		cout<<"                      ¦___¦"<<endl<<endl;
	}
	if(error==6){
		cout<<"                 +======+"<<endl;
		cout<<"                 ¦      ¦"<<endl;
		cout<<"               ¦¯¯¯¦    ¦"<<endl;
		cout<<"               ¦* *¦    ¦"<<endl;
		cout<<"               ¦_¯_¦    ¦"<<endl;
		cout<<"             ____¦____  ¦"<<endl;
		cout<<"                 ¦      ¦"<<endl;
		cout<<"                        ¦"<<endl;
		cout<<"                      ¦¯¯¯¦"<<endl;
		cout<<"                      ¦___¦"<<endl<<endl;
	}
	if(error==7){
		cout<<"                 +======+"<<endl;
		cout<<"                 ¦      ¦"<<endl;
		cout<<"               ¦¯¯¯¦    ¦"<<endl;
		cout<<"               ¦* *¦    ¦"<<endl;
		cout<<"               ¦_¯_¦    ¦"<<endl;
		cout<<"             ____¦____  ¦"<<endl;
		cout<<"                 ¦      ¦"<<endl;
		cout<<"                 ¦      ¦"<<endl;
		cout<<"                      ¦¯¯¯¦"<<endl;
		cout<<"                      ¦___¦"<<endl<<endl;
	}
	if(error==8){
		cout<<"                 +======+"<<endl;
		cout<<"                 ¦      ¦"<<endl;
		cout<<"               ¦¯¯¯¦    ¦"<<endl;
		cout<<"               ¦* *¦    ¦"<<endl;
		cout<<"               ¦_¯_¦    ¦"<<endl;
		cout<<"             ____¦____  ¦"<<endl;
		cout<<"                 ¦      ¦"<<endl;
		cout<<"                 ¦      ¦"<<endl;
		cout<<"                / \\   ¦¯¯¯¦"<<endl;
		cout<<"                      ¦___¦"<<endl<<endl;
	}
	if(error==9){
		cout<<"                 +======+"<<endl;
		cout<<"                 ¦      ¦"<<endl;
		cout<<"               ¦¯¯¯¦    ¦"<<endl;
		cout<<"               ¦* *¦    ¦"<<endl;
		cout<<"               ¦_¯_¦    ¦"<<endl;
		cout<<"             ____¦____  ¦"<<endl;
		cout<<"                 ¦      ¦"<<endl;
		cout<<"                 ¦      ¦"<<endl;
		cout<<"                / \\   ¦¯¯¯¦"<<endl;
		cout<<"               /   \\  ¦___¦"<<endl<<endl;
	}
}
