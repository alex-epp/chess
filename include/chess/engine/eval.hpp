#pragma once

#include "engine.hpp"
#include <chess/backend/chess.hpp>

#include <string_view>

namespace engine {

    class EvalResult {
    public:
        int wins, losses, draws;
    };

    inline bool is_game_over(const chess::Board& board) {
        return board.is_draw_50_move() || board.is_draw_insufficient_material() ||
               board.legal_moves().empty();
    }

    template <typename E1, typename E2>
    EvalResult eval(E1 engine, E2 opponent, size_t trials, std::string_view starting_fen = chess::STARTING_FEN) {
        std::vector<std::future<std::tuple<int, int, int>>> results;
        for (size_t i = 0; i < trials; ++i) {
            results.push_back(std::async([=]() {
                auto e = engine;
                auto o = opponent;
                auto board = chess::load_FEN<chess::Board>(starting_fen);
                while (!is_game_over(board)) {
                    auto move = e.move(board);
                    board.push_move(move);
                    if (is_game_over(board)) break;
                    move = o.move(board);
                    board.push_move(move);
                }
                if (board.is_draw_50_move() || board.is_draw_insufficient_material())
                    return std::make_tuple(0, 0, 1);
                else if (board.is_check(chess::Colour::WHITE))
                    return std::make_tuple(1, 0, 0);
                else if (board.is_check(chess::Colour::BLACK))
                    return std::make_tuple(0, 1, 0);
                else
                    return std::make_tuple(0, 0, 1);
            }));
        }

        EvalResult result = {0, 0, 0};
        for (auto& r : results) {
            const auto [wins, losses, draws] = r.get();
            result.wins += wins;
            result.losses += losses;
            result.draws += draws;
        }

        return result;
    }

}