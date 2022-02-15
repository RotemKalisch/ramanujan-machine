load("@rules_cc//cc:defs.bzl", "cc_library") 

cc_library(
    name = "compare",
    srcs = ["compare.cc"],
    hdrs = ["compare.h"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "meet",
    srcs = ["meet.cc"],
    hdrs = ["meet.h"],
    deps = [
        "//src/lhs:enumerator",
        "//src/rhs:enumerator",
        "//src/rhs:polynomial",
        "//src/rhs:number_generator",
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "meet_map",
    srcs = ["meet_map.cc"],
    hdrs = ["meet_map.h"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "utils",
    hdrs = ["utils.h"],
    visibility = ["//visibility:public"],
)
