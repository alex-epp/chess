#ifndef BITSCAN_H
#define BITSCAN_H

#include <cstdint>
#include <limits>
#include <bit>


namespace bitscan {
	constexpr unsigned int END = std::numeric_limits<unsigned int>::max();

    inline unsigned int first(std::uint64_t mask) noexcept {
        if (mask == 0)
            return END;
        else
            return std::countr_zero(mask);
    }
    inline unsigned int next(unsigned long last, std::uint64_t mask) noexcept {
        mask >>= (last + 1);
        if (last >= 63 || mask == 0)
            return END;
        else
            return std::countr_zero(mask) + last + 1;
    }

	#define BITSCAN_FOREACH(mask, index) for (unsigned long index = bitscan::first((mask)); index != bitscan::END; index = bitscan::next(index, (mask)))
}

#endif
