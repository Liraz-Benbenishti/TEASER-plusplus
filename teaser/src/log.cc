#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include <iostream>
#include "teaser/log.h"

inline bool isFileExists(const std::string& name) {
  struct stat buffer;   
  return (stat (name.c_str(), &buffer) == 0); 
}

inline void createFile(const std::string& name) {
  std::ofstream outfile (name);
  outfile.close();
}

void writeLog(const std::string& log) {
  const std::string& fileName = "program.log";
  if (!isFileExists(fileName)) {
   createFile(fileName); 
  }

  std::ofstream ofile;
  ofile.open(fileName, std::ios::app);
  ofile << log << std::endl;
}