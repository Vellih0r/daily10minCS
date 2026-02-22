# include <stdio.h>

int main()
{
	double nc;
	// for with empty body 
	for(nc = 0; getchar() != EOF; ++nc)
		//null statement
		;
	printf("%.0f\n", nc);
}
