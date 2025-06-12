#include <sstream>
#include <stdexcept>
#include <iostream>
#include "core/cpu/cpu.h"

// Wrapper functions
void CPU::R8_Wrapper(void (CPU::*ins)()) {
  operand = *pfx_register_ptr;
  (this->*ins)();
  *pfx_register_ptr = operand;
}

void CPU::HL_Wrapper(void (CPU::*ins)()) {
  operand = read8(HL.full);
  (this->*ins)();
  write8(HL.full, operand);
}

void CPU::A_Wrapper(void (CPU::*ins)()) {
  operand = AF.hi;
  (this->*ins)();
  AF.hi = operand;
}

// Print
void CPU::print_regs() {
  std::cout << "AF: 0x" << std::hex << AF.full << " | "
            << "BC: 0x" << std::hex << BC.full << " | "
            << "DE: 0x" << std::hex << DE.full << " | "
            << "HL: 0x" << std::hex << HL.full << " | "
            << "SP: 0x" << std::hex << SP << " | "
            << "PC: 0x" << std::hex << PC
            << std::endl;
}
