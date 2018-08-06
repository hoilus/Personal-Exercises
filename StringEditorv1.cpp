/*
The question is "realize a string editor, in which we can have insert, erase, undo and redo functions. You can use c++ STL."

This is my MathWorks technical phone interview question. I am required to realize it around 2 hrs. 
I shared my screen with the manager, and discussed my thoughts with him on phone, and revised and compiled my code on my local computer.
The manager was nice and also provided several suggestions to improve the code after the technical interview.
v1 is what I finished during the interview.
v2 is what I improved the code after the interview, and send it back to the manager for further suggestion in the evening of the same day of my interview.
v3 is what I revised the code again after the manager sent me his suggestions via email.
*/

#include <iostream>
#include <stack>
#include <utility> // pair
#include <string>

using namespace std;

class Editor {
private:
  string old_str;
  stack<pair<size_t, string>> stk;
  stack<pair<size_t, string>> stk_redo;
  stack<int> commands; // insert = 0, erase = 1;
  stack<int> commands_redo;
public:
  // constructor for updating input string
  Editor(string str1) {
    old_str = str1;
  }

  void insert(size_t pos, string sub_str) {
    old_str.insert(pos, sub_str); 
    stk.push({pos, sub_str});
    commands.push(0);

    while(!stk_redo.empty() || !commands_redo.empty()) 
      stk_redo.pop(), commands_redo.pop();
  }

  void erase(size_t pos, int length) {
    string tmp_era = old_str.substr(pos, length);
    old_str.erase(pos, length);
    stk.push({pos, tmp_era});
    commands.push(1);

    while(!stk_redo.empty() || !commands_redo.empty()) 
      stk_redo.pop(), commands_redo.pop();
  }

  void printstr() {
    cout << old_str << '\n';
  }

  void undo() {
    if (!stk.empty()) {
      pair<size_t, string> tmp_pair = stk.top();
      commands.top() ? old_str.insert(tmp_pair.first, tmp_pair.second) : old_str.erase(tmp_pair.first, tmp_pair.second.size());

      // push redo_stack
      stk_redo.push(tmp_pair);
      commands_redo.push(commands.top());

      stk.pop();
      commands.pop();
    }
    
  }

  void redo() {
    if (!stk_redo.empty()) {
      pair<size_t, string> tmp_redo = stk_redo.top();
      commands_redo.top() ? old_str.erase(tmp_redo.first, tmp_redo.second.size()): old_str.insert(tmp_redo.first, tmp_redo.second);

      // push redo_stack
      stk.push(tmp_redo);
      commands.push(commands_redo.top());

      commands_redo.pop();
      stk_redo.pop();
    } else {
      cout << "All previous undos have been recovered!!!\n";
      exit(1);
    }
  }
};

int main() {
  Editor edt("first string");
  edt.insert(5, "XXX");
  edt.printstr();
  edt.erase(5, 2);
  edt.printstr();
  edt.erase(4, 1);
  edt.printstr();
  edt.undo();
  edt.printstr();
  edt.undo();
  edt.printstr();
  edt.undo();
  edt.printstr();
  edt.redo();
  edt.printstr();
  edt.undo();
  edt.printstr();
  edt.redo();
  edt.printstr();
  edt.insert(1, "NEWHERE");
  edt.printstr();
  edt.undo();
  edt.printstr();
  edt.redo();
  edt.printstr();
  edt.redo();
  edt.printstr();

  return 0;
}
