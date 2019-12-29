#include "processor.h"

void stream_processor::process(std::shared_ptr<std::vector<std::shared_ptr<figure>>> buffer) {
    for (const auto& figure : *buffer) {
        figure->print(std::cout);
    }
}

void file_processor::process(std::shared_ptr<std::vector<std::shared_ptr<figure>>> buffer) {
    std::ofstream fout;
    fout.open(std::to_string(counter) + ".txt");
    counter++;
    if (!fout.is_open()) {
        std::cout << "File not opened\n";
        return;
    }
    for (const auto& figure : *buffer) {
        figure->print(fout);
    }

}
