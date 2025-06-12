#ifndef HRAM_H
#define HRAM_H

#include <stdint.h>
#include <string>


class HRAM {
public:
  HRAM() {}
  ~HRAM() {}
  uint8_t read8(uint16_t offset);
  void write8(uint16_t offset, uint8_t data);
  uint16_t read16(uint16_t offset);
  void write16(uint16_t offset, uint16_t data);

private:
  uint8_t hram[0x7F] = {0x00}; // 127 bytes
};

#endif
