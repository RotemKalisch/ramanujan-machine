#include "src/meet.h"
#include "src/meet_map.h"

int main() {
    using namespace ramanujan;

    MeetMap meet_map;
    std::cout << "Creating generators..." << std::endl;
    std::vector<rhs::number_generator_t> gens = create_generators(/*threshold=*/ 20);
    std::cout << "Loading meet_map..." << std::endl;
    load(meet_map, /*threshold=*/ 10);
    std::cout << "Meeting..." << std::endl;
    meet(meet_map, gens, gens, /*depth=*/100);
    return 0;
}
