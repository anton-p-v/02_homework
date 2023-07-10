load("@rules_pkg//pkg:tar.bzl", "pkg_tar")
load("@rules_pkg//pkg:deb.bzl", "pkg_deb")

cc_binary(
    name = "ip_filter",
    srcs = [
        "main.cpp",
    ],
    deps = [
        "//src/ip_addresses",
        "//src/version",
    ],
)

pkg_tar(
    name = "ip_filter_tar",
    srcs = [":ip_filter"],
    package_dir = "/usr/bin",
    package_file_name = "ip_filter.tar",
)

pkg_deb(
    name = "ip_filter_deb",
    data = ":ip_filter_tar",
    description = "02_homework for otus",
    maintainer = "antonplatonov@yandex-team.ru",
    package = "ip_filter",
    package_file_name = "ip_filter-0.0.$(VERSION)-Linux.deb",
    version = "1.0",
)
