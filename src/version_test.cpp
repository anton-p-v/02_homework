#include <gtest/gtest.h>

#include "version.h"


TEST(VersionTest, BasicAssertions) {
  EXPECT_EQ(version(), 1);
}
