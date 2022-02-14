load("@rules_cc//cc:defs.bzl", "cc_library") 

cc_library(
    name = "compare",
    srcs = ["compare.cc"],
    hdrs = ["compare.h"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "continued_fraction",
    hdrs = ["continued_fraction.h"],
    deps = ["//src:polynomial"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "generator",
    hdrs = ["generator.h"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "lhs_enumerator",
    srcs = ["lhs_enumerator.cc"],
    hdrs = ["lhs_enumerator.h"],
    deps = [
        "//src:generator",
        "//src:meet",
        "//src:mobius",
        "//src:utils",
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "polynomial",
    srcs = ["polynomial.cc"],
    hdrs = ["polynomial.h"],
    deps = [
        "//src:generator",
        "//src:utils",
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "meet",
    srcs = ["meet.cc"],
    hdrs = ["meet.h"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "mobius",
    srcs = ["mobius.cc"],
    hdrs = ["mobius.h"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "utils",
    hdrs = ["utils.h"],
    visibility = ["//visibility:public"],
)
