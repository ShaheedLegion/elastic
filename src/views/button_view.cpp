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

#include <nucleus/logging.h>

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
#if 0
    m_labelShape.setString(m_label);
    m_labelShape.setFont(*buttonFont);
    m_labelShape.setColor(sf::Color{127, 255, 127});
    m_labelShape.setCharacterSize(25);
#endif  // 0
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

#if 0
  // Calculate the size of the label.
  ca::Rect<f32> floatLabelSize{m_labelShape.getLocalBounds()};

  sf::Vector2i labelSize{static_cast<int>(std::ceil(floatLabelSize.width)),
                         static_cast<int>(std::ceil(floatLabelSize.height))};

  // Add a border around the label.
  labelSize.x += 20;
  labelSize.y += 20;

  result.x = std::max(result.x, labelSize.x);
  result.y = std::max(result.y, labelSize.y);
#endif  // 0

  return result;
}

void ButtonView::layout(const ca::Rect<i32>& rect) {
  View::layout(rect);

#if 0
  // Move the background shape into position.
  m_backgroundShape.setPosition(sf::Vector2f{static_cast<float>(rect.left),
                                             static_cast<float>(rect.top)});
  m_backgroundShape.setSize(sf::Vector2f{static_cast<float>(rect.width),
                                         static_cast<float>(rect.height)});

  sf::FloatRect floatLabelSize{m_labelShape.getLocalBounds()};

  // Move the shape to the correct position.
  m_labelShape.setPosition(
      sf::Vector2f{static_cast<float>(rect.left + 10) - floatLabelSize.left,
                   static_cast<float>(rect.top + 10) - floatLabelSize.top});
#endif  // 0
}

void ButtonView::render(ca::Canvas* canvas) const {
  View::render(canvas);

#if 0
  target.draw(m_backgroundShape);
  target.draw(m_labelShape);
#endif  // 0
}

}  // namespace el
