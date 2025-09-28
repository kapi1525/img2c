#include <cstdio>
#include <filesystem>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"



int main(int argc, const char *argv[]) {
    if (argc != 3) {
        std::fprintf(stderr, "Usage: img2c <path> <variable prefix> > <output>\n");
        return -1;
    }
    std::filesystem::path path(argv[1]);
    path = std::filesystem::absolute(path);

    if (path.empty()) {
        std::fprintf(stderr, "Expected a path!\n");
        return -1;
    }

    const char* var_prefix = argv[2];

    int x, y, channels_in_file;
    auto *img = stbi_load(path.c_str(), &x, &y, &channels_in_file, 3);

    if (!img) {
        std::fprintf(stderr, "Failed to load image: \"%s\".\n", path.c_str());
        return -1;
    }

    std::printf("#pragma once\n\n");

    std::printf("static const int %s_width = %d;\n", var_prefix, x);
    std::printf("static const int %s_height = %d;\n\n", var_prefix, y);

    std::printf("static const unsigned char %s_img[] = {\n    ", var_prefix);
    for (size_t i = 0; i < x * y * 3; i++) {
        std::printf("0x%02x,", img[i]);
    }

    std::printf("\n};\n");
    return 0;
}
