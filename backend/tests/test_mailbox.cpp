#include "catch.hpp"

#include <cstdint>
#include <sstream>

#include "../mailbox.hpp"

using namespace chess;


namespace tests
{
	TEST_CASE("TestMailbox") {
		SECTION("TestFlipVertical") {
			Mailbox mb;
			mb.set(PI::B3, Piece(Piece::ROOK, Piece::BLACK));

			Mailbox mb_flip_2 = mb;
			mb_flip_2.flip();
			mb_flip_2.flip();
			REQUIRE(mb == mb_flip_2);

			Mailbox mb_flip = mb;
			mb_flip.flip();
			Mailbox mb_flip_expected;
			mb_flip_expected.set(PI::B6, Piece(Piece::ROOK, Piece::WHITE));

			REQUIRE(mb_flip_expected == mb_flip);
		}
	};
}