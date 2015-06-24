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

#include "elastic/views/text_view.h"

#include <algorithm>

#include "canvas/math/transform.h"

#include "elastic/context.h"

namespace el {

TextView::TextView(Context* context, ca::Font* font, const std::string& label)
  : View(context), m_label(label), m_text(font, 30, label) {
}

TextView::~TextView() {
}

void TextView::setLabel(const std::string& label) {
  m_label = label;

  // Set the label on the shape.
  m_text.setText(label);
}

void TextView::setFont(ca::Font* font) {
  m_text.setFont(font);
}

ca::Size<i32> TextView::calculateMinSize() const {
  ca::Size<i32> result{View::calculateMinSize()};

  ca::Size<i32> boundSize = m_text.getBounds().size;
  result.width = std::max(result.width, boundSize.width);
  result.height = std::max(result.height, boundSize.height);

  return result;
}

void TextView::render(ca::Canvas* canvas, const ca::Mat4& transform) const {
  View::render(canvas, transform);

  // Get the bounds of the text.
  ca::Rect<i32> bounds = m_text.getBounds();

  // Adjust the text to the correct position.
  ca::Mat4 local =
      transform * ca::translate(ca::Vec3{
                      static_cast<f32>(m_rect.pos.x - bounds.pos.x),
                      static_cast<f32>(m_rect.pos.y - bounds.pos.y), 0.f});

  m_text.render(canvas, local);
}

}  // namespace el
