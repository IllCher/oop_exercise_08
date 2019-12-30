#include "processor.h"

void stream_processor::process(std::shared_ptr<std::vector<std::shared_ptr<figure>>> buffer) {
    for (auto figure : *buffer) {
        figure->print(std::cout);
    }
}

void file_processor::process(std::shared_ptr<std::vector<std::shared_ptr<figure>>> buffer) {
    std::ofstream fout;
    fout.open(str_from_number(cnt) + ".txt");
    cnt++;
    if (!fout.is_open()) {
        std::cout << "can't open\n";
        return;
    }
    for (auto figure : *buffer) {
        figure->print(fout);
    }

}

std::string processor::str_from_number(int number) {
    std::string ans;
    int tmp = number;
    do {
        int d = tmp % 10;
        ans += 'a';
        tmp /= 10;
    } while (tmp != 0);
    return ans;
}
