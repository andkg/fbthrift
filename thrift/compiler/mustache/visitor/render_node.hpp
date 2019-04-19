/*

The source code contained in this file is based on the original code by
Daniel Sipka (https://github.com/no1msd/mstch). The original license by Daniel
Sipka can be read below:

The MIT License (MIT)

Copyright (c) 2015 Daniel Sipka

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#pragma once

#include <sstream>
#include <boost/variant/static_visitor.hpp>

#include "render_context.hpp"
#include "mstch/mstch.hpp"
#include "utils.hpp"

namespace mstch {

class render_node: public boost::static_visitor<std::string> {
 public:
  enum class flag { none, escape_html };
  render_node(render_context& ctx, flag p_flag = flag::none):
      m_ctx(ctx), m_flag(p_flag)
  {
  }

  template<class T>
  std::string operator()(const T&) const {
    return "";
  }

  std::string operator()(const int& value) const {
    return std::to_string(value);
  }

  std::string operator()(const double& value) const {
    std::stringstream ss;
    ss << value;
    return ss.str();
  }

  std::string operator()(const bool& value) const {
    return value ? "true" : "false";
  }

  std::string operator()(const lambda& value) const {
    template_type interpreted{value([this](const mstch::node& n) {
      return visit(render_node(m_ctx), n);
    })};
    auto rendered = render_context::push(m_ctx).render(interpreted);
    return (m_flag == flag::escape_html) ? html_escape(rendered) : rendered;
  }

  std::string operator()(const std::string& value) const {
    return (m_flag == flag::escape_html) ? html_escape(value) : value;
  }

 private:
  render_context& m_ctx;
  flag m_flag;
};

}
