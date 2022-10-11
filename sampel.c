#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int main()
{	
	double vcc;
	double spe;
	int i = INT_MIN;
	int bit;
	printf("skriv cvv:");
	scanf("%lf",&vcc);

	printf("skriv spening:");
	scanf("%lf",&spe);

	printf("bit len:");
	scanf("%d",&bit);

	int i_spen = (int)((spe/vcc)*bit);
	printf("speningen er %d eller ",i_spen);

	while((i_spen & i) >= 0)
		i_spen = i_spen << 1;
	while(i_spen != 0)
	{
		printf((i_spen & i) >= 0 ? "0" : "1");
		i_spen = i_spen << 1;
	}
	printf("\n");
	return 0;
}
