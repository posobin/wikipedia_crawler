#ifndef CRAWLER_H
#define CRAWLER_H

#include <unordered_set>
#include <string>
#include <queue>

class Crawler
{
  std::unordered_set<std::string> visited_links_;
  std::queue<std::string> download_queue_;
  std::string data_directory_;
  std::string root_path_;
  std::string download_queue_file_;
  const std::string link_prefix_ = "<a href=\"";
  std::string required_link_prefix_;

  std::string GenerateFileName();
  bool FetchNextPage();
  void GetLinks(const std::string& filename);

 public:
  Crawler(const std::string& data_directory,
      const std::string& root_path,
      const std::string& required_link_prefix);

  void Crawl(const std::string& start_page);
};

#endif