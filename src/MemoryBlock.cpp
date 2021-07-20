//
// Created by wangzitu on 2021/6/9.
//
#include "../include/MemoryBlock.h"

//标识是否输出
bool FLAG = false;

MemoryBlock::MemoryBlock(US initialBlocks, US unitSize) :
        prev(nullptr), next(nullptr), freeBlock(nullptr), lastBlock(nullptr)
{
//    memset(&lastBlock + 1, 0, initialBlocks * unitSize);
    char* padptr = this->pad;     //一个指向pad的char*，用来之后不断后移划分block
    padptr += 24;           //第一个block的位置

    Block* current = reinterpret_cast<Block*>(padptr);      //一个current用来迭代，第一个指向刚刚创建的那个block
    this->freeBlock = current;                                    //当前可用的block位置，就在current
    this->freeBlock->data = 0;
    for (int i = 1; i < initialBlocks; i++) {
        padptr += unitSize;                                 //不断后移unitSize个字节，划分Block
        current->next = reinterpret_cast<Block*>(padptr);   //指向下一个block
        current->data = i;
        current = current->next;//----------------------------//迭代
    }
    current->data = initialBlocks;
    lastBlock = reinterpret_cast<char*>(current);           //当前block链的末尾
//    lastBlock += unitSize;
//    std::cout << "freeblock: " << freeBlock << std::endl;
//    std::cout << (void*)(freeBlock) << std::endl;
    current->next = nullptr;
//    std::cout << "freeblock->next: " << freeBlock->next << std::endl;
//    std::cout << "unitSize: " << unitSize << std::endl;
//    Block* tmp = this->freeBlock;
//    int i = 0;
//    while(tmp != nullptr) {
//        std::cout << tmp->data << std::endl;
//        tmp = tmp->next;
//    }
}

