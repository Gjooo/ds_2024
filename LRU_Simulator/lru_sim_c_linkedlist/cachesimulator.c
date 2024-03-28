#include "cachesimulator.h"

CacheSimulator_t* CacheSimulator(int cache_slots_)
{
    CacheSimulator_t* sim = (CacheSimulator_t*)malloc(sizeof(CacheSimulator_t));
    if (!sim) {
        printf("Faled to Alloc\n");
        return NULL;
    }

    sim->cache = LinkedList();
    sim->cache_size = 0;
    sim->cache_slots = cache_slots_;
    sim->cache_hit = 0;
    sim->tot_cnt = 0;

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
    if (indexLinkedList(sim->cache, page) != (-2))
    {
        removeLinkedList(sim->cache, page);
        (sim->cache_hit)++;
        appendLinkedList(sim->cache, page);
        return;
    }

    if (sim->cache_size >= sim->cache_slots)
    {
        popLinkedList(sim->cache, 0);
        appendLinkedList(sim->cache, page);
        return;
    }
    else
    {
        (sim->cache_size)++;
        appendLinkedList(sim->cache, page);
        return;
    }
    
}

void print_stats_CacheSimulator(CacheSimulator_t* sim)
{
    printf("cache_slot = %d cache_hit = %d hit ratio = %f\n", sim->cache_slots, sim->cache_hit, (float)sim->cache_hit / (float)sim->tot_cnt);
    return;
}