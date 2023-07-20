#include <algorithm>

#include "ip_addresses/ip_addresses.h"


struct CompareIpAddress {
  bool operator()(const IpAddress& ip_address, unsigned value) const {
    return ip_address[0] > value;
  }
  bool operator()(unsigned value, const IpAddress& ip_address) const {
    return value > ip_address[0];
  }

  bool operator()(const IpAddress& ip_address, std::array<unsigned, 2> value) const {
    return std::array<unsigned, 2>{ip_address[0], ip_address[1]} > value;
  }
  bool operator()(std::array<unsigned, 2> value, const IpAddress& ip_address) const {
    return value > std::array<unsigned, 2>{ip_address[0], ip_address[1]};
  }
};

int main(int argc, char const *argv[]) {
  try {
    IpAddresses ip_addresses = ReadIpAddresses(std::cin);

    std::sort(ip_addresses.rbegin(), ip_addresses.rend());

    for (const auto& ip_address : ip_addresses) {
      std::cout << ip_address << '\n';
    }

    {
      const auto range = std::equal_range(ip_addresses.begin(), ip_addresses.end(), 1u, CompareIpAddress{});

      for (auto it = range.first; it != range.second; ++it) {
        std::cout << *it << '\n';
      }
    }

    {
      const auto range = std::equal_range(ip_addresses.begin(), ip_addresses.end(), std::array<unsigned, 2>{46u, 70u}, CompareIpAddress{});

      for (auto it = range.first; it != range.second; ++it) {
        std::cout << *it << '\n';
      }
    }

    {
      auto lambda = [](const IpAddress& ip_address) {
        return std::get<0>(ip_address) == 46
          || std::get<1>(ip_address) == 46
          || std::get<2>(ip_address) == 46
          || std::get<3>(ip_address) == 46; 
      };

      const auto it_begin = ip_addresses.begin();
      const auto it_end = ip_addresses.end();

      for (
        auto it_current = std::find_if(it_begin, it_end, lambda);
        it_current != it_end;
        it_current = std::find_if(std::next(it_current), it_end, lambda)) {
        std::cout << *it_current << '\n';
      }
    }
  } catch(const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
