#include <iostream>
#include <memory>
#include <vector>
#include <thread>
#include "factory.h"
#include "figure.h"
#include "octagon.h"
#include "quadrate.h"
#include "triangle.h"
#include "subscriber.h"
/*int for_test(int cnt, int size) {
    std::shared_ptr<std::vector<std::shared_ptr<figure>>> buffer = std::make_shared<std::vector<std::shared_ptr<figure>>>();
    buffer->reserve(size);
    int tmp = size;
    int fig = 0;
    while (cnt != 0) {
        if (tmp == 0) {
            tmp = size;
            cnt--;
        }
        if (fig == 0) {
            std::shared_ptr<figure> cur = std::shared_ptr<figure>( new  octagon(point(rand(), rand()), point(rand(), rand()),
                                                point(rand(), rand()), point(rand(), rand()),
                                                point(rand(), rand()), point(rand(), rand()),
                                                point(rand(), rand()),
                                                point(rand(), rand())));
            buffer->push_back(cur);
            fig++;
        } else if (fig == 1) {
            std::shared_ptr<figure> cur = std::shared_ptr<figure>( new  quadrate(point(rand(), rand()), point(rand(), rand())));
            buffer->push_back(cur);
            fig++;
        } else if (fig == 2) {
            std::shared_ptr<figure> cur = std::shared_ptr<figure>( new  triangle(point(2, 0), point(0, 4), point(-3, 0)));
            buffer->push_back(cur);
            fig = 0;
        } else {
            std::cout << "How?\n";
        }
        tmp--;
    }
    return 0;
}*/
int main(int argc,char* argv[]) {
    if (argc != 2) {
        std::cout << "not enough arguments\n";
        return 1;
    }
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
                sub.cond_var.wait(locker);
                buffer->clear();
            }
        } else if (cmd == "ext")  {
            break;
        } else {
            std::cout << "no such a command\n";
        }
    }
    sub.end = true;
    sub.cond_var.notify_all();
    sub_thread.join();
    return 0;
}