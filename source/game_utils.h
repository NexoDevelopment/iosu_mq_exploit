#pragma once
#include "common.h"

void Write32(uint32_t *addr, uint32_t value);
void MemoryCopy(void *dest, void *src, int size);
unsigned int doBL( unsigned int dst, unsigned int src );