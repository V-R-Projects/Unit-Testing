# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/ramsensei/Desktop/Ramsensei/Unit-Testing/build/_deps/googletest-src"
  "/home/ramsensei/Desktop/Ramsensei/Unit-Testing/build/_deps/googletest-build"
  "/home/ramsensei/Desktop/Ramsensei/Unit-Testing/build/_deps/googletest-subbuild/googletest-populate-prefix"
  "/home/ramsensei/Desktop/Ramsensei/Unit-Testing/build/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "/home/ramsensei/Desktop/Ramsensei/Unit-Testing/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "/home/ramsensei/Desktop/Ramsensei/Unit-Testing/build/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "/home/ramsensei/Desktop/Ramsensei/Unit-Testing/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/ramsensei/Desktop/Ramsensei/Unit-Testing/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
