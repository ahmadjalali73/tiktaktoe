#include <stdint.h>

class Piece {
private:
  uint8_t y;
  char x;
  uint8_t color;
  char type;

public:
  Piece();
  void xSetter(char x);
  void ySetter(uint8_t y);
  void colorSetter(uint8_t color);
  void typeSetter(char type);
  uint8_t yGetter();
  uint8_t colorGetter();
  char xGetter();
  char tyepGetter();
  void move();
};

class Soldjer : Piece {
public:
  Soldjer(char x, uint8_t color);
  Soldjer(char x, uint8_t y, uint8_t color);
  void move();
};

class Horse : Piece {
public:
  Horse(char x, uint8_t y, uint8_t color);
  void move();
};

class Elephant : Piece {
public:
  Elephant(char x, uint8_t y, uint8_t color);
  void move();
};

class Rokh : Piece {
public:
  Rokh(char x, uint8_t y, uint8_t color);
  void move();
};

class Minister : Piece {
public:
  Minister(char x, uint8_t y, uint8_t color);
  void move();
};

class King : Piece {
public:
  King(char x, uint8_t y, uint8_t color);
  void move();
};
