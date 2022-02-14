load("@rules_cc//cc:defs.bzl", "cc_library") 

cc_library(
    name = "lhs_enumerator",
    srcs = ["lhs_enumerator.cc"],
    hdrs = ["lhs_enumerator.h"],
    deps = [
        "//src:generator",
        "//src:meet_map",
        ":mobius",
        "//src:utils",
    ],
    visibility = ["//visibility:public"],
)
cc_library(
    name = "mobius",
    srcs = ["mobius.cc"],
    hdrs = ["mobius.h"],
    visibility = ["//visibility:public"],
)
