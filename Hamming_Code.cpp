/**
 * @file Hamming_Code.cpp
 * @author Mohamad Syafiq Asyraf Bin Bharudin (https://github.com/binaryassasins)
 * @brief This program was designed to illustrate how the Hamming code being implemented in data transmission
 * @version 0.1
 * @date 2022-06-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
  
  /**
   * ed = error detection
   * P = parity bit
   * D = data bit
   * ^ = bitwise XOR operator
   * word = hamming code
   * received = received code with error detection capability
   * 
   * Bitwise XOR operator (^) will return 1 only if one of the operand equals to 1 (0 ^ 1, returns 1)
   * Bitwise XOR operator (^) will return 0 if both operands has the same value (1 ^ 1 or 0 ^ 0, returns 0)
   */

  int word[10], received[10], ed1, ed2, ed3;

  cout << "  This program was designed to illustrate how the Hamming code being implemented in data transmission" << endl;

  // 4 bits of word is our actual data
  cout << "\n  Enter 4 bits of word: ";
  cin >> word[2]; 
  cin >> word[4]; 
  cin >> word[5]; 
  cin >> word[6];

  word[0] = word[2] ^ word[4] ^ word[6];
  word[1] = word[2] ^ word[5] ^ word[6];
  word[3] = word[4] ^ word[5] ^ word[6];

  cout << endl;

  cout << "  P = Parity bit position, D = Data bit position" << "\n" << endl;
  cout << "\tP1" << "\t" << "P2" << "\t" << "D3" << "\t" << "P4" << "\t" << "D5" << "\t" << "D6" << "\t" << "D7" << endl;  
  cout << "\t";
  for (int i = 0; i < 7; i++)
  {
    cout << word[i] << "   |   ";
  }

  cout << endl;
  cout << "\n  Parity bits: " << word[0] << " " << word[1] << " " << word[3] << endl;
  cout << "  Data bits: " << word[2] << " " << word[4] << " " << word[5] << " " << word[6] << endl;
  cout << endl;

  // Assume that the data bits has been distorted (an error has been encountered)
  cout << "  Enter 7 bits: ";
  for (int i = 0; i < 7; i++)
  {
    cin >> received[i];
  }
  cout << endl;

  /**
   * For each parities, it should obtain even parity bits
   * 
   * If it's an odd, throw 1
   * If it's an even, throw 0
   */
  ed1 = received[0] ^ received[2] ^ received[4] ^ received[6];
  ed2 = received[1] ^ received[2] ^ received[5] ^ received[6];
  ed3 = received[3] ^ received[4] ^ received[5] ^ received[6];

  // Convert into decimal notation -> -1 since the first element is counted as 0
  int pos = (ed1 * 1 + ed2 * 2 + ed3 * 4) - 1;

  if (pos == -1)
  {
    cout << "  There is no error" << endl;
  }
  else
  {
    cout << "  There is an error occured in the word at position " << pos + 1 << "\n" << endl;
    
    cout << "\tP1" << "\t" << "P2" << "\t" << "D3" << "\t" << "P4" << "\t" << "D5" << "\t" << "D6" << "\t" << "D7" << endl;  
    
    cout << "\t";
    for (int i = 0; i < 7; i++)
    {
      cout << received[i] << "   |   ";
    }

    cout << endl;
    for (int i = 0; i < 7; i++)
    {
      cout << "\t";
      if (i == pos)
      {
        cout << "^";
        break;
      }
    }

    // Correcting the code
    cout << endl;
    if (received[pos] == 0)
    {
      received[pos] = 1;
    }
    
    else
    {
      received[pos] = 0;
    }

    cout << "\n  The word after error has been corrected: " << "\n" << endl;
    cout << "\tP1" << "\t" << "P2" << "\t" << "D3" << "\t" << "P4" << "\t" << "D5" << "\t" << "D6" << "\t" << "D7" << endl;  
    cout << "\t";
    for (int i = 0; i < 7; i++)
    {
      cout << received[i] << "   |   ";
    }
  }

  cout << "\n" << endl;
  
  system("pause");
  return 0;
}
/**
MIT License

Copyright (c) [2022] [binaryassasins]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/