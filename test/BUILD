load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "continued_fraction_test",
    srcs = ["continued_fraction_test.cc"],
    deps = [
        "//src:compare",
        "//src:polynomial",
        "//src:continued_fraction",
        "@com_google_googletest//:gtest_main",
    ],
    visibility = ["//visibility:private"],
)

cc_test(
    name = "meet_test",
    srcs = ["meet_test.cc"],
    deps = [
        "//src:meet",
        "@com_google_googletest//:gtest_main",
    ],
    visibility = ["//visibility:private"],
)

cc_test(
    name = "mobius_test",
    srcs = ["mobius_test.cc"],
    deps = [
        "//src:compare",
        "//src:mobius",
        "@com_google_googletest//:gtest_main",
    ],
    visibility = ["//visibility:private"],
)

cc_test(
    name = "polynomial_test",
    srcs = ["polynomial_test.cc"],
    deps = [
        "//src:polynomial",
        "@com_google_googletest//:gtest_main",
    ],
    visibility = ["//visibility:private"],
)
