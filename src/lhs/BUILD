load("@rules_cc//cc:defs.bzl", "cc_library") 

cc_library(
    name = "enumerator",
    srcs = ["enumerator.cc"],
    hdrs = ["enumerator.h"],
    deps = [
        "//src/rhs:number_generator",
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
