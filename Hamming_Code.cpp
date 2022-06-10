/**
 * @file Hamming_Code.cpp
 * @author Mohamad Syafiq Asyraf Bin Bharudin (https://github.com/binaryassasins)
 * @brief This program was designed to illustrate how the Hamming code is being implemented in detecting and correcting code
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

  int word[6], received[6], ed1, ed2, ed3;

  cout << "  This program was designed to illustrate how the Hamming code being implemented in data transmission" << endl;

  // 4 bits of word is our actual data
  /**
   *              D7      D6      D5      P4      D3      P2      P1
              |   1   |   1   |   0   |   0   |   1   |   1   |   0   |
   *  Layout:     7       6       5       4       3       2       1
      Array:     [0]     [1]     [2]     [3]     [4]     [5]     [6]
   */ 
  cout << "\n  Enter 4 bits of word (separated by spaces): ";
  cin >> word[0]; 
  cin >> word[1]; 
  cin >> word[2]; 
  cin >> word[4];

  /**
   * P1 -> D3 D5 D7
   * P2 -> D3 D6 D7
   * P4 -> D5 D6 D7
   */
  word[6] = word[4] ^ word[2] ^ word[0];
  word[5] = word[4] ^ word[1] ^ word[0];
  word[3] = word[2] ^ word[1] ^ word[0];

  cout << endl;

  cout << "  P = Parity bit position, D = Data bit position" << "\n" << endl;
  cout << "\tD7" << "\t" << "D6" << "\t" << "D5" << "\t" << "P4" << "\t" << "D3" << "\t" << "P2" << "\t" << "P1" << endl;  
  cout << "\t";
  for (int i = 0; i < 7; i++)
  {
    cout << word[i] << "   |   ";
  }

  cout << endl;
  cout << "\n  Parity bits: " << word[6] << " " << word[5] << " " << word[3] << endl;
  cout << "  Data bits: " << word[0] << " " << word[1] << " " << word[2] << " " << word[4] << endl;
  cout << endl;

  /**
   *              D7      D6      D5      P4      D3      P2      P1
              |   1   |   1   |   1   |   0   |   1   |   1   |   0   |
   *  Layout:     7       6       5       4       3       2       1
      Array:     [0]     [1]     [2]     [3]     [4]     [5]     [6]
   */ 
  // Assume that the data bits has been distorted (an error has been encountered)
  cout << "  Enter 7 bits (separated by spaces): ";
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
  ed1 = received[6] ^ received[4] ^ received[2] ^ received[0];
  ed2 = received[5] ^ received[4] ^ received[1] ^ received[0];
  ed3 = received[3] ^ received[2] ^ received[1] ^ received[0];

  // Determine the position of the error (tot elements - position in the layout)
  int pos = 7 - (ed1 * 1 + ed2 * 2 + ed3 * 4);

  if (pos == 7)
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

Copyright (c) 2022 FiqAtGit

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
