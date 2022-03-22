#include <iostream>
#include <string>
#include <stack>

void display(std::stack<char> z);

int main() {

    char test[] = "(i+i)*i";
    int iterator = 0;
    int table[16][12] = {{55, 0, 0, 0, 0, 54, 0, 0, 1, 2, 3},
                         {0, 56, 57, 0, 0, 0, 0, 100, 0, 0, 0},
                         {0, 63, 63, 58, 59, 0, 63, 63, 0, 0, 0},
                         {0, 66, 66, 66, 66, 0, 66, 66, 10, 2, 3},
                         {55, 0, 0, 0, 0, 54, 0, 0, 10, 2, 3},
                         {0, 68, 68, 68, 68, 0, 68, 68, 0, 0, 0},
                         {55, 0, 0, 0, 0, 54, 0, 0, 0, 11, 3},
                         {55, 0, 0, 0, 0, 54, 0, 0, 0, 12, 3},
                         {55, 0, 0, 0, 0, 54, 0, 0, 0, 0, 13},
                         {55, 0, 0, 0, 0, 54, 0, 0, 0, 0, 14},
                         {0, 56, 57, 0, 0, 0, 515, 0, 0, 0, 0},
                         {0, 61, 61, 58, 59, 0, 61, 61, 0, 0, 0},
                         {0, 62, 62, 58, 59, 0, 62, 62, 0, 0, 0},
                         {0, 64, 64, 64, 64, 0, 64, 64, 0, 0, 0},
                         {0, 65, 65, 65, 65, 0, 65, 65, 0, 0, 0},
                         {0, 67, 67, 67, 67, 0, 67, 67, 0, 0, 0}};

    char character = test[iterator];
    int point;
    bool works = 1;
    int x, y = 0;

    //starting the stack
    std::stack<char> s;

    while (works == 1) {

      switch (character) {
        case 'i':
          y = 0;
          break;
        case '+':
          y = 1;
          break;
        case '-':
          y = 2;
          break;
        case '*':
          y = 3;
          break;
        case '/':
          y = 4;
          break;
        case '(':
          y = 5;
          break;
        case ')':
          y = 6;
          break;
        case '$':
          y = 7;
          break;
        case 'E':
          y = 8;
          break;
        case 'F':
          y = 9;
          break;
        case 'T':
          y = 10;
          break;
      }

      point = table[x][y];
      std::cout << point << '\n';

      //temporarily makes this only loop once
      works = 0;

      switch (point) {
        case 54:
          s.push(x);
          s.push(y);
          x = 4;
          character = test[++iterator];
          break;
        case 55:
          s.push(x);
          s.push(y);
          x = 5;
          character = test[++iterator];
          break;
        case 56:
          s.push(x);
          s.push(y);
          x = 6;
          character = test[++iterator];
          break;
        case 57:
          s.push(x);
          s.push(y);
          x = 7;
          character = test[++iterator];
          break;
        case 58:
          s.push(x);
          s.push(y);
          x = 8;
          character = test[++iterator];
          break;
        case 59:
          s.push(x);
          s.push(y);
          x = 9;
          character = test[++iterator];
          break;
        case 515:
          s.push(x);
          s.push(y);
          x = 15;
          character = test[++iterator];
          break;
      }

    }

  return 0;
}



void display(std::stack<char> z) {
  int x, j = z.size();
  char holder[x] = {'0'};
  for (int i = 0; i < x; i++) {
    holder[j - 1] = z.top();
    j--;
    if (z.top() != '$') {
      z.pop();
    }
  }
  std::cout << holder << '\n';
}
