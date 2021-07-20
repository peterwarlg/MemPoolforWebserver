#include <iostream>
//#include "include/MemoryPool.h"
#include "include/HttpData.h"
#include <memory>
//#include "include/MemoryPool.h"
#include <vector>
#include <chrono>

MemoryPool *mempool = MemoryPool::fooGetMemoryPoolInstance();

void deleter(HttpData *p) {
    mempool->Deallocate(p);
}

int main() {

    {
        std::vector<std::shared_ptr<HttpData>> vec(10005);
        const auto t1 = std::chrono::system_clock::now();
        for (int i = 0; i < 10; i++) {
            {
                std::shared_ptr<HttpData> s(new(mempool) HttpData(), deleter);
            }
        }
        const auto t2 = std::chrono::system_clock::now();
        const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
        std::cout << "Time : " << duration * 1e-3 << std::endl;

    }
    mempool->~MemoryPool();
    return 0;
}
