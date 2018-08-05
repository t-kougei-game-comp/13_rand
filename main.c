#include <stdio.h>
#include <stdlib.h>

static unsigned int g_last = 0;
unsigned int my_rand()
{
    g_last = (48271 * (long long int)g_last) % 0x7fffffff;
    return g_last;
}

unsigned int load_data()
{
    char str[100];
    return (unsigned int)atoi(fgets(str, sizeof(str), stdin));
}

int main(int argc, char *argv[]) 
{
    unsigned int seed, max, num;
    
    seed = load_data();
    max  = load_data();
    num  = load_data();
    
    g_last = seed;
    
    for(int i = 0; i < num; i++){
        unsigned int x = my_rand();
        unsigned int val = x / ((0x7fffffff+max-1)/max)+1;
	printf("%d\n", val);
    }
    
    return 0;
}
