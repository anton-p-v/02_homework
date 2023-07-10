#include <gtest/gtest.h>

#include "ip_addresses.h"


namespace {

TEST(IpAddresses, ReadIpAddresses) {
  std::stringstream ss;

  ss
    << "79.235.120.32	0	2" << '\n'
    << "187.37.143.79	530	0" << '\n'
    << "158.135.163.135	2	0" << '\n'
    << "5.101.219.197	17	0" << '\n'
    << "158.140.180.27	2	0" << '\n';

  IpAddresses actual_value = ReadIpAddresses(ss);

  IpAddresses expected_value {
    { 79, 235, 120, 32},
    {187,  37, 143, 79},
    {158, 135, 163, 135},
    {  5, 101, 219, 197},
    {158, 140, 180, 27},
  };

  EXPECT_EQ(actual_value, expected_value);
}

}
