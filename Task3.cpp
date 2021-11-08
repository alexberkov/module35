#include <iostream>
#include <filesystem>
#include <vector>

using namespace std;

int main() {
  string cpp = ".cpp", txt = ".txt";
  filesystem::path p = "/Users/alexberkov/CLionProjects/Task35-3";

  auto recursiveGetFileNamesByExtension = [](const filesystem::path& path, const string& extension) {
    vector<string> names;
    for(auto& p: filesystem::recursive_directory_iterator(path))
      if (p.path().extension().compare(extension) == 0) names.push_back(p.path().filename());
    return names;
  };

  auto executables = recursiveGetFileNamesByExtension(p, cpp);
  auto textFiles = recursiveGetFileNamesByExtension(p, txt);
  cout << "Directory: " << p << endl << "Executable files (.cpp):" << endl;
  for (auto &i: executables) cout << "\t" << i << endl;
  cout << "Text files (.txt):" << endl;
  for (auto &i: textFiles) cout << "\t" << i << endl;
  return 0;
}
