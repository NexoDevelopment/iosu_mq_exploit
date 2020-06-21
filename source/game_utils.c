#include "game_utils.h"

unsigned char *memcpy_buffer[0x400] __attribute__((section(".data")));

void pygecko_memcpy(unsigned char *dst, unsigned char *src, unsigned int len) {
	if(len>0x400) return;
	memcpy(memcpy_buffer, src, len);
	SC0x25_KernelCopyData((unsigned int)OSEffectiveToPhysical(dst), (unsigned int)&memcpy_buffer, len);
	DCFlushRange(dst, len);
	return;
}

void Write32(uint32_t *addr, uint32_t value)
{
	
	pygecko_memcpy((unsigned char *)addr, (unsigned char *)&value, 4);

}

void MemoryCopy(void *dest, void *src, int size)
{
	pygecko_memcpy((unsigned char *)dest, (unsigned char *)src, size);
}

unsigned int doBL( unsigned int dst, unsigned int src ){
    unsigned int newval = (dst - src);
    newval &= 0x03FFFFFC;
    newval |= 0x48000001;
    return newval;
}