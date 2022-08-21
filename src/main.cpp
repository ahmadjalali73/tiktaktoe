#include <iostream>
#include <limits>
#include <list>
#include <sys/socket.h>
#include <vector>

class index {
private:
  int i, j;

public:
  int get_i() { return this->i; }
  int get_j() { return this->j; }
  void setter(int i, int j) {
    this->i = i;
    this->j = j;
  }
};

index AI_gamer(int board[3][3], int mark) {
  std::list<index> null_indexes;
  std::list<index> ai_indexes;
  std::list<index> human_indexes;
  index res;
  res.setter(-1, -1);
  int antimark;
  if (mark == 0)
    antimark = 1;
  else
    antimark = 0;
  index tmp;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][(j + 3) % 3] == mark) {
        if (board[i][(j + 4) % 3] == mark) {
          if (board[i][(j + 5) % 3] == -1)
            res.setter(i, (j + 5) % 3);
        } else if (board[i][(j + 5) % 3] == mark) {
          if (board[i][(j + 5) % 3] == -1)
            res.setter(i, (j + 4) % 3);
        }
        if (board[(i + 4) % 3][j] == mark) {
          if (board[(i + 5) % 3][j] == -1)
            res.setter((i + 5) % 3, j);
        } else if (board[(i + 5) % 3][j] == mark) {
          if (board[(i + 4) % 3][j] == -1)
            res.setter((i + 4) % 3, j);
        }
      }
    }
  }
  if (res.get_i() != -1)
    return res;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][(j + 3) % 3] == antimark) {
        if (board[i][(j + 4) % 3] == antimark) {
          if (board[i][(j + 5) % 3] == -1)
            res.setter(i, (j + 5) % 3);
        } else if (board[i][(j + 5) % 3] == antimark) {
          if (board[i][(j + 5) % 3] == -1) {
            res.setter(i, (j + 4) % 3);
          }
        }
        if (board[(i + 4) % 3][j] == antimark) {
          if (board[(i + 5) % 3][j] == -1)
            res.setter((i + 5) % 3, j);
        } else if (board[(i + 5) % 3][j] == antimark) {
          if (board[(i + 4) % 3][j] == -1)
            res.setter((i + 4) % 3, j);
        }
      }
    }
  }
  if (res.get_i() != -1)
    return res;
  int row, column;
  if (res.get_i() == -1) {
    while (true) {
      row = rand() % 3;
      column = rand() % 3;
      if (board[row][column] == -1) {
        res.setter(row, column);
        break;
      }
    }
  }
  std::cout << "ai result: " << res.get_i() << " " << res.get_j() << std::endl;
  return res;
}

void printer(char board[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      std::cout << board[i][j];
      if (j < 2)
        std::cout << " | ";
      else
        std::cout << " ";
    }
    std::cout << std::endl;
    if (i < 2)
      std::cout << "----------" << std::endl;
  }
}

int winner_checker(int board[3][3]) {
  int res = -1;
  for (int i = 0; i < 3; i++) {
    if (board[0][i] != -1 || board[i][0] != -1) {
      res = -2;
      break;
    }
  }
  if (res == -1)
    return res;
  for (int i = 0; i < 3; i++) {
    if (board[i][0] != -1) {
      if (board[i][1] == board[i][0] && board[i][2] == board[i][0])
        return board[i][0];
      if (i == 0) {
        if (board[1][1] == board[i][0] && board[2][2] == board[i][0])
          return board[i][0];
      }
      if (i == 2) {
        if (board[1][1] == board[i][0] && board[0][0] == board[i][0])
          return board[i][0];
      }
    }
  }
  for (int i = 0; i < 3; i++) {
    if (board[0][i] != -1) {
      if (board[1][i] == board[0][i] && board[2][i] == board[0][i])
        return board[0][i];
    }
  }
  return res;
}

int main() {
  char board[3][3];
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      board[i][j] = ' ';

  int board_logic[3][3];
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      board_logic[i][j] = -1;
  int count = 0;
  int column = 0, row = 0;
  int res = -1;
  index ai_point;
  while (count < 9) {
    res = winner_checker(board_logic);
    if (res >= 0) {
      if (res == 0)
        std::cout << "X has won the game" << std::endl;
      if (res == 1)
        std::cout << "O has won the game" << std::endl;
      break;
    }
    if (count % 2 == 0) {
      try {
        std::cout << "insert row and column" << std::endl;
        std::cin.clear();
        std::cin >> row >> column;
        // std::cout << "column: " << column << " row: " << row << std::endl;
        // std::cout << "count: " << count << std::endl;
        if (row > 3 || row < 0) {
          throw std::invalid_argument("invalid row\n");
        }
        if (column > 3 || column < 0) {
          throw std::invalid_argument("invalid column\n");
        }
      } catch (...) {
        std::cout << "wrong input!" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        continue;
      }
      column--;
      row--;
    } else {
      ai_point = AI_gamer(board_logic, 1);
      row = ai_point.get_i();
      column = ai_point.get_j();
    }

    if (board_logic[row][column] == -1) {
      if (count % 2 == 0) {
        board[row][column] = 'x';
        board_logic[row][column] = 0;
      } else {
        board[ai_point.get_i()][ai_point.get_j()] = 'o';
        board_logic[ai_point.get_i()][ai_point.get_j()] = 1;
        printer(board);
      }
      count++;
    } else {
      std::cout << "this element has been taken!" << std::endl;
    }
  }
  if (count == 9 && res < 0)
    printer(board);
  // std::cout << "the game finished tie!" << std::endl;
  return 0;
}