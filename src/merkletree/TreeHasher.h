#ifndef TREEHASHER_H
#define TREEHASHER_H
#include <string>

#include "SerialHasher.h"

class TreeHasher {
 public:
  // Takes ownership of the SerialHasher.
  TreeHasher(SerialHasher *hasher);
  ~TreeHasher();

  size_t DigestSize() const { return hasher_->DigestSize(); }

  std::string HashEmpty();

  std::string HashLeaf(const std::string &data);

  // Accepts arbitrary strings as children. When hashing
  // digests, it is the responsibility of the caller to
  // ensure the inputs are of correct size.
  std::string HashChildren(const std::string &left_child,
                           const std::string &right_child);

 private:
  SerialHasher *hasher_;
};
#endif