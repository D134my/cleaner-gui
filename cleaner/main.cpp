#include "clean.hpp"

int main(int argc, char **argv) {

  Clean clean;

  clean.set_path("/tmp/test/");
  clean.start();

  return 0;
}
