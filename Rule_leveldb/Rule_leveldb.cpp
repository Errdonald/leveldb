// Rule_leveldb.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "leveldb/db.h"

int main() {
  // Create a LevelDB database
  leveldb::DB* db;
  leveldb::Options options;
  options.create_if_missing = true;  // Create the database if it does not exist

  // Open the database
  leveldb::Status status = leveldb::DB::Open(options, "my_database", &db);
  if (!status.ok()) {
    std::cerr << "Unable to open/create database: " << status.ToString()
              << std::endl;
    return -1;
  }

  // Insert a key-value pair
  std::string key = "name";
  std::string value = "Alice";
  status = db->Put(leveldb::WriteOptions(), key, value);
  if (!status.ok()) {
    std::cerr << "Failed to write to database: " << status.ToString()
              << std::endl;
  }

  // Retrieve the value for a key
  std::string retrieved_value;
  status = db->Get(leveldb::ReadOptions(), key, &retrieved_value);
  if (status.ok()) {
    std::cout << "Retrieved value: " << retrieved_value << std::endl;
  } else {
    std::cerr << "Failed to read from database: " << status.ToString()
              << std::endl;
  }

  // Delete a key-value pair
  status = db->Delete(leveldb::WriteOptions(), key);
  if (!status.ok()) {
    std::cerr << "Failed to delete key from database: " << status.ToString()
              << std::endl;
  }

  // Close the database
  delete db;

  return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
