#pragma warning(disable :4996)
#include <stdio.h>
#include <stdlib.h>
#include "cachesimulator.h"

//10만개 입력 받기
int main(void)
{
	FILE* fp;
	fp = fopen("linkbench.trc", "r");
	int input[100000];
	for (int i = 0; i < 100000; i++)
	{
		fscanf(fp, "%d", &input[i]);
	}

	for (int cache_slots = 100; cache_slots < 1001; cache_slots += 100)
	{
		CacheSimulator_t* cache_sim = CacheSimulator(cache_slots);
		for (int i = 0; i < 100000; i++)
		{
			do_sim_CacheSimulator(cache_sim, input[i]);
		}
		print_stats_CacheSimulator(cache_sim);
		destroyCacheSimulator(cache_sim);
	}
}