#include <gtest/gtest.h>

#include "src/meet_map.h"

namespace ramanujan {

static constexpr double epsilon = 0.0001;

TEST(Meet, contains) {
    MeetMap meet_map;
    static constexpr double key = 1.34950948573;
    EXPECT_FALSE(meet_map.contains(key));
    meet_map.insert(key, "key");
    EXPECT_TRUE(meet_map.contains(key));
}

TEST(Meet, resolution) {
    MeetMap meet_map;
    static constexpr double fraction = 1.0 / MeetMap::RESOLUTION;
    static constexpr double key = 1.349509485735987439;
    meet_map.insert(key, "key");
    EXPECT_TRUE(meet_map.contains(key));
    EXPECT_FALSE(meet_map.contains(key - fraction));
    EXPECT_FALSE(meet_map.contains(key + fraction));
}

} // namespace ramanujan
