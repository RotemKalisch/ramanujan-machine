#include "src/meet.h"
#include "src/meet_map.h"

int main() {
    using namespace ramanujan;

    MeetMap meet_map;
    std::cout << "Creating generators..." << std::endl;
    std::vector<rhs::number_generator_t> gens = create_generators();
    std::cout << "Loading meet_map..." << std::endl;
    load(meet_map);
    std::cout << "Meeting..." << std::endl;
    meet(meet_map, gens, gens);
    return 0;
}
