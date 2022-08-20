#include <stdint.h>

// enum columns{
//     A='a',
//     B=,

// };

class Element {
private:
  bool status;
  uint8_t y;
  char x;

public:
  Element(char x, uint8_t y);
  void xSetter(char x);
  void ySetter(uint8_t y);
  void statusSetter(bool full);
  char xGetter();
  uint8_t yGetter();
  uint8_t is_full();
};

class Board {
private:
  Element elements[8][8];

public:
  Board();
};

class Player {};