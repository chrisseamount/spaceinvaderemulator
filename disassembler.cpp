#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int disassemble(const std::string, const int, std::ofstream&);

int main()
{
  //buffer to store data from binary file
  std::string buffer;
  unsigned char c;

  //opens/creates disassemble file
  std::ofstream outFile;
  outFile.open("disassemble.txt");
  if(!outFile)
  {
    std::cout << "Unable to open output file" << std::endl;
    return 0;
  }

  //read file
  std::ifstream readFile;
  readFile.open("invaders/invaders.h");
  if(!readFile)
  {
    std::cout << "Unable to open input file" << std::endl;
    return 0;
  }
  while(readFile >> c) //writes text from file into char c and then from char c to buffer
  {
    buffer += c;
  }
  readFile.close();

  int ptr = 0;
  while(ptr < buffer.size())
  {
    ptr += disassemble(buffer, ptr, outFile);
  }

  outFile.close();

  return 0;
}

int disassemble(const std::string buffer, const int ptr, std::ofstream& outFile)
{
  unsigned char c = buffer[ptr];

  int funcSize = 1;

  switch(c)
  {
    case 0x00: outFile << "NOP"; break;
    case 0x01: outFile << "LXI  B, $" << std::hex << std::setfill('0') << std::setw(2) << (0xff & buffer[ptr+2]) << std::setfill('0') << std::setw(2) << (0xff & buffer[ptr+1]); funcSize = 3; break;
    case 0x02: outFile << "STAX  B"; break;
    case 0x03: outFile << "INX  B"; break;
    case 0x04: outFile << "INR  B"; break;
    case 0x05: outFile << "DCR  B"; break;
    case 0x06: outFile << "MVI  B, $" << std::hex << std::setfill('0') << std::setw(2) << (0xFF & buffer[ptr+1]); funcSize = 2; break;
    case 0x07: outFile << "RLC"; break;
    case 0x08: outFile << "NOP"; break;
    case 0x09: outFile << "DAD  B"; break;
    case 0x0A: outFile << "LDAX  B"; break;
    case 0x0B: outFile << "DCX  B"; break;
    case 0x0C: outFile << "INR  C"; break;
    case 0x0D: outFile << "DCR  C"; break;
    case 0x0E: outFile << "MVI  C, $" << std::hex << std::setfill('0') << std::setw(2) << (0xFF & buffer[ptr+1]); funcSize = 2; break;
    case 0x0F: outFile << "RRC"; break;

    case 0x10: outFile << ""; break;
    case 0x11: outFile << ""; break;
    case 0x12: outFile << ""; break;
    case 0x13: outFile << ""; break;
    case 0x14: outFile << ""; break;
    case 0x15: outFile << ""; break;
    case 0x16: outFile << ""; break;
    case 0x17: outFile << ""; break;
    case 0x18: outFile << ""; break;
    case 0x19: outFile << ""; break;
    case 0x1A: outFile << ""; break;
    case 0x1B: outFile << ""; break;
    case 0x1C: outFile << ""; break;
    case 0x1D: outFile << ""; break;
    case 0x1E: outFile << ""; break;
    case 0x1F: outFile << ""; break;

    case 0x20: outFile << ""; break;
    case 0x21: outFile << ""; break;
    case 0x22: outFile << ""; break;
    case 0x23: outFile << ""; break;
    case 0x24: outFile << ""; break;
    case 0x25: outFile << ""; break;
    case 0x26: outFile << ""; break;
    case 0x27: outFile << ""; break;
    case 0x28: outFile << ""; break;
    case 0x29: outFile << ""; break;
    case 0x2A: outFile << ""; break;
    case 0x2B: outFile << ""; break;
    case 0x2C: outFile << ""; break;
    case 0x2D: outFile << ""; break;
    case 0x2E: outFile << ""; break;
    case 0x2F: outFile << ""; break;

    case 0x30: outFile << ""; break;
    case 0x31: outFile << ""; break;
    case 0x32: outFile << ""; break;
    case 0x33: outFile << ""; break;
    case 0x34: outFile << ""; break;
    case 0x35: outFile << ""; break;
    case 0x36: outFile << ""; break;
    case 0x37: outFile << ""; break;
    case 0x38: outFile << ""; break;
    case 0x39: outFile << ""; break;
    case 0x3A: outFile << ""; break;
    case 0x3B: outFile << ""; break;
    case 0x3C: outFile << ""; break;
    case 0x3D: outFile << ""; break;
    case 0x3E: outFile << ""; break;
    case 0x3F: outFile << ""; break;

    case 0x40: outFile << ""; break;
    case 0x41: outFile << ""; break;
    case 0x42: outFile << ""; break;
    case 0x43: outFile << ""; break;
    case 0x44: outFile << ""; break;
    case 0x45: outFile << ""; break;
    case 0x46: outFile << ""; break;
    case 0x47: outFile << ""; break;
    case 0x48: outFile << ""; break;
    case 0x49: outFile << ""; break;
    case 0x4A: outFile << ""; break;
    case 0x4B: outFile << ""; break;
    case 0x4C: outFile << ""; break;
    case 0x4D: outFile << ""; break;
    case 0x4E: outFile << ""; break;
    case 0x4F: outFile << ""; break;

    case 0x50: outFile << ""; break;
    case 0x51: outFile << ""; break;
    case 0x52: outFile << ""; break;
    case 0x53: outFile << ""; break;
    case 0x54: outFile << ""; break;
    case 0x55: outFile << ""; break;
    case 0x56: outFile << ""; break;
    case 0x57: outFile << ""; break;
    case 0x58: outFile << ""; break;
    case 0x59: outFile << ""; break;
    case 0x5A: outFile << ""; break;
    case 0x5B: outFile << ""; break;
    case 0x5C: outFile << ""; break;
    case 0x5D: outFile << ""; break;
    case 0x5E: outFile << ""; break;
    case 0x5F: outFile << ""; break;

    case 0x60: outFile << ""; break;
    case 0x61: outFile << ""; break;
    case 0x62: outFile << ""; break;
    case 0x63: outFile << ""; break;
    case 0x64: outFile << ""; break;
    case 0x65: outFile << ""; break;
    case 0x66: outFile << ""; break;
    case 0x67: outFile << ""; break;
    case 0x68: outFile << ""; break;
    case 0x69: outFile << ""; break;
    case 0x6A: outFile << ""; break;
    case 0x6B: outFile << ""; break;
    case 0x6C: outFile << ""; break;
    case 0x6D: outFile << ""; break;
    case 0x6E: outFile << ""; break;
    case 0x6F: outFile << ""; break;

    case 0x70: outFile << ""; break;
    case 0x71: outFile << ""; break;
    case 0x72: outFile << ""; break;
    case 0x73: outFile << ""; break;
    case 0x74: outFile << ""; break;
    case 0x75: outFile << ""; break;
    case 0x76: outFile << ""; break;
    case 0x77: outFile << ""; break;
    case 0x78: outFile << ""; break;
    case 0x79: outFile << ""; break;
    case 0x7A: outFile << ""; break;
    case 0x7B: outFile << ""; break;
    case 0x7C: outFile << ""; break;
    case 0x7D: outFile << ""; break;
    case 0x7E: outFile << ""; break;
    case 0x7F: outFile << ""; break;

    case 0x80: outFile << ""; break;
    case 0x81: outFile << ""; break;
    case 0x82: outFile << ""; break;
    case 0x83: outFile << ""; break;
    case 0x84: outFile << ""; break;
    case 0x85: outFile << ""; break;
    case 0x86: outFile << ""; break;
    case 0x87: outFile << ""; break;
    case 0x88: outFile << ""; break;
    case 0x89: outFile << ""; break;
    case 0x8A: outFile << ""; break;
    case 0x8B: outFile << ""; break;
    case 0x8C: outFile << ""; break;
    case 0x8D: outFile << ""; break;
    case 0x8E: outFile << ""; break;
    case 0x8F: outFile << ""; break;

    case 0x90: outFile << ""; break;
    case 0x91: outFile << ""; break;
    case 0x92: outFile << ""; break;
    case 0x93: outFile << ""; break;
    case 0x94: outFile << ""; break;
    case 0x95: outFile << ""; break;
    case 0x96: outFile << ""; break;
    case 0x97: outFile << ""; break;
    case 0x98: outFile << ""; break;
    case 0x99: outFile << ""; break;
    case 0x9A: outFile << ""; break;
    case 0x9B: outFile << ""; break;
    case 0x9C: outFile << ""; break;
    case 0x9D: outFile << ""; break;
    case 0x9E: outFile << ""; break;
    case 0x9F: outFile << ""; break;

    case 0xA0: outFile << ""; break;
    case 0xA1: outFile << ""; break;
    case 0xA2: outFile << ""; break;
    case 0xA3: outFile << ""; break;
    case 0xA4: outFile << ""; break;
    case 0xA5: outFile << ""; break;
    case 0xA6: outFile << ""; break;
    case 0xA7: outFile << ""; break;
    case 0xA8: outFile << ""; break;
    case 0xA9: outFile << ""; break;
    case 0xAA: outFile << ""; break;
    case 0xAB: outFile << ""; break;
    case 0xAC: outFile << ""; break;
    case 0xAD: outFile << ""; break;
    case 0xAE: outFile << ""; break;
    case 0xAF: outFile << ""; break;

    case 0xB0: outFile << ""; break;
    case 0xB1: outFile << ""; break;
    case 0xB2: outFile << ""; break;
    case 0xB3: outFile << ""; break;
    case 0xB4: outFile << ""; break;
    case 0xB5: outFile << ""; break;
    case 0xB6: outFile << ""; break;
    case 0xB7: outFile << ""; break;
    case 0xB8: outFile << ""; break;
    case 0xB9: outFile << ""; break;
    case 0xBA: outFile << ""; break;
    case 0xBB: outFile << ""; break;
    case 0xBC: outFile << ""; break;
    case 0xBD: outFile << ""; break;
    case 0xBE: outFile << ""; break;
    case 0xBF: outFile << ""; break;

    case 0xC0: outFile << ""; break;
    case 0xC1: outFile << ""; break;
    case 0xC2: outFile << ""; break;
    case 0xC3: outFile << ""; break;
    case 0xC4: outFile << ""; break;
    case 0xC5: outFile << ""; break;
    case 0xC6: outFile << ""; break;
    case 0xC7: outFile << ""; break;
    case 0xC8: outFile << ""; break;
    case 0xC9: outFile << ""; break;
    case 0xCA: outFile << ""; break;
    case 0xCB: outFile << ""; break;
    case 0xCC: outFile << ""; break;
    case 0xCD: outFile << ""; break;
    case 0xCE: outFile << ""; break;
    case 0xCF: outFile << ""; break;

    case 0xD0: outFile << ""; break;
    case 0xD1: outFile << ""; break;
    case 0xD2: outFile << ""; break;
    case 0xD3: outFile << ""; break;
    case 0xD4: outFile << ""; break;
    case 0xD5: outFile << ""; break;
    case 0xD6: outFile << ""; break;
    case 0xD7: outFile << ""; break;
    case 0xD8: outFile << ""; break;
    case 0xD9: outFile << ""; break;
    case 0xDA: outFile << ""; break;
    case 0xDB: outFile << ""; break;
    case 0xDC: outFile << ""; break;
    case 0xDD: outFile << ""; break;
    case 0xDE: outFile << ""; break;
    case 0xDF: outFile << ""; break;

    case 0xE0: outFile << ""; break;
    case 0xE1: outFile << ""; break;
    case 0xE2: outFile << ""; break;
    case 0xE3: outFile << ""; break;
    case 0xE4: outFile << ""; break;
    case 0xE5: outFile << ""; break;
    case 0xE6: outFile << ""; break;
    case 0xE7: outFile << ""; break;
    case 0xE8: outFile << ""; break;
    case 0xE9: outFile << ""; break;
    case 0xEA: outFile << ""; break;
    case 0xEB: outFile << ""; break;
    case 0xEC: outFile << ""; break;
    case 0xED: outFile << ""; break;
    case 0xEE: outFile << ""; break;
    case 0xEF: outFile << ""; break;

    case 0xF0: outFile << ""; break;
    case 0xF1: outFile << ""; break;
    case 0xF2: outFile << ""; break;
    case 0xF3: outFile << ""; break;
    case 0xF4: outFile << ""; break;
    case 0xF5: outFile << ""; break;
    case 0xF6: outFile << ""; break;
    case 0xF7: outFile << ""; break;
    case 0xF8: outFile << ""; break;
    case 0xF9: outFile << ""; break;
    case 0xFA: outFile << ""; break;
    case 0xFB: outFile << ""; break;
    case 0xFC: outFile << ""; break;
    case 0xFD: outFile << ""; break;
    case 0xFE: outFile << ""; break;
    case 0xFF: outFile << ""; break;
  }

  outFile << std::endl;

  return funcSize;
}
