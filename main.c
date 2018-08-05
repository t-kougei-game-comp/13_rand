#include <stdio.h>
#include <stdlib.h>

static int g_last = 0;
unsigned int my_rand()
{
    g_last = (48271 * g_last) % 0x7fffffff;
    return g_last;
}

#define a 48271
#define m 0x7fffffff
#define q (m / a)
#define r (m % a)

long int PMrand()
{
	int hi = g_last / q;
	int lo = g_last % q;
	int test = a * lo - r * hi;
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
        int x = PMrand()-1;
        int val = x / (0x7fffffff/max)+1;
	printf("%d\n", val);
    }
    
    return 0;
}
