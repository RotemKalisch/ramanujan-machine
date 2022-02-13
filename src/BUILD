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
    name = "polynomial",
    srcs = ["polynomial.cc"],
    hdrs = ["polynomial.h"],
    deps = ["//src:generator"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "mobius",
    srcs = ["mobius.cc"],
    hdrs = ["mobius.h"],
    visibility = ["//visibility:public"],
)
