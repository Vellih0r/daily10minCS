#include <stdio.h>

#define	LOWER 0 	// lower livit of table
#define	UPPER 300	// upper limit
#define STEP  20	// step size

/*print Fahrenheit - Celsius table*/
int main()
{
	int fahr;
	printf("Fahrenheit | Celcius\n");
	for (fahr=UPPER; fahr >= LOWER; fahr -= STEP)
		printf("%10d |%7.1f\n", fahr, (5.0/9.0)*(fahr-32));
	return 0;
}
