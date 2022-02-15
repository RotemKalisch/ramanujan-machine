load("@rules_cc//cc:defs.bzl", "cc_library") 

cc_library(
    name = "enumerator",
    srcs = ["enumerator.cc"],
    hdrs = ["enumerator.h"],
    deps = [
        ":mobius",
        "//src:meet_map",
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
