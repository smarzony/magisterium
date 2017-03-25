 
#include <wiringPi.h>
#include <wiringPiI2C.h>
 
 
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
 
 
int main (void)
{
	int fd, dane, idDev=0x48;
	//FILE *fp;
	 
	 
	if(wiringPiSetup() == -1)
		exit(1);
	 
	if((fd=wiringPiI2CSetup(idDev)) == -1)
	{
		printf("error initialize I2C");
		exit(1);
	}
	printf("Modu³ PCF8591 A/C i D/C");
	//empty run
	dane = wiringPiI2CRead(fd);
	wiringPiI2CWrite (fd, 0x00);
	 
	/////AIN0
	delay (400) ;
	wiringPiI2CWrite (fd, 0x00);
	delay (400) ;

	while(1)
	{
		dane = wiringPiI2CRead(fd);
		delay (10.5) ;
		printf("\nAIN0: %d",dane);		
	}
 
	//AIN1
	// delay (400) ;
	// wiringPiI2CWrite (fd, 0x02);
	// delay (400) ;
	// dane = wiringPiI2CRead(fd);
	// delay (400) ;
	// printf("\nTermistor: %d",dane);
	 
	// AIN2
	 
	// wiringPiI2CWrite (fd, 0x03);
	// delay (400) ;
	// dane = wiringPiI2CRead(fd);
	// delay (400) ;
	// printf("\nPotencjometr: %d ",dane);
	// delay (400) ;
	 
	 
	//  AIN3
	 
	// wiringPiI2CWrite (fd, 0x00);
	// delay (400) ;
	// dane = wiringPiI2CRead(fd);
	// delay (400) ;
	// printf("\nFotorezystor: %d\n",dane);
 
 
	return 0 ;
}