#pragma once

#include <limits>
#include <iostream>
#include <string>
#include <array>
#include <vector>


using IpAddress = std::array<unsigned, 4>;
using IpAddresses = std::vector<IpAddress>;

IpAddresses ReadIpAddresses(std::istream& in);

std::ostream& operator<<(std::ostream& os, const IpAddress& ip_address);
