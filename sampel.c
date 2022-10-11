#include <stdio.h>
#include <limits.h>

int main()
{	
	double vcc;
	double spe;
	int i_m = INT_MIN;
	unsigned int i = *(int*)(&i_m);
	int bit;
	printf("skriv cvv:");
	scanf("%lf",&vcc);

	printf("skriv spening:");
	scanf("%lf",&spe);

	printf("bit len:");
	scanf("%d",&bit);

	int i_spen = (int)((spe/vcc)*bit);
	printf("speningen er %d eller ",i_spen);

	while((i_spen & i) == 0)
		i = i >> 1;
	while(i != 0)
	{
		printf((i_spen & i) == 0 ? "0" : "1");
		i = i >> 1;
	}
	printf("\n");
	return 0;
}
