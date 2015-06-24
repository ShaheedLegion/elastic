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

#include "canvas/math/transform.h"

namespace el {

Context::Context() : m_contextView(this) {
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
  // Get the size of the render target in pixels for the UI to render.
  ca::Rect<i32> layoutRect{ca::Pos<i32>{}, canvas->getSize()};

  m_contextView.layout(layoutRect);

  ca::Mat4 transform = ca::ortho(0.f, static_cast<f32>(layoutRect.size.width),
                                 static_cast<f32>(layoutRect.size.height), 0.f);

  m_contextView.render(canvas, transform);
}

}  // namespace el
