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

#include "elastic/context.h"

namespace el {

Context::Context() : m_contextView(this) {
}

Context::~Context() {
}

void Context::setFocusView(View* view) {
  m_focusView = view;
}

void Context::onMouseMoved(const ca::MouseEvent& evt) {
  m_contextView.processMouseMoved(evt);
}

void Context::onMousePressed(const ca::MouseEvent& evt) {
  m_contextView.processMousePressed(evt, false);
}

void Context::onMouseReleased(const ca::MouseEvent& evt) {
  m_contextView.processMouseReleased(evt);
}

#if 0
void Context::handleInput(sf::Event& event) {
  switch (event.type) {
    case sf::Event::MouseButtonPressed: {
      
    } break;

    case sf::Event::MouseMoved: {
      
    } break;

    case sf::Event::MouseButtonReleased: {
      
    } break;

    case sf::Event::MouseWheelMoved: {
      m_contextView.processMouseWheel(event);
    } break;

    case sf::Event::KeyPressed: {
      m_contextView.processKeyPressed(event);
      break;
    }

    case sf::Event::KeyReleased: {
      m_contextView.processKeyReleased(event);
      break;
    }

    default:
      break;
  }
}
#endif  // 0

void Context::tick(float adjustment) {
  m_contextView.tick(adjustment);
}

void Context::render(ca::Canvas* canvas) const {
#if 0
  // Get the size of the render target in pixels for the UI to render.
  sf::IntRect layoutRect{0, 0, static_cast<int>(target.getSize().x),
                         static_cast<int>(target.getSize().y)};

  m_contextView.layout(layoutRect);
  target.draw(m_contextView, states);
#endif  // 0
}

}  // namespace el
