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

#ifndef ELASTIC_SIMPLE_WINDOW_DELEGATE_H_
#define ELASTIC_SIMPLE_WINDOW_DELEGATE_H_

#include "canvas/windows/window_delegate.h"

#include "elastic/simple_context.h"

namespace el {

class SimpleWindowDelegate : public ca::WindowDelegate {
public:
  ~SimpleWindowDelegate() = default;

  // Override: ca::WindowDelegate
  void onMouseMoved(const ca::MouseEvent& event) override;
  void onMousePressed(const ca::MouseEvent& event) override;
  void onMouseReleased(const ca::MouseEvent& event) override;

  void onPaint(ca::Canvas* canvas) override { m_context.render(canvas); }

protected:
  // Construct the window delegate with a resource root path.
  explicit SimpleWindowDelegate(const nu::FilePath& rootPath);

  // The UI context we'll use.
  SimpleContext m_context;

  DISALLOW_COPY_AND_ASSIGN(SimpleWindowDelegate);
};

}  // namespace el

#endif  // ELASTIC_SIMPLE_WINDOW_DELEGATE_H_
