#include <stdio.h>
#include <stdlib.h>

static int g_last = 0;
unsigned int my_rand()
{
    g_last = (48271 * (long long int)g_last) % 0x7fffffff;
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
        int x = my_rand();
        int val = x / (((long long int)0x7fffffff+max-1)/max)+1;
	printf("%d\n", val);
    }
    
    return 0;
}
