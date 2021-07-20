//
// Created by marvinle on 2019/2/26 2:39 PM.
//

#pragma once

#include <memory>
#include "MemoryPool.h"

struct S {
    int a;
};
class HttpData : public std::enable_shared_from_this<HttpData> {
public:
    int a;
    int b;
    long int c;

public:
    void* operator new(size_t, MemoryPool* mempool);
};


//#endif //WEBSERVER_HTTPDATA_H
