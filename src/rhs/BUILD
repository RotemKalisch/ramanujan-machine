load("@rules_cc//cc:defs.bzl", "cc_library") 

cc_library(
    name = "continued_fraction",
    hdrs = ["continued_fraction.h"],
    deps = [":polynomial"],
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
    deps = [
        ":generator",
        "//src:utils",
    ],
    visibility = ["//visibility:public"],
)
