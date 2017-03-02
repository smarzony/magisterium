#include <iostream>
#include <wiringPi.h> 
#include <wiringPiSPI.h> 

using namespace std;
 
int main(int argc, char **argv) 
{ 
    //Zmienne pomocnicza 
    unsigned char a, msg=129; 
 
    //Zmienna deskryptora SPI 
    int descriptor, device; 
 
    //Komunikat poczatkowy 
    cout<<"Program testowy SPI WiringPi!\n"; 
 
    if (wiringPiSetup() == -1) 
    { 
        cout<<"Nie mozna wystartowac wiringPi!"; 
        return 1; 
    } 
 
    //Inicjujemy SPI 
    descriptor=wiringPiSPISetup(0,500000); 
 
    //Sprawdzenie, czy dziala 
    if (descriptor!=-1) cout<<"Udalo sie zainicjowac SPI!\n"; 
    else 
    { 
        cout<<"Nie udalo sie zainicjowac SPI!\n"; 
        return 1; 
    } 
 
    //Petla programu 
    while (a!='q') 
    { 
        //Wysylamy/odbieramy bajt danych przez SPI 
        device = wiringPiSPIDataRW(0,&msg,1); 
 
        //Wyswietlamy info 
        cout<<"Zwrocone przez urzadzenie: \n"<<msg; 
 
        //Pobieramy znak 
        //scanf("%c",&a); 
		cin>>a;
    } 
 
    //Koniec programu 
    return 0; 
}