#pragma once

#include <iostream>
#include <memory>
#include <fstream>
#include <malloc.h>
#include <map>
#include <chrono>
#include <thread>
#include <functional>
#include <mutex>
#include <queue>
#include <sstream>
#include <execution>

#ifndef WIN32
#include <experimental/string_view>
namespace std
{
	using string_view = std::experimental::string_view;
}
#endif

#include "curl/curl.h"
#include "json.hpp"
#include "mysql.h"
#include "grpcpp/grpcpp.h"
#include "boost/format.hpp"