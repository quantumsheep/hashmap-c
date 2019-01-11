# HashMap C library
This library provide type-customizable linked list HashMap and functions to made their use easy. Working on any operating system.


# How to install
Just drop `async.h` and `async.c` in your project and include `async.h` using a relative path.


# Usage
## hmap_init()
```c
HashMap
hmap_init();
```
Initialize a HashMap. **It's very important to use this function before sending a HashMap variable into any functions of this library! If not it will just crash your program.**

## hmap_set()
```c
hval
hmap_get(HashMap map, hkey key);
```
Get the value paired with the given key.

### Parameters
**map**: a HashMap.  
**key**: the wanted value's key.  

### Return value
It returns a `hval`, defined by `HMAP_VAL_TYPE` (see [Change default types part](#change-default-types)) or `NULL` if the key doesn't exists.

## hmap_contains()
```c
int
hmap_contains(HashMap map, hkey key);
```
Check if a key is contained in the map.

### Parameters
**map**: a HashMap.  
**key**: the wanted key.  

### Return value
`1` if it's contained in `map`, `0` if not.

## hmap_set()
```c
void
hmap_set(HashMap *map, hkey key, hval val);
```
Set a key-value pair on a map.  
A new `Hash` will be created in case of the key is not already present, if the key already exists, the value will be replaced.

### Parameters
**map**: a HashMap.  
**key**: the key.  
**val**: the value.  

## hmap_remove()
```c
int
hmap_remove(HashMap *map, hkey key);
```
Remove a key-value from a map.

### Parameters
**map**: a HashMap.  
**key**: the key to remove.  

### Return value
An error code, if it occurs. This code can be `0` if no error or `HMAP_KEY_NOT_EXISTS` if the key to remove doesn't exists.

### Parameters
**map**: a HashMap.  
**key**: the key.  
**val**: the value.  

## hmap_loop()
```c
void
hmap_loop(HashMap *map, void (*cb)(Hash*, void*), void* args);
```
Call a function (`cb`) for each `Hash` in a `HashTable`.

### Parameters
**map**: a HashMap.  
**cb**: a pointer to a function that takes a `Hash *` and a `void *`.  
**args**: the callback's arguments. It will be sent to the second callback's argument.  


# Change default types
Their is 2 constants defined in `hmap.h`:
  - `HMAP_KEY_TYPE` (hkey)
  - `HMAP_VAL_TYPE` (hval)

By default `HMAP_KEY_TYPE` is a `char *` and `HMAP_VAL_TYPE` is a `void *`.  
To customize them, just define them before including `hmap.h`.

```c
#define HMAP_KEY_TYPE char *
#define HMAP_VAL_TYPE void *

#include "hmap.h"
```
