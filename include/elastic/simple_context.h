// Copyright (c) 2015, Tiaan Louw
//
// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
// REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
// AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
// INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
// LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
// OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
// PERFORMANCE OF THIS SOFTWARE.

#ifndef ELASTIC_SIMPLE_CONTEXT_H_
#define ELASTIC_SIMPLE_CONTEXT_H_

#include "nucleus/files/file_path.h"
#include "nucleus/macros.h"

#include "elastic/context.h"
#include "elastic/resources/simple_resource_manager.h"

namespace el {

class SimpleContext : public Context {
public:
  explicit SimpleContext(const nu::FilePath& resourceRootPath = nu::FilePath{});
  ~SimpleContext() = default;

  // Get/set the root path for resources.
  const nu::FilePath& getRootPath() const;
  void setRootPath(const nu::FilePath& rootPath);

  // Override: Context
  ca::Texture* getTexture(const std::string& name) override;
  ca::Font* getFont(const std::string& name) override;

private:
  // The resource manager we'll use for this type of context.
  SimpleResourceManager m_resourceManager;

  DISALLOW_COPY_AND_ASSIGN(SimpleContext);
};

}  // namespace el

#endif  // ELASTIC_SIMPLE_CONTEXT_H_
