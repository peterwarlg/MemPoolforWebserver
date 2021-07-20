//
// Created by marvinle on 2019/2/27 10:19 AM.
//

#include "../include/HttpData.h"

void* HttpData::operator new(size_t, MemoryPool *mempool) {
    void *p = mempool->Alloc(sizeof(HttpData));
    if (FLAG) std::cout << "addr of HD : " << p << std::endl;
    return p;
}

