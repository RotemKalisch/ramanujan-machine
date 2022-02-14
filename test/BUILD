load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "continued_fraction_test",
    srcs = ["continued_fraction_test.cc"],
    deps = [
        "//src:compare",
        "//src/rhs:polynomial",
        "//src/rhs:continued_fraction",
        "@com_google_googletest//:gtest_main",
    ],
    visibility = ["//visibility:private"],
)

cc_test(
    name = "meet_map_test",
    srcs = ["meet_map_test.cc"],
    deps = [
        "//src:meet_map",
        "@com_google_googletest//:gtest_main",
    ],
    visibility = ["//visibility:private"],
)

cc_test(
    name = "mobius_test",
    srcs = ["mobius_test.cc"],
    deps = [
        "//src:compare",
        "//src/lhs:mobius",
        "@com_google_googletest//:gtest_main",
    ],
    visibility = ["//visibility:private"],
)

cc_test(
    name = "polynomial_test",
    srcs = ["polynomial_test.cc"],
    deps = [
        "//src/rhs:polynomial",
        "@com_google_googletest//:gtest_main",
    ],
    visibility = ["//visibility:private"],
)
