#include <stdio.h>
#include <limits.h>

void print_biner(int i_spen)
{
	int i_m = INT_MIN;
	unsigned int i = *(int*)(&i_m);
	while((i_spen & i) == 0)
		i = i >> 1;
	while(i != 0)
	{
		printf((i_spen & i) == 0 ? "0" : "1");
		i = i >> 1;
	}
	printf("\n");
}

int main()
{	
	double vcc;
	double spe;
	int bit;
	printf("skriv cvv:");
	scanf("%lf",&vcc);

	printf("skriv spening:");
	scanf("%lf",&spe);

	printf("bit len:");
	scanf("%d",&bit);

	int i_spen = (int)((spe/vcc)*bit);
	printf("speningen er %d eller ",i_spen);
	print_biner(i_spen);


	return 0;
}
