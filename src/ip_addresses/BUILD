cc_library(
    name = "ip_addresses",
    hdrs = ["ip_addresses.h"],
    srcs = ["ip_addresses.cpp"],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "ip_addresses_test",
    size = "small",
    srcs = [
        "ip_addresses_test.cpp",
    ],
    deps = [
        "@googletest//:gtest_main",
        ":ip_addresses",
    ],
)
