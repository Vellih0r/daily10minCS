#include <stdio.h>

// copy input to output; v2
int main()
{
	int c;

	/* the () are necessary because precedence of != is higher than =
	without () - it will become c = (getchar() != EOF)*/
	while ((c = getchar()) != EOF)
		putchar(c);
	return 0;
	
	
	/* v1
	c = getchar();
	while (c != EOF)
	{	
		putchar(c);
		c = getchar();
	}
	*/
}
