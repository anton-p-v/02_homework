load("@rules_pkg//pkg:tar.bzl", "pkg_tar")
load("@rules_pkg//pkg:deb.bzl", "pkg_deb")

cc_library(
    name = "version",
    hdrs = ["version.h"],
    srcs = ["version.cpp"],
    local_defines = ["VERSION=$(VERSION)"],
)

cc_test(
    name = "version_test",
    size = "small",
    srcs = ["version_test.cpp"],
    deps = [
        "@googletest//:gtest_main",
        ":version",
    ],
)

cc_binary(
    name = "helloworld_cli",
    srcs = ["main.cpp"],
    deps = [
        ":version",
    ],
)

pkg_tar(
    name = "helloworld_cli_tar",
    srcs = [":helloworld_cli"],
    package_dir = "/usr/bin",
    package_file_name = "helloworld_cli.tar",
)

pkg_deb(
    name = "helloworld_cli_deb",
    data = ":helloworld_cli_tar",
    description = "homework for otus",
    maintainer = "antonplatonov@yandex-team.ru",
    package = "helloworld_cli",
    package_file_name = "helloworld-0.0.$(VERSION)-Linux.deb",
    version = "1.0",
)
