#ifndef _HMAP_H
#define _HMAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef HMAP_KEY_TYPE
#define HMAP_KEY_TYPE char *
#endif

#ifndef HMAP_VAL_TYPE
#define HMAP_VAL_TYPE void *
#endif

typedef HMAP_KEY_TYPE hkey;
typedef HMAP_VAL_TYPE hval;

typedef struct hash_t Hash;
struct hash_t
{
    hkey key;
    hval val;

    Hash *previous;
    Hash *next;
};

typedef struct hmap_t HashMap;
struct hmap_t
{
    Hash *first;
    Hash *last;
};

HashMap
hmap_init();

hval
hmap_get(HashMap map, hkey key);

int
hmap_contains(HashMap map, hkey key);

void
hmap_set(HashMap *map, hkey key, hval val);

#define HMAP_KEY_NOT_EXISTS 1

int
hmap_remove(HashMap *map, hkey key);

void
hmap_loop(HashMap *map, void (*cb)(Hash*, void*), void* args);

#endif
