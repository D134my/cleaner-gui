#ifndef TYPES_H
#define TYPES_H
#include <string>
#include <vector>

struct types {
  // cry -_- I could not use auto here // we can't use it in not static way

  const std::vector<std::string> pic{".jpg", ".png", ".webp", ".gif", ".jpeg"};
  const std::vector<std::string> video{".mp4", ".mkv"};
  const std::vector<std::string> music{".mp3"};
  const std::vector<std::string> doc{".txt", ".pdf", ".docx"};
  const std::vector<std::string> compress{".zip", ".rar", ".7zip", ".tar"};
};

#endif // TYPES_H
