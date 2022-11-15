#include <stdio.h>
#include <limits.h>

void print_biner(int i_spen)                                                                              
{
        int i_m = INT_MIN;
        unsigned int i = *(int*)(&i_m);
//        while((i_spen & i) == 0)
//                i = i >> 1;
        while(i != 0)
        {   
                (i_spen & i) == 0 ? putchar('0') : putchar('1');;;
                i = i >> 1;
        }
}

int main()
{
	int h = 0;
	for(int i = 1;i;i++)
	{
		printf("\t0x%08x\r%d\t",i,i);
		print_biner(i);
	}
	return 0;
}
