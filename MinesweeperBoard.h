//
// Created by ja on 09.03.2020.
//

#ifndef UNTITLED1_MINESWEEPERBOARD_H
#define UNTITLED1_MINESWEEPERBOARD_H


enum GameMode  {DEBUG,EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };
struct field
{
    bool hasFlay;
    bool hasMine;
    bool isRevealed;
};
class MinesweeperBoard
{
    field board[100][100];
    int width;
    int height;
    GameMode  mode;
    int bomb_amount;
    GameState status_gry;
    int mines_left;
    int number_of_player_action;

public:
    MinesweeperBoard(int height,int width,GameMode mode);

    void Debug_Display() const;

        int getBoardWidth() const;

    int getBoardHeight() const;

    int getMineCount() const;

    int countMines(int x, int y) const;

    bool hasFlag(int x, int y) const;

    void toggleFlag(int x, int y);

    void revealField(int x, int y);

    bool isRevealed(int x, int y) const;

    GameState getGameState() const;

    char getFieldInfo(int x, int y) const;

};

#endif //UNTITLED1_MINESWEEPERBOARD_H
