#include "cachesimulator.h"

CacheSimulator_t* CacheSimulator(int cache_slots_)
{
    CacheSimulator_t* sim = (CacheSimulator_t*)malloc(sizeof(CacheSimulator_t));
    if (!sim) {
        printf("Faled to Alloc\n");
        return NULL;
    }

    sim->cache = (int*)malloc(sizeof(int) * cache_slots_);
    if (!(sim->cache)) {
        printf("Failed to Alloc\n");
        return NULL;
    }
    sim->cache_hit = 0;
    sim->tot_cnt = 0;

    sim->do_sim = do_sim_CacheSimulator;
    sim->print_stats = print_stats_CacheSimulator;

    return sim;
}

void destroyCacheSimulator(CacheSimulator_t* sim)
{
    free(sim);
    return;
}

void do_sim_CacheSimulator(CacheSimulator_t* sim, int page)
{
    (sim->tot_cnt++);
    int temp = -1;
    int temp2;
    while (*(sim->cache + (++temp)) != NULL)
    {
        if (*(sim->cache + temp) == page)
        {
            temp2 = temp;
            break;
        }
    }
    while (*(sim->cache + (++temp != NULL)))
    {

    }
    return;
}

void print_stats_CacheSimulator(CacheSimulator_t* sim)
{
    printf("cache_slot = %d cache_hit = %d hit ratio = %f", sim->cache_slots, sim->cache_hit, (float)sim->cache_hit / (float)sim->tot_cnt);
    return;
}