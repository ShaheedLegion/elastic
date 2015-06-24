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

#include "elastic/simple_window_delegate.h"

namespace el {

void SimpleWindowDelegate::onMouseMoved(const ca::MouseEvent& event) {
  WindowDelegate::onMouseMoved(event);
  m_context.onMouseMoved(event);
}

void SimpleWindowDelegate::onMousePressed(const ca::MouseEvent& event) {
  WindowDelegate::onMousePressed(event);
  m_context.onMousePressed(event);
}

void SimpleWindowDelegate::onMouseReleased(const ca::MouseEvent& event) {
  WindowDelegate::onMouseReleased(event);
  m_context.onMouseReleased(event);
}

SimpleWindowDelegate::SimpleWindowDelegate(const nu::FilePath& rootPath)
  : m_context(rootPath) {
}

}  // namespace el
