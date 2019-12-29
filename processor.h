#ifndef OOP_EXERCISE_08_PROCESSOR_H
#define OOP_EXERCISE_08_PROCESSOR_H
#include <iostream>
#include <condition_variable>
#include <thread>
#include <vector>
#include <mutex>
#include "factory.h"
#include "figure.h"

struct processor {
    virtual void process(std::shared_ptr<std::vector<std::shared_ptr<figure>>> buffer) = 0;

};

struct stream_processor : processor {
    void process(std::shared_ptr<std::vector<std::shared_ptr<figure>>> buffer) override;
};

struct file_processor : processor {
    void process(std::shared_ptr<std::vector<std::shared_ptr<figure>>> buffer) override;
private:
    int counter = 0;
};
#endif
