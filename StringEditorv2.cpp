/*
The question is "realize a string editor, in which we can have insert, erase, undo and redo functions. You can use c++ STL."

This is my MathWorks technical phone interview question. I am required to realize it around 2 hrs.
I shared my screen with the manager, and discussed my thoughts with him on phone, and revised and compiled my code on my local computer.
The manager was nice and also provided several suggestions to improve the code after the technical interview.
v1 is what I finished during the interview.
v2 is what I improved the code after the interview, and send it back to the manager for further suggestion in the
 evening of the same day of my interview.
v3 is what I revised the code again after the manager sent me his suggestions via email.
*/

#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

class Editor {
private:
  string old_str;
  // list to store operation history
  list<vector<string>> lst; // the three elements in vector<string>
 			    // 1. commands: "insert" or "erase"
                            // 2. string of position
                            // 3. substr
public:
  static int node_idx; // lst node position active for undo and redo
  static int redo_steps; // max redo times

  // constructor for updating input string
  Editor(string str1) {
    old_str = str1;
  }

  void insert(int pos, string sub_str) {
    // pop the no longer needed list nodes
    // when new operation occurs.
    if (redo_steps != 0) {
      int lstLen = lst.size();
      for (int i = lstLen - redo_steps + 1; i <= lstLen; i++)
        lst.pop_back();
    }

    old_str.insert(pos, sub_str); 
    lst.push_back({"insert", to_string(pos), sub_str});
    ++node_idx;
    redo_steps = 0;
  }

  void erase(int pos, int length) {
    // pop the no longer needed list nodes
    // when new operation occurs.
    if (redo_steps != 0) {
      int lstLen = lst.size();
      for (int i = lstLen - redo_steps + 1; i <= lstLen; i++)
        lst.pop_back();
    }

    string tmp_era = old_str.substr(pos, length);
    old_str.erase(pos, length);
    lst.push_back({"erase", to_string(pos), tmp_era});
    ++node_idx;
    redo_steps = 0;
  }

  void printstr() {
    cout << old_str << '\n';
  }

  void undo() {
    if (!lst.empty()) {
      // locate node elements from back of the list
      // via iterator
      auto it = lst.end();
      for (int i = node_idx; i <= lst.size(); i++)
	--it;

      vector<string> tmp_list = *it;
      tmp_list[0] == "erase" ? old_str.insert(stoi(tmp_list[1]), tmp_list[2]) : old_str.erase(stoi(tmp_list[1]), tmp_list[2].size()); 
      --node_idx;
      ++redo_steps;
    }
    
  }

  void redo() {
    if (redo_steps != 0) {
      // locate node elements from back of the list
      // via iterator
      auto it = lst.end();
      for (int i = node_idx + 1; i <= lst.size(); i++)
        --it;

      vector<string> tmp_list = *it;
      tmp_list[0] == "insert" ? old_str.insert(stoi(tmp_list[1]), tmp_list[2]) : old_str.erase(stoi(tmp_list[1]), tmp_list[2].size());
      ++node_idx;
      --redo_steps;
    } else {
      cout << "All previous undos have been recovered!!!\n";
      exit(1);
    }
  } 
};

// Initialize static variables in Editor class
int Editor::node_idx = 0;
int Editor::redo_steps = 0;

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
