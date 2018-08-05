#include <stdio.h>
#include <stdlib.h>

static unsigned long g_last = 0;
unsigned int my_rand()
{
    g_last = (48271 * g_last) % 0x7fffffff;
    return g_last;
}

#define a 48271
#define m 2147483647
#define q (m / a)
#define r (m % a)

long int PMrand()
{
	long int hi = g_last / q;
	long int lo = g_last % q;
	long int test = a * lo - r * hi;
	if(test > 0)
		g_last = test;
	else	g_last = test + m;
	return g_last;
}

int load_data()
{
    char str[100];
    return  atoi(fgets(str, sizeof(str), stdin));
}

int main(int argc, char *argv[]) 
{
    int seed, max, num;
    
    seed = load_data();
    max  = load_data();
    num  = load_data();
    
    g_last = seed;
    
    for(int i = 0; i < num; i++){
        unsigned int x = PMrand();
        unsigned int val = x / (0x7fffffff/max)+1;
        printf("%u\n", val);
    }
    
    return 0;
}
