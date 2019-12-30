#include "subscriber.h"

void subscriber::operator()() {
    while(true) {
        std::unique_lock<std::mutex>lock(mtx);
        cond_var.wait(lock,[&]{ return (buffer != nullptr || stop);});
        if (stop) {
            break;
        }
        for (const auto& processor_elem: processors) {
            processor_elem->process(buffer);
        }
        buffer = nullptr;
        cond_var.notify_all();
    }
}