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
    sim->cache_slots = cache_slots_;
    sim->cache_size = 0;
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
    int temp = sim->cache_size - 1;
    int temp2 = 0;
    while(temp >= 0)//arr을 순회해보자
    {
        if (sim->cache[temp] == page)
        {
            temp2 = 1; //arr에 있는 경우
            sim->cache_hit++;
            break;
        }
        temp--;
    }
    if (!temp2) //arr에 없음
    {
        if (sim->cache_size == sim->cache_slots)
        { //cache가 꽉참
            for (int i = 0; i < sim->cache_size - 1; i++)
            { //앞으로 1 당기기
                sim->cache[i] = sim->cache[i + 1];
            }
            sim->cache[sim->cache_size - 1] = page;
        }
        else {
            sim->cache[sim->cache_size] = page;
            sim->cache_size++;
        }
        return;
    }
    //arr의 temp번에 있음!!
    while (temp < sim->cache_size-1)
    {//temp+1번째부터 끝까지 앞으로 1칸 당기기
        sim->cache[temp] = sim->cache[temp + 1];
        temp++;
    }
    sim->cache[sim->cache_size - 1] = page;
}

void print_stats_CacheSimulator(CacheSimulator_t* sim)
{
    printf("cache_slot = %d cache_hit = %d hit ratio = %f\n", sim->cache_slots, sim->cache_hit, (float)sim->cache_hit / (float)sim->tot_cnt);
    return;
}