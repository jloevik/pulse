/*
 * Copyright (C) 2013-2014 Phokham Nonava
 *
 * Use of this source code is governed by the MIT license that can be
 * found in the LICENSE file.
 */
#ifndef PULSE_UCI_H
#define PULSE_UCI_H

#include "search.h"
#include "notation.h"

namespace pulse {

class Uci : public Protocol {
public:
  void run();

  virtual void sendBestMove(int bestMove, int ponderMove);
  virtual void sendStatus(
    int currentDepth, int currentMaxDepth, uint64_t totalNodes, int currentMove, int currentMoveNumber);
  virtual void sendStatus(
    bool force, int currentDepth, int currentMaxDepth, uint64_t totalNodes, int currentMove, int currentMoveNumber);
  virtual void sendMove(MoveList::Entry entry, int currentDepth, int currentMaxDepth, uint64_t totalNodes);

  static std::string fromMove(int move);

private:
  std::chrono::system_clock::time_point startTime;
  std::chrono::system_clock::time_point statusStartTime;

  // We have to maintain at least the state of the board and the search.
  std::unique_ptr<Board> board = std::unique_ptr<Board>(new Board(Notation::toBoard(Notation::STANDARDBOARD)));
  std::unique_ptr<Search> search = Search::newInfiniteSearch(*this, *board);

  void receiveInitialize();
  void receiveReady();
  void receiveNewGame();
  void receivePosition(std::istringstream& input);
  void receiveGo(std::istringstream& input);
  void receivePonderHit();
  void receiveStop();
};

}

#endif