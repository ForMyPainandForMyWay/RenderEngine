#include <algorithm>
#include <iostream>
#include "thread_pool.h"

class SimpleTask : public Task{
    void run() override {
        std::cout << "test\n" << std::endl;
    }
};

int main() {
    ThreadPool threadPool;
    threadPool.addTask(new SimpleTask());
    threadPool.addTask(new SimpleTask());
    threadPool.addTask(new SimpleTask());
    threadPool.addTask(new SimpleTask());
    threadPool.addTask(new SimpleTask());
    threadPool.addTask(new SimpleTask());

    return 0;
}