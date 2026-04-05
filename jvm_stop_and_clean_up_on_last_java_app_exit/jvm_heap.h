#pragma once

typedef struct {
    void *slot1;
    void *slot2;
    void *slot1_heap;
    void *slot2_heap;
    size_t slot1_heap_size;
    size_t slot2_heap_size;
} JVM_HEAP;
