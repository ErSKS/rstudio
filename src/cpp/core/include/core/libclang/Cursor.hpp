/*
 * Cursor.hpp
 *
 * Copyright (C) 2009-12 by RStudio, Inc.
 *
 * Unless you have received this program directly from RStudio pursuant
 * to the terms of a commercial license agreement with RStudio, then
 * this program is licensed to you under the terms of version 3 of the
 * GNU Affero General Public License. This program is distributed WITHOUT
 * ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING THOSE OF NON-INFRINGEMENT,
 * MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE. Please refer to the
 * AGPL (http://www.gnu.org/licenses/agpl-3.0.txt) for more details.
 *
 */

#ifndef CORE_LIBCLANG_CURSOR_HPP
#define CORE_LIBCLANG_CURSOR_HPP

#include <boost/shared_ptr.hpp>

#include "clang-c/Index.h"

#include "SourceLocation.hpp"

namespace core {
namespace libclang {

class Cursor
{
public:

   Cursor() {}

   explicit Cursor(CXCursor cursor)
      : pCursor_(new CXCursor(cursor))
   {
   }

   ~Cursor();

public:

   bool isDefinition() const;

   Cursor getDefinition() const;

   SourceLocation getSourceLocation() const;

   bool isNull() const;

private:
   CXCursor cursor() const { return *pCursor_; }

private:
   boost::shared_ptr<CXCursor> pCursor_;
};

} // namespace libclang
} // namespace core

#endif // CORE_LIBCLANG_CURSOR_HPP
