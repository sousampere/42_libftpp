#include "src/design_patterns/design_patterns.hpp"
#include <iostream>

void say_hello() {
    std::cout << "Hello world\n";
}

void say_bye() {
    std::cout << "bye !\n";
}

int main() {

    // --- Observer ---

    Observer<int> obs;

    obs.subscribe(42, say_hello);
    obs.subscribe(8, say_bye);
    obs.notify(42);
    obs.notify(8);
    return 0;
}