load("@rules_cc//cc:defs.bzl", "cc_test")

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
