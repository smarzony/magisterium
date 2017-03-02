#include <iostream>
#include <wiringPi.h> 
#include <softPwm.h>

using namespace std;
 
int main(int argc, char **argv) 
{ 
    cout<<"Program testowy WiringPi!\n";
 
    if (wiringPiSetup() == -1) 
    { 
        cout<<"Nie mozna wystartowac wiringPi!\n"; 
        return 1; 
    } 
	cout<<"Poprawnie wystartowano biblioteke wiringPi!\n"; 
	pinMode(0,OUTPUT);
	pinMode(2,OUTPUT);
	softPwmCreate(0,0,256); 
	softPwmCreate(2,0,256); 
	cout<<"Zadeklarowano piny jako wyjscia\n";
	
	for(int i=1;i<=4;i++)
	{
		softPwmWrite(2,50);
		softPwmWrite(0,0);
		delay(500);
		softPwmWrite(0,50);
		softPwmWrite(2,0);
		delay(500);		 
	}
	softPwmWrite(0,0);
	softPwmWrite(2,0);
 
    cout<<"Koniec programu\n";
    return 0; 
}