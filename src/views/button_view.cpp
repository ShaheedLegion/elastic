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

#include "elastic/views/button_view.h"

#include <cmath>
#include <algorithm>
#include <string>

#include "canvas/math/transform.h"
#include "nucleus/logging.h"

#include "elastic/context.h"

namespace el {

ButtonView::OnClickListener::~OnClickListener() {
}

ButtonView::ButtonView(Context* context, const std::string& label,
                       OnClickListener* listener)
  : View(context), m_label(label), m_listener(listener) {
  ca::Font* buttonFont = context->getFont("default");

  // Set up the background shape.
#if 0
  m_backgroundShape.setFillColor(sf::Color{255, 255, 255, 127});
  m_backgroundShape.setOutlineColor(sf::Color{127, 255, 127});
  m_backgroundShape.setOutlineThickness(1);
#endif  // 0

  // Set up the label.
  if (buttonFont) {
    m_labelShape.setText(m_label);
    m_labelShape.setFont(buttonFont);
    // m_labelShape.setColor(sf::Color{127, 255, 127});
    m_labelShape.setTextSize(25);
  }
}

ButtonView::~ButtonView() {
}

void ButtonView::setLabel(const std::string& label) {
  m_label = label;
  m_labelShape.setText(label);
}

bool ButtonView::onMousePressed(const ca::MouseEvent& event) {
  View::onMousePressed(event);
  return true;
}

void ButtonView::onMouseReleased(const ca::MouseEvent& event) {
  View::onMouseReleased(event);

  if (m_listener) {
    m_listener->onButtonClicked(this);
  }
}

void ButtonView::onMouseEntered(const ca::MouseEvent& event) {
#if 0
  m_backgroundShape.setFillColor(sf::Color{255, 255, 255, 191});
#endif  // 0
}

void ButtonView::onMouseExited(const ca::MouseEvent& event) {
#if 0
  m_backgroundShape.setFillColor(sf::Color{255, 255, 255, 127});
#endif  // 0
}

ca::Size<i32> ButtonView::calculateMinSize() const {
  ca::Size<i32> result{View::calculateMinSize()};

  ca::Size<i32> boundSize = m_labelShape.getBounds().size;

  result.width = std::max(result.width, boundSize.width);
  result.height = std::max(result.height, boundSize.height);

  return result;
}

void ButtonView::render(ca::Canvas* canvas, const ca::Mat4& transform) const {
  View::render(canvas, transform);

  // Get the bounds of the text.
  ca::Rect<i32> bounds = m_labelShape.getBounds();

  // Adjust the text to the correct position.
  ca::Mat4 local =
      transform * ca::translate(ca::Vec3{
                      static_cast<f32>(m_rect.pos.x - bounds.pos.x),
                      static_cast<f32>(m_rect.pos.y - bounds.pos.y), 0.f});

  m_labelShape.render(canvas, local);
}

}  // namespace el
