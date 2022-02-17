load("@rules_cc//cc:defs.bzl", "cc_library") 

cc_library(
    name = "continued_fraction",
    srcs = ["continued_fraction.cc"],
    hdrs = ["continued_fraction.h"],
    deps = [":polynomial"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "number_generator",
    srcs = ["number_generator.cc"],
    hdrs = ["number_generator.h"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "polynomial",
    srcs = ["polynomial.cc"],
    hdrs = ["polynomial.h"],
    deps = [
        ":number_generator",
        "//src:utils",
    ],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "enumerator",
    hdrs = ["enumerator.h"],
    deps = [
        ":number_generator",
        ":continued_fraction",
        "//src:meet_map",
    ],
    visibility = ["//visibility:public"],
)
