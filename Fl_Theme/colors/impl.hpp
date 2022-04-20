#pragma once

namespace detail {
constexpr unsigned int from_rgb(unsigned char r, unsigned char g, unsigned char b, unsigned char) {
    auto a = 0;
    return ((r & 0xff) << 24) + ((g & 0xff) << 16) + ((b & 0xff) << 8) + (a & 0xff);
}
} // namespace detail