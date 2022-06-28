#ifndef CLEAN_HPP
#define CLEAN_HPP

#include "types.hpp"
#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;

class Clean {
public:
  void set_path(std::string const &path = fs::current_path());
  void start() noexcept;

private:
  void get_files();
  void detect_type(std::vector<std::string> const &files);
  void create_dir();
  void move_files();

private:
  fs::path _path = fs::current_path();
  bool result_move = false;

  // files gonna save into these vectors
  std::vector<std::string> _videos;
  std::vector<std::string> _musics;
  std::vector<std::string> _documents;
  std::vector<std::string> _compresses;
  std::vector<std::string> _pictures;
};

#endif // CLEAN_HPP
