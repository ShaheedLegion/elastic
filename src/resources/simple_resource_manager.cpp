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

#include "elastic/resources/simple_resource_manager.h"

#include <functional>
#include <string>

#include "nucleus/streams/file_input_stream.h"

namespace el {

SimpleResourceManager::SimpleResourceManager(const nu::FilePath& rootPath)
  : m_rootPath(rootPath) {
}

void SimpleResourceManager::setRootPath(const nu::FilePath& rootPath) {
  m_rootPath = rootPath;
}

ca::Texture* SimpleResourceManager::getTexture(const nu::FilePath& path) {
  nu::FilePath pathToResource = m_rootPath.append(path);

  // Check if we've already loaded the file.
  auto it = m_textureCache.find(pathToResource);
  if (it == std::end(m_textureCache)) {
    nu::FileInputStream stream(pathToResource);

    // Create the resource
    ca::Image image;
    image.loadFromStream(&stream);

    auto newTexture = std::make_unique<ca::Texture>();
    if (newTexture->createFromImage(image)) {
      // Store the result before we move out from the unique ptr.
      ca::Texture* result = newTexture.get();

      // Store the resource.
      m_textureCache.insert(
          std::make_pair(pathToResource, std::move(newTexture)));

      return result;
    }
  }

  return it->second.get();
}

ca::Font* SimpleResourceManager::getFont(const nu::FilePath& path) {
  nu::FilePath pathToResource = m_rootPath.append(path);

  // Check if we've already loaded the file.
  auto it = m_fontCache.find(pathToResource);
  if (it == std::end(m_fontCache)) {
    nu::FileInputStream stream(pathToResource);

    // Create the resource
    auto newFont = std::make_unique<ca::Font>();
    if (newFont->loadFromStream(&stream)) {
      // Store the result before we move out from the unique ptr.
      ca::Font* result = newFont.get();

      // Store the resource.
      m_fontCache.insert(std::make_pair(pathToResource, std::move(newFont)));

      return result;
    }
  }

  return it->second.get();
}

}  // namespace el
