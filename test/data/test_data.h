#pragma once

#include <vector>
#include <memory>
#include <string>
#include <sstream>
#include <fstream>

#include <iostream>

#include <gtest/gtest.h>

#include "liboculus/SimplePingResult.h"

// NOTE: must be set via CMake
#ifndef TEST_DATA_PATH
  #error "TEST_DATA_PATH must be defined for unit test data to be found"
#endif

#define ONE_RAW_PING    (TEST_DATA_PATH"/one_ping.raw")
#define THREE_RAW_PINGS (TEST_DATA_PATH"/three_ping.raw")

namespace Oculus_TestData {

  using std::vector;

  inline vector<uint8_t> Load( const std::string &filename ) {

    std::ifstream inf( filename );

    if( !inf.is_open() ) return vector<uint8_t>();

    // This feels a little ... wrong
    inf.seekg(0, std::ios::end);

    const size_t sz = inf.tellg();

    std::string out( sz, '\0' );
    inf.seekg(0, std::ios::beg);
    inf.read( &out[0], sz );

    return vector<uint8_t>(out.begin(), out.end());
  }

  inline liboculus::MessageHeader LoadMessageBuffer( const std::string &filename ) {
    std::vector<uint8_t> pingData = Load( filename );
    return liboculus::MessageHeader( pingData );
  }


}
