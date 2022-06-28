#include "clean.hpp"
#include <algorithm>
#include <ranges>
#include <regex>

void Clean::set_path(std::string const &path) {

  if (_path != path) {
    if (!path.starts_with("/")) {
      std::cout << "path must start with / \n";
      exit(-1);
    }

    _path = path;
  }

  std::cout << "path is " << _path << std::endl;
}

void Clean::start() noexcept { get_files(); }

void Clean::get_files() {
  fs::current_path(_path);

  std::vector<std::string> all_files;
  for (auto const &dir_entry : fs::recursive_directory_iterator(_path)) {
    if (!dir_entry.is_directory())

      all_files.push_back(dir_entry.path());
  }

  detect_type(all_files);
}

void Clean::detect_type(const std::vector<std::string> &files) {

  std::regex find_extension_re{"(\\.[^.]+)$"};
  std::smatch extension_smatch;

  for (auto const &file : files) {
    std::string file_result = file;

    // remove directory path from files
    if (auto pos = file_result.find(_path.string()); pos != std::string::npos) {
      file_result.erase(pos, _path.string().size());
    }

    std::cout << "files " << file_result << std::endl;

    if (std::regex_search(file, extension_smatch, find_extension_re)) {

      // find the type
      types _type;

      for (auto const &music : _type.music) {
        if (music == extension_smatch.str())
          _musics.push_back(file_result);
      }

      for (auto const &vid : _type.video) {
        if (vid == extension_smatch.str())
          _videos.push_back(file_result);
      }

      for (auto const &pic : _type.pic) {
        if (pic == extension_smatch.str())
          _pictures.push_back(file_result);
      }
      for (auto const &doc : _type.doc) {
        if (doc == extension_smatch.str())
          _documents.push_back(file_result);
      }

      for (auto const &comp : _type.compress) {
        if (comp == extension_smatch.str())
          _compresses.push_back(file_result);
      }
    }
  }
  create_dir();
}

void Clean::create_dir() {
  try {
    if (!_videos.empty()) {
      fs::create_directory(_path.string() + "Videos_");
      result_move = true;
    }
    if (!_musics.empty()) {
      fs::create_directory(_path.string() + "Music_");
      result_move = true;
    }

    if (!_documents.empty()) {
      fs::create_directory(_path.string() + "Documents_");
      result_move = true;
    }
    if (!_compresses.empty()) {
      fs::create_directory(_path.string() + "Compresses_");
      result_move = true;
    }

    if (!_pictures.empty()) {
      fs::create_directory(_path.string() + "Pictures_");
      result_move = true;
    }

    if (result_move)
      move_files();
  } catch (std::exception &error) {
    std::cerr << "Error happend " << error.what() << std::endl;
  }
}

void Clean::move_files() {

  if (!_videos.empty())
    for (auto const &vid : _videos) {
      std::system(
          std::string("mv " + vid + ' ' + _path.string() + "/Videos_").c_str());
    }

  if (!_musics.empty())
    for (auto const &music : _musics) {
      std::system(std::string("mv " + music + ' ' + _path.string() + "/Music_")
                      .c_str());
    }

  if (!_documents.empty())
    for (auto const &doc : _documents) {
      std::system(
          std::string("mv " + doc + ' ' + _path.string() + "/Documents_")
              .c_str());
    }

  if (!_compresses.empty())
    for (auto const &comp : _compresses) {
      std::system(
          std::string("mv " + comp + ' ' + _path.string() + "/Compresses_")
              .c_str());
    }

  if (!_pictures.empty())
    for (auto const &pic : _pictures) {
      std::system(std::string("mv " + pic + ' ' + _path.string() + "/Pictures_")
                      .c_str());
    }
}
