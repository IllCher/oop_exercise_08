#include <iostream>
#include <memory>
#include <vector>
#include <thread>
#include "factory.h"
#include "figure.h"
#include "subscriber.h"
int check(int cnt) {

    return 0;
}
int main(int argc,char* argv[]) {
    if (argc != 2) {
        std::cout << "not enough arguments\n";
        return 1;
    }
    int b;
    int  buffer_size = std::stoi(argv[1]);
    std::shared_ptr<std::vector<std::shared_ptr<figure>>> buffer = std::make_shared<std::vector<std::shared_ptr<figure>>>();
    buffer->reserve(buffer_size);
    factory factory;
    std::string cmd;
    subscriber sub;
    sub.processors.push_back(std::make_shared<stream_processor>());
    sub.processors.push_back(std::make_shared<file_processor>());
    std::thread sub_thread(std::ref(sub));

    while (true) {
        std::unique_lock<std::mutex> locker(sub.mtx);
        std::cin >> cmd;
        if (cmd == "+") {
            try {
                buffer->push_back(factory.new_figure(std::cin));
            } catch (std::logic_error &e) {
                std::cout << e.what() << '\n';
                continue;
            }
            if (buffer->size() == buffer_size) {
                sub.buffer = buffer;
                sub.cond_var.notify_all();
                sub.cond_var.wait(locker, [&](){ return sub.buffer == nullptr;});
                buffer->clear();
            }
        } else if (cmd == "ext")  {
            break;
        } else {
            std::cout << "no such a command\n";
        }
    }
    sub.stop = true;
    sub.cond_var.notify_all();
    sub_thread.join();
    return 0;
}