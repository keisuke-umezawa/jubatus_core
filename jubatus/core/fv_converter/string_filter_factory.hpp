// Jubatus: Online machine learning framework for distributed environment
// Copyright (C) 2011 Preferred Networks and Nippon Telegraph and Telephone Corporation.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License version 2.1 as published by the Free Software Foundation.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

#ifndef JUBATUS_CORE_FV_CONVERTER_STRING_FILTER_FACTORY_HPP_
#define JUBATUS_CORE_FV_CONVERTER_STRING_FILTER_FACTORY_HPP_

#include <string>
#include <map>
#include "jubatus/util/lang/function.h"
#include "jubatus/util/lang/shared_ptr.h"
#include "string_filter.hpp"
#include "type.hpp"

namespace jubatus {
namespace core {
namespace fv_converter {

class string_filter_factory {
 public:
  typedef jubatus::util::lang::function<
    string_filter*(const std::string&, const param_t&)> create_function;

  string_filter_factory() {
  }

  explicit string_filter_factory(const create_function& ext)
    : ext_(ext) {
  }

  jubatus::util::lang::shared_ptr<string_filter> create(
      const std::string& name, const param_t& params) const;

 private:
  create_function ext_;
};

}  // namespace fv_converter
}  // namespace core
}  // namespace jubatus

#endif  // JUBATUS_CORE_FV_CONVERTER_STRING_FILTER_FACTORY_HPP_
