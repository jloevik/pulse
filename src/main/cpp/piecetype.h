/*
 * Copyright (C) 2013-2014 Phokham Nonava
 *
 * Use of this source code is governed by the MIT license that can be
 * found in the LICENSE file.
 */
#ifndef PULSE_PIECETYPE_H
#define PULSE_PIECETYPE_H

#include <array>

namespace pulse {

class PieceType {
public:
  static const int MASK = 0x7;

  static const int PAWN = 0;
  static const int KNIGHT = 1;
  static const int BISHOP = 2;
  static const int ROOK = 3;
  static const int QUEEN = 4;
  static const int KING = 5;

  static const int NOPIECETYPE = 6;

  static const int SIZE = 6;
  static const std::array<int, SIZE> values;

  // Piece values as defined by Larry Kaufman
  static const int PAWN_VALUE = 100;
  static const int KNIGHT_VALUE = 325;
  static const int BISHOP_VALUE = 325;
  static const int ROOK_VALUE = 500;
  static const int QUEEN_VALUE = 975;
  static const int KING_VALUE = 20000;

  static bool isValid(int pieceType);
  static bool isValidPromotion(int pieceType);
  static bool isSliding(int pieceType);
  static int getValue(int pieceType);

private:
  PieceType();
  ~PieceType();
};

}

#endif
