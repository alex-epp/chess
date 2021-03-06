#include <catch2/catch.hpp>
#include <cstdint>
#include <sstream>

#include <chess/backend/chess.hpp>

namespace tests {
	constexpr auto initial = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
	constexpr auto kiwipete = "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1";
	constexpr auto position_3 = "8/2p5/3p4/KP5r/1R3p1k/8/4P1P1/8 w - - 0 1";
	constexpr auto position_4 = "r3k2r/Pppp1ppp/1b3nbN/nP6/BBP1P3/q4N2/Pp1P2PP/R2Q1RK1 w kq - 0 1";
	constexpr auto position_5 = "rnbq1k1r/pp1Pbppp/2p5/8/2B5/8/PPP1NnPP/RNBQK2R w KQ - 1 8";
	constexpr auto position_6 = "r4rk1/1pp1qppp/p1np1n2/2b1p1B1/2B1P1b1/P1NP1N2/1PP1QPPP/R4RK1 w - - 0 10";

    void perft_test(const char* fen, std::initializer_list<size_t> nodes_list) {
        size_t depth = 1;
        for (auto it = nodes_list.begin(); it != nodes_list.end(); ++it, ++depth) {
            REQUIRE(static_cast<size_t>(*it) == chess::perft(chess::load_FEN<chess::Board>(fen), depth));
        }
    }

    void perft_cache_test(const char* fen, std::initializer_list<size_t> nodes_list) {
        size_t depth = 1;
        for (auto it = nodes_list.begin(); it != nodes_list.end(); ++it, ++depth) {
            REQUIRE(static_cast<size_t>(*it) == chess::perft_cache(chess::load_FEN<chess::Board>(fen), depth));
        }
    }

    void perft_parallel_test(const char* fen, std::initializer_list<size_t> nodes_list) {
        size_t depth = 1;
        for (auto it = nodes_list.begin(); it != nodes_list.end(); ++it, ++depth) {
            REQUIRE(static_cast<size_t>(*it) == chess::perft_parallel(chess::load_FEN<chess::Board>(fen), depth));
        }
    }

	TEST_CASE("perft", "[!hide]") {
		SECTION("perft_initial") { perft_test(initial, { 20, 400, 8902, 197281, 4865609 }); }
		SECTION("perft_kiwipete") { perft_test(kiwipete, { 48, 2039, 97862, 4085603, 193690690 }); }
		SECTION("perft_position_3") { perft_test(position_3, { 14, 191, 2812, 43238, 674624 }); }
		SECTION("perft_position_4") { perft_test(position_4, { 6, 264, 9467, 422333, 15833292 }); }
		SECTION("perft_position_5") { perft_test(position_5, { 44, 1486, 62379, 2103487, 89941194 }); }
		SECTION("perft_position_6") { perft_test(position_6, { 46, 2079, 89890, 3894594, 164075551,  6923051137 }); }
	}

    TEST_CASE("perft_cache", "[!hide]") {
        SECTION("perft_initial") { perft_cache_test(initial, { 20, 400, 8902, 197'281, 4'865'609 }); }
        SECTION("perft_kiwipete") { perft_cache_test(kiwipete, { 48, 20'39, 97'862, 4'085'603, 193'690'690 }); }
        SECTION("perft_position_3") { perft_cache_test(position_3, { 14, 191, 2'812, 43'238, 674'624 }); }
        SECTION("perft_position_4") { perft_cache_test(position_4, { 6, 264, 9'467, 422'333, 15'833'292 }); }
        SECTION("perft_position_5") { perft_cache_test(position_5, { 44, 1486, 62'379, 2'103'487, 89'941'194 }); }
        SECTION("perft_position_6") { perft_cache_test(position_6, { 46, 2079, 89'890, 3'894'594, 164'075'551,  6'923'051'137 }); }
    }

    TEST_CASE("perft_parallel") {
        SECTION("perft_initial") { perft_parallel_test(initial, { 20, 400, 8902, 197'281, 4'865'609 }); }
        SECTION("perft_kiwipete") { perft_parallel_test(kiwipete, { 48, 20'39, 97'862, 4'085'603, 193'690'690 }); }
        SECTION("perft_position_3") { perft_parallel_test(position_3, { 14, 191, 2'812, 43'238, 674'624 }); }
        SECTION("perft_position_4") { perft_parallel_test(position_4, { 6, 264, 9'467, 422'333, 15'833'292 }); }
        SECTION("perft_position_5") { perft_parallel_test(position_5, { 44, 1486, 62'379, 2'103'487, 89'941'194 }); }
        SECTION("perft_position_6") { perft_parallel_test(position_6, { 46, 2079, 89'890, 3'894'594, 164'075'551,  6'923'051'137 }); }
    }
}