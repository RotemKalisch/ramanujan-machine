load("@rules_cc//cc:defs.bzl", "cc_test")

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
