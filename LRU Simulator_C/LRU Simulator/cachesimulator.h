#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct cachesimulator {
    int cache_slots;
    int* cache;
    int cache_hit;
    int tot_cnt;

    void (*do_sim)(CacheSimulator_t*, int);
    void (*print_stats)(CacheSimulator_t*)
} CacheSimulator_t;

CacheSimulator_t* CacheSimulator(int cache_slots_);
void destroyCacheSimulator(CacheSimulator_t* sim);
void do_sim_CacheSimulator(CacheSimulator_t* sim, int page);
void print_stats_CacheSimulator(CacheSimulator_t* sim);