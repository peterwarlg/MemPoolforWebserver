//
// Created by perterwarlg on 2021/6/8.
//
#pragma once

#include <stdlib.h>
#include <string.h>
#include <iostream>

//标识是否输出
extern bool FLAG;

typedef unsigned short US;


struct Block {
    Block* next;
    long int data;
};

struct MemoryBlock {
    MemoryBlock* prev;
    MemoryBlock* next;
    char pad[8];
    Block* freeBlock;
    char* lastBlock;

    MemoryBlock(US initialBolcks, US unitSize);

    static void* operator new(size_t, US initBlock, US unitSize) {
        return ::operator new(sizeof(MemoryBlock) + (initBlock * (unitSize)));
    }

    static void operator delete(void* p) {
        ::operator delete(p);
    }
};

