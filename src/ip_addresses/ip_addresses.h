#pragma once

#include <limits>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>


using IpAddress = std::tuple<unsigned, unsigned, unsigned, unsigned>;
using IpAddresses = std::vector<IpAddress>;

IpAddresses ReadIpAddresses(std::istream& in);

std::ostream& operator<<(std::ostream& os, const IpAddress& ip_address);
