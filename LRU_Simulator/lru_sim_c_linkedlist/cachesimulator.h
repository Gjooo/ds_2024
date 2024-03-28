#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

typedef struct cachesimulator {
    int cache_slots;
    LinkedList_t* cache;
    int cache_size;
    int cache_hit;
    int tot_cnt;

} CacheSimulator_t;

CacheSimulator_t* CacheSimulator(int cache_slots_);
void destroyCacheSimulator(CacheSimulator_t* sim);
void do_sim_CacheSimulator(CacheSimulator_t* sim, int page);
void print_stats_CacheSimulator(CacheSimulator_t* sim);