#include "ip_addresses.h"


IpAddresses ReadIpAddresses(std::istream& in) {
  constexpr auto kMaxStreamSize = std::numeric_limits<std::streamsize>::max();

  IpAddresses addresses;

  while (in) {
    if (in.peek() == EOF) {
      break;
    }

    unsigned n1;
    unsigned n2;
    unsigned n3;
    unsigned n4;

    in >> n1;
    in.ignore(1);
    in >> n2;
    in.ignore(1);
    in >> n3;
    in.ignore(1);
    in >> n4;

    addresses.emplace_back(n1, n2, n3, n4);

    in.ignore(kMaxStreamSize, '\n');
  }

  return addresses;
}

std::ostream& operator<<(std::ostream& os, const IpAddress& ip_address) {
  os
    << std::get<0>(ip_address)
    << '.'
    << std::get<1>(ip_address)
    << '.'
    << std::get<2>(ip_address)
    << '.'
    << std::get<3>(ip_address);

  return os;  
}
