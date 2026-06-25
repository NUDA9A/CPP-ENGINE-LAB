#include <gtest/gtest.h>

#include <engine/math/vec3.hpp>

TEST(Vec3SmokeTest, CanCreateVector) {
    const engine::math::Vec3 v{ 1.0f, 2.0f, 3.0f };

    EXPECT_FLOAT_EQ(v.x, 1.0f);
    EXPECT_FLOAT_EQ(v.y, 2.0f);
    EXPECT_FLOAT_EQ(v.z, 3.0f);
}