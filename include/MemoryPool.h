//
// Created by perterwarlg on 2021/6/8.
//
#pragma once

#include <stdlib.h>
#include <map>
#include "MemoryBlock.h"
#include <typeinfo>
#include "MutexLock.h"
#include <type_traits>
#include <typeinfo>


class MemoryPool {
private:
    int initialBlocks;
    int POOLALIGNMENT = 16;
    MemoryBlock *block;
    MutexLock mMutex;
private:
    int AlignBytes(int);

protected:
    static MemoryPool *memoryPoolInstance;

    MemoryPool();

public:
    void *Alloc(int);

    template<typename T>
    void Deallocate(T* p) {
        //还内存块时加锁
        MutexLockGuard MG(mMutex);
        memset(p, 0, sizeof(T));
        if (FLAG) std::cout << "start deleter" << std::endl;
        Block* tmp = reinterpret_cast<Block *>(p);
        tmp->next = block->freeBlock;
        block->freeBlock = tmp;
        if (FLAG) std::cout << "finish deleter" << std::endl;
    }

    static MemoryPool *fooGetMemoryPoolInstance();

    ~MemoryPool();

    void fooPoolMapInit();
};
