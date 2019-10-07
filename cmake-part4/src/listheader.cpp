#include <string>
#include "io.hpp"

int main(int argc, char *argv[])
{
  std::string file_name;
  file_name = argv[1];
  listhead(file_name);
}
